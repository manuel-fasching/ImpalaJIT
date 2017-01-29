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
    configFile << "../../tests/impala_files/conditional_eq.impala\n";
    configFile << "../../tests/impala_files/conditional_gt.impala\n";
    configFile << "../../tests/impala_files/conditional_gte.impala\n";
    configFile << "../../tests/impala_files/conditional_lt.impala\n";
    configFile << "../../tests/impala_files/conditional_lte.impala\n";
    configFile << "../../tests/impala_files/conditional_neq.impala";
    configFile.close();

    impalajit::Compiler compiler(CONFIG_FILE_PATH);
    std::map<std::string, dasm_gen_func> functions = compiler.compileMultipleFunctions();

    assert(functions.at("eq")(1.0,1.0) == 1.0);
    assert(functions.at("eq")(1.0,0.0) == 0.0);

    assert(functions.at("gt")(1.0, 0.0) == 1.0);
    assert(functions.at("gt")(0.0, 1.0) == 0.0);
    assert(functions.at("gt")(0.0, 0.0) == 0.0);

    assert(functions.at("gte")(2.0, 1.0) == 1.0);
    assert(functions.at("gte")(1.0, 1.0) == 1.0);
    assert(functions.at("gte")(0.0, 1.0) == 0.0);

    assert(functions.at("lt")(1.0, 0.0) == 0.0);
    assert(functions.at("lt")(0.0, 1.0) == 1.0);
    assert(functions.at("lt")(0.0, 0.0) == 0.0);

    assert(functions.at("lte")(2.0, 1.0) == 0.0);
    assert(functions.at("lte")(1.0, 1.0) == 1.0);
    assert(functions.at("lte")(0.0, 1.0) == 1.0);

    assert(functions.at("neq")(2.0, 1.0) == 1.0);
    assert(functions.at("neq")(1.0, 1.0) == 0.0);
    assert(functions.at("neq")(0.0, 1.0) == 1.0);
    return 0;
}