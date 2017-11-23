#ifndef QUAT_FLOAT
#define QUAT_FLOAT
#include <stdbool.h>
#include "math_types.h"

/* Scalar and vector parts
 *     r == scalar == float,     v == vector == Vec3
 *     q = (r, v), q E H, r E R, v E (R * R * R)
 *     (r0, v0) + (r1, v1) = (r0 + r1, v0 + v1)
 *     (r0, v0)(r1, v1) = (r0*r1 - dot(v0, v1), r0*v1 + r1*v0 + cross(v0, v1)
 * Unit quaternion
 * Divide a non-zero quaternion by its norm yields a unit quaternion Uq, called the versor
 *              Uq = q/||q||
 * Polar decomposition: q = ||q|| dot Uq
 * For imaginary quaternions
 * Dot product
 * p.q = b0*b1 + c0*c1 + d0*d1 = 1/2(p'q+q'p) = 1/2(pq'+qp')
 * Cross product
 * pxq = (c0*d1 - d0*c1)i + (d0*b1 - b0*d1)j + (b0*c1 - c0*b1)k = 1/2(pq-q'p')
 */




/****************
 *                  Generative functions
 */

/**
 *
 */
#define quat_construct(X,Y,Z,W) \
    (quat_t){ .x = (X), .y = (Y), .z = (Z), .w = (W) }

/**
 *
 */
#define quat_init(dest, X, Y, Z, W) \
    ({ \
        *dest = quat_construct((X),(Y),(Z),(W)); \
    }), dest

/**
 * quat_copy
 */
quat_t quat_copy(quat_t *src);

/**
 * quat_set
 */
quat_t *quat_set(quat_t *dest, const quat_t *src);

/**
 * quat_from_euler
 */
quat_t *quat_from_euler(quat_t *dest, const struct euler *src);

/**
 * quat_from_vec3
 */
quat_t *quat_from_vec3(quat_t *dest, const vec3_t *src);

/**
 * quat_from_mat3
 */
quat_t *quat_from_mat3(quat_t *q, mat3_t *m);





/******************
 *                  Arithmetic
 */

/**
 * quat_add
 */
quat_t *quat_add(quat_t *dest, const quat_t *src);

/**
 * quat_sub
 */
quat_t *quat_sub(quat_t *dest, const quat_t *src);

/**
 * quat_mul
 * For a quaternion in ordered list form:
 * (a0, b0, c0, d0) * (a1, b1, c1, d1) =
 * (a0*a1 - b0*b1 - c0*c1 - d0*d1,
 *  a0*b1 + b0*a1 + c0*d1 - d0*c1,
 *  a0*c1 - b0*d1 + c0*a1 + d0*b1,
 *  a0*d1 + b0*c1 - c0*b1 + d0*a1)
 */
quat_t * quat_mul(quat_t *dest, const quat_t *src);







/****************
 *                  Mutative
 */

/**
 * quat_conjugate
 *
 * Description:
 * Changes the sign of the vector components of the quaternion.
 */
quat_t *quat_conjugate(quat_t *dest);

/**
 * quat_normalize
 *
 * Description:
 * Normalizes to a unit vector.
 */
quat_t *quat_normalize(quat_t *dest);

/**
 * quat_scale
 *
 * Description:
 * Multiplies the vector component of the quaternion by a scalar value.
 */
quat_t *quat_scale(quat_t *dest, float s);

/**
 * quat_inverse
 */
quat_t *quat_inverse(quat_t *dest);





/* * * * * * * * * * * *
 *                      Condition / State
 */

/**
 * quat_norm
 *
 * Description:
 *
 * The dot product of the quaternion with itself.
 * Use to check if the quanternion needs to be
 * normalized.
 */
float quat_len_sqr(const quat_t *q);

/**
 * quat_length
 *
 * Description:
 *
 * The sqare root of the dot product of the
 * quaternion with itself. The magnitude of
 * the quatenion. For unit quaternions, this
 * should be near 1.
 */
float quat_length(const quat_t *dest);

/**
 * quat_dot
 *
 * Description:
 * The dot product of two quaternions. The sum of
 * the products of each quaternions' parts.
 */
float quat_dot(const quat_t *q0, const quat_t *q1);

/**
 * quat_extract_angle
 */
float quat_extract_angle(const quat_t *q);

#endif /* VEC3_FLOAT */
