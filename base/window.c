/** window.c
 *  glfwようなものはここでやります。glfwと言えばGLFWwindowの変数を初期化、
 *  コールバック関数、キーボード入力を格納（かくのう）など
 */

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include "window.h"

/** 関数プロトタイプ宣言 */
extern void _key_callback(GLFWwindow *, int, int, int, int); /* input.c */

/** @引数w ウィンドの横サイズのピクセル量
 *  @引数h ウィンドの縦サイズのピクセル量
 *  @戻り値（もどりち）初期化されているGLFWwindowのポインター変数
 */
void *
window_init(int w, int h)
{
    GLFWwindow *window = NULL;

    /** glfw初期化 */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /** glfw window初期化 */
    window = glfwCreateWindow( w, h
        , "Windmill hell yeah we got it from window.c" , NULL, NULL);

    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    /** キー押されたばい_key_callback関数は呼ばれます */
    glfwSetKeyCallback(window, _key_callback);

    if (!_gl_glew_init(w, h))
        return NULL;

    return window;
}

void
get_gpu_info()
{
    int n;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &n);
    printf("\n\n\tmax attributes: %i\n\n", n);
}

int
_gl_glew_init(int w, int h)
{
    /** glew初期化 */
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        return 0;
    }

    glViewport(0, 0, w, h);

    return 1;
}

/**　glオブジェクト初期化 */
int
init_shaders(
      unsigned int *shader_program
    , unsigned int *vao
    , unsigned int *vbo
//    , unsigned int *ebo
    , unsigned int *tex
    )
{
    *shader_program = _shader_program_init();
    if (!shader_program)
        return 0;

    *vao = _init_vao();
    *vbo = _init_vbo();
//    *ebo = _init_ebo();

    const int array_stride = (int)(5 * sizeof(float));
    const int position_size = 3;
    glVertexAttribPointer(
          VS_POSITION_LOC, position_size
        , GL_FLOAT, GL_FALSE
        , array_stride, NULL
    );
    glEnableVertexAttribArray(VS_POSITION_LOC);

    /*
    const int color_size = 3;
    glVertexAttribPointer(
          VS_COLOR_LOC, color_size
        , GL_FLOAT, GL_FALSE
        , array_stride, (void *)(3 * sizeof(float))
    );
    glEnableVertexAttribArray(VS_COLOR_LOC);
    */

    const int texture_size = 2;
    glVertexAttribPointer(
          VS_TEXTURE_LOC, texture_size
        , GL_FLOAT, GL_FALSE
        , array_stride, (void *)(3 * sizeof(float))
    );
    glEnableVertexAttribArray(VS_TEXTURE_LOC);
    *tex = _init_texture();

   /** エラー起きないようにバインドを外す。でも、どういうわけかエレメント配列
    *  バッファーだけは外さないんだって
    */
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST/* | GL_BLEND */);

    // return (int)(*vao && *vbo && *ebo && *tex);
    return (int)(*vao && *vbo && *tex);
}

unsigned int
_shader_program_init()
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
 // glBufferData(GL_ARRAY_BUFFER, sizeof VERTICES4, VERTICES4, GL_STATIC_DRAW);
    glBufferData(
    GL_ARRAY_BUFFER, sizeof VERTICES36, VERTICES36, GL_STATIC_DRAW);
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

void
init_uniforms(unsigned int shader_fd, int *model_fd, int *view_fd, int *pers_fd)
{
    *model_fd = glGetUniformLocation(shader_fd, "u_model");
    *view_fd = glGetUniformLocation(shader_fd, "u_view");
    *pers_fd = glGetUniformLocation(shader_fd, "u_perspective");
}
