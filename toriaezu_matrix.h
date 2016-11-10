/** toriaezu_matrix.h */
#ifndef TORIAEZU_MATRIX_H_
#define TORIAEZU_MATRIX_H_
#define MATRIX_SIZE 16
#define VECTOR_SIZE 4

enum MatrixStyle {
      DEBUG
    , IDENTITY
};

/** export variables */
extern const float DebugMatrix[MATRIX_SIZE];
extern const float IdentityMatrix[MATRIX_SIZE];

/** export functions */
extern void matrix_set(float *restrict, int);
extern void matrix_copy(float *restrict, const float *restrict);
extern void matrix_transpose(float *restrict);
extern void debug_matrix_print(const float *);
#endif
