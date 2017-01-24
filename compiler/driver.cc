// $Id$
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include <driver.h>
#include <scanner.h>

namespace impalajit {

dasm_gen_func Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(false);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(false);
    parser.parse();

    assembly.initialize();
    assembly.prologue();

    expressionContext.evaluateAst();

    assembly.extractResult();
    assembly.epilogue();

    dasm_gen_func fp = assembly.linkAndEncode();
    return fp;
}

dasm_gen_func Driver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) throw (std::runtime_error("Bad input file."));
    return parse_stream(in, filename);
}

dasm_gen_func Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
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
