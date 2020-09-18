project(jsonWrapper)

message("Test Code - jsonWrapper")

#-------------------------------------------------------------------------------
# Set Example
#-------------------------------------------------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY    ${BUILD_DIR_EXAMPLES}/jsonWrapper )

#-------------------------------------------------------------------------------
# Build
#-------------------------------------------------------------------------------
add_executable(jsonWrapper_TestCode main.cpp)
target_link_libraries(jsonWrapper_TestCode -ldl)
