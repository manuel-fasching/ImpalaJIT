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

#include <impalajit.hh>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <node.h>
#include <driver.h>

impalajit::Driver driver;

impalajit::Compiler::Compiler() {
}

impalajit::Compiler::Compiler(std::string _configPath) {
    std::ifstream fin(_configPath.c_str());
    if(!fin.good()) {
        fin.close();
        throw std::runtime_error("Bad configuration file");
    }
    fin.close();
    configPath = _configPath;

}

void impalajit::Compiler::compile(){
    std::vector<std::string> v;
    std::string line;
    std::ifstream fin(configPath.c_str());
    while(getline(fin,line)) {
        if (line.empty()){
            continue;
        }
        else if(line.find (' ') != line.npos) {
            continue;
        }
        else if(line.find('\t') != line.npos){
            continue;
        }
        v.push_back(line);
    }
    fin.close();

    for(std::vector<std::string>::iterator it = v.begin(); it != v.end(); ++it) {
        dasm_gen_func function = driver.parse_file((*it));
        std::cout << "function name: " << driver.getFunctionName() << std::endl;
        functionMap.insert(std::make_pair(driver.getFunctionName(), function));
    }
}

dasm_gen_func impalajit::Compiler::getFunction(std::string functionName) {
    if(functionMap.find(functionName) == functionMap.end()){
        throw std::runtime_error("Function \""+functionName+"\" not found");
    }
    return functionMap.at(functionName);
}

//C Interface

impalajit_compiler *impalajit_compiler_create() {
    return new impalajit::Compiler();
}

impalajit_compiler *impalajit_compiler_create_with_config(char* config_file_path) {
    return new impalajit::Compiler(std::string (config_file_path));
}

void impalajit_compiler_compile(impalajit_compiler *handle) {
    handle->compile();
}

dasm_gen_func impalajit_compiler_get_function(impalajit_compiler *handle, char* function_name){
    return handle->getFunction(std::string(function_name));
}

