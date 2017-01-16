//
// Created by manuel on 15.01.17.
//

#ifndef IMPALAJIT_IMPALAJIT_F90_H
#define IMPALAJIT_IMPALAJIT_F90_H

#include "impalajit/types.hh"

typedef void ImpalaJIT_f90;

#ifdef __cplusplus
extern "C" {
#endif

    ImpalaJIT_f90 * impalajit_f90_create();

    int impalajit_f90_setVariable(ImpalaJIT_f90* i, char* name, double value);
    void impalajit_f90_clearVariables(ImpalaJIT_f90* i);

    dasm_gen_func impalajit_f90_compile(ImpalaJIT_f90* i);

#ifdef __cplusplus
};
#endif


#endif //IMPALAJIT_IMPALAJIT_F90_H
