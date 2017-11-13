
#include "shaderdata.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>

static char **shader_paths;
static size_t num_shader_files;

int initShaderData(const char *dirpath)
{
    shader_paths = readDirFiles(dirpath, &num_shader_files);
    if (!shader_paths)
        return 0;
    sortStringArray(shader_paths, num_shader_files);
    return 1;
}

void printShaderFiles(void)
{
    printStringArray("Shader files:", shader_paths, num_shader_files);
}

void destroyShaderData(void)
{
    size_t i;
    for (i = 0; i < num_shader_files; ++i)
        free(shader_paths[i]);
    free(shader_paths);
}
