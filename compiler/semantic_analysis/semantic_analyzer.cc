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

#include <semantic_analyzer.hh>
#include <expression_nodes.h>
#include <assignment_nodes.h>
#include <stdexcept>

SemanticAnalyzer::~SemanticAnalyzer()
{
}


void SemanticAnalyzer::performSemanticAnalysis(FunctionContext* &functionContext){
    evaluateAst(functionContext, functionContext->root);

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
            dsfUtil(functionContext, node);
            if(functionContext->containsVariable(static_cast<VariableNode*>(node)->name)) {
                break;
            }
            else if(functionContext->containsParameter(static_cast<VariableNode*>(node)->name)) {
                break;
            }
            else{
                throw std::runtime_error("Variable "+static_cast<VariableNode*>(node)->name+" not initialized!");
            }
        }
        case ASSIGNMENT:
        {   // Check if the variable or parameter is already known. If not -> insert
            dsfUtil(functionContext, node);
            if(functionContext->containsVariable(static_cast<AssignmentNode*>(node)->name)) {
                break;
            }
            else if(functionContext->containsParameter(static_cast<AssignmentNode*>(node)->name)) {
                break;
            }
            else{
                functionContext->variables.push_back((static_cast<AssignmentNode *>(node)->name));
                break;
            }
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

        case EXTERNAL_FUNCTION:
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

