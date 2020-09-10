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
add_library(myModule SHARED Drived1.cpp)
set_target_properties(myModule PROPERTIES SOVERSION 1)

#-------------------------------------------------------------------------------
# Build
#-------------------------------------------------------------------------------
add_executable(dlopen_TestCode main.cpp)
target_link_libraries(dlopen_TestCode -ldl)
