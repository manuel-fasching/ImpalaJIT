//
// Created by manuel on 22.11.16.
//

#include <impalajit.hh>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <node.h>
#include <driver.h>

impalajit::Driver driver;

impalajit::Compiler::Compiler() {
}

impalajit::Compiler::Compiler(std::string _configFilePath) {
    std::ifstream fin(_configFilePath.c_str());
    if(!fin.good()) {
        fin.close();
        throw std::runtime_error("Bad configuration file");
    }
    fin.close();
    configFilePath = _configFilePath;

}

dasm_gen_func impalajit::Compiler::compile(){
    std::string line;
    std::ifstream fin(configFilePath.c_str());
    getline(fin, line);
    fin.close();
    return driver.parse_single_file(line);
}
std::map<std::string, dasm_gen_func> impalajit::Compiler::compileMultipleFunctions(){
    std::vector<std::string> v;
    std::string line;
    std::ifstream fin(configFilePath.c_str());
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
    return driver.parse_multiple_files(v);
}

//C Interface

impalajit_compiler *impalajit_compiler_create() {
    return new impalajit::Compiler();
}

impalajit_compiler *impalajit_compiler_create_with_config(char* config_file_path) {
    return new impalajit::Compiler(std::string (config_file_path));
}

dasm_gen_func impalajit_compiler_compile(impalajit_compiler *handle) {
    handle->compile();
}

c_function_map* impalajit_compiler_compile_multiple_functions(impalajit_compiler *handle) {
    std::map<std::string, dasm_gen_func> cpp_result = handle->compileMultipleFunctions();
    c_function_map* map = (c_function_map*) malloc(sizeof(c_function_map)*cpp_result.size());
    int i=0;
    for(std::map<std::string, dasm_gen_func>::iterator it = cpp_result.begin(); it != cpp_result.end(); ++it) {
        map[i].key=(*it).first.c_str();
        map[i].value=(*it).second;
        i++;
    }
    return map;
}