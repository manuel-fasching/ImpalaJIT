#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <defines.hh>
#include <assert.h>
using namespace std;

int main(int argc, char** argv) {

    ofstream configFile;
    configFile.open(CONFIG_FILE_PATH);
    configFile << "../../tests/impala_files/conditional_lt.impala";
    configFile.close();

    impalajit::Compiler compiler(CONFIG_FILE_PATH);
    dasm_gen_func function = compiler.compile();

    assert(function(1.0, 0.0) == 0.0);
    assert(function(0.0, 1.0) == 1.0);
    assert(function(0.0, 0.0) == 0.0);

    return 0;
}