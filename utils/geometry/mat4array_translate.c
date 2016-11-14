/** mat4array_translate.c */
#include "include/vecMat4.h"

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
    mat.d[0] += mat.a[0] * x + mat.b[0] * y + mat.c[0] * z;
    mat.d[1] += mat.a[1] * x + mat.b[1] * y + mat.c[1] * z;
    mat.d[2] += mat.a[2] * x + mat.b[2] * y + mat.c[2] * z;
    mat.d[3] += mat.a[3] * x + mat.b[3] * y + mat.c[3] * z;
}

void                    /* float out[16],       float in[3] */
mat4array_translatev(float *restrict out, float *restrict in)
{
    vecMat4_t mat = vecMat4_row_get(out);
    /*  [12]  = [0]  * x + [4] * y + [8] * z + [12], etc ... */
    mat.d[0] += mat.a[0] * in[0] + mat.b[0] * in[1] + mat.c[0] * in[3];
    mat.d[1] += mat.a[1] * in[0] + mat.b[1] * in[1] + mat.c[1] * in[3];
    mat.d[2] += mat.a[2] * in[0] + mat.b[2] * in[1] + mat.c[2] * in[3];
    mat.d[3] += mat.a[3] * in[0] + mat.b[3] * in[1] + mat.c[3] * in[3];
}
