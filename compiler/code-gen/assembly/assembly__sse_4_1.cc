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
static const unsigned char impala_actions[577] = {
  85,65,84,72,137,229,255,72,129,252,236,239,255,72,184,237,237,72,137,132,
  253,36,233,252,243,64,15,126,132,253,240,140,36,233,255,72,184,237,237,72,
  137,132,253,36,233,255,102,64,15,214,133,253,240,140,233,255,76,139,148,253,
  36,233,76,137,149,233,255,252,243,64,15,126,192,240,132,240,52,255,252,243,
  64,15,126,133,253,240,140,233,255,102,64,15,214,132,253,240,140,36,233,255,
  76,139,149,233,76,137,148,253,36,233,255,249,255,252,233,245,255,252,242,
  64,15,194,192,240,132,240,52,235,102,64,15,56,23,192,240,133,240,53,255,252,
  242,64,15,194,132,253,240,140,36,233,235,102,64,15,56,23,192,240,133,240,
  53,255,15,133,245,255,15,132,245,255,252,242,64,15,88,192,240,132,240,52,
  255,252,242,64,15,88,132,253,240,140,36,233,255,102,64,15,214,132,253,240,
  140,36,233,252,243,64,15,126,132,253,240,140,36,233,252,242,64,15,88,132,
  253,240,140,36,233,102,64,15,214,132,253,240,140,36,233,252,243,64,15,126,
  132,253,240,140,36,233,255,252,242,64,15,92,192,240,132,240,52,255,252,242,
  64,15,92,132,253,240,140,36,233,255,102,64,15,214,132,253,240,140,36,233,
  252,243,64,15,126,132,253,240,140,36,233,252,242,64,15,92,132,253,240,140,
  36,233,102,64,15,214,132,253,240,140,36,233,252,243,64,15,126,132,253,240,
  140,36,233,255,252,242,64,15,89,192,240,132,240,52,255,252,242,64,15,89,132,
  253,240,140,36,233,255,102,64,15,214,132,253,240,140,36,233,252,243,64,15,
  126,132,253,240,140,36,233,252,242,64,15,89,132,253,240,140,36,233,102,64,
  15,214,132,253,240,140,36,233,252,243,64,15,126,132,253,240,140,36,233,255,
  252,242,64,15,94,192,240,132,240,52,255,252,242,64,15,94,132,253,240,140,
  36,233,255,102,64,15,214,132,253,240,140,36,233,252,243,64,15,126,132,253,
  240,140,36,233,252,242,64,15,94,132,253,240,140,36,233,102,64,15,214,132,
  253,240,140,36,233,252,243,64,15,126,132,253,240,140,36,233,255,76,139,148,
  253,36,233,76,137,148,253,36,233,255,73,137,228,255,72,131,228,252,240,255,
  72,131,252,236,32,255,72,184,237,237,255,252,255,208,255,76,137,228,255,252,
  243,64,15,126,192,240,140,255,102,15,214,132,253,36,233,255,76,139,156,253,
  36,233,76,137,156,253,36,233,255,252,243,64,15,126,192,240,44,255,252,243,
  15,126,132,253,36,233,255,72,137,252,236,65,92,93,195,255
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
#line 75 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
#line 88 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}
/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::pushConstantToStack(double value){
    stackPos++;
    union {
        double floatingPointValue;
        int64_t integerValue;
    };

    // DynASM is only able to accept imm64 values, when the mov64 instruction is used.
    // So we have to mask the floating point value as a 64 byte int. It's the only way
    // to load a floating point constant in a register...
    floatingPointValue = value;

    if(stackPos <= LAST_XMM_REG) {
        //| mov64 rax, integerValue
        //| mov qword[rsp-rspOffset()-8], rax
        //| movq xmm(stackPos), qword [rsp-rspOffset()-8]
        dasm_put(Dst, 13, (unsigned int)(integerValue), (unsigned int)((integerValue)>>32), -rspOffset()-8, (stackPos), -rspOffset()-8);
#line 108 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        //| mov64 rax, integerValue
        //| mov qword[rsp-rspOffset()], rax
        dasm_put(Dst, 35, (unsigned int)(integerValue), (unsigned int)((integerValue)>>32), -rspOffset());
#line 112 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::storeLocalVariable(int index) {
    if(stackPos <= LAST_XMM_REG) {
        //| movq qword [rbp-8-index*8], xmm(stackPos)
        dasm_put(Dst, 46, (stackPos), -8-index*8);
#line 121 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| mov r10, qword [rsp-rspOffset()]
        //| mov qword [rbp-8-index*8], r10
        dasm_put(Dst, 56, -rspOffset(), -8-index*8);
#line 125 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
            dasm_put(Dst, 67, (stackPos), (index));
#line 140 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq xmm(stackPos), qword [rbp+8+(index-7)*8]
            dasm_put(Dst, 78, (stackPos), 8+(index-7)*8);
#line 143 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    else{
        if(index <= 7){
            //| movq qword[rsp-rspOffset()], xmm(index)
            dasm_put(Dst, 89, (index), -rspOffset());
#line 148 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword [rbp+8+(index-7)*8]
            //| mov qword[rsp-rspOffset()], r10
            dasm_put(Dst, 100, 8+(index-7)*8, -rspOffset());
#line 152 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
            dasm_put(Dst, 67, (index), (stackPos));
#line 165 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| movq qword [rbp+8+(index-7)*8], xmm(stackPos)
            dasm_put(Dst, 46, (stackPos), 8+(index-7)*8);
#line 168 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    else{
        if(index <= 7){
            //| movq xmm(index), qword[rsp-rspOffset()]
            dasm_put(Dst, 23, (index), -rspOffset());
#line 173 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            //| mov r10, qword[rsp-rspOffset()]
            //| mov qword [rbp+8+(index-7)*8], r10
            dasm_put(Dst, 56, -rspOffset(), 8+(index-7)*8);
#line 177 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
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
        dasm_put(Dst, 78, (stackPos), -8-index*8);
#line 189 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| mov r10, qword [rbp-8-index*8]
        //| mov qword[rsp-rspOffset()], r10
        dasm_put(Dst, 100, -8-index*8, -rspOffset());
#line 193 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }

}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 111, labelNumber);
#line 202 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 113, labelNumber);
#line 209 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
    if(stackPos <= LAST_XMM_REG) {
        //| cmpsd xmm(stackPos), xmm(stackPos-1), operator_
        //| ptest xmm(stackPos), xmm(stackPos)
        dasm_put(Dst, 117, (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 218 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if (stackPos == LAST_XMM_REG+1){
        //Backup one xmm register
        //| movq qword[rsp-rspOffset()-8], xmm(0)
        dasm_put(Dst, 89, (0), -rspOffset()-8);
#line 222 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Load value in registers for comparison
        //| movq xmm(0), qword[rsp-rspOffset()]
        dasm_put(Dst, 23, (0), -rspOffset());
#line 225 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //| cmpsd xmm(0), xmm(LAST_XMM_REG), operator_
        //| ptest xmm(0), xmm(0)
        dasm_put(Dst, 117, (0), (LAST_XMM_REG), operator_, (0), (0));
#line 228 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Restore register
        //| movq xmm(0), qword[rsp-rspOffset()-8]
        dasm_put(Dst, 23, (0), -rspOffset()-8);
#line 231 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        // Backup one registers
        //| movq qword[rsp-rspOffset()-8], xmm(0)
        dasm_put(Dst, 89, (0), -rspOffset()-8);
#line 235 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        // Load values in registers for comparison
        //| movq xmm(0), qword[rsp-rspOffset()]
        dasm_put(Dst, 23, (0), -rspOffset());
#line 238 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //| cmpsd xmm(0), qword[rsp-rspOffset()+8], operator_
        //| ptest xmm(0), xmm(0)
        dasm_put(Dst, 139, (0), -rspOffset()+8, operator_, (0), (0));
#line 241 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

        //Restore register
        //| movq xmm(0), qword[rsp-rspOffset()-8]
        dasm_put(Dst, 23, (0), -rspOffset()-8);
#line 244 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    }
    if(condition){
        //| jnz => labelNumber
        dasm_put(Dst, 162,  labelNumber);
#line 248 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| jz => labelNumber
        dasm_put(Dst, 166,  labelNumber);
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
        dasm_put(Dst, 170, (stackPos-1), (stackPos));
#line 262 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| addsd xmm(LAST_XMM_REG), qword[rsp-rspOffset()]
        dasm_put(Dst, 181, (LAST_XMM_REG), -rspOffset());
#line 265 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-rspOffset()-8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()+8]
        //| addsd xmm(0), qword[rsp-rspOffset()]
        //| movq qword[rsp-rspOffset()+8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()-8]
        dasm_put(Dst, 193, (0), -rspOffset()-8, (0), -rspOffset()+8, (0), -rspOffset(), (0), -rspOffset()+8, (0), -rspOffset()-8);
#line 272 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateSubtraction(){
    if(stackPos <= LAST_XMM_REG) {
        //| subsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 247, (stackPos-1), (stackPos));
#line 282 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| subsd xmm(LAST_XMM_REG), qword[rsp-rspOffset()]
        dasm_put(Dst, 258, (LAST_XMM_REG), -rspOffset());
#line 285 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-rspOffset()-8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()+8]
        //| subsd xmm(0), qword[rsp-rspOffset()]
        //| movq qword[rsp-rspOffset()+8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()-8]
        dasm_put(Dst, 270, (0), -rspOffset()-8, (0), -rspOffset()+8, (0), -rspOffset(), (0), -rspOffset()+8, (0), -rspOffset()-8);
#line 292 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateMultiplication(){
    if(stackPos <= LAST_XMM_REG) {
        //| mulsd xmm(stackPos-1), xmm(stackPos)
        dasm_put(Dst, 324, (stackPos-1), (stackPos));
#line 302 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| mulsd xmm(LAST_XMM_REG), qword[rsp-rspOffset()]
        dasm_put(Dst, 335, (LAST_XMM_REG), -rspOffset());
#line 305 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-rspOffset()-8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()+8]
        //| mulsd xmm(0), qword[rsp-rspOffset()]
        //| movq qword[rsp-rspOffset()+8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()-8]
        dasm_put(Dst, 347, (0), -rspOffset()-8, (0), -rspOffset()+8, (0), -rspOffset(), (0), -rspOffset()+8, (0), -rspOffset()-8);
#line 312 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::calculateDivision(){
    if(stackPos <= LAST_XMM_REG) {
    //| divsd xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 401, (stackPos-1), (stackPos));
#line 322 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else if(stackPos == LAST_XMM_REG+1){
        //| divsd xmm(LAST_XMM_REG), qword[rsp-rspOffset()]
        dasm_put(Dst, 412, (LAST_XMM_REG), -rspOffset());
#line 325 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else{
        //| movq qword[rsp-rspOffset()-8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()+8]
        //| divsd xmm(0), qword[rsp-rspOffset()]
        //| movq qword[rsp-rspOffset()+8], xmm(0)
        //| movq xmm(0), qword[rsp-rspOffset()-8]
        dasm_put(Dst, 424, (0), -rspOffset()-8, (0), -rspOffset()+8, (0), -rspOffset(), (0), -rspOffset()+8, (0), -rspOffset()-8);
#line 332 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    stackPos--;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::callExternalFunction(externalFunction functionPtr, unsigned numberOfArguments){

    //Backup the stack. Function arguments will be replaced by a result
    //and therefor excluded from the backup.
    //I assume, that there is no external function, which has more than 8 arguments...
    for(int i=0; i<=stackPos-numberOfArguments+1; i++){
        int backupOffset = rspOffset() + (i+1)*8;
        if(i<=LAST_XMM_REG){
            //| movq qword [rsp-backupOffset], xmm(i)
            dasm_put(Dst, 89, (i), -backupOffset);
#line 348 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            int localRspOffset = (i-LAST_XMM_REG)*8;
            //| mov r10, qword [rsp-localRspOffset]
            //| mov qword [rsp-backupOffset], r10
            dasm_put(Dst, 478, -localRspOffset, -backupOffset);
#line 353 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }


    //Load parameters to register
    for(int i=stackPos-numberOfArguments+1; i<=stackPos; i++){
        int argumentRegisterNumber = i-(stackPos-numberOfArguments+1);
        if(i<=LAST_XMM_REG){
            //| movq xmm(argumentRegisterNumber), xmm(i)
            dasm_put(Dst, 67, (argumentRegisterNumber), (i));
#line 362 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            int localRspOffset = (i-LAST_XMM_REG)*8;
            //| movq xmm(argumentRegisterNumber), qword[rsp-localRspOffset]
            dasm_put(Dst, 23, (argumentRegisterNumber), -localRspOffset);
#line 366 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }


    // Save frame pointer in non-volatile register
    //| mov r12, rsp
    dasm_put(Dst, 491);
#line 372 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Subtract rpn stack
    if(stackPos > LAST_XMM_REG){
        //| sub rsp, rspOffset()
        dasm_put(Dst, 7, rspOffset());
#line 376 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    // Subtract amount of register backup
    //| sub rsp, (stackPos-numberOfArguments+1)*8
    dasm_put(Dst, 7, (stackPos-numberOfArguments+1)*8);
#line 379 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Align frame pointer on 16 bit
    //| and rsp, -16
    dasm_put(Dst, 495);
#line 382 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Add Shadow space (32bit)
    // Not sure, if this is still needed.
    //| sub rsp, 32
    dasm_put(Dst, 501);
#line 386 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Move address of function to register
    //| mov64 rax, (uintptr_t) functionPtr
    dasm_put(Dst, 507, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 389 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Call function
    //| call rax
    dasm_put(Dst, 512);
#line 392 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"

    // Restore rsp
    //| mov rsp, r12
    dasm_put(Dst, 516);
#line 395 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"


    //Put function result on top of stack
    if((stackPos-numberOfArguments+1) <= LAST_XMM_REG){
        //| movq xmm(stackPos-numberOfArguments+1), xmm0
        dasm_put(Dst, 520, (stackPos-numberOfArguments+1));
#line 400 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }
    else {
        int localRspOffset = ((stackPos-numberOfArguments+1)-LAST_XMM_REG)*8;
        //| movq qword[rsp-localRspOffset], xmm0
        dasm_put(Dst, 529, -localRspOffset);
#line 404 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
    }


    //Restore old stack
    for(int i=stackPos-numberOfArguments; i>=0; i--){
        if(i<=LAST_XMM_REG){
            //| movq xmm(i), qword [rsp-rspOffset()-(i+1)*8]
            dasm_put(Dst, 23, (i), -rspOffset()-(i+1)*8);
#line 411 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
        else {
            int localRspOffset = ((stackPos-numberOfArguments+1)-LAST_XMM_REG)*8;
            //| mov r11, qword [rsp-rspOffset()-(i+1)*8]
            //| mov qword[rsp-localRspOffset+(stackPos-i)*8], r11
            dasm_put(Dst, 537, -rspOffset()-(i+1)*8, -localRspOffset+(stackPos-i)*8);
#line 416 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
        }
    }
    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    stackPos = stackPos-numberOfArguments+1;
}

/**
 * @see assembly.hh
 */
void Assembly__SSE_4_1::extractResult(){
     if(stackPos <= LAST_XMM_REG){
        //| movq xmm0, xmm(stackPos)
        dasm_put(Dst, 550, (stackPos));
#line 429 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
     }
     else {
        //| movq xmm0, qword[rsp-rspOffset()]
        dasm_put(Dst, 559, -rspOffset());
#line 432 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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
    dasm_put(Dst, 568);
#line 443 "compiler/code-gen/assembly/assembly__sse_4_1.dasc"
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

int Assembly__SSE_4_1::rspOffset(){
    if((stackPos-LAST_XMM_REG) <= 0){
        return 0;
    }
    return (stackPos-LAST_XMM_REG)*8;
}

void Assembly__SSE_4_1::pushStackPos(){
    stackPosStack.push(stackPos);
}

void Assembly__SSE_4_1::popStackPos(){
    stackPos = stackPosStack.top();
    stackPosStack.pop();
}
