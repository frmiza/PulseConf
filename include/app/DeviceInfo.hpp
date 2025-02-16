#ifndef AUDIO_DEVICE_INFO_HPP
#define AUDIO_DEVICE_INFO_HPP

#include "PortInfo.hpp"
#include <string>
#include <map>
#include <vector>
#include <pulse/introspect.h>
#include <pulse/pulseaudio.h>
#include <pulse/def.h>

namespace DVI {
  
class DeviceInfo {

protected:
  std::string device_name;
  std::string device_description;
  std::string device_driver;
  std::string device_state;
  std::vector<port_info> device_ports;

public:

  DeviceInfo(std::string dv_name, 
                  std::string dv_desc, 
                  std::string dv_driver);
  
  virtual ~DeviceInfo();
  
  virtual void stateToString() = 0;
  virtual void addDevicePort() = 0; 

  std::string getDeviceName();
  std::string getDeviceDescription();
  std::string getDeviceDriver();
  std::string getDeviceState();
  std::vector<port_info> getDevicePorts();

};

}

#endif // AUDIO_DEVICE_INFO_HPP
