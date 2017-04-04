/**
 * @file utils.c
 */
#include "utils.h"
#include <stdio.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void print_gpu_info(void)
{
    int n;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n);
    printf("\n\n\tmax attributes: %i\n\n", n);
}
