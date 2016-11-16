/** @file main.c
 *  @author cy baca
 *  comments in japanese because it looks cool and I can so gomd
 *
 *  次: ３Dキューブを書いてみましょう
 *      coordinate systems（いちばん細かくから）
 *         ・  ローカル・スペース がモデル・マトリクスをつかうんだっけ
 *         ・  ワールド・スペース
 *         ・    ビュー・スペース（自分の立場の観点）
 *         ・  クリップ・スペース（画面に映るように座標をNDCに戻す
 *         ・スクリーン・スペース・ファックイェーア！
 *              もしくはviewport transform
 *
 *  ようするにVclip = Mprojection ・Mview ・Mmodel ・Vlocalってことは
 *  デ・ブィ・デ・シェーダーのとこはこういう風に書くんだだろな：
 *  a_Position = u_projection * u_view * u_model * vec4(a_Position, 1.0)
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/input.h"
#include "../include/mat4array.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/** objects.cのキューブス */
extern void cubes_init(float *);
extern void animate_cubes(float *);
extern void draw_cubes(int, float *, int);

extern void get_projection(float *);

/** player.c */
extern void player_init(float *restrict, float *restrict);
extern void player_update(float *restrict, double, double);
extern void player_move(float *restrict, int, float, double *, double *);
extern void player_get_view(float *restrict, float *restrict);

/** window.cで現実にされている関数プロトタイプ宣言 */
extern void *window_init(int, int);
extern int init_shaders(
      unsigned int *
    , unsigned int *
    , unsigned int *
    // , unsigned int *
    , unsigned int *);
extern void get_gpu_info();

int
main(int argc, char **argv)
/** プログラム開始 */
{
    if (argc > 1 && (strcmp(argv[1], "-i") == 0)) {
        get_gpu_info();
        exit(EXIT_SUCCESS);
    }

    /** 変数宣言 */
    GLFWwindow *window = NULL;
    unsigned int texture_fd = 0;
    unsigned int shader_fd = 0;
    unsigned int vbo = 0;
    unsigned int vao = 0;
    int model_fd = -1; /* for vs "u_model" */
    int view_fd = -1; /* for vs "u_proj"  */
    int proj_fd = -1; /* for vs "u_proj"  */

    window = window_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!window)
        exit(EXIT_FAILURE);

    if (!init_shaders(&shader_fd, &vao, &vbo, /* &ebo, */  &texture_fd))
        exit(EXIT_FAILURE);

    model_fd = glGetUniformLocation(shader_fd, "u_model");
    if (model_fd < 0)
        fprintf(stderr, "failed to locate u_model");
    view_fd = glGetUniformLocation(shader_fd, "u_view");
    if (view_fd < 0)
        fprintf(stderr, "failed to locate u_view");
    proj_fd = glGetUniformLocation(shader_fd, "u_proj");
    if (proj_fd < 0)
        fprintf(stderr, "failed to locate u_proj");

#   define x 0
#   define y 1
#   define z 2
#   define TIME_DELTA 0
#   define TIME_LAST 1
#   define TIME_NOW 2
    /* runtime vars */

    // float windmill[MAT4ARRAY_LEN * 5]; /* 320 byte */
    //float cubes[MAT4ARRAY_LEN * 2]; /* 128  bytes */
    //windmill_init(windmill);

    const int num_cubes = 5;
    float cubes[MAT4ARRAY_LEN * num_cubes]; /* 64 byte */
    cubes_init(cubes);

    float view_m[MAT4ARRAY_LEN]; /* 64 byte */
    float player[16]; /* 64 byte */
    player_init(view_m, player);

    float proj_m[MAT4ARRAY_LEN]; /* 64 byte */
    mat4array_set(proj_m, MAT4ARRAY_IDENTITY);

    double yaw = -WINDMILL_PI2;
    double pitch = 0.0;

    double times[3];

    do { /** プログラム・ループ */
        glfwPollEvents();
        /** bg カーラをリフレーシュー */
        glClearColor(0.0f, 0.0f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4array_set(proj_m, MAT4ARRAY_IDENTITY);

        /* カメラ */
        const float vel = 5.0f * (float)times[TIME_DELTA];
        player_move(player, get_keys(), vel, &yaw, &pitch);
        player_get_view(view_m, player);

        /* 世界座標 */
        get_projection(proj_m);

        /* 回転箱たち */
        // animate_cubes(cubes);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_fd);
        glUseProgram(shader_fd);

        /** シェーダーに変換行列データー渡します */
        glBindVertexArray(vao);
        glUniformMatrix4fv(view_fd, 1, GL_FALSE, view_m);
        glUniformMatrix4fv(proj_fd, 1, GL_FALSE, proj_m);

        draw_cubes(model_fd, cubes, num_cubes);


        /** VAOなど変えたりしないといけないときもあるからとりあえず外す*/
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);

        /** よくわからんが重要です。*/
        glfwSwapBuffers(window);
        times[TIME_LAST] = times[TIME_NOW];
        times[TIME_NOW] = glfwGetTime();
        times[TIME_DELTA] = times[TIME_NOW] - times[TIME_LAST];

    } while (!glfwWindowShouldClose(window));
#   undef x
#   undef y
#   undef z
/* 多分ここらへんまで ***/

    /* メモリリーク出ないように・・・な！*/
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    // glDeleteBuffers(1, &ebo);
    glfwTerminate();
    return EXIT_SUCCESS;
}
