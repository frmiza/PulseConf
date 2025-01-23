#ifndef AUDIO_DEVICE_SOURCE_INFO_HPP
#define AUDIO_DEVICE_SOURCE_INFO_HPP

#include "AudioDeviceInfo.hpp"
#include <pulse/def.h>
#include <pulse/pulseaudio.h>
#include <string>
#include <vector>

namespace DVI {
  
class DeviceSouceInfo : public DeviceInfo {
 
private:
  std::string device_state;
  std::vector<pa_source_port_info> source_ports;

  std::string selectStateName(pa_source_state device_state);

public:

  DeviceSouceInfo(std::string dv_name, 
                  std::string dv_desc, 
                  std::string dv_driver,
                  pa_source_state dv_state);
  
  std::string getDeviceState();
  std::vector<pa_source_port_info> getSourcePorts();

};

}

#endif // AUDIO_DEVICE_SOURCE_INFO_HPP
