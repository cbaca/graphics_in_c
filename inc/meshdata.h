#ifndef MESHDATA_H
#define MESHDATA_H
#include <stdlib.h>

typedef struct meshdata_t {
    float *vertices;
    float *uvs;
    float *normals;
    unsigned int *indices;
    size_t lenVertices;
    size_t lenIndices;
    size_t lenUvs;
    size_t lenNormals;
} meshdata_t;

// meshdata
void meshdata_destroy(meshdata_t *m);
void printMeshData(meshdata_t *m);
meshdata_t *genMeshdataFromFile(const char *path, meshdata_t *meshdata);

// data files
void initMeshData(const char *dirpath);
void finalizeMeshData(void);

char *getObjPath(size_t index);
char *findObjPath(const char *name);
// char *getTexPath(size_t index);

size_t getNumTexFiles(void);
size_t getNumObjFiles(void);
// void printTexFiles(void);
void printObjFiles(void);

// raw data arrays
float *get_quad_vertex_array(size_t *len);
float *get_quad_normal_array(size_t *len);
float *get_quad_uv_array(size_t *len);
unsigned int *get_quad_index_array(size_t *len);

float *get_plane_vertex_array(size_t *len);
float *get_plane_uv_array(size_t *len);
float *get_plane_normal_array(size_t *len);
unsigned int *get_plane_index_array(size_t *len);

float *getSphereVertexArray(size_t *len);
float *getSphereNormalArray(size_t *len);
unsigned int *getSphereIndexArray(size_t *len);
float *getSphereUVArray(size_t *len);

float *getPyramidVertexArray(size_t *len);
float *getPyramidNormalArray(size_t *len);
unsigned int *getPyramidIndexArray(size_t *len);
float *getPyramidUVArray(size_t *len);

float *getCubeVertexArray(size_t *len);
float *getCubeNormalArray(size_t *len);
unsigned int *getCubeIndexArray(size_t *len);
float *getCubeUVArray(size_t *len);

#endif /* MESHDATA_H */
