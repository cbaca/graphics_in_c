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
    float model_m[2][MAT4ARRAY_LEN];
    float view_m[MAT4ARRAY_LEN];
    float proj_m[MAT4ARRAY_LEN];

    unsigned int texture_fd = 0;
    unsigned int shader_fd = 0;
    unsigned int vbo = 0;
    unsigned int vao = 0;
    // unsigned int ebo = 0;
    int m_fd; /* for vs "u_model" */
    int v_fd; /* for vs "u_view"  */
    int p_fd; /* for vs "u_proj"  */

    struct Camera {
        float pos[3]; /* カメラ立場 */
        float eye[3]; /* 目線       */
        float nec[3]; /* 首         */
    } cam;

    window = window_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!window)
        exit(EXIT_FAILURE);

    if (!init_shaders(&shader_fd, &vao, &vbo, /* &ebo, */  &texture_fd))
        exit(EXIT_FAILURE);

    init_uniforms(shader_fd, &m_fd, &v_fd, &p_fd);

/*** こっからはいろいろ変わったりするけ壊せんでな */
    /** 4x4単精度浮動小数点数行列: VSに渡します */


#   define x 0
#   define y 1
#   define z 2
    mat4array_set(model_m[0], MAT4ARRAY_IDENTITY);
    mat4array_set(model_m[1], MAT4ARRAY_IDENTITY);
    mat4array_set(view_m, MAT4ARRAY_IDENTITY);
    mat4array_set(proj_m, MAT4ARRAY_IDENTITY);
    cam.pos[x] = 4.0; cam.eye[x] = 0.0f; cam.nec[x] = 0.0f;
    cam.pos[y] = 0.0; cam.eye[y] = 0.0f; cam.nec[y] = 1.0f;
    cam.pos[z] = 5.0; cam.eye[z] = 0.0f; cam.nec[z] = 0.0f;
    double nowt = 0.0f;
    double dt = 0.0f;
    double last = 0.0f;
    do { /** プログラム・ループ */
        glfwPollEvents();
        /** bg カーラをリフレーシュー */
        glClearColor(0.3f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        mat4array_set(model_m[0], MAT4ARRAY_IDENTITY);
        mat4array_set(model_m[1], MAT4ARRAY_IDENTITY);
        mat4array_set(proj_m, MAT4ARRAY_IDENTITY);
        float dcam = 5.0f * (float)dt;
        // float dy = 0.1f;
        // float dz = 0.1f;
        // float shift = 0.0f;
        int input = get_keys();
        if (input & KEY_SHIFT) {
        }
        if (input & KEY_UP) {
            cam.pos[x] += dcam;
            cam.pos[y] += dcam;
            cam.pos[z] += dcam;
        }
        if (input & KEY_DOWN) {
            cam.pos[x] -= dcam;
            cam.pos[y] -= dcam;
            cam.pos[z] -= dcam;
        }
        if (input & KEY_RIGHT) {
            cam.pos[x] += dcam;
            cam.pos[y] += dcam;
            cam.pos[z] += dcam;
        }
        if (input & KEY_LEFT) {
            cam.pos[x] -= dcam;
            cam.pos[y] -= dcam;
            cam.pos[z] -= dcam;
            /*
            float cross[3] = {
                  cam.eye[y] * cam.nec[z] - cam.eye[z] * cam.nec[y]
                , cam.eye[z] * cam.nec[x] - cam.eye[x] * cam.nec[z]
                , cam.eye[x] * cam.nec[y] - cam.eye[y] * cam.nec[x] };
            float rlen = 1.0f / (float)sqrt(
                  cross[x] * cross[x]
                + cross[y] * cross[y]
                + cross[z] * cross[z] );
            cam.pos[x] -= cross[x] * rlen * dcam;
            cam.pos[y] -= cross[y] * rlen * dcam;
            cam.pos[z] -= cross[z] * rlen * dcam;
            */
        }
        /* カメラ */
        mat4array_get_look_at(view_m, cam.pos, cam.eye, cam.nec);

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
        glUniformMatrix4fv(v_fd, 1, GL_FALSE, view_m);
        glUniformMatrix4fv(p_fd, 1, GL_FALSE, proj_m);

        glUniformMatrix4fv(m_fd, 1, GL_FALSE, model_m[0]);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        glUniformMatrix4fv(m_fd, 1, GL_FALSE, model_m[1]);
        glDrawArrays(GL_TRIANGLES, 0, 36);


        /** VAOなど変えたりしないといけないときもあるからとりあえず外す*/
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);

        /** よくわからんが重要です。*/
        glfwSwapBuffers(window);
        last = nowt;
        nowt = glfwGetTime();
        dt = nowt - last;

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
