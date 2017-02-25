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

#ifndef IMPALAJIT_ASSEMBLY_HH
#define IMPALAJIT_ASSEMBLY_HH

#include <dasm_proto.h>
#include <dasm_x86.h>
#include <types.hh>
#include <internal_types.hh>

class Assembly {

public:

    virtual void initialize(int parameterCount) = 0;

    virtual void prologue()= 0;

    virtual void epilogue()= 0;

    virtual void growPC(unsigned npc)= 0;

    virtual void pushParameterToStack(int index)= 0;

    virtual void pushLocalVariableToStack(int index)= 0;

    virtual void popStack() = 0;

    virtual void replaceParameter(int index)= 0;

    virtual void pushConstantToStack(double value)= 0;

    virtual void storeLocalVariable()= 0;

    virtual void replaceLocalVariable(int index)= 0;

    virtual void calculateAddition()= 0;

    virtual void calculateSubtraction()= 0;

    virtual void calculateMultiplication()= 0;

    virtual void calculateDivision()= 0;

    virtual void callExternalFunction(externalFunction functionPtr, unsigned NumberOfArguments)= 0;

    virtual void addDynamicLabel(unsigned labelNumber)= 0;

    virtual void addLocalLabel(unsigned labelNumber)= 0;

    virtual void jumpForwardToDynamicLabel(unsigned labelNumber)= 0;

    virtual void jumpForwardToLocalLabel(unsigned labelNumber)= 0;

    virtual void conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_)= 0;

    virtual void conditionalJumpForwardToLocalLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_)= 0;

    virtual void extractResult()= 0;

    virtual dasm_gen_func linkAndEncode()= 0;

protected:
    dasm_State* d;
    dasm_State** Dst;
    void** labels;
    int stackPos;
};

#endif //IMPALAJIT_ASSEMBLY_HH