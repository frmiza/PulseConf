#include "DeviceSourceInfo.hpp"
#include <cstddef>
#include <pulse/def.h>
#include <pulse/introspect.h>
#include <string>

namespace DVI {
  
  DeviceSourceInfo::DeviceSourceInfo(){}  

  void DeviceSourceInfo::stateToString(pa_source_state state){
    device_state = (state != -1) ? avaliable_state[state] : "Unknown";
  }
 
  void DeviceSourceInfo::addDevicePort(pa_source_port_info** ports, pa_source_port_info* active_port){
    
    for(pa_source_port_info** s_ports = ports; (*s_ports) != NULL; s_ports++){
      if((*s_ports) == active_port){
        device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Active"});   
      }
      else{
        device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Inactive"});   
      }
    } 
  }

  void DeviceSourceInfo::setupDevice(const pa_source_info& info){
    setDeviceName(info.name);
    setDeviceDescription(info.description);
    setDeviceDriver(info.driver);
    stateToString(info.state);
    addDevicePort(info.ports, info.active_port);
  }
}

