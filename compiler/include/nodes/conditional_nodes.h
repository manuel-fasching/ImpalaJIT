/**
 * Copyright 2017 Manuel Fasching <manuel.fasching@tum.de>
 * Distributed under the MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
 * FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

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
