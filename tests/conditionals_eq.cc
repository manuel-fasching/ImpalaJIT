#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <defines.hh>

using namespace std;

int main(int argc, char** argv) {

    ofstream configFile;
    configFile.open(CONFIG_FILE_PATH);
    configFile << "../../tests/impala_files/conditional_eq.impala";
    configFile.close();

    impalajit::Compiler compiler(CONFIG_FILE_PATH);
    compiler.compile();
    dasm_gen_func function = compiler.getFunction("eq");

    assert(function(1.0,1.0) == 1.0);
    assert(function(1.0,0.0) == 0.0);

    return 0;
}