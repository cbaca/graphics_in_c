/** toriaezu_debug.c */

#include "_toriaezu_matrix.h"
#include <stdio.h>

void
debug_tori_print(const float *matrix)
{
    int i, j;
    i = VECTOR_SIZE;
    ++i;
    while (--i) {
        printf("\t");
            for (j = 0; j < VECTOR_SIZE; ++j)
                printf("%3.3g ", matrix[j]);
            matrix += VECTOR_SIZE;
            printf("\n");
    }
    printf("\n");
}
