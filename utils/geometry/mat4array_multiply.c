/** mat4array_multiply.c */
#include "include/vecMat4.h"

void
mat4array_get_product(float *restrict out, const float *restrict in)
{
    float A[16] = { 0 };
    float B[16] = { 0 };
    
    /** outのコピーAを */
    // mat4array_copy(A, out);
    A[ 0] = out[ 0]; A[ 1] = out[ 1]; A[ 2] = out[ 2]; A[ 3] = out[ 3];
    A[ 4] = out[ 4]; A[ 5] = out[ 5]; A[ 6] = out[ 6]; A[ 7] = out[ 7];
    A[ 8] = out[ 8]; A[ 9] = out[ 9]; A[10] = out[10]; A[11] = out[11];
    A[12] = out[12]; A[13] = out[13]; A[14] = out[14]; A[15] = out[15];

    /** inのコピーBを */
    // mat4array_copy(B, in);
    B[ 0] = in[ 0]; B[ 1] = in[ 1]; B[ 2] = in[ 2]; B[ 3] = in[ 3];
    B[ 4] = in[ 4]; B[ 5] = in[ 5]; B[ 6] = in[ 6]; B[ 7] = in[ 7];
    B[ 8] = in[ 8]; B[ 9] = in[ 9]; B[10] = in[10]; B[11] = in[11];
    B[12] = in[12]; B[13] = in[13]; B[14] = in[14]; B[15] = in[15];

    /** outの全座標をゼロに */
    out[ 0] = 0.0f; out[ 1] = 0.0f; out[ 2] = 0.0f; out[ 3] = 0.0f;
    out[ 4] = 0.0f; out[ 5] = 0.0f; out[ 6] = 0.0f; out[ 7] = 0.0f;
    out[ 8] = 0.0f; out[ 9] = 0.0f; out[10] = 0.0f; out[11] = 0.0f;
    out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 0.0f;

    /** やりやすいからrow vector struct vecMat4_t に */
    vecMat4_t vec_c = vecMat4_row_get(out);
    vecMat4_t vec_a = vecMat4_row_get(A);
    vecMat4_t vec_b = vecMat4_row_get(B);

    for (int i = 0; i < 4; ++i) {
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

/* こいつ多分もうつかわないが使うとしたらかえなきゃだめです
float *
mat4array_make_product(const float *restrict a, const float *restrict b)
{
    float A[MAT4ARRAY_LEN] = { 0 };
    float B[MAT4ARRAY_LEN] = { 0 };
    float *out;
    rowVecMat4_t vec_c;
    rowVecMat4_t vec_a;
    rowVecMat4_t vec_b;

    out = mat4array_make(MAT4ARRAY_ZERO);
    mat4array_copy(A, a);
    mat4array_copy(B, b);
    vec_c = get_rowVecMat4(out);
    vec_a = get_rowVecMat4(A);
    vec_b = get_rowVecMat4(B);

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
    return out;
} */
