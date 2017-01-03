//
// Created by manuel on 16.12.16.
//

#ifndef IMPALAJIT_COMPARISON_EXPRESSION_H
#define IMPALAJIT_COMPARISON_EXPRESSION_H

#include <expression.h>
#include <basic_expression.h>

class CompareNode : public Node
{

public:
    CompareNode(class Assembly& _assembly)
            : Node(_assembly)
    {
    }

    virtual ~CompareNode()
    {
    }

    virtual void evaluate() = 0;

    virtual int getOperator() = 0;

};



class CNComparison : public CompareNode
{
    Node*     left;
    Node*     right;
    int       compareOperator;

public:
    explicit CNComparison(Node* _left, Node* _right, int _compareOperator, Assembly& _assembly)
            : CompareNode(_assembly), left(_left), right(_right), compareOperator(_compareOperator)
    {
    }
    virtual ~CNComparison()
    {
        delete left;
        delete right;
    }
    virtual void evaluate(){
        right->evaluate();
        left->evaluate();
        assembly.operator_ = compareOperator;
        assembly.compile();
    }

    virtual int getOperator(){
        return compareOperator;
    }
};


#endif //IMPALAJIT_COMPARISON_EXPRESSION_H
