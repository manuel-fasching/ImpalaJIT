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

    int operator_;

    Assembly();

    void addDynamicLabel1();

    void jumpForwardTo1();

    void addDynamicLabel2();

    void jumpForwardTo2();

    void conditionalJumpForwardTo1();

    void compile();

    void push(double* value);

    virtual ~Assembly();

    void* linkAndEncode();

private:
    dasm_State *d;
    void **labels;
    dasm_State **Dst;
};

#endif //IMPALAJIT_ASSEMBLY_HH