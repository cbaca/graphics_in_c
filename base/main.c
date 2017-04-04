/**
 * @file main.c
 * @author cy baca
 * -----------------------------------------------------------------------------
 */

#include "player.h"
#include "utils.h"
#include "shaders.h"
#include "input.h"
#include "mat4array.h"
#include "window.h"
#include "math_constants.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define GLEW_STATIC /* required by glew */
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define DEFAULT_WINDOW_WIDTH  800
#define DEFAULT_WINDOW_HEIGHT 600
#define TIME_DELTA 0
#define TIME_LAST 1
#define TIME_NOW 2
#define MODELM_LEN 16
#define NUM_CUBES 5
#define VEC_LEN 3
#define NUM_VECS 2
#define ASPECT_RATIO (12.0f / 10.0f)

static int g_window_width;
static int g_window_height;
static float g_aspect_ratio;
static float g_projection_matrix[16];

/* entry point */
int main(int argc, char **argv)
{
    if (argc > 1 && (strcmp(argv[1], "-i") == 0)) {
        print_gpu_info();
        exit(EXIT_SUCCESS);
    }

    /* main vars */
    GLFWwindow *window      = NULL;
    unsigned int texture_fd = 0;
    unsigned int shader_fd  = 0;
    int model_fd            = -1; /* for vs "u_model" */
    int view_fd             = -1; /* for vs "u_proj"  */
    int proj_fd             = -1; /* for vs "u_proj"  */

    g_window_width = DEFAULT_WINDOW_WIDTH;
    g_window_height = DEFAULT_WINDOW_HEIGHT;
    g_aspect_ratio = (float)g_window_width / (float)g_window_height;

    window = create_window_context(g_window_width, g_window_height);
    if (!window) exit(EXIT_FAILURE);

    if (!init_shaders(&shader_fd)) exit(EXIT_FAILURE);

    model_fd = glGetUniformLocation(shader_fd, "u_model");
    if (model_fd < 0) fprintf(stderr, "failed to locate u_model");

    view_fd = glGetUniformLocation(shader_fd, "u_view");
    if (view_fd < 0) fprintf(stderr, "failed to locate u_view");

    proj_fd = glGetUniformLocation(shader_fd, "u_proj");
    if (proj_fd < 0) fprintf(stderr, "failed to locate u_proj");

    // float projection_matrix[MAT4ARRAY_LEN]; /* 64 byte */

    struct player_data_t player;

    struct polygon_t poly;

    polygon_init(&poly, NULL);

    player_init((void *)&player);

    double times[3];
    float rgb[3]  = { 0.0001f, 0.002f,  0.01f   };
    float drgb[3] = { 0.0001f, 0.0003f, 0.0001f };

    glUseProgram(shader_fd);
    do { /* program loop */
        glfwPollEvents();
        /* refresh background color */
        int i = 0;
        for (; i < 3; ++i) {
            rgb[i] += drgb[i];
            if (rgb[i] > 1.0f || rgb[i] < 0.0f)
                drgb[i] = -drgb[i];
        }
        glClearColor(*rgb, *(rgb+1), *(rgb+2), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4array_set(g_projection_matrix, MAT4ARRAY_IDENTITY);

        /* camera */
        int input = get_keys();
        player_move(input, (float)times[TIME_DELTA]);
        player_get_view();

        mat4array_get_perspective(
              g_projection_matrix        /* projection matrix */
            , QUARTER_PI    /* field of view */
            , g_aspect_ratio  /* aspect ratio */
            , 0.001f        /* near plane */
            , 100.0f);      /* far plane */

        // glActiveTexture(GL_TEXTURE0);
        // glBindTexture(GL_TEXTURE_2D, texture_fd);

        /* vertex data to shader */
        glBindVertexArray(vao);
        glUniformMatrix4fv(view_fd, 1, GL_FALSE, player.view_m);
        glUniformMatrix4fv(proj_fd, 1, GL_FALSE, g_projection_matrix);

        /* unbind vao */
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);

        /* swap buffers */
        glfwSwapBuffers(window);
        times[TIME_LAST]  = times[TIME_NOW];
        times[TIME_NOW]   = glfwGetTime();
        times[TIME_DELTA] = times[TIME_NOW] - times[TIME_LAST];

    } while (!glfwWindowShouldClose(window));

    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glfwTerminate();
    return EXIT_SUCCESS;
}
