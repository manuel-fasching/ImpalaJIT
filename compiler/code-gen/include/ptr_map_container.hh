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

#ifndef IMPALAJIT_EXTERNAL_FUNCTION_DEFINITION_HH
#define IMPALAJIT_EXTERNAL_FUNCTION_DEFINITION_HH

#include <math.h>
#include <internal_types.hh>
#include <calculation_helper.hh>

/**
 * Container class for a static map of function pointers. The map acts
 * as a lookup table for function names, which are available in impala files.
 * A table base approach is necessary, since C++ does not support reflection.
 */
class FunctionPtrMap{
public:
    static std::map<std::string, externalFunction> map;

    /**
     * Initializes the map with function pointers and their names.
     * Add additional function HERE
     */
    static void initialize_map() {
            map["cos"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(cos));
            map["sin"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(sin));
            map["tan"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(tan));
            map["acos"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(acos));
            map["asin"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(asin));
            map["atan"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(atan));
            map["atan2"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double,double)>(atan2));
            map["cosh"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(cosh));
            map["sinh"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(sinh));
            map["tanh"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(tanh));
            map["exp"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(exp));
            map["log"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(log));
            map["log10"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(log10));
            map["pow"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double,double)>(pow));
            map["sqrt"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(sqrt));
            map["min"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double,double)>(fmin));
            map["max"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double,double)>(fmax));
            map["abs"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(fabs));
            map["floor"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(floor));
            map["ceil"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(ceil));
            map["round"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(round));
            map["erf"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(erf));
            map["erfc"] = reinterpret_cast<externalFunction>(static_cast<double(*)(double)>(erfc));
    }
private:
    /**
     * Avoid contruction
     * @return FunctionPointer
     */
    FunctionPtrMap() {
    }
};

#endif //IMPALAJIT_EXTERNAL_FUNCTION_DEFINITION_HH
