#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 9.0;

    setenv("IMPALA_FILE","../../tests/impala_files/conditional_gte_true_1.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    printf("Result: %f\n", function(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0));
    return 0;
}