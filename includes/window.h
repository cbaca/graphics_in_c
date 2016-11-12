/** window.h */

#ifndef _WINDOW_H_
#define _WINDOW_H_

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#define LOG_BUFFER_SIZE 512

/** 関数プロトタイプ宣言 */
int gl_glew_init(int, int);
unsigned int shader_init();
int init_shader_variables(
  unsigned int *, unsigned int *, unsigned int *, unsigned int *);
unsigned int _init_vao();
unsigned int _init_vbo();
unsigned int _init_ebo();
unsigned int _init_texture();
void get_gpu_info();
#endif
