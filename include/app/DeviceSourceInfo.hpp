#ifndef DEVICE_SOURCE_INFO_HPP
#define DEVICE_SOURCE_INFO_HPP

#include "DeviceInfo.hpp"
#include <string>
#include <map>
#include <pulse/def.h>
#include <pulse/introspect.h>

namespace DVI{

class DeviceSourceInfo : public DeviceInfo{

std::map<pa_source_state, std::string> avaliable_state{
  {PA_SOURCE_RUNNING, "RUNNING"}, 
  {PA_SOURCE_IDLE, "IDLE"}, 
  {PA_SOURCE_SUSPENDED, "SUSPENDED"}
};
  
public:

  DeviceSourceInfo();

  void stateToString(pa_source_state state);
  void addDevicePort(pa_source_port_info** ports, pa_source_port_info* active_port);
  void setupDevice(const pa_source_info& info);

};
}

#endif // DEVICE_SOURCE_INFO_HPP
