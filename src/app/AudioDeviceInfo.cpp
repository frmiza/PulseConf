#include "AudioDeviceInfo.hpp"

DVI::DeviceInfo::DeviceInfo(std::string dv_name, 
                            std::string dv_desc, 
                            std::string dv_driver) : 
  device_name(dv_name), 
  device_description(dv_desc), 
  device_driver(dv_driver) {}

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

const std::array<std::string, 3> DVI::DeviceInfo::avaliable_state = {
    "Active",
    "Inactive",
    "Suspended"
};

