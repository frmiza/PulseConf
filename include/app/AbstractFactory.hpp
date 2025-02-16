#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>
template<typename T>
class AbstractFactory {

  virtual std::unique_ptr<T> create(std::string name_obj) = 0;;
  
};

#endif // 




