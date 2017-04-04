/**
 * @file shaders.h
 */
#ifndef SHADERS_H_
#define SHADERS_H_
struct shader_t {
    unsigned int shader_fd;
    unsigned int texture_fd;
    unsigned int vbo;
    unsigned int vao;
    unsigned int ebo;
};

struct shader_code_t {
    char *vertex;
    char *fragment;
};

int init_shaders(unsigned int *shader_program);
#endif /* SHADERS_H_ */
