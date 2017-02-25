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

#ifndef IMPALAJIT_STATIC_PYTHAGORAS_FUNCTION_HH
#define IMPALAJIT_STATIC_PYTHAGORAS_FUNCTION_HH

#include <math.h>

/**
 * Static implemenation of the pythagoras function.
 * It was moved to a dedicated source file, to avoid
 * compilers from optimizing.
 */
class Pythagoras{
public:
    double pythagoras_static(double a, double b);
};
#endif //IMPALAJIT_STATIC_PYTHAGORAS_FUNCTION_HH
