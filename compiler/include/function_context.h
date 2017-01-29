//
// Created by manuel on 27.01.17.
//

#ifndef IMPALAJIT_FUNCTION_CONTEXT_HH
#define IMPALAJIT_FUNCTION_CONTEXT_HH

#include <vector>
#include <set>
#include <node.h>
#include <iostream>
#include <algorithm>

class FunctionContext {

public:
    std::set<std::string> parameters;
    std::set<std::string> variables;
    Node* root;
    std::string name;

    FunctionContext(std::string &_name, std::set<std::string> &_parameters, Node* &_root);

    ~FunctionContext();

    int getIndexOfParameter(std::string& name);

    int getIndexOfVariable(std::string &name);

    void clear();

};
#endif //IMPALAJIT_FUNCTION_CONTEXT_HH
