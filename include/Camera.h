#ifndef CAMERA_H
#define CAMERA_H
#include "Maths.h"
#include <math.h>

typedef enum CameraMode {
    CAMERAMODE_FIRSTPERSON,
    CAMERAMODE_THIRDPERSON,
} CameraMode;

// typedef struct Camera_t {
//     Vec3 position, front, forward, up, world, right, target;
//     float dist, yaw, pitch, velocity, sensitivity, lastX, lastY, fov, far, near;
// } Camera_t;
typedef struct Camera_t Camera_t;

Camera_t *newCamera(Vec3 *pos);
void destroyCamera(Camera_t *c);
Camera_t *cameraUpdateEvent(Camera_t *c);
void setCameraCallbacks(Camera_t *c);
Camera_t *cameraSetView(Camera_t *c, Mat4 *viewMatrix);
void cameraSetPerspective(Camera_t *c, Mat4 *p);
Vec3 *getCameraTarget(Camera_t *c);
Vec3 *getCameraPosition(Camera_t *c);
Vec3 *getCameraRay(Camera_t *c);
void cameraSetLookAt(Camera_t *c, Mat4 *viewMatrix);
#endif /* CAMERA_H */
