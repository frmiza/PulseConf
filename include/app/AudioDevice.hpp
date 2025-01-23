#ifndef AUDIO_DEVICE_HPP
#define AUDIO_DEVICE_HPP

#include <stdlib.h>
#include <pulse/pulseaudio.h>

namespace ADV {

class AudioDevice{
  
private:
  pa_mainloop *mainloop;
  pa_mainloop_api *api;
  
protected:
  pa_context *context;
  void runMainLoop();

public:
  
  AudioDevice();
  ~AudioDevice();
  
  virtual void readAudioDevices() = 0;
};

}
#endif // AUDIO_DEVICE_HPP
