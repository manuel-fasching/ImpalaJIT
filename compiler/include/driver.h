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

#ifndef IMPALAJIT_DRIVER_H
#define IMPALAJIT_DRIVER_H



#include <string>
#include <map>
#include <vector>

#include <function_context.h>
#include <types.hh>


namespace impalajit {

class Driver
{
private:
    FunctionContext* functionContext;
public:

    ~Driver();

    class Scanner* lexer;

    std::map<std::string,dasm_gen_func> parse_stream(std::istream& in);

    std::map<std::string,dasm_gen_func> parse_string(const std::string& input);

    void setFunctionContext(FunctionContext* _functionContext);

    void error(const class location& l, const std::string& m);

    void error(const std::string& m);
};

} // namespace impalajit

#endif // IMPALAJIT_DRIVER_H
