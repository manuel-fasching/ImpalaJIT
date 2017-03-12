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

#ifndef IMPALAJIT_H
#define IMPALAJIT_H

#define ENV_VARIABLE_NAME "IMPALA_FILE"

#include <string>
#include <impalajit/types.hh>
#include <map>
#include <vector>

#ifdef __cplusplus



namespace impalajit{
    class Compiler;
}
class impalajit::Compiler{
private:
    std::vector<std::string> functionDefinitions;
    std::map<std::string, dasm_gen_func> functionMap;

    void loadFunctionDefinitionsFromInputFiles(std::string _configPath);
public:

    Compiler(std::string _configFilePath);
    Compiler(std::vector<std::string> _functionDefinitions);
    Compiler();

    void compile();
    dasm_gen_func getFunction(std::string functionName);

    void close();
};

typedef impalajit::Compiler impalajit_compiler;

#else
typedef struct impalajit::Compiler impalajit_compiler;

#endif

//C Interface

#ifdef __cplusplus
extern "C" {
#endif

    impalajit_compiler * impalajit_compiler_create();

    impalajit_compiler * impalajit_compiler_create_with_config(const char* config_file_path);

    impalajit_compiler *impalajit_compiler_create_with_function_definitions(char** function_definitions);

    void impalajit_compiler_compile(impalajit_compiler* handle);

    dasm_gen_func impalajit_compiler_get_function(impalajit_compiler *handle, const char* function_name);

    void impalajit_compiler_close(impalajit_compiler* handle);


#ifdef __cplusplus
}
#endif

#endif