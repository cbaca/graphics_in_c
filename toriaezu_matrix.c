/** toriaezu_matrix.c
 *  行列数学を解くための関数をここで
 */

/** 後で最適化（さいてきか）するために使おうと */
// #ifndef __GNUC__
// do_something here
// #endif
// #if not (defined (__x86_64__) || defined(__i386__)
// do that thing again here
// #endif
// #include <x86intrin.h>

// #define MATRIX_SIZE 16
// #define VECTOR_SIZE 4

#include <stdio.h>
#include <assert.h>
#include "toriaezu_matrix.h"

const float DebugMatrix[MATRIX_SIZE] = {
       0,  1,  2,  3
    ,  4,  5,  6,  7
    ,  8,  9, 10, 11
    , 12, 13, 14, 15
};

const float IdentityMatrix[MATRIX_SIZE] = {
      1, 0, 0, 0
    , 0, 1, 0, 0
    , 0, 0, 1, 0
    , 0, 0, 0, 1
};

void
matrix_set(float *restrict matrix, int style)
{
    int i;
    if (style == DEBUG)
        for (i = 0; i < MATRIX_SIZE; ++i)
            matrix[i] = DebugMatrix[i];
    else if (style == IDENTITY)
        for (i = 0; i < MATRIX_SIZE; ++i)
            matrix[i] = IdentityMatrix[i];

}

void
matrix_copy(float *restrict new, const float *restrict old)
{
    int i = 0;
    for (; i < MATRIX_SIZE; ++i)
        new[i] = old[i];
}

void
matrix_transpose(float *restrict a)
{
    float copy[MATRIX_SIZE] = { 0 };
    float *restrict b;
    matrix_copy(copy, a);
    int i = 0, j;
    for (; i < VECTOR_SIZE; a += VECTOR_SIZE, ++i)
        for (b = copy, j = 0; j < VECTOR_SIZE; b += VECTOR_SIZE, ++j)
            a[j] = b[i];
}

void
debug_matrix_print(const float *matrix)
{
    int i, j;
    i = VECTOR_SIZE;
    ++i;
    while (--i) {
        printf("\t");
        for (j = 0; j < VECTOR_SIZE; ++j)
            printf("%f ", matrix[j]);
        matrix += VECTOR_SIZE;
        printf("\n");
    }
}
