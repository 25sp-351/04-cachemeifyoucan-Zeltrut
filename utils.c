#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

RodPiece *read_input_file(const char *filename, int *num_pieces) {
    FILE *file = fopen(filename, "r");
    if (!file) return NULL;

    int count = 0;
    RodPiece *pieces = malloc(sizeof(RodPiece) * 100);

    while (fscanf(file, "%d %d %d", &pieces[count].length, &pieces[count].value, &pieces[count].max_count) == 3) {
        count++;
    }

    fclose(file);
    *num_pieces = count;
    return pieces;
}

void print_cuts(int *cuts, int rod_length) {
    while (rod_length > 0) {
        printf("%d ", cuts[rod_length]);
        rod_length -= cuts[rod_length];
    }
    printf("\n");
}
