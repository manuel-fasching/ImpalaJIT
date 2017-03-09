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
#include <cstring>
#include <inttypes.h>

#define LAST_XMM_REG 15


//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 32 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.section code, data
#define DASM_SECTION_CODE	0
#define DASM_SECTION_DATA	1
#define DASM_MAXSECTION		2
#line 34 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 36 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[706] = {
  85,65,84,72,137,229,255,72,129,252,236,239,255,72,184,237,237,72,137,68,36,
  252,248,252,243,64,15,126,68,240,140,36,252,248,255,72,131,252,236,8,72,184,
  237,237,72,137,4,36,255,102,64,15,214,133,253,240,140,233,255,76,139,20,36,
  76,137,149,233,72,131,196,8,255,252,243,64,15,126,192,240,132,240,52,255,
  252,243,64,15,126,133,253,240,140,233,255,72,131,252,236,8,255,102,64,15,
  214,4,240,140,36,255,76,139,149,233,76,137,20,36,255,252,243,64,15,126,4,
  240,140,36,255,76,139,20,36,76,137,149,233,255,72,131,252,236,8,76,139,149,
  233,76,137,20,36,255,249,255,252,233,245,255,252,242,64,15,194,192,240,132,
  240,52,235,102,64,15,56,23,192,240,133,240,53,255,102,64,15,214,68,240,140,
  36,252,248,255,252,243,64,15,126,68,240,140,36,252,240,255,72,131,196,16,
  255,252,242,64,15,194,68,240,140,36,252,248,235,102,64,15,56,23,192,240,133,
  240,53,255,252,243,64,15,126,68,240,140,36,232,255,15,133,245,255,15,132,
  245,255,252,242,64,15,88,192,240,132,240,52,255,252,242,64,15,88,4,240,140,
  36,72,131,196,8,255,102,64,15,214,68,240,140,36,252,248,252,243,64,15,126,
  68,240,140,36,8,252,242,64,15,88,4,240,140,36,102,64,15,214,68,240,140,36,
  8,252,243,64,15,126,68,240,140,36,252,248,72,131,196,8,255,252,242,64,15,
  92,192,240,132,240,52,255,252,242,64,15,92,4,240,140,36,72,131,196,8,255,
  102,64,15,214,68,240,140,36,252,248,252,243,64,15,126,68,240,140,36,8,252,
  242,64,15,92,4,240,140,36,102,64,15,214,68,240,140,36,8,252,243,64,15,126,
  68,240,140,36,252,248,72,131,196,8,255,252,242,64,15,89,192,240,132,240,52,
  255,252,242,64,15,89,4,240,140,36,72,131,196,8,255,102,64,15,214,68,240,140,
  36,252,248,252,243,64,15,126,68,240,140,36,8,252,242,64,15,89,4,240,140,36,
  102,64,15,214,68,240,140,36,8,252,243,64,15,126,68,240,140,36,252,248,72,
  131,196,8,255,252,242,64,15,94,192,240,132,240,52,255,252,242,64,15,94,4,
  240,140,36,72,131,196,8,255,102,64,15,214,68,240,140,36,252,248,252,243,64,
  15,126,68,240,140,36,8,252,242,64,15,94,4,240,140,36,102,64,15,214,68,240,
  140,36,8,252,243,64,15,126,68,240,140,36,252,248,72,131,196,8,255,102,64,
  15,214,132,253,240,140,36,233,255,76,139,148,253,36,233,76,137,148,253,36,
  233,255,252,243,64,15,126,132,253,240,140,36,233,255,73,137,228,255,72,131,
  228,252,240,255,72,131,252,236,32,255,72,184,237,237,255,252,255,208,255,
  76,137,228,255,73,137,226,255,72,129,196,239,255,252,243,64,15,126,192,240,
  140,255,72,131,252,236,8,102,15,214,4,36,255,252,243,65,15,126,130,253,240,
  132,233,255,77,139,154,233,76,137,156,253,36,233,255,252,243,64,15,126,192,
  240,44,255,252,243,15,126,4,36,255,72,137,252,236,65,92,93,195,255
};

#line 37 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

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
#line 74 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
#line 87 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}
/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushConstantToStack(double value){
    stackPos++;

    // DynASM is only able to accept imm64 values, when the mov64 instruction is used.
    // So we have to mask the floating point value as a 64 byte int. It's the only way
    // to load a floating point constant in a register...
    int64_t imm64;
    memcpy(&imm64, &value, sizeof(value));

    if(stackPos <= LAST_XMM_REG) {
        //| mov64 rax, imm64
        //| mov qword[rsp-8], rax
        //| movq xmm(stackPos), qword [rsp-8]
        dasm_put(Dst, 13, (unsigned int)(imm64), (unsigned int)((imm64)>>32), (stackPos));
#line 104 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| sub rsp, 8
        //| mov64 rax, imm64
        //| mov qword[rsp], rax
        dasm_put(Dst, 35, (unsigned int)(imm64), (unsigned int)((imm64)>>32));
#line 109 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::storeLocalVariable(int index) {
    if(stackPos <= LAST_XMM_REG) {
        //| movq qword [rbp-8-index*8], xmm(stackPos)
        dasm_put(Dst, 49, (stackPos), -8-index*8);
#line 118 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| mov r10, qword [rsp]
        //| mov qword [rbp-8-index*8], r10
        //| add rsp, 8
        dasm_put(Dst, 59, -8-index*8);
#line 123 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
            dasm_put(Dst, 72, (stackPos), (index));
#line 138 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq xmm(stackPos), qword [rbp+8+(index-7)*8]
            dasm_put(Dst, 83, (stackPos), 8+(index-7)*8);
#line 141 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    else{
        //| sub rsp, 8
        dasm_put(Dst, 94);
#line 145 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        if(index <= 7){
            //| movq qword[rsp], xmm(index)
            dasm_put(Dst, 100, (index));
#line 147 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword [rbp+8+(index-7)*8]
            //| mov qword[rsp], r10
            dasm_put(Dst, 109, 8+(index-7)*8);
#line 151 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
            dasm_put(Dst, 72, (index), (stackPos));
#line 164 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq qword [rbp+8+(index-7)*8], xmm(stackPos)
            dasm_put(Dst, 49, (stackPos), 8+(index-7)*8);
#line 167 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    else{
        if(index <= 7){
            //| movq xmm(index), qword[rsp]
            dasm_put(Dst, 118, (index));
#line 172 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword[rsp]
            //| mov qword [rbp+8+(index-7)*8], r10
            dasm_put(Dst, 128, 8+(index-7)*8);
#line 176 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        //| add rsp, 8
        dasm_put(Dst, 67);
#line 178 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
        dasm_put(Dst, 83, (stackPos), -8-index*8);
#line 189 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| sub rsp, 8
        //| mov r10, qword [rbp-8-index*8]
        //| mov qword[rsp], r10
        dasm_put(Dst, 137, -8-index*8);
#line 194 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 151, labelNumber);
#line 203 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 153, labelNumber);
#line 210 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
    if(stackPos <= LAST_XMM_REG) {
        //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
        //| ptest xmm(stackPos), xmm(stackPos)
        dasm_put(Dst, 157, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 219 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if (stackPos == LAST_XMM_REG+1){
        //Backup one xmm register
        //| movq qword[rsp-8], xmm(0)
        dasm_put(Dst, 179, (0));
#line 223 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Load value in registers for comparison
        //| movq xmm(0), qword[rsp]
        dasm_put(Dst, 118, (0));
#line 226 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Conditions are not needed anymore, but only one was stored in memory
        // rsp has to be adapted before ptest, since the instruction modifies flags
        //| add rsp, 8
        dasm_put(Dst, 67);
#line 230 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //| cmpsd xmm(0), xmm(LAST_XMM_REG), operator_
        //| ptest xmm(0), xmm(0)
        dasm_put(Dst, 157, (0), (LAST_XMM_REG), operator_, (0), (0));
#line 233 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Restore register
        //| movq xmm(0), qword[rsp-16]
        dasm_put(Dst, 190, (0));
#line 236 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        // Backup one registers
        //| movq qword[rsp-8], xmm(0)
        dasm_put(Dst, 179, (0));
#line 240 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Load values in registers for comparison
        //| movq xmm(0), qword[rsp]
        dasm_put(Dst, 118, (0));
#line 243 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Conditions are not needed anymore
        // rsp has to be adapted before ptest, since the instruction modifies flags
        //| add rsp, 16
        dasm_put(Dst, 202);
#line 247 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //| cmpsd xmm(0), qword[rsp-8], operator_
        //| ptest xmm(0), xmm(0)
        dasm_put(Dst, 207, (0), operator_, (0), (0));
#line 250 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Restore register
        //| movq xmm(0), qword[rsp-24]
        dasm_put(Dst, 230, (0));
#line 253 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    }
    if(condition){
        //| jnz => labelNumber
        dasm_put(Dst, 241,  labelNumber);
#line 257 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| jz => labelNumber
        dasm_put(Dst, 245,  labelNumber);
#line 260 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
        dasm_put(Dst, 249, (stackPos-1), (stackPos));
#line 271 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| addsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 260, (LAST_XMM_REG));
#line 275 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| addsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 274, (0), (0), (0), (0), (0));
#line 283 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateSubtraction(){
    if(stackPos <= LAST_XMM_REG) {
        //| subsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 328, (stackPos-1), (stackPos));
#line 293 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| subsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 339, (LAST_XMM_REG));
#line 297 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| subsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 353, (0), (0), (0), (0), (0));
#line 305 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateMultiplication(){
    if(stackPos <= LAST_XMM_REG) {
        //| mulsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 407, (stackPos-1), (stackPos));
#line 315 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| mulsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 418, (LAST_XMM_REG));
#line 319 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| mulsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 432, (0), (0), (0), (0), (0));
#line 327 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateDivision(){
    if(stackPos <= LAST_XMM_REG) {
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 486, (stackPos-1), (stackPos));
#line 337 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| divsd xmm(LAST_XMM_REG), qword[rsp]
        //| add rsp, 8
        dasm_put(Dst, 497, (LAST_XMM_REG));
#line 341 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-8], xmm(0)
        //| movq xmm(0), qword[rsp+8]
        //| divsd xmm(0), qword[rsp]
        //| movq qword[rsp+8], xmm(0)
        //| movq xmm(0), qword[rsp-8]
        //| add rsp, 8
        dasm_put(Dst, 511, (0), (0), (0), (0), (0));
#line 349 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
            dasm_put(Dst, 565, (i), -(i+1)*8);
#line 364 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword [rsp+(stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8]
            //| mov qword [rsp-(i+1)*8], r10
            dasm_put(Dst, 576, (stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8, -(i+1)*8);
#line 368 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }


    //Load parameters to register
    for(int i=stackPos-numberOfArguments; i<=stackPos; i++){
        if(i<=LAST_XMM_REG){
            //| movq xmm(i-(stackPos-numberOfArguments+1)), xmm(i)
            dasm_put(Dst, 72, (i-(stackPos-numberOfArguments+1)), (i));
#line 376 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq xmm(i-(stackPos-numberOfArguments+1)), qword[rsp+(stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8 ]
            dasm_put(Dst, 589, (i-(stackPos-numberOfArguments+1)), (stackPos-LAST_XMM_REG)*8-(i-LAST_XMM_REG)*8);
#line 379 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }


    // Save frame pointer in non-volatile register
    //| mov r12, rsp
    dasm_put(Dst, 601);
#line 385 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Subtract amount of register backup
    //| sub rsp, (stackPos-numberOfArguments)*8
    dasm_put(Dst, 7, (stackPos-numberOfArguments)*8);
#line 388 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Align frame pointer on 16 bit
    //| and rsp, -16
    dasm_put(Dst, 605);
#line 391 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Add Shadow space (32bit)
    // Not sure, if this is still needed.
    //| sub rsp, 32
    dasm_put(Dst, 611);
#line 395 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Move address of function to register
    //| mov64 rax, (uintptr_t) functionPtr
    dasm_put(Dst, 617, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 398 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Call function
    //| call rax
    dasm_put(Dst, 622);
#line 401 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Restore rsp
    //| mov rsp, r12
    dasm_put(Dst, 626);
#line 404 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"


    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    //| mov r10, rsp
    dasm_put(Dst, 630);
#line 409 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    if(stackPos > LAST_XMM_REG){
        if(stackPos-LAST_XMM_REG<=(numberOfArguments)){
            //| add rsp, (stackPos-LAST_XMM_REG)*8
            dasm_put(Dst, 634, (stackPos-LAST_XMM_REG)*8);
#line 412 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else{
            //| add rsp, numberOfArguments*8
            dasm_put(Dst, 634, numberOfArguments*8);
#line 415 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    stackPos = stackPos-numberOfArguments;



    stackPos++;
    //Put function result on top of stack
    if(stackPos <= LAST_XMM_REG){
        //| movq xmm(stackPos), xmm0
        dasm_put(Dst, 639, (stackPos));
#line 425 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| sub rsp, 8
        //| movq qword[rsp], xmm0
        dasm_put(Dst, 648);
#line 429 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }


    //Restore old stack
    for(int i=stackPos-1; i>=0; i--){
        if(i<=LAST_XMM_REG){
            //| movq xmm(i), qword [r10-(i+1)*8]
            dasm_put(Dst, 659, (i), -(i+1)*8);
#line 436 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r11, qword [r10-(i+1)*8]
            //| mov qword[rsp+(stackPos-i)*8], r11
            dasm_put(Dst, 670, -(i+1)*8, (stackPos-i)*8);
#line 440 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::extractResult(){
     if(stackPos <= LAST_XMM_REG){
        //| movq xmm0, xmm(stackPos)
        dasm_put(Dst, 681, (stackPos));
#line 450 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else {
        //| movq xmm0, qword[rsp]
        dasm_put(Dst, 690);
#line 453 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
    dasm_put(Dst, 697);
#line 464 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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

