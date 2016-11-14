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
int _gl_glew_init(int, int);
unsigned int _shader_program_init();
unsigned int _init_vao();
unsigned int _init_vbo();
unsigned int _init_ebo();
unsigned int _init_texture();

/** from graphics.c */
extern const char *const *VSHADER_STRING;
extern const char *const *FSHADER_STRING;
extern float VERTICES4[20];
extern unsigned int INDEX_ARRAY3[6];
// extern float VERTICES36[180];
extern float VERTICES36[288];
#endif
