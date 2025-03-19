namespace DVI {

template <typename T_State>
void DeviceInfo::stateToString(T_State state, const std::map<T_State, std::string>& state_map) {
  if (state == static_cast<T_State>(-1)) {
    device_state = "Unknown";
    return;
  }

  auto it = state_map.find(state);
  if (it != state_map.end()) {
    device_state = it->second;
  } else {
    device_state = "Unknown";
  }
}

template <typename T_port_info>
void DeviceInfo::addDevicePort(T_port_info** ports, T_port_info* active_port){
  
  if(!ports || !active_port) {return;}

  for(T_port_info** s_ports = ports; (*s_ports) != NULL; s_ports++){
    if((*s_ports) == active_port){
      device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Active"});   
    }
    else{
      device_ports.push_back({(*s_ports)->name,(*s_ports)->description, "Inactive"});   
    }
  } 
}

}
