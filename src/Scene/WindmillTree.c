#include "WindmillTree.h"
#include "SceneObject.h"
#include <stdlib.h>

const float DefaultStep = 1.81f;
static SceneTreeNode *_newBodyNode(BufferData *data, Vec3 *pos, float size);
static SceneObject *_newBladeNode(BufferData *data, float size, Vec3 *scale, Vec3 *pos);
static void _updateDrawMatrix(SceneTreeNode *sn, Vec3 *angles);
// static void _drawSceneNode(SceneNode *sn, GLint uModel, GLint uColor, Vec3 *angles);

WMTree *newWindmillTree(BufferData *data, Vec3 *pos, float size)
{
    WMTree *wm = malloc(sizeof(WMTree));
    wm->root = _newBodyNode(data, pos, size);
    float bladeLen = size * 0.4f;
    float bladeWid = size * 0.06f;
    float bladeThickness = size * 0.005f;
    float hubRad = size * 0.48f;
    float hubDist = size * 0.125f;
    float bladeOri = 0.0f;
    Vec3 scl = (Vec3){ bladeLen, bladeWid, bladeThickness };
    Vec3 p = (Vec3){ hubRad, bladeOri, hubDist };
    insertChildSceneTreeNode(wm->root, _newBladeNode(data, size, &scl, &p));

    scl = (Vec3){ bladeWid, bladeLen, bladeThickness };
    p = (Vec3){ bladeOri, hubRad, hubDist };
    insertChildSceneTreeNode(wm->root, _newBladeNode(data, size, &scl, &p));

    scl = (Vec3){ bladeLen, bladeWid, bladeThickness };
    p = (Vec3){ -hubRad, -bladeOri, hubDist };
    insertChildSceneTreeNode(wm->root, _newBladeNode(data, size, &scl, &p));

    scl = (Vec3){ bladeWid, bladeLen, bladeThickness };
    p = (Vec3){ -bladeOri, -hubRad, hubDist };
    insertChildSceneTreeNode(wm->root, _newBladeNode(data, size, &scl, &p));

    wm->angles = (Vec3){ 0.0f, 0.0f, 0.0f };



    wm->bodySpinFlag = false;
    wm->bladeSpinFlag = false;
    wm->numNodes = 5;

    return wm;
}

void updateWindmillTree(WMTree *wm, bool f1, bool f2)
{
    wm->bodySpinFlag = f1;
    wm->bladeSpinFlag = f2;
    if (f1) {
        wm->angles.y += DefaultStep;
        if (wm->angles.y >= 360.0f)
            wm->angles.y = 0.0f;
    }
    if (f2) {
        wm->angles.z += DefaultStep;
        if (wm->angles.z >= 360.0f)
            wm->angles.z = 0.0f;
    }

    updateSceneTreeNode(wm->root);
}

void updateWindmillMatrices(WMTree *wm)
{
    _updateDrawMatrix(wm->root, &wm->angles);
}

void destroyWindmillTree(WMTree *wm)
{
    destroySceneTreeNode(wm->root);
    free(wm);
}

static SceneTreeNode *_newBodyNode(BufferData *data, Vec3 *pos, float size)
{
    SceneObject *so = newSceneObject(data);
    so->color = (Vec3){ 0.4f, 0.4f, 1.0f };
    so->scale = (Vec3){ size * 0.05f, size, size *0.05f };
    Vec3 p;
    vec3set(&p, pos);
    p.y += size * 0.5f;
    translateMat4(so->modelMatrix, &p);

    SceneTreeNode *root = newSceneTreeNode(so);
    return root;
}

static SceneObject *_newBladeNode(BufferData *data, float size, Vec3 *scale, Vec3 *pos)
{
    SceneObject *so = newSceneObject(data);
    so->color = (Vec3){ 1.0f, 0.4f, 0.4f };
    Vec3 p = (Vec3){ 0.0f, size * 0.6f, 0.0f };
    setTranslationMat4(so->modelMatrix, &p);
    vec3set(&so->scale, scale);
    vec3set(&so->position, pos);
    // SceneTreeNode *node = newSceneTreeNode(so);
    // return node;
    return so;
}

void _updateBodyMatrix(SceneObject *body, Vec3 *angles)
{
    setMat4(body->drawMatrix, body->worldMatrix);
    rotateYMat4(body->drawMatrix, angles->y);
}

void _updateBladeMatrix(SceneObject *blade, Vec3 *angles)
{
    // setMat4(blade->drawMatrix, blade->worldMatrix);
    // rotateYMat4(blade->drawMatrix, angles->y);
    rotateZMat4(blade->drawMatrix, angles->z);
    translateMat4(blade->drawMatrix, &blade->position);
}

static void _updateDrawMatrix(SceneTreeNode *sn, Vec3 *angles)
{
    _updateBodyMatrix(sn->object, angles);
    if (sn->parent)
        _updateBladeMatrix(sn->object, angles);
    scaleMat4(sn->object->drawMatrix, &sn->object->scale);
    size_t i;
    for (i = 0; i < sn->num_children; ++i)
        _updateDrawMatrix(sn->child[i], angles);
}

void _setRenderHL(SceneTreeNode *stn)
{
    stn->object->renderMode |= RENDER_HIGHLIGHT;
    size_t i;
    for (i = 0; i < stn->num_children; ++i)
        _setRenderHL(stn->child[i]);
}
void _checkHL(SceneTreeNode *stn)
{
    size_t i;
    for (i = 0; i < stn->num_children; ++i)
        _checkHL(stn->child[i]);
    if (stn->object->renderMode & RENDER_HIGHLIGHT) {
        SceneTreeNode *tmp = stn;
        while (tmp->parent)
            tmp = tmp->parent;
        _setRenderHL(tmp);
    }
}

void checkWindmillTreeHL(WMTree *wm)
{
    _checkHL(wm->root);
}
