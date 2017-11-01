

#include <float.h>
bool rayAndTriangleIntersection(const Vec3 *res, const Vec3 *from, const Vec3 *dir, const Vec3 *v0, const Vec3 *v1, const Vec3 *v2)
{
    // area of surface
    Vec3 e1 = (Vec3){ v1.x - v0.x, v1.y - v0.y, v1.z - v0.z };
    Vec3 e2 = (Vec3){ v2.x - v0.x, v2.y - v0.y, v2.z - v0.z };
    Vec3 h;
    // up vector of triangle
    vec3cross(vec3set(&h, dir), &e2);
    float a = vec3dotProduct(&e1, &h);

    if (a > -FLT_EPSILON && a < FLT_EPSILON) // if a == 0.0f
        return false;

    float f = 1.0f / a;

    Vec3 s;
    vec3sub(vec3set(&s, from), v0);
    float u = f * vec3dotProduct(&s, &h);

    if (u < 0.0f || u > 1.0f)
        return false;

}

