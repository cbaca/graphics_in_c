/** @file main.c
 *  @author cy baca
 *  comments in japanese because it looks cool and I can so gomd
 *
 *  **double asterisk comments are descriptive of the program and meant to stay
 *  *single asterisk comments should be temporary
 *
 *  次: ３Dキューブを書いてみましょう
 *      coordinate systems（いちばん細かくから）
 *         ・  ローカル・
 *         ・  ワールド・スペースを取り出せる
 *         ・    ビュー・スペース（自分の立場の観点）
 *         ・  クリップ・スペース（画面に映るように座標をNDCに戻す
 *         ・スクリーン・スペース・ファックイェーア！
 *              もしくはviewport transform
 *
 *  float get_perspective(
 *        field_of_view // size of viewspace
 *      , aspect_ratio  // viewport_w / viewport_h
 *      , near_plane
 *      , far_plane
 *  );
 *
 *  ようするにVclip = Mprojection ・Mview ・Mmodel ・Vlocal
 *  現実にやるときはこの連続の逆だそうです
 *
 *  ヨー、ピッチ、ロールに含まれっテイル「オイラー角」に付いて
 *  ・ロール:横のX
 *  ・ビッチ:横のY
 *  ・ヨー  :縦のZ
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
extern int gl_glew_init(int, int);
extern unsigned int shader_init();
extern int init_shader_variables(
  unsigned int *, unsigned int *, unsigned int *, unsigned int *);
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
    GLuint vbo = 0            /** 頂点バッファーオブジェクト       */
         , vao = 0            /** 頂点配列オブジェクト             */
         , ebo = 0            /** エレメントバッファーオブジェクト */
         , texture_fd = 0     /** テキスチャー記述子               */
         , shader_program = 0 /** シェーダープログラム記述子       */
         ;

    /** 頂点シェーダーと連絡するためのファイル記述子 */
    // int model_fd = 0 /** "u_model"      */
    //   , view_fd = 0  /** "u_view"       */
    //   , pers_fd = 0  /** "u_perspective */
    //   ;

    /** 4x4単精度浮動小数点数行列: VSに渡します */
    // float model_m[MAT4ARRAY_LEN];
    // float view_m[MAT4ARRAY_LEN];
    // float proj_m[MAT4ARRAY_LEN];

    window = window_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!window)
        exit(EXIT_FAILURE);

    /** GLやGLFWなど初期化 */
    if (!gl_glew_init(WINDOW_WIDTH, WINDOW_HEIGHT))
        return EXIT_FAILURE;

    /** シェーダープログラムコンパイルコンパイルやリンキン */
    shader_program = shader_init();
    if (!shader_program)
        exit(EXIT_FAILURE);

    if (!init_shader_variables(&vao, &vbo, &ebo, &texture_fd))
        exit(EXIT_FAILURE);

/*** こっからは必要なくなるものが多い */
    float reality_check = 0;
    float dt = 0;
    float dx = 0.1f;
    float dy = 0.1f;
    float kali_mm[MAT4ARRAY_LEN] = { 0 };
    float kali_tm[MAT4ARRAY_LEN] = { 0 };
    float kali_rm[MAT4ARRAY_LEN] = { 0 };
    int input = 0;

    mat4array_make(kali_mm, MAT4ARRAY_IDENTITY);
    mat4array_make_translation(kali_tm, dx, dy, 0.0f);
    mat4array_make_rotation(kali_rm, dt);

    int translate_fd = glGetUniformLocation(shader_program, "u_model");

    /** プログラム・ループ */
    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();

        /** bg カーラをリフレーシュー */
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);

        /** ちょっとキーで何とか動かせれるかどうか */
        input = get_keys();
        if (input & KEY_LEFT) {
            dt -= WINDMILL_PI / 16;
            dx -= 0.001f;
        }
        if (input & KEY_RIGHT) {
            dt += WINDMILL_PI / 16;
            dx += 0.001f;
        }
        if (input & KEY_UP) {
            dt = 0;
            dy += 0.01f;
        }
        if (input & KEY_DOWN) {
            dt = 0;
            dy -= 0.01f;
        }
        /** 回ァーーーす　猫ナリ */
        if (input) {
            mat4array_make_translation(kali_tm, dx, dy, 0.0f);
            if (dt > reality_check || dt < reality_check) {
                mat4array_make_rotation(kali_rm, dt);
                mat4array_multiply(kali_mm, kali_tm);
                mat4array_multiply(kali_mm, kali_rm);
                mat4array_make_translation(kali_tm, -dx, -dy, 0.0f);
            }
            mat4array_multiply(kali_mm, kali_tm);
            dx = 0;
            dy = 0;
            dt = 0;
        }

        glUniformMatrix4fv(translate_fd, 1, GL_TRUE, kali_mm);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_fd);
        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }
/* 多分ここらへんまで ***/

    /* メモリリーク出ないように・・・な！*/
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glfwTerminate();
    return EXIT_SUCCESS;
}
