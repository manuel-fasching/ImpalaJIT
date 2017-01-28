// $Id$
/** \file expression.h Implements an example calculator class group. */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <internal_types.hh>
#include <vector>

class Node
{
public:
    NodeType nodeType;
    std::vector<Node*> nodes;

    Node(NodeType _nodeType) :
            nodeType(_nodeType)
    {
    }
    virtual ~Node()
    {
        nodes.clear();
    }
};

class RootNode : public Node
{
public:
    RootNode()
            : Node(ROOT)
    {
    }
};

#endif // EXPRESSION_H
