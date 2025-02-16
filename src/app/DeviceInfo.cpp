#include "DeviceInfo.hpp"
#include <cstddef>
#include <string>
#include <vector>
#include <pulse/introspect.h>

namespace  DVI {

DeviceInfo::DeviceInfo(std::string dv_name,
                       std::string dv_desc,
                       std::string dv_driver) :
  device_name(dv_name),
  device_description(dv_desc),
  device_driver(dv_driver)
  {
    device_state = std::string();
    device_ports = std::vector<port_info>();
  }

DVI::DeviceInfo::~DeviceInfo(){}

std::string DeviceInfo::getDeviceName(){
  return device_name;
}

std::string DeviceInfo::getDeviceDescription(){
  return device_description;
}

std::string DeviceInfo::getDeviceDriver(){
  return device_driver;
}

std::string DeviceInfo::getDeviceState(){
  return device_state;
}

std::vector<port_info> DeviceInfo::getDevicePorts(){
  return device_ports;
}

}
