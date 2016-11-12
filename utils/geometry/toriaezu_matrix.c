/** toriaezu_matrix.c
 *  行列数学式実現
 */

/** 後で最適化（さいてきか）するために使おうと */
// #ifndef __GNUC__
// do_something here
// #endif
// #if not (defined (__x86_64__) || defined(__i386__)
// do that thing again here
// #endif
// #include <x86intrin.h>

/* todo:
 * inversion
 * orthographic projection
 * perspective projection
 * viewing matrix
 *
 * refactor multiplication
 * refactor translation
 * refactor rotation
 */

/* cosider implementing later:
 * ・pthread.h or
 * ・omp.h
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "include/mat4_manip.h"
#include "toriaezu_matrix.h"
//#include "header/macros.h"
//#include "header/enum.h"
//#include "include/data_type.h"

void
tori_set(float *restrict matrix, int style)
{
    int i;
    switch (style) {
        case TORI_DEBUG:
            for (i = 0; i < MAT_SIZE; ++i)
                matrix[i] = _DebugMatrix[i];
            break;
        case TORI_IDENTITY:
            for (i = 0; i < MAT_SIZE; ++i)
                matrix[i] = _IdentityMatrix[i];
            break;
        case TORI_ZERO:
            for (i = 0; i < MAT_SIZE; ++i)
                matrix[i] = _ZeroMatrix[i];
            break;
        default:
            assert(style < TORI_STYLE_ERROR && style >= 0);
    }
}

void
mat4_copy(float *restrict out, const float *restrict in)
{
    out[ 0] = in[ 0]; out[ 1] = in[ 1]; out[ 2] = in[ 2]; out[ 3] = in[ 3];
    out[ 4] = in[ 4]; out[ 5] = in[ 5]; out[ 6] = in[ 6]; out[ 7] = in[ 7];
    out[ 8] = in[ 8]; out[ 9] = in[ 9]; out[10] = in[10]; out[11] = in[11];
    out[12] = in[12]; out[13] = in[13]; out[14] = in[14]; out[15] = in[15];
}

void
tori_multiply(
      float *restrict a
    , float *restrict b)
{
    /* やりなおそ */
    float A[MAT_SIZE] = { 0 };
    float B[MAT_SIZE] = { 0 };
    mat4_copy(A, a);
    mat4_copy(B, b);
    tori_transpose(B);
    tori_set(a, TORI_ZERO);

    /* struct */ _Vec vec_c = _vectorize(a);
    /* struct */ _Vec vec_a = _vectorize(A);
    /* struct */ _Vec vec_b = _vectorize(B);
    int i = 0;
    for (; i < VEC_SIZE; ++i) {
        vec_c.a[0] += vec_a.a[i] * vec_b.a[i];
        vec_c.a[1] += vec_a.a[i] * vec_b.b[i];
        vec_c.a[2] += vec_a.a[i] * vec_b.c[i];
        vec_c.a[3] += vec_a.a[i] * vec_b.d[i];

        vec_c.b[0] += vec_a.b[i] * vec_b.a[i];
        vec_c.b[1] += vec_a.b[i] * vec_b.b[i];
        vec_c.b[2] += vec_a.b[i] * vec_b.c[i];
        vec_c.b[3] += vec_a.b[i] * vec_b.d[i];

        vec_c.c[0] += vec_a.c[i] * vec_b.a[i];
        vec_c.c[1] += vec_a.c[i] * vec_b.b[i];
        vec_c.c[2] += vec_a.c[i] * vec_b.c[i];
        vec_c.c[3] += vec_a.c[i] * vec_b.d[i];

        vec_c.d[0] += vec_a.d[i] * vec_b.a[i];
        vec_c.d[1] += vec_a.d[i] * vec_b.b[i];
        vec_c.d[2] += vec_a.d[i] * vec_b.c[i];
        vec_c.d[3] += vec_a.d[i] * vec_b.d[i];
    }
}

void
tori_get_translate(float *restrict matrix, float x, float y, float z)
{
    tori_set(matrix, TORI_IDENTITY);
    /* struct */ _Vec vec = _vectorize(matrix);
    int i = 0;
    for (; i < VEC_SIZE; ++i)
        vec.d[i] += vec.a[i] * x + vec.b[i] * y + vec.c[i] * z;
}

/** モデルマトリクスを回す状態にするには
 *  xを回る倍:
 *  { 1   0       0    0
 *    0 cos(θ) -sin(θ) 0
 *    0 sin(θ)  cos(θ) 0
 *    0   0       0    1 }
 *  悪いがタンジェント無し
 *
 *  yを
 *  { cos(θ) 0 sin(θ) 0
 *      0    1   0    0
 *   -sin(θ) 0 cos(θ) 0
 *      0    0   0    1 }
 *
 *  z
 *  { cos(θ) -sin(θ) 0 0
 *    sin(θ)  cos(θ) 0 0
 *      0       0    1 0
 *      0       0    0 1 }
 *
 *  注意しろ, ジンバルロックを
 *  ピッチした後に、ヨーは既に済んで、ヨーとロールは平気のはずだって
 *  でまぁ、よく分からんがピッチが９０度なったらヨーもロールもなんか
 *  いきなりへんなムードに入って動き始まるんだって
 *  げきおこワッタファっだまじ
 */
void
tori_get_rotate(float *restrict new, double theta)
{
    /* とりあえずZ回転軸（もしくはオイラーさんの「ヨー」）から現実に */
    double c = cos(theta);
    double s = sin(theta);
    tori_set(new, TORI_IDENTITY);
    new[0] = (float)c;
    new[1] = (float)s;
    new[4] = (float)(-s);
    new[5] = (float)c;
    /* X回転軸は「ロール」
     * または、Yが「ピッチ」
     */
}

void
tori_transpose(float *restrict a)
{
    float copy[MAT_SIZE] = { 0 };
    float *restrict b;
    mat4_copy(copy, a);
    int i = 0, j;
    for (; i < VEC_SIZE; a += VEC_SIZE, ++i)
        for (b = copy, j = 0; j < VEC_SIZE; b += VEC_SIZE, ++j)
            a[j] = b[i];
}
