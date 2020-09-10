/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#ifndef SRC_DLOPEN_DRIVED1_HPP_
#define SRC_DLOPEN_DRIVED1_HPP_

#include <iostream>
#include <string>

#include "Base.hpp"

class Drived1 : public Base {
 public:
  explicit Drived1(const std::string& name);
  virtual ~Drived1();

  void init() override;
  void run() override;

 private:
  std::string m_name;
};

extern "C" Base* createModule();
extern "C" void destroyModule(Base* node);

#endif  // SRC_DLOPEN_DRIVED1_HPP_
