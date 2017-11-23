#ifndef MATH_TYPES_H
#define MATH_TYPES_H
#include <stdint.h>

#define PI 3.141592653589793f
#define _E 2.718281828459045f
#define MAT4_SIZE   sizeof(float) * 16
#define SIZEOFMAT4  sizeof(struct vec16_float)

#define TO_DEG(x) (x) / PI * 180.f
#define TO_RAD(x) (x) * PI / 180.f
#define max(t0, t1) ({ (t1) > (t0) ? (t1) : (t0); })
#define min(t0, t1) ({ (t0) > (t1) ? (t1) : (t0); })

/* Returns lo if val is less than low.
 * Returns hi if val is greater than hi.
 * Otherwise returns val.  */
#define clamp(val, lo, hi) \
    min((typeof(val))max(val, lo), hi)


/**
 * Defines a type of "vec" struct which contains
 * an array of length @len, of type @type. e.g.
 * DECLARE_VECTYPE(float, 16) will produce:
 *
 *     struct vec16_float {
 *         float data[16];
 *     };
 */
#define DECLARE_VECTYPE(type, len) \
    struct vec##len##_##type { \
        type data[len]; \
    }

/* 4x4 float matrix structure */
DECLARE_VECTYPE(float, 16);

/* 3x3 float matrix structure */
DECLARE_VECTYPE(float, 9);

/* For complex representation of quaternions.
   Not currently implemented. */
struct vec7_fp {
    float
    b, c, d, a, /* real units */
    i, j, k,    /* imaginary units */
    PAD0;       /* To align at a 16 bit boundary. */
};

/* For the "quat_t" quaternion and vec4_t datatpes. */
struct vec4_fp {
    float x, y, z, w;
};

/* For the vec3_t datatype and any general
   calculation/strorage involving 3D vector space.
   Aligned at 16 bytes for optimal compatibility
   with mat4_t datatypes, and possible vectorizing
   optimizations. */
struct vec3_fp{
    float   x, y, z;
} __attribute__ ((aligned(16)));

/* To keep track of 3D object/camera orientation. */
struct euler {
    float yaw, pitch, roll;
};

typedef struct vec16_float  mat4_t;
typedef struct vec9_float   mat3_t;
typedef struct vec7_fp      quat_c_t;
typedef struct vec4_fp      quat_t;
typedef struct vec4_fp      vec4_t;
typedef struct vec3_fp      vec3_t;
typedef struct euler        euler_t;

typedef struct vec16_float  Mat4;    /*    depricate */
typedef struct vec9_float   Mat3;    /*    depricate */
typedef struct vec4_fp      Vec4;    /*    depricate */
typedef struct vec4_fp      Quat;    /*    depricate */
typedef struct vec3_fp      Vec3;    /*    depricate */

#endif /* MATH_TYPES_H */
