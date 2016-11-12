/** vec.h 
 *  At the moment, this is only meant to be included in two files:
 *  ・data_type.c, and
 *  ・data_type.h
 */
#ifndef TM_VEC_H_
#define TM_VEC_H_
typedef struct {
      float *restrict a;
      float *restrict b;
      float *restrict c;
      float *restrict d;
} _Vec;
#endif /** TM_VEC_H_ */
