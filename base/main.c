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

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/input.h"
#include "../include/mat4array.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

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
extern void init_uniforms(unsigned int, int *, int *, int *);

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
    GLuint vbo = 0
         , vao = 0
         // , ebo = 0
         , texture_fd = 0
         , shader_program = 0
         ;

    /** 頂点シェーダーと連絡するためのファイル記述子 */
    int model_fd = 0 /** "u_model"      */
      , view_fd = 0  /** "u_view"       */
      , pers_fd = 0  /** "u_perspective */
      ;

    window = window_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!window)
        exit(EXIT_FAILURE);

    if (!init_shaders(&shader_program, &vao, &vbo, /* &ebo, */  &texture_fd))
        exit(EXIT_FAILURE);



    // init_uniforms(shader_program, &model_fd, &view_fd, &pers_fd);
    model_fd = glGetUniformLocation(shader_program, "u_model");
    view_fd = glGetUniformLocation(shader_program, "u_view");
    pers_fd = glGetUniformLocation(shader_program, "u_perspective");

/*** こっからはいろいろ変わったりするけ壊せんでな */
    /** 4x4単精度浮動小数点数行列: VSに渡します */
    float model_m[MAT4ARRAY_LEN];
    float view_m[MAT4ARRAY_LEN];
    float proj_m[MAT4ARRAY_LEN];

    const float oneOfour = 1.0f / 4.0f;
    float box_rad = 0;
    float box_dx = 0.0f;
    float box_dy = 0.0f;
    int input = 0;
    mat4array_set(model_m, MAT4ARRAY_IDENTITY);
    mat4array_set(view_m, MAT4ARRAY_IDENTITY);
    mat4array_set(proj_m, MAT4ARRAY_IDENTITY);
    // float tmv = (GLfloat)glfwGetTime() * WINDMILL_PI4;
    // const float rad = WINDMILL_PI4;
    // const float ar = WINDOW_WIDTH / WINDOW_HEIGHT;
    // mat4array_get_perspective(proj_m, rad, ar, 0.1f, 100.0f);
    do { /** プログラム・ループ */

        glfwPollEvents();

        /** bg カーラをリフレーシュー */
        glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_fd);

        /** シェーダープログラムを選びます。*/
        glUseProgram(shader_program);

        /** ユーザー入力 */
        /*
        */
        input = get_keys();
        if (input & KEY_RIGHT) {
            box_rad += WINDMILL_PI4 * oneOfour;
            box_dx += 0.01f;
        }
        if (input & KEY_LEFT) {
            box_rad -= WINDMILL_PI4 * oneOfour;
            box_dx -= 0.01f;
        }
        if (input & KEY_DOWN) {
            box_dy -= 0.01f;
        }
        if (input & KEY_UP) {
            box_dy += 0.01f;
        }
        // if (input & KEY_SHIFT) { }
        mat4array_translate(view_m, 0.0f, 0.0f, -0.3f);
        // mat4array_translate(model_m, box_dx, box_dy, 0.0f);
        mat4array_rotate(model_m, box_rad, 0.0f, 0.0f, 1.0f);
        if (input) {
            mat4array_get_product(model_m, view_m);
            box_dx = 0.0f;
            box_dy = 0.0f;
            box_rad = 0.0f;
        }
        // mat4array_get_product(view_m, proj_m);
        /** シェーダーに変換行列データー渡します */
        glUniformMatrix4fv(model_fd, 1, GL_FALSE, model_m);
        glUniformMatrix4fv(view_fd, 1, GL_FALSE, view_m);
        glUniformMatrix4fv(pers_fd, 1, GL_FALSE, proj_m);

        /** オブジェクトの頂点データーを渡します */
        glBindVertexArray(vao);

        /** 実際に画面に結果を画面にGPUにお願いする */
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        /** VAOなど変えたりしないといけないときもあるからとりあえず外す*/
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);

        /** よくわからんが重要です。*/
        glfwSwapBuffers(window);

    } while (!glfwWindowShouldClose(window));
/* 多分ここらへんまで ***/

    /* メモリリーク出ないように・・・な！*/
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    // glDeleteBuffers(1, &ebo);
    glfwTerminate();
    return EXIT_SUCCESS;
}
