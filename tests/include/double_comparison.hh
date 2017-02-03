//
// Created by manuel on 03.02.17.
//

#ifndef IMPALAJIT_DOUBLE_COMPARISON_HH
#define IMPALAJIT_DOUBLE_COMPARISON_HH
#include <math.h>
bool double_equals(double a, double b, double epsilon = pow(10, -12))
{
    if(a<b) {
        return b - a < epsilon;
    }
    else {
        return a - b < epsilon;
    }
}


#endif //IMPALAJIT_DOUBLE_COMPARISON_HH
