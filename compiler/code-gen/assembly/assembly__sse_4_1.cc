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

#define LAST_XMM_REG 15


//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 30 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 32 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 34 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[696] = {
  85,65,84,72,137,229,255,72,129,252,236,239,255,252,243,64,15,126,4,240,140,
  37,237,255,72,131,252,236,8,76,139,20,37,237,76,137,20,36,255,102,64,15,214,
  133,253,240,140,233,255,76,139,20,36,76,137,149,233,72,131,196,8,255,252,
  243,64,15,126,192,240,132,240,52,255,252,243,64,15,126,133,253,240,140,233,
  255,72,131,252,236,8,255,102,64,15,214,4,240,140,36,255,76,139,149,233,76,
  137,20,36,255,252,243,64,15,126,4,240,140,36,255,76,139,20,36,76,137,149,
  233,255,72,131,252,236,8,76,139,149,233,76,137,20,36,255,249,255,252,233,
  245,255,252,242,64,15,194,192,240,132,240,52,235,102,64,15,56,23,192,240,
  133,240,53,255,102,64,15,214,68,240,140,36,252,248,255,252,243,64,15,126,
  68,240,140,36,252,240,255,72,131,196,16,255,252,242,64,15,194,68,240,140,
  36,252,248,235,102,64,15,56,23,192,240,133,240,53,255,252,243,64,15,126,68,
  240,140,36,232,255,15,133,245,255,15,132,245,255,252,242,64,15,88,192,240,
  132,240,52,255,252,242,64,15,88,4,240,140,36,72,131,196,8,255,102,64,15,214,
  68,240,140,36,252,248,252,243,64,15,126,68,240,140,36,8,252,242,64,15,88,
  4,240,140,36,102,64,15,214,68,240,140,36,8,252,243,64,15,126,68,240,140,36,
  252,248,72,131,196,8,255,252,242,64,15,92,192,240,132,240,52,255,252,242,
  64,15,92,4,240,140,36,72,131,196,8,255,102,64,15,214,68,240,140,36,252,248,
  252,243,64,15,126,68,240,140,36,8,252,242,64,15,92,4,240,140,36,102,64,15,
  214,68,240,140,36,8,252,243,64,15,126,68,240,140,36,252,248,72,131,196,8,
  255,252,242,64,15,89,192,240,132,240,52,255,252,242,64,15,89,4,240,140,36,
  72,131,196,8,255,102,64,15,214,68,240,140,36,252,248,252,243,64,15,126,68,
  240,140,36,8,252,242,64,15,89,4,240,140,36,102,64,15,214,68,240,140,36,8,
  252,243,64,15,126,68,240,140,36,252,248,72,131,196,8,255,252,242,64,15,94,
  192,240,132,240,52,255,252,242,64,15,94,4,240,140,36,72,131,196,8,255,102,
  64,15,214,68,240,140,36,252,248,252,243,64,15,126,68,240,140,36,8,252,242,
  64,15,94,4,240,140,36,102,64,15,214,68,240,140,36,8,252,243,64,15,126,68,
  240,140,36,252,248,72,131,196,8,255,102,64,15,214,132,253,240,140,36,233,
  255,76,139,148,253,36,233,76,137,148,253,36,233,255,252,243,64,15,126,132,
  253,240,140,36,233,255,73,137,228,255,72,131,228,252,240,255,72,131,252,236,
  32,255,72,184,237,237,255,252,255,208,255,76,137,228,255,73,137,226,255,72,
  129,196,239,255,252,243,64,15,126,192,240,140,255,72,131,252,236,8,102,15,
  214,4,36,255,252,243,65,15,126,130,253,240,132,233,255,77,139,154,233,76,
  137,156,253,36,233,255,252,243,64,15,126,192,240,44,255,252,243,15,126,4,
  36,255,72,137,252,236,65,92,93,195,255
};

#line 35 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

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
    dasm_init(&d, DASM_MAXSECTION);

    void* labels[lbl__MAX];
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    dasm_growpc(&d, 0);

    Dst = &d;

    // First 8 arguments are passed in registers
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

void Assembly__SSE_4_1::reserveMemoryForLocalVariables(int variableCount)
{
    //| sub rsp, variableCount*8
    dasm_put(Dst, 7, variableCount*8);
#line 85 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}
/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushConstantToStack(double value){
    stackPos++;
    double* ptr = static_cast<double*>(malloc(sizeof(double)));
    *ptr = value;
    if(stackPos <= LAST_XMM_REG) {
        //| movq xmm(stackPos), qword[ptr]
        dasm_put(Dst, 13, (stackPos), ptr);
#line 95 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| sub rsp, 8
        //| mov r10, qword[ptr]
        //| mov qword[rsp], r10
        dasm_put(Dst, 24, ptr);
#line 100 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::storeLocalVariable(int index) {
    if(stackPos <= LAST_XMM_REG) {
        //| movq qword [rbp-8-index*8], xmm(stackPos)
        dasm_put(Dst, 39, (stackPos), -8-index*8);
#line 109 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| mov r10, qword [rsp]
        //| mov qword [rbp-8-index*8], r10
        //| add rsp, 8
        dasm_put(Dst, 49, -8-index*8);
#line 114 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers

    if(stackPos <= LAST_XMM_REG) {
        if(index <= 7){
            //| movq xmm(stackPos), xmm(index)
            dasm_put(Dst, 62, (stackPos), (index));
#line 129 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq xmm(stackPos), qword [rbp+8+(index-7)*8]
            dasm_put(Dst, 73, (stackPos), 8+(index-7)*8);
#line 132 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    else{
        //| sub rsp, 8
        dasm_put(Dst, 84);
#line 136 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        if(index <= 7){
            //| movq qword[rsp], xmm(index)
            dasm_put(Dst, 90, (index));
#line 138 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword [rbp+8+(index-7)*8]
            //| mov qword[rsp], r10
            dasm_put(Dst, 99, 8+(index-7)*8);
#line 142 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }

}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(stackPos <= LAST_XMM_REG) {
        if(index <= 7){
            //| movq xmm(index), xmm(stackPos)
            dasm_put(Dst, 62, (index), (stackPos));
#line 155 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq qword [rbp+8+(index-7)*8], xmm(stackPos)
            dasm_put(Dst, 39, (stackPos), 8+(index-7)*8);
#line 158 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    else{
        if(index <= 7){
            //| movq xmm(index), qword[rsp]
            dasm_put(Dst, 108, (index));
#line 163 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword[rsp]
            //| mov qword [rbp+8+(index-7)*8], r10
            dasm_put(Dst, 118, 8+(index-7)*8);
#line 167 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        //| add rsp, 8
        dasm_put(Dst, 57);
#line 169 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushLocalVariableToStack(int index) {
    stackPos++;
    if(stackPos <= LAST_XMM_REG) {
        //| movq xmm(stackPos), qword [rbp-8-index*8]
        dasm_put(Dst, 73, (stackPos), -8-index*8);
#line 180 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| sub rsp, 8
        //| mov r10, qword [rbp-8-index*8]
        //| mov qword[rsp], r10
        dasm_put(Dst, 127, -8-index*8);
#line 185 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 141, labelNumber);
#line 194 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 143, labelNumber);
#line 201 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
    if(stackPos <= LAST_XMM_REG) {
        //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
        //| ptest xmm(stackPos), xmm(stackPos)
        dasm_put(Dst, 147, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 210 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if (stackPos == LAST_XMM_REG+1){
        //Backup one xmm register
        //| movq qword[rsp-8], xmm(0)
        dasm_put(Dst, 169, (0));
#line 214 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Load value in registers for comparison
        //| movq xmm(0), qword[rsp]
        dasm_put(Dst, 108, (0));
#line 217 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Conditions are not needed anymore, but only one was stored in memory
        // rsp has to be adapted before ptest, since the instruction modifies flags
        //| add rsp, 8
        dasm_put(Dst, 57);
#line 221 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //| cmpsd xmm(0), xmm(LAST_XMM_REG), operator_
        //| ptest xmm(0), xmm(0)
        dasm_put(Dst, 147, (0), (LAST_XMM_REG), operator_, (0), (0));
#line 224 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Restore register
        //| movq xmm(0), qword[rsp-16]
        dasm_put(Dst, 180, (0));
#line 227 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        // Backup one registers
        //| movq qword[rsp-8], xmm(0)
        dasm_put(Dst, 169, (0));
#line 231 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Load values in registers for comparison
        //| movq xmm(0), qword[rsp]
        dasm_put(Dst, 108, (0));
#line 234 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Conditions are not needed anymore
        // rsp has to be adapted before ptest, since the instruction modifies flags
        //| add rsp, 16
        dasm_put(Dst, 192);
#line 238 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //| cmpsd xmm(0), qword[rsp-8], operator_
        //| ptest xmm(0), xmm(0)
        dasm_put(Dst, 197, (0), operator_, (0), (0));
#line 241 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Restore register
        //| movq xmm(0), qword[rsp-24]
        dasm_put(Dst, 220, (0));
#line 244 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    }
    if(condition){
        //| jnz => labelNumber
        dasm_put(Dst, 231,  labelNumber);
#line 248 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| jz => labelNumber
        dasm_put(Dst, 235,  labelNumber);
#line 251 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    //Conditions are not needed anymore
    stackPos=stackPos-2;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateAddition(){
    if(stackPos <= LAST_XMM_REG) {
        //| addsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 239, (stackPos-1), (stackPos));
#line 262 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| addsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 250, (LAST_XMM_REG));
#line 266 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| addsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 264, (0), (0), (0), (0), (0));
#line 274 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateSubtraction(){
    if(stackPos <= LAST_XMM_REG) {
        //| subsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 318, (stackPos-1), (stackPos));
#line 284 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| subsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 329, (LAST_XMM_REG));
#line 288 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| subsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 343, (0), (0), (0), (0), (0));
#line 296 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateMultiplication(){
    if(stackPos <= LAST_XMM_REG) {
        //| mulsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 397, (stackPos-1), (stackPos));
#line 306 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| mulsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 408, (LAST_XMM_REG));
#line 310 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| mulsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 422, (0), (0), (0), (0), (0));
#line 318 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateDivision(){
    if(stackPos <= LAST_XMM_REG) {
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 476, (stackPos-1), (stackPos));
#line 328 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| divsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 487, (LAST_XMM_REG));
#line 332 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| divsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 501, (0), (0), (0), (0), (0));
#line 340 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::callExternalFunction(externalFunction functionPtr, unsigned numberOfArguments){

    //Backup the stack. Function arguments will be replaced by a result
    //and therefor excluded from the backup.
    //I assume, that there is no external function, which has more than 16 arguments...
    for(int i=0; i<=stackPos-numberOfArguments; i++){
        if(i<=LAST_XMM_REG){
            //| movq qword [rsp-(i+1)*8], xmm(i)
            dasm_put(Dst, 555, (i), -(i+1)*8);
#line 355 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword [rsp+(stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8]
            //| mov qword [rsp-(i+1)*8], r10
            dasm_put(Dst, 566, (stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8, -(i+1)*8);
#line 359 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }


    //Load parameters to register
    for(int i=stackPos-numberOfArguments; i<=stackPos; i++){
        if(i<=LAST_XMM_REG){
            //| movq xmm(i-(stackPos-numberOfArguments+1)), xmm(i)
            dasm_put(Dst, 62, (i-(stackPos-numberOfArguments+1)), (i));
#line 367 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq xmm(i-(stackPos-numberOfArguments+1)), qword[rsp+(stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8 ]
            dasm_put(Dst, 579, (i-(stackPos-numberOfArguments+1)), (stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8);
#line 370 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }


    // Save frame pointer in non-volatile register
    //| mov r12, rsp
    dasm_put(Dst, 591);
#line 376 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Subtract amount of register backup
    //| sub rsp, (stackPos-numberOfArguments)*8
    dasm_put(Dst, 7, (stackPos-numberOfArguments)*8);
#line 379 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Align frame pointer on 16 bit
    //| and rsp, -16
    dasm_put(Dst, 595);
#line 382 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Add Shadow space (32bit)
    // Not sure, if this is still needed.
    //| sub rsp, 32
    dasm_put(Dst, 601);
#line 386 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Move address of function to register
    //| mov64 rax, (uintptr_t) functionPtr
    dasm_put(Dst, 607, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 389 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Call function
    //| call rax
    dasm_put(Dst, 612);
#line 392 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Restore rsp
    //| mov rsp, r12
    dasm_put(Dst, 616);
#line 395 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"


    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    //| mov r10, rsp
    dasm_put(Dst, 620);
#line 400 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    if(stackPos > LAST_XMM_REG){
        if(stackPos-LAST_XMM_REG<=(numberOfArguments)){
            //| add rsp, (stackPos-LAST_XMM_REG)*8
            dasm_put(Dst, 624, (stackPos-LAST_XMM_REG)*8);
#line 403 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else{
            //| add rsp, numberOfArguments*8
            dasm_put(Dst, 624, numberOfArguments*8);
#line 406 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    stackPos = stackPos-numberOfArguments;



    stackPos++;
    //Put function result on top of stack
    if(stackPos <= LAST_XMM_REG){
        //| movq xmm(stackPos), xmm0
        dasm_put(Dst, 629, (stackPos));
#line 416 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| sub rsp, 8
        //| movq qword[rsp], xmm0
        dasm_put(Dst, 638);
#line 420 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }


    //Restore old stack
    for(int i=stackPos-1; i>=0; i--){
        if(i<=LAST_XMM_REG){
            //| movq xmm(i), qword [r10-(i+1)*8]
            dasm_put(Dst, 649, (i), -(i+1)*8);
#line 427 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r11, qword [r10-(i+1)*8]
            //| mov qword[rsp+(stackPos-i)*8], r11
            dasm_put(Dst, 660, -(i+1)*8, (stackPos-i)*8);
#line 431 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::extractResult(){
     if(stackPos <= LAST_XMM_REG){
        //| movq xmm0, xmm(stackPos)
        dasm_put(Dst, 671, (stackPos));
#line 441 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else {
        //| movq xmm0, qword[rsp]
        dasm_put(Dst, 680);
#line 444 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::epilogue(){
    //| mov rsp, rbp
    //| pop r12
    //| pop rbp
    //| ret
    dasm_put(Dst, 687);
#line 455 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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

