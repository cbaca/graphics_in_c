#ifndef TEXTURE_H
#define TEXTURE_H
#include <GL/glew.h>
typedef struct Texture {
    GLuint tex;
    GLenum activeTexture;
    GLint index;
} Texture;


size_t getNumTexFiles(void);
char *getTexPath(size_t index);
void printTexFiles(void);

void printTextures(void);
size_t getMaxTextures(void);
void initTextures(const char *dir_path);
void finalizeTextures(void);
Texture *getTexture(size_t index);
void insertTexture(const char *path);
size_t insertBufferTexture(GLuint *texture, int width, int height);
#endif // TEXTURE_H
