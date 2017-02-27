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

#ifndef IMPALAJIT_CODE_GENERATOR_HH
#define IMPALAJIT_CODE_GENERATOR_HH

#include <types.hh>
#include <internal_types.hh>
#include <function_context.h>
#include <vector>
#include <map>
#include <assembly__avx.hh>
#include <assembly__sse_4_1.hh>
#include <cmath>

/**
 * This class traverses the AST and calls appropriate functions in the
 * impalajit assembly layer.
 */
class CodeGenerator {
private:
    unsigned dynamicLabelCount; // Global count of assigned

    // Initialize the right assembly class based on preprocessor directives
#if defined(__AVX__)
    Assembly__AVX assembly;
#elif defined(__SSE2__)
    Assembly__SSE_4_1 assembly;
#endif

    /**
     * This functions performs the depth-first search algorithm.
     * Each Node of the AST carries a type.
     * The big switch statement is ugly, I know. In terms of code style and
     * it would be better to add an evaluate function to the ast nodes and call
     * it recursively.
     *
     * However, the label numbers in conditionals depend on the state of caller nodes.
     * This means, an evaluate() function of conditional nodes would have to take labels
     * as arguments and would hence differ from other nodes, which makes
     * a clean inherited node structure difficult. The label placement would be also more difficult.
     *
     * I also tried it with pointers...don't do it, it's a mess.
     *
     * TODO: Devlop a clean concept, which solves all problems.
     *
     * @param functionContext The function context, which carries the ast
     * @param node The currently visited node.
     */
    void evaluateAst(FunctionContext* &functionContext, Node* &node);

    /**
     * Simple helper function which calls evaluateAst for all child nodes
     *
     * @param functionContext The function context, which carries the ast
     * @param node The currently visited node.
     */
    void dsfUtil(FunctionContext* &functionContext, Node* &node);

    /**
     * Helper function for conditional nodes. Places lables and jumps, based
     * on ast structure. This is also true for nested if else statements.
     * It needs two labels: One where it jumps to, if the condition is true,
     * and one if it's false.
     *
     * @param functionContext The function context, which carries the ast
     * @param node The currently visited node.
     * @param label1 The good label. (condition == True)
     * @param label2 The bad label. (condition ==False)
     */
    void conditionEvaluationHelper(FunctionContext* &functionContext, Node* &node, unsigned label1, unsigned label2);

    /**
     * This function counts the amount of labels, which is required by an
     * conditional node. This number is needed in advance, since the number
     * of available labels are increased dynamically for performance reasons.
     *
     * @param node The conditional node
     * @return the required amount of labels
     */
    unsigned countLabels(Node* node);

public:
    /**
     * Constructor. Initializes the dynamic label count;
     */
    CodeGenerator();

    /**
     * Destructor
     */
    ~CodeGenerator();

    /**
     * This function calls the assembly prologue and starts evaluation
     * the ast. Afterwards it extracts the functions.
     *
     * @param functionContext The function context, which carries the ast
     * @return the function pointer
     */
    dasm_gen_func generateCode(FunctionContext* &functionContext);
};
#endif //IMPALAJIT_CODE_GENERATOR_HH
