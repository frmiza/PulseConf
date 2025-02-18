#ifndef AUDIO_DEVICE_INFO_HPP
#define AUDIO_DEVICE_INFO_HPP

#include "PortInfo.hpp"
#include <cstdlib>
#include <map>
#include <string>
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

  std::map<pa_source_state, std::string> avaliable_state{
    {PA_SOURCE_RUNNING, "RUNNING"}, 
    {PA_SOURCE_IDLE, "IDLE"}, 
    {PA_SOURCE_SUSPENDED, "SUSPENDED"}
  };

  DeviceInfo();
  
  virtual ~DeviceInfo();

  virtual void stateToString(void* state) = 0;
  virtual void addDevicePort(void* ports, void* active_port) = 0;

  void setDeviceName(std::string dv_name);
  void setDeviceDescription(std::string dv_description);
  void setDeviceDriver(std::string dv_driver);
  
  std::string getDeviceName();
  std::string getDeviceDescription();
  std::string getDeviceDriver();
  std::string getDeviceState();
  std::vector<port_info> getDevicePorts();

};

}

#endif // AUDIO_DEVICE_INFO_HPP
