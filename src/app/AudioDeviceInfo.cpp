#include "AudioDeviceInfo.hpp"

DVI::DeviceInfo::DeviceInfo(std::string dv_name, 
                            std::string dv_desc, 
                            std::string dv_driver,
                            pa_source_state dv_state) : 
  device_name(dv_name),
  device_description(dv_desc), 
  device_driver(dv_driver),
  device_state(selectStateName(dv_state)){}

DVI::DeviceInfo::~DeviceInfo(){}

std::string DVI::DeviceInfo::getDeviceName(){
  return device_name;
}

std::string DVI::DeviceInfo::getDeviceDescription(){
  return device_description;
}

std::string DVI::DeviceInfo::getDeviceDriver(){
  return device_driver;
}

std::string DVI::DeviceInfo::selectStateName(pa_source_state dv_state){
  return (dv_state != -1) ? avaliable_state[dv_state] : "Unknown";
}

const std::array<std::string, 3> DVI::DeviceInfo::avaliable_state = {
    "Active",
    "Inactive",
    "Suspended"
};

