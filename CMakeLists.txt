cmake_minimum_required(VERSION 3.5)
project(ImpalaJIT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/build")

set(SOURCE_FILES main.cpp)

add_executable(ImpalaJIT ${SOURCE_FILES})

find_library(LIBTCC NAMES libtcc.a libtcc)
find_library(DL dl)

target_link_libraries(ImpalaJIT
        ${LIBTCC}
        ${DL})
