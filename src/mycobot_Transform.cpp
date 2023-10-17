// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  mycobot_Transform.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "mycobot_Transform.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const mycobot_transform_spec[] =
#else
static const char* mycobot_transform_spec[] =
#endif
    {"implementation_id", "mycobot_Transform", "type_name", "mycobot_Transform",
     "description", "ModuleDescription", "version", "1.0.0", "vendor", "rsdlab",
     "category", "Category", "activity_type", "PERIODIC", "kind",
     "DataFlowComponent", "max_instance", "1", "language", "C++", "lang_type",
     "compile",
     // Configuration variables
     "conf.default.cameraPoseX", "0", "conf.default.cameraPoseY", "0",
     "conf.default.cameraPoseZ", "0", "conf.default.cameraPoseRoll", "0",
     "conf.default.cameraPosePitch", "0", "conf.default.cameraPoseYaw", "0",

     // Widget
     "conf.__widget__.cameraPoseX", "text", "conf.__widget__.cameraPoseY",
     "text", "conf.__widget__.cameraPoseZ", "text",
     "conf.__widget__.cameraPoseRoll", "text",
     "conf.__widget__.cameraPosePitch", "text", "conf.__widget__.cameraPoseYaw",
     "text",
     // Constraints

     "conf.__type__.cameraPoseX", "double", "conf.__type__.cameraPoseY",
     "double", "conf.__type__.cameraPoseZ", "double",
     "conf.__type__.cameraPoseRoll", "double", "conf.__type__.cameraPosePitch",
     "double", "conf.__type__.cameraPoseYaw", "double",

     ""};
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
mycobot_Transform::mycobot_Transform(RTC::Manager* manager)
    // <rtc-template block="initializer">
    : RTC::DataFlowComponentBase(manager),
      m_ArucoMakerPoseIn("ArucoMakerPose", m_ArucoMakerPose),
      m_mycobotPoseIn("mycobotPose", m_mycobotPose),
      m_TransformedPoseOut("TransformedPose", m_TransformedPose)
// </rtc-template>
{}

/*!
 * @brief destructor
 */
mycobot_Transform::~mycobot_Transform() {}

RTC::ReturnCode_t mycobot_Transform::onInitialize() {
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("ArucoMakerPose", m_ArucoMakerPoseIn);
  addInPort("mycobotPose", m_mycobotPoseIn);

  // Set OutPort buffer
  addOutPort("TransformedPose", m_TransformedPoseOut);

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
RTC::ReturnCode_t mycobot_Transform::onFinalize()
{
  return RTC::RTC_OK;
}
*/

// RTC::ReturnCode_t mycobot_Transform::onStartup(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

// RTC::ReturnCode_t mycobot_Transform::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

RTC::ReturnCode_t mycobot_Transform::onActivated(RTC::UniqueId /*ec_id*/) {
  return RTC::RTC_OK;
}

RTC::ReturnCode_t mycobot_Transform::onDeactivated(RTC::UniqueId /*ec_id*/) {
  return RTC::RTC_OK;
}

RTC::ReturnCode_t mycobot_Transform::onExecute(RTC::UniqueId /*ec_id*/) {
  if (m_ArucoMakerPoseIn.isNew()) {
    std::cout << "Received ID" << std::endl;
    m_ArucoMakerPoseIn.read();
    RTC::TimedPose3D MakerPose;

    MakerPose.data.position.x = m_ArucoMakerPose.translates[0].x;
    MakerPose.data.position.y = m_ArucoMakerPose.translates[0].y;
    MakerPose.data.position.z = m_ArucoMakerPose.translates[0].z;

    m_TransformedPose.data.position.x =
        m_cameraPoseX + MakerPose.data.position.x;
    m_TransformedPose.data.position.y =
        m_cameraPoseY + MakerPose.data.position.y;
    m_TransformedPose.data.position.z =
        m_cameraPoseZ + MakerPose.data.position.z;

    m_TransformedPoseOut.write(m_TransformedPose);
  }

  return RTC::RTC_OK;
}

// RTC::ReturnCode_t mycobot_Transform::onAborting(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

// RTC::ReturnCode_t mycobot_Transform::onError(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

// RTC::ReturnCode_t mycobot_Transform::onReset(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

// RTC::ReturnCode_t mycobot_Transform::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

// RTC::ReturnCode_t mycobot_Transform::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//   return RTC::RTC_OK;
// }

extern "C" {

void mycobot_TransformInit(RTC::Manager* manager) {
  coil::Properties profile(mycobot_transform_spec);
  manager->registerFactory(profile, RTC::Create<mycobot_Transform>,
                           RTC::Delete<mycobot_Transform>);
}
}
