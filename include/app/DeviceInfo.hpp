#ifndef AUDIO_DEVICE_INFO_HPP
#define AUDIO_DEVICE_INFO_HPP

#include "PortInfo.hpp"
#include <cstdlib>
#include <map>
#include <memory>
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

  DeviceInfo();
  
  template<typename T_state>
  void stateToString(T_state state, const std::map<T_state, std::string>& state_map);
  
  template <typename T_PortInfo>
  void addDevicePort(T_PortInfo** ports, T_PortInfo* active_port);

  virtual ~DeviceInfo();
  virtual std::unique_ptr<DeviceInfo> clone() = 0;
  
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

#include "DeviceInfo.ipp"

#endif // AUDIO_DEVICE_INFO_HPP
