//
// Created by manuel on 16.12.16.
//

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
    explicit PowerNode(Node* _left, Node* _right)
            : Node(POWER)
    {
        nodes.push_back(_right);
        nodes.push_back(_left);
    }
};

#endif //IMPALAJIT_BASIC_EXPRESSION_H_HH
