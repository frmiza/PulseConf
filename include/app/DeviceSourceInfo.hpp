#ifndef DEVICE_SOURCE_INFO_HPP
#define DEVICE_SOURCE_INFO_HPP

#include "DeviceInfo.hpp"
#include <pulse/def.h>
#include <pulse/introspect.h>

namespace DVI{

class DeviceSourceInfo : public DeviceInfo{
  
public:

  DeviceSourceInfo();

  void stateToString(void* state) override;
  void addDevicePort(void* ports, void* active_port) override;
  
  void setupDevice(const pa_source_info& info);

};
}

#endif // DEVICE_SOURCE_INFO_HPP
