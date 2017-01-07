#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 1.0;

    setenv("IMPALA_FILE","impala_files/conditional_gte_true_1.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    printf("Result: %f\n", function());
    if((function())==expection)
        return 0;
    return 1;
}