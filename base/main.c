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

/** player.c */
extern void player_init(float *restrict);
extern void player_update(float *restrict, double, double);
extern void player_move(float *restrict, int, float);
extern void player_get_view(float *restrict, float *restrict);

/** window.cで現実にされている関数プロトタイプ宣言 */
extern void *window_init(int, int);
extern void debug_print_keys();
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
    float model_m[2][MAT4ARRAY_LEN];
    float view_m[MAT4ARRAY_LEN];
    float proj_m[MAT4ARRAY_LEN];
    // player camera data [ pos ][front][right][  up ][world]
    //                    0      3      6      9      12
    float player[12]; /* 48 byte */
    // double yaw = -WINDMILL_PI2;
    // double pitch = 0.0f;

    player_init(player);

    mat4array_set(model_m[0], MAT4ARRAY_IDENTITY);
    mat4array_set(model_m[1], MAT4ARRAY_IDENTITY);
    mat4array_set(view_m, MAT4ARRAY_IDENTITY);
    mat4array_set(proj_m, MAT4ARRAY_IDENTITY);
    double times[3];
    do { /** プログラム・ループ */
        glfwPollEvents();
        /** bg カーラをリフレーシュー */
        glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        mat4array_set(model_m[0], MAT4ARRAY_IDENTITY);
        mat4array_set(model_m[1], MAT4ARRAY_IDENTITY);
        mat4array_set(proj_m, MAT4ARRAY_IDENTITY);

        /* カメラ */
        const float vel = 0.5f * (float)times[TIME_DELTA];
        player_move(player, get_keys(), vel);
        player_get_view(view_m, player);

        /* 世界座標 */
        const float aspect = 4.0f / 3.0f;
        mat4array_get_perspective(proj_m, WINDMILL_PI4, aspect, 0.1f, 1000.0f);

        /* 回転箱 */
        const float time_scl = (float)(glfwGetTime() * WINDMILL_PI4 / 4);
        mat4array_rotate(model_m[0], time_scl, 1.0f, 1.0f, 0.0f);
        mat4array_translate(model_m[0], 0.0f, 0.0f, 0.0f);
        mat4array_rotate(model_m[1], time_scl, 1.0f, 1.0f, 0.0f);
        mat4array_translate(model_m[1], 2.3f, 1.3f, 0.0f);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_fd);
        glUseProgram(shader_fd);

        /** シェーダーに変換行列データー渡します */
        glBindVertexArray(vao);
        glUniformMatrix4fv(view_fd, 1, GL_FALSE, view_m);
        glUniformMatrix4fv(proj_fd, 1, GL_FALSE, proj_m);

        glUniformMatrix4fv(model_fd, 1, GL_FALSE, model_m[0]);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glUniformMatrix4fv(model_fd, 1, GL_FALSE, model_m[1]);
        glDrawArrays(GL_TRIANGLES, 0, 36);


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
