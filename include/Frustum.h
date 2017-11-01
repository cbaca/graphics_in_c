#ifndef FRUSTUM_H
#define FRUSTUM_H
#include "Maths.h"
#include <stdbool.h>

typedef enum FrustumPlane {
    FRUSTUM_RIGHT, FRUSTUM_LEFT, FRUSTUM_BOTTOM, FRUSTUM_TOP, FRUSTUM_FAR, FRUSTUM_NEAR
} FrustumPlane;

typedef struct Frustum {
    Vec3 plane_normals[6];
    float plane_dists[6];
} Frustum;

Frustum *newFrustum(Mat4 *view, Mat4 *pers);
void destroyFrustum(Frustum *f);
bool frustumSphereIntersection(Frustum *f, Vec3 *pos, float radius);
void updateFrustum(Frustum *f, Mat4 *view, Mat4 *perspective);
#endif /* FRUSTUM_H */
