cmake_minimum_required(VERSION 3.10.2)
project(interconnect)

file(GLOB_RECURSE INTERCONNECT_SOURCES src/*.cpp)

include_directories(include)

add_executable(interconnect ${INTERCONNECT_SOURCES})
set_property(TARGET interconnect PROPERTY CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
