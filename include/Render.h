#ifndef RENDER_H
#define RENDER_H
#include "Camera.h"
#include "Shader.h"
#include "Backend.h"
#include "World.h"
#include "meshdata.h"
#include "BufferData.h"
#include "Maths.h"
#include "Scene.h"

/*

typedef struct Render_t {
    RenderList *rl;
    Shader *shader;
} Render_t;
*/

typedef struct Render_t {
    World_t world;
    Scene scene;
    HighlightShader hlShader;
    MaterialShader mShader;
    ObjShader *oShader;
    float windowW, windowH;
    bool needsUpdate;
} Render_t;


void finalizeRenderer(Render_t *r); // void sceneDestroy(Scene_t *s);
int initRenderer(Render_t *r);
void updateRenderer(Render_t *r, float windowW, float windowH, float seconds, bool needsUpdate);
void render(Render_t *r);

// Scene draw call declarations
void drawSceneColor(Scene *s, MaterialShader *sh, Vec3 *campos);
void drawSceneHighlightColor(Scene *s, MaterialShader *sh, Vec3 *campos);
void drawSceneTexture(Scene *s, GLint uModel, GLint uTexture);
void drawSceneHighlightTexture(Scene *s, GLint uModel, GLint uTexture);
void drawSceneHighlight(Scene *s, GLint uModel);

// RenderList draw call declatations
void drawHighlightRenderList(RenderList *rl, GLint uModel);
void drawTextureRenderList(RenderList *rl, GLint uModel, GLint uTexture);
void drawDebugColorRenderList(RenderList *rl, GLint uModel, GLint uColor);
void drawColorRenderList(RenderList *rl, MaterialShader *sh, Vec3 *campos);

// SceneObject draw calls
void drawHighlightSceneObject(SceneObject *so, GLint uModel);
void drawTextureSceneObject(SceneObject *so, GLint uModel, GLint uTexture);
// void drawColorSceneObject(SceneObject *so, GLint uModel, GLint uColor);
void drawColorSceneObject(SceneObject *so, MaterialShader *sh, Vec3 *campos);
void drawDebugColorSceneObject(SceneObject *so, GLint uModel, GLint uColor);
void drawSceneObject(SceneObject *sn, GLint uModel, GLint uColor);
#endif /* RENDER_H */
