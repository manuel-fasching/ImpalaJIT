//
// Created by manuel on 16.12.16.
//

#ifndef IMPALAJIT_COMPLEX_EXPRESSION_H
#define IMPALAJIT_COMPLEX_EXPRESSION_H

#include <node.h>

class IfStmtNode : public Node
{
public:
    IfStmtNode(Node* _condition, Node* _if_body)
            : Node(IF_STATEMENT)
    {
        nodes.push_back(_condition);
        nodes.push_back(_if_body);
    }
/*
    void evaluate()
    {
        int* label1 = new int(1);
        int* label2 = new int(9);

        ((BooleanJunctionNode*) condition)->label1 = label1;
        ((BooleanJunctionNode*) condition)->label2 = label2;

        condition->evaluate();
        assembly.addLocalLabel(*label1);
        for(std::vector<Node*>::iterator it = body_if.begin(); it != body_if.end(); ++it)
            (*it)->evaluate();
        assembly.addLocalLabel(*label2);

        delete label1;
        delete label2;
    }*/
};

class IfElseStmtNode : public Node
{
public:

    explicit IfElseStmtNode(Node* _condition, Node* _if_body, Node* _else_body)
            : Node(IF_ELSE_STATEMENT)
    {
        nodes.push_back(_condition);
        nodes.push_back(_if_body);
        nodes.push_back(_else_body);
    }
/*
    virtual void evaluate()
    {
        int* label1 = new int(1);
        int* label2 = new int(8);
        int* label3 = new int(9);

        ((BooleanJunctionNode*) condition)->label1 = label1;
        ((BooleanJunctionNode*) condition)->label2 = label2;
        condition->evaluate();
        assembly.addLocalLabel(*label1);
        for(std::vector<Node*>::iterator it = body_if.begin(); it != body_if.end(); ++it)
            (*it)->evaluate();
        assembly.jumpForwardTo(*label3);
        assembly.addLocalLabel(*label2);
        for(std::vector<Node*>::iterator it = body_else.begin(); it != body_else.end(); ++it)
            (*it)->evaluate();
        assembly.addLocalLabel(*label3);

        delete label1;
        delete label2;
        delete label3;
    }
*/
};

class IfConditionNode : public Node
{
public:
    IfConditionNode(Node* _node)
            : Node(IF_CONDITION)
    {
        nodes.push_back(_node);
    }

    virtual ~IfConditionNode()
    {
    }
};

class IfBodyNode : public Node
{
public:
    IfBodyNode()
            : Node(IF_BODY)
    {
    }

    virtual ~IfBodyNode()
    {
    }
};

class ElseBodyNode : public Node
{
public:
    ElseBodyNode()
            : Node(ELSE_BODY)
    {
    }

    virtual ~ElseBodyNode()
    {
    }
};
#endif //IMPALAJIT_COMPLEX_EXPRESSION_H
