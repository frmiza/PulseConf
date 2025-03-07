#include "DeviceInfoFactory.hpp"
#include "DeviceType.hpp"
#include "DeviceInfo.hpp"
#include "DeviceSourceInfo.hpp"
#include <ctime>
#include <memory>

namespace DIF {
  
DeviceInfoFactory::DeviceInfoFactory(){
  m_DeviceInfo[DVI::INPUT] = std::make_unique<DVI::DeviceSourceInfo>();
}

std::unique_ptr<DVI::DeviceInfo> DeviceInfoFactory::createDeviceInfo(DVI::DeviceType device_type){
  return m_DeviceInfo[device_type]->clone();
}
}
