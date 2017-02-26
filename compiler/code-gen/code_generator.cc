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

#include <code_generator.hh>
#include <expression_nodes.h>
#include <compare_nodes.h>
#include <external_function_nodes.h>
#include <calculation_helper.hh>
#include <ptr_map_container.hh>

std::map<std::string, externalFunction> FunctionPtrMap::map;

CodeGenerator::CodeGenerator() {
    dynamicLabelCount = 0;
}

CodeGenerator::~CodeGenerator()
{
}

dasm_gen_func CodeGenerator::generateCode(FunctionContext* &functionContext)
{
    FunctionPtrMap::initialize_map();
    assembly.initialize(functionContext->parameters.size());
    assembly.prologue();

    evaluateAst(functionContext, functionContext->root);

    return assembly.linkAndEncode();
}

void CodeGenerator::evaluateAst(FunctionContext* &functionContext, Node* &node){
    switch(node->nodeType)
    {
        case ROOT:{
            dsfUtil(functionContext, node);
            break;
        }
        case CONSTANT:
        {
            assembly.pushConstantToStack((static_cast<ConstantNode *>(node)->value));
            break;
        }

        case VARIABLE:
        {
            try {
                int index = functionContext->getIndexOfParameter((static_cast<VariableNode *>(node)->name));
                assembly.pushParameterToStack(index);
                break;
            }
            catch(std::exception& e) {
            }
            int index = functionContext->getIndexOfVariable((static_cast<VariableNode *>(node)->name));
            assembly.pushLocalVariableToStack(index);
            break;
        }

        case NEGATION:
        {
            dsfUtil(functionContext, node);
            assembly.callExternalFunction(reinterpret_cast<externalFunction>(CalculationHelper::changeSign), 1);
            break;
        }

        case ADDITION:
        {
            dsfUtil(functionContext, node);
            assembly.calculateAddition();
            break;
        }

        case SUBTRACTION:
        {
            dsfUtil(functionContext, node);
            assembly.calculateSubtraction();
            break;
        }

        case MULTIPLICATION:
        {
            dsfUtil(functionContext, node);
            assembly.calculateMultiplication();
            break;
        }

        case DIVISION:
        {
            dsfUtil(functionContext, node);
            assembly.calculateDivision();
            break;
        }

        case EXTERNAL_FUNCTION:
        {
            dsfUtil(functionContext, node);
            assembly.callExternalFunction(FunctionPtrMap::map.find((static_cast<ExternalFunctionNode *>(node)->name))->second, node->nodes.size());
            break;
        }

        case ASSIGNMENT:
        {
            dsfUtil(functionContext, node);
            try {
                int index = functionContext->getIndexOfParameter((static_cast<VariableNode *>(node)->name));
                assembly.replaceParameter(index);
                break;
            }
            catch(std::exception& e) {
            }
            try {
                int index = functionContext->getIndexOfVariable((static_cast<VariableNode *>(node)->name));
                assembly.replaceLocalVariable(index);
                break;
            }
            catch(std::exception& e) {
            }
            functionContext->variables.push_back((static_cast<VariableNode *>(node)->name));
            assembly.storeLocalVariable();
            break;
        }

        case IF_STATEMENT:
        {
            unsigned labelDemand = (2+ countLabels(node->nodes.at(0)));
            unsigned label1 = dynamicLabelCount;
            dynamicLabelCount += labelDemand;
            unsigned label2 = dynamicLabelCount-1;
            assembly.growPC(dynamicLabelCount);

            conditionEvaluationHelper(functionContext, node->nodes.at(0), label1, label2); //condition
            assembly.addDynamicLabel(label1);
            dsfUtil(functionContext, node->nodes.at(1)); // if body
            assembly.addDynamicLabel(label2);
            break;
        }
        case IF_ELSE_STATEMENT:
        {
            unsigned labelDemand = (3 + countLabels(node->nodes.at(0)));
            unsigned label1 = dynamicLabelCount;
            dynamicLabelCount += labelDemand;
            unsigned label2 = dynamicLabelCount-2;
            unsigned label3 = dynamicLabelCount-1;
            assembly.growPC(dynamicLabelCount);

            conditionEvaluationHelper(functionContext, node->nodes.at(0), label1, label2); //condition

            assembly.addDynamicLabel(label1);
            dsfUtil(functionContext, node->nodes.at(1));
            assembly.jumpForwardToDynamicLabel(label3);
            assembly.addDynamicLabel(label2);
            dsfUtil(functionContext, node->nodes.at(2));
            assembly.addDynamicLabel(label3);
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
            assembly.extractResult();
            assembly.epilogue();
            break;
        }
    }
}


void CodeGenerator::dsfUtil(FunctionContext* &functionContext, Node* &node) {
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        evaluateAst(functionContext, (*it));
    }
}

unsigned CodeGenerator::countLabels(Node* node){
    unsigned labels = 0;
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        if (node->nodeType == BOOLEAN_OR_JUNCTION) {
            if ((*it)->nodeType == BOOLEAN_AND_JUNCTION) {
                labels++;
            }
        }
        else if (node->nodeType == BOOLEAN_AND_JUNCTION) {
            if ((*it)->nodeType == BOOLEAN_OR_JUNCTION) {
                labels++;
            }
        }
        labels += countLabels((*it));
    }
    return labels;
}

void CodeGenerator::conditionEvaluationHelper(FunctionContext* &functionContext, Node* &node, unsigned label1, unsigned label2){
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        switch(node->nodeType)
        {
            case COMPARISON:
            {
                dsfUtil(functionContext, node);
                assembly.conditionalJumpForwardToDynamicLabel(label2, false, static_cast<CompareNode*>(node)->compareOperator);
                break;
            }
            case BOOLEAN_OR_JUNCTION:
            {
                switch((*it)->nodeType){
                    case COMPARISON:
                    {
                        dsfUtil(functionContext, *it);
                        assembly.conditionalJumpForwardToDynamicLabel(label1, true, static_cast<CompareNode*>(*it)->compareOperator);
                        break;
                    }
                    case BOOLEAN_OR_JUNCTION:
                    {
                        conditionEvaluationHelper(functionContext, (*it), label1, label2);
                        break;
                    }
                    case BOOLEAN_AND_JUNCTION:
                    {
                        conditionEvaluationHelper(functionContext, (*it), label1, label2-1);
                        assembly.jumpForwardToDynamicLabel(label1);
                        assembly.addDynamicLabel(label2-1);
                        break;
                    }
                }
                break;
            }

            case BOOLEAN_AND_JUNCTION:
            {
                switch((*it)->nodeType) {
                    case COMPARISON: {
                        dsfUtil(functionContext, *it);
                        assembly.conditionalJumpForwardToDynamicLabel(label2, false, static_cast<CompareNode*>(*it)->compareOperator);
                        break;
                    }
                    case BOOLEAN_AND_JUNCTION:
                    {
                        conditionEvaluationHelper(functionContext, (*it), label1, label2);
                        break;
                    }
                    case BOOLEAN_OR_JUNCTION:
                    {
                        conditionEvaluationHelper(functionContext, (*it), label1+1, label2);
                        assembly.addDynamicLabel(label1+1);
                        break;
                    }
                }
            }
        }
        if(node->nodeType == COMPARISON)
            break;
    }
    if(node->nodeType == BOOLEAN_OR_JUNCTION)
            assembly.jumpForwardToDynamicLabel(label2);
}