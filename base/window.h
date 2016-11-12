/** private window.h */

#ifndef WINDMILL_WINDOW_H_
#define WINDMILL_WINDOW_H_
#define LOG_BUFFER_SIZE 512
#define TEXTURE_PATH "textures/awesomeface.png"
enum {
      VS_POSITION_LOC
    , VS_COLOR_LOC
    , VS_TEXTURE_LOC
};
int gl_glew_init(int, int);
unsigned int shader_init();
int init_shader_variables(
  unsigned int *, unsigned int *, unsigned int *, unsigned int *);
unsigned int _init_vao();
unsigned int _init_vbo();
unsigned int _init_ebo();
unsigned int _init_texture();
void get_gpu_info();

/** from graphics.c */
extern const char *const *VSHADER_STRING;
extern const char *const *FSHADER_STRING;
extern unsigned int INDEX_ARRAY3[6];
extern float VERTICES4[32];
extern float VERTICES36[180];
#endif
