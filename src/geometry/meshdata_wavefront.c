#include "meshdata.h"
#include "types.h"
#include "vecmath.h"
#include "utils.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

static size_t num_wavefront_files = 0;
static char **wavefront_file_path_array;

void wavefront_files_init(const char *dirpath)
{
    wavefront_file_path_array = readDirFiles(dirpath, &num_wavefront_files);
    sortStringArray(wavefront_file_path_array, num_wavefront_files);
}

void wavefront_files_finalize(void)
{
    size_t i;
    for (i = 0; i < num_wavefront_files; ++i)
        free(wavefront_file_path_array[i]);
    free(wavefront_file_path_array);
}


char *wavefront_filepath_search(const char *name)
{
    size_t i;
    for (i = 0; i < num_wavefront_files; ++i) {
        char *pname = getFileNameFromPath(wavefront_file_path_array[i]);
        if (strcmp(pname, name) == 0) {
            free(pname);
            return wavefront_file_path_array[i];
        }
        free(pname);
    }
    return null;
}

char *wavefront_filepath_from_index(size_t index)
{
    if (num_wavefront_files < index)
        return null;
    return wavefront_file_path_array[index];
}

size_t wavefront_filepaths_len(void)
{
    return num_wavefront_files;
}

void wavefront_paths_print(void)
{
    printStringArray("Wavefront files: ", wavefront_file_path_array, num_wavefront_files);
}

// .obj wavefront
meshdata_t *meshdata_from_wavefront(const char *path, meshdata_t *meshdata)
{
    if (!checkFileType(path, ".obj")) {
        fprintf(stderr, "Wrong filetype: %s\n", path);
        return NULL;
    }
    FILE *fp = fopen(path, "r");
    if (!fp) {
        fprintf(stderr, "Unable to open filepath: %s\n", path);
        return NULL;
    }

    printf("\tLoading mesh data from: %s\n", path);

    char *lineBuffer;
    size_t lineBufferSize = 0;
    size_t vLen = 0;
    size_t uLen = 0;
    size_t nLen = 0;
    size_t iLen = 0;

    const char *headers[4] = { "v ", "vt", "vn", "f " };
    while (getline(&lineBuffer, &lineBufferSize, fp) > 0) {
        if (memcmp(headers[0], lineBuffer, 2) == 0) vLen += 3;
        else if (memcmp(headers[1], lineBuffer, 2) == 0) uLen += 2;
        else if (memcmp(headers[2], lineBuffer, 2) == 0) nLen += 3;
        else if (memcmp(headers[3], lineBuffer, 2) == 0) iLen += 3;
    }

    rewind(fp);
    float *vertices = malloc(sizeof(float) * vLen);
    float *uvs = malloc(sizeof(float) * uLen);
    float *normals= malloc(sizeof(float) * nLen);
    unsigned int *indices = malloc(sizeof(unsigned int) * iLen);
    size_t curV = 0, curU = 0, curI = 0, curN = 0;

    while (getline(&lineBuffer, &lineBufferSize, fp) > 0) {
        if (memcmp(headers[0], lineBuffer, 2) == 0) { // vertices
            float f[3];
            sscanf(lineBuffer, "v %f %f %f\n", &f[0], &f[1], &f[2]);
            memcpy(vertices + curV, f, sizeof(f));
            curV += 3;
            assert(curV <= vLen);
        } else if (memcmp(headers[1], lineBuffer, 2) == 0) { // uvs
            float f[2];
            sscanf(lineBuffer, "vt %f %f\n", &f[0], &f[1]);
            memcpy(uvs + curU, f, sizeof(f));
            curU += 2;
            assert(curU <= uLen);
        } else if (memcmp(headers[2], lineBuffer, 2) == 0) { // vertex normals
            float f[3];
            sscanf(lineBuffer, "vn %f %f %f\n", &f[0], &f[1], &f[2]);
            memcpy(normals + curN, f, sizeof(f));
            curN += 3;
            assert(curN <= nLen);
        } else if (memcmp(headers[3], lineBuffer, 2) == 0) { // indices
            int i[9];
            sscanf(lineBuffer, "f %d/%d/%d %d/%d/%d %d/%d/%d\n",
                &i[0], &i[1], &i[2], &i[3], &i[4], &i[5], &i[6], &i[7], &i[8]);
            indices[curI++] = (unsigned int)i[0] - 1;
            indices[curI++] = (unsigned int)i[3] - 1;
            indices[curI++] = (unsigned int)i[6] - 1;
            assert(curI <= iLen);
        }
    }

    fclose(fp);
    free(lineBuffer);

    meshdata->vertices = vertices;
    meshdata->uvs = uvs;
    meshdata->normals = normals;
    meshdata->indices = indices;
    meshdata->lenVertices = vLen;
    meshdata->lenNormals = nLen;
    meshdata->lenUvs = uLen;
    meshdata->lenIndices = iLen;

    return meshdata;
}
