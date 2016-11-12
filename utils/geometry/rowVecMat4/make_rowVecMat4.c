/** make_RowVexMat4.c */

#include <assert.h>
#include "rowVecMat4_t.h"

/* consider later:
 * ・typedef float float[16] or
 * ・typedef struct float { unsigned char[16] } mat4;
 *  as per http://stackoverflow.com/questions/4523497/typedef-fixed-length-array
 */

rowVecMat4_t
make_rowVecMat4(float *restrict mat)
{
    const int VEC_LEN = 4;
    const int MAT_LEN = 16;
    float *restrict matrix = mat;
    rowVecMat4_t vec;
    vec.a = matrix;
    matrix += VEC_LEN;
    vec.b = matrix;
    matrix += VEC_LEN;
    vec.c = matrix;
    matrix += VEC_LEN;
    vec.d = matrix;
    assert(vec.d < mat + MAT_LEN - 1);
    return vec;
}
