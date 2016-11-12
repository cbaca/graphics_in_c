/** data_type.c */

#include <assert.h>
#include "macros.h"
#include "_vec.h"

/* consider later:
 * ・typedef float float[16] or
 * ・typedef struct float { unsigned char[16] } mat4;
 *  as per http://stackoverflow.com/questions/4523497/typedef-fixed-length-array
 */

const float _DebugMatrix[MAT_SIZE] = {
       0,  1,  2,  3
    ,  4,  5,  6,  7
    ,  8,  9, 10, 11
    , 12, 13, 14, 15
};

const float _IdentityMatrix[MAT_SIZE] = {
      1, 0, 0, 0
    , 0, 1, 0, 0
    , 0, 0, 1, 0
    , 0, 0, 0, 1
};

const float _ZeroMatrix[MAT_SIZE] = {
      0, 0, 0, 0
    , 0, 0, 0, 0
    , 0, 0, 0, 0
    , 0, 0, 0, 0
};

_Vec
_vectorize(float *matrix)
{
    _Vec vec;
    vec.a = matrix;
    matrix += VEC_SIZE;
    vec.b = matrix;
    matrix += VEC_SIZE;
    vec.c = matrix;
    matrix += VEC_SIZE;
    vec.d = matrix;
    assert(vec.d < matrix + MAT_SIZE - 1);
    return vec;
}
