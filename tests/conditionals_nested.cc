//
// Created by manuel on 28.01.17.
//

#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main(int argc, char** argv) {

    setenv("IMPALA_FILE","../../tests/impala_files/conditional_nested.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    assert(function(1.0, 1.0, 1.0, 1.0) == 4.0);
    assert(function(1.0, 1.0, 1.0, 0.0) == 3.0);
    assert(function(1.0, 0.0, 1.0, 1.0) == 2.0);
    assert(function(1.0, 0.0, 1.0, 0.0) == 1.0);
    return 0;
}