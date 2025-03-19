#include "DeviceSinkInfo.hpp"
#include "DeviceInfo.hpp"
#include <cstddef>
#include <memory>
#include <pulse/def.h>
#include <pulse/introspect.h>
#include <string>

namespace DVI {
  
  DeviceSinkInfo::DeviceSinkInfo(){}  
  DeviceSinkInfo::~DeviceSinkInfo(){}

  void DeviceSinkInfo::setupDevice(const pa_sink_info& info){
    setDeviceName(info.name);
    setDeviceDescription(info.description);
    setDeviceDriver(info.driver);
    stateToString(info.state, avaliable_state);
    addDevicePort(info.ports,info.active_port);
  }

  std::unique_ptr<DeviceInfo> DeviceSinkInfo::clone(){
    return std::make_unique<DeviceSinkInfo>(*this);
  }
}
