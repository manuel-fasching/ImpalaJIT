/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.4.0, DynASM x64 version 1.4.0
** DO NOT EDIT! The original file is in "compiler/code-gen/assembly/assembly__sse_4_1.dasc".
*/

#line 1 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
/**
 * Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
 * Distributed under the MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <assembly__sse_4_1.hh>
#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <cmath>



//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 29 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 31 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 33 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[214] = {
  85,65,84,72,137,229,255,252,243,64,15,126,4,240,140,37,237,255,72,131,252,
  236,8,102,64,15,214,4,240,140,36,255,252,243,64,15,126,192,240,132,240,52,
  255,252,243,64,15,126,133,253,240,140,233,255,102,64,15,214,133,253,240,140,
  233,255,249,255,252,233,245,255,252,242,64,15,194,192,240,132,240,52,235,
  102,64,15,56,23,192,240,133,240,53,255,15,133,245,255,15,132,245,255,252,
  242,64,15,88,192,240,132,240,52,255,252,242,64,15,92,192,240,132,240,52,255,
  252,242,64,15,89,192,240,132,240,52,255,252,242,64,15,94,192,240,132,240,
  52,255,73,137,228,255,72,131,228,252,240,255,72,131,252,236,32,255,72,184,
  237,237,255,252,255,208,255,76,137,228,255,252,243,64,15,126,192,240,140,
  255,252,243,64,15,126,4,240,140,36,72,131,196,8,255,252,243,64,15,126,192,
  240,44,255,72,137,252,236,65,92,93,195,255
};

#line 34 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif

Assembly__SSE_4_1::~Assembly__SSE_4_1()
{
    dasm_free(&d);
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::initialize(int parameterCount) {
    std::cout << "ImpalaJIT: AVX Support disabled" << std::endl;

    dasm_init(&d, DASM_MAXSECTION);

    void* labels[lbl__MAX];
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    dasm_growpc(&d, 0);

    Dst = &d;

    stackPos = parameterCount >= 8 ? 7 : parameterCount-1;
}
/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::prologue(){
    //| push rbp
    //| push r12
    //| mov rbp, rsp
    dasm_put(Dst, 0);
#line 72 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushConstantToStack(double value){
    stackPos++;
    double* ptr = static_cast<double*>(malloc(sizeof(double)));
    *ptr = value;
    //| movq xmm(stackPos), qword[ptr]
    dasm_put(Dst, 7, (stackPos), ptr);
#line 90 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::storeLocalVariable() {
    //| sub rsp, 8
    //| movq qword [rsp], xmm(stackPos)
    dasm_put(Dst, 18, (stackPos));
#line 98 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(stackPos), xmm(index)
        dasm_put(Dst, 32, (stackPos), (index));
#line 109 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq xmm(stackPos), qword [rbp+8+(index-7)*8]
        dasm_put(Dst, 43, (stackPos), 8+(index-7)*8);
#line 112 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(index), xmm(stackPos)
        dasm_put(Dst, 32, (index), (stackPos));
#line 122 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq qword [rbp+8+(index-7)*8], xmm(stackPos)
        dasm_put(Dst, 54, (stackPos), 8+(index-7)*8);
#line 125 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushLocalVariableToStack(int index) {
    stackPos++;
    //| movq xmm(stackPos), qword [rbp-8-index*8]
    dasm_put(Dst, 43, (stackPos), -8-index*8);
#line 135 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::replaceLocalVariable(int index) {
    //| movq qword [rbp-8-index*8], xmm(stackPos)
    dasm_put(Dst, 54, (stackPos), -8-index*8);
#line 142 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 64, labelNumber);
#line 150 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 66, labelNumber);
#line 157 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
     //| ptest xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 70, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 165 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     if(condition){
         //| jnz => labelNumber
         dasm_put(Dst, 92,  labelNumber);
#line 167 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else{
        //| jz => labelNumber
        dasm_put(Dst, 96,  labelNumber);
#line 170 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateAddition(){
    //| addsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 100, (stackPos-1), (stackPos));
#line 179 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateSubtraction(){
    //| subsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 111, (stackPos-1), (stackPos));
#line 187 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateMultiplication(){
    //| mulsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 122, (stackPos-1), (stackPos));
#line 195 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateDivision(){
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 133, (stackPos-1), (stackPos));
#line 203 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::callExternalFunction(externalFunction functionPtr, unsigned numberOfArguments){

    //Backup the stack. Function arguments will be replaced by a result
    //and therefor excluded from the backup.
    for(int i=0; i<stackPos-(numberOfArguments-1); i++){
       //| sub rsp, 8
       //| movq qword [rsp], xmm(i)
       dasm_put(Dst, 18, (i));
#line 216 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }


    //Load parameters to register
    for(int i=stackPos-(numberOfArguments-1); i<=stackPos; i++){
       //| movq xmm(i-(stackPos-(numberOfArguments-1))), xmm(i)
       dasm_put(Dst, 32, (i-(stackPos-(numberOfArguments-1))), (i));
#line 222 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    stackPos = stackPos-(numberOfArguments-1);

    // Save frame pointer in non-volatile register
    //| mov r12, rsp
    dasm_put(Dst, 144);
#line 230 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Align frame pointer on 16 bit
    //| and rsp, -16
    dasm_put(Dst, 148);
#line 233 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Add Shadow space (32bit)
    // Not sure, if this is still needed.
    //| sub rsp, 32
    dasm_put(Dst, 154);
#line 237 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Move address of function to register
    //| mov64 rax, (uintptr_t) functionPtr
    dasm_put(Dst, 160, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 240 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Call function
    //| call rax
    dasm_put(Dst, 165);
#line 243 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Restore rsp
    //| mov rsp, r12
    dasm_put(Dst, 169);
#line 246 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"


    //Put function result on top of stack
    //| movq xmm(stackPos), xmm0
    dasm_put(Dst, 173, (stackPos));
#line 250 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    //Restore old stack
    for(int i=stackPos-1; i>=0; i--){
        //| movq xmm(i), qword [rsp]
        //| add rsp, 8
        dasm_put(Dst, 182, (i));
#line 255 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::extractResult(){
     //| movq xmm0, xmm(stackPos)
     dasm_put(Dst, 196, (stackPos));
#line 263 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::epilogue(){
    //| mov rsp, rbp
    //| pop r12
    //| pop rbp
    //| ret
    dasm_put(Dst, 205);
#line 273 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
dasm_gen_func Assembly__SSE_4_1::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return (dasm_gen_func) buf;
}

