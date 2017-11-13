#ifndef MATH_TYPES_H
#define MATH_TYPES_H

#include <stdint.h>

#define PI 3.141592653589793f
#define TO_DEG(x) (x) / PI * 180.f
#define TO_RAD(x) (x) * PI / 180.f
#define _FASI(f) (*((int *) &f))
#define _FASUI(f) (*((unsigned int *) &f))
#define _LT0(f) (_FASUI(f) > 0x80000000U)
#define _LE0(f) (_FASI(f)  <= 0)
#define _GT0(f) (_FASI(f)  > 0)
#define _GE0(f) (_FASUI(f) <= 0x80000000U)

struct vec4f32_t { float   x, y, z, w; };
// struct vec3f32_t { float   x, y, z; } __attribute__ ((aligned(16), packed));
struct vec3f32_t { float   x, y, z; } __attribute__ ((aligned(16)));
struct matrix44f32_t { float data[16]; };

typedef struct vec4f32_t Vec4;
typedef struct vec4f32_t Quat;
typedef struct vec3f32_t Vec3;
typedef struct matrix44f32_t Mat4;

#define MAT4_SIZE sizeof(float) * 16
#define SIZEOFMAT4 sizeof(struct matrix44f32_t)

#endif /* MATH_TYPES_H */
