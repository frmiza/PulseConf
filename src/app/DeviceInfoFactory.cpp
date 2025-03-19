#include "DeviceInfoFactory.hpp"
#include "DeviceType.hpp"
#include "DeviceInfo.hpp"
#include "DeviceSourceInfo.hpp"
#include "DeviceSinkInfo.hpp"
#include <ctime>
#include <memory>

namespace DIF {
  
DeviceInfoFactory::DeviceInfoFactory(){
  m_DeviceInfo[DVI::INPUT] = std::make_unique<DVI::DeviceSourceInfo>();
  m_DeviceInfo[DVI::OUTPUT] = std::make_unique<DVI::DeviceSinkInfo>();
}

std::unique_ptr<DVI::DeviceInfo> DeviceInfoFactory::getObjDeviceInfo(DVI::DeviceType device_type){
  return m_DeviceInfo[device_type]->clone();
}
}
