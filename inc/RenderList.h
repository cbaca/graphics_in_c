#ifndef SCENELIST_H
#define SCENELIST_H
#include <stdlib.h>
#include "SceneObject.h"
#include "camera.h"

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

/**
 * renderlist_create
 */
RenderList *renderlist_create(RenderMode rm) __attribute__ ((malloc));

/**
 * renderlist_destroy
 */
void renderlist_destroy(RenderList *rl);

/**
 * renderlist_count_items
 */
size_t renderlist_count_items(RenderList *rl);

/**
 * renderlist_push
 */
void renderlist_push(RenderList *sceneList, SceneObject *so);

/**
 * renderlist_pop
 */
SceneObject *renderlist_pop(RenderList *sceneList);

/**
 * renderlist_push_node
 */
void renderlist_push_node(RenderList *rl, ObjNode *on);

/**
 * renderlist_pop_node
 */
ObjNode *renderlist_pop_node(RenderList *rl);

/**
 * renderlist_compare_and_update
 */
void renderlist_compare_and_update(RenderList *dest, RenderList *src);

/**
 * renderlist_print
 */
void renderlist_print(RenderList *rl);

/**
 * renderlist_has_frustum_collision
 */
// bool_t renderlist_has_frustum_collision(RenderList *rl, Frustum *fr);

/**
 * renderlist_has_point_radius_collisions
 */
bool_t renderlist_has_point_radius_collisions(RenderList *rl, struct camera *c);

/**
 * renderlist_update_cam_dists
 */
void renderlist_update_cam_dists(RenderList *rl, Vec3 *camPos);

/**
 * renderlist_calc_bounding_radii
 */
void renderlist_calc_bounding_radii(RenderList *rl);

/**
 * renderlist_is_empty
 */
bool_t renderlist_is_empty(RenderList *rl);

#endif // SCENELIST_H
