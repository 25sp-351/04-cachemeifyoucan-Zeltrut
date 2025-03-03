#include "rod_cut.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int *cache = NULL;
int *best_piece = NULL;

void init_cache(int size) {
    cache = malloc((size + 1) * sizeof(int));
    best_piece = malloc((size + 1) * sizeof(int));

    for (int i = 0; i <= size; i++) {
        cache[i] = -1;
        best_piece[i] = -1;
    }
}

void free_cache() {
    free(cache);
    free(best_piece);
    cache = NULL;
    best_piece = NULL;
}

int rod_cut(int n, RodPiece pieces[], int num_pieces, int solution[]) {
    if (n == 0) return 0;
    if (cache[n] != -1) return cache[n];

    int max_value = INT_MIN;
    int best_cut = -1;  // Track the best piece used

    for (int i = 0; i < num_pieces; i++) {
        if (pieces[i].length <= n) {
            int value = pieces[i].value + rod_cut(n - pieces[i].length, pieces, num_pieces, solution);
            if (value > max_value) {
                max_value = value;
                best_cut = pieces[i].length;
            }
        }
    }

    cache[n] = max_value;
    best_piece[n] = best_cut;  // Store the best piece used
    return max_value;
}

// Backtrack to reconstruct the cuts
void get_cut_solution(int n) {
    while (n > 0 && best_piece[n] != -1) {
        printf("%d ", best_piece[n]);
        n -= best_piece[n];
    }
    printf("\n");
}
