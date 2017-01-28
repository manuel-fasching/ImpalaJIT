//
// Created by manuel on 27.01.17.
//

#ifndef IMPALAJIT_AST_TYPES_HH
#define IMPALAJIT_AST_TYPES_HH

enum NodeType {
    ROOT,
    CONSTANT,
    VARIABLE,
    NEGATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER,
    SQRT,
    ASSIGNMENT,
    COMPARISON,
    BOOLEAN_JUNCTION,
    IF_STATEMENT,
    IF_ELSE_STATEMENT,
    IF_BODY,
    ELSE_BODY,
    RETURN
};

enum CompareOperatorType{
    EQ, NE, GT, LT, GTE, LTE
};

enum BooleanJunctionType{
    AND, OR
};

#endif //IMPALAJIT_AST_TYPES_HH
