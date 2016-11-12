/** mat4_make.c */

#include <assert.h>
#include "include/mat4array_copy.h"
#include "header/mat4array_defs.h"

static const float DebugMatrix4Array[MAT4ARRAY_LEN] = {
       0,  1,  2,  3
    ,  4,  5,  6,  7
    ,  8,  9, 10, 11
    , 12, 13, 14, 15
};

static const float IdentityMatrix4Array[MAT4ARRAY_LEN] = {
      1, 0, 0, 0
    , 0, 1, 0, 0
    , 0, 0, 1, 0
    , 0, 0, 0, 1
};

static const float ZeroMatrix4Array[MAT4ARRAY_LEN] = {
      0, 0, 0, 0
    , 0, 0, 0, 0
    , 0, 0, 0, 0
    , 0, 0, 0, 0
};

void
mat4array_make(float *restrict matrix, int style)
{
    switch (style) {
        case MAT4ARRAY_DEBUG:
            mat4array_copy(matrix, DebugMatrix4Array);
            break;
        case MAT4ARRAY_IDENTITY:
            mat4array_copy(matrix, IdentityMatrix4Array);
            break;
        case MAT4ARRAY_ZERO:
            mat4array_copy(matrix, ZeroMatrix4Array);
            break;
        default:
            assert(style < MAT4ARRAY_ERROR && style >= 0);
    }
}
