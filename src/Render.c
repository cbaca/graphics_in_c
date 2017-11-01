#include "Render.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void _renderColor(Render_t *r);
static void _renderTexture(Render_t *r);
void _renderHighlight(Render_t *r);

static void _setColorShader(Scene *s, World_t *w, ColorShader *sh);
static void _setTexShader(Scene *s, World_t *w, TexShader *sh);
static void _setHighlightShader(Scene *s, World_t *w, HighlightShader *sh, float ww, float wh);
void _renderHighlightTexture(Render_t *r);
void _renderHighlightColor(Render_t *r);

void finalizeRenderer(Render_t *r)
{
    finalizeWorld(&r->world);
    finalizeScene(&r->scene);
}

int initRenderer(Render_t *r)
{
    initWorld(&r->world);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    if (!initColorShader(&r->cShader)) return 0;
    if (!initTexShader(&r->tShader)) return 0;
    if (!initHighlightShader(&r->hlShader)) return 0;

    initScene(&r->scene);

    return 1;
}

void updateRenderer(Render_t *r, float windowW, float windowH, float seconds, bool needsUpdate)
{
    r->windowW = windowW;
    r->windowH = windowH;
    r->needsUpdate = needsUpdate;
    worldUpdate(&r->world, seconds);
    updateScene(&r->scene, needsUpdate);
}

void render(Render_t *r)
{
    float *bg_color = getWorldBGColor(&r->world);
    glEnable(GL_DEPTH_TEST);
    glClearColor(bg_color[0], bg_color[1], bg_color[2],  1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    glStencilMask(0x00);
    _renderTexture(r);
    _renderColor(r);

    int rm = sceneHasHighlightObjects(&r->scene);
    if (!rm) return;

    if (rm & RENDER_COLOR)

        _renderHighlightColor(r);
    else

        _renderHighlightTexture(r);

    _renderHighlight(r);

}


void setMaterialUniforms(MaterialUniforms *mu, Material *ma)
{
    glUniform3fv(mu->ambient, 1, (float *)&ma->ambient);
    glUniform3fv(mu->diffuse, 1, (float *)&ma->diffuse);
    glUniform3fv(mu->specular, 1, (float *)&ma->specular);
    glUniform1f(mu->shininess, ma->shininess);
}

void setLightUniforms(LightUniforms *lu, DirLight *dl)
{
    glUniform3fv(lu->color, 1, (float *)&dl->color);
    glUniform3fv(lu->direction, 1, (float *)&dl->direction);
    glUniform1f(lu->ambientIntensity, dl->ambientIntensity);
    glUniform1f(lu->diffuseIntensity, dl->diffuseIntensity);
}

void setSpotLightUniforms(SpotLightUniforms *su, SpotLight *sl)
{
    glUniform3fv(su->direction, 1, (float *)&sl->direction);
    glUniform1f(su->ambientIntensity, sl->ambientIntensity);
    glUniform1f(su->diffuseIntensity, sl->diffuseIntensity);
    glUniform1f(su->inner_cutoff, sl->inner_cutoff);
    glUniform1f(su->outer_cutoff, sl->outer_cutoff);
}

void setPointLightUniforms(PointLightUniforms *pu, PointLight *pl)
{
    glUniform3fv(pu->position, 1, (float *)&pl->position);
    glUniform3fv(pu->ambient, 1, (float *)&pl->ambient);
    glUniform3fv(pu->diffuse, 1, (float *)&pl->diffuse);
    glUniform3fv(pu->specular, 1, (float *)&pl->specular);
    glUniform1f(pu->Kc, pl->Kc);
    glUniform1f(pu->Kl, pl->Kl);
    glUniform1f(pu->Kq, pl->Kq);
}


/**
 * Scene render function definitions
 */
void drawSceneColor(Scene *s, ColorShader *sh, Vec3 *cam_pos)
{
    drawColorRenderList(s->colorList, sh, cam_pos);
}

// void drawSceneTexture(Scene *s, GLint uModel, GLint uTexture)
void drawSceneTexture(Scene *s, TexShader *sh, Vec3 *cam_pos)
{
    drawTextureRenderList(s->textureList, sh, cam_pos);
}

void drawSceneHighlightColor(Scene *s, ColorShader *sh, Vec3 *cam_pos)
{
    drawColorRenderList(s->highlightList, sh, cam_pos);
}

// void drawSceneHighlightTexture(Scene *s, GLint uModel, GLint uTexture)
void drawSceneHighlightTexture(Scene *s, TexShader *sh, Vec3 *cam_pos)
{
    // drawTextureRenderList(s->highlightList, uModel, uTexture);
    drawTextureRenderList(s->textureList, sh, cam_pos);
}
void drawSceneHighlight(Scene *s, GLint uModel)
{
    drawHighlightRenderList(s->highlightList, uModel);
}

/**
 * RenderList render call defs
 */
void _drawObjListColor(ObjNode *sn, BufferData *cur_data, ColorShader *sh, Vec3 *cam_pos);
void _drawObjListTexture(ObjNode *sn, BufferData *cur_data, TexShader *sh, Vec3 *cam_pos);
void _drawObjListHighlight(ObjNode *sn, BufferData *cur_data, GLint uModel);
void _drawObjListColorDebug(ObjNode *sn, BufferData *cur_data, GLint uModel, GLint uColor);

void drawColorRenderList(RenderList *ol, ColorShader *sh, Vec3 *cam_pos)
{
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListColor(ol->root, curData, sh, cam_pos);
}

// void drawTextureRenderList(RenderList *ol, GLint uModel, GLint uTexture)
void drawTextureRenderList(RenderList *ol, TexShader *sh, Vec3 *cam_pos)
{
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListTexture(ol->root, curData, sh, cam_pos);
}

void drawHighlightRenderList(RenderList *ol, GLint uModel)
{
    // printf("Its alive\n");
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListHighlight(ol->root, curData, uModel);
}

void drawDebugColorRenderList(RenderList *ol, GLint uModel, GLint uColor)
{
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListColorDebug(ol->root, curData, uModel, uColor);
}

// recrusive private func defs for list draw calls
#define CHECK_CUR_DATA(buffer_data, cur_data) \
    if (buffer_data != cur_data) { \
        cur_data = buffer_data;    \
        bufferDataUse(cur_data);   \
    }

void _drawObjListHighlight(ObjNode *sn, BufferData *cur_data, GLint uModel)
{
    if (!sn) return;
    sn->object->renderMode &= ~RENDER_HIGHLIGHT;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawHighlightSceneObject(sn->object, uModel);
    _drawObjListHighlight(sn->next, cur_data, uModel);
}

void _drawObjListColor(ObjNode *sn, BufferData *cur_data, ColorShader *sh, Vec3 *cam_pos)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawColorSceneObject(sn->object, sh, cam_pos);
    _drawObjListColor(sn->next, cur_data, sh, cam_pos);
}

// void _drawObjListTexture(ObjNode *sn, BufferData *cur_data, GLint uModel, GLint uTexture)
void _drawObjListTexture(ObjNode *sn, BufferData *cur_data, TexShader *sh, Vec3 *cam_pos)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawTextureSceneObject(sn->object, sh, cam_pos);
    _drawObjListTexture(sn->next, cur_data, sh, cam_pos);
}

void _drawObjListColorDebug(ObjNode *sn, BufferData *cur_data, GLint uModel, GLint uColor)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawDebugColorSceneObject(sn->object, uModel, uColor);
    _drawObjListColorDebug(sn->next, cur_data, uModel, uColor);
}

/**
 * SceneObject draw call definitions
 */
void drawColorSceneObject(SceneObject *so, ColorShader *sh, Vec3 *cam_pos)
{
    glUniform3fv(sh->uColor, 1, (float *)&so->color);

    setMaterialUniforms(&sh->uMaterial, &so->material);
    glUniform3fv(sh->uCamPos, 1, (float *)cam_pos);
    glUniform3fv(sh->uWorldPos, 1, (float *)&so->position);
    glUniformMatrix4fv(sh->uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

// void drawTextureSceneObject(SceneObject *so, GLint uModel, GLint uTexture)
void drawTextureSceneObject(SceneObject *so, TexShader *sh, Vec3 *cam_pos)
{
    glActiveTexture(so->activeTexture);
    glBindTexture(GL_TEXTURE_2D, so->texture);
    glUniform1i(sh->uTexture, so->textureIndex);

    setMaterialUniforms(&sh->uMaterial, &so->material);
    glUniform3fv(sh->uCamPos, 1, (float *)cam_pos);
    glUniform3fv(sh->uWorldPos, 1, (float *)&so->position);
    glUniformMatrix4fv(sh->uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void drawHighlightSceneObject(SceneObject *so, GLint uModel)
{
    Mat4 m;
    Vec3 scl = (Vec3){1.1f, 1.1f, 1.1f};
    setMat4(&m, so->drawMatrix);
    scaleMat4(&m, &scl);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, m.data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

void drawDebugColorSceneObject(SceneObject *so, GLint uModel, GLint uColor)
{
    glUniform3fv(uColor, 1, (float *)&so->color);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(GL_POINTS, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    glDrawElements(GL_LINE_LOOP, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

// void drawSceneObject(SceneObject *sn, GLint uModel, GLint uColor)
// {
//     glUniform3fv(uColor, 1, (float *)&sn->color);
//     glUniformMatrix4fv(uModel, 1, GL_FALSE, sn->drawMatrix->data);
//     glDrawElements(GL_TRIANGLES, sn->bufferData->elementCount, GL_UNSIGNED_INT, 0);
// }

// Local function definitions
void _renderColor(Render_t *r)
{
    ColorShader *sh = &r->cShader;
    _setColorShader(&r->scene, &r->world, sh);
    drawSceneColor(&r->scene, sh, getCameraPosition(r->scene.camera));
    bufferDataFinish();

}

static void _renderTexture(Render_t *r)
{
    TexShader *sh = &r->tShader;
    _setTexShader(&r->scene, &r->world, sh);
    // drawSceneTexture(&r->scene, sh->shader.uModel, sh->uTexture);
    drawSceneTexture(&r->scene, sh, getCameraPosition(r->scene.camera));
    bufferDataFinish();
}

void _renderHighlight(Render_t *r)
{
    glStencilFunc(GL_NOTEQUAL, 1, 0xff);
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);

    HighlightShader *sh = &r->hlShader;
    _setHighlightShader(&r->scene, &r->world, sh, r->windowW, r->windowH);
    drawSceneHighlight(&r->scene, sh->uModel);

    glStencilMask(0xff);
    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(0);
    bufferDataFinish();
}

static void _setColorShader(Scene *s, World_t *w, ColorShader *sh)
{
    glUseProgram(sh->program);
    passViewMatrix(s, sh->uView);
    passProjectionMatrix(s, sh->uProjection);
    setLightUniforms(&sh->uDirLight, &w->dirLight);
    setSpotLightUniforms(&sh->uSpotLight, &w->spotLight);
    setPointLightUniforms(&sh->uPointLight, &w->pointLight);
}

static void _setTexShader(Scene *s, World_t *w, TexShader *sh)
{
    glUseProgram(sh->program);
    passViewMatrix(s, sh->uView);
    passProjectionMatrix(s, sh->uProjection);
    setLightUniforms(&sh->uDirLight, &w->dirLight);
    setSpotLightUniforms(&sh->uSpotLight, &w->spotLight);
    setPointLightUniforms(&sh->uPointLight, &w->pointLight);
}

static void _setHighlightShader(Scene *s, World_t *w, HighlightShader *sh, float ww, float wh)
{
    glUseProgram(sh->program);
    passViewMatrix(s, sh->uView);
    passProjectionMatrix(s, sh->uProjection);
    glUniform2f(sh->uResolution, ww, wh);
    glUniform1f(sh->uTime, w->lastTime / 1000.0f);
}

void _renderHighlightColor(Render_t *r)
{
    glStencilFunc(GL_ALWAYS, 1, 0xff);
    glStencilMask(0xff);
    ColorShader *sh = &r->cShader;
    _setColorShader(&r->scene, &r->world, sh);
    drawSceneHighlightColor(&r->scene, sh, getCameraPosition(r->scene.camera));
    bufferDataFinish();
}

void _renderHighlightTexture(Render_t *r)
{
    glStencilFunc(GL_ALWAYS, 1, 0xff);
    glStencilMask(0xff);
    TexShader *sh = &r->tShader;
    _setTexShader(&r->scene, &r->world, sh);
    drawSceneHighlightTexture(&r->scene, sh, getCameraPosition(r->scene.camera));
    bufferDataFinish();
}
