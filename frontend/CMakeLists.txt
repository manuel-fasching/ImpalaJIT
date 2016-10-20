cmake_minimum_required(VERSION 3.5)

set(frontend_source_files
        parser.cc
        scanner.cc
        driver.cc
        )
add_library(frontend ${frontend_source_files})
target_include_directories (frontend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})