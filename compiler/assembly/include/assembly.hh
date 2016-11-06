//
// Created by manuel on 06.11.16.
//

#ifndef IMPALAJIT_ASSEMBLY_HH
#define IMPALAJIT_ASSEMBLY_HH

#include <dasm_proto.h>
#include <dasm_x86.h>

class Assembly {

public:
    Assembly();

    dasm_State *getValue(double *value);

    virtual ~Assembly();

private:
    dasm_State *d;
    void **labels;
    dasm_State **Dst;
};

#endif //IMPALAJIT_ASSEMBLY_HH