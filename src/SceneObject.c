
#include "SceneObject.h"
#include "texture.h"
#include <stdio.h>
#include <math.h>

static SceneObject *_initSceneObject(SceneObject *sn, BufferData *data);

SceneObject *newSceneObject(BufferData *data)
{
    SceneObject *sn = malloc(sizeof(SceneObject));
    return _initSceneObject(sn, data);
}

SceneObject *newSceneObjectFromSceneObject(SceneObject *src)
{
    SceneObject *sn = malloc(sizeof(SceneObject));

    sn->renderMode = src->renderMode;
    sn->modelMatrix = newMat4();
    sn->worldMatrix = newMat4();
    sn->drawMatrix = newMat4();
    vec3set(&sn->position, &src->position);
    vec3set(&sn->scale, &src->scale);
    vec3set(&sn->color, &src->color);
    sn->permanent = false;

    return sn;
}

void destroySceneObject(SceneObject *sn)
{
    destroyMat4(sn->modelMatrix);
    destroyMat4(sn->worldMatrix);
    destroyMat4(sn->drawMatrix);
}

void calcBoundingRadius(SceneObject *sn)
{
    if (!sn) return;
    sn->boundingRadius = vec3length(&sn->scale);
}

/*
void drawHighlightSceneObject(SceneObject *so, GLint uModel)
{
    Mat4 m;
    Vec3 scl = (Vec3){1.1f, 1.1f, 1.1f};
    setMat4(&m, so->drawMatrix);
    scaleMat4(&m, &scl);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, m.data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

void drawTextureSceneObject(SceneObject *so, GLint uModel, GLint uTexture)
{
    glActiveTexture(so->activeTexture);
    glBindTexture(GL_TEXTURE_2D, so->texture);
    glUniform1i(uTexture, so->textureIndex);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// void drawColorSceneObject(SceneObject *so, GLint uModel, GLint uColor)
void drawColorSceneObject(SceneObject *so, MaterialShader *sh, Vec3 *campos)
{

    glUniform3fv(sh->uMaterial.ambient, 1, (float *)&so->material.ambient);
    glUniform3fv(sh->uMaterial.diffuse, 1, (float *)&so->material.diffuse);
    glUniform3fv(sh->uMaterial.specular, 1, (float *)&so->material.specular);
    glUniform3fv(sh->uCamPos, 1, (float *)campos);
    glUniform3fv(sh->uWorldPos, 1, (float *)&so->position);
    glUniform1f(sh->uMaterial.shininess, so->material.shininess);

    // glUniform3fv(uColor, 1, (float *)&so->color);
    glUniformMatrix4fv(sh->uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

void drawDebugColorSceneObject(SceneObject *so, GLint uModel, GLint uColor)
{
    glUniform3fv(uColor, 1, (float *)&so->color);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, so->drawMatrix->data);
    // glDrawElements(GL_TRIANGLES, sn->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    glDrawElements(GL_POINTS, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    glDrawElements(GL_LINE_LOOP, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

void drawSceneObject(SceneObject *sn, GLint uModel, GLint uColor)
{
    glUniform3fv(uColor, 1, (float *)&sn->color);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, sn->drawMatrix->data);
    glDrawElements(GL_TRIANGLES, sn->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}
*/

void updateObjectDistFromCam(SceneObject *sn, Vec3 *camPos)
{
    Vec3 p = (Vec3){sn->position.x, sn->position.y, sn->position.z};
    sn->distFromCam = vec3dotProduct(&p, camPos);
}

void setSceneObjectWorldFromSceneObject(SceneObject *dest, SceneObject *src)
{
    setMat4(dest->worldMatrix, src->worldMatrix);
}

void setSceneObjectWorldFromModel(SceneObject *so)
{
    setMat4(so->worldMatrix, so->modelMatrix);
}

void updateSceneObjectWorldMatrix(SceneObject *so)
{
    mulMat4(so->worldMatrix, so->modelMatrix);
}

void updateSceneObjectMatrices(SceneObject *sn)
{
    setMat4(sn->drawMatrix, sn->worldMatrix);
    scaleMat4(sn->drawMatrix, &sn->scale);
}

void addSceneObjectTexture(SceneObject *sn, size_t index)
{
    Texture *t = getTexture(index);
    sn->texture = t->tex;
    sn->activeTexture = t->activeTexture;
    sn->textureIndex = t->index;
    sn->renderMode = RENDER_TEXTURE;
}

int compareCameraDists(SceneObject *a, SceneObject *b)
{
    float dist_a = fabsf(a->distFromCam);
    float dist_b = fabsf(b->distFromCam);
    return dist_a > dist_b ? 1 : dist_b > dist_a ? -1 : 0;
}

static SceneObject *_initSceneObject(SceneObject *sn, BufferData *data)
{
    sn->renderMode = RENDER_COLOR;
    sn->name = NULL;
    sn->modelMatrix = newMat4();
    sn->worldMatrix = newMat4();
    sn->drawMatrix = newMat4();
    sn->position = (Vec3){ 0.0f, 0.0f, 0.0f };
    sn->scale = (Vec3){ 1.0f, 1.0f, 1.0f };
    sn->color = (Vec3){ 0.5f, 0.5f, 0.5f };
    sn->bufferData = data;
    return sn;
}

bool pointInSceneObjectRadius(SceneObject *so, Vec3 *pt)
{
    if (pointInSphere(pt, &so->position, so->boundingRadius) && !so->permanent) {
        // printf("%s collision at: %.2f %.2f %.2f\n", so->name, pt->x, pt->y, pt->z);
        so->renderMode |= RENDER_HIGHLIGHT;
        so->highLight = true;
        return true;
    }
    so->highLight = false;
    so->renderMode &= ~RENDER_HIGHLIGHT;
    return false;
}

