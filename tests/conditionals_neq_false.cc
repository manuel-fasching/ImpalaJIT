#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 0.0;

    setenv("IMPALA_FILE","../../tests/impala_files/conditional_neq_false.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    if((function())==expection)
        return 0;
    return 1;
}