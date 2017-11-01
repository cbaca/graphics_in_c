#ifndef MESHDATA_H
#define MESHDATA_H
#include "utils.h"
#include "Array.h"
#include <stdlib.h>

// struct Vertex {
//     Vec3 vertex;
//     Color color;
//     Vec3 normal;
//     Plane tangent;
//     Vec2 uv;
//     intArray bones;
//     floatArray weights;
//     intArray edges;
//     intArray faces; // indices
// };

typedef struct mesh_arrays_t {
    Array *vertices;
    Array *indices;
    Array *vnormals;
    Array *fnormals;
    Array *uvs;

} mesh_arrays_t;

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
