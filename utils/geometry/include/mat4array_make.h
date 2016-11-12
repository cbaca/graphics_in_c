/** mat4_make.h */
#ifndef WINDMILL_MAT4ARRAY_MAKE_H_
#define WINDMILL_MAT4ARRAY_MAKE_H_
#define MAT4ARRAY_LEN 16
#define MAT4VEC_LEN 4
enum {
      MAT4ARRAY_DEBUG
    , MAT4ARRAY_MODEL
    , MAT4ARRAY_VIEW
    , MAT4ARRAY_CLIP
    , MAT4ARRAY_IDENTITY
    , MAT4ARRAY_ZERO
    , MAT4ARRAY_ERROR
};
extern void mat4array_make(float *restrict, int);
#endif
