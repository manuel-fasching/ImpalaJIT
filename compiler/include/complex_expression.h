//
// Created by manuel on 16.12.16.
//

#ifndef IMPALAJIT_COMPLEX_EXPRESSION_H
#define IMPALAJIT_COMPLEX_EXPRESSION_H

#include <expression.h>
#include <comparison_expression.h>
#include <basic_expression.h>

class ComplexNode : public Node
{
public:

    ComplexNode(class Assembly& _assembly)
            : Node(_assembly){
    }
    virtual ~ComplexNode()
    {
    }

    virtual void evaluate() = 0;

    virtual int getOperator() = 0;
};



class CxNIfStmt : public ComplexNode
{
    Node*   condition;
    Node*     body_if;

public:

    explicit CxNIfStmt(Node* _condition, Node* _body_if, Assembly& _assembly)

            : ComplexNode(_assembly), condition(_condition), body_if(_body_if)
    {
    }

    virtual ~CxNIfStmt()
    {
        delete condition;
        delete body_if;
    }

    virtual void evaluate()
    {
        condition->evaluate();
        /*for( unsigned int a = 0; a < sizeof(body_if)/sizeof(body_if[0]); a = a + 1 )
            body_if[a]->evaluate();*/
        body_if->evaluate();
        /*if(elsePresent)
            assembly.jumpForwardTo3();*/
        assembly.addDynamicLabel2();
    }
    virtual int getOperator(){
        return -1;
    }
};


class CxNIfElseStmt : public ComplexNode
{
    Node*   condition;
    Node*     body_if;
    Node*     body_else;

public:

    explicit CxNIfElseStmt(Node* _condition, Node* _body_if, Node* _body_else, Assembly& _assembly)

            : ComplexNode(_assembly), condition(_condition), body_if(_body_if), body_else(_body_else)
    {
    }

    virtual ~CxNIfElseStmt()
    {
        delete condition;
        delete body_if;
        delete body_else;
    }

    virtual void evaluate()
    {
        condition->evaluate();
        body_if->evaluate();
        assembly.jumpForwardTo3();
        assembly.addDynamicLabel2();
        body_else->evaluate();
        assembly.addDynamicLabel3();
    }

    virtual int getOperator(){
        return -1;
    }
};

#endif //IMPALAJIT_COMPLEX_EXPRESSION_H
