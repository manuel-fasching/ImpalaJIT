//
// Created by manuel on 26.12.16.
//

#ifndef IMPALAJIT_BOOL_H
#define IMPALAJIT_BOOL_H

#include <node.h>

class BooleanAndNode : public Node {

public:
    BooleanAndNode()
    : Node(BOOLEAN_AND_JUNCTION)
    {
    }
};


class BooleanOrNode : public Node {

public:
    BooleanOrNode()
            : Node(BOOLEAN_OR_JUNCTION)
    {
    }
};

#endif //IMPALAJIT_BOOL_H
