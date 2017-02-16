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

#include <impalajit.hh>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <stdlib.h>

#define CONFIG_FILE_PATH "benchmark.conf"
#define A 50000
#define B 50000


double pythagoras_static(double a, double b){
    if(a<0 || b<0){
        return -1;
    }
    else {
        return sqrt(pow(a, 2) + pow(b, 2));
    }
}

int main(){
    struct timeval tv;

    double** result_static = (double**) malloc(A*sizeof(double**));
    for(int i = 0; i< A; i++)
        result_static[i] = (double*) malloc(B*sizeof(double*));

    double** result_dynamic = (double**) malloc(A*sizeof(double**));
    for(int i = 0; i< A; i++)
        result_dynamic[i] = (double*) malloc(B*sizeof(double*));


    // Dynamic compilation
    impalajit::Compiler compiler(CONFIG_FILE_PATH);
    compiler.compile();
    dasm_gen_func pythagoras_dynamic = compiler.getFunction("pythagoras");

    gettimeofday(&tv, NULL);
    unsigned long long start_dynamic =
            (unsigned long long)(tv.tv_sec) * 1000 +
            (unsigned long long)(tv.tv_usec) / 1000;

    for(int i = 0; i<A; i++) {
        for (int j = 0; j < B; j++) {
            result_dynamic[i][j] = pythagoras_dynamic((double)i, (double)j);
        }
    }

    gettimeofday(&tv, NULL);
    unsigned long long end_dynamic =
            (unsigned long long)(tv.tv_sec) * 1000 +
            (unsigned long long)(tv.tv_usec) / 1000;


    // Static compilation
    gettimeofday(&tv, NULL);
    unsigned long long start_static =
            (unsigned long long)(tv.tv_sec) * 1000 +
            (unsigned long long)(tv.tv_usec) / 1000;

    for(int i = 0; i<A; i++) {
        for (int j = 0; j < B; j++) {
            result_static[i][j] = pythagoras_static((double)i, (double)j);
        }
    }

    gettimeofday(&tv, NULL);
    unsigned long long end_static =
            (unsigned long long)(tv.tv_sec) * 1000 +
            (unsigned long long)(tv.tv_usec) / 1000;


    // Write results
    std::ofstream outputFile;
    outputFile.open ("result.txt");
    outputFile << "------------ Dynamic compilation ------------" << std::endl;
    outputFile << "Duration (ms): " << end_dynamic-start_dynamic << std::endl;
    outputFile << "---------------------------------------------" << std::endl;
    outputFile << std::endl;
    outputFile << "------------- Static compilation ------------" << std::endl;
    outputFile << "Duration (ms): " << end_static-start_static << std::endl;
    outputFile << "---------------------------------------------" << std::endl;
    outputFile.close();



}