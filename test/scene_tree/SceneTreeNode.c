
#include "SceneTreeNode.h"
#include "texture.h"
#include <stdio.h>
#include <math.h>

// static SceneTreeNode *_initSceneTreeNode(SceneTreeNode *sn, BufferData *data);

void pushSceneTreeNodeToRenderList(SceneTreeNode *stn, RenderList *rl)
{
    size_t i;
    for (i = 0; i < stn->num_children; ++i)
        pushSceneTreeNodeToRenderList(stn->child[i], rl);
    if (stn->object->renderMode == getRenderListRenderMode(rl))
        pushSceneObject(rl, stn->object);
}

SceneTreeNode *newSceneTreeNode(SceneObject *so)
{
    SceneTreeNode *stn = malloc(sizeof(SceneTreeNode));
    stn->object = so;
    stn->num_children = 0;
    stn->max_children = 0;
    stn->parent = NULL;
    stn->child = NULL;
    return stn;
}

void destroySceneTreeNode(SceneTreeNode *sn)
{
    size_t i;
    for (i = 0; i < sn->num_children; ++i)
        destroySceneTreeNode(sn->child[i]);
    sn->num_children = 0;

    if (sn->child) {
        free(sn->child);
        sn->child = NULL;
    }
    if (sn) {
        free(sn);
        sn = NULL;
    }
}

void insertChildSceneTreeNode(SceneTreeNode *dest, SceneObject *src_so)
{
    SceneTreeNode *src = newSceneTreeNode(src_so);
    if (dest->max_children == 0) {
        dest->max_children = 10;
        dest->child = malloc(sizeof(SceneTreeNode *) * dest->max_children);
    }
    dest->child[dest->num_children] = src;
    dest->child[dest->num_children++]->parent = dest;
    if (dest->max_children <= dest->num_children) {
        dest->max_children *= 2;
        SceneTreeNode **temp = realloc(dest->child, dest->max_children * sizeof(SceneTreeNode *));
        dest->child = temp;
    }
}

void drawSceneTreeNode(SceneTreeNode *sn, GLint uModel, GLint uColor)
{
    // glUniform3fv(uColor, 1, (float *)&sn->color);
    // glUniformMatrix4fv(uModel, 1, GL_FALSE, sn->drawMatrix->data);
    // glDrawElements(GL_TRIANGLES, sn->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    drawSceneObject(sn->object, uModel, uColor);
    size_t i;
    for (i = 0; i < sn->num_children; ++i)
        drawSceneTreeNode(sn->child[i], uModel, uColor);
}

void updateSceneTreeNode(SceneTreeNode *sn)
{
    if (!sn) return;
    if (sn->parent) {
        setSceneObjectWorldFromSceneObject(sn->object, sn->parent->object);
        updateSceneObjectWorldMatrix(sn->object);
        // setMat4(sn->worldMatrix, sn->parent->worldMatrix);
        // mulMat4(sn->worldMatrix, sn->modelMatrix);
    } else {
        setSceneObjectWorldFromModel(sn->object);
        // setMat4(sn->worldMatrix, sn->modelMatrix);
    }

    size_t i;
    for (i = 0; i < sn->num_children; ++i)
        updateSceneTreeNode(sn->child[i]);
}

void updateSceneTreeNodeMatrices(SceneTreeNode *sn)
{
    // setMat4(sn->drawMatrix, sn->worldMatrix);
    // scaleMat4(sn->drawMatrix, &sn->scale);
    updateSceneObjectMatrices(sn->object);
    size_t i;
    for (i = 0; i < sn->num_children; ++i)
        updateSceneTreeNodeMatrices(sn->child[i]);
}

void addSceneTreeNodeTexture(SceneTreeNode *sn, size_t index)
{
    // Texture *t = getTexture(index);
    // sn->texture = t->tex;
    // sn->activeTexture = t->activeTexture;
    // sn->textureIndex = t->index;
    // sn->renderMode = RENDER_TEXTURE;
    addSceneObjectTexture(sn->object, index);
    size_t i;
    for (i = 0; i < sn->num_children; ++i)
        addSceneTreeNodeTexture(sn->child[i], index);
}

/*
static SceneTreeNode *_initSceneTreeNode(SceneTreeNode *sn, BufferData *data)
{
    sn->renderMode = RENDER_COLOR;
    sn->name = NULL;
    sn->modelMatrix = newMat4();
    sn->worldMatrix = newMat4();
    sn->drawMatrix = newMat4();
    sn->position = (Vec3){ 0.0f, 0.0f, 0.0f };
    sn->scale = (Vec3){ 1.0f, 1.0f, 1.0f };
    sn->color = (Vec3){ 0.5f, 0.5f, 0.5f };
    sn->num_children = 0;
    sn->max_children = 0;
    sn->bufferData = data;
    sn->child = NULL;
    sn->parent = NULL;
    return sn;
}
*/

/*
SceneTreeNode *newSceneTreeNodeFromSceneTreeNode(SceneTreeNode *src)
{
    SceneTreeNode *sn = malloc(sizeof(SceneTreeNode));

    sn->renderMode = src->renderMode;
    sn->modelMatrix = newMat4();
    sn->worldMatrix = newMat4();
    sn->drawMatrix = newMat4();
    vec3set(&sn->position, &src->position);
    vec3set(&sn->scale, &src->scale);
    vec3set(&sn->color, &src->color);
    sn->num_children = 0;
    sn->max_children = 0;
    sn->bufferData = src->bufferData;
    sn->child = NULL;
    sn->parent = NULL;
    sn->next = NULL;

    return sn;
}
*/

