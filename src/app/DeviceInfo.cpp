#include "DeviceInfo.hpp"
#include <string>
#include <vector>
#include <pulse/introspect.h>

namespace  DVI {

DeviceInfo::DeviceInfo(){
  device_name =  std::string();
  device_description = std::string();
  device_driver = std::string();
  device_state = std::string();
  device_ports = std::vector<port_info>();
}

DVI::DeviceInfo::~DeviceInfo(){}

void DeviceInfo::setDeviceName(std::string dv_name){
  device_name = dv_name;
}

void DeviceInfo::setDeviceDescription(std::string dv_description){
  device_description = dv_description;
}

void DeviceInfo::setDeviceDriver(std::string dv_driver){
  device_driver = dv_driver;
}

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
