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

#ifndef IMPALAJIT_BASIC_EXPRESSION_H_HH
#define IMPALAJIT_BASIC_EXPRESSION_H_HH

#include <node.h>

class ConstantNode : public Node
{
public:
    double value;
    explicit ConstantNode(double _value)
            : Node(CONSTANT), value(_value)
    {
    }
};

class VariableNode : public Node {

public:
    std::string &name;
    explicit VariableNode(std::string &_name)
            : Node(VARIABLE), name(_name) {
    }
};

class NegationNode : public Node
{
public:
    explicit NegationNode(Node* _node)
            : Node(NEGATION)
    {
        nodes.push_back(_node);
    }
};

class AdditionNode : public Node
{
public:
    explicit AdditionNode(Node* _left, Node* _right)
            : Node(ADDITION)
    {
        nodes.push_back(_left);
        nodes.push_back(_right);
    }
};

class SubtractionNode : public Node
{
public:
    explicit SubtractionNode(Node* _left, Node* _right)
            : Node(SUBTRACTION)
    {
        nodes.push_back(_left);
        nodes.push_back(_right);
    }
};

class MultiplicationNode : public Node
{
public:
    explicit MultiplicationNode(Node* _left, Node* _right)
            : Node(MULTIPLICATION)
    {
        nodes.push_back(_left);
        nodes.push_back(_right);
    }
};

class DivisionNode : public Node
{
public:
    explicit DivisionNode(Node* &_left, Node* &_right)
            : Node(DIVISION)
    {
        nodes.push_back(_left);
        nodes.push_back(_right);
    }
};

class SQRTNode: public Node
{
public:
    explicit SQRTNode(Node* &_node)
            : Node(SQRT)
    {
        nodes.push_back(_node);
    }
};

class PowerNode : public Node
{
public:
    explicit PowerNode(Node* _base, Node* _exponent)
            : Node(POWER)
    {
        nodes.push_back(_exponent);
        nodes.push_back(_base);
    }
};

#endif //IMPALAJIT_BASIC_EXPRESSION_H_HH
