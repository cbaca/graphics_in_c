#include "Render.h"
#include "backend.h"
#include "camera.h"
#include "RenderList.h"
#include "types.h"
#include "Mat4.h"
#include <stdio.h>
#include <string.h>

#define USE_SHADER(s) glUseProgram(s->program)

#define CHECK_CUR_DATA(buffer_data, cur_data) \
    if (buffer_data != cur_data) { \
        cur_data = buffer_data;    \
        bufferDataUse(cur_data);   \
    }

static GLenum DrawMode = GL_TRIANGLES;

void rendermode_points_cb(void *rm)
{
    printf("GL_POINTS\n");
    *((GLenum *)rm) = GL_POINTS;
}

void rendermode_linestrip_cb(void *rm)
{
    printf("GL_LINE_STRIP\n");
    *((GLenum *)rm) = GL_LINE_STRIP;
}

void rendermode_lineloop_cb(void *rm)
{
    printf("GL_LINE_LOOP\n");
    *((GLenum *)rm) = GL_LINE_LOOP;
}

void rendermode_lines_cb(void *rm)
{
    printf("GL_LINES\n");
    *((GLenum *)rm) = GL_LINES;
}

void rendermode_trianglestrip_cb(void *rm)
{
    printf("GL_TRIANGLE_STRIP\n");
    *((GLenum *)rm) = GL_TRIANGLE_STRIP;
}

void rendermode_trianglefan_cb(void *rm)
{
    printf("GL_TRIANGLE_FAN\n");
    *((GLenum *)rm) = GL_TRIANGLE_FAN;
}

void rendermode_triangles_cb(void *rm)
{
    printf("GL_TRIANGLES\n");
    *((GLenum *)rm) = GL_TRIANGLES;
}

void _set_backend_render_callbacks(GLenum *rm)
{
    void *renderMode = (void *)rm;
    set_backend_key_callbacks(rendermode_points_cb, renderMode, KEY_1);
    set_backend_key_callbacks(rendermode_linestrip_cb, renderMode, KEY_2);
    set_backend_key_callbacks(rendermode_lineloop_cb, renderMode, KEY_3);
    set_backend_key_callbacks(rendermode_lines_cb, renderMode, KEY_4);
    set_backend_key_callbacks(rendermode_trianglestrip_cb, renderMode, KEY_5);
    set_backend_key_callbacks(rendermode_trianglefan_cb, renderMode, KEY_6);
    set_backend_key_callbacks(rendermode_triangles_cb, renderMode, KEY_7);
    DrawMode = GL_TRIANGLES;
}

struct render_t {
    World_t world;
    Scene scene;

    LightingShader  tShader;
    LightingShader  cShader;
    ToyShader       hShader;
    ToyShader       mShader;

    GLuint uMatBuffer;
    GLuint uLightsBuffer;

    WindowSize window_size;
    bool_t needs_update;

    unsigned int vao, vbo, ebo;
};

static const GLsizeiptr MAT4SIZE = (GLsizeiptr)(sizeof(float) * 16);

void _render_list(Renderer *r, RenderList *rl, LightingShader *sh);
void _draw_render_list(RenderList *ol, LightingShader *sh);
void _draw_obj_list(ObjNode *sn, BufferData *cur_data, LightingShader *sh);
void _draw_scene_object(SceneObject *so, LightingShader *sh);

void _renderHighlight(Renderer *r);
void drawHighlightRenderList(RenderList *ol, GLint uModel);
void _drawObjListHighlight(ObjNode *sn, BufferData *cur_data, GLint uModel);
void drawHighlightSceneObject(SceneObject *so, GLint uModel);

void destroy_renderer(Renderer *r)
{
    finalizeWorld(&r->world);
    scene_finalize(&r->scene);
    free(r);
}

void _init_quad(Renderer *r)
{
    float quadv[] = {
         1.f,  1.f, 0.f,
         1.f, -1.f, 0.f,
        -1.f, -1.f, 0.f,
        -1.f,  1.f, 0.f, };
    unsigned int quadi[] = { 0, 1, 2, 0, 3, 2 };

    glGenVertexArrays(1, &r->vao);
    glGenBuffers(1, &r->vbo);
    glGenBuffers(1, &r->ebo);
    glBindVertexArray(r->vao);
    glBindBuffer(GL_ARRAY_BUFFER, r->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadv), quadv, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, r->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(quadi), quadi, GL_STATIC_DRAW);
    glBindVertexArray(0);
}

struct render_t *new_renderer(void)
{
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_STENCIL_TEST);
    glStencilFunc(GL_NOTEQUAL, 1, 0xff);
    glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    struct render_t *r = malloc(sizeof(struct render_t));

    initWorld(&r->world);
    scene_init(&r->scene);

    // Shaders
    {
        if (!init_texture_shader(&r->tShader))  return nil;
        if (!init_color_shader(&r->cShader))    return nil;
        if (!init_marching_shader(&r->mShader)) return nil;
        if (!init_highlight_shader(&r->hShader)) return nil;

        const GLsizeiptr buflen = (GLsizeiptr)(sizeof(float) * 2 * 16);
        glGenBuffers(1, &r->uMatBuffer);
        glBindBuffer(GL_UNIFORM_BUFFER, r->uMatBuffer);
        glBufferData(GL_UNIFORM_BUFFER, buflen, nil, GL_STATIC_DRAW);
        glBindBufferRange(GL_UNIFORM_BUFFER, 0, r->uMatBuffer, 0, buflen);
    }

    _init_quad(r);

    _set_backend_render_callbacks(&DrawMode);
    return r;
}

static const int SIZE_OF_FLOAT_X3 = 3 * sizeof(GLfloat);
void render_idle(Renderer *r)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    const ToyShader *sh = &r->mShader;
    USE_SHADER(sh);
    float *cur = camera_get_mouse_pos(&r->scene.camera);
    float mou[2];
    mou[0] = -cur[0];
    mou[1] = cur[1];
    glUniform1f(sh->uTime, r->world.lastTime);
    glUniform2fv(sh->uResolution, 1, camera_get_resolution(&r->scene.camera));
    glUniform2fv(sh->uMouse, 1, mou);

    glBindVertexArray(r->vao);
    glBindBuffer(GL_ARRAY_BUFFER, r->vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, SIZE_OF_FLOAT_X3, (void *)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, r->ebo);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void _bind_matrix_data_buffer(Renderer *r)
{
    glBindBuffer(GL_UNIFORM_BUFFER, r->uMatBuffer);
    glBufferSubData(GL_UNIFORM_BUFFER, 0, MAT4SIZE, r->scene.viewMatrix->data);
    glBufferSubData(GL_UNIFORM_BUFFER, MAT4SIZE, MAT4SIZE, r->scene.projectionMatrix->data);
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

void render(Renderer *r)
{
    const float *bg_color = getWorldBGColor(&r->world);
    glClearColor(bg_color[0], bg_color[1], bg_color[2],  1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glStencilMask(0x00);

    _bind_matrix_data_buffer(r);
    _render_list(r, r->scene.colorList, &r->cShader);
    _render_list(r, r->scene.textureList, &r->tShader);

    if (scene_has_highlight_objects(&r->scene))
        _renderHighlight(r);
}

void update_renderer(Renderer *r, const WindowSize *ws, const float seconds, const bool_t needs_update)
{
    r->window_size = *ws;
    r->needs_update = needs_update;
    worldUpdate(&r->world, seconds);
    scene_update(&r->scene, needs_update);
}

/**
 * Lighting shader rendering functions defs
 */
void _render_list(Renderer *r, RenderList *rl, LightingShader *sh)
{
    Scene *s = &r->scene;
    World_t *w = &r->world;

    glUseProgram(sh->program);
    glUniform3fv(sh->uCamPos, 1, (float *)camera_get_pos(&s->camera));
    setLightUniforms(&sh->uDirLight, &w->dirLight);
    setSpotLightUniforms(&sh->uSpotLight, &w->spotLight);
    setPointLightUniforms(&sh->uPointLight, &w->pointLight);

    _draw_render_list(rl, sh);
    bufferDataFinish();
}

void _draw_render_list(RenderList *ol, LightingShader *sh)
{
    if (!ol->root) return;
    BufferData *curData = ol->root->object->bufferData;
    bufferDataUse(curData);
    _draw_obj_list(ol->root, curData, sh);
}

void _draw_obj_list(ObjNode *sn, BufferData *cur_data, LightingShader *sh)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    _draw_scene_object(sn->object, sh);
    _draw_obj_list(sn->next, cur_data, sh);
}

void _draw_scene_object(SceneObject *so, LightingShader *sh)
{
    if (sh->st & UV_ATTRIB) {
        glActiveTexture(so->activeTexture);
        glBindTexture(GL_TEXTURE_2D, so->texture);
        glUniform1i(sh->u0, so->textureIndex);

        setMaterialUniforms(&sh->uMaterial, &so->material);
        glUniformMatrix4fv(sh->uModel, 1, GL_FALSE, so->drawMatrix->data);
        glDrawElements(DrawMode, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);

        glBindTexture(GL_TEXTURE_2D, 0);
        return;
    }
    glUniform3fv(sh->u0, 1, (float *)&so->color);
    setMaterialUniforms(&sh->uMaterial, &so->material);
    glUniformMatrix4fv(sh->uModel, 1, GL_FALSE, so->drawMatrix->data);
    glDrawElements(DrawMode, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}

/**
 * Render highlighted objects function defs
 */
void _renderHighlight(Renderer *r)
{
    glStencilFunc(GL_ALWAYS, 1, 0xff);
    glStencilMask(0xff);

    // Render as usual
    _render_list(r, r->scene.highlightColorList, &r->cShader);
    _render_list(r, r->scene.highlightTextureList, &r->tShader);

    // Render highlight
    {
        glStencilFunc(GL_NOTEQUAL, 1, 0xff);
        glStencilMask(0x00);
        glDisable(GL_DEPTH_TEST);

        ToyShader *sh = &r->hShader;
        USE_SHADER(sh);
        glUniform2f(sh->uResolution, r->window_size.w, r->window_size.h);
        glUniform1f(sh->uTime, r->world.lastTime / 1000.0f);

        drawHighlightRenderList(r->scene.highlightColorList, sh->uModel);
        drawHighlightRenderList(r->scene.highlightTextureList, sh->uModel);
    }

    glStencilMask(0xff);
    glEnable(GL_DEPTH_TEST);
    glBindVertexArray(0);
    bufferDataFinish();
}

void drawHighlightRenderList(RenderList *ol, GLint uModel)
{
    if (!ol->root) return;
    BufferData *curData = ol->root->object->bufferData;
    bufferDataUse(curData);
    _drawObjListHighlight(ol->root, curData, uModel);
}

void _drawObjListHighlight(ObjNode *sn, BufferData *cur_data, GLint uModel)
{
    if (!sn) return;
    CHECK_CUR_DATA(sn->object->bufferData, cur_data);
    drawHighlightSceneObject(sn->object, uModel);
    _drawObjListHighlight(sn->next, cur_data, uModel);
}

void drawHighlightSceneObject(SceneObject *so, GLint uModel)
{
    Mat4 m;
    Vec3 scl = (Vec3){1.1f, 1.1f, 1.1f};
    setMat4(&m, so->drawMatrix);
    scaleMat4(&m, &scl);
    glUniformMatrix4fv(uModel, 1, GL_FALSE, m.data);
    // glDrawElements(GL_TRIANGLES, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
    glDrawElements(DrawMode, so->bufferData->elementCount, GL_UNSIGNED_INT, 0);
}
