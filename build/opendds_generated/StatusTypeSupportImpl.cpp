/* Generated by /opt/OpenDDS/bin/opendds_idl version 3.20.0 (ACE version 6.2a_p23) running on input file /home/happikin/dev/projects/majorproject/ex2/Status.idl */
#include "StatusTypeSupportImpl.h"

#include <cstring>
#include <stdexcept>
#include "dds/DCPS/BuiltInTopicUtils.h"
#include "dds/DCPS/ContentFilteredTopicImpl.h"
#include "dds/DCPS/DataReaderImpl_T.h"
#include "dds/DCPS/DataWriterImpl_T.h"
#include "dds/DCPS/FilterEvaluator.h"
#include "dds/DCPS/MultiTopicDataReader_T.h"
#include "dds/DCPS/PoolAllocator.h"
#include "dds/DCPS/PublicationInstance.h"
#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/RakeData.h"
#include "dds/DCPS/RakeResults_T.h"
#include "dds/DCPS/ReceivedDataElementList.h"
#include "dds/DCPS/Registered_Data_Types.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/SubscriberImpl.h"
#include "dds/DCPS/Util.h"
#include "dds/DCPS/XTypes/TypeObject.h"
#include "dds/DCPS/debug.h"
#include "dds/DdsDcpsDomainC.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: OpenDDS */


/* End MODULE: OpenDDS */


/* Begin STRUCT: Status */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<> const XTypes::TypeIdentifier& getMinimalTypeIdentifier<Status_xtag>()
{
  static XTypes::TypeIdentifier ti;
  ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, TheServiceParticipant->get_static_xtypes_lock(), ti);
  if (ti.kind() == XTypes::TK_NONE) {
    ti = XTypes::TypeIdentifier(XTypes::EK_MINIMAL, XTypes::EquivalenceHashWrapper(85, 21, 137, 90, 204, 51, 162, 238, 129, 1, 248, 253, 164, 155));
  }
  return ti;
}

static const XTypes::TypeMap& get_minimal_type_map();
template<> const XTypes::TypeMap& getMinimalTypeMap<Status_xtag>()
{
  return get_minimal_type_map();
}

} }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

bool vread(OpenDDS::DCPS::ValueReader& value_reader,  ::Status& value)
{
  ACE_UNUSED_ARG(value_reader);
  ACE_UNUSED_ARG(value);
  static const ListMemberHelper::Pair pairs[] = {{"ID",0},{"ready",1},{"engineTemp",2},{"carWeight",3},{"rpmStatus",4},{"fuelTank",5},{"suspensionHealth",6},{0,0}};
  ListMemberHelper helper(pairs);
  if (!value_reader.begin_struct()) return false;
  XTypes::MemberId member_id;
  while (value_reader.begin_struct_member(member_id, helper)) {
    switch (member_id) {
    case 0: {
      if (!value_reader.read_int32(value.ID)) return false;
      break;
    }
    case 1: {
      if (!value_reader.read_byte(value.ready)) return false;
      break;
    }
    case 2: {
      if (!value_reader.read_float32(value.engineTemp)) return false;
      break;
    }
    case 3: {
      if (!value_reader.read_float32(value.carWeight)) return false;
      break;
    }
    case 4: {
      if (!value_reader.read_int32(value.rpmStatus)) return false;
      break;
    }
    case 5: {
      if (!value_reader.read_float32(value.fuelTank)) return false;
      break;
    }
    case 6: {
      if (!value_reader.read_float32(value.suspensionHealth)) return false;
      break;
    }
    }
    if (!value_reader.end_struct_member()) return false;
  }
  if (!value_reader.end_struct()) return false;
  return true;
}

} }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void vwrite(OpenDDS::DCPS::ValueWriter& value_writer, const  ::Status& value)
{
  ACE_UNUSED_ARG(value_writer);
  ACE_UNUSED_ARG(value);
  value_writer.begin_struct();
  value_writer.begin_struct_member("ID");
  value_writer.write_int32(value.ID);
  value_writer.end_struct_member();
  value_writer.begin_struct_member("ready");
  value_writer.write_byte(value.ready);
  value_writer.end_struct_member();
  value_writer.begin_struct_member("engineTemp");
  value_writer.write_float32(value.engineTemp);
  value_writer.end_struct_member();
  value_writer.begin_struct_member("carWeight");
  value_writer.write_float32(value.carWeight);
  value_writer.end_struct_member();
  value_writer.begin_struct_member("rpmStatus");
  value_writer.write_int32(value.rpmStatus);
  value_writer.end_struct_member();
  value_writer.begin_struct_member("fuelTank");
  value_writer.write_float32(value.fuelTank);
  value_writer.end_struct_member();
  value_writer.begin_struct_member("suspensionHealth");
  value_writer.write_float32(value.suspensionHealth);
  value_writer.end_struct_member();
  value_writer.end_struct();
}

} }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<> void set_default( ::Status& stru)
{
  ACE_UNUSED_ARG(stru);
  stru.ID = 0;
  stru.ready = 0;
  stru.engineTemp = 0;
  stru.carWeight = 0;
  stru.rpmStatus = 0;
  stru.fuelTank = 0;
  stru.suspensionHealth = 0;
}

void serialized_size(const Encoding& encoding, size_t& size, const  ::Status& stru)
{
  ACE_UNUSED_ARG(encoding);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(stru);
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    serialized_size_delimiter(encoding, size);
  }
  primitive_serialized_size(encoding, size, stru.ID);
  primitive_serialized_size(encoding, size, ACE_OutputCDR::from_octet(stru.ready));
  primitive_serialized_size(encoding, size, stru.engineTemp);
  primitive_serialized_size(encoding, size, stru.carWeight);
  primitive_serialized_size(encoding, size, stru.rpmStatus);
  primitive_serialized_size(encoding, size, stru.fuelTank);
  primitive_serialized_size(encoding, size, stru.suspensionHealth);
}

bool operator<<(Serializer& strm, const  ::Status& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  const Encoding& encoding = strm.encoding();
  ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    serialized_size(encoding, total_size, stru);
    if (!strm.write_delimiter(total_size)) {
      return false;
    }
  }
  return (strm << stru.ID)
    && (strm << ACE_OutputCDR::from_octet(stru.ready))
    && (strm << stru.engineTemp)
    && (strm << stru.carWeight)
    && (strm << stru.rpmStatus)
    && (strm << stru.fuelTank)
    && (strm << stru.suspensionHealth);
}

bool operator>>(Serializer& strm,  ::Status& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  const Encoding& encoding = strm.encoding();
  ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    if (!strm.read_delimiter(total_size)) {
      return false;
    }
  }
  const size_t end_of_struct = strm.rpos() + total_size;

  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.ID)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> ACE_InputCDR::to_octet(stru.ready))) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.engineTemp)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.carWeight)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.rpmStatus)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.fuelTank)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.suspensionHealth)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() < end_of_struct) {
    strm.skip(end_of_struct - strm.rpos());
  }
  return true;
}

void serialized_size(const Encoding& encoding, size_t& size, const NestedKeyOnly<const  ::Status>& stru)
{
  ACE_UNUSED_ARG(encoding);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(stru);
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    serialized_size_delimiter(encoding, size);
  }
  primitive_serialized_size(encoding, size, stru.value.ID);
}

bool operator<<(Serializer& strm, const NestedKeyOnly<const  ::Status>& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  const Encoding& encoding = strm.encoding();
  ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    serialized_size(encoding, total_size, stru);
    if (!strm.write_delimiter(total_size)) {
      return false;
    }
  }
  return (strm << stru.value.ID);
}

bool operator>>(Serializer& strm, const NestedKeyOnly< ::Status>& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  const Encoding& encoding = strm.encoding();
  ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    if (!strm.read_delimiter(total_size)) {
      return false;
    }
  }
  const size_t end_of_struct = strm.rpos() + total_size;

  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.value.ID)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() < end_of_struct) {
    strm.skip(end_of_struct - strm.rpos());
  }
  return true;
}

void serialized_size(const Encoding& encoding, size_t& size, const KeyOnly<const  ::Status>& stru)
{
  ACE_UNUSED_ARG(encoding);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(stru);
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    serialized_size_delimiter(encoding, size);
  }
  primitive_serialized_size(encoding, size, stru.value.ID);
}

bool operator<<(Serializer& strm, const KeyOnly<const  ::Status>& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  const Encoding& encoding = strm.encoding();
  ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    serialized_size(encoding, total_size, stru);
    if (!strm.write_delimiter(total_size)) {
      return false;
    }
  }
  return (strm << stru.value.ID);
}

bool operator>>(Serializer& strm, const KeyOnly< ::Status>& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  const Encoding& encoding = strm.encoding();
  ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    if (!strm.read_delimiter(total_size)) {
      return false;
    }
  }
  const size_t end_of_struct = strm.rpos() + total_size;

  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() >= end_of_struct) {
    return true;
  }
  if (!(strm >> stru.value.ID)) {
    return false;
  }
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2 &&
      strm.rpos() < end_of_struct) {
    strm.skip(end_of_struct - strm.rpos());
  }
  return true;
}

} }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


::DDS::DataWriter_ptr StatusTypeSupportImpl::create_datawriter()
{
  typedef OpenDDS::DCPS::DataWriterImpl_T<Status> DataWriterImplType;
  ::DDS::DataWriter_ptr writer_impl = ::DDS::DataWriter::_nil();
  ACE_NEW_NORETURN(writer_impl,
                   DataWriterImplType());
  return writer_impl;
}

::DDS::DataReader_ptr StatusTypeSupportImpl::create_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<Status> DataReaderImplType;
  ::DDS::DataReader_ptr reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(reader_impl,
                   DataReaderImplType());
  return reader_impl;
}

#ifndef OPENDDS_NO_MULTI_TOPIC
::DDS::DataReader_ptr StatusTypeSupportImpl::create_multitopic_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<Status> DataReaderImplType;
  typedef OpenDDS::DCPS::MultiTopicDataReader_T<Status, DataReaderImplType> MultiTopicDataReaderImplType;
  ::DDS::DataReader_ptr multitopic_reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(multitopic_reader_impl,
                   MultiTopicDataReaderImplType());
  return multitopic_reader_impl;
}
#endif /* !OPENDDS_NO_MULTI_TOPIC */

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
const OpenDDS::DCPS::MetaStruct& StatusTypeSupportImpl::getMetaStructForType()
{
  return OpenDDS::DCPS::getMetaStruct<Status>();
}
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */

bool StatusTypeSupportImpl::has_dcps_key()
{
  return TraitsType::gen_has_key();
}

const char* StatusTypeSupportImpl::default_type_name() const
{
  return TraitsType::type_name();
}

void StatusTypeSupportImpl::representations_allowed_by_type(
  ::DDS::DataRepresentationIdSeq& seq)
{
  MarshalTraitsType::representations_allowed_by_type(seq);
}

const OpenDDS::XTypes::TypeIdentifier& StatusTypeSupportImpl::getMinimalTypeIdentifier() const
{
  return OpenDDS::DCPS::getMinimalTypeIdentifier<OpenDDS::DCPS::Status_xtag>();
}

const OpenDDS::XTypes::TypeMap& StatusTypeSupportImpl::getMinimalTypeMap() const
{
  return OpenDDS::DCPS::getMinimalTypeMap<OpenDDS::DCPS::Status_xtag>();
}

const OpenDDS::XTypes::TypeIdentifier& StatusTypeSupportImpl::getCompleteTypeIdentifier() const
{
  static OpenDDS::XTypes::TypeIdentifier ti;
  return ti;
}

const OpenDDS::XTypes::TypeMap& StatusTypeSupportImpl::getCompleteTypeMap() const
{
  static OpenDDS::XTypes::TypeMap tm;
  return tm;
}

OpenDDS::DCPS::Extensibility StatusTypeSupportImpl::getExtensibility() const
{
  return MarshalTraitsType::extensibility();
}

StatusTypeSupport::_ptr_type StatusTypeSupportImpl::_narrow(CORBA::Object_ptr obj)
{
  return TypeSupportType::_narrow(obj);
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
struct MetaStructImpl< ::Status> : MetaStruct {
  typedef  ::Status T;

#ifndef OPENDDS_NO_MULTI_TOPIC
  void* allocate() const { return new T; }

  void deallocate(void* stru) const { delete static_cast<T*>(stru); }

  size_t numDcpsKeys() const { return 1; }

#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool isDcpsKey(const char* field) const
  {
    if (!ACE_OS::strcmp(field, "ID")) {
      return true;
    }
    return false;
  }

  ACE_CDR::ULong map_name_to_id(const char* field) const
  {
    static const std::pair<std::string, ACE_CDR::ULong> name_to_id_pairs[] = {
      std::make_pair("ID", 0),
      std::make_pair("ready", 1),
      std::make_pair("engineTemp", 2),
      std::make_pair("carWeight", 3),
      std::make_pair("rpmStatus", 4),
      std::make_pair("fuelTank", 5),
      std::make_pair("suspensionHealth", 6),
    };
    static const std::map<std::string, ACE_CDR::ULong> name_to_id_map(name_to_id_pairs, name_to_id_pairs + 7);
    std::map<std::string, ACE_CDR::ULong>::const_iterator it = name_to_id_map.find(field);
    if (it == name_to_id_map.end()) {
      throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct ::Status)");
    } else {
      return it->second;
    }
  }

  Value getValue(const void* stru, const char* field) const
  {
    const  ::Status& typed = *static_cast<const  ::Status*>(stru);
    ACE_UNUSED_ARG(typed);
    if (std::strcmp(field, "ID") == 0) {
      return typed.ID;
    }
    if (std::strcmp(field, "ready") == 0) {
      return typed.ready;
    }
    if (std::strcmp(field, "engineTemp") == 0) {
      return typed.engineTemp;
    }
    if (std::strcmp(field, "carWeight") == 0) {
      return typed.carWeight;
    }
    if (std::strcmp(field, "rpmStatus") == 0) {
      return typed.rpmStatus;
    }
    if (std::strcmp(field, "fuelTank") == 0) {
      return typed.fuelTank;
    }
    if (std::strcmp(field, "suspensionHealth") == 0) {
      return typed.suspensionHealth;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct ::Status)");
  }

  Value getValue(Serializer& strm, const char* field) const
  {
    const Encoding& encoding = strm.encoding();
    ACE_UNUSED_ARG(encoding);
  size_t total_size = 0;
  if (encoding.xcdr_version() == Encoding::XCDR_VERSION_2) {
    if (!strm.read_delimiter(total_size)) {
      throw std::runtime_error("Unable to reader delimiter in getValue");
    }
  }
    std::string base_field = field;
    size_t index = base_field.find('.');
    std::string subfield;
    if (index != std::string::npos) {
      subfield = base_field.substr(index + 1);
      base_field = base_field.substr(0, index);
    }
    if (base_field == "ID") {
      ACE_CDR::Long val;
      if (!(strm >> val)) {
        throw std::runtime_error("Field 'ID' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  4 )) {
        throw std::runtime_error("Field 'ID' could not be skipped");
      }
    }
    if (base_field == "ready") {
      ACE_CDR::Octet val;
      if (!(strm >> ACE_InputCDR::to_octet(val))) {
        throw std::runtime_error("Field 'ready' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  1 )) {
        throw std::runtime_error("Field 'ready' could not be skipped");
      }
    }
    if (base_field == "engineTemp") {
      ACE_CDR::Float val;
      if (!(strm >> val)) {
        throw std::runtime_error("Field 'engineTemp' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  4 )) {
        throw std::runtime_error("Field 'engineTemp' could not be skipped");
      }
    }
    if (base_field == "carWeight") {
      ACE_CDR::Float val;
      if (!(strm >> val)) {
        throw std::runtime_error("Field 'carWeight' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  4 )) {
        throw std::runtime_error("Field 'carWeight' could not be skipped");
      }
    }
    if (base_field == "rpmStatus") {
      ACE_CDR::Long val;
      if (!(strm >> val)) {
        throw std::runtime_error("Field 'rpmStatus' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  4 )) {
        throw std::runtime_error("Field 'rpmStatus' could not be skipped");
      }
    }
    if (base_field == "fuelTank") {
      ACE_CDR::Float val;
      if (!(strm >> val)) {
        throw std::runtime_error("Field 'fuelTank' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  4 )) {
        throw std::runtime_error("Field 'fuelTank' could not be skipped");
      }
    }
    if (base_field == "suspensionHealth") {
      ACE_CDR::Float val;
      if (!(strm >> val)) {
        throw std::runtime_error("Field 'suspensionHealth' could not be deserialized");
      }
      return val;
    } else {
      if (!strm.skip(1,  4 )) {
        throw std::runtime_error("Field 'suspensionHealth' could not be skipped");
      }
    }
    if (!field[0]) {
      return 0;
    }
    throw std::runtime_error("Did not find field in getValue");
  }

  ComparatorBase::Ptr create_qc_comparator(const char* field, ComparatorBase::Ptr next) const
  {
    ACE_UNUSED_ARG(next);
    if (std::strcmp(field, "ID") == 0) {
      return make_field_cmp(&T::ID, next);
    }
    if (std::strcmp(field, "ready") == 0) {
      return make_field_cmp(&T::ready, next);
    }
    if (std::strcmp(field, "engineTemp") == 0) {
      return make_field_cmp(&T::engineTemp, next);
    }
    if (std::strcmp(field, "carWeight") == 0) {
      return make_field_cmp(&T::carWeight, next);
    }
    if (std::strcmp(field, "rpmStatus") == 0) {
      return make_field_cmp(&T::rpmStatus, next);
    }
    if (std::strcmp(field, "fuelTank") == 0) {
      return make_field_cmp(&T::fuelTank, next);
    }
    if (std::strcmp(field, "suspensionHealth") == 0) {
      return make_field_cmp(&T::suspensionHealth, next);
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct ::Status)");
  }

#ifndef OPENDDS_NO_MULTI_TOPIC
  const char** getFieldNames() const
  {
    static const char* names[] = {"ID", "ready", "engineTemp", "carWeight", "rpmStatus", "fuelTank", "suspensionHealth", 0};
    return names;
  }

  const void* getRawField(const void* stru, const char* field) const
  {
    if (std::strcmp(field, "ID") == 0) {
      return &static_cast<const T*>(stru)->ID;
    }
    if (std::strcmp(field, "ready") == 0) {
      return &static_cast<const T*>(stru)->ready;
    }
    if (std::strcmp(field, "engineTemp") == 0) {
      return &static_cast<const T*>(stru)->engineTemp;
    }
    if (std::strcmp(field, "carWeight") == 0) {
      return &static_cast<const T*>(stru)->carWeight;
    }
    if (std::strcmp(field, "rpmStatus") == 0) {
      return &static_cast<const T*>(stru)->rpmStatus;
    }
    if (std::strcmp(field, "fuelTank") == 0) {
      return &static_cast<const T*>(stru)->fuelTank;
    }
    if (std::strcmp(field, "suspensionHealth") == 0) {
      return &static_cast<const T*>(stru)->suspensionHealth;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct ::Status)");
  }

  void assign(void* lhs, const char* field, const void* rhs,
    const char* rhsFieldSpec, const MetaStruct& rhsMeta) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    ACE_UNUSED_ARG(rhsFieldSpec);
    ACE_UNUSED_ARG(rhsMeta);
    if (std::strcmp(field, "ID") == 0) {
      static_cast<T*>(lhs)->ID = *static_cast<const  ::CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "ready") == 0) {
      static_cast<T*>(lhs)->ready = *static_cast<const  ::CORBA::Octet*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "engineTemp") == 0) {
      static_cast<T*>(lhs)->engineTemp = *static_cast<const  ::CORBA::Float*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "carWeight") == 0) {
      static_cast<T*>(lhs)->carWeight = *static_cast<const  ::CORBA::Float*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "rpmStatus") == 0) {
      static_cast<T*>(lhs)->rpmStatus = *static_cast<const  ::CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "fuelTank") == 0) {
      static_cast<T*>(lhs)->fuelTank = *static_cast<const  ::CORBA::Float*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "suspensionHealth") == 0) {
      static_cast<T*>(lhs)->suspensionHealth = *static_cast<const  ::CORBA::Float*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct ::Status)");
  }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool compare(const void* lhs, const void* rhs, const char* field) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    if (std::strcmp(field, "ID") == 0) {
      return static_cast<const T*>(lhs)->ID == static_cast<const T*>(rhs)->ID;
    }
    if (std::strcmp(field, "ready") == 0) {
      return static_cast<const T*>(lhs)->ready == static_cast<const T*>(rhs)->ready;
    }
    if (std::strcmp(field, "engineTemp") == 0) {
      return static_cast<const T*>(lhs)->engineTemp == static_cast<const T*>(rhs)->engineTemp;
    }
    if (std::strcmp(field, "carWeight") == 0) {
      return static_cast<const T*>(lhs)->carWeight == static_cast<const T*>(rhs)->carWeight;
    }
    if (std::strcmp(field, "rpmStatus") == 0) {
      return static_cast<const T*>(lhs)->rpmStatus == static_cast<const T*>(rhs)->rpmStatus;
    }
    if (std::strcmp(field, "fuelTank") == 0) {
      return static_cast<const T*>(lhs)->fuelTank == static_cast<const T*>(rhs)->fuelTank;
    }
    if (std::strcmp(field, "suspensionHealth") == 0) {
      return static_cast<const T*>(lhs)->suspensionHealth == static_cast<const T*>(rhs)->suspensionHealth;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct ::Status)");
  }
};

template<>
const MetaStruct& getMetaStruct< ::Status>()
{
  static MetaStructImpl< ::Status> msi;
  return msi;
}

bool gen_skip_over(Serializer& ser,  ::Status*)
{
  ACE_UNUSED_ARG(ser);
  MetaStructImpl< ::Status>().getValue(ser, "");
  return true;
}

} }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: Status */
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

namespace {
XTypes::TypeObject minimal_to0()
{
  return XTypes::TypeObject(XTypes::MinimalTypeObject(XTypes::MinimalStructType(XTypes::IS_APPENDABLE, XTypes::MinimalStructHeader(XTypes::TypeIdentifier(XTypes::TK_NONE), XTypes::MinimalTypeDetail()), XTypes::MinimalStructMemberSeq().append(XTypes::MinimalStructMember(XTypes::CommonStructMember(0, XTypes::TRY_CONSTRUCT1 | XTypes::IS_KEY, XTypes::TypeIdentifier(XTypes::TK_INT32)), XTypes::MinimalMemberDetail(183, 24, 173, 236))).append(XTypes::MinimalStructMember(XTypes::CommonStructMember(1, XTypes::TRY_CONSTRUCT1, XTypes::TypeIdentifier(XTypes::TK_BYTE)), XTypes::MinimalMemberDetail(178, 253, 171, 35))).append(XTypes::MinimalStructMember(XTypes::CommonStructMember(2, XTypes::TRY_CONSTRUCT1, XTypes::TypeIdentifier(XTypes::TK_FLOAT32)), XTypes::MinimalMemberDetail(106, 232, 216, 182))).append(XTypes::MinimalStructMember(XTypes::CommonStructMember(3, XTypes::TRY_CONSTRUCT1, XTypes::TypeIdentifier(XTypes::TK_FLOAT32)), XTypes::MinimalMemberDetail(126, 47, 113, 235))).append(XTypes::MinimalStructMember(XTypes::CommonStructMember(4, XTypes::TRY_CONSTRUCT1, XTypes::TypeIdentifier(XTypes::TK_INT32)), XTypes::MinimalMemberDetail(217, 60, 131, 177))).append(XTypes::MinimalStructMember(XTypes::CommonStructMember(5, XTypes::TRY_CONSTRUCT1, XTypes::TypeIdentifier(XTypes::TK_FLOAT32)), XTypes::MinimalMemberDetail(254, 30, 145, 247))).append(XTypes::MinimalStructMember(XTypes::CommonStructMember(6, XTypes::TRY_CONSTRUCT1, XTypes::TypeIdentifier(XTypes::TK_FLOAT32)), XTypes::MinimalMemberDetail(195, 7, 80, 169))))));
}

XTypes::TypeMap get_minimal_type_map_private()
{
  XTypes::TypeMap tm;
  tm[XTypes::TypeIdentifier(XTypes::EK_MINIMAL, XTypes::EquivalenceHashWrapper(85, 21, 137, 90, 204, 51, 162, 238, 129, 1, 248, 253, 164, 155))] = minimal_to0();
  return tm;
}

}

const XTypes::TypeMap& get_minimal_type_map()
{
  static XTypes::TypeMap tm;
  ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, TheServiceParticipant->get_static_xtypes_lock(), tm);
  if (tm.empty()) {
    tm = get_minimal_type_map_private();
  }
  return tm;
}

} }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

