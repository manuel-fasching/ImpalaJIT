# Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
# Distributed under the MIT License
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is furnished
# to do so, subject to the following conditions:
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
# PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
# FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
# ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.


cmake_minimum_required(VERSION 2.6)

option( INTEL_COMPILER "Use Intel compiler" ON)

if(INTEL_COMPILER)
        set(CMAKE_C_COMPILER icc)
        set(CMAKE_CXX_COMPILER icpc)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -mavx -O3")

project(Pythagoras)

# Set impalajit directory
set( impalajitDir /path/to/impalajit )

link_directories(${impalajitDir}/lib)
include_directories(${impalajitDir}/include include)

add_executable( pythagoras_benchmark pythagoras.cc
        static_pythagoras_function.cc )

target_link_libraries( pythagoras_benchmark impalajit )


