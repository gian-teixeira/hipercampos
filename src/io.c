#include "io.h"

void param_error() {
    printf("\nInvalid arguments! The needed and supported arguments are\n-i: input file\n-o: output file\n\n");
	exit(EXIT_FAILURE);
}

int read_list_size(FILE *inputFile) {
    int size;
    fscanf(inputFile, " %d ", &size);
    return size;
}

int read_list(FILE *inputFile, PointList list) {
    if(!inputFile) return 0;
    
    fscanf(inputFile, " %d %d ", &list->anchor_A->x, &list->anchor_B->x);
    for(Point current_point = list->begin; current_point != list->end; current_point++) {
        fscanf(inputFile, " %d %d ", &current_point->x, &current_point->y);
        current_point->chaining_length = 1;
        current_point->better_partner = NULL;
    }

    return 1;
}

// Geração da saída padrão especificada no problema
int gen_std_output(FILE *outputFile, Point max_chaining_point) {
    if(!outputFile) return 0;
    fprintf(outputFile, "%d\n", max_chaining_point->chaining_length);
    return 1;
}

