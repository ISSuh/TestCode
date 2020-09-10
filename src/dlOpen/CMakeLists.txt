project(Dlopen)

message("Test Code - dlopen")

#-------------------------------------------------------------------------------
# Set Example
#-------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY    ${BUILD_DIR_EXAMPLES}/dlOpen )
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY    ${BUILD_DIR_EXAMPLES}/dlOpen )

#-------------------------------------------------------------------------------
# Build Shared Library
#-------------------------------------------------------------------------------
add_library(myModule_1 SHARED Drived1.cpp)
set_target_properties(myModule_1 PROPERTIES SOVERSION 1)

add_library(myModule_2 SHARED Drived2.cpp)
set_target_properties(myModule_2 PROPERTIES SOVERSION 1)

#-------------------------------------------------------------------------------
# Build
#-------------------------------------------------------------------------------
add_executable(dlopen_TestCode main.cpp)
target_link_libraries(dlopen_TestCode -ldl)
