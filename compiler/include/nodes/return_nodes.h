//
// Created by manuel on 28.01.17.
//

#ifndef IMPALAJIT_RETURN_NODE_H
#define IMPALAJIT_RETURN_NODE_H

#include <node.h>

class ReturnNode : public Node
{
public:
    explicit ReturnNode(Node* _node)
            : Node(RETURN)
    {
        nodes.push_back(_node);
    }
};
#endif //IMPALAJIT_RETURN_NODE_H
