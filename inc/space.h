#ifndef SPACE_H
#define SPACE_H
#include "types.h"

struct force {
    float mass, velocity;
};

#define euler_construct(x, y, z) \
    (struct euler){ .yaw = (x), .pitch = (y), .roll = (z) }

#define force_construct(m, v) \
    (struct force){ .mass = (m), .velocity = (v) }

struct space {

    /* orientation in space */
    vec3_t
        pos,
        forward,
        right,
        up;

    euler_t angles;
};

struct transform {
    mat4_t *mmatrix; /* model matrix */
    mat4_t *wmatrix; /* world matrix */

    quat_t rot;      /* rotation */
};

struct bound {
    float  radius;
};



#endif /* SPACE_H */
