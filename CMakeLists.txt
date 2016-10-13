cmake_minimum_required(VERSION 3.6)
project(ImpalaJIT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

set(SOURCE_FILES main.cpp)
add_executable(ImpalaJIT ${SOURCE_FILES})