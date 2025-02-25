#ifndef DEVICE_SOURCE_INFO_HPP
#define DEVICE_SOURCE_INFO_HPP

#include "DeviceInfo.hpp"
#include <memory>
#include <pulse/def.h>
#include <pulse/introspect.h>

namespace DVI{

class DeviceSourceInfo : public DeviceInfo{
  
public:
  DeviceSourceInfo();
  ~DeviceSourceInfo() override;

  void stateToString(pa_source_state state);
  void addDevicePort(pa_source_port_info** ports, pa_source_port_info* active_port);
  
  void setupDevice(const pa_source_info& info);
  std::unique_ptr<DeviceInfo> clone() override;

};
}

#endif // DEVICE_SOURCE_INFO_HPP
