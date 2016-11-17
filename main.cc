// $Id$

#include <iostream>
#include <fstream>

#include <driver.h>
#include <expression.h>

int main(int argc, char *argv[])
{
    ExpressionContext expressionContext;
    impalajit::Driver driver(expressionContext);
    bool readfile = false;

    for(int ai = 1; ai < argc; ++ai)
    {
        if (argv[ai] == std::string ("-p")) {
            driver.trace_parsing = true;
        }
        else if (argv[ai] == std::string ("-s")) {
            driver.trace_scanning = true;
        }
        else
        {
            // read a file with expressions

            std::ifstream infile(argv[ai]);
            if (!infile.good())
            {
                std::cerr << "Could not open file: " << argv[ai] << std::endl;
                return 0;
            }

            expressionContext.clearExpressions();
            double result = driver.parse_file(argv[ai]);
            printf("Result: %f", result);
        }
    }

    return 0;
}