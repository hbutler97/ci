cmake_minimum_required (VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
project (graph)


#version number
set (CMakeHelloWorld_VERSION_MAJOR 1)
set (CMakeHelloWorld_VERSION_MINOR 0)

#include the subdirectory containing our libs
add_subdirectory (Hello)
include_directories(Hello ../)
#indicate the entry point for the executable
add_executable (graph Hello HelloWorld.cpp ../graph.cpp)

# Indicate which libraries to include during the link process.
target_link_libraries (graph Hello)

install (TARGETS graph DESTINATION bin)
