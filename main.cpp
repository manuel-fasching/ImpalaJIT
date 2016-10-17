#include <iostream>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include "libtcc.h"

int main(int argc, char *argv[])
{

    TCCState *s;
    unsigned long val;
    char* src;
    char cwd[1024];

    s = tcc_new();
    if (!s) {
        fprintf(stderr, "Could not create tcc state\n");
        exit(1);
    }

    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    tcc_add_file(s, argv[1]);

    tcc_run(s, 0, NULL);

    exit(0);
}