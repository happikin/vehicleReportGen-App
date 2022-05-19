#include <ace/Log_Msg.h>
#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsSubscriptionC.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>
#include <dds/DCPS/StaticIncludes.h>
#include "DataReaderListenerImpl.h"
#include "StatusTypeSupportImpl.h"
#include <thread>


using namespace std::chrono_literals;
using namespace DDS;

bool terminate{false};
bool over{false};

void monProc();
void mainWaitProc(DDS::WaitSet_var ws,DDS::ConditionSeq cond, DDS::DataReader_ptr dr);
void initForAll();

class MainSub {
    private:
    std::vector<const char*> topicNames{
        "EngineTemperature",
        "CarWeight",
        "RPMData",
        "FuelStatus",
        "SuspensionStatus"
    };
    
    // these variables are for state generation
    std::vector<DDS::Topic_var> topics;
    std::vector<DDS::DataReader_var> dataReaders;
    std::vector<StatusDataReader_var> mssgReaders;
    std::vector<DDS::StatusCondition_var> conditions;
    std::vector<DDS::WaitSet_var> waitSets;

    // the member are for participant construction
    DDS::DomainParticipantFactory_var dpf;
    DDS::DomainParticipant_var participant;
    StatusTypeSupport_var mts;
    CORBA::String_var typeName;
    Subscriber_var subscriber;
    DataReaderListener_ptr listener;

    std::thread *monitor;
    bool over;
    
    public:
    MainSub(int argc, char *argv[]) :
        dpf(TheParticipantFactoryWithArgs(argc,argv)) {
            
            std::cout << "Constructed\n";
            participant = dpf->create_participant(0,
                PARTICIPANT_QOS_DEFAULT,
                0,
                OpenDDS::DCPS::DEFAULT_STATUS_MASK
            );
            if(participant.ptr() != nullptr) {
                std::cout << "Participant created\n";
            }
            mts = new StatusTypeSupportImpl();
            if(mts->register_type(participant, "") == DDS::RETCODE_OK) {
                typeName = mts->get_type_name();
                std::cout << "Type registered\n";
                
            }

            subscriber = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
            std::cout << "Subscriber created\n";
            
            monitor = new std::thread(monProc);
            std::cout << "Monitor thread started\n";

            over = false;
            statusData.allocMem();
            
            std::cout << "stautsData mem alloc\n";
        }

        void init() {
            std::cout << "Init loop\n";
            int topicLoopCount{0};
            for(auto& topicName:topicNames) {

                std::cout << "Count: " << topicLoopCount << " TopicName: " << topicName << "\n";
                topics.push_back(participant->create_topic(topicName,typeName,TOPIC_QOS_DEFAULT,0,OpenDDS::DCPS::DEFAULT_STATUS_MASK));
                std::cout << "Topic created\n";
                
                dataReaders.push_back(subscriber->create_datareader(topics[topicLoopCount], DATAREADER_QOS_DEFAULT, listener, OpenDDS::DCPS::DEFAULT_STATUS_MASK));
                std::cout << "Data reader created\n";
                
                mssgReaders.push_back(StatusDataReader::_narrow(dataReaders[topicLoopCount]));
                std::cout << "MssgReader created\n";
                
                conditions.push_back(dataReaders[topicLoopCount]->get_statuscondition());
                conditions[topicLoopCount]->set_enabled_statuses(DDS::SUBSCRIPTION_MATCHED_STATUS);
                std::cout << "Condition Set\n";
                
                waitSets.push_back(new DDS::WaitSet);
                waitSets[topicLoopCount]->attach_condition(conditions[topicLoopCount]);
                
                topicLoopCount++;
            }

        }
        void wait() {
            int wsLoopCount{0};
            std::vector<std::thread*> threads(5);
            std::vector<DDS::ConditionSeq> condSeq(5);
            
            for(auto& ws:waitSets) {
                threads[wsLoopCount] =
                    new std::thread(&mainWaitProc,
                        ws,
                        condSeq[wsLoopCount],
                        static_cast<DDS::DataReader_ptr>(dataReaders[wsLoopCount])
                    );
                wsLoopCount++;
            }

            for(auto& t:threads) {
                t->join();
            }
        }
        void setListener(DataReaderListenerImpl *impl) {
            listener = impl;
        }
        void stop() {
            int detachCount{0};
            for(auto& w:waitSets) {
                w->detach_condition(conditions[detachCount++]);
            }

            participant->delete_contained_entities();
            dpf->delete_participant(participant);
            TheServiceParticipant->shutdown();

            over=true;
            monitor->join();
        }
};

int main(int argc, char *argv[])
{
    MainSub mainsub(argc,argv);
    mainsub.setListener(new DataReaderListenerImpl);
    mainsub.init();
    mainsub.wait();
    mainsub.stop();
    return 0;
}

void monProc() {
    while(getchar()!='\n');
    terminate = true;
    statusData.deallocMem();
    while(!over);
    std::cout << "MESSAGE::Closing MainSub process\n";
    //exit(0);
}

void mainWaitProc(DDS::WaitSet_var ws,DDS::ConditionSeq cond, DDS::DataReader_ptr dr) {
    while (true) {

        if(terminate) { break; }

        int result = ws->wait(cond, {1,0});
        if(result == RETCODE_TIMEOUT) {
            // std::cout << "wait timed out ...\n";
        } else {
            // std::cout << "Match outer...\n";
            DDS::SubscriptionMatchedStatus matches;
            dr->get_subscription_matched_status(matches);
            if (matches.current_count == 0 && matches.total_count > 0) {

                //std::this_thread::yield();
            }
        }
    }
}