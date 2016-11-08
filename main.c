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
 *  今の様子：ただ四角を書くだけ
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

#define TEXTURE_PATH "textures/awesomeface.png"

extern const char *const *VSHADER_STRING;
extern const char *const *FSHADER_STRING;
extern unsigned int INDEX_ARRAY3[6];
extern float VERTICES4[32];
GLFWwindow *window = NULL;

/** 関数プロトタイプ宣言
 */
int wm_init();

/** キーコールバック */
void key_callback(GLFWwindow *, int, int, int, int);

/** gpu情報を標準出力に */
void get_gpu_info();
/** END 関数プロトタイプ宣言
*/

/** プログラム開始（かいし）*/
int
main(int argc, char **argv)
{
    if (argc > 1 && (strcmp(argv[1], "-i") == 0)) {
        get_gpu_info();
        exit(EXIT_SUCCESS);
    }

    /** 変数宣言 */
    GLchar info_log_buffer[LOG_BUFFER_SIZE]; /** 512 bytes */
    GLint gl_success;
    GLuint vbo /** vertex buffer object  */
         , vao /** vertex array object   */
         , ebo /** element buffer object */
         , v_shader_fd
         , f_shader_fd
         , shader_program
         ;

    /** glfwなど初期化 */
    if (!wm_init())
        return EXIT_FAILURE;

    /**　頂点シェーダーをコンパイルしよう！*/
    v_shader_fd = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader_fd, 1, VSHADER_STRING, NULL);
    glCompileShader(v_shader_fd);

    /** 頂点シェーダーコンパイラのエラーなかったように確認しましょう */
    glGetShaderiv(v_shader_fd, GL_COMPILE_STATUS, &gl_success);
    if (!gl_success) {
        glGetShaderInfoLog(v_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(stderr, "vshader compile error\n%s\n", info_log_buffer);
    }

    /** ピクセルシェーダーをコンパイルします */
    f_shader_fd = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader_fd, 1, FSHADER_STRING, NULL);
    glCompileShader(f_shader_fd);

    /** ピクセルシェーダーコンパイラのエラーなかったように確認しましょう */
    glGetShaderiv(f_shader_fd, GL_COMPILE_STATUS, &gl_success);
    if (!gl_success) {
        glGetShaderInfoLog(f_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(stderr , "fshader compile error\n%s\n", info_log_buffer);
    }

    /** シェーダープログラム初期化&リンキン */
    shader_program = glCreateProgram();
    glAttachShader(shader_program, v_shader_fd);
    glAttachShader(shader_program, f_shader_fd);
    glLinkProgram(shader_program);

    /** 出来たかしら？*/
    glGetProgramiv(shader_program, GL_LINK_STATUS, &gl_success);
    if (!gl_success) {
        glGetProgramInfoLog(shader_program, LOG_BUFFER_SIZE
                                            , NULL, info_log_buffer);
        fprintf(stderr, "shader program linking failed\n%s\n", info_log_buffer);
    }

    /** こいつらはもういらないな */
    glDeleteShader(v_shader_fd);
    glDeleteShader(f_shader_fd);

    /** glバッファ初期化 */
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    /* GL_STATIC_DRAW: 実行中ほぼバッファのデータは変わらないはず
     * GL_DYNAMIC_DRAW:　実行中データはいっぱい変わっちゃう可能性が高い
     * GL_STREAM_DRAW: 絶対に毎回データ変わっちゃう
     */
    glBufferData(
          GL_ARRAY_BUFFER
        , sizeof VERTICES4
        , VERTICES4
        , GL_STATIC_DRAW
    );

    /** エレメント配列バッファーも */
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER
        , sizeof INDEX_ARRAY3
        , INDEX_ARRAY3
        , GL_STATIC_DRAW
    );

    const int array_stride = (int)(8 * sizeof(float));
    const int position_size = 3;
    const int color_size = 3;
    const int texture_size = 2;
    glVertexAttribPointer(
          POSITION_LOCATION
        , position_size
        , GL_FLOAT
        , GL_FALSE
        , array_stride
        , NULL
    );
    glEnableVertexAttribArray(POSITION_LOCATION);

    glVertexAttribPointer(
          COLOR_LOCATION
        , color_size
        , GL_FLOAT
        , GL_FALSE
        , array_stride
        , (void *)(3 * sizeof(float))
    );
    glEnableVertexAttribArray(COLOR_LOCATION);

    glVertexAttribPointer(
          TEXTURE_LOCATION
        , texture_size
        , GL_FLOAT
        , GL_FALSE
        , array_stride
        , (void *)(6 * sizeof(float))
    );

    /** テキスチャーをつけてみましょう */
    unsigned int texture_fd;
    glGenTextures(1, &texture_fd);
    glBindTexture(GL_TEXTURE_2D, texture_fd);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    int w, h;
    unsigned char *image_fd;
    image_fd = SOIL_load_image(TEXTURE_PATH, &w, &h, 0, SOIL_LOAD_RGB);
    glTexImage2D(
          GL_TEXTURE_2D
        , 0
        , GL_RGB
        , w
        , h
        , 0
        , GL_RGB
        , GL_UNSIGNED_BYTE
        , image_fd
    );
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image_fd);
    glBindTexture(GL_TEXTURE_2D, 0);

    /** エラー起きないようにバインドを外す。でも、どういうわけかエレメント配列
     *  バッファーは外さないんだって。
     */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);


    struct _Colors {
        float r, b, g, a; /** 16 byte */
    };

    struct _Colors colors = { .r = 0.5f, .b = 0.2f, .g = 0.0f, .a = 1.0f };
    double tv;
    float time_value;
    double gv;
    int vertex_color_location;
    /** アニメループ */
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);

        tv = glfwGetTime();
        time_value = (float)tv;
        gv = (sin(time_value) / 2) + 0.5;
        colors.g = (float)gv;
        vertex_color_location = glGetUniformLocation(shader_program, "u_color");
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_fd);

        glUniform4f(
              vertex_color_location
            , colors.r
            , colors.g
            , colors.b
            , colors.a
        );

        glUniform1i(glGetUniformLocation(shader_program, "u_tex"), 0);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
wm_init()
{
    /** glfw初期化 */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /** window初期化 */
    window = glfwCreateWindow(
          WINDOW_WIDTH, WINDOW_HEIGHT
        , "Windmill hell yeah lets do this"
        , NULL, NULL
    );
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return 0;
    }
    glfwMakeContextCurrent(window);

    /** キーのどれを押したか語存に出来るようなコールバック */
    glfwSetKeyCallback(window, key_callback);

    /** glew初期化 */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    /** シェーダープログラム文字列ゲット！*/
    /* はずだった・・・ */
    return 1;
}

void
key_callback(
      GLFWwindow *win
    , int key
    , int scancode
    , int action
    , int mode
) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win/* dow */, GL_TRUE);

    /* コンパイラうるさいんじゃけこれをいれといた */
    printf("scancode %d\n", scancode);
    printf("mode     %d\n", mode);
}

void
get_gpu_info()
{
    int n;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n);
    printf("\n\n\tmax attributes: %i\n\n", n);
}

/* w coord is used for PERSPECTIVE DIVISION */
