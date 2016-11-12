/** toriaezu_matrix.h */
#ifndef TM_TORIAEZU_MATRIX_H_
#define TM_TORIAEZU_MATRIX_H_
#include "header/sizes.h"
#include "header/matrices.h"
#include "include/data_type.h"
void tori_set(float *restrict, int);
void tori_copy(float *restrict, /* const */ float *restrict);
void tori_multiply(float *restrict, float *restrict);
void tori_transpose(float *restrict);
void tori_get_translate(float *restrict, float, float, float);
void tori_get_rotate(float *restrict, double);
void debug_tori_print(const float *);
#endif /** TM_TORIAEZU_MATRIX_H_ */
