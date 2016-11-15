/** mat4array_scale.c */
#include "vecMat4.h"
/*   S_x  0   0   0
 *    0  S_y  0   0
 *    0   0  S_z  0
 *    0   0   0   1
 */

void
mat4array_get_scaled(float *restrict out, float x, float y, float z)
{
    out[ 0] = x;    out[ 1] = 0.0f; out[ 2] = 0.0f; out[ 3] = 0.0f;
    out[ 4] = 0.0f; out[ 5] = y;    out[ 6] = 0.0f; out[ 7] = 0.0f;
    out[ 8] = 0.0f; out[ 9] = 0.0f; out[10] = z;    out[11] = 0.0f;
    out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 1.0f;
}

void
mat4array_scale(float *restrict out, float x, float y, float z)
{
    vecMat4_t ot = vecMat4_row_get(out);
    /*
    float cop[16];
    out[ 0] = cop[ 0]; out[ 1] = cop[ 1]; out[ 2] = cop[ 2]; out[ 3] = cop[ 3];
    out[ 4] = cop[ 4]; out[ 5] = cop[ 5]; out[ 6] = cop[ 6]; out[ 7] = cop[ 7];
    out[ 8] = cop[ 8]; out[ 9] = cop[ 9]; out[10] = cop[10]; out[11] = cop[11];
    out[12] = cop[12]; out[13] = cop[13]; out[14] = cop[14]; out[15] = cop[15];
    vecMat_t cp = vecMat4_row_get(cop);
    float scl[16];
    scl[ 0] = x;    scl[ 1] = 0.0f; scl[ 2] = 0.0f; scl[ 3] = 0.0f;
    scl[ 4] = 0.0f; scl[ 5] = y;    scl[ 6] = 0.0f; scl[ 7] = 0.0f;
    scl[ 8] = 0.0f; scl[ 9] = 0.0f; scl[10] = z;    scl[11] = 0.0f;
    scl[12] = 0.0f; scl[13] = 0.0f; scl[14] = 0.0f; scl[15] = 1.0f;
    vecMat_t sc = vecMat4_row_get(scl);
    int i = 0;
    for (; i < 4; ++i){
        ot.a[i] = cp.a[i] * x;
        ot.b[i] = cp.b[i] * y;
        ot.c[i] = cp.c[i] * z;
    }
    */
    int i = 0;
    for (; i < 4; ++i) {
        ot.x[i] *= x;
        ot.y[i] *= y;
        ot.z[i] *= z;
    }
}

void
mat4array_scalev3(float *restrict out, float *restrict in)
{
    vecMat4_t ot = vecMat4_row_get(out);
    int i = 0;
    for (; i < 4; ++i) {
        ot.x[i] *= in[0];
        ot.y[i] *= in[1];
        ot.z[i] *= in[2];
    }
}
