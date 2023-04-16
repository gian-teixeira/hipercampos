#ifndef IO
#define IO

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "pointlist.h"

typedef struct Data {
    FILE *input;
    FILE *output;
    FILE *sequenceOutput;
} *Data;

int read_list_size(FILE *inputFile);
int read_list(FILE *inputFile, PointList list);
int gen_std_output(FILE *outputFile, Point maxChainingPoint);
void param_error();

#endif