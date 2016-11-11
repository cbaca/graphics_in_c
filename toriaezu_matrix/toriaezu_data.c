/** toriaezu_data.c */

#include <assert.h>

struct _Vectors
_vectorize(float *matrix)
{
    struct _Vectors vec;
    vec.a = matrix;
    matrix += VECTOR_SIZE;
    vec.b = matrix;
    matrix += VECTOR_SIZE;
    vec.c = matrix;
    matrix += VECTOR_SIZE;
    vec.d = matrix;
    assert(vec.d < vec.a + MATRIX_SIZE);
    return vec;
}
