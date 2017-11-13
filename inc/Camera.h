#ifndef CAMERA_H
#define CAMERA_H
#include "types.h"
#include <math.h>

typedef enum CameraMode {
    CAMERAMODE_FIRSTPERSON,
    CAMERAMODE_THIRDPERSON,
} CameraMode;

typedef struct camera_t Camera;

Camera *new_camera(Vec3 *pos);

void destroy_camera(Camera *c);

// Camera_t *cameraUpdateEvent(Camera_t *c);
Camera *update_camera(Camera *c);

void init_camera_movement_control_callbacks(Camera *c);

Mat4 *get_camera_lookat_matrix(Camera *c, Mat4 *viewMatrix);

Mat4 *get_camera_perspective_matrix(Camera *c, Mat4 *p);

Mat4 *get_camera_view_matrix(Camera *c, Mat4 *viewMatrix);

Vec3 get_camera_target_as(Camera *c, const Vec3 *obj_pos);

Vec3 *get_camera_target(Camera *c);

Vec3 *get_camera_position(Camera *c);

float *get_resolution_from_camera(Camera *c);

float *get_mouse_from_camera(Camera *c);

void set_camera_dist(Camera *c, float d);
#endif /* CAMERA_H */
