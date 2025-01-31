#ifndef AUDIO_DEVICE_IN_HPP
#define AUDIO_DEVICE_IN_HPP

#include "AudioDevice.hpp"
#include "AudioDeviceInfo.hpp"

namespace  ADV {

class AudioDeviceInput : public AudioDevice {
  
  
private:

  static void stateInfoCallback(pa_context *context, void *userdata);
  static void sourceInfoCallback(pa_context *context, const pa_source_info *info, int eol, void *userdata);

public:
  
  AudioDeviceInput();
  void readAudioDevices() override;
  void addDeviceInfo(DVI::DeviceInfo* device_info) override;

};

}

#endif // AUDIO_DEVICE_IN_HPP


