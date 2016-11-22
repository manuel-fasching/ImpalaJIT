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

    expressionContext.clearExpressions();
    return driver.parse_file(fileName);
}

impalajit::Compiler::impalajit_error impalajit::Compiler::setVariable(char* name, double* buffer){
    expressionContext.variables[name] = buffer;
}

void impalajit::Compiler::clearVariables() {
    expressionContext.clearVariables();
}