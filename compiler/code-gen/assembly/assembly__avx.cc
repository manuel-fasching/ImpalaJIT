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
#include <math.h>
#include <stdio.h>
#include <stdint.h>



//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 29 "compiler/code-gen/assembly/assembly__avx.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 31 "compiler/code-gen/assembly/assembly__avx.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 33 "compiler/code-gen/assembly/assembly__avx.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[222] = {
  85,72,137,229,255,197,252,250,126,4,240,132,37,237,255,196,225,252,249,214,
  133,253,240,133,233,255,196,225,122,126,192,240,133,240,45,255,197,252,250,
  126,133,253,240,132,233,255,249,255,252,233,245,255,196,225,123,240,160,194,
  192,240,133,240,45,235,196,226,121,14,192,240,133,240,37,255,15,133,245,255,
  15,132,245,255,196,225,122,126,192,240,133,240,45,196,225,123,240,160,92,
  192,240,133,240,45,196,225,123,240,160,92,192,240,133,240,45,255,196,225,
  123,240,160,88,192,240,133,240,45,255,196,225,123,240,160,89,192,240,133,
  240,45,255,196,225,123,240,160,94,192,240,133,240,45,255,197,252,250,126,
  192,240,132,197,252,250,126,193,240,132,255,196,225,122,126,192,240,45,196,
  225,122,126,200,240,45,72,184,237,237,252,255,208,197,252,250,126,192,240,
  132,255,196,225,122,126,200,240,45,196,225,122,126,192,240,45,255,196,225,
  123,81,192,240,133,240,45,255,93,195,255
};

#line 34 "compiler/code-gen/assembly/assembly__avx.dasc"

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
    localVarPos = 0;
}

void Assembly__AVX::prologue(){
    //| push rbp
    //| mov rbp, rsp
    dasm_put(Dst, 0);
#line 65 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly__AVX::pushConstantToStack(double *value){
    stackPos++;
    //| vmovq xmm(stackPos), qword [value]
    dasm_put(Dst, 5, (stackPos), value);
#line 75 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::storeLocalVariable() {
    localVarPos++;
    //| vmovq qword [rbp-8*localVarPos], xmm(stackPos)
    dasm_put(Dst, 15, (stackPos), -8*localVarPos);
#line 80 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::pushParameterToStack(int index) {
    stackPos++;
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| vmovq xmm(stackPos), xmm(index)
        dasm_put(Dst, 26, (stackPos), (index));
#line 87 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
    else {
        //| vmovq xmm(stackPos), qword [rbp+(8+(index-7)*8)]
        dasm_put(Dst, 36, (stackPos), (8+(index-7)*8));
#line 90 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
}

void Assembly__AVX::replaceParameter(int index) {
    // See x64 calling conventions. Paramters 1-8 are passed in registers
    if(index <= 7){
        //| vmovq xmm(index), xmm(stackPos)
        dasm_put(Dst, 26, (index), (stackPos));
#line 97 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
    else {
        //| vmovq qword [rbp+(8+(index-7)*8)], xmm(stackPos)
        dasm_put(Dst, 15, (stackPos), (8+(index-7)*8));
#line 100 "compiler/code-gen/assembly/assembly__avx.dasc"
    }
}

void Assembly__AVX::pushLocalVariableToStack(int index) {
    stackPos++;
    //| vmovq xmm(stackPos), qword [rbp-(8+index*8)]
    dasm_put(Dst, 36, (stackPos), -(8+index*8));
#line 106 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::replaceLocalVariable(int index) {
    //| vmovq qword [rbp-(8+index*8)], xmm(stackPos)
    dasm_put(Dst, 15, (stackPos), -(8+index*8));
#line 110 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 46, labelNumber);
#line 114 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 48, labelNumber);
#line 118 "compiler/code-gen/assembly/assembly__avx.dasc"
}


void Assembly__AVX::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
     //| vcmpsd xmm(stackPos), xmm(stackPos), xmm(stackPos-1), operator_
     //| vptestps xmm(stackPos), xmm(stackPos)
     dasm_put(Dst, 52, (stackPos), (stackPos), (stackPos-1), operator_, (stackPos), (stackPos));
#line 124 "compiler/code-gen/assembly/assembly__avx.dasc"
     if(condition){
         //| jnz => labelNumber
         dasm_put(Dst, 74,  labelNumber);
#line 126 "compiler/code-gen/assembly/assembly__avx.dasc"
     }
     else{
        //| jz => labelNumber
        dasm_put(Dst, 78,  labelNumber);
#line 129 "compiler/code-gen/assembly/assembly__avx.dasc"
     }
     stackPos--;
}

void Assembly__AVX::performNegation(){
    //| vmovq xmm(stackPos+1), xmm(stackPos)
    //| vsubsd xmm(stackPos), xmm(stackPos), xmm(stackPos+1)
    //| vsubsd xmm(stackPos), xmm(stackPos), xmm(stackPos+1)
    dasm_put(Dst, 82, (stackPos+1), (stackPos), (stackPos), (stackPos), (stackPos+1), (stackPos), (stackPos), (stackPos+1));
#line 137 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::calculateAddition(){
    //| vaddsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 114, (stackPos-1), (stackPos-1), (stackPos));
#line 141 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateSubtraction(){
    //| vsubsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 102, (stackPos-1), (stackPos-1), (stackPos));
#line 146 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateMultiplication(){
    //| vmulsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 126, (stackPos-1), (stackPos-1), (stackPos));
#line 151 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateDivision(){
    //| vdivsd xmm(stackPos-1), xmm(stackPos-1), xmm(stackPos)
    dasm_put(Dst, 138, (stackPos-1), (stackPos-1), (stackPos));
#line 156 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculatePower(){
    // Backup xmm0 and xmm1
    //| vmovq	xmm(stackPos+1), xmm0
    //| vmovq	xmm(stackPos+2), xmm1
    dasm_put(Dst, 150, (stackPos+1), (stackPos+2));
#line 163 "compiler/code-gen/assembly/assembly__avx.dasc"

    // Call pow function of c std math lib
    //| vmovq xmm0, xmm(stackPos)
    //| vmovq xmm1, xmm(stackPos-1)
    //| mov64 rax, (uintptr_t) pow
    //| call rax
    //| vmovq xmm(stackPos-1), xmm0
    dasm_put(Dst, 165, (stackPos), (stackPos-1), (unsigned int)((uintptr_t) pow), (unsigned int)(((uintptr_t) pow)>>32), (stackPos-1));
#line 170 "compiler/code-gen/assembly/assembly__avx.dasc"

     // Restore xmm0 and xmm1
    //| vmovq xmm1, xmm(stackPos+1)
    //| vmovq xmm0, xmm(stackPos+2)
    dasm_put(Dst, 194, (stackPos+1), (stackPos+2));
#line 174 "compiler/code-gen/assembly/assembly__avx.dasc"
    stackPos--;
}

void Assembly__AVX::calculateSQRT(){
    //| vsqrtsd xmm(stackPos), xmm(stackPos)
    dasm_put(Dst, 209, (stackPos), (stackPos));
#line 179 "compiler/code-gen/assembly/assembly__avx.dasc"
}

void Assembly__AVX::extractResult(){
     //| vmovq xmm0, xmm(stackPos)
     dasm_put(Dst, 201, (stackPos));
#line 183 "compiler/code-gen/assembly/assembly__avx.dasc"
}


void Assembly__AVX::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 219);
#line 189 "compiler/code-gen/assembly/assembly__avx.dasc"
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

