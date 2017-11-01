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
    ColorShader cShader;
    TexShader tShader;

    float windowW, windowH;
    bool needsUpdate;
} Render_t;


void finalizeRenderer(Render_t *r); // void sceneDestroy(Scene_t *s);
int initRenderer(Render_t *r);
void updateRenderer(Render_t *r, float windowW, float windowH, float seconds, bool needsUpdate);
void render(Render_t *r);

// Scene draw call declarations
void drawSceneColor(Scene *s, ColorShader *sh, Vec3 *cam_pos);
void drawSceneTexture(Scene *s, TexShader *sh, Vec3 *cam_pos);
void drawSceneHighlightColor(Scene *s, ColorShader *sh, Vec3 *cam_pos);
void drawSceneHighlightTexture(Scene *s, TexShader *sh, Vec3 *cam_pos);
void drawSceneHighlight(Scene *s, GLint uModel);

// RenderList draw call declatations
void drawColorRenderList(RenderList *rl, ColorShader *sh, Vec3 *cam_pos);
void drawTextureRenderList(RenderList *rl, TexShader *sh, Vec3 *cam_pos);
void drawHighlightRenderList(RenderList *rl, GLint uModel);
void drawDebugColorRenderList(RenderList *rl, GLint uModel, GLint uColor);

// SceneObject draw calls
void drawColorSceneObject(SceneObject *so, ColorShader *sh, Vec3 *cam_pos);
void drawTextureSceneObject(SceneObject *so, TexShader *sh, Vec3 *cam_pos);
void drawHighlightSceneObject(SceneObject *so, GLint uModel);
void drawDebugColorSceneObject(SceneObject *so, GLint uModel, GLint uColor);
void drawSceneObject(SceneObject *sn, GLint uModel, GLint uColor);
#endif /* RENDER_H */
