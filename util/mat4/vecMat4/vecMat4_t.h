#ifndef WINDMILL_VECMAT4_T_H_
#define WINDMILL_VECMAT4_T_H_
typedef struct {
      float *restrict x;
      float *restrict y;
      float *restrict z;
      float *restrict w;
} vecMat4_t;

typedef struct {
      const float *restrict x;
      const float *restrict y;
      const float *restrict z;
      const float *restrict w;
} cvecMat4_t;
#endif
