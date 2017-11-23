#include "meshdata.h"

#define QUAD_VERTEX_ARRAY_LEN 12
#define QUAD_NORMAL_ARRAY_LEN 12
#define QUAD_UV_ARRAY_LEN 8
#define QUAD_INDEX_ARRAY_LEN 6

float quad_vertex_array[QUAD_VERTEX_ARRAY_LEN] = {
    -1.f, -1.f, 0.f,
     1.f, -1.f, 0.f,
    -1.f,  1.f, 0.f,
     1.f,  1.f, 0.f
};

float quad_normal_array[QUAD_NORMAL_ARRAY_LEN] = {
    0.f, 0.f, -1.f,
    0.f, 0.f, -1.f,
    0.f, 0.f, -1.f,
    0.f, 0.f, -1.f
};

float quad_uv_array[QUAD_UV_ARRAY_LEN] = {
    0.f, 1.f,
    0.f, 0.f,
    1.f, 1.f,
    1.f, 0.f
};

unsigned int quad_index_array[QUAD_INDEX_ARRAY_LEN] = {
    0, 1, 2, 1, 2, 3
};

void meshdata_generate_quad(struct meshdata *m)
{
    m->vertices = quad_vertex_array;
    m->vnormals = nil;
    m->fnormals = quad_normal_array;
    m->uvs = quad_uv_array;
    m->indices = quad_index_array;

    m->v_len = QUAD_VERTEX_ARRAY_LEN;
    m->vn_len = 0;
    m->fn_len = QUAD_NORMAL_ARRAY_LEN;
    m->uv_len = QUAD_UV_ARRAY_LEN;
    m->i_len = QUAD_INDEX_ARRAY_LEN;
}

/*
void meshdata_generate_quad_facing(struct meshdata *m, Vec3 *fn)
{
    struct array _vertices, _fnormals, _indices, _uvs;
    struct array *vertices = &_vertices,
                 *fnormals = &_fnormals,
                 *indices  =  &_indices,
                 *uvs      =      &_uvs;

    array_init(vertices, 12,        sizeof(float));
    array_init(fnormals, 12,        sizeof(float));
    array_init(indices ,  6, sizeof(unsigned int));
    array_init(uvs     ,  8,        sizeof(float));
}
*/
