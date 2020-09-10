/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include "Drived2.hpp"

Drived2::Drived2(const std::string& name) : Base(name) {
  std::cout << "Drived2 Constructor\n";
}

Drived2::~Drived2() {
  std::cout << "Drived2 Distructor\n";
}

void Drived2::init() {
  std::cout << "Drived2::init\n";
  m_name = "MyDrived2";
}

void Drived2::run() {
  std::cout << "Drived2::run\n";
  std::cout << "Base : " << Base::getName() << ", " <<"Drived2 : " << m_name << std::endl;
}

extern "C" Base* createModule() {
  std::cout << "createModule - 2\n";
  return new Drived2("TestNode2");
}

extern "C" void destroyModule(Base* node) {
  std::cout << "destroyModule - 2\n";
  delete node;
}
