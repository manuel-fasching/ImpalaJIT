/**
 * Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
 * Distributed under the MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdexcept>

#include <function_context.h>


FunctionContext::FunctionContext(std::string &_name, std::set<std::string> &_parameters, Node* &_root)
: name(_name), parameters(_parameters), root(_root)
{
}

FunctionContext::~FunctionContext() {
    delete root;
    parameters.clear();
    variables.clear();
    root = NULL;
}

int FunctionContext::getIndexOfParameter(std::string &name) {
    std::set<std::string>::iterator it = std::find(parameters.begin(), parameters.end(), name);
    if (it == parameters.end()) {
        throw std::runtime_error("Parameter not found");
    }
    else{
        return std::distance(parameters.begin(), it);
    }
}

int FunctionContext::getIndexOfVariable(std::string &name) {
    std::set<std::string>::iterator it = std::find(variables.begin(), variables.end(), name);
    if (it == variables.end()) {
        throw std::runtime_error("Variable not found");
    }
    else{
        return std::distance(variables.begin(), it);
    }
}

void FunctionContext::clear(){
    delete root;
    parameters.clear();
    variables.clear();
    root = NULL;
}
