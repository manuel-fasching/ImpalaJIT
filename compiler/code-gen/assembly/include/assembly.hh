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
/**
 * Base class for assembly implementations. Child classes
 * should implement these functions for different architectures.
 */
class Assembly {

public:

    /**
     * Initializes the dynasm context
     * @param parameterCount The amount of passed parameters
     */
     virtual void initialize(int parameterCount) = 0;

    /**
     * First assembly instruction in function.
     * Usually something like:
     *  push rbp
     *  mov rbp, rsp
     *  This sets up our stack frame
     *
     * @param parameterCount The amount of passed parameters
     */
     virtual void prologue()= 0;

    /**
     * Restore the original base and frame pointer.
     * This is required, since the caller function probably wants to proceed.
     * Basically it reverts the things made in prologue
     */
    virtual void epilogue()= 0;

    /**
     * Dynamically increase the amount of available dynamic labels
     * This function can be called multiple times.
     *
     * @param npc The new amount of available dynamic lables
     */
    virtual void growPC(unsigned npc)= 0;

    /**
     * Pushes a parameter onto the rpn stack.
     * TODO: Rename to avoid confusion with call stack
     *
     * @param index The index of the parameter
     */
    virtual void pushParameterToStack(int index)= 0;

    /**
     * Pushes a local variable onto the rpn stack.
     * TODO: Rename to avoid confusion with call stack
     *
     * @param index The index of the variable
     */
    virtual void pushLocalVariableToStack(int index)= 0;

    /**
     * Replaces the value of an parameter.
     *
     * @param index The index of the parameter
     */
    virtual void replaceParameter(int index)= 0;

    /**
     * Pushes a constant value onto the rpn stack.
     * This function will allocate memory space for the
     * constant.
     *
     * @param value The constant value
     */
    virtual void pushConstantToStack(double value)= 0;

    /**
     * Pushes the top value of the rpn stack onto the call stack.
     */
    virtual void storeLocalVariable()= 0;

    /**
     * Replaces the value of a local variable
     *
     * @param index The index of the variable
     */
    virtual void replaceLocalVariable(int index)= 0;

    /**
     * Performs a simple addition.
     */
    virtual void calculateAddition()= 0;

    /**
     * Performs a simple addition.
     */
    virtual void calculateSubtraction()= 0;

    /**
     * Performs a simple multiplication.
     */
    virtual void calculateMultiplication()= 0;

    /**
     * Performs a simple division.
     */
    virtual void calculateDivision()= 0;

    /**
     * Function call. Arguments are passed in register xmm0 - xmm(numberOfArguments-1)
     * Due to this function the -mno-red-zone flag is necessary.
     * GNU (and maybe intel, did not check) considers us as a leaf function. So, the "red-zone"
     * optimization is true for us. This would prevent us from calling other functions.
     * TODO: Currently only 8 arguments can be passed. Additional arguments must be added to the call stack
     * TODO: Check if the "red-zone" optimization can be disabled for functions
     *
     * @param functionPtr pointer to function which should get called
     * @param numberOfArguments number of arguments which should get passed to called function
     */
    virtual void callExternalFunction(externalFunction functionPtr, unsigned NumberOfArguments)= 0;

    /**
     * Adds a dynamic label
     * @param labelNumber
     */
    virtual void addDynamicLabel(unsigned labelNumber)= 0;

    /**
     * Compares the top 2 values of the rpn stack and performs a conditional jump to the specified label.
     * This is used for if else statements
     *
     * @param labelNumber the number of the dynamic label
     * @param condition wheter the condition must be true or false
     * @param operator_ compare operator. Currently implemented: GT, LT, EQ, NE, GTE, LTE
     */
    virtual void conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_)= 0;

    /**
     * Put execution result to register xmm0.
     * According to x64 calling conventions the return value of a function is expected in reg xmm0.
     */
    virtual void extractResult()= 0;

    /**
     * Generate machine executable code
     *
     * @return  A pointer to the machine executable code
     */
    virtual dasm_gen_func linkAndEncode()= 0;

protected:
    dasm_State* d;
    dasm_State** Dst;
    void** labels;
    int stackPos;   // The head of the rpn stack
};

#endif //IMPALAJIT_ASSEMBLY_HH