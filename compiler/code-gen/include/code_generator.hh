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
    Assembly assembly;
    void evaluateAst(Node *node);
    void dsfUtil(Node* node);
    void evaluateCondition(Node* node, int label1, int label2);
    CompareOperatorType  evaluateComparison(Node* node);
    class FunctionContext &functionContext;

public:
    CodeGenerator(class FunctionContext &_functionContext)
            : functionContext(_functionContext)
    {
    }
    ~CodeGenerator();
    dasm_gen_func generateCode();
};
#endif //IMPALAJIT_CODE_GENERATOR_HH
