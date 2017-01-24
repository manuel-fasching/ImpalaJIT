//
// Created by manuel on 16.12.16.
//

#ifndef IMPALAJIT_COMPLEX_EXPRESSION_H
#define IMPALAJIT_COMPLEX_EXPRESSION_H

#include <expression.h>
#include <comparison_expression.h>
#include <basic_expression.h>
#include <boolean_expression.h>

class CxNIfStmt : public Node
{
    Node*   condition;
    Node*     body_if;

public:

    explicit CxNIfStmt(Node* _condition, Node* _body_if, class Assembly& _assembly, class ExpressionContext& _expressionContext)

            : Node(_assembly, _expressionContext), condition(_condition), body_if(_body_if)
    {
    }

    ~CxNIfStmt()
    {
        delete condition;
        delete body_if;
    }

    void evaluate()
    {
        int label1 = 1;
        int label2 = 9;


        ((BooleanJunctionNode*) condition)->label1 = &label1;
        ((BooleanJunctionNode*) condition)->label2 = &label2;

        condition->evaluate();
        assembly.addLocalLabel(label1);
        body_if->evaluate();
        assembly.addLocalLabel(label2);
    }

    virtual int getOperator(){
        return -1;
    }
};


class CxNIfElseStmt : public Node
{
    Node*   condition;
    Node*     body_if;
    Node*     body_else;

public:

    explicit CxNIfElseStmt(Node* _condition, Node* _body_if, Node* _body_else, class Assembly& _assembly, class ExpressionContext& _expressionContext)

            : Node(_assembly, _expressionContext), condition(_condition), body_if(_body_if), body_else(_body_else)
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
        int label1 = 1;
        int label2 = 8;
        int label3 = 9;

        ((BooleanJunctionNode*) condition)->label1 = &label1;
        ((BooleanJunctionNode*) condition)->label2 = &label2;
        condition->evaluate();
        assembly.addLocalLabel(label1);
        body_if->evaluate();
        assembly.jumpForwardTo(label3);
        assembly.addLocalLabel(label2);
        body_else->evaluate();
        assembly.addLocalLabel(label3);
    }

    virtual int getOperator(){
        return -1;
    }
};

#endif //IMPALAJIT_COMPLEX_EXPRESSION_H
