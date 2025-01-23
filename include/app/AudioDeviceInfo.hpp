#ifndef AUDIO_DEVICE_INFO_HPP
#define AUDIO_DEVICE_INFO_HPP

#include <string>
#include <array>
#include <pulse/introspect.h>
#include <pulse/def.h>
#include <pulse/pulseaudio.h>

namespace DVI {
  
class DeviceInfo {
 
private:
  std::string device_name;
  std::string device_description;
  std::string device_driver;

protected:

  static const std::array<std::string,3> avaliable_state;

public:

  DeviceInfo(std::string dv_name, std::string dv_desc, std::string dv_driver);
  ~DeviceInfo();
  
  std::string getDeviceName();
  std::string getDeviceDescription();
  std::string getDeviceDriver();

};

}

#endif // AUDIO_DEVICE_INFO_HPP
