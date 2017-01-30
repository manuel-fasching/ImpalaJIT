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

    virtual ~Assembly();

    void initialize();

    void prologue();

    void epilogue();

    void growPC(unsigned npc);

    void pushParameterToFPUStack(int index);

    void pushLocalVariableToFPUStack(int index);

    void replaceParameter(int index);

    void pushConstantToFPUStack(double *value);

    void storeLocalVariable();

    void replaceLocalVariable(int index);

    void performNegation();

    void calculateAddition();

    void calculateSubtraction();

    void calculateMultiplication();

    void calculateDivision();

    void calculatePower();

    void calculateSQRT();

    void performComparison();

    void addDynamicLabel(unsigned labelNumber);

    void jumpForwardToDynamicLabel(unsigned labelNumber);

    void conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_);

    void extractResult();

    dasm_gen_func linkAndEncode();

private:
    dasm_State* d;
    dasm_State** Dst;
    void** labels;
};

#endif //IMPALAJIT_ASSEMBLY_HH