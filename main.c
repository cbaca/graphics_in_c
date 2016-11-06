/** @file main.c
 *  @author cy baca
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

#define VSHADER_PATH "/shaders/vshader.glsl";
#define FSHADER_PATH "/shaders/fshader.glsl";

/** callback 関数宣言（かんすうせんげん）prototype */
void key_callback(GLFWwindow *, int, int, int, int);

/** シェーダーの文字列をファイルから取り出す */
int get_shader_string(char **vshader_buffer, char **fshader_buffer);

/** プログラム開始（かいし）*/
int
main(/* int argc, char **argv */)
{
    /** 頂点（ちょうてん）配列（はいれつ）aka バッファ
     *  頂点配列初期化
     *  ベクトルとしてGPUに渡します
     */
    GLfloat vertices[] = {
         -0.5f, -0.5f, 0.0f
        , 0.5f, -0.5f, 0.0f
        , 0.0f,  0.5f, 0.0f
    };

    /** 変数宣言（へんすうせんげん）*/
    GLchar *vertex_shader_source = NULL;
    GLchar *fragent_shader_source = NULL;
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
        , "LearnOpenGL"
        , NULL
        , NULL
    );
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);

    /** glew初期化 */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    /** シェーダープログラム文字列ゲット！*/
    if (get_shader_string(&vertex_shader_source, &fragment_shader_source));
    /**　頂点シェーダーをコンパイルしよう！*/
    v_shader_fd = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader_fd, 1, &vertex_shader_source, NULL);
    glComplieShader(v_shader_fd);

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
    glShaderSource(f_shader_fd, 1, &fragment_shader_source, NULL);
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

    /** glバッファ初期化（しょきか）*/
    glGenBuffers(1, &vertex_buffer_object);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
    /* GL_STATIC_DRAW: 実行中ほぼバッファのデータは変わらないはず
     * GL_DYNAMIC_DRAW:　実行中データはいっぱい変わっちゃう可能性が高い
     * GL_STREAM_DRAW: 絶対に毎回データ変わっちゃう
     */
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(
          VS_LOC
        , 3
        , GL_FLOAT
        , GL_FALSE
        , 3 * (sizeof GLfloat)
        , NULL
    );
    glEnableVertexAttribArray(VS_LOC);

    /*
    glGenVertexArrays(1, &vertex_array_object);
    glBindVertexArray(vertex_array_object);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof GLfloat, NULL);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    */

    glUseProgram(shader_program);

    /** アニメループ */
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        /** rendering, etc instructions */
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }

    glfwSetKeyCallback(window, key_callback);

    free(vertex_shader_source);
    free(fragent_shader_source);
    glDeleteShader(v_shader_fd);
    glDeleteShader(f_shader_fd);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void
key_callback(
      GLFWwindow *window
    , int key
    , int action
    , int scancode
    , int mode
) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    printf("scancode %d\n", scancode);
    printf("mode     %d\n", mode);
}

int
get_shader_string(char **vshader_buffer, char **fshader_buffer)
{
    FILE *vfd = NULL;
    FILE *ffd = NULL;
    char *line_buffer = NULL;
    size_t line_length = 0;

    *vshader_buffer = malloc(sizeof(char) * SHADER_BUFFER_SIZE);
    *fshader_buffer = malloc(sizeof(char) * SHADER_BUFFER_SIZE);
    
    vfd = fopen(VSHADER_PATH, "r");
    if (!vfd) {
        fprintf(stderr, "Couldn't obtain vshader file at %s\n", VSHADER_PATH);
        return EXIT_FAILURE;
    }
    while((getline(&line_buffer, &line_length, vfd)) > 0)
        strcat(*vshader_buffer, line_buffer);
    fclose(vfd);

    ffd = fopen(FSHADER_PATH, "r");
    if (!ffd) {
        fprintf(stderr, "Couldn't obtain fshader file at %s\n", FSHADER_PATH);
        return 0;
    }
    while((getline(&line_buffer, &line_length, ffd)) > 0)
        strcat(*fshader_buffer, line_buffer);
    fclose(ffd);

    free(line_buffer);
    return 1;
}
/* w coord is used for PERSPECTIVE DIVISION */
