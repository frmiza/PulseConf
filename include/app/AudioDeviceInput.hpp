#ifndef AUDIO_DEVICE_IN_HPP
#define AUDIO_DEVICE_IN_HPP

#include <vector>
#include "AudioDevice.hpp"
#include "AudioDeviceSourceInfo.hpp"

namespace  ADV {

class AudioDeviceInput : public AudioDevice {
  
  
private:

  bool devices_read;
  std::vector<DVI::DeviceSouceInfo*> source_info;

  static void stateInfoCallback(pa_context *context, void *userdata);
  static void sourceInfoCallback(pa_context *context, const pa_source_info *info, int eol, void *userdata);

public:
  
  AudioDeviceInput();
  void readAudioDevices() override;
  void addDeviceInfo(DVI::DeviceSouceInfo* source_info);
  std::vector<DVI::DeviceSouceInfo*> getSourceInfo();

};

}

#endif // AUDIO_DEVICE_IN_HPP


