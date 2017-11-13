#ifndef MAT4_FLOAT
#define MAT4_FLOAT
#include "math_types.h"
// #include "Vec3.h"

#define MAT4_SIZE sizeof(float) * 16
#define IDENTITY_MATRIX 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f


Mat4 *newMat4(void) __attribute__ ((malloc));
void destroyMat4(Mat4 *m);

Mat4 *setMat4(Mat4 *dest, const Mat4 *src);
Mat4 *setIdentityMat4(Mat4 *mat);
Mat4 *setTranslationMat4(Mat4 *mat, const Vec3 *v);
Mat4 *setScaledMat4(Mat4 *mat, const Vec3 *v);
Mat4 *setRotationMat4(Mat4 *mat, const Vec3 *v, const float degrees);
Mat4 *setRotXMat4(Mat4 *mat, const float degrees);
Mat4 *setRotYMat4(Mat4 *mat, const float degrees);
Mat4 *setRotZMat4(Mat4 *mat, const float degrees);
Mat4 *setLookAtMat4FP(Mat4 *mat, const Vec3 *tar, const Vec3 *up);
Mat4 *setLookAtMat4(Mat4 *mat, Vec3 *pos, Vec3 *tar, Vec3 *up);
Mat4 *setCameraTransformMat4(Mat4 *mat, const Vec3 *pos, const Vec3 *tar, const Vec3 *up);
Mat4 *setPerspectiveMat4(Mat4 *mat, const float fov, const float aspect, const float near, const float far);

Mat4 *mulMat4(Mat4 *dest, Mat4 *src);
Mat4 *translateMat4(Mat4 *mat, const Vec3 *v);
Mat4 *scaleMat4(Mat4 *mat, const Vec3 *v);
Mat4 *rotateMat4(Mat4 *mat, const Vec3 *v, const float degrees);
Mat4 *rotateXMat4(Mat4 *mat, const float degrees);
Mat4 *rotateYMat4(Mat4 *mat, const float degrees);
Mat4 *rotateZMat4(Mat4 *mat, const float degrees);

void printMat4(Mat4 *m);

#endif /* MAT4_FLOAT */
