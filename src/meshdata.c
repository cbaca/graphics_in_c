#include "meshdata.h"
#include "types.h"
#include "vecmath.h"
#include "utils.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

/* global vars */
static meshdata_t sphere_arrays;
static meshdata_t cube_arrays;
static meshdata_t pyramid_arrays;
static struct meshdata quad_arrays;

void _meshdata_destroy(struct meshdata *m)
{
    if (m->vertices)
        free(m->vertices);

    if (m->vnormals)
        free(m->vnormals);

    if (m->fnormals)
        free(m->fnormals);

    if (m->uvs)
        free(m->uvs);

    if (m->indices)
        free(m->indices);
}

/* definitions */
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

void meshdata_print(meshdata_t *meshdata)
{
    size_t vLen = meshdata->lenVertices;
    size_t uLen = meshdata->lenUvs;
    size_t nLen = meshdata->lenNormals;
    size_t iLen = meshdata->lenIndices;
    size_t i;
    for (i = 0; i < vLen; i+=3)
        printf("v %f %f %f\n",
            meshdata->vertices[i],
            meshdata->vertices[i+1],
            meshdata->vertices[i+2]);
    for (i = 0; i < uLen; i += 2)
        printf("vt %f %f\n", meshdata->uvs[i], meshdata->uvs[i+1]);
    for (i = 0; i < nLen; i += 3)
        printf("vn %f %f %f\n",
            meshdata->normals[i],
            meshdata->normals[i+1],
            meshdata->normals[i+2]);
    printf("s off\n");
    for (i = 0; i < iLen; i += 3)
        printf("f %u/x/x %u/x/x %u/x/x\n",
            meshdata->indices[i], meshdata->indices[i+1], meshdata->indices[i+2]);
    printf("vLen, uLen, nLen, iLen %lu %lu %lu %lu\n",
        vLen, uLen, nLen, iLen);
}

void meshdata_arrays_init(const char *dirpath)
{
    meshdata_generate_quad(&quad_arrays);
    meshdata_generate_pyramid(&pyramid_arrays);
    meshdata_generate_cube(&cube_arrays);
    meshdata_generate_sphere(&sphere_arrays);
    wavefront_files_init(dirpath);
}

void meshdata_arrays_finalize(void)
{
    // _meshdata_destroy(&quad_arrays);
    meshdata_destroy(&pyramid_arrays);
    meshdata_destroy(&cube_arrays);
    meshdata_destroy(&sphere_arrays);
    wavefront_files_finalize();
}

void *get_quad_vertex_array(size_t *len)
{
    *len = quad_arrays.v_len;
    return quad_arrays.vertices;
}

void *get_quad_normal_array(size_t *len)
{
    *len = quad_arrays.fn_len;
    return quad_arrays.fnormals;
}

void *get_quad_uv_array(size_t *len)
{
    *len = quad_arrays.uv_len;
    return quad_arrays.uvs;
}

void *get_quad_index_array(size_t *len)
{
    *len = quad_arrays.i_len;
    return quad_arrays.indices;
}

/*
 * Sphere data get function implementations
 */
void *getSphereVertexArray(size_t *len)
{
    *len = sphere_arrays.lenVertices;
    return sphere_arrays.vertices;
}

void *getSphereIndexArray(size_t *len)
{
    *len = sphere_arrays.lenIndices;
    return sphere_arrays.indices;
}

void *getSphereNormalArray(size_t *len)
{
    *len = sphere_arrays.lenNormals;
    return sphere_arrays.normals;
}

void *getSphereUVArray(size_t *len)
{
    *len = sphere_arrays.lenUvs;
    return sphere_arrays.uvs;
}

/*
 * Pyramid data get function implementations
 */
void *getPyramidVertexArray(size_t *len)
{
    *len = pyramid_arrays.lenVertices;
    return pyramid_arrays.vertices;
}

void *getPyramidIndexArray(size_t *len)
{
    *len = pyramid_arrays.lenIndices;
    return pyramid_arrays.indices;
}

void *getPyramidNormalArray(size_t *len)
{
    *len = pyramid_arrays.lenNormals;
    return pyramid_arrays.normals;
}

void *getPyramidUVArray(size_t *len)
{
    *len = pyramid_arrays.lenUvs;
    return pyramid_arrays.uvs;
}

/*
 * Cube data get function implementations
 */
void *getCubeVertexArray(size_t *len)
{
    *len = cube_arrays.lenVertices;
    return cube_arrays.vertices;
}

void *getCubeIndexArray(size_t *len)
{
    *len = cube_arrays.lenIndices;
    return cube_arrays.indices;
}

void *getCubeNormalArray(size_t *len)
{
    *len = cube_arrays.lenNormals;
    return cube_arrays.normals;
}

void *getCubeUVArray(size_t *len)
{
    *len = cube_arrays.lenUvs;
    return cube_arrays.uvs;
}
