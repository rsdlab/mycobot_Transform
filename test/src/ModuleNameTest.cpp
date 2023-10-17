// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ModuleNameTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "ModuleNameTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const modulename_spec[] =
#else
static const char* modulename_spec[] =
#endif
  {
    "implementation_id", "ModuleNameTest",
    "type_name",         "ModuleNameTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "rsdlab",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.robotPoseX", "0",
    "conf.default.robotPoseY", "0",
    "conf.default.robotPoseZ", "0",
    "conf.default.robotPoseRoll", "0",
    "conf.default.robotPosePitch", "0",
    "conf.default.robotPoseYaw", "0",

    // Widget
    "conf.__widget__.robotPoseX", "text",
    "conf.__widget__.robotPoseY", "text",
    "conf.__widget__.robotPoseZ", "text",
    "conf.__widget__.robotPoseRoll", "text",
    "conf.__widget__.robotPosePitch", "text",
    "conf.__widget__.robotPoseYaw", "text",
    // Constraints

    "conf.__type__.robotPoseX", "double",
    "conf.__type__.robotPoseY", "double",
    "conf.__type__.robotPoseZ", "double",
    "conf.__type__.robotPoseRoll", "double",
    "conf.__type__.robotPosePitch", "double",
    "conf.__type__.robotPoseYaw", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ModuleNameTest::ModuleNameTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_ArucoMakerPoseOut("ArucoMakerPose", m_ArucoMakerPose),
    m_mycobotPoseOut("mycobotPose", m_mycobotPose),
    m_TransformedPoseIn("TransformedPose", m_TransformedPose)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ModuleNameTest::~ModuleNameTest()
{
}



RTC::ReturnCode_t ModuleNameTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("TransformedPose", m_TransformedPoseIn);
  
  // Set OutPort buffer
  addOutPort("ArucoMakerPose", m_ArucoMakerPoseOut);
  addOutPort("mycobotPose", m_mycobotPoseOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("robotPoseX", m_robotPoseX, "0");
  bindParameter("robotPoseY", m_robotPoseY, "0");
  bindParameter("robotPoseZ", m_robotPoseZ, "0");
  bindParameter("robotPoseRoll", m_robotPoseRoll, "0");
  bindParameter("robotPosePitch", m_robotPosePitch, "0");
  bindParameter("robotPoseYaw", m_robotPoseYaw, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ModuleNameTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t ModuleNameTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ModuleNameTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t ModuleNameTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ModuleNameTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ModuleNameTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t ModuleNameTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ModuleNameTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ModuleNameTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ModuleNameTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ModuleNameTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool ModuleNameTest::runTest()
{
    return true;
}


extern "C"
{
 
  void ModuleNameTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(modulename_spec);
    manager->registerFactory(profile,
                             RTC::Create<ModuleNameTest>,
                             RTC::Delete<ModuleNameTest>);
  }
  
}
