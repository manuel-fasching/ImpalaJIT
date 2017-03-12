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

#include "impalajit.hh"
#include <iostream>
#include <fstream>
#include <assert.h>
#include <defines.hh>
#include <double_comparison.hh>
using namespace std;


double reference_function(double z, double i){
    if(z < 10000.0 && z >= 500.0) {
        if(i==1.0){
            return 2100.0;
        }
        if(i==2.0){
            return 2100000000.0;
        }
        if(i==3.0){
            return 3381000000.0;
        }
    }
    if(z < -500.0 && z >= -1500.0) {
        if(i==1.0){
            return 2400.0;
        }
        if(i==2.0){
            return 9600000000.0;
        }
        if(i==3.0){
            return 19200000000.0;
        }
    }
    if(z < -1500.0  && z >= -4000.0) {
        if(i==1.0){
            return 2700.0;
        }
        if(i==2.0){
            return 27648000000.0;
        }
        if(i==3.0){
            return 26379000000.0;
        }
    }
    if(z < -4000.0 && z >= -270000.0) {
        if(i==1.0){
            return 2800.0;
        }
        if(i==2.0){
            return 36288000000.0;
        }
        if(i==3.0){
            return 38556000000.0;
        }
    }
    if(z < -270000.0 && z >= -400000.0) {
        if(i==1.0){
            return 2900.0;
        }
        if(i==2.0){
            return 44109000000.0;
        }
        if(i==3.0){
            return 45878000000.0;
        }
    }
    if(i==1.0){
        return 3300.0;
    }
    if(i==2.0){
        return 66825000000.0;
    }
    if(i==3.0){
        return 67122000000.0;
    }
}

int main(int argc, char** argv) {

    ofstream configFile;
    configFile.open(CONFIG_FILE_PATH);
    configFile << "../../tests/impala_files/many_if.impala;";
    configFile.close();

    impalajit::Compiler compiler(CONFIG_FILE_PATH);
    compiler.compile();
    dasm_gen_func function = compiler.getFunction("many_if");
    compiler.close();
    for(int i=-500000; i< 500000; i++) {
        assert(double_equals(function(static_cast<double>(i), 1.0), reference_function(static_cast<double>(i), 1.0)));
        assert(double_equals(function(static_cast<double>(i), 2.0), reference_function(static_cast<double>(i), 2.0)));
        assert(double_equals(function(static_cast<double>(i), 3.0), reference_function(static_cast<double>(i), 3.0)));
    }
    return 0;
}

