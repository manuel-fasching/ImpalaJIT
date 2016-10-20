cmake_minimum_required(VERSION 3.5)
project(ImpalaJIT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
set(CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/build")

add_subdirectory(frontend)
add_executable(ImpalaJIT main.cc)

target_link_libraries(ImpalaJIT frontend)
