/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <dlfcn.h>

#include <iostream>
#include <string>

#include "Base.hpp"

int main() {
  std::cout << "Test Code - dlopen\n";

  const std::string modulePath_1 = "/home/issuh/workspace/myProject/testCode/build/bin/dlOpen/libmyModule_1.so";
  const std::string modulePath_2 = "/home/issuh/workspace/myProject/testCode/build/bin/dlOpen/libmyModule_2.so";

  const char* dlsymError = nullptr;

  void* module1 = dlopen(modulePath_1.c_str(), RTLD_LAZY);
  if (!module1) {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }

  void* module2 = dlopen(modulePath_2.c_str(), RTLD_LAZY);
  if (!module2) {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }

  create_t* createModule_1 = reinterpret_cast<create_t*>(dlsym(module1, "createModule"));
  dlsymError = dlerror();
  if (dlsymError) {
    std::cerr << "Cannot load symbol destroy: " << dlsymError << '\n';
    exit(1);
  }

  create_t* createModule_2 = reinterpret_cast<create_t*>(dlsym(module2, "createModule"));
  dlsymError = dlerror();
  if (dlsymError) {
    std::cerr << "Cannot load symbol destroy: " << dlsymError << '\n';
    exit(1);
  }

  destroy_t* destroyModule_1 = reinterpret_cast<destroy_t*>(dlsym(module1, "destroyModule"));
  dlsymError = dlerror();
  if (dlsymError) {
    std::cerr << "Cannot load symbol destroy: " << dlsymError << '\n';
    exit(1);
  }

  destroy_t* destroyModule_2 = reinterpret_cast<destroy_t*>(dlsym(module2, "destroyModule"));
  dlsymError = dlerror();
  if (dlsymError) {
    std::cerr << "Cannot load symbol destroy: " << dlsymError << '\n';
    exit(1);
  }

  Base* base1 = createModule_1();
  base1->init();
  base1->run();

  destroyModule_1(base1);
  base1 = nullptr;

  std::cout << "-------------------------\n";

  Base* base2 = createModule_2();
  base2->init();
  base2->run();

  destroyModule_2(base2);
  base2 = nullptr;

  dlclose(module1);
  dlclose(module2);
}
