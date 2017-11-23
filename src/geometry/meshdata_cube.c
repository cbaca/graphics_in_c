#include "meshdata.h"
#include "array.h"
#include "vecmath.h"
#include <math.h>

void meshdata_generate_cube(meshdata_t *m)
{
    struct array _vertices, _vnormals, _indices, _uvs;

    struct array *vertices = &_vertices;
    struct array *vnormals = &_vnormals;
    struct array *indices = &_indices;
    struct array *uvs  = &_uvs;

    array_init(vertices, 72, sizeof(float));
    array_init(vnormals, 72, sizeof(float));
    array_init(indices, 36, sizeof(unsigned int));
    array_init(uvs, 48, sizeof(float));

    unsigned int indices_base[6] = { 0, 2, 1, 2, 3, 1 };
    unsigned int vid[6][4] = { { 3, 0, 2, 1 }, { 0, 4, 1, 5 }, { 2, 1, 6, 5 },
                               { 4, 7, 5, 6 }, { 7, 3, 6, 2 }, { 7, 4, 3, 0 } };
    float corner_verts[8][3] = {
        {  1.0f,  1.0f,  1.0f },
        {  1.0f, -1.0f,  1.0f },
        { -1.0f, -1.0f,  1.0f },
        { -1.0f,  1.0f,  1.0f },

        {  1.0f,  1.0f, -1.0f },
        {  1.0f, -1.0f, -1.0f },
        { -1.0f, -1.0f, -1.0f },
        { -1.0f,  1.0f, -1.0f }
    };

    float uvs_base[4][2] = {
        { 0.0f, 1.0f },
        { 1.0f, 1.0f },
        { 0.0f, 0.0f },
        { 1.0f, 0.0f }
    };

    size_t i;
    for (i = 0; i < 6; ++i) {

        size_t j;
        Vec3 v[4];

        array_push_back_x(indices, indices_base, 6);

        for (j = 0; j < 6; ++j)
            indices_base[j] += 4;

        for (j = 0; j < 4; j++) {

            v[j] = vec3construct(corner_verts[vid[i][j]][0], corner_verts[vid[i][j]][1], corner_verts[vid[i][j]][2]);

            array_push_back_x(vertices, &v[j], 3);
            array_push_back_x(uvs, uvs_base[j], 2);
        }

        Vec3 n0 = vec3copy(&v[0]);
        vec3normalVector(&n0, &v[1], &v[2]);
        vec3normalize(&n0);
        array_push_back_x(vnormals, &n0, 3);
        array_push_back_x(vnormals, &n0, 3);
        array_push_back_x(vnormals, &n0, 3);
        array_push_back_x(vnormals, &n0, 3);
    }

    m->vertices = vertices->load;
    m->normals = vnormals->load;
    m->indices = indices->load;
    m->uvs = uvs->load;
    m->lenVertices = vertices->cur_len;
    m->lenNormals = vnormals->cur_len;
    m->lenIndices = indices->cur_len;
    m->lenUvs = uvs->cur_len;
}
