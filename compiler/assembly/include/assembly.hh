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
    static const int SQRT = 6;
    static const int POW = 7;

    static const int GT = 8;
    static const int LT = 9;
    static const int GTE = 10;
    static const int LTE = 11;
    static const int EQ = 12;
    static const int NE = 13;

    static const int AND = 14;
    static const int OR = 15;


    int operator_;

    Assembly();

    void addLocalLabel(int labelNumber);

    void jumpForwardTo(int labelNumber);

    void jumpBackwardTo(int labelNumber);

    void conditionalJumpForwardTo(int labelNumber, bool condition);

    void conditionalJumpBackwardTo(int labelNumber, bool condition);

    void compile();

    void push(double* value);

    double* pull();

    virtual ~Assembly();

    void* linkAndEncode();

private:
    dasm_State *d;
    void **labels;
    dasm_State **Dst;
};

#endif //IMPALAJIT_ASSEMBLY_HH