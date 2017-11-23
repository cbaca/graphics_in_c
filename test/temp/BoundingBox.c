#include "BoundingBox.h"

BoundingBox *calcFromTransformVecs(BoundingBox *bb, Vec3 *scale, Vec3 *translate)
{
    bb->front[0] = vec3construct( 1.0f,  1.0f, 1.0f);
    bb->front[1] = vec3construct( 1.0f, -1.0f, 1.0f);
    bb->front[2] = vec3construct(-1.0f,  1.0f, 1.0f);

    bb->top[0] = vec3construct( 1.0f, 1.0f,  1.0f);
    bb->top[1] = vec3construct( 1.0f, 1.0f, -1.0f);
    bb->top[2] = vec3construct(-1.0f, 1.0f,  1.0f);

    bb->right[0] = vec3construct(1.0f,  1.0f,  1.0f);
    bb->right[1] = vec3construct(1.0f, -1.0f,  1.0f);
    bb->right[2] = vec3construct(1.0f,  1.0f, -1.0f);

}
