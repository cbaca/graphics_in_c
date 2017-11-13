#ifndef MAT4_FLOAT
#define MAT4_FLOAT
#include "math_types.h"

/**
 * Make a new instance of Mat4 and return pointer.
 */
Mat4 *newMat4(void) __attribute__ ((malloc));

/**
 * Destroy instance of Mat4.
 */
void destroyMat4(Mat4 *m);

Mat4 *setMat4(Mat4 *dest, const Mat4 *src);

Mat4 *setIdentityMat4(Mat4 *mat);

Mat4 *setTranslationMat4(Mat4 *mat, const Vec3 *v);

Mat4 *setScaledMat4(Mat4 *mat, const Vec3 *v);

Mat4 *setRotationMat4(Mat4 *mat, const Vec3 *v, const float degrees);

Mat4 *setRotXMat4(Mat4 *mat, const float degrees);

Mat4 *setRotYMat4(Mat4 *mat, const float degrees);

Mat4 *setRotZMat4(Mat4 *mat, const float degrees);

Mat4 *mulMat4(Mat4 *dest, Mat4 *src);

Mat4 *translateMat4(Mat4 *mat, const Vec3 *v);

Mat4 *scaleMat4(Mat4 *mat, const Vec3 *v);

Mat4 *rotateMat4(Mat4 *mat, const Vec3 *v, const float degrees);

Mat4 *rotateXMat4(Mat4 *mat, const float degrees);

Mat4 *rotateYMat4(Mat4 *mat, const float degrees);

Mat4 *rotateZMat4(Mat4 *mat, const float degrees);

/**
 * perspective matrix:
 * |              1                                                              |
 * |    ---------------------         0               0               0          |
 * |    aspect * tan(ang / 2)                                                    |
 * |                                  1                                          |
 * |                            ------------          0               0          |
 * |             0              tan(ang / 2)                                     |
 * |                                            -near - far    2 * Far * Near    |
 * |             0                    0       -------------     --------------   |
 * |                                            near - far        Near - Far     |
 */
Mat4 *setPerspectiveMat4(Mat4 *mat, const float fov, const float aspect, const float near, const float far);

Mat4 *setLookAtMat4(Mat4 *mat, Vec3 *pos, Vec3 *tar, Vec3 *up);

Mat4 *setLookAtMat4FP(Mat4 *mat, const Vec3 *tar, const Vec3 *up);

Mat4 *setCameraTransformMat4(Mat4 *mat, const Vec3 *pos, const Vec3 *tar, const Vec3 *up);

void printMat4(Mat4 *m);

#endif /* MAT4_FLOAT */
