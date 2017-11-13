#include "Frustum.h"
#include <stdlib.h>

Frustum *newFrustum(Mat4 *view, Mat4 *pers)
{
    Frustum *f = malloc(sizeof(Frustum));
    updateFrustum(f, view, pers);
    return f;
}

void destroyFrustum(Frustum *f) { free(f); }

float vec3gyakudst(const Vec3 *from, const Vec3 *to)
{
    Vec3 ret = vec3construct(to->x - from->x, to->y - from->y, to->z - from->z);
    return vec3length(&ret);
}

void updateFrustum(Frustum *f, Mat4 *view, Mat4 *perspective)
{
    Mat4 m;
    setMat4(&m, view);
    mulMat4(&m, perspective);

    Vec3 xaxis = vec3construct(m.data[0], m.data[4], m.data[ 8]);
    Vec3 yaxis = vec3construct(m.data[1], m.data[5], m.data[ 9]);
    Vec3 zaxis = vec3construct(m.data[2], m.data[6], m.data[10]);
    Vec3 waxis = vec3construct(m.data[3], m.data[7], m.data[11]);

    // f->plane_normals[0] = vec3distance(&waxis, &xaxis);
    // f->plane_normals[1] = vec3gyakudst(&waxis, &xaxis);
    // f->plane_normals[2] = vec3gyakudst(&waxis, &yaxis);
    // f->plane_normals[3] = vec3distance(&waxis, &yaxis);
    // f->plane_normals[4] = vec3distance(&waxis, &zaxis);
    // f->plane_normals[5] = vec3gyakudst(&waxis, &zaxis);

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

    vec3mulScalar(&f->plane_normals[0], r_len);
    vec3mulScalar(&f->plane_normals[1], l_len);
    vec3mulScalar(&f->plane_normals[2], b_len);
    vec3mulScalar(&f->plane_normals[3], t_len);
    vec3mulScalar(&f->plane_normals[4], f_len);
    vec3mulScalar(&f->plane_normals[5], n_len);

}

bool frustumSphereIntersection(Frustum *f, Vec3 *pos, float radius)
{
    size_t i;
    Vec3 p;
    vec3set(&p, pos);
    for (i = 0; i < 6; ++i)
        if (vec3dot(&p, &f->plane_normals[i]) + f->plane_dists[i] <= -radius)
            return false;
    return true;
}

// bool sphereIntersectsPlane(Plane *pl, Vec3 *pos, float radius)
// {
//     float mag = vec3dot(pos, &pl->normal) + p->distance;
//     return mag > -radius;
// }

/*
void setFrustem(Frustum *f, float fovy, float aspect, float znear, float zfar)
{
    const float an = TO_RAD(fovy);
    const float si = sinf(an);
    const float co = cosf(an);

    // plane_normals[0] = vec3construct(0.0f,  -co, si);
    // plane_normals[1] = vec3construct(0.0f,   co, si);
    // plane_normals[2] = vec3construct(  co, 0.0f, si * aspect);
    // plane_normals[3] = vec3construct( -co, 0.0f, si * aspect);
    // plane_normals[4] = vec3construct(0.0f, 0.0f,  1.0f);
    // plane_normals[5] = vec3construct(0.0f, 0.0f, -1.0f);

    f->planes[ 0] =  0.0f; f->planes[ 1] =  -co;  f->planes[ 2] =  si;        f->planes[ 3] =  0.0f;
    f->planes[ 4] =  0.0f; f->planes[ 5] =   co;  f->planes[ 6] =  si;        f->planes[ 7] =  0.0f;
    f->planes[ 8] =  co;   f->planes[ 9] = 0.0f;  f->planes[10] =  si*aspect; f->planes[11] =  0.0f;
    f->planes[12] = -co;   f->planes[13] = 0.0f;  f->planes[14] =  si*aspect; f->planes[15] =  0.0f;
    f->planes[16] =  0.0f; f->planes[17] = 0.0f;  f->planes[18] =  1.0f;      f->planes[19] =  zfar;
    f->planes[20] =  0.0f; f->planes[21] = 0.0f;  f->planes[22] = -1.0f;      f->planes[23] = -znear;

}
*/

/*
*
if (is_inside_frustum(frustum, box + 6 * i) !=0
    add_to_render_list
*/
