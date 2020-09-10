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

  const std::string dlPath = "/home/issuh/workspace/myProject/testCode/build/bin/dlOpen/libmyModule.so";
  const char* dlsymError = nullptr;

  void* handle = dlopen(dlPath.c_str(), RTLD_LAZY);
  if (!handle) {
    std::cerr << dlerror() << std::endl;
    exit(1);
  }

  create_t* crateModule = reinterpret_cast<create_t*>(dlsym(handle, "createModule"));
  dlsymError = dlerror();
  if (dlsymError) {
    std::cerr << "Cannot load symbol destroy: " << dlsymError << '\n';
    exit(1);
  }

  destroy_t* destroyModule = reinterpret_cast<destroy_t*>(dlsym(handle, "destroyModule"));
  dlsymError = dlerror();
  if (dlsymError) {
    std::cerr << "Cannot load symbol destroy: " << dlsymError << '\n';
    exit(1);
  }

  Base* base = crateModule();
  base->init();
  base->run();

  destroyModule(base);
  base = nullptr;

  dlclose(handle);
}
