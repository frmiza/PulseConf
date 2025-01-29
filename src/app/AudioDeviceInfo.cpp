#include "AudioDeviceInfo.hpp"
#include <cstddef>
#include <vector>
#include <pulse/introspect.h>

const std::array<std::string, 3> DVI::DeviceInfo::avaliable_state = {
    "Active",
    "Inactive",
    "Suspended"
};

DVI::DeviceInfo::DeviceInfo(std::string dv_name,
                            std::string dv_desc,
                            std::string dv_driver,
                            pa_source_state dv_state,
                            pa_source_port_info** dv_ports,
                            pa_source_port_info* dv_active_ports) :
  device_name(dv_name),
  device_description(dv_desc),
  device_driver(dv_driver),
  device_state(selectStateName(dv_state)),
  device_ports(addDevicePort(dv_ports, dv_active_ports)){}

DVI::DeviceInfo::~DeviceInfo(){}

std::string DVI::DeviceInfo::selectStateName(pa_source_state dv_state){
  return (dv_state != -1) ? avaliable_state[dv_state] : "Unknown";
}

std::vector<port_info> DVI::DeviceInfo::addDevicePort(pa_source_port_info** dv_ports, pa_source_port_info* dv_active_ports){
  
  std::vector<port_info> info_ports;

  for (pa_source_port_info** ports = dv_ports; (*ports) != NULL; ports++) {
    if((*ports) == dv_active_ports){
      info_ports.push_back({(*ports)->name, (*ports)->description, "Active"});
    } else {
      info_ports.push_back({(*ports)->name, (*ports)->description, "Inactive"});
    }
  }

  return info_ports;
}

std::string DVI::DeviceInfo::getDeviceName(){
  return device_name;
}

std::string DVI::DeviceInfo::getDeviceDescription(){
  return device_description;
}

std::string DVI::DeviceInfo::getDeviceDriver(){
  return device_driver;
}

std::string DVI::DeviceInfo::getDeviceState(){
  return device_state;
}

std::vector<port_info> DVI::DeviceInfo::getDevicePorts(){
  return device_ports;
}
