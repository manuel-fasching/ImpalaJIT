//
// Created by manuel on 27.01.17.
//

#include <code_generator.hh>
#include <expression_nodes.h>
#include <compare_nodes.h>

CodeGenerator::CodeGenerator(class FunctionContext &_functionContext)
    : functionContext(_functionContext){
    dynamicLabelCount = 0;
}

CodeGenerator::~CodeGenerator()
{
}

dasm_gen_func CodeGenerator::generateCode()
{
    assembly.initialize();
    assembly.prologue();

    evaluateAst(functionContext.root);

    return assembly.linkAndEncode();
}

void CodeGenerator::evaluateAst(Node *node){
    switch(node->nodeType)
    {
        case ROOT:{
            dsfUtil(node);
            break;
        }
        case CONSTANT:
        {
            assembly.pushConstantToFPUStack(&(static_cast<ConstantNode*>(node)->value));
            break;
        }

        case VARIABLE:
        {
            try {
                int index = functionContext.getIndexOfParameter((static_cast<VariableNode *>(node)->name));
                assembly.pushParameterToFPUStack(index);
                break;
            }
            catch(std::exception& e) {
            }
            int index = functionContext.getIndexOfVariable((static_cast<VariableNode *>(node)->name));
            assembly.pushLocalVariableToFPUStack(index);
            break;
        }

        case NEGATION:
        {
            dsfUtil(node);
            assembly.performNegation();
            break;
        }

        case ADDITION:
        {
            dsfUtil(node);
            assembly.calculateAddition();
            break;
        }

        case SUBTRACTION:
        {
            dsfUtil(node);
            assembly.calculateSubtraction();
            break;
        }

        case MULTIPLICATION:
        {
            dsfUtil(node);
            assembly.calculateMultiplication();
            break;
        }

        case DIVISION:
        {
            dsfUtil(node);
            assembly.calculateDivision();
            break;
        }

        case POWER:
        {
            dsfUtil(node);
            assembly.calculatePower();
            break;
        }

        case SQRT:
        {
            dsfUtil(node);
            assembly.calculateSQRT();
            break;
        }

        case ASSIGNMENT:
        {
            dsfUtil(node);
            try {
                int index = functionContext.getIndexOfParameter((static_cast<VariableNode *>(node)->name));
                assembly.replaceParameter(index);
                break;
            }
            catch(std::exception& e) {
            }
            try {
                int index = functionContext.getIndexOfVariable((static_cast<VariableNode *>(node)->name));
                assembly.replaceLocalVariable(index);
                break;
            }
            catch(std::exception& e) {
            }
            functionContext.variables.insert((static_cast<VariableNode *>(node)->name));
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

            conditionEvaluationHelper(node->nodes.at(0), label1, label2); //condition
            assembly.addDynamicLabel(label1);
            dsfUtil(node->nodes.at(1)); // if body
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

            conditionEvaluationHelper(node->nodes.at(0), label1, label2); //condition

            assembly.addDynamicLabel(label1);
            dsfUtil(node->nodes.at(1));
            assembly.jumpForwardToDynamicLabel(label3);
            assembly.addDynamicLabel(label2);
            dsfUtil(node->nodes.at(2));
            assembly.addDynamicLabel(label3);
            break;
        }
        case IF_BODY:
        {
            dsfUtil(node);
            break;
        }
        case ELSE_BODY:
        {
            dsfUtil(node);
            break;
        }

        case RETURN:
        {
            dsfUtil(node);
            assembly.extractResult();
            assembly.epilogue();
            break;
        }
    }
}


void CodeGenerator::dsfUtil(Node* node) {
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        evaluateAst((*it));
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

void CodeGenerator::conditionEvaluationHelper(Node* node, unsigned label1, unsigned label2){
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        switch(node->nodeType)
        {
            case COMPARISON:
            {
                dsfUtil(node);
                assembly.performComparison();
                assembly.conditionalJumpForwardToDynamicLabel(label2, false, static_cast<CompareNode*>(node)->compareOperator);
                break;
            }
            case BOOLEAN_OR_JUNCTION:
            {
                switch((*it)->nodeType){
                    case COMPARISON:
                    {
                        dsfUtil(*it);
                        assembly.performComparison();
                        assembly.conditionalJumpForwardToDynamicLabel(label1, true, static_cast<CompareNode*>(*it)->compareOperator);
                        break;
                    }
                    case BOOLEAN_OR_JUNCTION:
                    {
                        conditionEvaluationHelper((*it), label1, label2);
                        break;
                    }
                    case BOOLEAN_AND_JUNCTION:
                    {
                        conditionEvaluationHelper((*it), label1, label2-1);
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
                        dsfUtil(*it);
                        assembly.performComparison();
                        assembly.conditionalJumpForwardToDynamicLabel(label2, false, static_cast<CompareNode*>(*it)->compareOperator);
                        break;
                    }
                    case BOOLEAN_AND_JUNCTION:
                    {
                        conditionEvaluationHelper(*(it), label1, label2);
                        break;
                    }
                    case BOOLEAN_OR_JUNCTION:
                    {
                        conditionEvaluationHelper((*it), label1+1, label2);
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