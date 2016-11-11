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
 *         ・ローカル
 *         ・からのワールドスペースを取り出せる
 *         ・ヴぃーウスペース（自分が立ってて目から除いでる観点）
 *         ・クリップスペース（画面に映すためにcoordを -1.0～1.0 に
 *         ・スクリーンスペース・ファックイェーア！
 *              もしくはviewport transform
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/** idky but apparently glew wants this */
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LOG_BUFFER_SIZE 512
#define SHADER_BUFFER_SIZE 512

#define POSITION_LOCATION 0
#define COLOR_LOCATION 1
#define TEXTURE_LOCATION 2

#define TEXTURE_PATH "textures/ff.png"

#include "includes/toriaezu_matrix.h"
/** import variables */
extern const char *const *VSHADER_STRING; /** graphics.c */
extern const char *const *FSHADER_STRING; /** graphics.c */
extern unsigned int INDEX_ARRAY3[6];      /** graphics.c */
extern float VERTICES4[32];               /** graphics.c */

/** import functions */
extern void *window_init(int, int);       /** window.c   */
extern void debug_print_keys();           /** window.c   */


GLFWwindow *window = NULL;

/** 関数プロトタイプ宣言
 */
int gl_glew_init();
unsigned int shader_init();
int init_shader_variables(
      unsigned int *, unsigned int *, unsigned int *, unsigned int *);
    unsigned int _init_vao();
    unsigned int _init_vbo();
    unsigned int _init_ebo();
    unsigned int _init_texture();

/** gpu情報を標準出力に */
void get_gpu_info();
/** END 関数プロトタイプ宣言
*/

int
main(int argc, char **argv)
/** プログラム開始 */
{
    if (argc > 1 && (strcmp(argv[1], "-i") == 0)) {
        get_gpu_info();
        exit(EXIT_SUCCESS);
    }

    /** 変数宣言 */
    GLuint vbo = 0 /** vertex buffer object  */
         , vao = 0 /** vertex array object   */
         , ebo = 0 /** element buffer object */
         , texture_fd = 0 /** テキスチャー記述（きじゅつ）*/
         , shader_program = 0
         ;
    int translate_fd = 0;

    window = window_init(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!window)
        exit(EXIT_FAILURE);

    /** GLやGLFWなど初期化 */
    if (!gl_glew_init())
        return EXIT_FAILURE;

    /** シェーダープログラムコンパイルコンパイルやリンキン */
    shader_program = shader_init();
    if (!shader_program)
        exit(EXIT_FAILURE);

    if (!init_shader_variables(&vao, &vbo, &ebo, &texture_fd))
        exit(EXIT_FAILURE);


    const float dt = TORI_PI / 24;
    float dx = 0.1f;
    float dy = 0.1f;
    float kali_mm[MATRIX_SIZE] = { 0 };
    float kali_tm[MATRIX_SIZE] = { 0 };
    float kali_rm[MATRIX_SIZE] = { 0 };

    tori_set(kali_mm, TORI_IDENTITY);
    tori_get_translate(kali_tm, dx, dy, 0.0f);
    tori_get_rotate(kali_rm, dt);

    translate_fd = glGetUniformLocation(shader_program, "u_transform");

    /** プログラム・ループ */
    while (!glfwWindowShouldClose(window)) {

        glfwPollEvents();
        
        /** bg カーラをリフレーシュー */
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);

        /** 回ァーーーす　猫ナリ */
        tori_get_translate(kali_tm, dx, dy, 0.0f);
        tori_get_rotate(kali_rm,  glfwGetTime() * dt);
        tori_multiply(kali_mm, kali_tm);
        tori_multiply(kali_mm, kali_rm);
        tori_get_translate(kali_tm, -dx, -dy, 0.0f);
        tori_multiply(kali_mm, kali_tm);

        glUniformMatrix4fv(translate_fd, 1, GL_TRUE, kali_mm);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_fd);
        glBindVertexArray(vao);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    /* メモリリーク出ないように・・・な！*/
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glfwTerminate();
    return EXIT_SUCCESS;
}

int
gl_glew_init()
{
    /** glew初期化 */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return 0;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    return 1;
}

void
get_gpu_info()
{
    int n;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n);
    printf("\n\n\tmax attributes: %i\n\n", n);
}

/**　glオブジェクト初期化 */
int
init_shader_variables(
      unsigned int *vao
    , unsigned int *vbo
    , unsigned int *ebo
    , unsigned int *tex
    )
{
    *vao = _init_vao();
    *vbo = _init_vbo();
    *ebo = _init_ebo();

    const int array_stride = (int)(8 * sizeof(float));
    const int position_size = 3;
    glVertexAttribPointer(
          POSITION_LOCATION, position_size
        , GL_FLOAT, GL_FALSE
        , array_stride, NULL
    );
    glEnableVertexAttribArray(POSITION_LOCATION);

    const int color_size = 3;
    glVertexAttribPointer(
          COLOR_LOCATION, color_size
        , GL_FLOAT, GL_FALSE
        , array_stride, (void *)(3 * sizeof(float))
    );
    glEnableVertexAttribArray(COLOR_LOCATION);

    const int texture_size = 2;
    glVertexAttribPointer(
          TEXTURE_LOCATION, texture_size
        , GL_FLOAT, GL_FALSE
        , array_stride, (void *)(6 * sizeof(float))
    );
    glEnableVertexAttribArray(TEXTURE_LOCATION);
    *tex = _init_texture();

   /** エラー起きないようにバインドを外す。でも、どういうわけかエレメント配列
    *  バッファーだけは外さないんだって
    */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    return (int)(*vao && *vbo && *ebo && *tex);
}

unsigned int
shader_init()
{
    char info_log_buffer[LOG_BUFFER_SIZE];
    int sc_success;
    unsigned int v_shader_fd
               , f_shader_fd
               , shader_program
               ;

    /** 頂点シェーダーをコンパイルしよう！*/
    v_shader_fd = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader_fd, 1, VSHADER_STRING, NULL);
    glCompileShader(v_shader_fd);

    /** 頂点しぇーだーコンパイラエラーなかったように確認しましょう */
    glGetShaderiv(v_shader_fd, GL_COMPILE_STATUS, &sc_success);
    if (!sc_success) {
        glGetShaderInfoLog(v_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(stderr, "vshader compile error \n%s\n", info_log_buffer);
    }

    /** ピクセルシェーダーコンパイルします */
    f_shader_fd = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader_fd, 1, FSHADER_STRING, NULL);
    glCompileShader(f_shader_fd);

    /** ピクセルシェーダーコンパイラなかったように確認でしゅ */
    glGetShaderiv(f_shader_fd, GL_COMPILE_STATUS, &sc_success);
    if (!sc_success) {
        glGetShaderInfoLog(f_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(stderr, "fshader compile error\n%s\n", info_log_buffer);
    }

    /** シェーダープログラム初期化&リンキン */
    shader_program = glCreateProgram();
    glAttachShader(shader_program, v_shader_fd);
    glAttachShader(shader_program, f_shader_fd);
    glLinkProgram(shader_program);

    /** 出来かしら */
    glGetProgramiv(shader_program, GL_LINK_STATUS, &sc_success);
    if (!sc_success) {
        glGetProgramInfoLog(
            shader_program
          , LOG_BUFFER_SIZE
          , NULL
          , info_log_buffer
      );
        fprintf(stderr, "shader program linking failed\n%s\n", info_log_buffer);
    }

    /** こういつらはもういらないな */
    glDeleteShader(v_shader_fd);
    glDeleteShader(f_shader_fd);

    return shader_program;
}

/** gl頂点配列オブジェクト初期化 */
unsigned int
_init_vao()
{
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

/** gl頂点バッファーオブジェクト初期化 */
unsigned int
_init_vbo()
{
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    /* GL_STATIC_DRAW: 実行中ほぼバッファのデータは変わらないはず
     * GL_DYNAMIC_DRAW:　実行中データはいっぱい変わっちゃう可能性が高い
     * GL_STREAM_DRAW: 絶対に毎回データ変わっちゃう
     */
    glBufferData(GL_ARRAY_BUFFER, sizeof VERTICES4, VERTICES4, GL_STATIC_DRAW);
    return vbo;
}

/** glエレメントバッファーオブジェクト初期化 */
unsigned int
_init_ebo()
{
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
          GL_ELEMENT_ARRAY_BUFFER
        , sizeof INDEX_ARRAY3
        , INDEX_ARRAY3
        , GL_STATIC_DRAW
    );
    return ebo;
}

unsigned int
_init_texture()
{
    unsigned char *image_fd = NULL;
    int w, h;
    unsigned int texture_fd;
    glGenTextures(1, &texture_fd);
    glBindTexture(GL_TEXTURE_2D, texture_fd);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image_fd = SOIL_load_image(TEXTURE_PATH, &w, &h, 0, SOIL_LOAD_RGB);
    glTexImage2D(
          GL_TEXTURE_2D, 0, GL_RGB
        , w, h, 0
        , GL_RGB, GL_UNSIGNED_BYTE, image_fd
    );
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image_fd);
    glBindTexture(GL_TEXTURE_2D, 0);

    return texture_fd;
}
