// $Id$
/** \file expression.h Implements an example calculator class group. */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>
#include <assembly.hh>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <set>

class Node
{
protected:
    class Assembly &assembly;
    class ExpressionContext &expressionContext;

public:
    Node(class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : assembly(_assembly), expressionContext(_expressionContext)
    {
    }
    virtual ~ Node()
    {
    }

    virtual void evaluate() = 0;

    virtual int getOperator() = 0;

};

class ExpressionContext {
private:
    std::set<unsigned long> parameters;
    std::set<unsigned long> variables;
    std::vector<Node *> ast;

    unsigned long computeHash(const char* str)
    {
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
    }

public:
    ~ExpressionContext() {
        for(std::vector<Node*>::iterator it = ast.begin(); it != ast.end(); ++it) {
            delete (*it);
        }
    }

    void addParameter(std::string& name){
        unsigned long hash = computeHash(name.c_str());
        parameters.insert(hash);
    }

    void addVariable(std::string& name){
        unsigned long hash = computeHash(name.c_str());
        variables.insert(hash);
    }

    void addNode(Node* node){
        ast.push_back(node);
    }

    void evaluateAst(){
        for(std::vector<Node*>::iterator it = ast.begin(); it != ast.end(); ++it) {
            (*it)->evaluate();
        }
    }

    int getIndexOfParameter(std::string& name){
        unsigned long hash = computeHash(name.c_str());
        std::set<unsigned long>::iterator it = std::find(parameters.begin(), parameters.end(), hash);
        if (it == parameters.end()) {
            throw std::runtime_error("Parameter not found");
        }
        else{
            return std::distance(parameters.begin(), it);
        }
    }

    int getIndexOfVariable(std::string& name){
        unsigned long hash = computeHash(name.c_str());
        std::set<unsigned long>::iterator it = std::find(variables.begin(), variables.end(), hash);
        if (it == variables.end()) {
            throw std::runtime_error("Parameter not found");
        }
        else{
            return std::distance(variables.begin(), it);
        }
    }


};

#endif // EXPRESSION_H
