#include "meshdata.h"
#include "array.h"
#include "vecmath.h"
#include <math.h>

#define NUM_FACES 4

#define meshdata_uv_from_vertex(_uv, _v) /* float dest[2], Vec3 *src */ \
    _uv[0] = atan2f(_v.z, -_v.z) / 2.f / PI + 0.5f; \
    _uv[1] = (1.f - atan2f(-_v.y, sqrtf(_v.x * _v.x + _v.z * _v.z))) / PI + 0.5f;

void meshdata_generate_pyramid(meshdata_t *m)
{
    struct array
            _vertices, _vnormals, _indices, _uvs,
            _vfloor, _vfloorn;

    struct array *vertices = &_vertices,
                 *vnormals = &_vnormals,
                 *indices  =  &_indices,
                 *uvs      =      &_uvs,
                 *vfloor   =   &_vfloor,
                 *vfloorn  =  &_vfloorn;

    array_init(vertices,       48, sizeof(float));
    array_init(vnormals,       48, sizeof(float));
    array_init(indices, 18, sizeof(unsigned int));
    array_init(uvs,            18, sizeof(float));
    array_init(vfloor,         48, sizeof(float));
    array_init(vfloorn,        48, sizeof(float));

    const size_t ind[4][3]   = { { 1, 0, 1 }, { 1, 0, 0 }, { 0, 0, 0 }, { 0, 0, 1 } };
    const float  vi[2]       = { -1.0f, 1.0f };
    Vec3         nBottom     = { .x = 0.0f, .y = -1.0f, .z = 0.0f };
    unsigned int ind_base[3] = { 0, 1, 2 };

    size_t i;
    for (i = 0; i < NUM_FACES; ++i) {
        size_t j = i - 1;

        if (j >= NUM_FACES)
            j = NUM_FACES - 1;

        Vec3 t,  br,  bl,
            nt, nbr, nbl;

        t = nt = vec3_construct(0.f, 1.f, 0.f);
        br = nbr = vec3_construct(vi[ind[i][0]], vi[ind[i][1]], vi[ind[i][2]]);
        bl = nbl = vec3_construct(vi[ind[j][0]], vi[ind[j][1]], vi[ind[j][2]]);

        vec3_surface_normal_from_plane(&nt, &nbr, &nbl);

        array_push_back_x(vertices, &t, 3);
        array_push_back_x(vertices, &br, 3);
        array_push_back_x(vertices, &bl, 3);
        array_push_back_x(vfloor, &br, 3);

        array_push_back_x(vnormals,     &nt, 3);
        array_push_back_x(vnormals,    &nbr, 3);
        array_push_back_x(vnormals,    &nbl, 3);
        array_push_back_x(vfloorn, &nBottom, 3);

        float uvt[2];
        float uvbr[2];
        float uvbl[2];
        meshdata_uv_from_vertex(uvt, t);
        meshdata_uv_from_vertex(uvbr, br);
        meshdata_uv_from_vertex(uvbl, bl);

        array_push_back_x(uvs,  uvt, 2);
        array_push_back_x(uvs, uvbr, 2);
        array_push_back_x(uvs, uvbl, 2);

        array_push_back_x(indices, &ind_base, 3);
        ind_base[0] += 3;
        ind_base[1] += 3;
        ind_base[2] += 3;
    }

    array_concat(vertices, vfloor);
    array_concat(vnormals, vfloorn);
    array_push_back_x(indices, &ind_base, 3);
    ind_base[1]++;
    ind_base[2]++;
    array_push_back_x(indices, &ind_base, 3);
    array_finalize(vfloor);
    array_finalize(vfloorn);

    m->vertices = vertices->load;
    m->normals = vnormals->load;
    m->indices = indices->load;
    m->uvs = uvs->load;
    m->lenVertices = vertices->cur_len;
    m->lenNormals = vnormals->cur_len;
    m->lenIndices = indices->cur_len;
    m->lenUvs = uvs->cur_len;
}

