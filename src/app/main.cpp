#include<iostream>
#include "AudioDeviceInput.hpp"
int main(int argc, char *argv[]) {
    ADV::AudioDeviceInput adv_info; // Mudado para instância direta
    adv_info.readAudioDevices(); // Popula os dispositivos corretamente

    auto& sources = adv_info.getSourceInfo();
    std::cout << "Dispositivos encontrados: " << sources.size() << std::endl;

    for (const auto& source : sources) {
        if (source) { // Verifique se o ponteiro é válido
            std::cout << source->getDeviceName() << "\n";
            std::cout << source->getDeviceDescription() << "\n";
            std::cout << source->getDeviceDriver() << "\n";

            for (const auto& port : source->getDevicePorts()) {
                std::cout << "Nome Porta: " << port.port_name << "\n";
                std::cout << "Descricao Porta: " << port.port_description << "\n";
                std::cout << "Estado Porta: " << port.port_state << "\n";
            }
            std::cout << source->getDeviceState() << "\n";
        } else {
            std::cerr << "Erro: Ponteiro de dispositivo inválido!" << std::endl;
        }
    }

    return 0;
}

