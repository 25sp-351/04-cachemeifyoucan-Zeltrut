#include <stdio.h>
#include <stdlib.h>
#include "rod_cut.h"
#include "utils.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_lengths;
    RodPiece *pieces = read_input_file(argv[1], &num_lengths);
    if (!pieces) {
        fprintf(stderr, "Error reading input file.\n");
        return EXIT_FAILURE;
    }

    int rod_length;
    while (scanf("%d", &rod_length) == 1) {
        if (rod_length <= 0) {
            fprintf(stderr, "Invalid rod length: %d\n", rod_length);
            continue;
        }

        int revenue;
        init_cache(rod_length + 1);  // Allocate cache and best_piece

        revenue = rod_cut(rod_length, pieces, num_lengths, NULL);

        printf("Max Revenue: %d\nCuts: ", revenue);
        get_cut_solution(rod_length);

        free_cache();  // Free cache and best_piece
    }

    free(pieces);
    return EXIT_SUCCESS;
}
