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
#include <math.h>
#include <stdio.h>
#include <stdint.h>



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
static const unsigned char impala_actions[228] = {
  85,72,137,229,255,252,243,64,15,126,4,240,140,37,237,255,102,64,15,214,133,
  253,240,140,233,255,252,243,64,15,126,192,240,132,240,52,255,252,243,64,15,
  126,133,253,240,140,233,255,249,255,252,233,245,255,252,242,64,15,194,192,
  240,132,240,52,235,102,64,15,56,23,192,240,133,240,53,255,15,133,245,255,
  15,132,245,255,252,243,64,15,126,192,240,132,240,52,252,242,64,15,92,192,
  240,132,240,52,252,242,64,15,92,192,240,132,240,52,255,252,242,64,15,88,192,
  240,132,240,52,255,252,242,64,15,89,192,240,132,240,52,255,252,242,64,15,
  94,192,240,132,240,52,255,252,243,64,15,126,192,240,140,252,243,64,15,126,
  193,240,140,255,252,243,64,15,126,192,240,44,252,243,64,15,126,200,240,44,
  72,184,237,237,252,255,208,252,243,64,15,126,192,240,140,255,252,243,64,15,
  126,200,240,44,252,243,64,15,126,192,240,44,255,252,242,64,15,81,192,240,
  132,240,52,255,93,195,255
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

void Assembly__SSE_4_1::initialize(int parameterCount) {
    dasm_init(&d, DASM_MAXSECTION);

    void* labels[lbl__MAX];
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    dasm_growpc(&d, 0);

    Dst = &d;

    stackPos = parameterCount >= 8 ? 7 : parameterCount-1;
    localVarPos = 0;
}

void Assembly__SSE_4_1::prologue(){
    //| push rbp
    //| mov rbp, rsp
    dasm_put(Dst, 0);
#line 65 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly__SSE_4_1::pushConstantToStack(double *value){
    stackPos++;
    //| movq xmm(stackPos), qword [value]
    dasm_put(Dst, 5, (stackPos), value);
#line 75 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::storeLocalVariable() {
    localVarPos++;
    //| movq qword [rbp-8*localVarPos], xmm(stackPos)
    dasm_put(Dst, 16, (stackPos), -8*localVarPos);
#line 80 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(stackPos), xmm(index)
        dasm_put(Dst, 26, (stackPos), (index));
#line 87 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq xmm(stackPos), qword [rbp+(8+(index-7)*8)]
        dasm_put(Dst, 37, (stackPos), (8+(index-7)*8));
#line 90 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

void Assembly__SSE_4_1::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(index), xmm(stackPos)
        dasm_put(Dst, 26, (index), (stackPos));
#line 97 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq qword [rbp+(8+(index-7)*8)], xmm(stackPos)
        dasm_put(Dst, 16, (stackPos), (8+(index-7)*8));
#line 100 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

void Assembly__SSE_4_1::pushLocalVariableToStack(int index) {
    stackPos++;
    //| movq xmm(stackPos), qword [rbp-(8+index*8)]
    dasm_put(Dst, 37, (stackPos), -(8+index*8));
#line 106 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::replaceLocalVariable(int index) {
    //| movq qword [rbp-(8+index*8)], xmm(stackPos)
    dasm_put(Dst, 16, (stackPos), -(8+index*8));
#line 110 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 48, labelNumber);
#line 114 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 50, labelNumber);
#line 118 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}


void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
     //| ptest xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 54, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 124 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     if(condition){
         //| jnz => labelNumber
         dasm_put(Dst, 76,  labelNumber);
#line 126 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else{
        //| jz => labelNumber
        dasm_put(Dst, 80,  labelNumber);
#line 129 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     stackPos--;
}

void Assembly__SSE_4_1::performNegation(){
    //| movq xmm(stackPos+1), xmm(stackPos)
    //| subsd xmm(stackPos), xmm(stackPos+1)
    //| subsd xmm(stackPos), xmm(stackPos+1)
    dasm_put(Dst, 84, (stackPos+1), (stackPos), (stackPos), (stackPos+1), (stackPos), (stackPos+1));
#line 137 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::calculateAddition(){
    //| addsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 115, (stackPos-1), (stackPos));
#line 141 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateSubtraction(){
    //| subsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 104, (stackPos-1), (stackPos));
#line 146 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateMultiplication(){
    //| mulsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 126, (stackPos-1), (stackPos));
#line 151 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateDivision(){
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 137, (stackPos-1), (stackPos));
#line 156 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculatePower(){
    // Backup xmm0 and xmm1
    //| movq	xmm(stackPos+1), xmm0
    //| movq	xmm(stackPos+2), xmm1
    dasm_put(Dst, 148, (stackPos+1), (stackPos+2));
#line 163 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Call pow function of c std math lib
    //| movq xmm0, xmm(stackPos)
    //| movq xmm1, xmm(stackPos-1)
    //| mov64 rax, (uintptr_t) pow
    //| call rax
    //| movq xmm(stackPos-1), xmm0
    dasm_put(Dst, 165, (stackPos), (stackPos-1), (unsigned int)((uintptr_t) pow), (unsigned int)(((uintptr_t) pow)>>32), (stackPos-1));
#line 170 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

     // Restore xmm0 and xmm1
    //| movq xmm1, xmm(stackPos+1)
    //| movq xmm0, xmm(stackPos+2)
    dasm_put(Dst, 197, (stackPos+1), (stackPos+2));
#line 174 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateSQRT(){
    //| sqrtsd xmm(stackPos), xmm(stackPos)
    dasm_put(Dst, 214, (stackPos), (stackPos));
#line 179 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::extractResult(){
     //| movq xmm0, xmm(stackPos)
     dasm_put(Dst, 205, (stackPos));
#line 183 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}


void Assembly__SSE_4_1::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 225);
#line 189 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

dasm_gen_func Assembly__SSE_4_1::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return (dasm_gen_func) buf;
}

