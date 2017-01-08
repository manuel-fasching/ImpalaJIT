#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv) {
    double expection = 10.0;

    setenv("IMPALA_FILE","../../tests/impala_files/swe_waterheight.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    compiler.setVariable("x", 50);
    compiler.setVariable("y", 50);

    if((function())==expection)
        return 0;
    return 1;
}