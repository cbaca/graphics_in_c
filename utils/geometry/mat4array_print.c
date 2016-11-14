/** mat4array_print.c */
#include <stdio.h>

void
mat4array_print(const float *matrix)
{
    const int VEC4_LEN = 4;
    int i, j;
    i = VEC4_LEN;
    ++i;
    while (--i) {
        printf("\t");
            for (j = 0; j < VEC4_LEN; ++j)
                printf("%3.3g ", matrix[j]);
            matrix += VEC4_LEN;
            printf("\n");
    }
    printf("\n");
}
