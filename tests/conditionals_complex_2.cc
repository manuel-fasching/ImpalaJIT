//
// Created by manuel on 29.01.17.
//

#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <assert.h>

using namespace std;

int main(int argc, char** argv) {

    setenv("IMPALA_FILE","../../tests/impala_files/conditional_complex_2.impala", 1);

    impalajit::Compiler compiler;
    dasm_gen_func function = compiler.compile();

    assert(function(1.0, 1.0, 1.0, 1.0) == 2.0);
    assert(function(1.0, 1.0, 1.0, 0.0) == 2.0);
    assert(function(1.0, 1.0, 0.0, 1.0) == 2.0);
    assert(function(1.0, 1.0, 0.0, 0.0) == 2.0);
    assert(function(1.0, 0.0, 1.0, 1.0) == 2.0);
    assert(function(1.0, 0.0, 1.0, 0.0) == 2.0);
    assert(function(1.0, 0.0, 0.0, 1.0) == 2.0);
    assert(function(1.0, 0.0, 0.0, 0.0) == 2.0);
    assert(function(0.0, 1.0, 1.0, 1.0) == 1.0);
    assert(function(0.0, 1.0, 1.0, 0.0) == 2.0);
    assert(function(0.0, 1.0, 0.0, 1.0) == 1.0);
    assert(function(0.0, 1.0, 0.0, 0.0) == 2.0);
    assert(function(0.0, 0.0, 1.0, 1.0) == 1.0);
    assert(function(0.0, 0.0, 1.0, 0.0) == 2.0);
    assert(function(0.0, 0.0, 0.0, 1.0) == 2.0);
    assert(function(0.0, 0.0, 0.0, 0.0) == 2.0);

    return 0;
}