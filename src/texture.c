#include "texture.h"
#include "utils.h"
#include <SOIL/SOIL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct TextureArray {
    Texture **texture;
    size_t max_textures;
    size_t num_textures;
} TextureArray;

static TextureArray ta;
static bool initiated;
static char **TexPaths;
static size_t NumTexFiles;
static void _initTexPaths(const char *dir_path);

size_t getNumTexFiles(void) { return NumTexFiles; }
char *getTexPath(size_t index)
{
    if (index >= NumTexFiles)
        return NULL;
    return TexPaths[index];
}

void printTexFiles(void)
{
    printStringArray("Texture files:", TexPaths, NumTexFiles);
}

size_t getMaxTextures(void)
{
    return ta.max_textures;
}

void printTextures(void)
{
    size_t i;
    for (i = 0; i < ta.num_textures; ++i)
        printf("%u %d %u\n", ta.texture[i]->tex, ta.texture[i]->activeTexture, ta.texture[i]->index);
}

void initTextures(const char *dir_path)
{
    if (initiated) {
        fprintf(stderr, "TextureArray initiated already!\n");
        return;
    }
    initiated = true;
    GLint MaxTexUnits = 0;
    glGetIntegerv(GL_MAX_TEXTURE_UNITS, &MaxTexUnits);
    if (!MaxTexUnits) {
        fprintf(stderr, "Max texture units 0\n");
        return;
    }
    ta.max_textures = (size_t) MaxTexUnits;
    ta.num_textures = 0;
    ta.texture = malloc(sizeof(Texture *) * ta.max_textures);

    _initTexPaths(dir_path);

    size_t num_tex = NumTexFiles;
    size_t i;
    if (num_tex > ta.max_textures) num_tex = ta.max_textures;
    for (i = 0; i < num_tex; ++i)
        insertTexture(getTexPath(i));

}

void finalizeTextures(void)
{
    size_t i;
    for (i = 0; i < ta.num_textures; ++i) {
        glDeleteTextures(1, &ta.texture[i]->tex);
        free(ta.texture[i]);
    }
    free(ta.texture);

    for (i = 0; i < NumTexFiles; ++i)
        free(TexPaths[i]);
    free(TexPaths);
}

Texture *getTexture(size_t index)
{
    if (index >= ta.num_textures)
        return NULL;
    return ta.texture[index];
}

void insertTexture(const char *path)
{
    if (ta.num_textures == ta.max_textures) {
        fprintf(stderr, "Texture limit maxed\n");
        return;
    }

    printf("Loading texture %s\n", path);
    int width, height;
    unsigned char *imgdata;
    GLuint texture;

    imgdata = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGBA);
    if (!imgdata) {
        fprintf(stderr, "Error reading texture file %s\n", path);
        return;
    }

    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0 + (GLenum)ta.num_textures);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP); // GL_CLAMP, GL_CLAMP_TO_EDGE, GL_MIRRORED_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgdata);
    glGenerateMipmap(GL_TEXTURE_2D);

    SOIL_free_image_data(imgdata);
    ta.texture[ta.num_textures] = malloc(sizeof(Texture));
    ta.texture[ta.num_textures]->tex = texture;
    ta.texture[ta.num_textures]->activeTexture = GL_TEXTURE0 + (GLenum)ta.num_textures;
    ta.texture[ta.num_textures]->index = (GLint)ta.num_textures;
    ta.num_textures++;
}

size_t insertBufferTexture(GLuint *tex, int width, int height)
{
    if (ta.num_textures == ta.max_textures) {
        fprintf(stderr, "Texture limit maxed\n");
        return 0;
    }

    GLuint texture;

    glGenTextures(1, &texture);
    glActiveTexture(GL_TEXTURE0 + (GLenum)ta.num_textures);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (void *)0);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, 0);

    size_t ret = ta.num_textures;
    *tex = texture;

    ta.texture[ta.num_textures] = malloc(sizeof(Texture));
    ta.texture[ta.num_textures]->tex = texture;
    ta.texture[ta.num_textures]->activeTexture = GL_TEXTURE0 + (GLenum)ta.num_textures;
    ta.texture[ta.num_textures]->index = (GLint)ta.num_textures;
    ta.num_textures++;

    return ret;
}

static void _initTexPaths(const char *dir_path)
{
    TexPaths = readDirFiles(dir_path, &NumTexFiles);
    sortStringArray(TexPaths, NumTexFiles);
}

