/**
 * @file shaders.c
 * -----------------------------------------------------------------------------
 */

#include "shaders.h"
#include "data.h"

#include <stdio.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>

unsigned int _shader_program_init(void);
unsigned int _init_texture(void);
unsigned int _init_vao(void);
unsigned int _init_vertex_buffer_object(void);

typedef int bool {
    false = 0,
    true = !false
};

/*　gl object init */
int init_shaders(unsigned int *shader_program_fd)
{
    *shader_program_fd = _shader_program_init();
    if (!shader_program_fd)
        return 0;

    // *vao = _init_vao();
    // *vbo = _init_vertex_buffer_object();
    // *ebo = _init_ebo();

    // const int array_stride = (int)(8 * sizeof(float));
    // const int position_size = 3;
    // glVertexAttribPointer(
    //       VS_POSITION_LOC, position_size
    //     , GL_FLOAT, GL_FALSE
    //     , array_stride, NULL
    // );
    // glEnableVertexAttribArray(VS_POSITION_LOC);

    // const int color_size = 3;
    // glVertexAttribPointer(
    //       VS_COLOR_LOC, color_size
    //     , GL_FLOAT, GL_FALSE
    //     , array_stride, (void *)(3 * sizeof(float))
    // );
    // glEnableVertexAttribArray(VS_COLOR_LOC);

    // const int texture_size = 2;
    // glVertexAttribPointer(
    //       VS_TEXTURE_LOC, texture_size
    //     , GL_FLOAT, GL_FALSE
    //     , array_stride, (void *)(6 * sizeof(float))
    // );
    // glEnableVertexAttribArray(VS_TEXTURE_LOC);
    // *tex = _init_texture();

    /* unbind to avoid error */
    // glBindBuffer(GL_ARRAY_BUFFER, 0);
    // glBindVertexArray(0);

    // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    // glEnable(GL_DEPTH_TEST /* | GL_CULL_FACE */ );
    glEnable(GL_DEPTH_TEST);

    // return (int)(*vao && *vbo && *ebo && *tex);
    // return (int)(*vao && *vbo && *tex);
    return false;
}

unsigned int _shader_program_init()
{
    char info_log_buffer[LOG_BUFFER_SIZE];
    int sc_success;
    unsigned int v_shader_fd;
    unsigned int f_shader_fd;
    unsigned int shader_program;

    /* compile vertex shader */
    v_shader_fd = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(v_shader_fd, 1, VSHADER_STRING, NULL);
    glCompileShader(v_shader_fd);

    /* check for comilation error */
    glGetShaderiv(v_shader_fd, GL_COMPILE_STATUS, &sc_success);
    if (!sc_success) {
        glGetShaderInfoLog(v_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(stderr, "vshader compile error \n%s\n", info_log_buffer);
    }

    /* compile fragment shader */
    f_shader_fd = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(f_shader_fd, 1, FSHADER_STRING, NULL);
    glCompileShader(f_shader_fd);

    /* fragment shader compile error check */
    glGetShaderiv(f_shader_fd, GL_COMPILE_STATUS, &sc_success);
    if (!sc_success) {
        glGetShaderInfoLog(f_shader_fd, LOG_BUFFER_SIZE, NULL, info_log_buffer);
        fprintf(stderr, "fshader compile error\n%s\n", info_log_buffer);
    }

    /* shader program init and linking */
    shader_program = glCreateProgram();
    glAttachShader(shader_program, v_shader_fd);
    glAttachShader(shader_program, f_shader_fd);
    glLinkProgram(shader_program);

    glGetProgramiv(shader_program, GL_LINK_STATUS, &sc_success);
    if (!sc_success) {
        glGetProgramInfoLog(shader_program, LOG_BUFFER_SIZE, NULL,
            info_log_buffer);
        fprintf(stderr, "shader program linking failed\n%s\n", info_log_buffer);
    }

    /* free shader from memory */
    glDeleteShader(v_shader_fd);
    glDeleteShader(f_shader_fd);

    return shader_program;
}

/*
unsigned int _init_vao(void)
{
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    return vao;
}

unsigned int _init_vertex_buffer_object(void)
{
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
    GL_ARRAY_BUFFER, sizeof VERTICES36, VERTICES36, GL_STATIC_DRAW);
    return vbo;
}

unsigned int _init_ebo()
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

unsigned int _init_texture(void)
{
    unsigned char *image_fd = NULL;
    int w, h;
    unsigned int texture_fd;
    glGenTextures(1, &texture_fd);
    glBindTexture(GL_TEXTURE_2D, texture_fd);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    image_fd = SOIL_load_image(TEXTURE_PATH, &w, &h, 0, SOIL_LOAD_RGB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA , w, h, 0, GL_RGB,
        GL_UNSIGNED_BYTE, image_fd);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image_fd);
    glBindTexture(GL_TEXTURE_2D, 0);

    return texture_fd;
}
*/
