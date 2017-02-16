/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.4.0, DynASM x64 version 1.4.0
** DO NOT EDIT! The original file is in "compiler/code-gen/assembly/assembly.dasc".
*/

#line 1 "compiler/code-gen/assembly/assembly.dasc"
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

#include <assembly.hh>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdint.h>



//|.arch x64
#if DASM_VERSION != 10400
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 29 "compiler/code-gen/assembly/assembly.dasc"

//|.section code, imports
#define DASM_SECTION_CODE	0
#define DASM_SECTION_IMPORTS	1
#define DASM_MAXSECTION		2
#line 31 "compiler/code-gen/assembly/assembly.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 33 "compiler/code-gen/assembly/assembly.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[358] = {
  85,72,137,229,72,137,232,72,131,232,16,255,221,4,37,237,255,221,24,72,131,
  232,8,255,196,225,252,249,19,69,252,248,221,69,252,248,255,196,225,252,249,
  19,77,252,248,221,69,252,248,255,196,225,252,249,19,85,252,248,221,69,252,
  248,255,196,225,252,249,19,93,252,248,221,69,252,248,255,196,225,252,249,
  19,101,252,248,221,69,252,248,255,196,225,252,249,19,109,252,248,221,69,252,
  248,255,196,225,252,249,19,117,252,248,221,69,252,248,255,196,225,252,249,
  19,125,252,248,221,69,252,248,255,221,133,233,255,221,93,252,248,197,252,
  250,126,69,252,248,255,221,93,252,248,197,252,250,126,77,252,248,255,221,
  93,252,248,197,252,250,126,85,252,248,255,221,93,252,248,197,252,250,126,
  93,252,248,255,221,93,252,248,197,252,250,126,101,252,248,255,221,93,252,
  248,197,252,250,126,109,252,248,255,221,93,252,248,197,252,250,126,117,252,
  248,255,221,93,252,248,197,252,250,126,125,252,248,255,221,157,233,255,249,
  255,252,233,245,255,15,133,245,255,15,132,245,255,15,134,245,255,15,131,245,
  255,15,130,245,255,15,135,245,255,15,141,245,255,217,224,255,222,193,255,
  222,252,233,255,222,201,255,222,252,249,255,197,122,126,192,197,122,126,201,
  255,221,93,252,248,197,252,250,126,69,252,248,221,93,252,248,197,252,250,
  126,77,252,248,72,184,237,237,252,255,208,196,225,252,249,214,69,252,248,
  221,69,252,248,255,196,193,122,126,201,196,193,122,126,192,255,217,252,250,
  255,223,252,241,221,216,255,93,195,255
};

#line 34 "compiler/code-gen/assembly/assembly.dasc"


//|.macro call_extern, target
//|  .imports
//|  ->__imp__..target:
//|  .dword  (uint32_t)target
//|  .dword ((uint64_t)target >> 32)
//|  .code
//|  call qword [->__imp__..target]
//|.endmacro


#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif

Assembly::~Assembly()
{
    dasm_free(&d);
}

void Assembly::initialize() {
    dasm_init(&d, DASM_MAXSECTION);

    void* labels[lbl__MAX];
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, impala_actions);

    dasm_growpc(&d, 0);

    Dst = &d;
}

void Assembly::prologue(){

    //| push rbp
    //| mov rbp, rsp
    //| mov rax, rbp
    //| sub rax, 16
    dasm_put(Dst, 0);
#line 76 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly::pushConstantToFPUStack(double *value){
    //| fld qword [value]
    dasm_put(Dst, 12, value);
#line 85 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::storeLocalVariable() {
    //| fstp qword [rax]
    //| sub rax, 8
    dasm_put(Dst, 17);
#line 90 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::pushParameterToFPUStack(int index) {
    switch(index){
        case 0:
            {
                //| vmovlpd qword [rbp-8], xmm0
                //| fld qword [rbp-8]
                dasm_put(Dst, 24);
#line 98 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| vmovlpd qword [rbp-8], xmm1
                //| fld qword [rbp-8]
                dasm_put(Dst, 37);
#line 104 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| vmovlpd qword [rbp-8], xmm2
                //| fld qword [rbp-8]
                dasm_put(Dst, 50);
#line 110 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| vmovlpd qword [rbp-8], xmm3
                //| fld qword [rbp-8]
                dasm_put(Dst, 63);
#line 116 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| vmovlpd qword [rbp-8], xmm4
                //| fld qword [rbp-8]
                dasm_put(Dst, 76);
#line 122 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| vmovlpd qword [rbp-8], xmm5
                //| fld qword [rbp-8]
                dasm_put(Dst, 89);
#line 128 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| vmovlpd qword [rbp-8], xmm6
                //| fld qword [rbp-8]
                dasm_put(Dst, 102);
#line 134 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| vmovlpd qword [rbp-8], xmm7
                //| fld qword [rbp-8]
                dasm_put(Dst, 115);
#line 140 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fld qword [rbp+(8+(index-7)*8)]
                dasm_put(Dst, 128, (8+(index-7)*8));
#line 145 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
    }
}

void Assembly::replaceParameter(int index) {
    switch(index){
        case 0:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm0, qword [rbp-8]
                dasm_put(Dst, 132);
#line 156 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm1, qword [rbp-8]
                dasm_put(Dst, 144);
#line 162 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm2, qword [rbp-8]
                dasm_put(Dst, 156);
#line 168 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm3, qword [rbp-8]
                dasm_put(Dst, 168);
#line 174 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm4, qword [rbp-8]
                dasm_put(Dst, 180);
#line 180 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm5, qword [rbp-8]
                dasm_put(Dst, 192);
#line 186 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm6, qword [rbp-8]
                dasm_put(Dst, 204);
#line 192 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| fstp qword [rbp-8]
                //| vmovq xmm7, qword [rbp-8]
                dasm_put(Dst, 216);
#line 198 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fstp qword [rbp+(8+(index-7)*8)]
                dasm_put(Dst, 228, (8+(index-7)*8));
#line 203 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
    }
}

void Assembly::pushLocalVariableToFPUStack(int index) {
    //| fld qword [rbp-(16+index*8)]
    dasm_put(Dst, 128, -(16+index*8));
#line 210 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::replaceLocalVariable(int index) {
    //| fstp qword [rbp-(16+index*8)]
    dasm_put(Dst, 228, -(16+index*8));
#line 214 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 232, labelNumber);
#line 218 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 234, labelNumber);
#line 222 "compiler/code-gen/assembly/assembly.dasc"
}


void Assembly::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
    if(condition == false){
        switch(operator_){
            case EQ:
            {
                //| jne  =>labelNumber
                dasm_put(Dst, 238, labelNumber);
#line 231 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case NE:
            {
                //| je  =>labelNumber
                dasm_put(Dst, 242, labelNumber);
#line 236 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GT:
            {
                //| jbe  =>labelNumber
                dasm_put(Dst, 246, labelNumber);
#line 241 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LT:
            {
                //| jae  =>labelNumber
                dasm_put(Dst, 250, labelNumber);
#line 246 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GTE:
            {
                //| jb  =>labelNumber
                dasm_put(Dst, 254, labelNumber);
#line 251 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LTE:
            {
                //| ja  =>labelNumber
                dasm_put(Dst, 258, labelNumber);
#line 256 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        }
    }
    else{
        switch(operator_){
            case EQ:
            {
                //| je  =>labelNumber
                dasm_put(Dst, 242, labelNumber);
#line 265 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case NE:
            {
                //| jne  =>labelNumber
                dasm_put(Dst, 238, labelNumber);
#line 270 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GT:
            {
                //| ja  =>labelNumber
                dasm_put(Dst, 258, labelNumber);
#line 275 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LT:
            {
                //| jb  =>labelNumber
                dasm_put(Dst, 254, labelNumber);
#line 280 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GTE:
            {
                //| jge  =>labelNumber
                dasm_put(Dst, 262, labelNumber);
#line 285 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LTE:
            {
                //| jbe  =>labelNumber
                dasm_put(Dst, 246, labelNumber);
#line 290 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        }
     }
}

void Assembly::performNegation(){
    //| fchs
    dasm_put(Dst, 266);
#line 298 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateAddition(){
    //| faddp st1
    dasm_put(Dst, 269);
#line 302 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateSubtraction(){
    //| fsubp st1
    dasm_put(Dst, 272);
#line 306 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateMultiplication(){
    //| fmulp st1
    dasm_put(Dst, 276);
#line 310 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateDivision(){
    //| fdivp st1
    dasm_put(Dst, 279);
#line 314 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculatePower(){
    // Backup xmm0 and xmm1.
    //| vmovq	xmm8, xmm0
    //| vmovq	xmm9, xmm1
    dasm_put(Dst, 283);
#line 320 "compiler/code-gen/assembly/assembly.dasc"

    // Call pow function of c std math lib
    //| fstp qword [rbp-8]
    //| vmovq xmm0, qword [rbp-8]
    //| fstp qword [rbp-8]
    //| vmovq xmm1, qword [rbp-8]
    //| mov64 rax, (uintptr_t) pow
    //| call rax
    //| vmovq qword [rbp-8], xmm0
    //| fld qword [rbp-8]
    dasm_put(Dst, 292, (unsigned int)((uintptr_t) pow), (unsigned int)(((uintptr_t) pow)>>32));
#line 330 "compiler/code-gen/assembly/assembly.dasc"

     // Restore xmm0 and xmm1
    //| vmovq xmm1, xmm9
    //| vmovq xmm0, xmm8
    dasm_put(Dst, 334);
#line 334 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateSQRT(){
    //| fsqrt
    dasm_put(Dst, 345);
#line 338 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::performComparison(){
    //| fcomip st1
    //| fpop
    dasm_put(Dst, 349);
#line 343 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::extractResult(){
     //| fstp qword [rbp-8]
     //| vmovq xmm0, qword [rbp-8]
     dasm_put(Dst, 132);
#line 348 "compiler/code-gen/assembly/assembly.dasc"
}


void Assembly::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 355);
#line 354 "compiler/code-gen/assembly/assembly.dasc"
}

dasm_gen_func Assembly::linkAndEncode(){
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return (dasm_gen_func) buf;
}

