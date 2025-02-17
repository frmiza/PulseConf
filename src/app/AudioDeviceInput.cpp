#include "AudioDeviceInput.hpp"
#include "DeviceInfo.hpp"
#include "DeviceSourceInfo.hpp"
#include <string>
#include <memory>
#include <pulse/pulseaudio.h>

ADV::AudioDeviceInput::AudioDeviceInput(){
  pa_context_set_state_callback(context, &ADV::AudioDeviceInput::stateInfoCallback, this);
  pa_context_connect(context, nullptr, PA_CONTEXT_NOFLAGS, nullptr);
}

void ADV::AudioDeviceInput::stateInfoCallback(pa_context *context, void *userdata) {
    auto *instance = static_cast<AudioDeviceInput *>(userdata);
    pa_context_state_t state = pa_context_get_state(context);

  if(state == PA_CONTEXT_READY){
      pa_operation *op = pa_context_get_source_info_list(context, sourceInfoCallback, instance);
      if (op) {
        pa_operation_unref(op);
      }
  }
}

void ADV::AudioDeviceInput::sourceInfoCallback(pa_context *context, const pa_source_info *info, int eol, void *userdata) {
  
  auto *instance = static_cast<AudioDeviceInput *>(userdata);
  
  if (eol > 0){
    instance->devices_read = true;
    return;
  }
 

  DVI::DeviceSourceInfo* dvc_info = new DVI::DeviceSourceInfo();
  dvc_info->setupDevice(*info);

  instance->addDeviceInfo(dvc_info);
}

void ADV::AudioDeviceInput::addDeviceInfo(DVI::DeviceInfo* device_info){
  if(device_info->getDeviceName().find("monitor") == std::string::npos){
    this->device_info.push_back(std::move(device_info));
  }
}

void ADV::AudioDeviceInput::readAudioDevices() {
  while (!devices_read) {
    runMainLoop();
  }
}
