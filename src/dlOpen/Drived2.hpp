/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#ifndef SRC_DLOPEN_DRIVED2_HPP_
#define SRC_DLOPEN_DRIVED2_HPP_

#include <iostream>
#include <string>

#include "Base.hpp"

class Drived2 : public Base {
 public:
  explicit Drived2(const std::string& name);
  virtual ~Drived2();

  void init() override;
  void run() override;

 private:
  std::string m_name;
};

extern "C" Base* createModule();
extern "C" void destroyModule(Base* node);

#endif  // SRC_DLOPEN_DRIVED2_HPP_
