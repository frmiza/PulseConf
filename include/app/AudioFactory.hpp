#ifndef AUDIO_INFO_FACTORY_HPP
#define AUDIO_INFO_FACTORY_HPP

#include "AbstractFactory.hpp"
#include "DeviceInfo.hpp"

class AudioInfoFactory : public AbstractFactory<DVI::DeviceInfo> {
public:

  std::unique_ptr<DVI::DeviceInfo> create(std::string name_obj) override;

};

#endif // AUDIO_INFO_FACTORY_HPP

