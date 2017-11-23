#include "Animation.h"
#include "graphics_math.h"
#include <stdio.h>

const float DefaultStep = 1.81f; // 2.0f
static WindmillAnimation_t *_doFanAnimation(WindmillAnimation_t *wa);

#define BLADE_LEN 4

void finalizeWindmillAnimation(WindmillAnimation_t *wa)
{
    int i;
    for (i = 0; i < BLADE_LEN; ++i) {
        destroyMat4(wa->bladeModelMatrix[i]);
    }
    destroyMat4(wa->bodyModelMatrix);
    destroyMat4(wa->bodyWorldMatrix);
    destroyMat4(wa->bladeWorldMatrix);
    destroyMat4(wa->rotationMatrix);
    destroyMat4(wa->rotZ);
    destroyMat4(wa->rotY);
}

WindmillAnimation_t *initWindmillAnimation(WindmillAnimation_t *wa, float x, float y, float z, float size, unsigned int id)
{
    wa->id = id;
    int i;
    for (i = 0; i < BLADE_LEN; ++i) wa->bladeModelMatrix[i] = newMat4();
    wa->bodyModelMatrix = newMat4();
    wa->bodyWorldMatrix = newMat4();
    wa->bladeWorldMatrix = newMat4();
    wa->rotationMatrix = newMat4();
    wa->rotZ = newMat4();
    wa->rotY = newMat4();

    wa->numParts = 5;
    wa->angleStep = DefaultStep;
    float locx = x;
    float locy = y;
    float locz = z;
    float asize = size;
    float bodyHeight = asize;
    float bodyScl = bodyHeight * 0.05f;
    float bodyBase = bodyHeight * 0.50f + locy;
    float bladeLen = bodyHeight * 0.4f;
    float bladeWid = bodyHeight * 0.06f;
    float bladeThickness = bodyHeight * 0.005f;
    float hubDistance = bodyHeight * 0.125f;
    float hubRadius = bladeLen * 1.2f;
    float bladeOrientation = 0.0f;

    // body position and scale
    {
        Vec3 bodyPos =  (Vec3){ locx,      bodyBase, locz };
        wa->bodyScale =     (Vec3){ bodyScl, bodyHeight, bodyScl };
        mat4setTranslate(wa->bodyWorldMatrix, &bodyPos);
        mat4set(wa->bodyModelMatrix, wa->bodyWorldMatrix);
    }

    // blades position
    {
        vec3init(&wa->bladePos[0],         hubRadius,  bladeOrientation, hubDistance);
        vec3init(&wa->bladePos[1],  bladeOrientation,         hubRadius, hubDistance);
        vec3init(&wa->bladePos[2],        -hubRadius, -bladeOrientation, hubDistance);
        vec3init(&wa->bladePos[3], -bladeOrientation,        -hubRadius, hubDistance);
        // Vec3 v = (Vec3){ locx, bodyHeight, locz };
        // mat4setTranslate(wa->bladeWorldMatrix, &v);
        mat4set(wa->bladeWorldMatrix, wa->bodyWorldMatrix);
    }

    // blades scale
    {

        vec3init(&wa->bladeScale[0], bladeLen,  bladeWid, bladeThickness);
        vec3init(&wa->bladeScale[1], bladeWid,  bladeLen, bladeThickness);
        vec3init(&wa->bladeScale[2], bladeLen,  bladeWid, bladeThickness);
        vec3init(&wa->bladeScale[3], bladeWid,  bladeLen, bladeThickness);

    }

    // colors, etc ...
    {

        wa->color[0] = (Vec3){ 0.1f, 0.0f, 0.1f };
        wa->color[1] = wa->color[2] = wa->color[3] = wa->color[4] = (Vec3){ 0.1f, 0.1f, 0.1f };

        vec3init(&wa->angles, wa->angleStep, wa->angleStep, wa->angleStep);
    }


    mat4rotateY(wa->bodyModelMatrix, wa->angles.y);
    _doFanAnimation(wa);
    mat4scale(wa->bodyModelMatrix, &wa->bodyScale);

    return wa;
}

WindmillAnimation_t *animationSwitch(WindmillAnimation_t *wa, bool fanRotation, bool bodyRotation)
{
    wa->rotSet = bodyRotation;
    wa->fanSet = fanRotation;
    return wa;
}


WindmillAnimation_t *_doFanAnimation(WindmillAnimation_t *wa)
{
    int i;
    mat4multiply(wa->rotY, wa->rotZ);
    for (i = 0; i < BLADE_LEN; ++i) {
        mat4set(wa->bladeModelMatrix[i], wa->bladeWorldMatrix);
        mat4multiply(wa->bladeModelMatrix[i], wa->rotY);          // rotate
        mat4translate(wa->bladeModelMatrix[i], &wa->bladePos[i]); // translate
        mat4scale(wa->bladeModelMatrix[i], &wa->bladeScale[i]);        // scale
    }

    return wa;
}

void _rotateWindmillY(WindmillAnimation_t *wa)
{
    wa->angles.y += wa->angleStep;
    if (wa->angles.y >= 360.0f) wa->angles.y = 0.0f;
    mat4set(wa->bodyModelMatrix, wa->bodyWorldMatrix);
    mat4multiply(wa->bodyModelMatrix, wa->rotY);
    mat4scale(wa->bodyModelMatrix, &wa->bodyScale);
}

WindmillAnimation_t *animateFrame(WindmillAnimation_t *wa)
{
    if (!wa->rotSet && !wa->fanSet)
        return NULL;

    mat4setRotateY(wa->rotY, wa->angles.y);
    mat4setRotateZ(wa->rotZ, wa->angles.z);

    if (wa->rotSet) {
        /*
        wa->angles.y += wa->angleStep;
        if (wa->angles.y >= 360.0f) wa->angles.y = 0.0f;

        mat4set(wa->bodyModelMatrix, wa->bodyWorldMatrix);
        mat4multiply(wa->bodyModelMatrix, wa->rotY);
        mat4scale(wa->bodyModelMatrix, &wa->bodyScale);
        */
        _rotateWindmillY(wa);
    }

    /*
    if (wa->fanSet) {
        wa->angles.z += wa->angleStep;
        if (wa->angles.z > 360.0f) wa->angles.z = 0.0f;
    }
    _doFanAnimation(wa);
    */
    return wa;
}

void drawWindmill(WindmillAnimation_t *wa, GLint uModel, GLint uColor, GLsizei ec)
{
    glUniform3fv(uColor, 1, (float *)&wa->color[0]);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, wa->bodyModelMatrix->data);
    glDrawElements(GL_TRIANGLES, ec, GL_UNSIGNED_INT, 0);
    int i;
    for (i = 0; i < BLADE_LEN; ++i) {
        glUniform3fv(uColor, 1, (float *)&wa->color[i + 1]);
        glUniformMatrix4fv(uModel, 1, GL_FALSE, wa->bladeModelMatrix[i]->data);
        glDrawElements(GL_TRIANGLES, ec, GL_UNSIGNED_INT, 0);
    }
}
