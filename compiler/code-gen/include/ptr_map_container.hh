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
            map["pow"] = reinterpret_cast<externalFunction>(pow);
            map["sqrt"] = reinterpret_cast<externalFunction>(sqrt);
            map["min"] = reinterpret_cast<externalFunction>(fmin);
            map["max"] = reinterpret_cast<externalFunction>(fmax);
            map["abs"] = reinterpret_cast<externalFunction>(fabs);
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
