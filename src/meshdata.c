#include "meshdata.h"
// #include "texture.h"
#include "utils.h"
#include "Maths.h"
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// global vars
static size_t num_obj_files = 0;
static char **obj_paths;
static mesh_arrays_t pyramidArrays = { NULL, NULL, NULL, NULL, NULL };
static mesh_arrays_t cubeArrays = { NULL, NULL, NULL, NULL, NULL };
static mesh_arrays_t sphereArrays = { NULL, NULL, NULL, NULL, NULL };

// forward dec
static void _genSphereArrays(void);
static void _genPyramidArrays(void);
static void _genCubeArrays(void);
static void _finalizeFilePathData(void);
static void _finalize_mesh_arrays(mesh_arrays_t *ma);
static void _calcVertexNormal(Vec3 *A, Vec3 *B, Vec3 *C);
static void _calcUvs(float dest[2], Vec3 *src);

// definitions
static void _initObjPaths(const char *dirpath) {
    obj_paths = readDirFiles(dirpath, &num_obj_files);
    sortStringArray(obj_paths, num_obj_files);
}

void meshdata_destroy(meshdata_t *m)
{
    if (m->vertices && m->lenVertices)
        free(m->vertices);
    if (m->indices && m->lenIndices)
        free(m->indices);
    if (m->uvs && m->lenUvs)
        free(m->uvs);
    if (m->normals && m->lenNormals)
        free(m->normals);
}

void printMeshData(meshdata_t *meshdata)
{
    size_t vLen = meshdata->lenVertices;
    size_t uLen = meshdata->lenUvs;
    size_t nLen = meshdata->lenNormals;
    size_t iLen = meshdata->lenIndices;
    size_t i;
    for (i = 0; i < vLen; i+=3)
        printf("v %f %f %f\n", meshdata->vertices[i], meshdata->vertices[i+1], meshdata->vertices[i+2]);
    for (i = 0; i < uLen; i += 2)
        printf("vt %f %f\n", meshdata->uvs[i], meshdata->uvs[i+1]);
    for (i = 0; i < nLen; i += 3)
        printf("vn %f %f %f\n", meshdata->normals[i], meshdata->normals[i+1], meshdata->normals[i+2]);
    printf("s off\n");
    for (i = 0; i < iLen; i += 3)
        printf("f %u/x/x %u/x/x %u/x/x\n",
            meshdata->indices[i], meshdata->indices[i+1], meshdata->indices[i+2]);
    printf("vLen, uLen, nLen, iLen %lu %lu %lu %lu\n",
        vLen, uLen, nLen, iLen);
}

meshdata_t *genMeshdataFromFile(const char *path, meshdata_t *meshdata)
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

void _genPrimitiveArrays(void)
{
    _genPyramidArrays();
    _genCubeArrays();
    _genSphereArrays();
}

void initMeshData(const char *dirpath)
{
    _genPrimitiveArrays();
    _initObjPaths(dirpath);
}

void finalizeMeshData(void)
{
    _finalize_mesh_arrays(&pyramidArrays);
    _finalize_mesh_arrays(&cubeArrays);
    _finalize_mesh_arrays(&sphereArrays);
    _finalizeFilePathData();
}

void _finalizeFilePathData(void)
{
    size_t i;
    for (i = 0; i < num_obj_files; ++i)
        free(obj_paths[i]);
    free(obj_paths);
}

char *findObjPath(const char *name)
{
    size_t i;
    for (i = 0; i < num_obj_files; ++i) {
        char *pname = getFileNameFromPath(obj_paths[i]);
        if (strcmp(pname, name) == 0) {
            free(pname);
            return obj_paths[i];
        }
        free(pname);
    }
    fprintf(stderr, "No filepath matches %s\n", name);
    return NULL;
}

char *getObjPath(size_t index)
{
    if (index >= num_obj_files)
        return NULL;
    return obj_paths[index];
}

size_t getNumObjFiles(void) { return num_obj_files; }

void printObjFiles(void)
{
    printStringArray("Object files:", obj_paths, num_obj_files);
}

float *getSphereVertexArray(size_t *len) { return get_array_data_float(sphereArrays.vertices, len); }
unsigned int *getSphereIndexArray(size_t *len) { return get_array_data_uint(sphereArrays.indices, len); }
float *getSphereNormalArray(size_t *len) { return get_array_data_float(sphereArrays.vnormals, len); }
float *getSphereUVArray(size_t *len) { return get_array_data_float(sphereArrays.uvs, len); }

float *getPyramidVertexArray(size_t *len) { return get_array_data_float(pyramidArrays.vertices, len); }
unsigned int *getPyramidIndexArray(size_t *len) { return get_array_data_uint(pyramidArrays.indices, len); }
float *getPyramidNormalArray(size_t *len) { return get_array_data_float(pyramidArrays.vnormals, len); }
float *getPyramidUVArray(size_t *len) { return get_array_data_float(pyramidArrays.uvs, len); }

float *getCubeVertexArray(size_t *len) { return get_array_data_float(cubeArrays.vertices, len); }
unsigned int *getCubeIndexArray(size_t *len) { return get_array_data_uint(cubeArrays.indices, len); }
float *getCubeNormalArray(size_t *len) { return get_array_data_float(cubeArrays.vnormals, len); }
float *getCubeUVArray(size_t *len) { return get_array_data_float(cubeArrays.uvs, len); }

static void _genSphereArrays(void)
{
    sphereArrays.vertices = new_array(72, ARRAY_FLOAT);
    sphereArrays.vnormals = new_array(72, ARRAY_FLOAT);
    sphereArrays.indices = new_array(36, ARRAY_UNSIGNED_INT);
    sphereArrays.uvs = new_array(48, ARRAY_FLOAT);

    int64_t v_slices = 6;
    int64_t h_slices = 6;
    int64_t i, j;
    float theta_inc = 180.0f / (float)v_slices;
    float phi_inc = 360.0f / (float)h_slices;
    float radius = 1.0f;

    unsigned int ind[(v_slices + 1) * (h_slices + 1)];
    unsigned int ind_cnt = 0;
    unsigned int *iptr = ind;

    float y;
    float x;
    for (j = 0, y = 0.0f; j < v_slices + 1; ++j, ++y) {
        float the = y * TO_RAD(theta_inc);
        for (i = 0, x = 0.0f; i < h_slices + 1; ++i, ++x) {
            float phi = x * TO_RAD(phi_inc);
            float rsthe = radius * sinf(the);
            Vec3 ver, nor;
            ver = nor = (Vec3) { cosf(phi) * rsthe, radius * cosf(the), sinf(phi) * rsthe };
            append_arrayV3(sphereArrays.vertices, &ver);

            vec3normalize(&nor);
            append_arrayV3(sphereArrays.vnormals, &nor);

            float uv[2] = { phi, 1.0f - the };
            append_arrayVx(sphereArrays.uvs, uv, 2);

            *(iptr+i) = ind_cnt++;
        }
        iptr+= h_slices + 1;

    }

    iptr = ind;
    int64_t h_len = h_slices + 1;
    for (j = 0; j < v_slices; ++j) {
        for (i = 0; i < h_slices; ++i) {
            unsigned int a = iptr[i + 1];
            unsigned int b = iptr[i];
            unsigned int c = (iptr+h_len)[i];
            unsigned int d = (iptr+h_len)[i + 1];
            unsigned int in[2][3] = { { a, b, d }, { b, c, d } };
            if (j != 0) append_arrayVx(sphereArrays.indices, in[0], 3);
            if (j != h_len) append_arrayVx(sphereArrays.indices, in[1], 3);
        }
        iptr += h_len;
    }
}

static void _genCubeArrays(void)
{
    cubeArrays.vertices = new_array(72, ARRAY_FLOAT);
    cubeArrays.vnormals = new_array(72, ARRAY_FLOAT);
    cubeArrays.indices = new_array(36, ARRAY_UNSIGNED_INT);
    cubeArrays.uvs = new_array(48, ARRAY_FLOAT);

    unsigned int indices[6] = { 0, 2, 1, 2, 3, 1 };
    unsigned int vid[6][4] = { { 3, 0, 2, 1 }, { 0, 4, 1, 5 }, { 2, 1, 6, 5 },
                               { 4, 7, 5, 6 }, { 7, 3, 6, 2 }, { 7, 4, 3, 0 } };
    float norms[6][3] = { {  0.0f,  0.0f,  1.0f }, {  1.0f,  0.0f,  0.0f }, {  0.0f, -1.0f,  1.0f },
                          {  0.0f,  0.0f, -1.0f }, { -1.0f,  0.0f,  1.0f }, {  0.0f,  1.0f,  1.0f } };
    float verts[8][3] = {
        {  1.0f,  1.0f,  1.0f }, {  1.0f, -1.0f,  1.0f }, { -1.0f, -1.0f,  1.0f }, { -1.0f,  1.0f,  1.0f },
        {  1.0f,  1.0f, -1.0f }, {  1.0f, -1.0f, -1.0f }, { -1.0f, -1.0f, -1.0f }, { -1.0f,  1.0f, -1.0f } };
    float uvs[4][2] = { { 0.0f, 1.0f }, { 1.0f, 1.0f }, { 0.0f, 0.0f }, { 1.0f, 0.0f } };

    size_t i;
    for (i = 0; i < 6; ++i) {
        size_t j;
        Vec3 v[4];
        append_arrayVx(cubeArrays.indices, indices, 6);
        for (j = 0; j < 6; ++j) indices[j] += 4;

        for (j = 0; j < 4; ++j) {
            v[j] = (Vec3){ verts[vid[i][j]][0], verts[vid[i][j]][1], verts[vid[i][j]][2] };
            append_arrayV3(cubeArrays.vertices, &v[j]);
            append_arrayV3(cubeArrays.vnormals, norms[i]);
            append_arrayVx(cubeArrays.uvs, uvs[j], 2);
        }
    }
}

static void _genPyramidArrays(void)
{
    pyramidArrays.vertices = new_array(48, ARRAY_FLOAT);
    pyramidArrays.vnormals = new_array(48, ARRAY_FLOAT);
    pyramidArrays.indices = new_array(18, ARRAY_UNSIGNED_INT);
    pyramidArrays.uvs = new_array(18, ARRAY_FLOAT);

    Array *vFloor = new_array(48, ARRAY_FLOAT);
    Array *vFloorN = new_array(48, ARRAY_FLOAT);

    const size_t num_faces = 4;
    const size_t ind[4][3] = { { 1, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 }, { 0, 0, 1 } };
    const float vi[2] = { -1.0f, 1.0f };
    Vec3 nBottom = (Vec3){ 0.0f, -1.0f, 0.0f };

    unsigned int indices[3] = { 0, 1, 2 };

    size_t i;
    for (i = 0; i < num_faces; ++i) {
        size_t j = i - 1;
        if (j >= num_faces)
            j = num_faces - 1;
        Vec3 t, br, bl;
        Vec3 nt, nbr, nbl;
        t = nt = (Vec3) { 0.0f, 1.0f, 0.0f };
        br = nbr = (Vec3){ vi[ind[i][0]], vi[ind[i][1]], vi[ind[i][2]] };
        bl = nbl = (Vec3){ vi[ind[j][0]], vi[ind[j][1]], vi[ind[j][2]] };
        _calcVertexNormal(&nt, &nbr, &nbl);

        append_arrayV3(pyramidArrays.vertices, &t);
        append_arrayV3(pyramidArrays.vertices, &br);
        append_arrayV3(pyramidArrays.vertices, &bl);
        append_arrayV3(vFloor, &br);

        append_arrayV3(pyramidArrays.vnormals, &nt);
        append_arrayV3(pyramidArrays.vnormals, &nbr);
        append_arrayV3(pyramidArrays.vnormals, &nbl);
        append_arrayV3(vFloorN, &nBottom);

        float uvt[2];
        float uvbr[2];
        float uvbl[2];
        _calcUvs(uvt, &t);
        _calcUvs(uvbr, &br);
        _calcUvs(uvbl, &bl);
        append_arrayVx(pyramidArrays.uvs, uvt, 2);
        append_arrayVx(pyramidArrays.uvs, uvbr, 2);
        append_arrayVx(pyramidArrays.uvs, uvbl, 2);

        append_arrayV3(pyramidArrays.indices, &indices);
        indices[0] += 3; indices[1] += 3; indices[2] += 3;
    }

    cat_array(pyramidArrays.vertices, vFloor);
    cat_array(pyramidArrays.vnormals, vFloorN);
    append_arrayV3(pyramidArrays.indices, &indices);
    indices[1]++; indices[2]++;
    append_arrayV3(pyramidArrays.indices, &indices);
    destroy_array(vFloor);
    destroy_array(vFloorN);
}

static void _finalize_mesh_arrays(mesh_arrays_t *ma)
{
    destroy_array(ma->vertices);
    destroy_array(ma->indices);
    destroy_array(ma->vnormals);
    destroy_array(ma->fnormals);
    destroy_array(ma->uvs);
}

static void _calcVertexNormal(Vec3 *A, Vec3 *B, Vec3 *C)
{
    Vec3 a, b, c;
    Vec3 norm, tmp_c;

    vec3set(&a, A);
    vec3set(&b, B);
    vec3set(&c, C);

    vec3set(&norm, A);
    vec3set(&tmp_c, C);

    vec3sub(&tmp_c, &b);
    vec3sub(&norm, &b);
    vec3cross(&norm, &tmp_c);

    vec3normalize(vec3add(A, &norm));
    vec3normalize(vec3add(B, &norm));
    vec3normalize(vec3add(C, &norm));
}

static void _calcUvs(float dest[2], Vec3 *src)
{
    dest[0] = atan2f(src->z, -src->z) / 2.0f / PI + 0.5f;
    dest[1] = (1.0f - atan2f(-src->y, sqrtf(src->x * src->x + src->z * src->z))) / PI + 0.5f;
}

