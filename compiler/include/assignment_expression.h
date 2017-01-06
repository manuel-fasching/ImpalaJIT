//
// Created by manuel on 04.01.17.
//

#ifndef IMPALAJIT_ASSIGNMENT_EXPRESSION_HH
#define IMPALAJIT_ASSIGNMENT_EXPRESSION_HH
#include <expression.h>

class AssignmentExpression : public Node
{
public:
    Node* node;
    std::string& name;
    std::map<std::string, double*>& variables;

    AssignmentExpression(std::string &_name, Node* _node, std::map<std::string, double*>& _variables, class Assembly& _assembly)
            : Node(_assembly), name(_name), node(_node), variables(_variables)
    {
    }

    virtual ~AssignmentExpression()
    {
        delete node;
    }

    virtual void evaluate() {
        printf("assignment");
        node->evaluate();
        variables[name] = assembly.pull();
    }

    virtual int getOperator() {
        return -1;
    }
};
#endif //IMPALAJIT_ASSIGNMENT_EXPRESSION_HH
