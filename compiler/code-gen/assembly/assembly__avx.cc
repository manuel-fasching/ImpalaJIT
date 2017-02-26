/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.4.0, DynASM x64 version 1.4.0
** DO NOT EDIT! The original file is in "compiler/code-gen/assembly/assembly__avx.dasc".
*/

#line 1 "compiler/code-gen/assembly/assembly__avx.dasc"
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

#include <assembly__avx.hh>
#include <iostream>
#include <stdio.h>
#include <stdint.h>


//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 27 "compiler/code-gen/assembly/assembly__avx.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 29 "compiler/code-gen/assembly/assembly__avx.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 31 "compiler/code-gen/assembly/assembly__avx.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[275] = {
  85,72,137,229,255,197,252,250,126,4,240,132,37,237,255,72,131,252,236,8,196,
  225,252,249,214,4,240,133,36,255,196,225,122,126,192,240,133,240,45,255,197,
  252,250,126,133,253,240,132,233,255,196,225,252,249,214,133,253,240,133,233,
  255,249,255,252,233,245,255,196,225,123,240,160,194,192,240,133,240,45,235,
  196,226,121,14,192,240,133,240,37,255,15,133,245,255,15,132,245,255,248,1,
  255,248,2,255,248,3,255,252,233,244,247,255,252,233,244,248,255,252,233,244,
  249,255,15,133,244,247,255,15,133,244,248,255,15,133,244,249,255,15,132,244,
  247,255,15,132,244,248,255,15,132,244,249,255,196,225,123,240,160,88,192,
  240,133,240,45,255,196,225,123,240,160,92,192,240,133,240,45,255,196,225,
  123,240,160,89,192,240,133,240,45,255,196,225,123,240,160,94,192,240,133,
  240,45,255,73,137,228,255,72,131,228,252,240,255,65,84,255,72,131,252,236,
  40,255,72,184,237,237,255,252,255,208,255,72,131,196,40,255,65,92,255,76,
  137,228,255,197,252,250,126,192,240,132,255,197,252,250,126,4,240,132,36,
  72,131,196,8,255,196,225,122,126,192,240,45,255,72,137,252,236,93,195,255
};

#line 32 "compiler/code-gen/assembly/assembly__avx.dasc"

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif

Assembly__AVX::~Assembly__AVX()
{
    dasm_free(&d);
}

void Assembly__AVX::initialize(int parameterCount) {
    dasm_init(&d, DASM_MAXSECTION);

    void* labels[lbl__MAX];
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    dasm_growpc(&d, 0);

    Dst = &d;

    stackPos = parameterCount >= 8 ? 7 : parameterCount-1;
}

void Assembly__AVX::prologue(){
    //| push rbp
    //| mov rbp, rsp
    dasm_put(Dst, 0);
#line 62 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly__AVX::pushConstantToStack(double value){
    stackPos++;
    double* ptr = static_cast<double*>(malloc(sizeof(double)));
    *ptr = value;
    //| vmovq xmm(stackPos), qword[ptr]
    dasm_put(Dst, 5, (stackPos), ptr);
#line 74 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::storeLocalVariable() {
    //| sub rsp, 8
    //| vmovq qword [rsp], xmm(stackPos)
    dasm_put(Dst, 15, (stackPos));
#line 79 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| vmovq xmm(stackPos), xmm(index)
        dasm_put(Dst, 30, (stackPos), (index));
#line 87 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
    else {
        //| vmovq xmm(stackPos), qword [rbp+8+(index-7)*8]
        dasm_put(Dst, 40, (stackPos), 8+(index-7)*8);
#line 90 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
}

void Assembly__AVX::popStack(){
    stackPos--;
}

void Assembly__AVX::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| vmovq xmm(index), xmm(stackPos)
        dasm_put(Dst, 30, (index), (stackPos));
#line 101 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
    else {
        //| vmovq qword [rbp+8+(index-7)*8], xmm(stackPos)
        dasm_put(Dst, 50, (stackPos), 8+(index-7)*8);
#line 104 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
    stackPos--;
}

void Assembly__AVX::pushLocalVariableToStack(int index) {
    stackPos++;
    //| vmovq xmm(stackPos), qword [rbp-8-index*8]
    dasm_put(Dst, 40, (stackPos), -8-index*8);
#line 111 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::replaceLocalVariable(int index) {
    //| vmovq qword [rbp-8-index*8], xmm(stackPos)
    dasm_put(Dst, 50, (stackPos), -8-index*8);
#line 115 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 61, labelNumber);
#line 120 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 63, labelNumber);
#line 124 "compiler/code-gen/assembly/assembly__avx.dasc"
}


void Assembly__AVX::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| vcmpsd xmm(stackPos), xmm(stackPos), xmm(stackPos-1), operator_
     //| vptestps xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 67, (stackPos), (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 130 "compiler/code-gen/assembly/assembly__avx.dasc"
     if(condition){
         //| jnz => labelNumber
         dasm_put(Dst, 89,  labelNumber);
#line 132 "compiler/code-gen/assembly/assembly__avx.dasc"
     }
     else{
        //| jz => labelNumber
        dasm_put(Dst, 93,  labelNumber);
#line 135 "compiler/code-gen/assembly/assembly__avx.dasc"
     }
     stackPos--;
}

void Assembly__AVX::addLocalLabel(unsigned labelNumber) {
    switch(labelNumber){
        case 1: {
            //| 1:
            dasm_put(Dst, 97);
#line 143 "compiler/code-gen/assembly/assembly__avx.dasc"
            break;
            }
        case 2: {
            //| 2:
            dasm_put(Dst, 100);
#line 147 "compiler/code-gen/assembly/assembly__avx.dasc"
            break;
        }
        case 3: {
            //| 3:
            dasm_put(Dst, 103);
#line 151 "compiler/code-gen/assembly/assembly__avx.dasc"
            break;
        }
    }
}

void Assembly__AVX::jumpForwardToLocalLabel(unsigned labelNumber) {
    switch(labelNumber){
        case 1: {
            //| jmp >1
            dasm_put(Dst, 106);
#line 160 "compiler/code-gen/assembly/assembly__avx.dasc"
            break;
        }
        case 2: {
            //| jmp >2
            dasm_put(Dst, 111);
#line 164 "compiler/code-gen/assembly/assembly__avx.dasc"
            break;
        }
        case 3: {
            //| jmp >3
            dasm_put(Dst, 116);
#line 168 "compiler/code-gen/assembly/assembly__avx.dasc"
            break;
        }
    }
}

void Assembly__AVX::conditionalJumpForwardToLocalLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| vcmpsd xmm(stackPos), xmm(stackPos), xmm(stackPos-1), operator_
     //| vptestps xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 67, (stackPos), (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 176 "compiler/code-gen/assembly/assembly__avx.dasc"
     if(condition){
        switch(labelNumber){
            case 1: {
                //| jnz >1
                dasm_put(Dst, 121);
#line 180 "compiler/code-gen/assembly/assembly__avx.dasc"
                break;
            }
            case 2: {
                //| jnz >2
                dasm_put(Dst, 126);
#line 184 "compiler/code-gen/assembly/assembly__avx.dasc"
                break;
            }
            case 3: {
                //| jnz >3
                dasm_put(Dst, 131);
#line 188 "compiler/code-gen/assembly/assembly__avx.dasc"
                break;
            }
        }
     }
     else{
        switch(labelNumber){
            case 1: {
                //| jz >1
                dasm_put(Dst, 136);
#line 196 "compiler/code-gen/assembly/assembly__avx.dasc"
                break;
            }
            case 2: {
                //| jz >2
                dasm_put(Dst, 141);
#line 200 "compiler/code-gen/assembly/assembly__avx.dasc"
                break;
            }
            case 3: {
                //| jz >3
                dasm_put(Dst, 146);
#line 204 "compiler/code-gen/assembly/assembly__avx.dasc"
                break;
            }
        }
     }
     stackPos--;
}

void Assembly__AVX::calculateAddition(){
    //| vaddsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 151, (stackPos-1), (stackPos-1), (stackPos));
#line 213 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateSubtraction(){
    //| vsubsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 163, (stackPos-1), (stackPos-1), (stackPos));
#line 218 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateMultiplication(){
    //| vmulsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 175, (stackPos-1), (stackPos-1), (stackPos));
#line 223 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateDivision(){
    //| vdivsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 187, (stackPos-1), (stackPos-1), (stackPos));
#line 228 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::callExternalFunction(externalFunction functionPtr, unsigned numberOfArguments){

    //Backup the stack. Function arguments will be replaced by a result
    //and therefor excluded from the backup.
    for(int i=0; i<stackPos-(numberOfArguments-1); i++){
       //| sub rsp, 8
       //| vmovq qword [rsp], xmm(i)
       dasm_put(Dst, 15, (i));
#line 238 "compiler/code-gen/assembly/assembly__avx.dasc"
    }


    //Load parameters to register
    for(int i=stackPos-(numberOfArguments-1); i<=stackPos; i++){
       //| vmovq xmm(i-(stackPos-(numberOfArguments-1))), xmm(i)
       dasm_put(Dst, 30, (i-(stackPos-(numberOfArguments-1))), (i));
#line 244 "compiler/code-gen/assembly/assembly__avx.dasc"
    }

    //Function parameters are not needed anymore
    //Set the stackPos accordingly
    stackPos = stackPos-(numberOfArguments-1);
    //Perform function Call

    // Save rsp register
    //| mov r12, rsp
    dasm_put(Dst, 199);
#line 253 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Align frame pointer
    //| and rsp, -16
    dasm_put(Dst, 203);
#line 256 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Save old rsp value in aligned environment
    //| push r12
    dasm_put(Dst, 209);
#line 259 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Add Shadow space (32bit) and take care of alignment
    // We pushed r12, which caused -8bit. To align on 16bit: 32+8=40
    //| sub rsp, 40
    dasm_put(Dst, 212);
#line 263 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Move address of function to register
    //| mov64 rax, (uintptr_t) functionPtr
    dasm_put(Dst, 218, (unsigned int)((uintptr_t) functionPtr), (unsigned int)(((uintptr_t) functionPtr)>>32));
#line 266 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Call function
    //| call rax
    dasm_put(Dst, 223);
#line 269 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Delete shadow space
    //| add rsp, 40
    dasm_put(Dst, 227);
#line 272 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Move original rsp value to r12
    //| pop r12
    dasm_put(Dst, 232);
#line 275 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Restore rsp
    //| mov rsp, r12
    dasm_put(Dst, 235);
#line 278 "compiler/code-gen/assembly/assembly__avx.dasc"


    //Put function result on top of stack
    //| vmovq xmm(stackPos), xmm0
    dasm_put(Dst, 239, (stackPos));
#line 282 "compiler/code-gen/assembly/assembly__avx.dasc"

    //Restore old stack
    for(int i=stackPos-1; i>=0; i--){
        //| vmovq xmm(i), qword [rsp]
        //| add rsp, 8
        dasm_put(Dst, 247, (i));
#line 287 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
}

void Assembly__AVX::extractResult(){
     //| vmovq xmm0, xmm(stackPos)
     dasm_put(Dst, 260, (stackPos));
#line 292 "compiler/code-gen/assembly/assembly__avx.dasc"
}


void Assembly__AVX::epilogue(){
    //| mov rsp, rbp
    //| pop rbp
    //| ret
    dasm_put(Dst, 268);
#line 299 "compiler/code-gen/assembly/assembly__avx.dasc"
}

dasm_gen_func Assembly__AVX::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return (dasm_gen_func) buf;
}

