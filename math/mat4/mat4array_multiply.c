/** mat4array_multiply.c */
#include "vecMat4.h"

void
mat4array_get_product(float *restrict out, const float *restrict inp)
{
    float A[16];

    A[ 0] = out[ 0]; A[ 1] = out[ 1]; A[ 2] = out[ 2]; A[ 3] = out[ 3];
    A[ 4] = out[ 4]; A[ 5] = out[ 5]; A[ 6] = out[ 6]; A[ 7] = out[ 7];
    A[ 8] = out[ 8]; A[ 9] = out[ 9]; A[10] = out[10]; A[11] = out[11];
    A[12] = out[12]; A[13] = out[13]; A[14] = out[14]; A[15] = out[15];

    vecMat4_t ot = vecMat4_row_get(out);
    cvecMat4_t in = cvecMat4_row_get(inp);
    int i = 0;
    for (; i < 4; ++i) {
        ot.x[i] = A[ 0] * in.x[i]
                + A[ 1] * in.y[i]
                + A[ 2] * in.z[i]
                + A[ 3] * in.w[i];

        ot.y[i] = A[ 4] * in.x[i]
                + A[ 5] * in.y[i]
                + A[ 6] * in.z[i]
                + A[ 7] * in.w[i];

        ot.z[i] = A[ 8] * in.x[i]
                + A[ 9] * in.y[i]
                + A[10] * in.z[i]
                + A[11] * in.w[i];

        ot.w[i] = A[12] * in.x[i]
                + A[13] * in.y[i]
                + A[14] * in.z[i]
                + A[15] * in.w[i];
    }
}
