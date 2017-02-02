//
// Created by manuel on 30.01.17.
//

#ifndef IMPALAJIT_SEM_ANALYSIS_HH
#define IMPALAJIT_SEM_ANALYSIS_HH

#include <function_context.h>

class SemanticAnalyzer {
private:
    unsigned assignmentCount;
    void evaluateAst(FunctionContext* &functionContext, Node* &node);
    void dsfUtil(FunctionContext* &functionContext, Node* &node);
public:
    ~SemanticAnalyzer();
    void performSemanticAnalysis(FunctionContext* &functionContext);
};
#endif //IMPALAJIT_SEM_ANALYSIS_HH
