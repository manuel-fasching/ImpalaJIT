#ifndef IMPALAJIT_H
#define IMPALAJIT_H

#define ENV_VARIABLE_NAME "IMPALA_FILE"

#include <string>
#include "impalajit/types.hh"
#include <map>

#ifdef __cplusplus

namespace impalajit{
    class Compiler;
}
class impalajit::Compiler{
private:
    std::string configFilePath;
public:
    enum Error {
        SUCCESS,
        NO_IMPALAFILE_SPECIFIED,
        BAD_INPUT_FILE,
        COMPILATION_ERROR,
        EMPTY_VARIABLE_NAME,
        EMPTY_VARIABLE_BUFFER
    };

    Compiler(std::string configFilePath);
    Compiler();

    dasm_gen_func compile();
    std::map<std::string, dasm_gen_func> compileMultipleFunctions();
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

//C Interface

#ifdef __cplusplus
extern "C" {
#endif
    typedef struct
    {
        const char* key;
        dasm_gen_func value;
    } c_function_map;

    impalajit_compiler * impalajit_compiler_create();

    impalajit_compiler * impalajit_compiler_create_with_config(char* config_file_path);

    dasm_gen_func impalajit_compiler_compile(impalajit_compiler* handle);

    c_function_map* impalajit_compiler_compile_multiple_functions(impalajit_compiler* handle);

#ifdef __cplusplus
}
#endif

#endif