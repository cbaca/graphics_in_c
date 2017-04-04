/**
 * @file polygon.c
 */
#include "polygon.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

static float VERTICES36[288] = {
      -0.1f, -0.1f, -0.1f
    ,  0.1f, -0.1f, -0.1f
    ,  0.1f,  0.1f, -0.1f
    ,  0.1f,  0.1f, -0.1f
    , -0.1f,  0.1f, -0.1f
    , -0.1f, -0.1f, -0.1f

    , -0.1f, -0.1f,  0.1f
    ,  0.1f, -0.1f,  0.1f
    ,  0.1f,  0.1f,  0.1f
    ,  0.1f,  0.1f,  0.1f
    , -0.1f,  0.1f,  0.1f
    , -0.1f, -0.1f,  0.1f

    , -0.1f,  0.1f,  0.1f
    , -0.1f,  0.1f, -0.1f
    , -0.1f, -0.1f, -0.1f
    , -0.1f, -0.1f, -0.1f
    , -0.1f, -0.1f,  0.1f
    , -0.1f,  0.1f,  0.1f

    ,  0.1f,  0.1f,  0.1f
    ,  0.1f,  0.1f, -0.1f
    ,  0.1f, -0.1f, -0.1f
    ,  0.1f, -0.1f, -0.1f
    ,  0.1f, -0.1f,  0.1f
    ,  0.1f,  0.1f,  0.1f

    , -0.1f, -0.1f, -0.1f
    ,  0.1f, -0.1f, -0.1f
    ,  0.1f, -0.1f,  0.1f
    ,  0.1f, -0.1f,  0.1f
    , -0.1f, -0.1f,  0.1f
    , -0.1f, -0.1f, -0.1f

    , -0.1f,  0.1f, -0.1f
    ,  0.1f,  0.1f, -0.1f
    ,  0.1f,  0.1f,  0.1f
    ,  0.1f,  0.1f,  0.1f
    , -0.1f,  0.1f,  0.1f
    , -0.1f,  0.1f, -0.1f,
};

int polygon_init(struct polygon_t *poly, struct vertex_array_t *va)
{
    if (!va) va = VERTICES36;
    glGenVertexArrays(1, &poly->vao);
    glBindVertexArray(poly->vao);

    glGenBuffers(1, &poly->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, va->length, va->array_ptr, GL_STATIC_DRAW);

    glVertexAttribPointer(0, va->length, GL_FLOAT, GL_FALSE, va->stride
    , (void *) 0);
    glEnableVertexAttribArray(0);

    return (poly->vao && poly->vbo);
}

void polygon_draw(struct polygon_t *poly)
{
    int i;
    for (i = 0; i < poly->num_parts; ++i) {
        glUniformMatrix4fv(poly->model_fd, 1, GL_FALSE, poly->parts[i]);
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }
}

void poly_destroy(struct polygon_t *poly)
{
    if (!poly) return;
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
}
