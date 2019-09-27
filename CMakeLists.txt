cmake_minimum_required(VERSION 3.10.2)
project(interconnect)

file(GLOB_RECURSE INTERCONNECT_SOURCES src/*.cpp)

include_directories(include)

add_executable(interconnect ${INTERCONNECT_SOURCES})
set_property(TARGET interconnect PROPERTY CXX_STANDARD 17)
