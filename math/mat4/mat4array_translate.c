/** mat4array_translate.c */
#include "vecMat4.h"

/*   これが典型的なモデル・マトリクスです。
 *   1,  0,  0, T_x [0][0], [0][1], [0][2], [0][3] @ ────> i0, i1, i2, i3 >──╮
 *   --------------                                  ╭───<────────────────<──╯
 * , 0,  1,  0, T_y [1][0], [1][1], [1][2], [1][3] @ ╰──> i4, i5, i6, i7 ─>──╮
 *   --------------
 * , 0,  0,  1, T_z
 *   --------------
 * , 0,  0,  0,  1
 *
 *
 *
 *   1, | 0, | 0, | 0 [0][0], [1][0], [2][0], [3][0] @  ───> i0, i1, i2, i3 >──╮
 *      |    |    |                                    ╭───<────────────────<──╯
 * , 0, | 1, | 0, | 0 [0][1], [1][1], [2][1], [3][1] @ ╰──> i4, i5, i6, i7 ─>──╮
 *      |    |    |
 * , 0, | 0, | 1, | 0
 *      |    |    |
 * ,T_x,|T_y,|T_z,| 1
 */
#define X 0
#define Y 1
#define Z 2
#define W 3
void
mat4array_get_translationv3(float *restrict out, float *restrict in)
{
    out[ 0] = 1.0f;  out[ 1] = 0.0f;  out[ 2] = 0.0f;  out[ 3] = 0.0f;
    out[ 4] = 0.0f;  out[ 5] = 1.0f;  out[ 6] = 0.0f;  out[ 7] = 0.0f;
    out[ 8] = 0.0f;  out[ 9] = 0.0f;  out[10] = 1.0f;  out[11] = 0.0f;
    out[12] = in[X]; out[13] = in[Y]; out[14] = in[Z]; out[15] = 1.0f;
}

void
mat4array_get_translation(float *restrict out, float x, float y, float z)
{
    /* column major style */
    out[ 0] = 1.0f; out[ 1] = 0.0f; out[ 2] = 0.0f; out[ 3] = 0.0f;
    out[ 4] = 0.0f; out[ 5] = 1.0f; out[ 6] = 0.0f; out[ 7] = 0.0f;
    out[ 8] = 0.0f; out[ 9] = 0.0f; out[10] = 1.0f; out[11] = 0.0f;
    out[12] = x;    out[13] = y;    out[14] = z;    out[15] = 1.0f;
}

void
mat4array_translate(float *restrict out, float x, float y, float z)
{
    vecMat4_t mat = vecMat4_row_get(out);
    /*  [12]  = [0]  * x + [4] * y + [8] * z + [12], etc ...*/
    mat.w[X] += mat.x[X] * x + mat.y[X] * y + mat.z[X] * z;
    mat.w[Y] += mat.x[Y] * x + mat.y[Y] * y + mat.z[Y] * z;
    mat.w[Z] += mat.x[Z] * x + mat.y[Z] * y + mat.z[Z] * z;
    mat.w[W] += mat.x[W] * x + mat.y[W] * y + mat.z[W] * z;
}

void                    /* float out[16],       float in[3] */
mat4array_translatev3(float *restrict out, float *restrict in)
{
    vecMat4_t mat = vecMat4_row_get(out);
    /*  [12]  = [0]  * x + [4] * y + [8] * z + [12], etc ... */
    mat.w[X] += mat.x[X] * in[X] + mat.y[X] * in[Y] + mat.z[X] * in[Z];
    mat.w[Y] += mat.x[Y] * in[X] + mat.y[Y] * in[Y] + mat.z[Y] * in[Z];
    mat.w[Z] += mat.x[Z] * in[X] + mat.y[Z] * in[Y] + mat.z[Z] * in[Z];
    mat.w[W] += mat.x[W] * in[X] + mat.y[W] * in[Y] + mat.z[W] * in[Z];
}
#undef X
#undef Y
#undef Z
#undef W
