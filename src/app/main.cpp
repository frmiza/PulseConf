#include "AudioDevice.hpp"
#include<iostream>
#include "AudioDeviceInput.hpp"

int main(int argc, char *argv[]) {
    ADV::AudioDeviceInput* adv_info = new ADV::AudioDeviceInput();
    adv_info->readAudioDevices();
    for( auto i : adv_info->getSourceInfo()){
      std::cout << i->getDeviceName() << "\n";
      std::cout << i->getDeviceDescription() << "\n";
      std::cout << i->getDeviceDriver() << "\n";
      std::cout << i->getDeviceState() << "\n";
    }
    delete adv_info;
    return 0;
}
