/**
 * @file window.c
 * -----------------------------------------------------------------------------
 */

#include "window.h"
#include "input.h"

#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

void *create_window_context(int w, int h)
{
    GLFWwindow *window = NULL;

    /* init glfw */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /* glfw window init */
    window = glfwCreateWindow( w, h
        , "Windmill hell yeah we got it from window.c" , NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    /* set key callback function from input.h */
    glfwSetKeyCallback(window, key_callback);

    /* glew init */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return NULL;
    }

    glViewport(0, 0, w, h);

    glEnable(GL_DEPTH_TEST);

    return window;
}

void get_gpu_info(void)
{
    int n;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n);
    printf("\n\n\tmax attributes: %i\n\n", n);
}
