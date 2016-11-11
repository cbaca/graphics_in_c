/** _toriaezu_matrix.h
 *  toriaezu_matrix.c の中だけに使われる静的（せいてき）な隠蔽（いんぺい）な変数や
 *  関数などでーーす
 */

/* πは円周率とも呼ばれるらしいっす。ホーリーシット */
#define TORI_PI 3.14159265358979323846264338327950288419716939937510582097494f
#define MATRIX_SIZE 16
#define VECTOR_SIZE 4

/* extern */
void tori_set(float *restrict, int);
void tori_copy(float *restrict, /* const */ float *restrict);
void tori_multiply(float *restrict, float *restrict);
void tori_transpose(float *restrict);
void tori_get_translate(float *restrict, float, float, float);
void tori_get_rotate(float *restrict, double);
/* end extern */

/* デバッグ */
void debug_tori_print(const float *);

/** statics */
enum _ToriStyle {
      TORI_DEBUG
    , TORI_IDENTITY
    , TORI_ZERO
    , TORI_STYLE_ERROR
};

struct _Vectors {
    float *restrict a, *restrict b, *restrict c, *restrict d;
};

static const float _DebugMatrix[MATRIX_SIZE] = {
       0,  1,  2,  3
    ,  4,  5,  6,  7
    ,  8,  9, 10, 11
    , 12, 13, 14, 15
};

static const float _IdentityMatrix[MATRIX_SIZE] = {
      1, 0, 0, 0
    , 0, 1, 0, 0
    , 0, 0, 1, 0
    , 0, 0, 0, 1
};

static const float _ZeroMatrix[MATRIX_SIZE] = {
      0, 0, 0, 0
    , 0, 0, 0, 0
    , 0, 0, 0, 0
    , 0, 0, 0, 0
};

static struct _Vectors _vectorize(float *);
