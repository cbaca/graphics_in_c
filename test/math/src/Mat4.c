#include "Mat4.h"
#include "Vec3.h"
#include <float.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#define MAT4SET(mat, v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15) \
    mat->data[ 0] =  v0; mat->data[ 1] =  v1; mat->data[ 2] =  v2; mat->data[ 3] =  v3; \
    mat->data[ 4] =  v4; mat->data[ 5] =  v5; mat->data[ 6] =  v6; mat->data[ 7] =  v7; \
    mat->data[ 8] =  v8; mat->data[ 9] =  v9; mat->data[10] = v10; mat->data[11] = v11; \
    mat->data[12] = v12; mat->data[13] = v13; mat->data[14] = v14; mat->data[15] = v15;

#define MAT4SET_IDENTITY(mat) \
    mat->data[ 0] = 1.0f; mat->data[ 1] = 0.0f; mat->data[ 2] = 0.0f; mat->data[ 3] = 0.0f; \
    mat->data[ 4] = 0.0f; mat->data[ 5] = 1.0f; mat->data[ 6] = 0.0f; mat->data[ 7] = 0.0f; \
    mat->data[ 8] = 0.0f; mat->data[ 9] = 0.0f; mat->data[10] = 1.0f; mat->data[11] = 0.0f; \
    mat->data[12] = 0.0f; mat->data[13] = 0.0f; mat->data[14] = 0.0f; mat->data[15] = 1.0f;

Mat4 *newMat4(void)
{
    Mat4 *m = malloc(sizeof(Mat4));
    MAT4SET_IDENTITY(m);
    return m;
}

void destroyMat4(Mat4 *m)
{
    if (m)
        free(m);
}

Mat4 *setMat4(Mat4 *dest, const Mat4 *src)
{
    memcpy(dest, src, SIZEOFMAT4);
    return dest;
}

Mat4 *setIdentityMat4(Mat4 *mat)
{
    MAT4SET_IDENTITY(mat);
    return mat;
}

Mat4 *setTranslationMat4(Mat4 *m, const Vec3 *v)
{
    MAT4SET(m, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, v->x, v->y, v->z, 1.0f);
    return m;
}

Mat4 *setScaledMat4(Mat4 *mat, const Vec3 *v)
{
    MAT4SET(mat, v->x, 0.0f, 0.0f, 0.0f, 0.0f, v->y, 0.0f, 0.0f, 0.0f, 0.0f, v->z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
    return mat;
}

Mat4 *setRotationMat4(Mat4 *mat, const Vec3 *v, const float degrees)
{
    const float rad = TO_RAD(degrees);

    const float c = cosf(rad);
    const float s = sinf(rad);

    const float nc = 1.0f - c;
    const float zs = v->z * s;
    const float ys = v->y * s;
    const float xs = v->x * s;
    const float xy = v->x * v->y;
    const float xz = v->x * v->z;
    const float yz = v->y * v->z;
    const float xync = xy * nc;
    const float xznc = xz * nc;
    const float yznc = yz * nc;

    mat->data[ 0] = v->x * v->x * nc + c;
    mat->data[ 1] = xync + zs;
    mat->data[ 2] = xznc - ys;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = xync - zs;
    mat->data[ 5] = v->y * v->y * nc + c;
    mat->data[ 6] = yznc + xs;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = xznc + ys;
    mat->data[ 9] = yznc - xs;
    mat->data[10] = v->z * v->z * nc + c;
    mat->data[11] = 0.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = 0.0f;
    mat->data[15] = 1.0f;
    return mat;
}

Mat4 *setRotXMat4(Mat4 *mat, const float degrees)
{
    // const float radians = PI * degrees / 180.0f;
    const float radians = TO_RAD(degrees);
    float s = sinf(radians);
    float c = cosf(radians);
    mat->data[ 0] = 1.0f;
    mat->data[ 1] = 0.0f;
    mat->data[ 2] = 0.0f;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = 0.0f;
    mat->data[ 5] = c;
    mat->data[ 6] = s;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = 0.0f;
    mat->data[ 9] = -s;
    mat->data[10] = c;
    mat->data[11] = 0.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = 0.0f;
    mat->data[15] = 1.0f;
    return mat;
}

Mat4 *setRotYMat4(Mat4 *mat, const float degrees)
{
    // const float radians = PI * degrees / 180.0f;
    const float radians = TO_RAD(degrees);
    float s = sinf(radians);
    float c = cosf(radians);
    mat->data[ 0] = c;
    mat->data[ 1] = 0.0f;
    mat->data[ 2] = -s;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = 0.0f;
    mat->data[ 5] = 1.0f;
    mat->data[ 6] = 0.0f;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = s;
    mat->data[ 9] = 0.0f;
    mat->data[10] = c;
    mat->data[11] = 0.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = 0.0f;
    mat->data[15] = 1.0f;
    return mat;
}

Mat4 *setRotZMat4(Mat4 *mat, const float degrees)
{
    // const float radians = PI * degrees / 180.0f;
    const float radians = TO_RAD(degrees);
    float s = sinf(radians);
    float c = cosf(radians);
    mat->data[ 0] = c;
    mat->data[ 1] = s;
    mat->data[ 2] = 0.0f;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = -s;
    mat->data[ 5] = c;
    mat->data[ 6] = 0.0f;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = 0.0f;
    mat->data[ 9] = 0.0f;
    mat->data[10] = 1.0f;
    mat->data[11] = 0.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = 0.0f;
    mat->data[15] = 1.0f;
    return mat;
}

Mat4 *mulMat4(Mat4 *dest, Mat4 *src)
{
    float c[4];
    int i;
    float *r = src->data;
    float d[16];
    memcpy(d, dest->data, MAT4_SIZE);
    for (i = 0; i < 4; ++i) {
        c[0] = d[i];
        c[1] = d[i + 0x4];
        c[2] = d[i + 0x8];
        c[3] = d[i + 0xc];

        dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
        dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
        dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
        dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
    }

    return dest;
}

Mat4 *translateMat4(Mat4 *m, const Vec3 *v)
{
    float *mat = m->data;
    mat[12] += mat[0] * v->x + mat[4] * v->y + mat[ 8] * v->z;
    mat[13] += mat[1] * v->x + mat[5] * v->y + mat[ 9] * v->z;
    mat[14] += mat[2] * v->x + mat[6] * v->y + mat[10] * v->z;
    mat[15] += mat[3] * v->x + mat[7] * v->y + mat[11] * v->z;
    return m;
}

Mat4 *scaleMat4(Mat4 *mat, const Vec3 *v)
{
    mat->data[ 0] *= v->x; mat->data[ 1] *= v->x; mat->data[ 2] *= v->x; mat->data[ 3] *= v->x;
    mat->data[ 4] *= v->y; mat->data[ 5] *= v->y; mat->data[ 6] *= v->y; mat->data[ 7] *= v->y;
    mat->data[ 8] *= v->z; mat->data[ 9] *= v->z; mat->data[10] *= v->z; mat->data[11] *= v->z;
    return mat;
}

Mat4 *rotateMat4(Mat4 *mat, const Vec3 *v, const float degrees)
{
    Mat4 tmp;
    memcpy(tmp.data, mat->data, MAT4_SIZE);
    return mulMat4(mat, setRotationMat4(&tmp, v, degrees));
}

Mat4 *rotateXMat4(Mat4 *mat, const float degrees)
{
    Mat4 tmp;
    return mulMat4(mat, setRotXMat4(setMat4(&tmp, mat), degrees));
}

Mat4 *rotateYMat4(Mat4 *mat, const float degrees)
{
    Mat4 tmp;
    return mulMat4(mat, setRotYMat4(setMat4(&tmp, mat), degrees));
}

Mat4 *rotateZMat4(Mat4 *mat, const float degrees)
{
    Mat4 tmp;
    return mulMat4(mat, setRotZMat4(setMat4(&tmp, mat), degrees));
}

Mat4 *setPerspectiveMat4(Mat4 *mat, const float fov, const float aspect, const float near, const float far)
{
    float rdist = 1.0f / (far - near);

    float rad = PI * fov / 180.0f / 2.0f;
    float cot = cosf(rad) / sinf(rad);

    mat->data[ 0] = cot / aspect;
    mat->data[ 1] = 0.0f;
    mat->data[ 2] = 0.0f;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = 0.0f;
    mat->data[ 5] = cot;
    mat->data[ 6] = 0.0f;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = 0.0f;
    mat->data[ 9] = 0.0f;
    mat->data[10] = -(far + near) * rdist;
    mat->data[11] = -1.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = -2 * near * far * rdist;
    mat->data[15] = 0.0f;

    return mat;
}

Mat4 *setLookAtMat4(Mat4 *mat, Vec3 *pos, Vec3 *tar, Vec3 *up)
{
    Vec3 forward;
    Vec3 side;
    Vec3 top;

    forward = vec3copy(tar);
    forward = vec3copySub(&forward, pos);
    vec3normalize(&forward);

    side = vec3copy(&forward);
    side = vec3copyCross(&side, up);
    vec3normalize(&side);

    top = vec3copy(&side);
    top = vec3copyCross(&top, &forward);

    mat->data[ 0] = side.x;
    mat->data[ 1] = top.x;
    mat->data[ 2] = -forward.x;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = side.y;
    mat->data[ 5] = top.y;
    mat->data[ 6] = -forward.y;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = side.z;
    mat->data[ 9] = top.z;
    mat->data[10] = -forward.z;
    mat->data[11] = 0.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = 0.0f;
    mat->data[15] = 1.0f;
    return mat;
}

Mat4 *setLookAtMat4FP(Mat4 *mat, const Vec3 *tar, const Vec3 *up)
{
    Vec3 n, u, v; // forward, right, up
    vec3normalize(vec3set(&n, tar));
    vec3normalize(vec3cross(vec3set(&u, up), tar));
    vec3cross(vec3set(&v, &n), &u);

    mat->data[ 0] = u.x;
    mat->data[ 1] = u.y;
    mat->data[ 2] = u.z;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = v.x;
    mat->data[ 5] = v.y;
    mat->data[ 6] = v.z;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = n.x;
    mat->data[ 9] = n.y;
    mat->data[10] = n.z;
    mat->data[11] = 0.0f;

    mat->data[12] = 0.0f;
    mat->data[13] = 0.0f;
    mat->data[14] = 0.0f;
    mat->data[15] = 1.0f;

    return mat;
}

Mat4 *setCameraTransformMat4(Mat4 *mat, const Vec3 *pos, const Vec3 *tar, const Vec3 *up)
{
    Vec3 f, s, u; // forward, right, up
    vec3normalize(vec3sub(vec3set(&f, tar), pos));
    vec3normalize(vec3cross(vec3set(&s, &f), up));
    vec3cross(vec3set(&u, &s), &f);

    mat->data[ 0] = s.x;
    mat->data[ 1] = u.x;
    mat->data[ 2] = -f.x;
    mat->data[ 3] = 0.0f;

    mat->data[ 4] = s.y;
    mat->data[ 5] = u.y;
    mat->data[ 6] = -f.y;
    mat->data[ 7] = 0.0f;

    mat->data[ 8] = s.z;
    mat->data[ 9] = u.z;
    mat->data[10] = -f.z;
    mat->data[11] = 0.0f;

    mat->data[12] = -vec3dotProduct(&s, pos);
    mat->data[13] = -vec3dotProduct(&u, pos);
    mat->data[14] = vec3dotProduct(&f, pos);
    mat->data[15] = 1.0f;
    return mat;
}

void printMat4(Mat4 *m)
{
    float *d = m->data;
    size_t i;
    for (i = 0; i < 4; ++i) {
        printf("%+-.2f %+-.2f %+-.2f %+-.2f\n", d[0], d[1], d[2], d[3]);
        d+= 4;
    }
}

/*
Mat4 *setScaledFactorMat4(Mat4 *mat, const Vec3 *v, const float k)
{
    float fact = k - 1.0f;
    float fxy = fact * v->x * v->y;
    float fxz = fact * v->x * v->z;
    float fyz = fact * v->y * v->z;

    MAT4SET(mat, 1 + fact * v->x * v->x, fxy, fxz, 0.0f, fxy, 1 + fact * v->y * v->y,
            fyz, 0.0f, fxz, fyz, 1 + fact * v->z * v->z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);

    return mat;
}

Mat4 *setFrustumMat4(Mat4 *m, float left, float right, float bottom, float top, float near, float far)
{
    assert(near > 0.0f);
    assert(far > 0.0f);

    float rW = 1.0f / (right - left);
    float rH = 1.0f / (top - bottom);
    float rDist = 1.0f / (far - near);
    float near2 = 2.0f  * near;

    m->data[ 0] = near2 * rW;
    m->data[ 1] = 0.0f;
    m->data[ 2] = 0.0f;
    m->data[ 3] = 0.0f;

    m->data[ 4] = 0.0f;
    m->data[ 5] = near2 * rH;
    m->data[ 6] = 0.0f;
    m->data[ 7] = 0.0f;

    m->data[ 8] = (right + left) * rW;
    m->data[ 9] = (top + bottom) * rH;
    m->data[10] = -(far + near) * rDist;
    m->data[11] = -1.0f;

    m->data[12] = 0.0f;
    m->data[13] = 0.0f;
    m->data[14] = -near2 * far * rDist;
    m->data[15] = 0.0f;
    return m;
}
*/
