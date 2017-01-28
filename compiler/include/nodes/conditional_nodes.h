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
