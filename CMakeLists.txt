cmake_minimum_required(VERSION 3.5)
project(ImpalaJIT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
set(CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/build")

set(include_dirs
        types
        include
        compiler/include
        compiler/assembly/include
        compiler/frontend/include
        types
        )

include_directories(${include_dirs})


set(source_files ${source_files}
        compiler/frontend/parser.cc
        compiler/frontend/scanner.cc
        compiler/driver.cc
        compiler/assembly/assembly.cc
        compiler/include/driver.h
        compiler/include/expression.h
        impalajit.cc
        )

install(FILES include/impalajit.hh
        DESTINATION include )
add_library( impalajit STATIC ${source_files})
install( TARGETS impalajit DESTINATION lib)

