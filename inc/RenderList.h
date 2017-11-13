#ifndef SCENELIST_H
#define SCENELIST_H
#include <stdlib.h>
#include "SceneObject.h"

typedef struct camera_t Camera;
typedef struct ObjNode ObjNode;
typedef struct RenderList RenderList;
typedef struct Frustum Frustum;

struct ObjNode {
    SceneObject *object;
    ObjNode *next;
    ObjNode *prev;
};

struct RenderList {
    ObjNode *root;
    size_t num_nodes;
    RenderMode renderMode;
};

size_t countItems(RenderList *rl);
RenderList *newRenderList(RenderMode rm);
void destroyRenderList(RenderList *rl);

void pushRenderList(RenderList *sceneList, SceneObject *so);
SceneObject *popRenderList(RenderList *sceneList);

void pushObjNode(RenderList *rl, ObjNode *on);
ObjNode *popObjNode(RenderList *rl);

void compareAndUpdateList(RenderList *dest, RenderList *src);

void printList(RenderList *rl);


bool_t checkFrustumCollision(RenderList *rl, Frustum *fr);
bool_t checkPointInRadiusCollisions(RenderList *rl, Camera *c);
void updateCamDists(RenderList *rl, Vec3 *camPos);
void calcBoundingRadii(RenderList *rl);
size_t objectListLen(RenderList *rl);
bool_t isEmpty(RenderList *rl);
// void printCamDists(RenderList *rl);
// void sortByCamDist(RenderList *rl);
// void removeObjNode(RenderList *rl, ObjNode *sn);

#endif // SCENELIST_H
