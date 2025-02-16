#include "DeviceInfo.hpp"
#include "DeviceSourceInfo.hpp"
#include <cstddef>
#include <pulse/def.h>
#include <pulse/introspect.h>
#include <string>

namespace DVI {
  
  DeviceSourceInfo::DeviceSourceInfo(const pa_source_info& info) :
    DeviceInfo(info.name, info.description, info.driver),
    device_source_state(info.state),
    device_source_ports(info.ports),
    device_active_port(info.active_port){}

  void DeviceSourceInfo::stateToString(){
    device_state = (device_source_state != -1) ? avaliable_state[device_source_state] : "Unknown";
  }
  
  void DeviceSourceInfo::addDevicePort(){
    
    for(pa_source_port_info** s_ports = device_source_ports; (*s_ports) != NULL; s_ports++){
      if((*s_ports) == device_active_port){
        device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Active"});   
      }
      else{
        device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Inactive"});   
      }
    } 
  }

}

