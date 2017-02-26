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
static const unsigned char impala_actions[297] = {
  85,72,137,229,255,252,243,64,15,126,4,240,140,37,237,255,72,131,252,236,8,
  102,64,15,214,4,240,140,36,255,252,243,64,15,126,192,240,132,240,52,255,252,
  243,64,15,126,133,253,240,140,233,255,102,64,15,214,133,253,240,140,233,255,
  249,255,252,233,245,255,252,242,64,15,194,192,240,132,240,52,235,102,64,15,
  56,23,192,240,133,240,53,255,15,133,245,255,15,132,245,255,248,1,255,248,
  2,255,248,3,255,252,233,244,247,255,252,233,244,248,255,252,233,244,249,255,
  196,225,123,240,160,194,192,240,133,240,45,235,196,226,121,14,192,240,133,
  240,37,255,15,133,244,247,255,15,133,244,248,255,15,133,244,249,255,15,132,
  244,247,255,15,132,244,248,255,15,132,244,249,255,252,242,64,15,88,192,240,
  132,240,52,255,252,242,64,15,92,192,240,132,240,52,255,252,242,64,15,89,192,
  240,132,240,52,255,252,242,64,15,94,192,240,132,240,52,255,73,137,228,255,
  72,131,228,252,240,255,65,84,255,72,131,252,236,40,255,72,184,237,237,255,
  252,255,208,255,72,131,196,40,255,65,92,255,76,137,228,255,252,243,64,15,
  126,192,240,140,255,252,243,64,15,126,4,240,140,36,72,131,196,8,255,252,243,
  64,15,126,192,240,44,255,72,137,252,236,93,195,255
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
}

void Assembly__SSE_4_1::prologue(){
    //| push rbp
    //| mov rbp, rsp
    dasm_put(Dst, 0);
#line 64 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly__SSE_4_1::pushConstantToStack(double value){
    stackPos++;
    double* ptr = static_cast<double*>(malloc(sizeof(double)));
    *ptr = value;
    //| movq xmm(stackPos), qword[ptr]
    dasm_put(Dst, 5, (stackPos), ptr);
#line 76 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::storeLocalVariable() {
    //| sub rsp, 8
    //| movq qword [rsp], xmm(stackPos)
    dasm_put(Dst, 16, (stackPos));
#line 81 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(stackPos), xmm(index)
        dasm_put(Dst, 30, (stackPos), (index));
#line 89 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq xmm(stackPos), qword [rbp+8+(index-7)*8]
        dasm_put(Dst, 41, (stackPos), 8+(index-7)*8);
#line 92 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

void Assembly__SSE_4_1::popStack(){
    stackPos--;
}

void Assembly__SSE_4_1::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| movq xmm(index), xmm(stackPos)
        dasm_put(Dst, 30, (index), (stackPos));
#line 103 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| movq qword [rbp+8+(index-7)*8], xmm(stackPos)
        dasm_put(Dst, 52, (stackPos), 8+(index-7)*8);
#line 106 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

void Assembly__SSE_4_1::pushLocalVariableToStack(int index) {
    stackPos++;
    //| movq xmm(stackPos), qword [rbp-8-index*8]
    dasm_put(Dst, 41, (stackPos), -8-index*8);
#line 113 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::replaceLocalVariable(int index) {
    //| movq qword [rbp-8-index*8], xmm(stackPos)
    dasm_put(Dst, 52, (stackPos), -8-index*8);
#line 117 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 62, labelNumber);
#line 122 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 64, labelNumber);
#line 126 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}


void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
     //| ptest xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 68, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 132 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     if(condition){
         //| jnz => labelNumber
         dasm_put(Dst, 90,  labelNumber);
#line 134 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else{
        //| jz => labelNumber
        dasm_put(Dst, 94,  labelNumber);
#line 137 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     stackPos--;
}

void Assembly__SSE_4_1::addLocalLabel(unsigned labelNumber) {
    switch(labelNumber){
        case 1: {
            //| 1:
            dasm_put(Dst, 98);
#line 145 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
            }
        case 2: {
            //| 2:
            dasm_put(Dst, 101);
#line 149 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
        case 3: {
            //| 3:
            dasm_put(Dst, 104);
#line 153 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
    }
}

void Assembly__SSE_4_1::jumpForwardToLocalLabel(unsigned labelNumber) {
    switch(labelNumber){
        case 1: {
            //| jmp >1
            dasm_put(Dst, 107);
#line 162 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
            }
        case 2: {
            //| jmp >2
            dasm_put(Dst, 112);
#line 166 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
        case 3: {
            //| jmp >3
            dasm_put(Dst, 117);
#line 170 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
            break;
        }
    }
}

void Assembly__SSE_4_1::conditionalJumpForwardToLocalLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| vcmpsd xmm(stackPos), xmm(stackPos), xmm(stackPos-1), operator_
     //| vptestps xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 122, (stackPos), (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 178 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     if(condition){
        switch(labelNumber){
            case 1: {
                //| jnz >1
                dasm_put(Dst, 144);
#line 182 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 2: {
                //| jnz >2
                dasm_put(Dst, 149);
#line 186 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 3: {
                //| jnz >3
                dasm_put(Dst, 154);
#line 190 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
        }
     }
     else{
        switch(labelNumber){
            case 1: {
                //| jz >1
                dasm_put(Dst, 159);
#line 198 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 2: {
                //| jz >2
                dasm_put(Dst, 164);
#line 202 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
            case 3: {
                //| jz >3
                dasm_put(Dst, 169);
#line 206 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
                break;
            }
        }
     }
     stackPos--;
}

void Assembly__SSE_4_1::calculateAddition(){
    //| addsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 174, (stackPos-1), (stackPos));
#line 215 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateSubtraction(){
    //| subsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 185, (stackPos-1), (stackPos));
#line 220 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateMultiplication(){
    //| mulsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 196, (stackPos-1), (stackPos));
#line 225 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::calculateDivision(){
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 207, (stackPos-1), (stackPos));
#line 230 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    stackPos--;
}

void Assembly__SSE_4_1::callExternalFunction(externalFunction functionPtr, unsigned numberOfArguments){

    //Backup the stack. Function arguments will be replaced by a result
    //and therefor excluded from the backup.
    for(int i=0; i<stackPos-(numberOfArguments-1); i++){
       //| sub rsp, 8
       //| movq qword [rsp], xmm(i)
       dasm_put(Dst, 16, (i));
#line 240 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }


    //Load parameters to register
    for(int i=stackPos-(numberOfArguments-1); i<=stackPos; i++){
       //| movq xmm(i-(stackPos-(numberOfArguments-1))), xmm(i)
       dasm_put(Dst, 30, (i-(stackPos-(numberOfArguments-1))), (i));
#line 246 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    stackPos = stackPos-(numberOfArguments-1);
    //Perform function Call

    // Save rsp register
    //| mov r12, rsp
    dasm_put(Dst, 218);
#line 255 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Align frame pointer
    //| and rsp, -16
    dasm_put(Dst, 222);
#line 258 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Save old rsp value in aligned environment
    //| push r12
    dasm_put(Dst, 228);
#line 261 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Add Shadow space (32bit) and take care of alignment
    // We pushed r12, which caused -8bit. To align on 16bit: 32+8=40
    //| sub rsp, 40
    dasm_put(Dst, 231);
#line 265 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Move address of function to register
    //| mov64 rax, (uintptr_t) functionPtr
    dasm_put(Dst, 237, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 268 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Call function
    //| call rax
    dasm_put(Dst, 242);
#line 271 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Delete shadow space
    //| add rsp, 40
    dasm_put(Dst, 246);
#line 274 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Move original rsp value to r12
    //| pop r12
    dasm_put(Dst, 251);
#line 277 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Restore rsp
    //| mov rsp, r12
    dasm_put(Dst, 254);
#line 280 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"


    //Put function result on top of stack
    //| movq xmm(stackPos), xmm0
    dasm_put(Dst, 258, (stackPos));
#line 284 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    //Restore old stack
    for(int i=stackPos-1; i>=0; i--){
        //| movq xmm(i), qword [rsp]
        //| add rsp, 8
        dasm_put(Dst, 267, (i));
#line 289 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

void Assembly__SSE_4_1::extractResult(){
     //| movq xmm0, xmm(stackPos)
     dasm_put(Dst, 281, (stackPos));
#line 294 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}


void Assembly__SSE_4_1::epilogue(){
    //| mov rsp, rbp
    //| pop rbp
    //| ret
    dasm_put(Dst, 290);
#line 301 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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

