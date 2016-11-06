cmake_minimum_required(VERSION 3.5)

set(compiler_source_files
        frontend/parser.cc
        frontend/scanner.cc
        driver.cc
        assembly/assembly.cc
        include/driver.h
        include/expression.h
        )

set(include_dirs
        include
        assembly/include
        frontend/include
        )

include_directories(${include_dirs})
add_library(compiler ${compiler_source_files})
target_include_directories (compiler PUBLIC ${include_dirs})