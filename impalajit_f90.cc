//
// Created by manuel on 15.01.17.
//

#include <impalajit_f90.h>
#include <impalajit.hh>

ImpalaJIT_f90 *impalajit_f90_create() {
    return static_cast<ImpalaJIT_f90 *>( new impalajit::Compiler());
}

int impalajit_f90_setVariable(ImpalaJIT_f90 *i, char *name, double value) {
    return static_cast<impalajit::Compiler *>(i)->setVariable(std::string(name), value);
}

void impalajit_f90_clearVariables(ImpalaJIT_f90 *i) {
    static_cast<impalajit::Compiler *>(i)->clearVariables();
}

dasm_gen_func impalajit_f90_compile(ImpalaJIT_f90 *i) {
    return static_cast<impalajit::Compiler *>(i)->compile();
}
