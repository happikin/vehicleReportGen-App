// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2a_p23
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:151

#ifndef _TAO_IDL__HOME_HAPPIKIN_DEV_PROJECTS_MAJORPROJECT_EX2_BUILD_OPENDDS_GENERATED_STATUSC_H_
#define _TAO_IDL__HOME_HAPPIKIN_DEV_PROJECTS_MAJORPROJECT_EX2_BUILD_OPENDDS_GENERATED_STATUSC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/ORB.h"
#include "tao/Basic_Types_IDLv4.h"
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{
  using namespace IDLv4;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 2 || TAO_BETA_VERSION != 0
#error This file should be regenerated with TAO_IDL
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 
// TAO_IDL - Generated from
// be/be_type.cpp:260



struct Status;

typedef
  ::TAO_Fixed_Var_T<
      Status
    >
  Status_var;

typedef
  Status &
  Status_out;


// TAO_IDL - Generated from
// be/be_visitor_structure/structure_ch.cpp:50



struct  Status
{
  // TAO_IDL - Generated from
  // be/be_type.cpp:304

  
  typedef Status_var _var_type;
  typedef Status_out _out_type;
  
  ::CORBA::Long ID;
  ::CORBA::Octet ready;
  ::CORBA::Float engineTemp;
  ::CORBA::Float carWeight;
  ::CORBA::Long rpmStatus;
  ::CORBA::Float fuelTank;
  ::CORBA::Float suspensionHealth;
};
// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:66



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:934

  

  template<>
  class Arg_Traits< ::Status>
    : public
        Fixed_Size_Arg_Traits_T<
            ::Status,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:60



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:45


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const Status &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, Status &);

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// be/be_codegen.cpp:1657

#if defined (__ACE_INLINE__)
#include "StatusC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */
