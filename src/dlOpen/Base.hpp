/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#ifndef SRC_DLOPEN_BASE_HPP_
#define SRC_DLOPEN_BASE_HPP_

#include <iostream>
#include <string>
#include <functional>

class Base {
 public:
  explicit Base(const std::string& name) : m_name(name) {
    std::cout << "Base Constructor\n";
  }

  virtual ~Base() {
    std::cout << "Base Distructor\n";
  }

  const std::string getName() const { return m_name; }

  virtual void init() = 0;
  virtual void run() = 0;

 private:
  const std::string m_name;
};

typedef Base* create_t();
typedef void destroy_t(Base* node);

#endif  // SRC_DLOPEN_BASE_HPP_
