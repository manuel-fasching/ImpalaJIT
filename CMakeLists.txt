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


cmake_minimum_required(VERSION 3.13)

option( SHARED_LIB "Compile as shared library" OFF )
option( TESTS "Enable Tests" OFF )

project(ImpalaJIT LANGUAGES CXX)

include (GNUInstallDirs)


set(source_files
        compiler/frontend/parser.cc
        compiler/frontend/scanner.cc
        compiler/driver.cc
        compiler/function_context.cc
        compiler/include/nodes/node.h
        impalajit.cc
        compiler/include/nodes/expression_nodes.h
        compiler/include/nodes/compare_nodes.h
        compiler/include/nodes/conditional_nodes.h
        compiler/include/nodes/boolean_nodes.h
        compiler/include/nodes/assignment_nodes.h
        compiler/semantic_analysis/semantic_analyzer.cc
        compiler/code-gen/include/ptr_map_container.hh
        compiler/code-gen/include/calculation_helper.hh
        compiler/code-gen/code_generator.cc
        compiler/code-gen/assembly/assembly__sse_4_1.cc)

if (SHARED_LIB)
    add_library(impalajit SHARED ${source_files})
else ()
    add_library(impalajit STATIC ${source_files})
    set_target_properties(impalajit PROPERTIES OUTPUT_NAME impalajit)
endif ()
target_compile_features (impalajit PUBLIC cxx_std_98)
target_include_directories (impalajit
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        include/impalajit
        compiler/include
        compiler/include/nodes
        compiler/include/types
        compiler/frontend/include
        compiler/semantic_analysis/include
        compiler/code-gen/include
        compiler/code-gen/assembly/include
)

set(CONFIG_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/impalajit)

install (TARGETS impalajit EXPORT impalajit-targets
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install (DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install (EXPORT impalajit-targets
    FILE impalajitConfig.cmake
    NAMESPACE impalajit::
    DESTINATION ${CONFIG_DESTINATION}
)

##### pkg-config #####
find_package( PkgConfig )
if( PKG_CONFIG_FOUND )
    # Detect private libs and directories

    set( _PKG_CONFIG_PROJECT_NAME ${PROJECT_NAME} )
    set( _PKG_CONFIG_DESCRIPTION "JIT Compilation to realize flexible data access" )
    set( _PKG_CONFIG_URL "https://github.com/Manuel1605/ImpalaJIT" )
    set( _PKG_CONFIG_VERSION "0.9" )

    set( _PKG_CONFIG_PREFIX ${CMAKE_INSTALL_PREFIX} )
    set( _PKG_CONFIG_LIBDIR "\${prefix}/lib" )
    set( _PKG_CONFIG_INCLUDEDIR "\${prefix}/include" )

    set( _PKG_CONFIG_LIBS "${CMAKE_LIBRARY_PATH_FLAG}\${libdir} ${CMAKE_LINK_LIBRARY_FLAG}impalajit" )

    set( _PKG_CONFIG_LIBS_PRIVATE  "${_PKG_CONFIG_LIBDIRS_PRIVATE} ${_PKG_CONFIG_LIBS_PRIVATE}" )
    set( _PKG_CONFIG_CFLAGS "-I\${includedir}" )

    # Where to install the pkg-config file?
    set( _PKG_CONFIG_DIR ${CMAKE_INSTALL_PREFIX}/lib/pkgconfig )

    # Configure the pkgconfig file
    configure_file( CMake/pkg-config.pc.in impalajit.pc )

    # Install the pkg file
    install( FILES ${CMAKE_CURRENT_BINARY_DIR}/impalajit.pc	DESTINATION lib/pkgconfig )
endif( PKG_CONFIG_FOUND )

# Tests
if( TESTS )
    enable_testing()
    add_subdirectory( tests )
endif( TESTS )


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


