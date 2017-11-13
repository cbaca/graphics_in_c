#pragma once

#define PI 3.141592653589793f

#define TO_DEG(x) (x) / PI * 180.f

#define TO_RAD(x) (x) * PI / 180.f

// http://aggregate.org/MAGIC/#Alignment%20of%20Pointers
#define _FASI(f) (*((int *) &f))
#define _FASUI(f) (*((unsigned int *) &f))

#define _LT0(f) (_FASUI(f) > 0x80000000U)
#define _LE0(f) (_FASI(f)  <= 0)
#define _GT0(f) (_FASI(f)  > 0)
#define _GE0(f) (_FASUI(f) <= 0x80000000U)

typedef struct Vec3 {
    float x, y, z;
} Vec3;

typedef struct Int3 {
    int x, y, z;
} Int3;

typedef struct Mat4 {
    float data[16];
} Mat4;
