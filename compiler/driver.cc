// $Id$
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include <driver.h>
#include <scanner.h>
#include <code_generator.hh>

namespace impalajit {

Driver::~Driver(){
    delete functionContext;
    functionContext = NULL;
}

dasm_gen_func Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(false);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(false);
    parser.parse();

    CodeGenerator codeGenerator(*functionContext);

    return codeGenerator.generateCode();
}

dasm_gen_func Driver::parse_single_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    return parse_stream(in, filename);
}

std::map<std::string, dasm_gen_func> Driver::parse_multiple_files(std::vector<std::string> &filenames)
{
    std::map<std::string, dasm_gen_func> result;

    for(std::vector<std::string>::iterator it = filenames.begin(); it != filenames.end(); ++it) {
        std::cout << (*it) << " asdf" << std::endl;
        dasm_gen_func function = parse_single_file((*it));
        result.insert(std::make_pair(functionContext->name, function));
    }
    return result;
}

dasm_gen_func Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void Driver::setFunctionContext(FunctionContext* &_functionContext){
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

std::string Driver::getName(){
    return functionContext->name;
}

} // namespace impalajit
