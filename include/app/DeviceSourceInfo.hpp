#ifndef DEVICE_SOURCE_INFO_HPP
#define DEVICE_SOURCE_INFO_HPP

#include "DeviceInfo.hpp"
#include <memory>
#include <pulse/def.h>
#include <pulse/introspect.h>

namespace DVI{

class DeviceSourceInfo : public DeviceInfo{
  
public:

  const std::map<pa_source_state, std::string> avaliable_state{
    {PA_SOURCE_RUNNING, "RUNNING"}, 
    {PA_SOURCE_IDLE, "IDLE"}, 
    {PA_SOURCE_SUSPENDED, "SUSPENDED"}
  };
  
  DeviceSourceInfo();
  ~DeviceSourceInfo() override;

  void setupDevice(const pa_source_info& info);
  std::unique_ptr<DeviceInfo> clone() override;

};
}

#endif // DEVICE_SOURCE_INFO_HPP
