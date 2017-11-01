#ifndef MODELSCENE_H
#define MODELSCENE_H
#include "SceneNode.h"
#include "meshdata.h"
#include "BufferData.h"
#include <stdbool.h>

typedef struct ModelScene {
    SceneObject *root;
    size_t numNodes;
} ModelScene;

ModelScene *newModelScene(BufferData *landscapeData);
void destroyModelScene(ModelScene *wm);
void drawModelScene(ModelScene *wm, GLint uModel, GLint uColor);
void updateModelScene(ModelScene *wm);
void updateModelMatrices(ModelScene *wm);
#endif /* MODELSCENE_H */
