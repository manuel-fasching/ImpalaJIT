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

impalajit::Compiler::impalajit_error impalajit::Compiler::setVariable(std::string name, double value){
    double* buffer = expressionContext.getVariable(name);
    *buffer = value;
}

void impalajit::Compiler::clearVariables() {
    expressionContext.clearVariables();
}