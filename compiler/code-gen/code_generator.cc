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
#include <assignment_nodes.h>
#include <compare_nodes.h>
#include <external_function_nodes.h>
#include <calculation_helper.hh>
#include <ptr_map_container.hh>
#include <stdexcept>




/**
 * @see ptr_map_container.hh
 */
std::map<std::string, externalFunction> FunctionPtrMap::map;

/**
 * @see code_generator.hh
 */
CodeGenerator::CodeGenerator() {
    dynamicLabelCount = 0;
}

/**
 * @see code_generator.hh
 */
CodeGenerator::~CodeGenerator()
{
}

/**
 * @see code_generator.hh
 */
dasm_gen_func CodeGenerator::generateCode(FunctionContext* &functionContext)
{
    FunctionPtrMap::initialize_map();
    assembly.initialize(functionContext->parameters.size());
    assembly.prologue();

    assembly.reserveMemoryForLocalVariables(functionContext->variables.size());

    evaluateAst(functionContext, functionContext->root);

    return assembly.linkAndEncode();
}

/**
 * @see code_generator.hh
 */
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
            dsfUtil(functionContext, node);
            if(functionContext->containsVariable(static_cast<VariableNode*>(node)->name)) {
                assembly.pushLocalVariableToStack(functionContext->getIndexOfVariable(static_cast<VariableNode*>(node)->name));
                break;
            }
            else if(functionContext->containsParameter(static_cast<VariableNode*>(node)->name)) {
                assembly.pushParameterToStack(functionContext->getIndexOfParameter(static_cast<VariableNode*>(node)->name));
                break;
            }
            else{
                throw std::runtime_error("Variable not found!");
            }
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
            if(functionContext->containsVariable(static_cast<AssignmentNode*>(node)->name)) {
                assembly.storeLocalVariable(functionContext->getIndexOfVariable(static_cast<VariableNode*>(node)->name));
                break;
            }
            else if(functionContext->containsParameter(static_cast<AssignmentNode*>(node)->name)) {
                assembly.replaceParameter(functionContext->getIndexOfParameter(static_cast<AssignmentNode*>(node)->name));
                break;
            }
            else{
                throw std::runtime_error("Variable was not found in semantic analysis phase!");
            }
        }

        case IF_STATEMENT:
        {
            unsigned labelDemand = (2 + countLabels(node->nodes.at(0))); // Two labels for me, and x for my children
            unsigned label1 = dynamicLabelCount; // The first new label number is the current overall count.
            dynamicLabelCount += labelDemand;
            unsigned label2 = dynamicLabelCount-1; // The  bad label has the highest number.
            // The first child will get label1+1 as good label and label2-1 as bad label

            assembly.growPC(dynamicLabelCount); // Now dynamically increase the number of available labels

            conditionEvaluationHelper(functionContext, node->nodes.at(0), label1, label2); // Evaluate the condition
            assembly.addDynamicLabel(label1); // Place the good label
            dsfUtil(functionContext, node->nodes.at(1)); // Place the if body
            assembly.addDynamicLabel(label2); // Place the bad label
            break;
        }
        case IF_ELSE_STATEMENT:
        {
            unsigned labelDemand = (3 + countLabels(node->nodes.at(0))); // Three labels for me (since I also carry an else part), and x for my children
            unsigned label1 = dynamicLabelCount;    // The first new label number is the current overall count.
            dynamicLabelCount += labelDemand;
            unsigned label2 = dynamicLabelCount-2; // The  bad label has the second highest number.
            unsigned label3 = dynamicLabelCount-1; // The  exit label has the highest number.
            assembly.growPC(dynamicLabelCount); // Now dynamically increase the number of available labels

            conditionEvaluationHelper(functionContext, node->nodes.at(0), label1, label2); // Evaluate the condition

            assembly.addDynamicLabel(label1); // Place the good label
            dsfUtil(functionContext, node->nodes.at(1)); // Place the if body
            assembly.jumpForwardToDynamicLabel(label3); // Jump forward to the exit label, if "if" was executed
            assembly.addDynamicLabel(label2); // Place the bad label
            dsfUtil(functionContext, node->nodes.at(2)); // Place the if body
            assembly.addDynamicLabel(label3); // Add the exit label
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

/**
 * @see code_generator.hh
 */
void CodeGenerator::dsfUtil(FunctionContext* &functionContext, Node* &node) {
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        evaluateAst(functionContext, (*it));
    }
}

/**
 * @see code_generator.hh
 */
unsigned CodeGenerator::countLabels(Node* node){
    unsigned labels = 0;
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {

        // A new label is only needed when I am an OR Junction and my child is an AND Junction or vice versa.
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

        // And I have to check this for my childs, too. Of course.
        labels += countLabels((*it));
    }
    return labels;
}

/**
 * @see code_generator.hh
 */
void CodeGenerator::conditionEvaluationHelper(FunctionContext* &functionContext, Node* &node, unsigned label1, unsigned label2){
    // Ok, let's start. I am a condition or a boolean junction. Check all my childs. These could either be also boolean junctions, or I only carry
    // a simple comparison. e.g. (x==y) && (a==b)     or    (x==y)
    for(std::vector<Node*>::iterator it = node->nodes.begin(); it != node->nodes.end(); ++it) {
        switch(node->nodeType)
        {
            case COMPARISON:
            {
                // I am a compare node. Ok, evaluate my expressions and place a conditionally jump statement
                // Max recursion depth reached
                dsfUtil(functionContext, node);
                assembly.conditionalJumpForwardToDynamicLabel(label2, false, static_cast<CompareNode*>(node)->compareOperator);
                break;
            }
            // I am a boolean or junction. This is true for the whole loop.
            case BOOLEAN_OR_JUNCTION:
            {
                //Ok, now I have to check the type of the currently traversed child.
                switch((*it)->nodeType){

                    // My Child is a comparison
                    case COMPARISON:
                    {
                        // Evaluate it's expressions and place a conditionally jump statement.
                        // Max recursion depth reached
                        dsfUtil(functionContext, *it);
                        assembly.conditionalJumpForwardToDynamicLabel(label1, true, static_cast<CompareNode*>(*it)->compareOperator);
                        break;
                    }

                    // My Child is an OR Junction
                    case BOOLEAN_OR_JUNCTION:
                    {
                        // Ok, OR junctions must evaluate all conditions. No need to jump here.
                        conditionEvaluationHelper(functionContext, (*it), label1, label2);
                        break;
                    }

                    // My child is an AND Junction
                    case BOOLEAN_AND_JUNCTION:
                    {
                        // Well, Adapt label numbers and call the evaluation helper again.
                        conditionEvaluationHelper(functionContext, (*it), label1, label2-1);

                        // This is executed, when any AND condition was true. Jump to the good label :)
                        assembly.jumpForwardToDynamicLabel(label1);

                        // And also place a bad label, where my children can jump to.
                        assembly.addDynamicLabel(label2-1);
                        break;
                    }
                }
                break;
            }

            // I am a boolean and junction. This is true for the whole loop.
            // Read the comment in line 295 again. Now you got it, right?
            case BOOLEAN_AND_JUNCTION:
            {
                //Again, now I have to check the type of the currently traversed child.
                switch((*it)->nodeType) {
                    // In case it is a comparison: Jump to the bad label, if the comparison is false...remember - I'm an
                        // AND junction. All conditions must be true.
                    case COMPARISON: {
                        dsfUtil(functionContext, *it);
                        assembly.conditionalJumpForwardToDynamicLabel(label2, false, static_cast<CompareNode*>(*it)->compareOperator);
                        break;
                    }

                    // Ok, my child is also a boolean AND Junction. No need to place a label. e.g. (A && (B && C)) = ( A && B && C)
                    case BOOLEAN_AND_JUNCTION:
                    {
                        conditionEvaluationHelper(functionContext, (*it), label1, label2);
                        break;
                    }

                    // My child is a boolean OR Junction. Evaluate the child and place a good label.
                    case BOOLEAN_OR_JUNCTION:
                    {
                        conditionEvaluationHelper(functionContext, (*it), label1+1, label2);
                        assembly.addDynamicLabel(label1+1);
                        break;
                    }
                }
            }
        }

        // If I am a comparison we can break the loop. All children were evaluated, and nothing more to do.
        if(node->nodeType == COMPARISON)
            break;
    }
    // After all we must place a bad label, in case I'm an OR junction. My children need a label to jump to, when nothing was true.
    if(node->nodeType == BOOLEAN_OR_JUNCTION)
            assembly.jumpForwardToDynamicLabel(label2);
}