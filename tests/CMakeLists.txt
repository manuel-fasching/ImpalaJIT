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
link_directories(${LIBRARY_OUTPUT_PATH})
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add test executable
function( add_test_executable name )
        set( sourceFiles
                ${name}.cc )

    add_executable( test_${name}.o ${sourceFiles} )
    add_test(${name} test_${name}.o)

    # Link with impalajit
    target_link_libraries( test_${name}.o impalajit)
endfunction( add_test_executable )

include_directories(include)


add_test_executable(conditionals_eq)
add_test_executable(conditionals_lt)
add_test_executable(conditionals_gt)
add_test_executable(conditionals_neq)
add_test_executable(conditionals_lte)
add_test_executable(conditionals_gte)
add_test_executable(conditionals_nested)
add_test_executable(conditionals_complex_1)
add_test_executable(conditionals_complex_2)
add_test_executable(multiple_functions)
add_test_executable(expressions_basic)
add_test_executable(assignments)
add_test_executable(many_if)