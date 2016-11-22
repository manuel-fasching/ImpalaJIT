/*
** This file has been pre-processed with DynASM.
** http://luajit.org/dynasm.html
** DynASM version 1.3.0, DynASM x64 version 1.3.0
** DO NOT EDIT! The original file is in "assembly.dasc".
*/

#line 1 "assembly.dasc"
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
#line 10 "assembly.dasc"

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 12 "assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 13 "assembly.dasc"
//|.actionlist bf_actions
static const unsigned char bf_actions[38] = {
  221,4,37,237,255,221,28,37,237,102,15,18,4,37,237,195,255,222,193,255,222,
  252,233,255,216,201,255,222,252,249,255,217,224,255,217,252,250,255
};

#line 14 "assembly.dasc"

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
#line 43 "assembly.dasc"
}
void Assembly::compile(){

    switch(operator_){
        case IDENTITY:
            {
                double* result = (double*) malloc(sizeof(double));
                //| fstp qword [result]
                //| movlpd xmm0, qword [result]
                //| ret
                dasm_put(Dst, 5, result, result);
#line 53 "assembly.dasc"
               break;
           }
        case ADD:
            {
                //| faddp st1
                dasm_put(Dst, 17);
#line 58 "assembly.dasc"
                break;
            }
         case SUB:
            {
                //| fsubp st1
                dasm_put(Dst, 20);
#line 63 "assembly.dasc"
                break;
            }
         case MUL:
            {
                //| fmul st1
                dasm_put(Dst, 24);
#line 68 "assembly.dasc"
                break;
            }
         case DIV:
            {
                //| fdivp st1
                dasm_put(Dst, 27);
#line 73 "assembly.dasc"
                break;
            }
         case NEG:
            {
                //| fchs
                dasm_put(Dst, 31);
#line 78 "assembly.dasc"
                break;
            }
         case SQRT:
            {
                //| fsqrt
                dasm_put(Dst, 34);
#line 83 "assembly.dasc"
                break;
            }
         case POW:
            {
                printf("^: Operation not supported");
                exit(0);
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
