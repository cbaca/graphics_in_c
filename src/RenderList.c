#include "RenderList.h"
#include "SceneTreeNode.h"
#include "Frustum.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

static ObjNode *_sortObjNodeByCamDist(ObjNode *n);
static void _updateObjNodeCamDist(ObjNode *sn, Vec3 *camPos);
static void _printObjNodeCamDist(ObjNode *sn);
static void _freeNodes(ObjNode *on);
static bool _checkObjNodePointInRadius(ObjNode *on, Vec3 *pt);
static bool _removeNode(ObjNode *cur, ObjNode *target);

SceneObject *getRenderListRoot(RenderList *rl)
{
    return rl->root->object;
}

RenderMode getRenderListRenderMode(RenderList *rl)
{
    return rl->renderMode;
}

RenderList *newRenderList(RenderMode rm)
{
    RenderList *ol = malloc(sizeof(RenderList));
    ol->root = NULL;
    ol->num_nodes = 0;
    ol->renderMode = rm;
    return ol;
}

void destroyRenderList(RenderList *ol)
{
    _freeNodes(ol->root);
    free(ol);
}

void pushSceneObject(RenderList *rl, SceneObject *so)
{
    ObjNode *on = malloc(sizeof(ObjNode));
    on->object = so;
    rl->num_nodes++;
    on->next = rl->root;
    rl->root = on;
}

SceneObject *popRenderList(RenderList *rl)
{
    if (!rl->root) return NULL;

    SceneObject *ret = rl->root->object;
    ObjNode *next = rl->root->next;
    free(rl->root);
    rl->root = next;
    --rl->num_nodes;
    return ret;
}

ObjNode *popObjNode(RenderList *rl)
{
    if (!rl->root) return NULL;
    ObjNode *ret = rl->root;
    rl->root = rl->root->next;
    ret->next = NULL;
    rl->num_nodes--;
    return ret;
}

void pushObjNode(RenderList *rl, ObjNode *on)
{
    if (!on) return;
    rl->num_nodes++;
    on->next = rl->root;
    rl->root = on;
}

void compareAndUpdateList(RenderList *dest, RenderList *src)
{
    ObjNode *cur = src->root;
    ObjNode *curprev = NULL;
    while (cur) {
        ObjNode *next = cur->next;
        if (cur->object->renderMode & dest->renderMode) {
            if (curprev) {
                curprev->next = cur->next;
                cur->next = dest->root;
                dest->root = cur;
            } else {
                ObjNode *tmp = src->root;
                src->root = src->root->next;
                tmp->next = dest->root;
                dest->root = tmp;
            }
            dest->num_nodes++;
            src->num_nodes--;
        }
        curprev = cur;
        cur = next;
    }
}

void sortByCamDist(RenderList *ol)
{
    if (!ol->root || !ol->root->next) return;
    ol->root = _sortObjNodeByCamDist(ol->root);
}

// interaction / geometry
void updateCamDists(RenderList *rl, Vec3 *camPos)
{
    _updateObjNodeCamDist(rl->root, camPos);
    // sortByCamDist(rl);
}


void _calcBoundingRadii(ObjNode *on)
{
    if (!on) return;
    calcBoundingRadius(on->object);
    if (on->object->permanent)
        on->object->boundingRadius = 0.0f;
    _calcBoundingRadii(on->next);
}

void calcBoundingRadii(RenderList *rl)
{
    _calcBoundingRadii(rl->root);
}

bool checkPointInRadiusCollisions(RenderList *rl, Vec3 *pt)
{
    return _checkObjNodePointInRadius(rl->root, pt);
}

void printCamDists(RenderList *ol)
{
    _printObjNodeCamDist(ol->root);
}

size_t objectListLen(RenderList *ol)
{
    return ol->num_nodes;
}

bool isEmpty(RenderList *rl)
{
    return rl->root == NULL;
}

void removeObjNode(RenderList *rl, ObjNode *sn)
{
    _removeNode(rl->root, sn);
}

/**
 * Private function definitions
 */
static ObjNode *_sortObjNodeByCamDist(ObjNode *n)
{
    ObjNode *root = NULL;
    while (n) {
        ObjNode *swap = n;
        n = n->next;
        ObjNode **handle = &root;
        while (!(*handle == NULL || compareCameraDists(swap->object, (*handle)->object) < 0))
            handle = &(*handle)->next;
        swap->next = *handle;
        *handle = swap;
    }
    n = root;
    return root;
}

static void _printObjNodeCamDist(ObjNode *sn)
{
    if (!sn) return;
    if (sn->object->name)
        printf("%s ", sn->object->name);
    printf("%f\n", sn->object->distFromCam);
    _printObjNodeCamDist(sn->next);
}

static void _updateObjNodeCamDist(ObjNode *sn, Vec3 *camPos)
{
    if (!sn) return;
    updateObjectDistFromCam(sn->object, camPos);
    _updateObjNodeCamDist(sn->next, camPos);
}

void _freeNodes(ObjNode *on)
{
    if (!on) return;
    _freeNodes(on->next);
    destroySceneObject(on->object);
    free(on);
}

bool _checkObjNodePointInRadius(ObjNode *on, Vec3 *pt)
{
    if (!on) return false;
    if (pointInSceneObjectRadius(on->object, pt))
        return true;
    return _checkObjNodePointInRadius(on->next, pt);
}

static bool _removeNode(ObjNode *cur, ObjNode *target)
{
    assert(target->next != target);
    if (!cur) return false;
    if (cur->next == target) {
        ObjNode *tmp = target->next;
        target->next = NULL;
        cur->next = tmp;
        return true;
    }
    return _removeNode(cur->next, target);
}

