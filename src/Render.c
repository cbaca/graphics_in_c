#include "Render.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void _renderMaterial(Render_t *r);
static void _renderTexture(Render_t *r);
void _renderHighlight(Render_t *r);

static void _setMaterialShader(Scene *s, World_t *w, MaterialShader *sh);
static void _setObjShader(Scene *s, World_t *w, ObjShader *o);
static void _setHighlightShader(Scene *s, World_t *w, HighlightShader *h, float ww, float wh);
void _renderHighlightTexture(Render_t *r);
void _renderHighlightColor(Render_t *r);

void finalizeRenderer(Render_t *r)
{
    finalizeWorld(&r->world);
    finalizeScene(&r->scene);
    free(r->oShader);
}

int initRenderer(Render_t *r)
{
    initWorld(&r->world);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    if (!materialShaderInit(&r->mShader))
        return 0;
    if (!highlightShaderInit(&r->hlShader))
        return 0;
    r->oShader = newObjShader();
    if (!r->oShader)
        return 0;

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
    _renderMaterial(r);

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


/**
 * Scene render function definitions
 */
void drawSceneColor(Scene *s, MaterialShader *sh, Vec3 *campos)
{
    drawColorRenderList(s->colorList, sh, campos);
}

void drawSceneHighlightColor(Scene *s, MaterialShader *sh, Vec3 *campos)
{
    drawColorRenderList(s->highlightList, sh, campos);
}

void drawSceneTexture(Scene *s, GLint uModel, GLint uTexture)
{
    drawTextureRenderList(s->textureList, uModel, uTexture);
}

void drawSceneHighlightTexture(Scene *s, GLint uModel, GLint uTexture)
{
    drawTextureRenderList(s->highlightList, uModel, uTexture);
}
void drawSceneHighlight(Scene *s, GLint uModel)
{
    drawHighlightRenderList(s->highlightList, uModel);
}

/**
 * RenderList render call defs
 */
void _drawObjListColor(ObjNode *sn, BufferData *cur_data, MaterialShader *sh, Vec3 *campos);
void _drawObjListTexture(ObjNode *sn, BufferData *cur_data, GLint uModel, GLint uTexture);
void _drawObjListHighlight(ObjNode *sn, BufferData *cur_data, GLint uModel);
void _drawObjListColorDebug(ObjNode *sn, BufferData *cur_data, GLint uModel, GLint uColor);

void drawHighlightRenderList(RenderList *ol, GLint uModel)
{
    // printf("Its alive\n");
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListHighlight(ol->root, curData, uModel);
}

void drawTextureRenderList(RenderList *ol, GLint uModel, GLint uTexture)
{
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListTexture(ol->root, curData, uModel, uTexture);
}

void drawColorRenderList(RenderList *ol, MaterialShader *sh, Vec3 *campos)
{
    if (!ol->root) return;
    ObjNode *curNode = ol->root;
    BufferData *curData = curNode->object->bufferData;
    bufferDataUse(curData);
    _drawObjListColor(ol->root, curData, sh, campos);
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

void _drawObjListTexture(ObjNode *sn, BufferData *cur_data, GLint uModel, GLint uTexture)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawTextureSceneObject(sn->object, uModel, uTexture);
    _drawObjListTexture(sn->next, cur_data, uModel, uTexture);
}

void _drawObjListColor(ObjNode *sn, BufferData *cur_data, MaterialShader *sh, Vec3 *campos)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawColorSceneObject(sn->object, sh, campos);
    _drawObjListColor(sn->next, cur_data, sh, campos);
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
void drawHighlightSceneObject(SceneObject *so, GLint uModel)
{
    Mat4 m;
    Vec3 scl = (Vec3){1.1f, 1.1f, 1.1f};
    setMat4(&m, so->drawMatrix);
    scaleMat4(&m, &scl);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, m.data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

void drawTextureSceneObject(SceneObject *so, GLint uModel, GLint uTexture)
{
    glActiveTexture(so->activeTexture);
    glBindTexture(GL_TEXTURE_2D, so->texture);
    glUniform1i(uTexture, so->textureIndex);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    glBindTexture(GL_TEXTURE_2D, 0);
}

// void drawColorSceneObject(SceneObject *so, GLint uModel, GLint uColor)
void drawColorSceneObject(SceneObject *so, MaterialShader *sh, Vec3 *campos)
{
    setMaterialUniforms(&sh->uMaterial, &so->material);
    glUniform3fv(sh->uCamPos, 1, (float *)campos);
    glUniform3fv(sh->uWorldPos, 1, (float *)&so->position);
    glUniformMatrix4fv(sh->uModel, 1, GL_FALSE, so->drawMatrix->data);
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
void _renderMaterial(Render_t *r)
{
    MaterialShader *sh = &r->mShader;
    _setMaterialShader(&r->scene, &r->world, sh);
    Vec3 *pos = getCameraPosition(r->scene.camera);
    drawSceneColor(&r->scene, sh, pos);// getCameraPosition(r->scene.camera));
    bufferDataFinish();

}

static void _renderTexture(Render_t *r)
{
    ObjShader *o = r->oShader;
    _setObjShader(&r->scene, &r->world, o);
    drawSceneTexture(&r->scene, o->shader.uModel, o->uTexture);
    bufferDataFinish();
}

void _renderHighlight(Render_t *r)
{
    glStencilFunc(GL_NOTEQUAL, 1, 0xff);
    glStencilMask(0x00);
    glDisable(GL_DEPTH_TEST);

    HighlightShader *hl = &r->hlShader;
    _setHighlightShader(&r->scene, &r->world, hl, r->windowW, r->windowH);
    drawSceneHighlight(&r->scene, hl->uMat.model);

    glStencilMask(0xff);
    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(0);
    bufferDataFinish();
}

static void _setMaterialShader(Scene *s, World_t *w, MaterialShader *sh)
{
    glUseProgram(sh->program);
    passViewMatrix(s, sh->uView);
    passProjectionMatrix(s, sh->uProjection);
    setLightUniforms(&sh->uDirLight, &w->dirLight);
}

static void _setHighlightShader(Scene *s, World_t *w, HighlightShader *h, float ww, float wh)
{
    glUseProgram(h->header.program);
    passViewMatrix(s, h->uMat.view);
    passProjectionMatrix(s, h->uMat.projection);
    glUniform2f(h->uResolution, ww, wh);
    glUniform1f(h->uTime, w->lastTime / 1000.0f);
}

static void _setObjShader(Scene *s, World_t *w, ObjShader *o)
{
    Shader_t *sh = &o->shader;
    glUseProgram(sh->program);
    passViewMatrix(s, sh->uView);
    passProjectionMatrix(s, sh->uProjection);
    setLightUniforms(&o->uLight, &w->dirLight);
}

void _renderHighlightColor(Render_t *r)
{
    glStencilFunc(GL_ALWAYS, 1, 0xff);
    glStencilMask(0xff);
    MaterialShader *sh = &r->mShader;
    _setMaterialShader(&r->scene, &r->world, sh);
    drawSceneHighlightColor(&r->scene, sh, getCameraPosition(r->scene.camera));
    bufferDataFinish();
}

void _renderHighlightTexture(Render_t *r)
{
    glStencilFunc(GL_ALWAYS, 1, 0xff);
    glStencilMask(0xff);
    ObjShader *o = r->oShader;
    _setObjShader(&r->scene, &r->world, o);
    drawSceneHighlightTexture(&r->scene, o->shader.uModel, o->uTexture);
    bufferDataFinish();
}
