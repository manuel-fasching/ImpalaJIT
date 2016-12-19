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
    int                 compareOperator;

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

class CNBooleanANDJunction : public CompareNode
{
    Node*       left;
    Node*       right;

public:
    explicit CNBooleanANDJunction(Node* _left, Node* _right, Assembly& _assembly)
            : CompareNode(_assembly), left(_left), right(_right)
    {
    }
    virtual ~CNBooleanANDJunction()
    {
        delete left;
        delete right;
    }

    virtual void evaluate(){
        left->evaluate();
        assembly.operator_ = left->getOperator();
        assembly.conditionalJumpForwardTo2IfFalse();
        right->evaluate();
        assembly.operator_ = right->getOperator();
        assembly.conditionalJumpForwardTo2IfFalse();
        assembly.conditionalJumpForwardTo1IfTrue();

        /*
        if(boolOperator == assembly.OR){
            assembly.jumpForwardTo2();
            assembly.addDynamicLabel1();
        }*/
    }

    virtual int getOperator(){
        return assembly.AND;
    }
};


class CNBooleanORJunction : public CompareNode
{
    Node*       left;
    Node*       right;

public:
    explicit CNBooleanORJunction(Node* _left, Node* _right, Assembly& _assembly)
            : CompareNode(_assembly), left(_left), right(_right)
    {
    }
    virtual ~CNBooleanORJunction()
    {
        delete left;
        delete right;
    }

    virtual void evaluate(){
        left->evaluate();
        assembly.operator_ = left->getOperator();
        assembly.conditionalJumpForwardTo1IfTrue();
        right->evaluate();
        assembly.operator_ = right->getOperator();
        assembly.conditionalJumpForwardTo1IfTrue();

    }

    virtual int getOperator(){
        return assembly.OR;
    }

        /*
        if(boolOperator == assembly.OR){
            assembly.jumpForwardTo2();
            assembly.addDynamicLabel1();
        }*/
};


class CNBoolean : public CompareNode
{
    Node*       node;

public:
    explicit CNBoolean(Node* _node, Assembly& _assembly)
            : CompareNode(_assembly), node(_node)
    {
    }
    virtual ~CNBoolean()
    {
        delete node;
    }

    virtual void evaluate(){
        node->evaluate();
        assembly.operator_ = node->getOperator();
        assembly.conditionalJumpForwardTo2IfFalse();
    }

    virtual int getOperator(){
        return assembly.OR;
    }
};


#endif //IMPALAJIT_COMPARISON_EXPRESSION_H
