#include <ace/Log_Msg.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DCPS/StaticIncludes.h>
#include "StatusTypeSupportImpl.h"
#include "setters.h"
#include <iostream>
#include <thread>

using namespace std::chrono_literals;
using namespace DDS;

void publishData(StatusDataWriter_var& mssgWriter, Status &mssg) {
        mssgWriter->write(mssg, HANDLE_NIL);
}

int main(int argc, char *argv[]) {

    DDS::DomainParticipantFactory_var dpf = 
        TheParticipantFactoryWithArgs(argc, argv);

    DDS::DomainParticipant_var participant;
    participant = dpf->create_participant(0,
        PARTICIPANT_QOS_DEFAULT,
        0,
        OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    
    StatusTypeSupport_var mts;
    mts = new StatusTypeSupportImpl();
    mts->register_type(participant, "");

    CORBA::String_var typeName = mts->get_type_name();
    
    DDS::Topic_var topic;
    topic = participant->create_topic("RPMData",typeName,TOPIC_QOS_DEFAULT,0,OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    Publisher_var publisher;
    publisher = participant->create_publisher(PUBLISHER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

    DataWriter_var dataWriter;
    dataWriter = publisher->create_datawriter(topic, DATAWRITER_QOS_DEFAULT, 0,  OpenDDS::DCPS::DEFAULT_STATUS_MASK);
    StatusDataWriter_var mssgWriter = StatusDataWriter::_narrow(dataWriter);    
    
    // DataWriterQos dataWriterQos;
    // dataWriterQos.liveliness.kind = LivelinessQosPolicyKind::AUTOMATIC_LIVELINESS_QOS;
    // dataWriterQos.history.depth = 50;
    // dataWriterQos.history.kind = HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
    // dataWriterQos.durability.kind = DurabilityQosPolicyKind::TRANSIENT_LOCAL_DURABILITY_QOS;
    // dataWriterQos.durability_service.history_depth = 100;
    // dataWriterQos.durability_service.history_kind = HistoryQosPolicyKind::KEEP_ALL_HISTORY_QOS;
    // dataWriterQos.durability_service.max_instances = 100;
    // dataWriterQos.durability_service.max_samples = 100;
    // dataWriter->set_qos(dataWriterQos);

    StatusCondition_var condition = dataWriter->get_statuscondition();
    condition->set_enabled_statuses(DDS::PUBLICATION_MATCHED_STATUS);
    WaitSet_var waitSet = new WaitSet;
    waitSet->attach_condition(condition);

    ifstream file;
    file.open("/home/happikin/dev/practice/ex2/dataStore/RPMdata.txt", std::ios::in);
    if(file.is_open()) {
        std::cout << "OPEN\n";
    }
    std::vector<int> rawData;
    while(file) {
        std::stringstream ss;
        std::string s;
        file >> s;
        int n; ss << s; ss >> n;
        rawData.push_back(n);
    }
    // for(auto& item:rawData) {
    //     std::cout << item << "\n";
    // }
    uint64_t count{};
    while (true) {
        PublicationMatchedStatus matches;
        dataWriter->get_publication_matched_status(matches);

        Status payload;
        if(matches.current_count >= 0) {
            payload.ready &= 0x00;
            setRPM(payload.ready);
            payload.rpmStatus = rawData[count++];
            // srand(time(0));
            // payload.rpmStatus = (rand() % 10000);
            // srand(time(0));
        }
        
        ConditionSeq conditions;
        waitSet->wait(conditions, {1, 0});
        if(matches.current_count >= 0) {
            publishData(mssgWriter,payload);
        }

        //std::this_thread::sleep_for(5000ms);
    }

    waitSet->detach_condition(condition);

    participant->delete_contained_entities();
    dpf->delete_participant(participant);
    TheServiceParticipant->shutdown();
}
