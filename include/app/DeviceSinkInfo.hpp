#ifndef DEVICE_SINK_INFO_HPP
#define DEVICE_SINK_INFO_HPP

#include "DeviceInfo.hpp"
#include <memory>
#include <pulse/def.h>
#include <pulse/introspect.h>

namespace DVI{

class DeviceSinkInfo : public DeviceInfo{
  
public:
  DeviceSinkInfo();
  ~DeviceSinkInfo() override;

  void stateToString(pa_sink_state state);
  void addDevicePort(pa_sink_port_info** ports, pa_sink_port_info* active_port);
  
  void setupDevice(const pa_sink_info& info);
  std::unique_ptr<DeviceInfo> clone() override;

};
}

#endif // DEVICE_SINK_INFO_HPP
