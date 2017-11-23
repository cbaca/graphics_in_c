#ifndef MESHDATA_H
#define MESHDATA_H
#include "types.h"

/*
 * TODO:
 */
struct meshdata {

   float *vertices,
         *vnormals,
         *fnormals,
         *uvs;

   unsigned int *indices;

   size_t v_len,
         vn_len,
         fn_len,
         uv_len,
          i_len;
};
/*
 * typedef struct meshdata meshdata_t;
 */


typedef struct meshdata_t {
    float *vertices;
    float *normals;
    unsigned int *indices;
    float *uvs;
    size_t lenVertices;
    size_t lenNormals;
    size_t lenIndices;
    size_t lenUvs;
} meshdata_t;

/*---------------------------------------------------------
            meshdata.c
 --------------------------------------------------------*/
/**
 * meshdata_arrays_init
 */
void meshdata_arrays_init(const char *dirpath);

/**
 * meshdata_arrays_finalize
 */
void meshdata_arrays_finalize(void);

/**
 * meshdata_destroy
 */
void meshdata_destroy(meshdata_t *m);

/**
 * meshdata_print
 */
void meshdata_print(meshdata_t *m);

/**
 * getSphereVertexArray
 */
void *getSphereVertexArray(size_t *len) __attribute__ ((pure));

/**
 * getSphereNormalArray
 */
void *getSphereNormalArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getSphereIndexArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getSphereUVArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getPyramidVertexArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getPyramidNormalArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getPyramidIndexArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getPyramidUVArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getCubeVertexArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getCubeNormalArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getCubeIndexArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *getCubeUVArray(size_t *len) __attribute__ ((pure));

/**
 *
 */
void *get_quad_vertex_array(size_t *len);

/**
 *
 */
void *get_quad_normal_array(size_t *len);

/**
 *
 */
void *get_quad_uv_array(size_t *len);

/**
 *
 */
void *get_quad_index_array(size_t *len);

/*---------------------------------------------------------
            meshdata_quad.c
 --------------------------------------------------------*/

/**
 *
 */
void meshdata_generate_quad(struct meshdata *m);

/*---------------------------------------------------------
            meshdata_sphere.c
 --------------------------------------------------------*/

/**
 *
 */
void meshdata_generate_sphere(meshdata_t *m);

/**********************************************************
 * meshdata_cube.c
 *********************************************************/
/**
 *
 */
void meshdata_generate_cube(meshdata_t *m);

/**********************************************************
 * meshdata_pyramid.c
 *********************************************************/
/**
 *
 */
void meshdata_generate_pyramid(meshdata_t *m);

/**********************************************************
 * meshdata_wavefront.c
 *********************************************************/

/**
 * meshdata_from_wavefront
 */
meshdata_t *meshdata_from_wavefront(const char *path, meshdata_t *meshdata);

/**
 * wavefront_files_init
 */
void wavefront_files_init(const char *dirpath);

/**
 * wavefront_files_finalize
 */
void wavefront_files_finalize(void);

/**
 * wavefront_filepath_search
 */
char *wavefront_filepath_search(const char *name);

/**
 * wavefront_filepath_from_index
 */
char *wavefront_filepath_from_index(size_t index);

/**
 * wavefront_filepath_len
 */
size_t wavefront_filepath_len(void);

/**
 * wavefront_paths_print
 */
void wavefront_paths_print(void);


// void meshdata_uv_from_vertex(float dest[2], Vec3 *src);
#endif /* MESHDATA_H */
