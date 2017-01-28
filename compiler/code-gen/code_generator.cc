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

        case COMPARISON:
        {
            dsfUtil(node);
            assembly.performComparison(static_cast<CompareNode*>(node)->compareOperator);
            break;
        }

        case BOOLEAN_JUNCTION:
        {
            break;
        }
        case IF_STATEMENT:
        {
            break;
        }
        case IF_ELSE_STATEMENT:
        {
            break;
        }
        case IF_BODY:
        {
            break;
        }
        case ELSE_BODY:
        {
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