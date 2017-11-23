#ifndef ANIMATION_H
#define ANIMATION_H
#include "graphics_math.h"
#include <stdbool.h>
#include <stdlib.h>
#include <GL/glew.h>

typedef struct WindmillAnimation_t {
    unsigned int id;
    // float modelMatrix[5][16];
    // float worldMatrix[5][16];
    // float rotationMatrix[16];

    Mat4 *bodyModelMatrix;
    Mat4 *bodyWorldMatrix;
    Vec3 bodyScale;

    Mat4 *bladeModelMatrix[4];
    Mat4 *bladeWorldMatrix;

    Mat4 *rotationMatrix;
    Mat4 *rotZ;
    Mat4 *rotY;

    Vec3 bladePos[4];
    Vec3 bladeScale[4];
    Vec3 angles;
    Vec3 color[5];
    Vec3 bladeOffsets;

    size_t numParts;
    float angleStep;
    bool rotSet;
    bool fanSet;
} WindmillAnimation_t;

void drawWindmill(WindmillAnimation_t *wa, GLint uModel, GLint uColor, GLsizei ec);
void finalizeWindmillAnimation(WindmillAnimation_t *wa);
WindmillAnimation_t *initWindmillAnimation(WindmillAnimation_t *wa, float x, float y, float z, float size, unsigned int id);
WindmillAnimation_t *animationSwitch(WindmillAnimation_t *wa, bool fanRotation, bool bodyRotation);
WindmillAnimation_t *animateFrame(WindmillAnimation_t *wa);
#endif /* ANIMATION_H */
