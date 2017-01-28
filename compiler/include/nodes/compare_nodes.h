//
// Created by manuel on 16.12.16.
//

#ifndef IMPALAJIT_COMPARISON_EXPRESSION_H
#define IMPALAJIT_COMPARISON_EXPRESSION_H

#include <node.h>

class CompareNode : public Node
{
public:
    CompareOperatorType  compareOperator;
    explicit CompareNode(Node* _left, Node* _right, CompareOperatorType _compareOperator)
            : Node(COMPARISON),  compareOperator(_compareOperator)
    {
        nodes.push_back(_left);
        nodes.push_back(_right);
    }
};


#endif //IMPALAJIT_COMPARISON_EXPRESSION_H
