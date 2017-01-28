/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "compiler/code-gen/assembly/assembly.dasc".
*/

#line 1 "compiler/code-gen/assembly/assembly.dasc"
//
// Created by manuel on 06.11.16.
//

#include <assembly.hh>
#include <iostream>


//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 10 "compiler/code-gen/assembly/assembly.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 12 "compiler/code-gen/assembly/assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 13 "compiler/code-gen/assembly/assembly.dasc"
//|.actionlist impala_actions
static const unsigned char impala_actions[299] = {
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
  224,255,222,193,255,222,252,233,255,222,201,255,222,252,249,255,217,252,241,
  217,192,217,252,252,220,225,217,201,217,224,217,252,240,217,232,222,193,217,
  252,253,221,217,255,217,252,250,255,223,252,241,221,216,255,93,195,255
};

#line 14 "compiler/code-gen/assembly/assembly.dasc"

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
#line 45 "compiler/code-gen/assembly/assembly.dasc"

    std::cout << "| push rbp" << std::endl;
    std::cout << "| mov rbp, rsp" << std::endl;
    std::cout << "| mov rax, rbp" << std::endl;
    std::cout << "| sub rax, 16" << std::endl;
}

void Assembly::growPC(unsigned npc)
{
    dasm_growpc(&d, npc);
}

void Assembly::pushConstantToFPUStack(double *value){
    //| fld qword [value]
    dasm_put(Dst, 12, value);
#line 59 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fld " << *value << std::endl;
}

void Assembly::storeLocalVariable() {
    //| fstp qword [rax]
    //| sub rax, 8
    dasm_put(Dst, 17);
#line 65 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fstp qword [rax]" << std::endl;
    std::cout << "| sub rax, 8" << std::endl;
}

void Assembly::pushParameterToFPUStack(int index) {
    switch(index){
        case 0:
            {
                //| movlpd qword [rbp-8], xmm0
                //| fld qword [rbp-8]
                dasm_put(Dst, 24);
#line 75 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| movlpd qword [rbp-8], xmm1
                //| fld qword [rbp-8]
                dasm_put(Dst, 35);
#line 81 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| movlpd qword [rbp-8], xmm2
                //| fld qword [rbp-8]
                dasm_put(Dst, 46);
#line 87 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| movlpd qword [rbp-8], xmm3
                //| fld qword [rbp-8]
                dasm_put(Dst, 57);
#line 93 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| movlpd qword [rbp-8], xmm4
                //| fld qword [rbp-8]
                dasm_put(Dst, 68);
#line 99 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| movlpd qword [rbp-8], xmm5
                //| fld qword [rbp-8]
                dasm_put(Dst, 79);
#line 105 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| movlpd qword [rbp-8], xmm6
                //| fld qword [rbp-8]
                dasm_put(Dst, 90);
#line 111 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| movlpd qword [rbp-8], xmm7
                //| fld qword [rbp-8]
                dasm_put(Dst, 101);
#line 117 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fld qword [rbp+(8+(index-7)*8)]
                dasm_put(Dst, 112, (8+(index-7)*8));
#line 122 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
    }
    std::cout << "| fld qword [rbp+" << (8+(index-7)*8) << "]" << std::endl;
}

void Assembly::replaceParameter(int index) {
    switch(index){
        case 0:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm0, qword [rbp-8]
                dasm_put(Dst, 116);
#line 134 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 1:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm1, qword [rbp-8]
                dasm_put(Dst, 127);
#line 140 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 2:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm2, qword [rbp-8]
                dasm_put(Dst, 138);
#line 146 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 3:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm3, qword [rbp-8]
                dasm_put(Dst, 149);
#line 152 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 4:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm4, qword [rbp-8]
                dasm_put(Dst, 160);
#line 158 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 5:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm5, qword [rbp-8]
                dasm_put(Dst, 171);
#line 164 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 6:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm6, qword [rbp-8]
                dasm_put(Dst, 182);
#line 170 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        case 7:
            {
                //| fstp qword [rbp-8]
                //| movlpd xmm7, qword [rbp-8]
                dasm_put(Dst, 193);
#line 176 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
        default:
            {
                //| fstp qword [rbp+(8+(index-7)*8)]
                dasm_put(Dst, 204, (8+(index-7)*8));
#line 181 "compiler/code-gen/assembly/assembly.dasc"
                break;
            }
    }
    std::cout << "| fstp qword [rbp+" << (8+(index-7)*8) << "]" << std::endl;
}

void Assembly::pushLocalVariableToFPUStack(int index) {
    //| fld qword [rbp-(16+index*8)]
    dasm_put(Dst, 112, -(16+index*8));
#line 189 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fld qword [rbp-" << (16+index*8) << "]" << std::endl;
}

void Assembly::replaceLocalVariable(int index) {
    //| fstp qword [rbp-(16+index*8)]
    dasm_put(Dst, 204, -(16+index*8));
#line 194 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fstp qword [rbp-" << (16+index*8) << "]" << std::endl;
}

void Assembly::addDynamicLabel(unsigned labelNumber) {
    //| =>labelNumber:
    dasm_put(Dst, 208, labelNumber);
#line 199 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| =>" << labelNumber << ":" << std::endl;
}

void Assembly::jumpForwardToDynamicLabel(unsigned labelNumber) {
    //| jmp =>labelNumber
    dasm_put(Dst, 210, labelNumber);
#line 204 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| jmp =>" << labelNumber << std::endl;
}


void Assembly::conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_){
    if(condition == false){
        switch(operator_){
            case EQ:
            {
                //| jne  =>labelNumber
                dasm_put(Dst, 214, labelNumber);
#line 214 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jne  =>" << labelNumber << std::endl;
                break;
            }
            case NE:
            {
                //| je  =>labelNumber
                dasm_put(Dst, 218, labelNumber);
#line 220 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| je  =>" << labelNumber << std::endl;
                break;
            }
            case GT:
            {
                //| jbe  =>labelNumber
                dasm_put(Dst, 222, labelNumber);
#line 226 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jbe  =>" << labelNumber << std::endl;
                break;
            }
            case LT:
            {
                //| jae  =>labelNumber
                dasm_put(Dst, 226, labelNumber);
#line 232 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jae  =>" << labelNumber << std::endl;
                break;
            }
            case GTE:
            {
                //| jb  =>labelNumber
                dasm_put(Dst, 230, labelNumber);
#line 238 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jbe  =>" << labelNumber << std::endl;
                break;
            }
            case LTE:
            {
                //| ja  =>labelNumber
                dasm_put(Dst, 234, labelNumber);
#line 244 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| ja  =>" << labelNumber << std::endl;
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
#line 254 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| je  =>" << labelNumber << std::endl;
                break;
            }
            case NE:
            {
                //| jne  =>labelNumber
                dasm_put(Dst, 214, labelNumber);
#line 260 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jne  =>" << labelNumber << std::endl;
                break;
            }
            case GT:
            {
                //| ja  =>labelNumber
                dasm_put(Dst, 234, labelNumber);
#line 266 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| ja  =>" << labelNumber << std::endl;
                break;
            }
            case LT:
            {
                //| jb  =>labelNumber
                dasm_put(Dst, 230, labelNumber);
#line 272 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jb  =>" << labelNumber << std::endl;
                break;
            }
            case GTE:
            {
                //| jge  =>labelNumber
                dasm_put(Dst, 238, labelNumber);
#line 278 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jge  =>" << labelNumber << std::endl;
                break;
            }
            case LTE:
            {
                //| jbe  =>labelNumber
                dasm_put(Dst, 222, labelNumber);
#line 284 "compiler/code-gen/assembly/assembly.dasc"
                std::cout << "| jbe  =>" << labelNumber << std::endl;
                break;
            }
        }
     }
}

void Assembly::performNegation(){
    //| fchs
    dasm_put(Dst, 242);
#line 293 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fchs" << std::endl;
}

void Assembly::calculateAddition(){
    //| faddp st1
    dasm_put(Dst, 245);
#line 298 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| faddp st1" << std::endl;
}

void Assembly::calculateSubtraction(){
    //| fsubp st1
    dasm_put(Dst, 248);
#line 303 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fsubp st1" << std::endl;
}

void Assembly::calculateMultiplication(){
    //| fmulp st1
    dasm_put(Dst, 252);
#line 308 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fmulp st1" << std::endl;
}

void Assembly::calculateDivision(){
    //| fdivp st1
    dasm_put(Dst, 255);
#line 313 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fdivp st1" << std::endl;
}

void Assembly::calculatePower(){
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
    dasm_put(Dst, 259);
#line 328 "compiler/code-gen/assembly/assembly.dasc"

    std::cout << "| fyl2x" << std::endl;
    std::cout << "| fld st0" << std::endl;
    std::cout << "| frndint" << std::endl;
    std::cout << "| fsubr st1,st0" << std::endl;
    std::cout << "| fxch st1" << std::endl;
    std::cout << "| fchs" << std::endl;
    std::cout << "| f2xm1" << std::endl;
    std::cout << "| fld1" << std::endl;
    std::cout << "| faddp st1,st0" << std::endl;
    std::cout << "| fscale" << std::endl;
    std::cout << "| fstp st1" << std::endl;
}

void Assembly::calculateSQRT(){
    //| fsqrt
    dasm_put(Dst, 286);
#line 344 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fsqrt" << std::endl;
}

void Assembly::performComparison(){
    //| fcomip st1
    //| fpop
    dasm_put(Dst, 290);
#line 350 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| fcomip st1" << std::endl;
    std::cout << "| fpop" << std::endl;
}

void Assembly::extractResult(){
     //| fstp qword [rbp-8]
     //| movlpd xmm0, qword [rbp-8]
     dasm_put(Dst, 116);
#line 357 "compiler/code-gen/assembly/assembly.dasc"
     std::cout << "| fstp qword [rbp-8]" << std::endl;
     std::cout << "| movlpd xmm0, qword [rbp-8]" << std::endl;
}


void Assembly::epilogue(){
    //| pop rbp
    //| ret
    dasm_put(Dst, 296);
#line 365 "compiler/code-gen/assembly/assembly.dasc"
    std::cout << "| pop rbp" << std::endl;
    std::cout << "| ret" << std::endl;
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
