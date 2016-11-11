/** @file main.c
 *  @author cy baca
 *  using tutorials from learnopengl.com
 *  comments in japanese because it looks cool and I can so gomd
 *
 *  comment strings that start with two asteriscs describe the program
 *  functionality and are meant to stay
 *
 *  only one asterisk means its a personal comment for my own understanding
 *  and I plan to remove it later
 *
 *  if you're looking at this source code and you are an effin pro, yes I'm
 *  that aware I have no clue what I'm doing. Please let me know how to
 *  improve.
 *
 *  main workspace:
 *  4.7.2-1-ARCH x86_64 GNU/Linux
 *  Intel(R) Core(TM) i5-2320 CPU @ 3.00GHz (sandybridge)
 *  VIM - Vi IMproved 8.0
 *
 *  今の様子：行列関数いちいち作られて、なんとかトランスフォームの
 *  なんこかの式を使えてます
 *
 *  次: ３Dキューブを書いてみましょう
 *      coordinate systems（いちばん細かくから）
 *         ・  ローカル・
 *         ・  ワールド・スペースを取り出せる
 *         ・    ビュー・スペース（自分が立ってて目から除いでる観点）
 *         ・  クリップ・スペース（画面に映すためにcoordを -1.0～1.0 に
 *         ・スクリーン・スペース・ファックイェーア！
 *              もしくはviewport transform
 *
 *  ・world coordinate system must be larger than canonical 2x2x2 view volume
 *  ・use texture-mapped geometry
 *  ・use 5 buildings of different shapes around the scene
 *  ・at least one building must have different colors
 *  ・use two program objects
 *  ・place a WINDMILL in the scene
 *      ・parts need a different color on every side
 *  座標をビューからクリップに変換するのに射影マトリクスを使うんだって
 *  射影マトリクスは座標を例えば-1000から1000まであっても、それを-1~1レーンジに
 *
 *  NDC == Normalized Device Coordinates AKA -1.0 ~ 1.0
 *  process to convert coordinates from a certain range to NDC is projection
 *
 *    
 *  mat4 get_perspective(
 *        field_of_view // size of viewspace
 *      , aspect_ratio  // viewport_w / viewport_h
 *      , near_plane
 *      , far_plane
 *  );
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "keys.h"

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../includes/toriaezu_matrix.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define SHADER_BUFFER_SIZE 512

/** 関数プロトタイプ宣言 */
extern void *window_init(int, int);       /** window.c   */
extern void debug_print_keys();           /** window.c   */
extern int get_keys();                    /** input.c    */

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
    GLuint vbo = 0 /** vertex buffer object  */
         , vao = 0 /** vertex array object   */
         , ebo = 0 /** element buffer object */
         , texture_fd = 0 /** テキスチャー記述（きじゅつ）*/
         , shader_program = 0
         ;
    int translate_fd = 0;

    // float model_m[MATRIX_SIZE];
    // float view_m[MATRIX_SIZE];
    // float proj_m[MATRIX_SIZE];

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


/** こっからは必要なくなる */
    float reality_check = 0;
    float dt = 0;//TORI_PI / 24;
    float dx = 0.1f;
    float dy = 0.1f;
    float kali_mm[MATRIX_SIZE] = { 0 };
    float kali_tm[MATRIX_SIZE] = { 0 };
    float kali_rm[MATRIX_SIZE] = { 0 };
    debug_tori_print(kali_rm);
    int input = 0;

    tori_set(kali_mm, TORI_IDENTITY);
    tori_get_translate(kali_tm, dx, dy, 0.0f);
    tori_get_rotate(kali_rm, dt);

    translate_fd = glGetUniformLocation(shader_program, "u_model");

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
            dt -= TORI_PI / 16;
            dx -= 0.001f;
        }
        if (input & KEY_RIGHT) {
            dt += TORI_PI / 16;
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
            tori_get_translate(kali_tm, dx, dy, 0.0f);
            if (dt > reality_check || dt < reality_check) {
                tori_get_rotate(kali_rm, dt);
                tori_multiply(kali_mm, kali_tm);
                tori_multiply(kali_mm, kali_rm);
                tori_get_translate(kali_tm, -dx, -dy, 0.0f);
            }
            tori_multiply(kali_mm, kali_tm);
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
/** 多分ここらへんまで */

    /* メモリリーク出ないように・・・な！*/
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glfwTerminate();
    return EXIT_SUCCESS;
}
