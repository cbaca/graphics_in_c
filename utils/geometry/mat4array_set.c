/** mat4_set.c */

/* http://ptolemy.eecs.berkeley.edu/~johnr/tutorials/assertions.html says:
 * Turning assertions off:
 *      By default, ANSI C compilers generate code to check assertions at
 *      run-time. Assertion-checking can be turned off by defining the NDEBUG
 *      flag to your compiler, either by inserting:
 *          "#define NDEBUG"
 *      in a header file such as stdhdr.h, or by calling your compiler with the
 *      -dNDEBUG option:
 *          cc -dNDEBUG ...
 *      This should be done only if you are confident that your program is
 *      operating correctly, and only if program run-time is a pressing concern.
 */

#include <assert.h>
#include <stdlib.h>
#include "header/mat4array_defs.h"

void
mat4array_set(float *restrict out, int style)
{
    assert(out != NULL);
    switch (style) {
        case MAT4ARRAY_IDENTITY:
            out[ 0] = 1.0f; out[ 1] = 0.0f; out[ 2] = 0.0f; out[ 3] = 0.0f;
            out[ 4] = 0.0f; out[ 5] = 1.0f; out[ 6] = 0.0f; out[ 7] = 0.0f;
            out[ 8] = 0.0f; out[ 9] = 0.0f; out[10] = 1.0f; out[11] = 0.0f;
            out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 1.0f;
            break;
        case MAT4ARRAY_ZERO:
            out[ 0] = 0.0f; out[ 1] = 0.0f; out[ 2] = 0.0f; out[ 3] = 0.0f;
            out[ 4] = 0.0f; out[ 5] = 0.0f; out[ 6] = 0.0f; out[ 7] = 0.0f;
            out[ 8] = 0.0f; out[ 9] = 0.0f; out[10] = 0.0f; out[11] = 0.0f;
            out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 0.0f;
            break;
        case MAT4ARRAY_DEBUG:
            out[ 0] = 0.0f; out[ 1] = 1.0f; out[ 2] = 2.0f; out[ 3] = 3.0f;
            out[ 4] = 4.0f; out[ 5] = 5.0f; out[ 6] = 6.0f; out[ 7] = 7.0f;
            out[ 8] = 8.0f; out[ 9] = 9.0f; out[10] = 10.0f; out[11] = 11.0f;
            out[12] = 12.0f; out[13] = 13.0f; out[14] = 14.0f; out[15] = 15.0f;
            break;
        default:
            assert(style < MAT4ARRAY_O_ERROR && style > MAT4ARRAY_U_ERROR);
    }
}
