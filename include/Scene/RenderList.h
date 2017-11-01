#ifndef SCENELIST_H
#define SCENELIST_H
#include "SceneObject.h"
#include <stdlib.h>

typedef struct ObjNode ObjNode;
typedef struct RenderList RenderList;

struct ObjNode {
    SceneObject *object;
    ObjNode *next;
};

struct RenderList {
    ObjNode *root;
    size_t num_nodes;
    RenderMode renderMode;
    bool debugMode;
};

RenderMode getRenderListRenderMode(RenderList *rl);
SceneObject *getRenderListRoot(RenderList *rl);
RenderList *newRenderList(RenderMode rm);
void destroyRenderList(RenderList *ol);

void pushSceneObject(RenderList *sceneList, SceneObject *so);
void pushObjNode(RenderList *rl, ObjNode *on);

SceneObject *popRenderList(RenderList *sceneList);
ObjNode *popObjNode(RenderList *rl);

void compareAndUpdateList(RenderList *dest, RenderList *src);
void sortByCamDist(RenderList *ol);

// void drawColorRenderList(RenderList *ol, GLint uModel, GLint uColor);
// void drawHighlightRenderList(RenderList *ol, GLint uModel);
// void drawTextureRenderList(RenderList *ol, GLint uModel, GLint uTexture);
// void drawDebugColorRenderList(RenderList *ol, GLint uModel, GLint uColor);
// void drawColorRenderList(RenderList *ol, MaterialShader *sh, Vec3 *campos);

void updateCamDists(RenderList *ol, Vec3 *camPos);
bool checkPointInRadiusCollisions(RenderList *rl, Vec3 *pt);
void printCamDists(RenderList *ol);
void calcBoundingRadii(RenderList *ol);

size_t objectListLen(RenderList *ol);
bool isEmpty(RenderList *rl);
void removeObjNode(RenderList *rl, ObjNode *sn);
// void removeNode(RenderList *rl, ObjNode *sn);

#endif // SCENELIST_H
