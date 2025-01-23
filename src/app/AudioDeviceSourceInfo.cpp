#include "AudioDeviceSourceInfo.hpp"
#include "AudioDeviceInfo.hpp"
#include <pulse/def.h>
#include <pulse/introspect.h>
#include <pulse/pulseaudio.h>
#include <string>

DVI::DeviceSouceInfo::DeviceSouceInfo(std::string dv_name, 
                                      std::string dv_desc, 
                                      std::string dv_driver,
                                      pa_source_state dv_state) : 
  DeviceInfo(dv_name, dv_desc, dv_driver),
  device_state(DVI::DeviceSouceInfo::selectStateName(dv_state)){}

std::string DVI::DeviceSouceInfo::getDeviceState(){
  return device_state;
}

std::string DVI::DeviceSouceInfo::selectStateName(pa_source_state dv_state){
  return (dv_state != -1) ? avaliable_state[dv_state] : "Unknown";
}
