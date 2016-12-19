/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "compiler/assembly/assembly.dasc".
*/

#line 1 "compiler/assembly/assembly.dasc"
//
// Created by manuel on 06.11.16.
//

#include <assembly.hh>
#include <stack>
#include <stdio.h>

//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 10 "compiler/assembly/assembly.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 12 "compiler/assembly/assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 13 "compiler/assembly/assembly.dasc"
//|.actionlist bf_actions
static const unsigned char bf_actions[128] = {
  221,4,37,237,255,248,1,255,248,2,255,248,3,255,252,233,244,247,255,252,233,
  244,248,255,252,233,244,249,255,15,133,244,248,255,15,132,244,248,255,15,
  134,244,248,255,15,131,244,248,255,15,130,244,248,255,15,135,244,248,255,
  15,132,244,247,255,15,133,244,247,255,15,135,244,247,255,15,130,244,247,255,
  15,141,244,247,255,15,134,244,247,255,221,28,37,237,102,15,18,4,37,237,195,
  255,222,193,255,222,252,233,255,222,201,255,222,252,249,255,217,224,255,217,
  252,250,255,223,252,241,221,216,255
};

#line 14 "compiler/assembly/assembly.dasc"

#if _WIN32
#include <Windows.h>
#else
#include <sys/mman.h>
#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif
#endif


dasm_State* d;
void** labels;
dasm_State** Dst;
int operator_;

Assembly::Assembly(){
    dasm_init(&d, DASM_MAXSECTION);

    labels = (void**) malloc(lbl__MAX);
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, bf_actions);

    Dst = &d;
}

void Assembly::push(double* value){
    //| fld qword [value]
    dasm_put(Dst, 0, value);
#line 43 "compiler/assembly/assembly.dasc"
    printf("fld qword [%f] \n", *value);
}
void Assembly::addDynamicLabel1(){
    //| 1:
    dasm_put(Dst, 5);
#line 47 "compiler/assembly/assembly.dasc"
    printf("1: \n");
}
void Assembly::addDynamicLabel2(){
    //| 2:
    dasm_put(Dst, 8);
#line 51 "compiler/assembly/assembly.dasc"
    printf("2: \n");
}
void Assembly::addDynamicLabel3(){
    //| 3:
    dasm_put(Dst, 11);
#line 55 "compiler/assembly/assembly.dasc"
    printf("3: \n");
}
void Assembly::jumpForwardTo1(){
    //| jmp >1
    dasm_put(Dst, 14);
#line 59 "compiler/assembly/assembly.dasc"
    printf("jmp >1 \n");
}
void Assembly::jumpForwardTo2(){
    //| jmp >2
    dasm_put(Dst, 19);
#line 63 "compiler/assembly/assembly.dasc"
    printf("jmp >2 \n");
}
void Assembly::jumpForwardTo3(){
    //| jmp >3
    dasm_put(Dst, 24);
#line 67 "compiler/assembly/assembly.dasc"
    printf("jmp >3 \n");
}

void Assembly::conditionalJumpForwardTo2IfFalse(){
    switch(operator_){
          case EQ:
            {
                //| jne >2
                dasm_put(Dst, 29);
#line 75 "compiler/assembly/assembly.dasc"
                printf("jne >2 \n");
                break;
            }
          case NE:
            {
                //| je >2
                dasm_put(Dst, 34);
#line 81 "compiler/assembly/assembly.dasc"
                printf("je >2 \n");
                break;
            }
         case GT:
            {
                //| jbe >2
                dasm_put(Dst, 39);
#line 87 "compiler/assembly/assembly.dasc"
                printf("jbe >2 \n");
                break;
            }
         case LT:
            {
                //| jae >2
                dasm_put(Dst, 44);
#line 93 "compiler/assembly/assembly.dasc"
                printf("jae >2 \n");
                break;
            }
         case GTE:
            {
                //| jb >2
                dasm_put(Dst, 49);
#line 99 "compiler/assembly/assembly.dasc"
                printf("jb >2 \n");
                break;
            }
         case LTE:
            {
                //| ja >2
                dasm_put(Dst, 54);
#line 105 "compiler/assembly/assembly.dasc"
                printf("ja >2 \n");
                break;
            }
    }
}


void Assembly::conditionalJumpForwardTo1IfTrue(){
    switch(operator_){
          case EQ:
            {
                //| je >1
                dasm_put(Dst, 59);
#line 117 "compiler/assembly/assembly.dasc"
                printf("je >1 \n");
                break;
            }
          case NE:
            {
                //| jne >1
                dasm_put(Dst, 64);
#line 123 "compiler/assembly/assembly.dasc"
                printf("jne >1 \n");
                break;
            }
         case GT:
            {
                //| ja >1
                dasm_put(Dst, 69);
#line 129 "compiler/assembly/assembly.dasc"
                printf("ja >1 \n");
                break;
            }
         case LT:
            {
                //| jb >1
                dasm_put(Dst, 74);
#line 135 "compiler/assembly/assembly.dasc"
                printf("jb >1 \n");
                break;
            }
         case GTE:
            {
                //| jge >1
                dasm_put(Dst, 79);
#line 141 "compiler/assembly/assembly.dasc"
                printf("jge >1 \n");
                break;
            }
         case LTE:
            {
                //| jbe >1
                dasm_put(Dst, 84);
#line 147 "compiler/assembly/assembly.dasc"
                printf("jbe >1 \n");
                break;
            }
    }
}



void Assembly::compile(){

    switch(operator_){
        case IDENTITY:
            {
                double* result = (double*) malloc(sizeof(double));
                //| fstp qword [result]
                //| movlpd xmm0, qword [result]
                //| ret
                dasm_put(Dst, 89, result, result);
#line 164 "compiler/assembly/assembly.dasc"
                printf("fstp qword %f \n", *result);
                printf("movlpd xmm0, qword [%f] \n", *result);
                printf("ret \n");
               break;
           }
        case ADD:
            {
                //| faddp st1
                dasm_put(Dst, 101);
#line 172 "compiler/assembly/assembly.dasc"
                printf("faddp st1 \n");
                break;
            }
         case SUB:
            {
                //| fsubp st1
                dasm_put(Dst, 104);
#line 178 "compiler/assembly/assembly.dasc"
                printf("fsubp st1 \n");
                break;
            }
         case MUL:
            {
                //| fmulp st1
                dasm_put(Dst, 108);
#line 184 "compiler/assembly/assembly.dasc"
                printf("fmulp st1 \n");
                break;
            }
         case DIV:
            {
                //| fdivp st1
                dasm_put(Dst, 111);
#line 190 "compiler/assembly/assembly.dasc"
                printf("fdivp st1 \n");
                break;
            }
         case NEG:
            {
                //| fchs
                dasm_put(Dst, 115);
#line 196 "compiler/assembly/assembly.dasc"
                printf("fchs \n");
                break;
            }
         case SQRT:
            {
                //| fsqrt
                dasm_put(Dst, 118);
#line 202 "compiler/assembly/assembly.dasc"
                printf("fsqrt \n");
                break;
            }
         case POW:
            {
                printf("^: Operation not supported yet");
                exit(0);
            }
         case EQ:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 122);
#line 214 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case NE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 122);
#line 222 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case GT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 122);
#line 230 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case LT:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 122);
#line 238 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case GTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 122);
#line 246 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
          case LTE:
            {
                //| fcomip st1
                //| fpop
                dasm_put(Dst, 122);
#line 254 "compiler/assembly/assembly.dasc"
                printf("fcomip st1 \n");
                printf("fpop \n");
                break;
            }
    }

    operator_ = EMPTY;
}

Assembly::~Assembly(){
    dasm_free(&d);
}


void* Assembly::linkAndEncode(){
  operator_ = IDENTITY;
  compile();
  size_t sz;
  void* buf;
  dasm_link(Dst, &sz);
  buf = mmap(0, sz, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  dasm_encode(Dst, buf);
  mprotect(buf, sz, PROT_READ | PROT_EXEC);
  return buf;
}
