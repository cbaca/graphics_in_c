#include "Frustum.h"
#include <stdlib.h>

Frustum *newFrustum(Mat4 *view, Mat4 *pers)
{
    Frustum *f = malloc(sizeof(Frustum));
    updateFrustum(f, view, pers);
    return f;
}

void destroyFrustum(Frustum *f) { free(f); }

void updateFrustum(Frustum *f, Mat4 *view, Mat4 *perspective)
{
    Mat4 m;
    setMat4(&m, view);
    mulMat4(&m, perspective);

    Vec3 xaxis = (Vec3){ m.data[0], m.data[4], m.data[ 8] };
    Vec3 yaxis = (Vec3){ m.data[1], m.data[5], m.data[ 9] };
    Vec3 zaxis = (Vec3){ m.data[2], m.data[6], m.data[10] };
    Vec3 waxis = (Vec3){ m.data[3], m.data[7], m.data[11] };

    float r_len = 1.0f / vec3length(vec3sub(vec3set(&f->plane_normals[0], &waxis), &xaxis));
    float l_len = 1.0f / vec3length(vec3add(vec3set(&f->plane_normals[1], &waxis), &xaxis));
    float b_len = 1.0f / vec3length(vec3add(vec3set(&f->plane_normals[2], &waxis), &yaxis));
    float t_len = 1.0f / vec3length(vec3sub(vec3set(&f->plane_normals[3], &waxis), &yaxis));
    float f_len = 1.0f / vec3length(vec3sub(vec3set(&f->plane_normals[4], &waxis), &zaxis));
    float n_len = 1.0f / vec3length(vec3add(vec3set(&f->plane_normals[5], &waxis), &zaxis));

    f->plane_dists[0] = (m.data[15] - m.data[12]) * r_len;
    f->plane_dists[1] = (m.data[15] - m.data[12]) * l_len;
    f->plane_dists[2] = (m.data[15] - m.data[13]) * b_len;
    f->plane_dists[3] = (m.data[15] - m.data[13]) * t_len;
    f->plane_dists[4] = (m.data[15] - m.data[14]) * f_len;
    f->plane_dists[5] = (m.data[15] - m.data[14]) * n_len;

    vec3multScalar(&f->plane_normals[0], r_len);
    vec3multScalar(&f->plane_normals[1], l_len);
    vec3multScalar(&f->plane_normals[2], b_len);
    vec3multScalar(&f->plane_normals[3], t_len);
    vec3multScalar(&f->plane_normals[4], f_len);
    vec3multScalar(&f->plane_normals[5], n_len);

}

// bool frustumSphereIntersection(Frustum *f, SceneNode *sn)
bool frustumSphereIntersection(Frustum *f, Vec3 *pos, float radius)
{
    size_t i;
    Vec3 p;
    vec3set(&p, pos);
    for (i = 0; i < 6; ++i)
        if (vec3dotProduct(&p, &f->plane_normals[i]) + f->plane_dists[i] <= -radius)
            return false;
    return true;
}

// bool sphereIntersectsPlane(Plane *pl, Vec3 *pos, float radius)
// {
//     float mag = vec3dot(pos, &pl->normal) + p->distance;
//     return mag > -radius;
// }

