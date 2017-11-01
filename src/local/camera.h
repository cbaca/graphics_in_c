#ifndef LOCALCAMERA_H
#define LOCALCAMERA_H
#include "Camera.h"

Camera_t *_cameraInit(Camera_t *c, Vec3 *pos, float x, float y);

void _cameraMoveForward(Camera_t *c);
void _cameraMoveBackward(Camera_t *c);
void _cameraMoveLeft(Camera_t *c);
void _cameraMoveRight(Camera_t *c);
void _cameraMoveDown(Camera_t *c);
void _cameraMoveUp(Camera_t *c);

void _camD_callback(void *c);
void _camU_callback(void *c);
void _camL_callback(void *c);
void _camR_callback(void *c);
void _camF_callback(void *c);
void _camB_callback(void *c);
#endif // LOCALCAMERA_H
