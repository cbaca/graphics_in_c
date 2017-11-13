#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H
#include "Maths.h"
typedef struct BoundingBox {
    Vec3 front[3];
    Vec3 top[3];
    Vec3 right[3];
} BoundingBox;
#endif
