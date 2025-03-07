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

  void DeviceSinkInfo::stateToString(pa_sink_state state){
    
    if(!state) {return;}
    device_state = (state != -1) ? avaliable_state[state] : "Unknown";
  }
 
  void DeviceSinkInfo::addDevicePort(pa_sink_port_info** ports, pa_sink_port_info* active_port){
    
    if(!ports || !active_port) {return;}

    for(pa_sink_port_info** s_ports = ports; (*s_ports) != NULL; s_ports++){
      if((*s_ports) == active_port){
        device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Active"});   
      }
      else{
        device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Inactive"});   
      }
    } 
  }

  void DeviceSinkInfo::setupDevice(const pa_sink_info& info){
    setDeviceName(info.name);
    setDeviceDescription(info.description);
    setDeviceDriver(info.driver);
    stateToString(info.state);
    addDevicePort(info.ports,info.active_port);
  }

  std::unique_ptr<DeviceInfo> DeviceSinkInfo::clone(){
    return std::make_unique<DeviceSinkInfo>(*this);
  }
}
