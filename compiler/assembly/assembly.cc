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
static const unsigned char bf_actions[119] = {
  221,4,37,237,255,248,1,255,248,2,255,252,233,244,247,255,252,233,244,248,
  255,15,133,244,247,255,221,28,37,237,102,15,18,4,37,237,195,255,222,193,255,
  222,252,233,255,222,201,255,222,252,249,255,217,224,255,217,252,250,255,223,
  252,241,221,216,15,133,244,247,255,223,252,241,221,216,15,132,244,247,255,
  223,252,241,221,216,15,134,244,247,255,223,252,241,221,216,15,131,244,247,
  255,223,252,241,221,216,15,130,244,247,255,223,252,241,221,216,15,135,244,
  247,255
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
}
void Assembly::addDynamicLabel1(){
    //| 1:
    dasm_put(Dst, 5);
#line 46 "compiler/assembly/assembly.dasc"
}
void Assembly::addDynamicLabel2(){
    //| 2:
    dasm_put(Dst, 8);
#line 49 "compiler/assembly/assembly.dasc"
}
void Assembly::jumpForwardTo1(){
    //| jmp >1
    dasm_put(Dst, 11);
#line 52 "compiler/assembly/assembly.dasc"
}
void Assembly::jumpForwardTo2(){
    //| jmp >2
    dasm_put(Dst, 16);
#line 55 "compiler/assembly/assembly.dasc"
}
void Assembly::conditionalJumpForwardTo1(){
    //| jnz >1
    dasm_put(Dst, 21);
#line 58 "compiler/assembly/assembly.dasc"
}
void Assembly::compile(){

    switch(operator_){
        case IDENTITY:
            {
                double* result = (double*) malloc(sizeof(double));
                //| fstp qword [result]
                //| movlpd xmm0, qword [result]
                //| ret
                dasm_put(Dst, 26, result, result);
#line 68 "compiler/assembly/assembly.dasc"
               break;
           }
        case ADD:
            {
                //| faddp st1
                dasm_put(Dst, 38);
#line 73 "compiler/assembly/assembly.dasc"
                break;
            }
         case SUB:
            {
                //| fsubp st1
                dasm_put(Dst, 41);
#line 78 "compiler/assembly/assembly.dasc"
                break;
            }
         case MUL:
            {
                //| fmulp st1
                dasm_put(Dst, 45);
#line 83 "compiler/assembly/assembly.dasc"
                break;
            }
         case DIV:
            {
                //| fdivp st1
                dasm_put(Dst, 48);
#line 88 "compiler/assembly/assembly.dasc"
                break;
            }
         case NEG:
            {
                //| fchs
                dasm_put(Dst, 52);
#line 93 "compiler/assembly/assembly.dasc"
                break;
            }
         case SQRT:
            {
                //| fsqrt
                dasm_put(Dst, 55);
#line 98 "compiler/assembly/assembly.dasc"
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
                //| jnz >1
                dasm_put(Dst, 59);
#line 110 "compiler/assembly/assembly.dasc"
                break;
            }
          case NE:
            {
                //| fcomip st1
                //| fpop
                //| jz >1
                dasm_put(Dst, 69);
#line 117 "compiler/assembly/assembly.dasc"
                break;
            }
         case GT:
            {
                //| fcomip st1
                //| fpop
                //| jbe >1
                dasm_put(Dst, 79);
#line 124 "compiler/assembly/assembly.dasc"
                break;
            }
         case LT:
            {
                //| fcomip st1
                //| fpop
                //| jae >1
                dasm_put(Dst, 89);
#line 131 "compiler/assembly/assembly.dasc"
                break;
            }
         case GTE:
            {
                //| fcomip st1
                //| fpop
                //| jb >1
                dasm_put(Dst, 99);
#line 138 "compiler/assembly/assembly.dasc"
                break;
            }
         case LTE:
            {
                //| fcomip st1
                //| fpop
                //| ja >1
                dasm_put(Dst, 109);
#line 145 "compiler/assembly/assembly.dasc"
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
