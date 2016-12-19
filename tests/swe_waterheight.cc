#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 10.0;

    setenv("IMPALA_FILE","impala_files/swe_waterheight.impala", 1);

    impalajit::Compiler compiler;
    double* buf_x = (double*) malloc(sizeof(double));
    double* buf_y = (double*) malloc(sizeof(double));
    *buf_x=50.0;
    *buf_y=50.0;

    compiler.setVariable("x", buf_x);
    compiler.setVariable("y", buf_y);

    dasm_gen_func function = compiler.compile();

    if((function())==expection)
        return 0;
    return 1;
}