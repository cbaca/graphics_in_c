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

/* cosider pthread.h or omp.h later */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "_toriaezu_matrix.h"

/** implement statics */
static struct _Vectors
_vectorize(float *matrix)
{
    struct _Vectors vec;
    vec.a = matrix;
    matrix += VECTOR_SIZE;
    vec.b = matrix;
    matrix += VECTOR_SIZE;
    vec.c = matrix;
    matrix += VECTOR_SIZE;
    vec.d = matrix;
    return vec;
}

/** implement externs */
void
tori_set(float *restrict matrix, int style)
{
    int i;
    switch (style) {
        case TORI_DEBUG:
            for (i = 0; i < MATRIX_SIZE; ++i)
                matrix[i] = _DebugMatrix[i];
            break;
        case TORI_IDENTITY:
            for (i = 0; i < MATRIX_SIZE; ++i)
                matrix[i] = _IdentityMatrix[i];
            break;
        case TORI_ZERO:
            for (i = 0; i < MATRIX_SIZE; ++i)
                matrix[i] = _ZeroMatrix[i];
            break;
        default:
            assert(style < TORI_STYLE_ERROR && style >= 0);
    }

}

void
tori_copy(float *restrict new, /* const */float *restrict old)
{
    struct _Vectors new_v = _vectorize(new);
    struct _Vectors old_v = _vectorize(old);
    int i = 0;
    for (; i < VECTOR_SIZE; ++i) {
        new_v.a[i] = old_v.a[i];
        new_v.b[i] = old_v.b[i];
        new_v.c[i] = old_v.c[i];
        new_v.d[i] = old_v.d[i];
    }
}

void
tori_multiply(
      float *restrict a
    , float *restrict b)
{
    /* ちょーっとだけ適当やけど時間ねぇんやけ最適化は後。まぁ、だからこそ
     * "とりあえず"って名にしたな。
     * と言えば、とりあえず三つの４x４の８バイト浮動小数点数変数ならば
     * L1に全部入るでしょう
     * このまま書きつづけると、もう屁理屈（へりくつ）マトリクスにしとこうかな
     */
    float A[MATRIX_SIZE] = { 0 };
    float B[MATRIX_SIZE] = { 0 };
    tori_copy(A, a);
    tori_copy(B, b);
    tori_transpose(B);
    tori_set(a, TORI_ZERO);

    struct _Vectors vec_c = _vectorize(a);
    struct _Vectors vec_a = _vectorize(A);
    struct _Vectors vec_b = _vectorize(B);
    int i = 0;
    for (; i < VECTOR_SIZE; ++i) {
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
    struct _Vectors vec = _vectorize(matrix);
    int i = 0;
    for (; i < VECTOR_SIZE; ++i)
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
    float copy[MATRIX_SIZE] = { 0 };
    float *restrict b;
    tori_copy(copy, a);
    int i = 0, j;
    for (; i < VECTOR_SIZE; a += VECTOR_SIZE, ++i)
        for (b = copy, j = 0; j < VECTOR_SIZE; b += VECTOR_SIZE, ++j)
            a[j] = b[i];
}

void
debug_tori_print(const float *matrix)
{
    int i, j;
    i = VECTOR_SIZE;
    ++i;
    while (--i) {
        printf("\t");
        for (j = 0; j < VECTOR_SIZE; ++j)
            printf("%3.3g ", matrix[j]);
        matrix += VECTOR_SIZE;
        printf("\n");
    }
    printf("\n");
}
