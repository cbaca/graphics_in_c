/** @file main.c
 *  @author cy baca
 *  using tutorials from learnopengl.com
 *  comments in japanese because it looks cool and I can
 *
 *  comment strings that start with two asteriscs describe the program
 *  functionality and are meant to stay
 *
 *  only one asterisk means its a personal comment for my own understanding
 *  and I plan to remove it later
 *
 *  if you're looking at this source code, yes I'm aware I have no clue what,
 *  I'm doing, thank you
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** idky but apparently glew wants this */
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LOG_BUFFER_SIZE 512
#define SHADER_BUFFER_SIZE 512
#define VS_LOC 0

#define VSHADER_PATH "shaders/vshader.glsl"
#define FSHADER_PATH "shaders/fshader.glsl"

/** callback 関数宣言（かんすうせんげん）prototype */
void key_callback(GLFWwindow *, int, int, int, int);

/** シェーダーの文字列をファイルから取り出す */
int get_shader_string(char *restrict, char *restrict);

/** プログラム開始（かいし）*/
int
main(/* int argc, char **argv */)
{
    /** 頂点（ちょうてん）配列（はいれつ）aka バッファ
     *  頂点配列初期化
     *  ベクトルとしてGPUに渡します
     */
    GLfloat vertices[] = {
         -0.5f, -0.5f, 0.0f /** 左側ジャわ     */
        , 0.5f, -0.5f, 0.0f /** 右側じゃってな */
        , 0.0f,  0.5f, 0.0f /** 上っっす       */
    };

    /** 変数宣言（へんすうせんげん）*/
    GLchar *vertex_shader_buffer = NULL;
    GLchar *fragment_shader_buffer = NULL;
    //GLchar const *vertex_shader_buffer[1];
    //GLchar const *fragment_shader_buffer[1];
    GLchar info_log_buffer[LOG_BUFFER_SIZE];
    GLint gl_success;
    GLuint vertex_buffer_object
         , vertex_array_object
         , v_shader_fd
         , f_shader_fd
         , shader_program
        ;

    /** glfw初期化 */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /** window初期化 */
    GLFWwindow *window = glfwCreateWindow(
          WINDOW_WIDTH
        , WINDOW_HEIGHT
        , "WindMillIfImLucky"
        , NULL
        , NULL
    );
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return EXIT_FAILURE;
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
    vertex_shader_buffer = malloc(sizeof(GLchar) * SHADER_BUFFER_SIZE);
    fragment_shader_buffer = malloc(sizeof(GLchar) * SHADER_BUFFER_SIZE);
    if (!get_shader_string(vertex_shader_buffer, fragment_shader_buffer))
        exit(EXIT_FAILURE);

    /**　頂点シェーダーをコンパイルしよう！*/
    v_shader_fd = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader_fd, 1, (const GLchar **)vertex_shader_buffer, NULL);
    glCompileShader(v_shader_fd);

    /** 頂点シェーダーコンパイラのエラーなかったように確認しましょう */
    glGetShaderiv(v_shader_fd, GL_COMPILE_STATUS, &gl_success);
    if (!gl_success) {
        glGetShaderInfoLog(v_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(
              stderr
            , "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s\n"
            , info_log_buffer
        );
    }

    /** ピクセルシェーダーをコンパイルします */
    f_shader_fd = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader_fd, 1, (const GLchar  **)fragment_shader_buffer, NULL);
    glCompileShader(f_shader_fd);

    /** ピクセルシェーダーコンパイラのエラーなかったように確認しましょう */
    glGetShaderiv(f_shader_fd, GL_COMPILE_STATUS, &gl_success);
    if (!gl_success) {
        glGetShaderInfoLog(f_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(
              stderr
            , "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n%s\n"
            , info_log_buffer
        );
    }

    /** シェーダープログラム初期化&リンキン */
    shader_program = glCreateProgram();
    glAttachShader(shader_program, v_shader_fd);
    glAttachShader(shader_program, f_shader_fd);
    glLinkProgram(shader_program);

    /** 出来たかしら？*/
    glGetProgramiv(shader_program, GL_LINK_STATUS, &gl_success);
    if (!gl_success) {
        glGetProgramInfoLog(
              shader_program
            , LOG_BUFFER_SIZE
            , NULL
            , info_log_buffer
        );
        fprintf(
              stderr
            , "ERROR::SHADER::PROGRAM::LINKING_FAILED\n%s\n"
            , info_log_buffer
        );
    }

    /** こいつらはもういらないな */
    glDeleteShader(v_shader_fd);
    glDeleteShader(f_shader_fd);

    /** glバッファ初期化（しょきか）*/
    glGenVertexArrays(1, &vertex_array_object);
    glGenBuffers(1, &vertex_buffer_object);
    glBindVertexArray(vertex_array_object);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
    /* GL_STATIC_DRAW: 実行中ほぼバッファのデータは変わらないはず
     * GL_DYNAMIC_DRAW:　実行中データはいっぱい変わっちゃう可能性が高い
     * GL_STREAM_DRAW: 絶対に毎回データ変わっちゃう
     */
    glBufferData(GL_ARRAY_BUFFER, (sizeof vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(
          VS_LOC
        , 3
        , GL_FLOAT
        , GL_FALSE
        , 3 * sizeof (GLfloat)
        , NULL
    );
    glEnableVertexAttribArray(VS_LOC);

    /** エラー起きないようにバインドを外す */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    /** アニメループ */
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_program);
        glBindVertexArray(vertex_array_object);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        glfwSwapBuffers(window);
    }

    glDeleteVertexArrays(1, &vertex_array_object);
    glDeleteBuffers(1, &vertex_buffer_object);
    free(vertex_shader_buffer);
    free(fragment_shader_buffer);
    // glDeleteShader(v_shader_fd);
    // glDeleteShader(f_shader_fd);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void
key_callback(
      GLFWwindow *window
    , int key
    , int scancode
    , int action
    , int mode
) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    printf("scancode %d\n", scancode);
    printf("mode     %d\n", mode);
}

int
get_shader_string(char *restrict vshader_buffer, char *restrict fshader_buffer)
{
    FILE *vfd = NULL;
    FILE *ffd = NULL;
    size_t i;
    int c;

    vfd = fopen(VSHADER_PATH, "r");
    if (!vfd) {
        fprintf(stderr, "Couldn't obtain vshader file at %s\n", VSHADER_PATH);
        return EXIT_FAILURE;
    }
    for (i = 0, c = 0; c != EOF; ++i) {
        c = fgetc(vfd);
        vshader_buffer[i] = (char)c;
    }
    vshader_buffer[i - 1] = '\0';
    fclose(vfd);

    ffd = fopen(FSHADER_PATH, "r");
    if (!ffd) {
        fprintf(stderr, "Couldn't obtain fshader file at %s\n", FSHADER_PATH);
        return 0;
    }
    for (i = 0, c = 0; c != EOF; ++i) {
        c = fgetc(ffd);
        fshader_buffer[i] = (char)c;
    }
    fshader_buffer[i - 1] = '\0';
    fclose(ffd);

    return 1;
}
/* w coord is used for PERSPECTIVE DIVISION */