// $Id$
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include <driver.h>
#include <scanner.h>
#include <expression.h>

namespace impalajit {

Driver::Driver(class ExpressionContext& _expressionContext)
    : trace_scanning(false),
      trace_parsing(false),
      expressionContext(_expressionContext)
{
}

double Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(trace_parsing);
    parser.parse();
    for (unsigned int ei = 0; ei < expressionContext.expressions.size(); ++ei) {
        expressionContext.expressions[ei]->evaluate();
    }
    dasm_gen_func fp = (dasm_gen_func)(expressionContext.assembly.linkAndEncode());
    return fp();
}

double Driver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

double Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void Driver::error(const class location& l,
		   const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}

} // namespace impalajit
