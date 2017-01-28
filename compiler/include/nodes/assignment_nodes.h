//
// Created by manuel on 04.01.17.
//

#ifndef IMPALAJIT_ASSIGNMENT_EXPRESSION_HH
#define IMPALAJIT_ASSIGNMENT_EXPRESSION_HH

#include <node.h>

class AssignmentNode : public Node
{
public:
    std::string &name;
    AssignmentNode(std::string &_name, Node* _node)
            : name(_name), Node(ASSIGNMENT)
    {
        nodes.push_back(_node);
    }

    virtual ~AssignmentNode()
    {
    }
/*
    virtual void evaluate() {
        node->evaluate();
        assembly.storeLocalVariable();
    }*/
};
#endif //IMPALAJIT_ASSIGNMENT_EXPRESSION_HH
