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


#include <fstream>
#include <sstream>

#include <driver.h>
#include <scanner.h>
#include <code_generator.hh>

namespace impalajit {

Driver::~Driver(){
}

std::map<std::string,dasm_gen_func> Driver::parse_stream(std::istream& in)
{
    Scanner scanner(&in);
    scanner.set_debug(false);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(false);
    parser.parse();

    CodeGenerator codeGenerator;
    dasm_gen_func function = codeGenerator.generateCode(functionContext);

    std::map<std::string,dasm_gen_func> resultMap;
    resultMap.insert(std::make_pair(functionContext->name, function));

    delete functionContext;
    functionContext = NULL;
    return resultMap;
}

std::map<std::string,dasm_gen_func> Driver::parse_string(const std::string &input)
{
    std::istringstream iss(input);
    return parse_stream(iss);
}

void Driver::setFunctionContext(FunctionContext* _functionContext){
    functionContext = _functionContext;
}

void Driver::error(const class location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}


void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}

} // namespace impalajit
