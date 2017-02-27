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

#ifndef IMPALAJIT_ASSEMBLY_AVX_HH
#define IMPALAJIT_ASSEMBLY_AVX_HH

#include <assembly.hh>

/**
 * This class generates VEX encoded assembly.
 * It utilizes AVX instructions
 *
 * @see Assembly
 */
class Assembly__AVX : public Assembly {
public:

    /**
     * Destructor. Calls the cleanup function of dynasm.
     */
    virtual ~Assembly__AVX();

    /**
     * @see assembly.hh
     */
    virtual void initialize(int parameterCount) ;

    /**
     * @see assembly.hh
     */
    virtual void prologue();

    /**
     * @see assembly.hh
     */
    virtual void epilogue();

    /**
     * @see assembly.hh
     */
    virtual void growPC(unsigned npc);

    /**
     * @see assembly.hh
     */
    virtual void pushParameterToStack(int index);

    /**
     * @see assembly.hh
     */
    virtual void pushLocalVariableToStack(int index);

    /**
     * @see assembly.hh
     */
    virtual void replaceParameter(int index);

    /**
     * @see assembly.hh
     */
    virtual void pushConstantToStack(double value);

    /**
     * @see assembly.hh
     */
    virtual void storeLocalVariable();

    /**
     * @see assembly.hh
     */
    virtual void replaceLocalVariable(int index);

    /**
     * @see assembly.hh
     */
    virtual void calculateAddition();

    /**
     * @see assembly.hh
     */
    virtual void calculateSubtraction();

    /**
     * @see assembly.hh
     */
    virtual void calculateMultiplication();

    /**
     * @see assembly.hh
     */
    virtual void calculateDivision();

    /**
     * @see assembly.hh
     */
    virtual void callExternalFunction(externalFunction functionPtr, unsigned NumberOfArguments);

    /**
     * @see assembly.hh
     */
    virtual void addDynamicLabel(unsigned labelNumber);

    /**
     * @see assembly.hh
     */
    virtual void jumpForwardToDynamicLabel(unsigned labelNumber);

    /**
     * @see assembly.hh
     */
    virtual void conditionalJumpForwardToDynamicLabel(unsigned labelNumber, bool condition, CompareOperatorType operator_);

    /**
     * @see assembly.hh
     */
    virtual void extractResult();

    /**
     * @see assembly.hh
     */
    virtual dasm_gen_func linkAndEncode();
};

#endif //IMPALAJIT_ASSEMBLY_AVX_HH