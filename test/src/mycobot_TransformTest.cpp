// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  mycobot_TransformTest.cpp
 * @brief ModuleDescription (test code)
 *
 */
// </rtc-template>

#include "mycobot_TransformTest.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const mycobot_transform_spec[] =
#else
static const char* mycobot_transform_spec[] =
#endif
  {
    "implementation_id", "mycobot_TransformTest",
    "type_name",         "mycobot_TransformTest",
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
    "conf.default.cameraPoseX", "0",
    "conf.default.cameraPoseY", "0",
    "conf.default.cameraPoseZ", "0",
    "conf.default.cameraPoseRoll", "0",
    "conf.default.cameraPosePitch", "0",
    "conf.default.cameraPoseYaw", "0",

    // Widget
    "conf.__widget__.cameraPoseX", "text",
    "conf.__widget__.cameraPoseY", "text",
    "conf.__widget__.cameraPoseZ", "text",
    "conf.__widget__.cameraPoseRoll", "text",
    "conf.__widget__.cameraPosePitch", "text",
    "conf.__widget__.cameraPoseYaw", "text",
    // Constraints

    "conf.__type__.cameraPoseX", "double",
    "conf.__type__.cameraPoseY", "double",
    "conf.__type__.cameraPoseZ", "double",
    "conf.__type__.cameraPoseRoll", "double",
    "conf.__type__.cameraPosePitch", "double",
    "conf.__type__.cameraPoseYaw", "double",

    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
mycobot_TransformTest::mycobot_TransformTest(RTC::Manager* manager)
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
mycobot_TransformTest::~mycobot_TransformTest()
{
}



RTC::ReturnCode_t mycobot_TransformTest::onInitialize()
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
  bindParameter("cameraPoseX", m_cameraPoseX, "0");
  bindParameter("cameraPoseY", m_cameraPoseY, "0");
  bindParameter("cameraPoseZ", m_cameraPoseZ, "0");
  bindParameter("cameraPoseRoll", m_cameraPoseRoll, "0");
  bindParameter("cameraPosePitch", m_cameraPosePitch, "0");
  bindParameter("cameraPoseYaw", m_cameraPoseYaw, "0");
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t mycobot_TransformTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t mycobot_TransformTest::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t mycobot_TransformTest::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t mycobot_TransformTest::onActivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t mycobot_TransformTest::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t mycobot_TransformTest::onExecute(RTC::UniqueId /*ec_id*/)
{
  return RTC::RTC_OK;
}


//RTC::ReturnCode_t mycobot_TransformTest::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t mycobot_TransformTest::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t mycobot_TransformTest::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t mycobot_TransformTest::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t mycobot_TransformTest::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


bool mycobot_TransformTest::runTest()
{
    return true;
}


extern "C"
{
 
  void mycobot_TransformTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(mycobot_transform_spec);
    manager->registerFactory(profile,
                             RTC::Create<mycobot_TransformTest>,
                             RTC::Delete<mycobot_TransformTest>);
  }
  
}
