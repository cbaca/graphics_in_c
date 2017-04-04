/** vexMat4.c */

#include <assert.h>
#include "vecMat4_t.h"

/* consider later:
 * ・typedef float float[16] or
 * ・typedef struct float { unsigned char[16] } mat4;
 *  as per http://stackoverflow.com/questions/4523497/typedef-fixed-length-array
 */

vecMat4_t
vecMat4_row_get(float *restrict in)
{
    vecMat4_t out;

    out.x = in;      /* -> [ 0][ 1][ 2][ 3]  OR [0][0],[0][1],[0][2],[0][3] */
    out.y = in +  4; /* -> [ 4][ 5][ 6][ 7]  OR [1][0],[1][1],[1][2],[1][3] */
    out.z = in +  8; /* -> [ 8][ 9][10][11]  OR [2][0],[2][1],[2][2],[2][3] */
    out.w = in + 12; /* -> [12][13][14][15]  OR [3][0],[3][1],[3][2],[3][3] */

    return out;
}

cvecMat4_t
cvecMat4_row_get(const float *restrict in)
{
    cvecMat4_t out;

    out.x = in;
    out.y = in +  4;
    out.z = in +  8;
    out.w = in + 12;

    return out;
}
