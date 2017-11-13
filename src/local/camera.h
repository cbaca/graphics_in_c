#ifndef LOCALCAMERA_H
#define LOCALCAMERA_H
#include "Camera.h"

Camera *_cameraInit(Camera *c, Vec3 *pos, float x, float y);

void _cameraMoveForward(Camera *c);
void _cameraMoveBackward(Camera *c);
void _cameraMoveLeft(Camera *c);
void _cameraMoveRight(Camera *c);
void _cameraMoveDown(Camera *c);
void _cameraMoveUp(Camera *c);

void _camD_callback(void *c);
void _camU_callback(void *c);
void _camL_callback(void *c);
void _camR_callback(void *c);
void _camF_callback(void *c);
void _camB_callback(void *c);
#endif // LOCALCAMERA_H
