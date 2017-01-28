//
// Created by manuel on 27.01.17.
//

#include <code_generator.hh>
#include <expression_nodes.h>
#include <compare_nodes.h>


CodeGenerator::~CodeGenerator()
{
}

dasm_gen_func CodeGenerator::generateCode()
{
    assembly.initialize();
    assembly.prologue();

    evaluateAst(functionContext.root);

    assembly.extractResult();

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
        {   int label1 = 1;
            int label2 = 9;
            evaluateCondition(node->nodes.at(0), label1, label2); //condition
            assembly.addLocalLabel(label1);
            dsfUtil(node->nodes.at(1)); // if body
            assembly.addLocalLabel(label2);
            break;
        }
        case IF_ELSE_STATEMENT:
        {
            int label1 = 1;
            int label2 = 8;
            int label3 = 9;
            evaluateCondition(node->nodes.at(0), label1, label2);
            assembly.addLocalLabel(label1);
            dsfUtil(node->nodes.at(1));
            assembly.jumpForwardTo(label3);
            assembly.addLocalLabel(label2);
            dsfUtil(node->nodes.at(2));
            assembly.addLocalLabel(label3);
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

void CodeGenerator::evaluateCondition(Node* node, int label1, int label2){
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        switch(node->nodeType)
        {
            case BOOLEAN_OR_JUNCTION:
            {
                switch((*it)->nodeType){
                    case COMPARISON:
                    {
                        CompareOperatorType cop = evaluateComparison((*it));
                        assembly.conditionalJumpForwardTo(label1, true, cop);
                        break;
                    }
                    case BOOLEAN_OR_JUNCTION:
                    {
                        evaluateCondition((*it), label1, label2);
                        break;
                    }
                    case BOOLEAN_AND_JUNCTION:
                    {
                        int label = label2-1;
                        evaluateCondition((*it), label1, label);
                        assembly.jumpForwardTo(label1);
                        assembly.addLocalLabel(label);
                        break;
                    }
                }
                break;
            }

            case BOOLEAN_AND_JUNCTION:
            {
                switch((*it)->nodeType) {
                    case COMPARISON: {
                        CompareOperatorType cop = evaluateComparison((*it));
                        assembly.conditionalJumpForwardTo(label2, false, cop);
                        break;
                    }
                    case BOOLEAN_AND_JUNCTION:
                    {
                        evaluateCondition(*(it), label1, label2);
                        break;
                    }
                    case BOOLEAN_OR_JUNCTION:
                    {
                        int label = label1+1;
                        evaluateCondition((*it), label, label2);
                        assembly.addLocalLabel(label);
                        break;
                    }
                }
            }
        }
    }
    switch(node->nodeType){
        case BOOLEAN_OR_JUNCTION:
        {
            assembly.jumpForwardTo(label2);
        }
    }
}

CompareOperatorType  CodeGenerator::evaluateComparison(Node* node){
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        dsfUtil(node);
    }
    assembly.performComparison(static_cast<CompareNode*>(node)->compareOperator);
    return static_cast<CompareNode*>(node)->compareOperator;
}

void CodeGenerator::dsfUtil(Node* node) {
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        evaluateAst((*it));
    }
}