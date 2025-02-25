
#ifndef PORT_INFO_H
#define PORT_INFO_H

#include<string>

namespace DVI {
  
typedef struct port_info{
  std::string port_name;
  std::string port_description;
  std::string port_state;
}port_info;
}
#endif //PORT_INFO_H
