#ifndef IMPALAJIT_H
#define IMPALAJIT_H

#define ENV_VARIABLE_NAME "IMPALA_FILE"


#include <string>

typedef double (*dasm_gen_func)();

namespace impalajit{
    class Compiler;
}

class impalajit::Compiler{

public:
    enum Error {
        SUCCESS = 0,
        NO_IMPALAFILE_SPECIFIED,
        BAD_INPUT_FILE,
        COMPILATION_ERROR,
        EMPTY_VARIABLE_NAME,
        EMPTY_VARIABLE_BUFFER
    };

    typedef Error impalajit_error;


    virtual ~Compiler(){}

    virtual impalajit_error setVariable(std::string name, double value);
    virtual void clearVariables();

    virtual dasm_gen_func compile();
};

#endif