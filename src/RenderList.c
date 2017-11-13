#include "RenderList.h"
#include "Frustum.h"
#include "Camera.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

static void _updateObjNodeCamDist(ObjNode *sn, Vec3 *camPos);
static void _freeNodes(ObjNode *on);
static bool_t _checkObjNodePointInRadius(ObjNode *on, Camera *c);
// static void _printObjNodeCamDist(ObjNode *sn);
// static ObjNode *_sortObjNodeByCamDist(ObjNode *n);
// static bool_t _removeNode(ObjNode *cur, ObjNode *target);

size_t countItems(RenderList *rl)
{
    ObjNode *on = rl->root;
    size_t cnt = 0;
    while (on) {
        on = on->next;
        cnt++;
    }
    return cnt;
}

RenderList *newRenderList(RenderMode rm)
{
    RenderList *rl = malloc(sizeof(RenderList));
    rl->root = NULL;
    rl->num_nodes = 0;
    rl->renderMode = rm;
    return rl;
}

void destroyRenderList(RenderList *rl)
{
    _freeNodes(rl->root);
    free(rl);
}

void pushRenderList(RenderList *rl, SceneObject *so)
{
    ObjNode *on = malloc(sizeof(ObjNode));
    on->object = so;
    rl->num_nodes++;
    if (rl->root)
        rl->root->prev = on;
    on->next = rl->root;
    rl->root = on;
    rl->root->prev = NULL;
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

void pushObjNode(RenderList *rl, ObjNode *on)
{
    if (!on) return;
    rl->num_nodes++;
    if (rl->root)
        rl->root->prev = on;
    on->next = rl->root;
    rl->root = on;
    rl->root->prev = NULL;
}

ObjNode *popObjNode(RenderList *rl)
{
    if (!rl->root) return NULL;

    ObjNode *ret = rl->root;
    rl->root = rl->root->next;
    if (!rl->root)
        rl->root->prev = NULL;
    ret->next = NULL;
    rl->num_nodes--;
    return ret;
}

void compareAndUpdateList(RenderList *dest, RenderList *src)
{
    ObjNode *cur = src->root;
    while (cur) {
        ObjNode *nxt = cur->next;
        if (cur->object->renderMode & dest->renderMode) {
            if (cur->prev == NULL) {
                if (cur->next) {
                    cur->next->prev = NULL;
                    src->root = cur->next;
                } else {
                    src->root = NULL;
                }
                if (dest->root)
                    dest->root->prev = cur;
                cur->next = dest->root;
                dest->root = cur;
                dest->root->prev = NULL;
            } else {
                cur->prev->next = cur->next;
                if (cur->next)
                    cur->next->prev = cur->prev;
                cur->next = dest->root;
                dest->root = cur;
                dest->root->prev = NULL;
            }
        }
        cur = nxt;
    }
}

void _printList(ObjNode *on)
{
    if (!on) return;
    printf("%s\n", on->object->name);
    _printList(on->next);
}

void printList(RenderList *rl)
{
    _printList(rl->root);
}

void updateCamDists(RenderList *rl, Vec3 *camPos)
{
    _updateObjNodeCamDist(rl->root, camPos);
}

void _calcBoundingRadii(ObjNode *on)
{
    if (!on) return;
    if (on->object->permanent)
        on->object->boundingRadius = 0.0f;
    else
        calcBoundingRadius(on->object);
    _calcBoundingRadii(on->next);
}

void calcBoundingRadii(RenderList *rl)
{
    _calcBoundingRadii(rl->root);
}

bool_t checkPointInRadiusCollisions(RenderList *rl, Camera *c)
{
    return _checkObjNodePointInRadius(rl->root, c);
}

size_t objectListLen(RenderList *rl)
{
    return rl->num_nodes;
}

bool_t isEmpty(RenderList *rl)
{
    return rl->root == NULL;
}

bool_t _checkFrustumCollision(ObjNode *on, Frustum *fr)
{
    if (!on) return no;
    if (frustumSphereIntersection(fr, &on->object->position, on->object->boundingRadius)) {
        on->object->renderMode |= RENDER_INVISIBLE;
        return yes;
    }
    on->object->renderMode &= ~RENDER_INVISIBLE;
    // if (on->object->name)
        // printf("%s @ %.2f %.2f %.2f is invisible\n", on->object->name, on->object->position.x, on->object->position.y,
        //     on->object->position.z);
    return _checkFrustumCollision(on->next, fr);
}

bool_t checkFrustumCollision(RenderList *rl, Frustum *fr)
{
    return _checkFrustumCollision(rl->root, fr);
}

// void sortByCamDist(RenderList *rl)
// {
//     if (!rl->root || !rl->root->next) return;
//     rl->root = _sortObjNodeByCamDist(rl->root);
// }


// void removeObjNode(RenderList *rl, ObjNode *sn)
// {
//     _removeNode(rl->root, sn);
// }

/**
 * Private function definitions
 */
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

bool_t _checkObjNodePointInRadius(ObjNode *on, Camera *c)
{
    if (!on) return no;
    Vec3 pt = get_camera_target_as(c, &on->object->position);
    if (pointInSceneObjectRadius(on->object, &pt))
        return yes;
    return _checkObjNodePointInRadius(on->next, c);
}

// static void _printObjNodeCamDist(ObjNode *sn)
// {
//     if (!sn) return;
//     if (sn->object->name)
//         printf("%s ", sn->object->name);
//     printf("%f\n", sn->object->distFromCam);
//     _printObjNodeCamDist(sn->next);
// }

// void printCamDists(RenderList *rl)
// {
//     _printObjNodeCamDist(rl->root);
// }

// ObjNode *_sortObjNodeByCamDist(ObjNode *n)
// {
//     ObjNode *root = NULL;
//     while (n) {
//         ObjNode *swap = n;
//         n = n->next;
//         ObjNode **handle = &root;
//         while (!(*handle == NULL || compareCameraDists(swap->object, (*handle)->object) < 0))
//             handle = &(*handle)->next;
//         swap->next = *handle;
//         *handle = swap;
//     }
//     n = root;
//     return root;
// }

// bool_t _removeNode(ObjNode *cur, ObjNode *target)
// {
//     assert(target->next != target);
//     if (!cur) return no;
//     if (cur->next == target) {
//         ObjNode *tmp = target->next;
//         target->next = NULL;
//         cur->next = tmp;
//         return yes;
//     }
//     return _removeNode(cur->next, target);
// }

