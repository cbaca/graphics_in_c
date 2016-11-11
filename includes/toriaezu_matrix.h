/** toriaezu_matrix.h */
#ifndef TORIAEZU_MATRIX_H_
#define TORIAEZU_MATRIX_H_
#define MATRIX_SIZE 16
#define VECTOR_SIZE 4
#define TORI_PI 3.14159265358979323846264338327950288419716939937510582097494f

enum ToriaezuStyle {
      TORI_DEBUG
    , TORI_IDENTITY
    , TORI_ZERO
    , TORI_STYLE_ERROR
};

/** export functions */
extern void tori_set(float *restrict, int);
extern void tori_copy(float *restrict, /* const */ float *restrict);
extern void tori_multiply(float *restrict, float *restrict);
extern void tori_transpose(float *restrict);
extern void tori_get_translate(float *restrict, float, float, float);
extern void tori_get_rotate(float *restrict, double);
extern void debug_tori_print(const float *);
#endif /** TORIAEZU_MATRIX_H_ */
