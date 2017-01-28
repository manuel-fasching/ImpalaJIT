//
// Created by manuel on 06.11.16.
//

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