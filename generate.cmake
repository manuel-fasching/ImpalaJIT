cmake_minimum_required(VERSION 3.5)

# Parser generation macro
macro(translate_bison_file)
    execute_process(COMMAND bison -o parser.cc parser.yy
            WORKING_DIRECTORY compiler/frontend
            )
    execute_process(COMMAND mv stack.hh ./include
            WORKING_DIRECTORY compiler/frontend/
            )
    execute_process(COMMAND mv location.hh ./include
            WORKING_DIRECTORY compiler/frontend/
            )
    execute_process(COMMAND mv parser.hh ./include
            WORKING_DIRECTORY compiler/frontend/
            )
    execute_process(COMMAND mv position.hh ./include
            WORKING_DIRECTORY compiler/frontend/
            )
endmacro(translate_bison_file)

# Scanner generation macro
macro(translate_flex_file)
    execute_process(COMMAND flex -o scanner.cc scanner.ll
            WORKING_DIRECTORY compiler/frontend
            )
endmacro(translate_flex_file)

# Asm generation macro
macro(translate_dynasm_file)
    execute_process(COMMAND gcc -o minilua 3rd_party/LuaJIT/src/host/minilua.c -lm
            )
    execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/minilua 3rd_party/LuaJIT/dynasm/dynasm.lua -o compiler/code-gen/assembly/assembly.cc -D X64 compiler/code-gen/assembly/assembly.dasc
            )
    execute_process(COMMAND rm minilua
            )
endmacro()

translate_bison_file()
translate_flex_file()
translate_dynasm_file()
