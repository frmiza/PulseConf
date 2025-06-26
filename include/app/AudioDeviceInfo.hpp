#ifndef AUDIO_DEVICE_INFO_HPP
#define AUDIO_DEVICE_INFO_HPP

#include "PortInfo.hpp"
#include <string>
#include <array>
#include <pulse/introspect.h>
#include <pulse/def.h>
#include <pulse/pulseaudio.h>
#include <vector>

namespace DVI {
  
class DeviceInfo {
 
private:
  std::string device_name;
  std::string device_description;
  std::string device_driver;
  std::string device_state;
  std::vector<port_info> device_ports;

  std::string selectStateName(pa_source_state device_state);
  std::string addDevicePort(pa_source_state device_state);

protected:

  static const std::array<std::string,3> avaliable_state;

public:

  DeviceInfo(std::string dv_name, 
                  std::string dv_desc, 
                  std::string dv_driver,
                  pa_source_state dv_state);
  
  DeviceInfo(std::string dv_name, 
                  std::string dv_desc, 
                  std::string dv_driver,
                  pa_sink_state dv_state,
                  pa_sink_port_info** dv_ports);
  
  ~DeviceInfo();
  
  std::string getDeviceName();
  std::string getDeviceDescription();
  std::string getDeviceDriver();
  std::string getDeviceState();
  std::vector<port_info> getPortInfo();

};

}

#endif // AUDIO_DEVICE_INFO_HPP
