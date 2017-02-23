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

#ifndef IMPALAJIT_EXTERNAL_FUNCTION_NODE_H
#define IMPALAJIT_EXTERNAL_FUNCTION_NODE_H

#include <node.h>
#include <iostream>

class ExternalFunctionNode: public Node
{
public:
    std::string &name;
    ExternalFunctionNode(std::string &_name, std::vector<Node*> &_parameters)
            : name(_name), Node(EXTERNAL_FUNCTION)
    {
        nodes.insert(nodes.end(), _parameters.begin(), _parameters.end());
    }
    ExternalFunctionNode(std::string &_name)
            : name(_name), Node(EXTERNAL_FUNCTION)
    {
    }
    virtual ~ExternalFunctionNode()
    {
    }
};

class ExternalFunctionParametersNode : public Node
{
public:
    ExternalFunctionParametersNode()
            : Node(EXTERNAL_FUNCTION_PARAMETER)
    {
    }

    virtual ~ExternalFunctionParametersNode()
    {
    }
};


#endif //IMPALAJIT_EXTERNAL_FUNCTION_NODE_H