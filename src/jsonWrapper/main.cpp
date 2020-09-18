/**
 * 
 *  Copyright:  Copyright (c) 2020, ISSuh
 * 
 */

#include <iostream>
#include <string>

#include "JsonWrapper.hpp"

int main() {
  const std::string jsonStr(
    "{  \
      \"node_name\" : \"helloworld\", \
      \"log_level\" : \"debug\", \
      \"modules\" :  \
        [ \
          { \
              \"module_name\" : \"Sample_0\", \
              \"module_path\" : \"/Users/inseocksuh/projects/SimpleComponentTemplate/example/hello_world/libhello_world.so\", \
              \"module\" : { \
                  \"class_name\" : \"SampleModule\", \
                  \"configure\" : { \
                      \"threading\" : false, \
                      \"args\" : { \
                          \"int_test\" : 1, \
                          \"float_test\" : 1.1, \
                          \"bool_test\" : true, \
                          \"string_test\" : \"Hello World!\", \
                          \"array_test\" : [1, 2, 3, 4, 5] \
                      } \
                  } \
              } \
          } \
        ] \
    }");

  json jsonTest1 = json::parse(jsonStr);
  JsonWrapper jsonTest2(jsonStr);
  JsonWrapper args();

  std::cout << jsonTest1.size() << " / " << jsonTest2.getSize() << std::endl;
  std::cout << jsonTest1["node_name"] << " / " << jsonTest2.get<std::string>("node_name") << std::endl;
  std::cout << jsonTest1["module_name"] << " / " << jsonTest2["module_name"] << std::endl;
}
