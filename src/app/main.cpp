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
      for(auto j : i->getDevicePorts()){
        std::cout << "Nome Porta: " << j.port_name << "\n";
        std::cout << "Descricao Porta: " << j.port_description << "\n";
        std::cout << "Estado Porta: " << j.port_state << "\n";
      }
      std::cout << i->getDeviceState() << "\n";
    }
    delete adv_info;
    return 0;
}
