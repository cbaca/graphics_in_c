/** mat4array_rotate.c
 *  めっちゃ役に立ちますWikipediaのこれに感謝:
 *  https://en.wikipedia.org/wiki/Rotation_matrix
 */
#include <math.h>
#include <assert.h>
#include "vecMat4.h"
#include "mat4array_euler_defs.h"

void _about_roll(float *, double);
void _about_pitch(float *, double);
void _about_yaw(float *, double);

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
    ret.x[0] = mat.x[0] * rot[0] + mat.y[0] * rot[1] + mat.z[0] * rot[ 2];
    ret.x[1] = mat.x[1] * rot[0] + mat.y[1] * rot[1] + mat.z[1] * rot[ 2];
    ret.x[2] = mat.x[2] * rot[0] + mat.y[2] * rot[1] + mat.z[2] * rot[ 2];
    ret.x[3] = mat.x[3] * rot[0] + mat.y[3] * rot[1] + mat.z[3] * rot[ 2];

    ret.y[0] = mat.x[0] * rot[4] + mat.y[0] * rot[5] + mat.z[0] * rot[ 6];
    ret.y[1] = mat.x[1] * rot[4] + mat.y[1] * rot[5] + mat.z[1] * rot[ 6];
    ret.y[2] = mat.x[2] * rot[4] + mat.y[2] * rot[5] + mat.z[2] * rot[ 6];
    ret.y[3] = mat.x[3] * rot[4] + mat.y[3] * rot[5] + mat.z[3] * rot[ 6];

    ret.z[0] = mat.x[0] * rot[8] + mat.y[0] * rot[9] + mat.z[0] * rot[10];
    ret.z[1] = mat.x[1] * rot[8] + mat.y[1] * rot[9] + mat.z[1] * rot[10];
    ret.z[2] = mat.x[2] * rot[8] + mat.y[2] * rot[9] + mat.z[2] * rot[10];
    ret.z[3] = mat.x[3] * rot[8] + mat.y[3] * rot[9] + mat.z[3] * rot[10];
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


 /* 座標使用 */
#   define x 0
#   define y 1
#   define z 2
    /* normalize http://www.fundza.com/vectors/normalize/ */
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
    ot.x[0] = cp.x[0] * rot[0] + cp.y[0] * rot[1] + cp.z[0] * rot[ 2];
    ot.x[1] = cp.x[1] * rot[0] + cp.y[1] * rot[1] + cp.z[1] * rot[ 2];
    ot.x[2] = cp.x[2] * rot[0] + cp.y[2] * rot[1] + cp.z[2] * rot[ 2];
    ot.x[3] = cp.x[3] * rot[0] + cp.y[3] * rot[1] + cp.z[3] * rot[ 2];

    ot.y[0] = cp.x[0] * rot[4] + cp.y[0] * rot[5] + cp.z[0] * rot[ 6];
    ot.y[1] = cp.x[1] * rot[4] + cp.y[1] * rot[5] + cp.z[1] * rot[ 6];
    ot.y[2] = cp.x[2] * rot[4] + cp.y[2] * rot[5] + cp.z[2] * rot[ 6];
    ot.y[3] = cp.x[3] * rot[4] + cp.y[3] * rot[5] + cp.z[3] * rot[ 6];

    ot.z[0] = cp.x[0] * rot[8] + cp.y[0] * rot[9] + cp.z[0] * rot[10];
    ot.z[1] = cp.x[1] * rot[8] + cp.y[1] * rot[9] + cp.z[1] * rot[10];
    ot.z[2] = cp.x[2] * rot[8] + cp.y[2] * rot[9] + cp.z[2] * rot[10];
    ot.z[3] = cp.x[3] * rot[8] + cp.y[3] * rot[9] + cp.z[3] * rot[10];
}


/*  learnopengl.comによりZ軸回転
 *
 *  cos（Θ） -sin（Θ） 0 0
 *  sin（Θ）  cos（Θ） 0 0
 *   0         0       1 0
 *   0         0       0 1
 */
void
_about_roll(float *out, double rad)
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
_about_pitch(float *out, double rad)
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
_about_yaw(float *out, double rad)
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
