cmake_minimum_required(VERSION 3.5)
project(ImpalaJIT)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")
#set(CMAKE_SOURCE_DIR "${CMAKE_SOURCE_DIR}/build")
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

macro(translate_bison_file)
    execute_process(COMMAND bison -o parser.cc parser.yy
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/compiler/frontend
            )
    execute_process(COMMAND mv stack.hh ./include
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/compiler/frontend/
            )
    execute_process(COMMAND mv location.hh ./include
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/compiler/frontend/
            )
    execute_process(COMMAND mv parser.hh ./include
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/compiler/frontend/
            )
    execute_process(COMMAND mv position.hh ./include
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/compiler/frontend/
            )
endmacro(translate_bison_file)
macro(translate_flex_file)
    execute_process(COMMAND flex -o scanner.cc scanner.ll
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/compiler/frontend
            )
endmacro(translate_flex_file)
macro(translate_dynasm_file)
    execute_process(COMMAND gcc -o minilua 3rd_party/LuaJIT/src/host/minilua.c -lm
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            )
    execute_process(COMMAND ./minilua 3rd_party/LuaJIT/dynasm/dynasm.lua -o compiler/code-gen/assembly/assembly.cc -D X64 compiler/code-gen/assembly/assembly.dasc
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            )
endmacro()

translate_bison_file()
translate_flex_file()
translate_dynasm_file()

enable_language( C Fortran )
set( CMAKE_Fortran_COMPILER gfortran )
enable_testing()
add_subdirectory( tests )

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

install(FILES include/impalajit.hh
        DESTINATION include )
install(FILES include/impalajit/types.hh
        DESTINATION include/impalajit )

add_library( impalajit STATIC ${source_files})
target_link_libraries (impalajit m)

install( TARGETS impalajit DESTINATION lib)


