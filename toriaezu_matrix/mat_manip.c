/** toriaezu_manip.c */
#include <assert.h>
#include <_toriaezu_matrix.h>

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
            assert(style < TORI_STYLE_ERROR && style >=0);
    }
}

void
tori_copy(float *restrict out , /* const */ float *restrict in)
{
    struct _Vectors out_v = _vectorize(out);
    struct _Vectors in_v = _vectorize(in);
    int i = 0;
    for (; i < VECTOR_SIZE; ++i) {
        out_v.a[i] = old_v.a[i];
        out_v.b[i] = old_v.b[i];
        out_v.c[i] = old_v.c[i];
        out_v.d[i] = old_v.d[i];
    }
}
