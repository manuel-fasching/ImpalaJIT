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
    execute_process(COMMAND ./minilua 3rd_party/LuaJIT/dynasm/dynasm.lua -o compiler/assembly/assembly.cc -D X64 compiler/assembly/assembly.dasc
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            )
endmacro()

translate_bison_file()
translate_flex_file()
translate_dynasm_file()

enable_testing()
add_subdirectory( tests )

set(include_dirs
        include
        include/impalajit
        compiler/include
        compiler/assembly/include
        compiler/frontend/include
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
        compiler/include/basic_expression.h
        compiler/include/comparison_expression.h
        compiler/include/complex_expression.h
        compiler/include/boolean_expression.h
        compiler/include/assignment_expression.h)

install(FILES include/impalajit.hh
        DESTINATION include )
install(FILES include/impalajit/types.hh
        DESTINATION include/impalajit )


add_library( impalajit STATIC ${source_files})

install( TARGETS impalajit DESTINATION lib)

