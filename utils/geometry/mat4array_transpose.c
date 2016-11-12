/** mat4array_transpose.c */
#include "include/mat4array_copy.h"

void
mat4array_transpose(float *restrict a)
{
    float copy[16] = { 0 };
    float *restrict b;
    mat4array_copy(copy, a);
    int i = 0, j;
    for (; i < 4; a += 4, ++i)
        for (b = copy, j = 0; j < 4; b += 4, ++j)
            a[j] = b[i];
}
