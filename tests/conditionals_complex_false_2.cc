//
// Created by manuel on 07.01.17.
//

#include "impalajit.hh"
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 0.0;

    setenv("IMPALA_FILE","impala_files/conditional_complex_false_2.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    if((function())==expection)
        return 0;
    return 1;
}