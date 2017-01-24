//
// Created by manuel on 22.11.16.
//

#include <impalajit.hh>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "expression.h"
#include "driver.h"


impalajit::Driver driver;


dasm_gen_func impalajit::Compiler::compile(){
    char* fileName = std::getenv(ENV_VARIABLE_NAME);
    if(fileName == NULL) {
        printf("Please specify env variable IMPALA_FILE. Error %u", NO_IMPALAFILE_SPECIFIED);
        exit(0);
    }

    return driver.parse_file(fileName);
}

//C Interface
impalajit_compiler *impalajit_compiler_create() {
    return new impalajit::Compiler();
}

dasm_gen_func impalajit_compiler_compile(impalajit_compiler *handle) {
    handle->compile();
}