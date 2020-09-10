CMAKE_MINIMUM_REQUIRED (VERSION 3.5)
PROJECT (TestCode)

#-------------------------------------------------------------------------------
# Set Compiler
#-------------------------------------------------------------------------------
SET( CMAKE_CXX_STANDARD 11)
SET( CMAKE_CXX_STANDARD_REQUIRED ON )
SET( CMAKE_MAKE_PROGRAM="make -j 24" )
ADD_COMPILE_OPTIONS ( -g -Wall -Wextra )

#-------------------------------------------------------------------------------
# Set Build Variable
#-------------------------------------------------------------------------------
SET(PROJECT_DIR ${PROJECT_SOURCE_DIR})
SET(BUILD_DIR_EXAMPLES ${CMAKE_SOURCE_DIR}/build/bin)

#-------------------------------------------------------------------------------
# Set SubDirectory
#-------------------------------------------------------------------------------
add_subdirectory(src)
