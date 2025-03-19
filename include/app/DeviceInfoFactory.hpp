#ifndef DEVICE_INFO_FACTORY_HPP
#define DEVICE_INFO_FACTORY_HPP
#include <functional>
#include <memory>
#include <unordered_map>
#include "DeviceType.hpp"
#include "DeviceInfo.hpp"

namespace DIF {

class DeviceInfoFactory{

private:
  std::unordered_map<DVI::DeviceType, std::unique_ptr<DVI::DeviceInfo>, std::hash<int> > m_DeviceInfo;

public: 
  DeviceInfoFactory();
  std::unique_ptr<DVI::DeviceInfo> getObjDeviceInfo(DVI::DeviceType device_type);
};
}

#endif // DEVICE_INFO_FACTORY_HPP
