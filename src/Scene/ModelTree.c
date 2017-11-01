#include "ModelScene.h"
#include "utils.h"

#define LANDSCAPE_SCALE 300.0f, 300.0f, 300.0f
#define LANDSCAPE_COLOR 0.4f, 0.8f, 0.4f
#define LANDSCAPE_POS 0.0f, 0.0f, 0.0f

static void _initModelScene(ModelScene *ms, BufferData *landscapeData);
ModelScene *newModelScene(BufferData *landscapeData)
{
    ModelScene *ms = malloc(sizeof(ModelScene));
    _initModelScene(ms, landscapeData);
    return ms;
}

void destroyModelScene(ModelScene *ms)
{
    destroySceneNode(ms->root);
    free(ms);
}

void updateModelMatrices(ModelScene *ms)
{
    updateSceneNodeMatrices(ms->root);
}

void updateModelScene(ModelScene *ms)
{
    updateSceneNode(ms->root);
}

void drawModelScene(ModelScene *ms, GLint uModel, GLint uColor)
{
    drawSceneNode(ms->root, uModel, uColor);
}

static void _initModelScene(ModelScene *ms, BufferData *landscapeData)
{
    ms->root = newSceneNode(landscapeData);
    SceneObject *root = ms->root;
    root->color = (Vec3){ LANDSCAPE_COLOR };
    root->scale = (Vec3){ LANDSCAPE_SCALE };
    root->position = (Vec3){ LANDSCAPE_POS };
    setTranslationMat4(root->modelMatrix, &root->position);
    ms->numNodes = 1;
}
