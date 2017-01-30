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
    std::string configPath;
    std::map<std::string, dasm_gen_func> functionMap;
public:

    Compiler(std::string configFilePath);
    Compiler();

    void compile();
    dasm_gen_func getFunction(std::string functionName);
};

typedef impalajit::Compiler impalajit_compiler;

#else
typedef struct impalajit::Compiler impalajit_compiler;

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

    void impalajit_compiler_compile(impalajit_compiler* handle);

    dasm_gen_func impalajit_compiler_get_function(char* function_name);


#ifdef __cplusplus
}
#endif

#endif