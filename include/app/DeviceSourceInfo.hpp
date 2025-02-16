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

private:
  
  pa_source_state device_source_state;
  pa_source_port_info** device_source_ports;
  pa_source_port_info* device_active_port;

public:

  DeviceSourceInfo(const pa_source_info& info);
  
  void stateToString() override;
  void addDevicePort() override;

};
}

#endif // DEVICE_SOURCE_INFO_HPP
