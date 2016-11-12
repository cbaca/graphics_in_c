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
 *  次: ３Dキューブを書いてみましょう
 *      coordinate systems（いちばん細かくから）
 *         ・  ローカル・
 *         ・  ワールド・スペースを取り出せる
 *         ・    ビュー・スペース（自分の立場の観点）
 *         ・  クリップ・スペース（画面に映るように座標をNDCに戻す
 *         ・スクリーン・スペース・ファックイェーア！
 *              もしくはviewport transform
 *
 *  mat4 get_perspective(
 *        field_of_view // size of viewspace
 *      , aspect_ratio  // viewport_w / viewport_h
 *      , near_plane
 *      , far_plane
 *  );
 *
 *  ようするにVclip = Mprojection ・Mview ・Mmodel ・Vlocal
 *  現実にやるときはこの連続の逆パタンだって
 *
 *  ヨー、ピッチ、ロールに含まれっテイル「オイラー角」の理解しやすい考えかたです
 *  ・ロールと言えば、飛び中飛行機は曲がるときに右側の羽か左側の羽どっちかが下へ
 *    、もうどっちかが上へ。ときに、飛行機の体が周り回転するじゃないですか。って
 *    ことなら、飛行機自体がX軸みたいじゃーーん。そして「回転」って英語で言おう
 *    と思えば、「ロール」って言わないっけ？だよな！ほら、飛行機 ＝ ロール ＝ X軸
 *  ・ピッチがY回転軸やったな。思いたかったと違ってYは縦じゃなくて、
 *    飛行機の羽の先がつなげられる線のほうだったらしい。と覚えとけば、後は飛行機が
 *    上か下に迎えるときにのその羽の間の線を考えればいいから。直感的にわかりやすいかも
 *    まぁ、とりあえずピッチがY回転軸です。そして、Y回転軸がX回転軸じゃないはの横に
 *    なってるやつです。
 *  ・ヨーがZです。なぜならXとYはもうとられている。そんだけです。直感的にわかりやすい
 *    飛考え方は、行機は飛んでる間にゴジラとか狂人とかに攻撃された場合だけしかに直接
 *    曲がらない回転軸。それ縦のやつだったな。わかりやすべ？
 *  要約に、
 *  ・ロールが横のX。からの
 *  ・ビッチがもう一つの横のY。
 *  ・ヨーが縦のZ。お終了です。
 *  ・理由は意味不明。おやすみなさい。
 *  やっぱ説明としてくそやけこれも見といてください：
 *    https://en.wikipedia.org/wiki/Aircraft_principal_axes
 */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/keys.h"

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../includes/toriaezu_matrix.h"
#include "../includes/input.h"

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
    // mat4 model_m[MAT_SIZE];
    // mat4 view_m[MAT_SIZE];
    // mat4 proj_m[MAT_SIZE];

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
    mat4 kali_mm[MAT_SIZE] = { 0 };
    mat4 kali_tm[MAT_SIZE] = { 0 };
    mat4 kali_rm[MAT_SIZE] = { 0 };
    int input = 0;

    tori_set(kali_mm, TORI_IDENTITY);
    tori_get_translate(kali_tm, dx, dy, 0.0f);
    tori_get_rotate(kali_rm, dt);

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
/* 多分ここらへんまで ***/

    /* メモリリーク出ないように・・・な！*/
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glfwTerminate();
    return EXIT_SUCCESS;
}
