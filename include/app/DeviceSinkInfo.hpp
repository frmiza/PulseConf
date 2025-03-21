#ifndef DEVICE_SINK_INFO_HPP
#define DEVICE_SINK_INFO_HPP

#include "DeviceInfo.hpp"
#include <memory>
#include <map>
#include <pulse/def.h>
#include <pulse/introspect.h>

namespace DVI{

class DeviceSinkInfo : public DeviceInfo{
  
public:

  const std::map<pa_sink_state, std::string> avaliable_state{
    {PA_SINK_RUNNING, "RUNNING"}, 
    {PA_SINK_IDLE, "IDLE"}, 
    {PA_SINK_SUSPENDED, "SUSPENDED"}
  };
  
  DeviceSinkInfo();
  ~DeviceSinkInfo() override;

  void setupDevice(const pa_sink_info& info);
  std::unique_ptr<DeviceInfo> clone() override;

};
}

#endif // DEVICE_SINK_INFO_HPP
