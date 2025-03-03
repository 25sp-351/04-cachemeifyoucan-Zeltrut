#include "policies.h"
#include <stdlib.h>
#include <stdio.h>

void apply_policy_a(int *cache, int size) {
    for (int i = 0; i < size; i++) cache[i] = -1;
}
