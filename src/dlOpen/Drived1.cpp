/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include "Drived1.hpp"

Drived1::Drived1(const std::string& name) : Base(name) {
  std::cout << "Drived1 Constructor\n";
}

Drived1::~Drived1() {
  std::cout << "Drived1 Distructor\n";
}

void Drived1::init() {
  std::cout << "Drived1::init\n";
  m_name = "MyDrived1";
}

void Drived1::run() {
  std::cout << "Drived1::run\n";
  std::cout << "Base : " << Base::getName() << ", " <<"Drived1 : " << m_name << std::endl;
}

extern "C" Base* createModule() {
  std::cout << "createModule - 1\n";
  return new Drived1("TestNode1");
}

extern "C" void destroyModule(Base* node) {
  std::cout << "destroyModule - 1\n";
  delete node;
}
