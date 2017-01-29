//
// Created by manuel on 28.01.17.
//

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
        throw std::runtime_error("Parameter not found");
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
