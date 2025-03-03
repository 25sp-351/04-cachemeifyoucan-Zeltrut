#ifndef UTILS_H
#define UTILS_H

#include "rod_cut.h"

RodPiece *read_input_file(const char *filename, int *num_pieces);
void print_cuts(int *cuts, int rod_length);

#endif
