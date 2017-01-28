//
// Created by manuel on 27.01.17.
//

#ifndef IMPALAJIT_CODE_GENERATOR_HH
#define IMPALAJIT_CODE_GENERATOR_HH

#include <types.hh>
#include <function_context.h>
#include <vector>
#include <assembly.hh>

class CodeGenerator {
private:
    unsigned dynamicLabelCount;
    Assembly assembly;
    void evaluateAst(Node *node);
    void dsfUtil(Node* node);
    void conditionEvaluationHelper(Node *node, unsigned label1, unsigned label2);
    unsigned countLabels(Node* node);
    CompareOperatorType  comparisonEvaluationHelper(Node *node);
    class FunctionContext &functionContext;

public:
    CodeGenerator(class FunctionContext &_functionContext);
    ~CodeGenerator();
    dasm_gen_func generateCode();
};
#endif //IMPALAJIT_CODE_GENERATOR_HH
