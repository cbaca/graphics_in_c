#include "meshdata.h"
#include "array.h"
#include "vecmath.h"
#include <math.h>

void meshdata_generate_sphere(meshdata_t *m)
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

    long int v_slices = 32;
    long int h_slices = 32;
    long int i, j;
    float theta_inc = 180.f / (float)v_slices;
    float phi_inc = 360.f / (float)h_slices;
    float radius = 1.f;

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
            ver = nor = (Vec3){ .x = cosf(phi) * rsthe, .y = radius * cosf(the), .z = sinf(phi) * rsthe };
            array_push_back_x(vertices, &ver, 3);

            vec3normalize(&nor);
            array_push_back_x(vnormals, &nor, 3);

            float uv[2] = { phi, 1.f - the };
            array_push_back_x(uvs, uv, 2);

            *(iptr + i) = ind_cnt++;
        }
        iptr += h_slices + 1;
    }

    iptr = ind;
    long int h_len = h_slices + 1;
    for (j = 0; j < v_slices; ++j) {
        for (i = 0; i < h_slices; ++i) {
            unsigned int a = iptr[i + 1];
            unsigned int b = iptr[i];
            unsigned int c = (iptr + h_len)[i];
            unsigned int d = (iptr + h_len)[i + 1];
            unsigned int in[2][3] = { { a, b, d }, { b, c, d } };
            if (j != 0)
                array_push_back_x(indices, in[0], 3);
            if (j != h_len)
                array_push_back_x(indices, in[1], 3);
        }
        iptr += h_len;
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
