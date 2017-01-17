//
// Created by manuel on 22.11.16.
//

#include <impalajit.hh>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "expression.h"
#include "driver.h"


ExpressionContext expressionContext;
impalajit::Driver driver(expressionContext);


dasm_gen_func impalajit::Compiler::compile(){
    char* fileName = std::getenv(ENV_VARIABLE_NAME);
    if(fileName == NULL) {
        printf("Please specify env variable IMPALA_FILE. Error %u", NO_IMPALAFILE_SPECIFIED);
        exit(0);
    }

    expressionContext.clearExpressions();
    return driver.parse_file(fileName);
}

impalajit::Compiler::Error impalajit::Compiler::setVariable(std::string name, double value){
    double* buffer = expressionContext.getVariable(name);
    *buffer = value;
}

void impalajit::Compiler::clearVariables() {
    expressionContext.clearVariables();
}



//C Interface

impalajit_compiler *impalajit_compiler_create() {
    return new impalajit::Compiler();
}

impalajit_error impalajit_compiler_set_variable(impalajit_compiler *handle, const char name[], double value) {
    return handle->setVariable(std::string(name), value);
}

void impalajit_compiler_clear_variables(impalajit_compiler *handle) {
    handle->clearVariables();
}

dasm_gen_func impalajit_compiler_compile(impalajit_compiler *handle) {
    handle->compile();
}