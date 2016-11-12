/** mat4array_multiply.c */
#include "include/rowVecMat4.h"
#include "include/mat4array_copy.h"
#include "include/mat4array_make.h"

void
mat4array_multiply( float *restrict a, const float *restrict b)
{
    float A[MAT4ARRAY_LEN] = { 0 };
    float B[MAT4ARRAY_LEN] = { 0 };
    rowVecMat4_t vec_c;
    rowVecMat4_t vec_a;
    rowVecMat4_t vec_b;

    mat4array_copy(A, a);
    mat4array_copy(B, b);
    mat4array_make(a, MAT4ARRAY_ZERO);
    vec_c = make_rowVecMat4(a);
    vec_a = make_rowVecMat4(A);
    vec_b = make_rowVecMat4(B);

    int i = 0;
    for (; i < MAT4VEC_LEN; ++i) {
        vec_c.a[0] += vec_a.a[i] * vec_b.a[i];
        vec_c.a[1] += vec_a.a[i] * vec_b.b[i];
        vec_c.a[2] += vec_a.a[i] * vec_b.c[i];
        vec_c.a[3] += vec_a.a[i] * vec_b.d[i];

        vec_c.b[0] += vec_a.b[i] * vec_b.a[i];
        vec_c.b[1] += vec_a.b[i] * vec_b.b[i];
        vec_c.b[2] += vec_a.b[i] * vec_b.c[i];
        vec_c.b[3] += vec_a.b[i] * vec_b.d[i];

        vec_c.c[0] += vec_a.c[i] * vec_b.a[i];
        vec_c.c[1] += vec_a.c[i] * vec_b.b[i];
        vec_c.c[2] += vec_a.c[i] * vec_b.c[i];
        vec_c.c[3] += vec_a.c[i] * vec_b.d[i];

        vec_c.d[0] += vec_a.d[i] * vec_b.a[i];
        vec_c.d[1] += vec_a.d[i] * vec_b.b[i];
        vec_c.d[2] += vec_a.d[i] * vec_b.c[i];
        vec_c.d[3] += vec_a.d[i] * vec_b.d[i];
    }
}
