#include "DeviceSourceInfo.hpp"
#include "DeviceInfo.hpp"
#include <memory>
#include <pulse/def.h>
#include <pulse/introspect.h>
#include <string>

namespace DVI {
  
  DeviceSourceInfo::DeviceSourceInfo(){}  
  DeviceSourceInfo::~DeviceSourceInfo(){}

  void DeviceSourceInfo::setupDevice(const pa_source_info& info){
    setDeviceName(info.name);
    setDeviceDescription(info.description);
    setDeviceDriver(info.driver);
    stateToString(info.state, avaliable_state);
    addDevicePort(info.ports,info.active_port);
  }

  std::unique_ptr<DeviceInfo> DeviceSourceInfo::clone(){
    return std::make_unique<DeviceSourceInfo>(*this);
  }
}
