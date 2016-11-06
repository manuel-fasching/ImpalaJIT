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
//|.if X64
//|.arch x64
#if DASM_VERSION != 10300
#error "Version mismatch between DynASM and included encoding engine"
#endif
#line 8 "compiler/assembly/assembly.dasc"
//|.else
//|.arch x86
//|.endif

//|.section code
#define DASM_SECTION_CODE	0
#define DASM_MAXSECTION		1
#line 13 "compiler/assembly/assembly.dasc"
//|.globals lbl_
enum {
  lbl__MAX
};
#line 14 "compiler/assembly/assembly.dasc"
//|.actionlist bf_actions
static const unsigned char bf_actions[6] = {
  72,199,192,237,195,255
};

#line 15 "compiler/assembly/assembly.dasc"

dasm_State* d;
void** labels;
dasm_State** Dst;

Assembly::Assembly(){
    dasm_init(&d, DASM_MAXSECTION);

    labels = (void**) malloc(lbl__MAX);
    dasm_setupglobal(&d, labels, lbl__MAX);

    dasm_setup(&d, bf_actions);

    Dst = &d;
}

dasm_State* Assembly::getValue(double *value) {
    //|  mov rax, value
    //|  ret
    dasm_put(Dst, 0, value);
#line 34 "compiler/assembly/assembly.dasc"
    return d;
}

Assembly::~Assembly(){
    dasm_free(&d);
}
