#ifndef AUDIO_DEVICE_HPP
#define AUDIO_DEVICE_HPP

#include "DeviceInfo.hpp"
#include <vector>
#include<memory>
#include <pulse/pulseaudio.h>

namespace ADV {

class AudioDevice{
  
private:
  pa_mainloop *mainloop;
  pa_mainloop_api *api;
  
protected:
  bool devices_read;
  std::vector<DVI::DeviceInfo*> device_info;
  pa_context *context;
  void runMainLoop();

public:
  
  AudioDevice();
  ~AudioDevice();
  
  std::vector<DVI::DeviceInfo*> getSourceInfo();
};

}
#endif // AUDIO_DEVICE_HPP
