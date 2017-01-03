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

class Node
{
protected:
    class Assembly& assembly;

public:
    Node(class Assembly& _assembly)
            : assembly(_assembly)
    {
    }
    virtual ~ Node()
    {
    }

    virtual void evaluate() = 0;

    virtual int getOperator() = 0;

};

/** ImpalaJIT context used to save the parsed expressions. This context is
 * passed along to the impalajit::Driver class and fill during parsing via bison
 * actions. */
class ExpressionContext {
public:

    /// type of the variable storage
    typedef std::map<std::string, double*> variablemap_type;

    /// variable storage. maps variable string to doubles
    variablemap_type variables;

    /// array of unassigned expressions found by the parser. these are then
    /// outputted to the user.
    std::vector<Node *> expressions;

    /// free the saved expression trees
    ~ExpressionContext() {
        clearExpressions();
        clearVariables();
    }

    /// free all saved expression trees
    void clearExpressions() {
        for (unsigned int i = 0; i < expressions.size(); ++i) {
            delete expressions[i];
        }
        expressions.clear();
    }

    /// free all variables
    void clearVariables(){
        variables.clear();
    }

    void addVariable(const std::string &varname, Node* node) {
        node->evaluate();
        variables[varname] = assembly.pull();
    }

    /// check if the given variable name exists in the storage
    bool existsVariable(const std::string &varname) const {
        return variables.find(varname) != variables.end();
    }

    /// return the given variable from the storage. throws an exception if it
    /// does not exist.
    double* getVariable(const std::string &varname) const {
        variablemap_type::const_iterator vi = variables.find(varname);
        if (vi == variables.end())
            throw (std::runtime_error("Unknown variable."));
        else
            return vi->second;
    }
    Assembly assembly;
};

#endif // EXPRESSION_H
