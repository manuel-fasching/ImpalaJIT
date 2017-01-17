#ifndef IMPALAJIT_H
#define IMPALAJIT_H

#define ENV_VARIABLE_NAME "IMPALA_FILE"

#include <string>
#include "impalajit/types.hh"

#ifdef __cplusplus

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

    virtual ~Compiler(){}

    virtual Error setVariable(std::string name, double value);
    virtual void clearVariables();

    virtual dasm_gen_func compile();
};

typedef impalajit::Compiler impalajit_compiler;
typedef impalajit::Compiler::Error impalajit_error;

#else
typedef struct impalajit::Compiler impalajit_compiler;
typedef enum {
    IMPALAJIT_SUCCESS = 0,
    IMPALAJIT_NO_IMPALAFILE_SPECIFIED,
    IMPALAJIT_BAD_INPUT_FILE,
    IMPALAJIT_COMPILATION_ERROR,
    IMPALAJIT_EMPTY_VARIABLE_NAME,
    IMPALAJIT_EMPTY_VARIABLE_BUFFER
} impalajit_error;
#endif

#ifdef __cplusplus
extern "C" {
#endif

    impalajit_compiler * impalajit_compiler_create();

    impalajit_error impalajit_compiler_set_variable(impalajit_compiler* handle, const char name[], double value);
    void impalajit_compiler_clear_variables(impalajit_compiler* handle);

    dasm_gen_func impalajit_compiler_compile(impalajit_compiler* handle);

#ifdef __cplusplus
}
#endif

#endif