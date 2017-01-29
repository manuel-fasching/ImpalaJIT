//
// Created by manuel on 28.01.17.
//

#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <defines.hh>
using namespace std;

int main(int argc, char** argv) {

    ofstream configFile;
    configFile.open(CONFIG_FILE_PATH);
    configFile << "../../tests/impala_files/conditional_nested.impala";
    configFile.close();

    impalajit::Compiler compiler(CONFIG_FILE_PATH);
    dasm_gen_func function = compiler.compile();

    assert(function(1.0, 1.0, 1.0, 1.0) == 4.0);
    assert(function(1.0, 1.0, 1.0, 0.0) == 3.0);
    assert(function(1.0, 0.0, 1.0, 1.0) == 2.0);
    assert(function(1.0, 0.0, 1.0, 0.0) == 1.0);
    return 0;
}