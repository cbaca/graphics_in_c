/** toriaezu_debug.c */

#include "macros.h"
#include <stdio.h>

void
debug_tori_print(const float *matrix)
{
    int i, j;
    i = VEC_SIZE;
    ++i;
    while (--i) {
        printf("\t");
            for (j = 0; j < VEC_SIZE; ++j)
                printf("%3.3g ", matrix[j]);
            matrix += VEC_SIZE;
            printf("\n");
    }
    printf("\n");
}
