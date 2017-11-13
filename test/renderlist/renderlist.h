#ifndef SCENELIST_H
#define SCENELIST_H
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef int32_t RenderMode;

typedef struct ObjNode ObjNode;
typedef struct RenderList RenderList;

struct ObjNode {
    char *name;
    RenderMode renderMode;
    ObjNode *next;
    ObjNode *prev;
};

struct RenderList {
    ObjNode *root;
    char name[100];
    size_t num_nodes;
    RenderMode renderMode;
};

RenderList *newRenderList(const char *name);
void destroyRenderList(RenderList *rl);

void pushRenderList(RenderList *sceneList, const char *name);
char *popRenderList(RenderList *rl);

void pushObjNode(RenderList *rl, ObjNode *on);
ObjNode *popObjNode(RenderList *rl);

void compareAndUpdateList(RenderList *dest, RenderList *src);

void printList(RenderList *rl);

ObjNode *searchList(RenderList *rl, const char *tar);
ObjNode *removeSearch(RenderList *rl, const char *tar);

bool isEmpty(RenderList *rl);
// void printCamDists(RenderList *rl);
// void sortByCamDist(RenderList *rl);
// void removeObjNode(RenderList *rl, ObjNode *sn);

#endif // SCENELIST_H
