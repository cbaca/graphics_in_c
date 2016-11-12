/** mat4array_translate.c */
#include "include/mat4array_make.h"
#include "include/rowVecMat4.h"

void
mat4array_make_translation(float *restrict mat, float x, float y, float z)
{
    mat4array_make(mat, MAT4ARRAY_IDENTITY);
    rowVecMat4_t vec = make_rowVecMat4(mat);
    int i = 0;
    for (; i < MAT4VEC_LEN; ++i)
        vec.d[i] += vec.a[i] * x + vec.b[i] * y + vec.c[i] * z;
}
