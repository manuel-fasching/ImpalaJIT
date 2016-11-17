//
// Created by manuel on 06.11.16.
//

#ifndef IMPALAJIT_ASSEMBLY_HH
#define IMPALAJIT_ASSEMBLY_HH

#include <dasm_proto.h>
#include <dasm_x86.h>
#include <stack>

class Assembly {

public:
    static const int EMPTY = -1;
    static const int IDENTITY = 0;
    static const int ADD = 1;
    static const int SUB = 2;
    static const int MUL = 3;
    static const int DIV = 4;
    static const int NEG = 5;

    std::stack<double*> operandStack;
    int operator_;


    Assembly();

    void compile();

    virtual ~Assembly();

    void* linkAndEncode();

private:
    dasm_State *d;
    void **labels;
    dasm_State **Dst;
};

#endif //IMPALAJIT_ASSEMBLY_HH