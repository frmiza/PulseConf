#include "DeviceSourceInfo.hpp"
#include <cstddef>
#include <pulse/def.h>
#include <pulse/introspect.h>
#include <string>

namespace DVI {
  
  DeviceSourceInfo::DeviceSourceInfo(){}  

  void DeviceSourceInfo::stateToString(void* state){
    
    if(!state) {return;}
    pa_source_state* c_state = static_cast<pa_source_state*>(state);
    device_state = (*(c_state) != -1) ? avaliable_state[*(c_state)] : "Unknown";
  }
 
  void DeviceSourceInfo::addDevicePort(void* ports, void* active_port){
    
    if(!ports || !active_port) {return;}
    pa_source_port_info** c_ports = static_cast<pa_source_port_info**>(ports);
    pa_source_port_info* c_active_port = static_cast<pa_source_port_info*>(active_port);

    for(pa_source_port_info** s_ports = c_ports; (*s_ports) != NULL; s_ports++){
      if((*s_ports) == c_active_port){
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
    stateToString(static_cast<void*>(const_cast<pa_source_state*>(&info.state)));
    addDevicePort(static_cast<void*>(info.ports),
                  static_cast<void*>(info.active_port));
  }
}

