/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
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


//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 27 "compiler/code-gen/assembly/assembly.dasc"

//|.section code, imports
#define DASM_SECTION_CODE	0
#define DASM_SECTION_IMPORTS	1
#define DASM_MAXSECTION		2
#line 29 "compiler/code-gen/assembly/assembly.dasc"

//|.globals lbl_
enum {
  lbl__MAX
};
#line 31 "compiler/code-gen/assembly/assembly.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[358] = {
  85,72,137,229,72,137,232,72,131,232,16,255,221,4,37,237,255,221,24,72,131,
  232,8,255,102,15,19,69,252,248,221,69,252,248,255,102,15,19,77,252,248,221,
  69,252,248,255,102,15,19,85,252,248,221,69,252,248,255,102,15,19,93,252,248,
  221,69,252,248,255,102,15,19,101,252,248,221,69,252,248,255,102,15,19,109,
  252,248,221,69,252,248,255,102,15,19,117,252,248,221,69,252,248,255,102,15,
  19,125,252,248,221,69,252,248,255,221,133,233,255,221,93,252,248,102,15,18,
  69,252,248,255,221,93,252,248,102,15,18,77,252,248,255,221,93,252,248,102,
  15,18,85,252,248,255,221,93,252,248,102,15,18,93,252,248,255,221,93,252,248,
  102,15,18,101,252,248,255,221,93,252,248,102,15,18,109,252,248,255,221,93,
  252,248,102,15,18,117,252,248,255,221,93,252,248,102,15,18,125,252,248,255,
  221,157,233,255,249,255,252,233,245,255,15,133,245,255,15,132,245,255,15,
  134,245,255,15,131,245,255,15,130,245,255,15,135,245,255,15,141,245,255,217,
  224,255,222,193,255,222,252,233,255,222,201,255,222,252,249,255,217,193,217,
  228,155,223,224,158,15,132,244,247,255,217,228,155,223,224,158,15,132,244,
  248,255,217,252,241,217,192,217,252,252,220,225,217,201,217,224,217,252,240,
  217,232,222,193,217,252,253,221,217,252,233,244,249,255,248,1,221,216,221,
  216,221,216,217,232,252,233,244,249,255,248,2,221,216,221,216,217,232,217,
  232,216,225,255,248,3,255,217,252,250,255,223,252,241,221,216,255,93,195,
  255
};

#line 32 "compiler/code-gen/assembly/assembly.dasc"


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
#line 74 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly::pushConstantToFPUStack(double *value){
    //| fld qword [value]
    dasm_put(Dst, 12, value);
#line 83 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::storeLocalVariable() {
    //| fstp qword [rax]
    //| sub rax, 8
    dasm_put(Dst, 17);
#line 88 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::pushParameterToFPUStack(int index) {
    switch(index){
        case 0:
            {
                //| movlpd qword [rbp-8], xmm0
                //| fld qword [rbp-8]
                dasm_put(Dst, 24);
#line 96 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| movlpd qword [rbp-8], xmm1
                //| fld qword [rbp-8]
                dasm_put(Dst, 35);
#line 102 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| movlpd qword [rbp-8], xmm2
                //| fld qword [rbp-8]
                dasm_put(Dst, 46);
#line 108 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| movlpd qword [rbp-8], xmm3
                //| fld qword [rbp-8]
                dasm_put(Dst, 57);
#line 114 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| movlpd qword [rbp-8], xmm4
                //| fld qword [rbp-8]
                dasm_put(Dst, 68);
#line 120 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| movlpd qword [rbp-8], xmm5
                //| fld qword [rbp-8]
                dasm_put(Dst, 79);
#line 126 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| movlpd qword [rbp-8], xmm6
                //| fld qword [rbp-8]
                dasm_put(Dst, 90);
#line 132 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| movlpd qword [rbp-8], xmm7
                //| fld qword [rbp-8]
                dasm_put(Dst, 101);
#line 138 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fld qword [rbp+(8+(index-7)*8)]
                dasm_put(Dst, 112, (8+(index-7)*8));
#line 143 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
    }
}

void Assembly::replaceParameter(int index) {
    switch(index){
        case 0:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm0, qword [rbp-8]
                dasm_put(Dst, 116);
#line 154 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm1, qword [rbp-8]
                dasm_put(Dst, 127);
#line 160 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm2, qword [rbp-8]
                dasm_put(Dst, 138);
#line 166 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm3, qword [rbp-8]
                dasm_put(Dst, 149);
#line 172 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm4, qword [rbp-8]
                dasm_put(Dst, 160);
#line 178 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm5, qword [rbp-8]
                dasm_put(Dst, 171);
#line 184 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm6, qword [rbp-8]
                dasm_put(Dst, 182);
#line 190 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm7, qword [rbp-8]
                dasm_put(Dst, 193);
#line 196 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fstp qword [rbp+(8+(index-7)*8)]
                dasm_put(Dst, 204, (8+(index-7)*8));
#line 201 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
    }
}

void Assembly::pushLocalVariableToFPUStack(int index) {
    //| fld qword [rbp-(16+index*8)]
    dasm_put(Dst, 112, -(16+index*8));
#line 208 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::replaceLocalVariable(int index) {
    //| fstp qword [rbp-(16+index*8)]
    dasm_put(Dst, 204, -(16+index*8));
#line 212 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 208, labelNumber);
#line 216 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 210, labelNumber);
#line 220 "compiler/code-gen/assembly/assembly.dasc"
}


void Assembly::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
    if(condition == false){
        switch(operator_){
            case EQ:
            {
                //| jne  =>labelNumber
                dasm_put(Dst, 214, labelNumber);
#line 229 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case NE:
            {
                //| je  =>labelNumber
                dasm_put(Dst, 218, labelNumber);
#line 234 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GT:
            {
                //| jbe  =>labelNumber
                dasm_put(Dst, 222, labelNumber);
#line 239 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LT:
            {
                //| jae  =>labelNumber
                dasm_put(Dst, 226, labelNumber);
#line 244 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GTE:
            {
                //| jb  =>labelNumber
                dasm_put(Dst, 230, labelNumber);
#line 249 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LTE:
            {
                //| ja  =>labelNumber
                dasm_put(Dst, 234, labelNumber);
#line 254 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        }
    }
    else{
        switch(operator_){
            case EQ:
            {
                //| je  =>labelNumber
                dasm_put(Dst, 218, labelNumber);
#line 263 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case NE:
            {
                //| jne  =>labelNumber
                dasm_put(Dst, 214, labelNumber);
#line 268 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GT:
            {
                //| ja  =>labelNumber
                dasm_put(Dst, 234, labelNumber);
#line 273 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LT:
            {
                //| jb  =>labelNumber
                dasm_put(Dst, 230, labelNumber);
#line 278 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case GTE:
            {
                //| jge  =>labelNumber
                dasm_put(Dst, 238, labelNumber);
#line 283 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
            case LTE:
            {
                //| jbe  =>labelNumber
                dasm_put(Dst, 222, labelNumber);
#line 288 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        }
     }
}

void Assembly::performNegation(){
    //| fchs
    dasm_put(Dst, 242);
#line 296 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateAddition(){
    //| faddp st1
    dasm_put(Dst, 245);
#line 300 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateSubtraction(){
    //| fsubp st1
    dasm_put(Dst, 248);
#line 304 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateMultiplication(){
    //| fmulp st1
    dasm_put(Dst, 252);
#line 308 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateDivision(){
    //| fdivp st1
    dasm_put(Dst, 255);
#line 312 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculatePower(){
    //| fld st1
    //| ftst
    //| fstsw ax
    //| sahf
    //| jz >1
    dasm_put(Dst, 259);
#line 320 "compiler/code-gen/assembly/assembly.dasc"

    //| ftst
    //| fstsw ax
    //| sahf
    //| jz >2
    dasm_put(Dst, 272);
#line 325 "compiler/code-gen/assembly/assembly.dasc"

    //| fyl2x
    //| fld st0
    //| frndint
    //| fsubr st1,st0
    //| fxch st1
    //| fchs
    //| f2xm1
    //| fld1
    //| faddp st1,st0
    //| fscale
    //| fstp st1
    //| jmp >3
    dasm_put(Dst, 283);
#line 338 "compiler/code-gen/assembly/assembly.dasc"

    //| 1:
    //| fpop
    //| fpop
    //| fpop
    //| fld1
    //| jmp >3
    dasm_put(Dst, 314);
#line 345 "compiler/code-gen/assembly/assembly.dasc"

    //| 2:
    //| fpop
    //| fpop
    //| fld1
    //| fld1
    //| fsub st1
    dasm_put(Dst, 329);
#line 352 "compiler/code-gen/assembly/assembly.dasc"

    //| 3:
    dasm_put(Dst, 342);
#line 354 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::calculateSQRT(){
    //| fsqrt
    dasm_put(Dst, 345);
#line 358 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::performComparison(){
    //| fcomip st1
    //| fpop
    dasm_put(Dst, 349);
#line 363 "compiler/code-gen/assembly/assembly.dasc"
}

void Assembly::extractResult(){
     //| fstp qword [rbp-8]
     //| movlpd xmm0, qword [rbp-8]
     dasm_put(Dst, 116);
#line 368 "compiler/code-gen/assembly/assembly.dasc"
}


void Assembly::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 355);
#line 374 "compiler/code-gen/assembly/assembly.dasc"
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

