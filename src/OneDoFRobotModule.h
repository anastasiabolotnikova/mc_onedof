#pragma once

#include <mc_rbdyn/RobotModule.h>

#include <mc_robots/api.h>

namespace mc_robots
{

struct MC_ROBOTS_DLLAPI OneDoFRobotModule : public mc_rbdyn::RobotModule
{
  OneDoFRobotModule();
};

} // namespace mc_robots

extern "C"
{
  ROBOT_MODULE_API void MC_RTC_ROBOT_MODULE(std::vector<std::string> & names)
  {
    names = {"OneDoF"};
  }
  ROBOT_MODULE_API void destroy(mc_rbdyn::RobotModule * ptr)
  {
    delete ptr;
  }
  ROBOT_MODULE_API mc_rbdyn::RobotModule * create(const std::string & n)
  {
    if(n == "OneDoF")
    {
      return new mc_robots::OneDoFRobotModule();
    }
    else
    {
      mc_rtc::log::error("[mc_onedof] OneDoF module cannot create an object of type {}", n);
      return nullptr;
    }
  }
}
