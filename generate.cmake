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

# Parser generation macro
macro(translate_bison_file)
    execute_process(COMMAND bison -o parser.cc -Wconflicts-sr parser.yy
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
    execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/minilua 3rd_party/LuaJIT/dynasm/dynasm.lua -o compiler/code-gen/assembly/assembly__sse_4_1.cc -D X64 compiler/code-gen/assembly/assembly__sse_4_1.dasc
            )
    execute_process(COMMAND ${CMAKE_CURRENT_BINARY_DIR}/minilua 3rd_party/LuaJIT/dynasm/dynasm.lua -o compiler/code-gen/assembly/assembly__avx.cc -D X64 compiler/code-gen/assembly/assembly__avx.dasc
            )
    execute_process(COMMAND rm minilua
            )
endmacro()

translate_bison_file()
translate_flex_file()
translate_dynasm_file()
