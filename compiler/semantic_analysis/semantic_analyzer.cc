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

#include <stdexcept>

#include <semantic_analyzer.hh>
#include <expression_nodes.h>

SemanticAnalyzer::~SemanticAnalyzer()
{
}


void SemanticAnalyzer::performSemanticAnalysis(FunctionContext* &functionContext){
    assignmentCount=0;
    evaluateAst(functionContext, functionContext->root);
    if(assignmentCount > 31){
        throw std::runtime_error("Error: ImpalaJIT only support 31 local variables");
    }
}

void SemanticAnalyzer::evaluateAst(FunctionContext* &functionContext, Node* &node){
    switch(node->nodeType)
    {
        case ROOT:
        {
            dsfUtil(functionContext, node);
            break;
        }
        case VARIABLE:
        {
            try {
                functionContext->getIndexOfParameter((static_cast<VariableNode *>(node)->name));
                break;
            }
            catch(std::exception& e) {
            }
            functionContext->getIndexOfVariable((static_cast<VariableNode *>(node)->name));
            break;
        }
        case ASSIGNMENT:
        {
            dsfUtil(functionContext, node);
            try {
                functionContext->getIndexOfParameter((static_cast<VariableNode *>(node)->name));
                break;
            }
            catch(std::exception& e) {
            }
            try {
                functionContext->getIndexOfVariable((static_cast<VariableNode *>(node)->name));
                break;
            }
            catch(std::exception& e) {
            }
            functionContext->variables.insert((static_cast<VariableNode *>(node)->name));
            assignmentCount++;
            break;
        }

        case NEGATION:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case ADDITION:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case SUBTRACTION:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case MULTIPLICATION:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case DIVISION:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case POWER:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case SQRT:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case IF_STATEMENT:
        {
            dsfUtil(functionContext, node->nodes.at(0));
            dsfUtil(functionContext, node->nodes.at(1)); // if body
            break;
        }
        case IF_ELSE_STATEMENT:
        {
            dsfUtil(functionContext, node->nodes.at(0));
            dsfUtil(functionContext, node->nodes.at(1)); // if body
            dsfUtil(functionContext, node->nodes.at(2)); // else body
            break;
        }
        case IF_BODY:
        {
            dsfUtil(functionContext, node);
            break;
        }
        case ELSE_BODY:
        {
            dsfUtil(functionContext, node);
            break;
        }

        case RETURN:
        {
            dsfUtil(functionContext, node);
            break;
        }
    }
}


void SemanticAnalyzer::dsfUtil(FunctionContext* &functionContext, Node* &node) {
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        evaluateAst(functionContext, (*it));
    }
}

