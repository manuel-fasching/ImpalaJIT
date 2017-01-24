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

    AssignmentExpression(Node* _node, class Assembly& _assembly, class ExpressionContext& _expressionContext)
            : node(_node), Node(_assembly, _expressionContext)
    {
    }

    virtual ~AssignmentExpression()
    {
        delete node;
    }

    virtual void evaluate() {
        node->evaluate();
        assembly.storeLocalVariable();
    }

    virtual int getOperator() {
        return -1;
    }
};
#endif //IMPALAJIT_ASSIGNMENT_EXPRESSION_HH
