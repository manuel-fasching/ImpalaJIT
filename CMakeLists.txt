cmake_minimum_required(VERSION 3.5)
project(ImpalaJIT)

option( SHARED_LIB "Compile the shared library" ON )
option( STATIC_LIB "Compile the static library" OFF )
option( TESTS "Enable Tests" OFF )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
enable_language( C Fortran )
set( CMAKE_Fortran_COMPILER gfortran )

set(include_dirs
        include
        include/impalajit
        compiler/include
        compiler/include/nodes
        compiler/include/types
        compiler/semantic_analysis/include
        compiler/frontend/include
        compiler/code-gen/include
        compiler/code-gen/assembly/include
        )

include_directories(${include_dirs})


set(source_files ${source_files}
        compiler/frontend/parser.cc
        compiler/frontend/scanner.cc
        compiler/driver.cc
        compiler/function_context.cc
        compiler/code-gen/assembly/assembly.cc
        compiler/semantic_analysis/semantic_analyzer.cc
        compiler/include/nodes/node.h
        impalajit.cc
        compiler/include/nodes/expression_nodes.h
        compiler/include/nodes/compare_nodes.h
        compiler/include/nodes/conditional_nodes.h
        compiler/include/nodes/boolean_nodes.h
        compiler/include/nodes/assignment_nodes.h
        compiler/code-gen/code_generator.cc)


if( SHARED_LIB )
    add_library( impalajit SHARED ${source_files})
    target_link_libraries( impalajit m )
endif( SHARED_LIB )

if( STATIC_LIB )
    add_library( impalajit-static STATIC ${source_files} )
    set_target_properties( impalajit-static
            PROPERTIES OUTPUT_NAME impalajit )
endif( STATIC_LIB )

# Tests
if( TESTS )
    enable_testing()
    add_subdirectory( tests )
endif( TESTS )

# install target
if( SHARED_LIB )
    install( TARGETS impalajit
             DESTINATION lib )
endif( SHARED_LIB )
if( STATIC_LIB )
    install( TARGETS impalajit-static
             DESTINATION lib )
endif( STATIC_LIB )
install( FILES include/impalajit.hh
         DESTINATION include )
install( FILES include/impalajit/types.hh
         DESTINATION include/impalajit )



# uninstall target
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
        IMMEDIATE @ONLY)
add_custom_target(uninstall
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)


# code generation target
add_custom_target(generate
        COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/generate.cmake
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})


