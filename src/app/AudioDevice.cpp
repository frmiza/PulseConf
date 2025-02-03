#include "AudioDevice.hpp"
#include "DeviceInfo.hpp"
#include <vector>
#include <pulse/context.h>
#include <pulse/mainloop.h>

ADV::AudioDevice::AudioDevice(){
  
  mainloop = pa_mainloop_new();
  api = pa_mainloop_get_api(mainloop);
  context = pa_context_new(api, "Pulse Audio connection");

  devices_read = false;
  device_info = {};
}

ADV::AudioDevice::~AudioDevice(){

  pa_context_disconnect(context);
  pa_context_unref(context);
  pa_mainloop_free(mainloop);
  device_info.clear();
}

std::vector<DVI::DeviceInfo*> ADV::AudioDevice::getSourceInfo(){
  return device_info;
}

void ADV::AudioDevice::runMainLoop(){
  pa_mainloop_iterate(mainloop, 1, nullptr);
}
