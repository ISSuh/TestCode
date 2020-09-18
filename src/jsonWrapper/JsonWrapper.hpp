/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#ifndef SRC_JSONWRAPPER_JSONWRAPPER_HPP_
#define SRC_JSONWRAPPER_JSONWRAPPER_HPP_

#include <string>

#include "json.hpp"

using json = nlohmann::json;

class JsonWrapper {
 public:
  JsonWrapper() : m_jsonObj() {}
  explicit JsonWrapper(const char* jsonStr) { m_jsonObj = json::parse(jsonStr); }
  explicit JsonWrapper(const std::string& jsonStr) { m_jsonObj = json::parse(jsonStr); }
  JsonWrapper(const JsonWrapper&& json) {
    m_jsonObj.clear();
    m_jsonObj = json.m_jsonObj;
  }

  virtual ~JsonWrapper() = default;

  template<class T>
  const T get(const std::string& key) {
    return m_jsonObj.at(key).get<T>();
  }

  size_t getSize(const std::string& key = "") const {
    if (key.empty()) {
      return m_jsonObj.empty();
    }

    return m_jsonObj.at(key).size();
  }

  bool empty(const std::string& key = "") const {
    if (key.empty()) {
      return m_jsonObj.empty();
    }

    return m_jsonObj.at(key).empty();
  }

  JsonWrapper& operator=(const JsonWrapper& rhs) {
    if (&rhs != this) {
      return *this;
    }

    m_jsonObj.clear();
    m_jsonObj = rhs.m_jsonObj;

    return *this;
  }

  template<class T>
  json& operator[](const std::string& key) {
    return m_jsonObj[key];
  }

 private:
  json m_jsonObj;
};

#endif  // SRC_JSONWRAPPER_JSONWRAPPER_HPP_
