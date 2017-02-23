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

#ifndef IMPALAJIT_ASSEMBLY_SSE_4_1_HH
#define IMPALAJIT_ASSEMBLY_SSE_4_1_HH

#include <assembly.hh>

class Assembly__SSE_4_1 : public Assembly {
public:
    virtual ~Assembly__SSE_4_1();

    virtual void initialize(int parameterCount);

    virtual void prologue();

    virtual void epilogue();

    virtual void growPC(unsigned npc);

    virtual void pushParameterToStack(int index);

    virtual void pushLocalVariableToStack(int index);

    virtual void replaceParameter(int index);

    virtual void pushConstantToStack(double value);

    virtual void popStack();

    virtual void storeLocalVariable();

    virtual void replaceLocalVariable(int index);

    virtual void calculateAddition();

    virtual void calculateSubtraction();

    virtual void calculateMultiplication();

    virtual void calculateDivision();

    virtual void callExternalFunction(externalFunction functionPtr, unsigned NumberOfArguments);

    virtual void addDynamicLabel(unsigned labelNumber);

    virtual void addLocalLabel(unsigned labelNumber);

    virtual void jumpForwardToDynamicLabel(unsigned labelNumber);

    virtual void jumpForwardToLocalLabel(unsigned labelNumber);

    virtual void conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_);

    virtual void conditionalJumpForwardToLocalLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_);

    virtual void extractResult();

    virtual dasm_gen_func linkAndEncode();
};

#endif //IMPALAJIT_ASSEMBLY_SSE_4_1_HH