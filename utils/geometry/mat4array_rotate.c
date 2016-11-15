/** mat4array_rotate.c
 *  めっちゃ役に立ちますWikipediaのこれに感謝:
 *  https://en.wikipedia.org/wiki/Rotation_matrix
 */
#include <math.h>
#include <assert.h>
#include "include/vecMat4.h"
#include "header/mat4array_euler_defs.h"

void _about_roll(float *restrict, double);
void _about_pitch(float *restrict, double);
void _about_yaw(float *restrict, double);

void
mat4array_get_rotation(float *restrict out, double rad, int axis)
{
    switch (axis) {
        /*** 合わせる選択はこれじゃダメのはずじゃが気になるやけちょっと・・・
         *   あと解く順番になにか関係あるって読んだ気がするな。
         */
        case MAT4ARRAY_ROLL | MAT4ARRAY_PITCH | MAT4ARRAY_YAW:
            _about_roll(out, rad);
            _about_pitch(out, rad);
            _about_yaw(out, rad);
            break;
        case MAT4ARRAY_ROLL | MAT4ARRAY_PITCH:
            _about_roll(out, rad);
            _about_pitch(out, rad);
            break;
        case MAT4ARRAY_ROLL | MAT4ARRAY_YAW:
            _about_roll(out, rad);
            _about_yaw(out, rad);
            break;
        case MAT4ARRAY_PITCH | MAT4ARRAY_YAW:
            _about_pitch(out, rad);
            _about_yaw(out, rad);
            break; /* ぜってぇダメでしょな ***/
        case MAT4ARRAY_ROLL:
            _about_roll(out, rad);
            break;
        case MAT4ARRAY_PITCH:
            _about_pitch(out, rad);
            break;
        case MAT4ARRAY_YAW:
            _about_yaw(out, rad);
            break;
        default:
            assert(axis > MAT4ARRAY_EULER_U_ERROR
                && axis < MAT4ARRAY_EULER_O_ERROR);
    }
}

void
mat4array_rotate(float *restrict out, double rad, float x, float y, float z)
{
    float cop[16];
    float rot[16];
    vecMat4_t ret;
    vecMat4_t mat;

    /* copy input matrix */
    cop[ 0] = out[ 0]; cop[ 1] = out[ 1]; cop[ 2] = out[ 2]; cop[ 3] = out[ 3];
    cop[ 4] = out[ 4]; cop[ 5] = out[ 5]; cop[ 6] = out[ 6]; cop[ 7] = out[ 7];
    cop[ 8] = out[ 8]; cop[ 9] = out[ 9]; cop[10] = out[10]; cop[11] = out[11];
    cop[12] = out[12]; cop[13] = out[13]; cop[14] = out[14]; cop[15] = out[15];

    float c = (float)cos(rad);
    float s = (float)sin(rad);

    /* normalize http://www.fundza.com/vectors/normalize/ */
    float len = (float)sqrt((x * x) + (y * y) + (z * z));
    float nx = x / len;
    float ny = y / len;
    float nz = z / len;

    /* make rotation matrix, thank you glm header lib */
    float tx = (1.0f - c) * nx;
    float ty = (1.0f - c) * ny;
    float tz = (1.0f - c) * nz;
    rot[ 0] = c + tx * nx;
    rot[ 1] =     tx * ny + s * nz;
    rot[ 2] =     tx * nz - s * ny;

    rot[ 4] =     ty * nx - s * nz;
    rot[ 5] = c + ty * ny;
    rot[ 6] =     ty * nz + s * nx;

    rot[ 8] =     tz * nx + s * ny;
    rot[ 9] =     tz * ny - s * nx;
    rot[10] = c + tz * nz;

    /* multiply by original */
    ret = vecMat4_row_get(out);
    mat = vecMat4_row_get(cop);
    ret.a[0] = mat.a[0] * rot[0] + mat.b[0] * rot[1] + mat.c[0] * rot[ 2];
    ret.a[1] = mat.a[1] * rot[0] + mat.b[1] * rot[1] + mat.c[1] * rot[ 2];
    ret.a[2] = mat.a[2] * rot[0] + mat.b[2] * rot[1] + mat.c[2] * rot[ 2];
    ret.a[3] = mat.a[3] * rot[0] + mat.b[3] * rot[1] + mat.c[3] * rot[ 2];

    ret.b[0] = mat.a[0] * rot[4] + mat.b[0] * rot[5] + mat.c[0] * rot[ 6];
    ret.b[1] = mat.a[1] * rot[4] + mat.b[1] * rot[5] + mat.c[1] * rot[ 6];
    ret.b[2] = mat.a[2] * rot[4] + mat.b[2] * rot[5] + mat.c[2] * rot[ 6];
    ret.b[3] = mat.a[3] * rot[4] + mat.b[3] * rot[5] + mat.c[3] * rot[ 6];

    ret.c[0] = mat.a[0] * rot[8] + mat.b[0] * rot[9] + mat.c[0] * rot[10];
    ret.c[1] = mat.a[1] * rot[8] + mat.b[1] * rot[9] + mat.c[1] * rot[10];
    ret.c[2] = mat.a[2] * rot[8] + mat.b[2] * rot[9] + mat.c[2] * rot[10];
    ret.c[3] = mat.a[3] * rot[8] + mat.b[3] * rot[9] + mat.c[3] * rot[10];
}

void
mat4array_rotatev3(float *restrict out, double rad, float *restrict in)
{
    float cop[16];
    float rot[16];
    vecMat4_t ot;
    vecMat4_t cp;
    ot = vecMat4_row_get(out);
    cp = vecMat4_row_get(cop);

    float c = (float)cos(rad);
    float s = (float)sin(rad);

    /* copy input matrix */
    cop[ 0] = out[ 0]; cop[ 1] = out[ 1]; cop[ 2] = out[ 2]; cop[ 3] = out[ 3];
    cop[ 4] = out[ 4]; cop[ 5] = out[ 5]; cop[ 6] = out[ 6]; cop[ 7] = out[ 7];
    cop[ 8] = out[ 8]; cop[ 9] = out[ 9]; cop[10] = out[10]; cop[11] = out[11];
    cop[12] = out[12]; cop[13] = out[13]; cop[14] = out[14]; cop[15] = out[15];

    /* normalize http://www.fundza.com/vectors/normalize/ */
#   define x 0
#   define y 1
#   define z 2
    float len = (float)sqrt((in[x] * in[x]) + (in[y] * in[y]) + (in[z] * in[z]));
    float norm[3] = { in[x] / len, in[y] / len, in[z] / len };
    float frac[3] = { (1.0f - c) * norm[x], (1.0f - c) * norm[y], (1.0f - c) * norm[z] };

    /* make rotation matrix, thank you glm header lib */
    rot[ 0] = c + frac[x] * norm[x];
    rot[ 1] =     frac[x] * norm[y] + s * norm[z];
    rot[ 2] =     frac[x] * norm[z] - s * norm[y];

    rot[ 4] =     frac[y] * norm[x] - s * norm[z];
    rot[ 5] = c + frac[y] * norm[y];
    rot[ 6] =     frac[y] * norm[z] + s * norm[x];

    rot[ 8] =     frac[z] * norm[x] + s * norm[y];
    rot[ 9] =     frac[z] * norm[y] - s * norm[x];
    rot[10] = c + frac[z] * norm[z];
#   undef x
#   undef y
#   undef z

    /* multiply by original */
    ot.a[0] = cp.a[0] * rot[0] + cp.b[0] * rot[1] + cp.c[0] * rot[ 2];
    ot.a[1] = cp.a[1] * rot[0] + cp.b[1] * rot[1] + cp.c[1] * rot[ 2];
    ot.a[2] = cp.a[2] * rot[0] + cp.b[2] * rot[1] + cp.c[2] * rot[ 2];
    ot.a[3] = cp.a[3] * rot[0] + cp.b[3] * rot[1] + cp.c[3] * rot[ 2];

    ot.b[0] = cp.a[0] * rot[4] + cp.b[0] * rot[5] + cp.c[0] * rot[ 6];
    ot.b[1] = cp.a[1] * rot[4] + cp.b[1] * rot[5] + cp.c[1] * rot[ 6];
    ot.b[2] = cp.a[2] * rot[4] + cp.b[2] * rot[5] + cp.c[2] * rot[ 6];
    ot.b[3] = cp.a[3] * rot[4] + cp.b[3] * rot[5] + cp.c[3] * rot[ 6];

    ot.c[0] = cp.a[0] * rot[8] + cp.b[0] * rot[9] + cp.c[0] * rot[10];
    ot.c[1] = cp.a[1] * rot[8] + cp.b[1] * rot[9] + cp.c[1] * rot[10];
    ot.c[2] = cp.a[2] * rot[8] + cp.b[2] * rot[9] + cp.c[2] * rot[10];
    ot.c[3] = cp.a[3] * rot[8] + cp.b[3] * rot[9] + cp.c[3] * rot[10];
}


/*  learnopengl.comによりZ軸回転
 *
 *  cos（Θ） -sin（Θ） 0 0
 *  sin（Θ）  cos（Θ） 0 0
 *   0         0       1 0
 *   0         0       0 1
 */
void
_about_roll(float *restrict out, double rad)
{
    float c = (float)cos(rad);
    float s = (float)sin(rad);
    out[ 0] = c;
    out[ 1] = s;
    out[ 2] = 0.0f;
    out[ 3] = 0.0f;

    out[ 4] = -s;
    out[ 5] = c;
    out[ 6] = 0.0f;
    out[ 7] = 0.0f;

    out[ 8] = 0.0f;
    out[ 9] = 0.0f;
    out[10] = 1.0f;
    out[11] = 0.0f;

    out[12] = 0.0f;
    out[13] = 0.0f;
    out[14] = 0.0f;
    out[15] = 1.0f;
}

/*   learnopngl.comによりX軸回転
 *   1  0         0       0
 *   0 cos（Θ） -sin（Θ） 0
 *   0 sin（Θ）  cos（Θ） 0
 *   0  0         0       1
 */
void
_about_pitch(float *restrict out, double rad)
{
    float c = (float)cos(rad);
    float s = (float)sin(rad);
    out[ 0] = 1.0f;
    out[ 1] = 0.0f;
    out[ 2] = 0.0f;
    out[ 3] = 0.0f;

    out[ 4] = 0.0f;
    out[ 5] = c;
    out[ 6] = (-s);
    out[ 7] = 0.0f;

    out[ 8] = 0.0f;
    out[ 9] = -s;
    out[10] = c;
    out[11] = 0.0f;

    out[12] = 0.0f;
    out[13] = 0.0f;
    out[14] = 0.0f;
    out[15] = 1.0f;
}

/*  learnopengl.comによりY軸回転だった気がする：
 *    cos（Θ） 0 sin（Θ） 0
 *     0       1  0       0
 *   -sin（Θ） 0 cos（Θ） 0
 *     0       0  0       1
 */
void
_about_yaw(float *restrict out, double rad)
{
    float c = (float)cos(rad);
    float s = (float)sin(rad);
    out[ 0] = c;
    out[ 1] = 0.0f;
    out[ 2] = -s;
    out[ 3] = 0.0f;

    out[ 4] = 0.0f;
    out[ 5] = 1.0f;
    out[ 6] = 0.0f;
    out[ 7] = 0.0f;

    out[ 8] = s;
    out[ 9] = 0;
    out[10] = c;
    out[11] = 0.0f;

    out[12] = 0.0f;
    out[13] = 0.0f;
    out[14] = 0.0f;
    out[15] = 1.0f;
}
