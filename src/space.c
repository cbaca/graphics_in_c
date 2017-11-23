
#include "space.h"

void space_init(struct space *s)
{
    s->position = s->front = s->right = s->up = vec3_construct(0.f, 0.f, 0.f);
    s->orientation = euler_construct(0.f, 0.f, 0.f);
    s->force = force_construct(0.f, 0.f, 0.f);
}

void space_calc_vectors_from_eulers(struct space *s)
{
    const float y = TO_RAD(s->orientation.yaw);
    const float p = TO_RAD(s->orientation.pitch);
    const float cp = cosf(pitch);
    const Vec3 w = vec3_construct(0.f, 1.f, 0.f);

    Vec3 *world =        &w,
         *front = &s->front,
         *right = &s->right,
         *up    =    &s->up;


    s->front = vec3_construct(cosf(y) * cp, sinf(p), sinf(y) * cp);
    s->right = vec3_copy_cross(front, world);
    s->up = vec3_copy_cross(right, front);
    s->target = vec3copyAdd(&s->position, front);
}


