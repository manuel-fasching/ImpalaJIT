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
static const unsigned char bf_actions[109] = {
  102,15,18,4,37,237,195,255,102,15,18,4,37,237,252,242,15,88,4,37,237,102,
  15,19,4,37,237,255,102,15,18,4,37,237,252,242,15,92,4,37,237,102,15,19,4,
  37,237,255,102,15,18,4,37,237,252,242,15,89,4,37,237,102,15,19,4,37,237,255,
  102,15,18,4,37,237,252,242,15,94,4,37,237,102,15,19,4,37,237,255,72,184,237,
  237,102,72,15,110,200,102,15,252,239,193,102,15,19,4,37,237,255
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
std::stack<double*> operandStack;
int operator_;

Assembly::Assembly(){
    dasm_init(&d, DASM_MAXSECTION);

    labels = (void**) malloc(lbl__MAX);
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, bf_actions);

    Dst = &d;
}

void Assembly::compile(){

    switch(operator_){
        case IDENTITY:
            {
                double* value = operandStack.top();
                operandStack.pop();
                //|  movlpd xmm0, qword [value]
                //|  ret
                dasm_put(Dst, 0, value);
#line 51 "assembly.dasc"

               break;
           }
        case ADD:
            {
                double* value1 = operandStack.top();
                operandStack.pop();
                double* value2 = operandStack.top();
                operandStack.pop();
                double* result = (double*) malloc(sizeof(double));

                //| movlpd xmm0, qword [value1]
                //| addsd xmm0, qword [value2]
                //| movlpd qword [result], xmm0
                dasm_put(Dst, 8, value1, value2, result);
#line 65 "assembly.dasc"

                operandStack.push(result);

                break;
            }
         case SUB:
            {
                double* value1 = operandStack.top();
                operandStack.pop();
                double* value2 = operandStack.top();
                operandStack.pop();
                double* result = (double*) malloc(sizeof(double));

                //| movlpd xmm0, qword [value2]
                //| subsd xmm0, qword [value1]
                //| movlpd qword [result], xmm0
                dasm_put(Dst, 28, value2, value1, result);
#line 81 "assembly.dasc"

                operandStack.push(result);

                break;
            }
         case MUL:
            {
                double* value1 = operandStack.top();
                operandStack.pop();
                double* value2 = operandStack.top();
                operandStack.pop();
                double* result = (double*) malloc(sizeof(double));

                //| movlpd xmm0, qword [value2]
                //| mulsd xmm0, qword [value1]
                //| movlpd qword [result], xmm0
                dasm_put(Dst, 48, value2, value1, result);
#line 97 "assembly.dasc"

                operandStack.push(result);

                break;
            }
         case DIV:
            {
                double* value1 = operandStack.top();
                operandStack.pop();
                double* value2 = operandStack.top();
                operandStack.pop();
                double* result = (double*) malloc(sizeof(double));

                //| movlpd xmm0, qword [value2]
                //| divsd xmm0, qword [value1]
                //| movlpd qword [result], xmm0
                dasm_put(Dst, 68, value2, value1, result);
#line 113 "assembly.dasc"

                operandStack.push(result);

                break;
            }
         case NEG:
            {
                double* value = operandStack.top();
                operandStack.pop();
                double* result = (double*) malloc(sizeof(double));
                //| mov64 rax, 0x8000000000000000
                //| movd xmm1, rax
                //| pxor xmm0, xmm1
                //| movlpd qword [result], xmm0
                dasm_put(Dst, 88, (unsigned int)(0x8000000000000000), (unsigned int)((0x8000000000000000)>>32), result);
#line 127 "assembly.dasc"

                operandStack.push(result);

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
