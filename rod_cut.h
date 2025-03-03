#ifndef ROD_CUT_H
#define ROD_CUT_H

typedef struct {
    int length;
    int value;
    int max_count;
} RodPiece;

extern int *cache;
extern int *best_piece;

void init_cache(int size);
void free_cache();
int rod_cut(int n, RodPiece pieces[], int num_pieces, int solution[]);
void get_cut_solution(int n);

#endif
