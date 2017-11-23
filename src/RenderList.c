#include "RenderList.h"
#include "vecmath.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

static void _updateObjNodeCamDist(ObjNode *sn, Vec3 *camPos);
static void _freeNodes(ObjNode *on);
static bool_t _checkObjNodePointInRadius(ObjNode *on, struct camera *c);

RenderList *renderlist_create(RenderMode rm)
{
    RenderList *rl = malloc(sizeof(RenderList));
    rl->root = NULL;
    rl->num_nodes = 0;
    rl->renderMode = rm;
    return rl;
}

static void _freeNodes(ObjNode *on)
{
    if (!on) return;
    _freeNodes(on->next);
    destroySceneObject(on->object);
    free(on);
}

void renderlist_destroy(RenderList *rl)
{
    _freeNodes(rl->root);
    free(rl);
}

size_t renderlist_count_items(RenderList *rl)
{
    ObjNode *on = rl->root;
    size_t cnt = 0;
    while (on) {
        on = on->next;
        cnt++;
    }
    return cnt;
}

void renderlist_push(RenderList *rl, SceneObject *so)
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

SceneObject *renderlist_pop(RenderList *rl)
{
    if (!rl->root) return NULL;

    SceneObject *ret = rl->root->object;
    ObjNode *next = rl->root->next;
    free(rl->root);
    rl->root = next;
    --rl->num_nodes;
    return ret;
}

void renderlist_push_node(RenderList *rl, ObjNode *on)
{
    if (!on) return;
    rl->num_nodes++;
    if (rl->root)
        rl->root->prev = on;
    on->next = rl->root;
    rl->root = on;
    rl->root->prev = NULL;
}

ObjNode *renderlist_pop_node(RenderList *rl)
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

/* compare and swap if prereqs met */
void renderlist_compare_and_update(RenderList *dest, RenderList *src)
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





bool_t renderlist_is_empty(RenderList *rl)
{
    return rl->root == nil;
}




void _printList(ObjNode *on)
{
    if (!on) return;
    printf("%s\n", on->object->name);
    _printList(on->next);
}

void renderlist_print(RenderList *rl)
{
    _printList(rl->root);
}




/* SceneObject's update cam dist function is called recursively
   for each SceneObject in the list */
static void _updateObjNodeCamDist(ObjNode *sn, vec3_t *camPos)
{
    if (!sn) return;
    sn->object->distFromCam = vec3dot(&sn->object->position, camPos);
    _updateObjNodeCamDist(sn->next, camPos);
}

void renderlist_update_cam_dists(RenderList *rl, Vec3 *camPos)
{
    _updateObjNodeCamDist(rl->root, camPos);
}




/* SceneObject's "calcBoundingRadius" called recursively */
void _calcBoundingRadii(ObjNode *on)
{
    if (!on) return;
    if (on->object->permanent)
        on->object->boundingRadius = 0.0f;
    else
        on->object->boundingRadius = vec3length(&on->object->scale);
    _calcBoundingRadii(on->next);
}

void renderlist_calc_bounding_radii(RenderList *rl)
{
    _calcBoundingRadii(rl->root);
}




/* Detection for camera target collision , recursive */
bool_t _checkObjNodePointInRadius(ObjNode *on, struct camera *c)
{
    if (!on)
        return no;
    vec3_t pt = camera_target_from_pos(c, &on->object->position);

    if (pointInSceneObjectRadius(on->object, &pt))
        return yes;
    return _checkObjNodePointInRadius(on->next, c);
}

bool_t renderlist_has_point_radius_collisions(RenderList *rl, struct camera *c)
{
    return _checkObjNodePointInRadius(rl->root, c);
}









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
// void sortByCamDist(RenderList *rl)
// {
//     if (!rl->root || !rl->root->next) return;
//     rl->root = _sortObjNodeByCamDist(rl->root);
// }
// void removeObjNode(RenderList *rl, ObjNode *sn)
// {
//     _removeNode(rl->root, sn);
// }
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

