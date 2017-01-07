//
// Created by manuel on 07.01.17.
//

#include "impalajit.hh"
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 1.0;

    setenv("IMPALA_FILE","impala_files/conditional_complex_true_4.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    if((function())==expection)
        return 0;
    return 1;
}