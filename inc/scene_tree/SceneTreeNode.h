#ifndef SCENETREENODE_H
#define SCENETREENODE_H
#include "RenderList.h"
#include "BufferData.h"
#include "Maths.h"
#include <GL/glew.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct SceneTreeNode SceneTreeNode;

struct SceneTreeNode {
    SceneObject *object;
    size_t num_children;
    size_t max_children;
    SceneTreeNode **child;
    SceneTreeNode *parent;
};

void pushSceneTreeNodeToRenderList(SceneTreeNode *stn, RenderList *rl);
SceneTreeNode *newSceneTreeNode(SceneObject *so);
void destroySceneTreeNode(SceneTreeNode *sn);
void insertChildSceneTreeNode(SceneTreeNode *dest, SceneObject *src_so);
void drawSceneTreeNode(SceneTreeNode *sn, GLint uModel, GLint uColor);
void updateSceneTreeNode(SceneTreeNode *sn);
void updateSceneTreeNodeMatrices(SceneTreeNode *sn);
void addSceneTreeNodeTexture(SceneTreeNode *sn, size_t index);

// void calcBoundingRadius(SceneTreeNode *sn);

#endif // SCENETREENODE_H
