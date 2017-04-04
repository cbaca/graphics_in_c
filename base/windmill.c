/** @file objects.c */

/*  4 sails + 1 body = at least 5 objects */

#include "windmill.h"
#include "polygon.h"
#include "math_constants.h"
#include "input.h"
#include "mat4array.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define X 0
#define Y 1
#define Z 2
#define NUM_CUBES 5
#define NEXT_CUBE 16
#define SCALE 3
#define NEXT_VEC 6
#define SAIL_VEC1 6
#define SAIL_VEC2 12
#define SAIL_VEC3 18
#define SAIL_VEC4 24
#define BODY 0x00
#define SAIL1 0x10
#define SAIL2 0x20
#define SAIL3 0x30
#define SAIL4 0x40
#define SAILEND 0x41
#define ROLL 32
#define YAW 31
#define PITCH 30

/*  matrix data looks like:
 *  [  tower ][ sail1  ][ sail2  ][ sail3  ][ sail4  ]
 *  0         16        32        48        64        80
 *  vector data looks like:
 *  [ trans ][ scale ]
 *  0        3        6
 *  angles data looks like:
 *  [ x axis ][ y axis  ][ z axis ]
 *  0         1          2
 */

static float *restrict _cube_itr;
static float *restrict _vec_itr;
void windmill_init(float *restrict cubes, float *restrict vecs,
    float *restrict angles)
{
    _cube_itr = cubes;
    _vec_itr  = vecs;
    /* init matrices */
    mat4array_set(_cube_itr + BODY, MAT4ARRAY_IDENTITY);
    mat4array_set(_cube_itr + SAIL1, MAT4ARRAY_IDENTITY);
    mat4array_set(_cube_itr + SAIL2, MAT4ARRAY_IDENTITY);
    mat4array_set(_cube_itr + SAIL3, MAT4ARRAY_IDENTITY);
    mat4array_set(_cube_itr + SAIL4, MAT4ARRAY_IDENTITY);

    float *vec1 = _vec_itr + SAIL_VEC1;
    float *vec2 = _vec_itr + SAIL_VEC2;
    float *vec3 = _vec_itr + SAIL_VEC3;
    float *vec4 = _vec_itr + SAIL_VEC4;

    /* init transformation vecs */
    // body trans vec
    _vec_itr[X] = 0.0f; _vec_itr[Y] = 0.0f; _vec_itr[Z] = -2.0f;
    _vec_itr[3] = 2.0f; _vec_itr[4] = 40.0f; _vec_itr[5] = 2.0f;

    vec1[X] = -10.0f; vec1[Y] = 0.0f; vec1[Z] = 0.0f;
    vec1[3] = 20.0f; vec1[4] = 2.0f; vec1[5] = 0.2f;
    vec2[X] = 0.0f; vec2[Y] = -10.0f; vec2[Z] = 0.0f;
    vec2[3] = 2.0f; vec2[4] = 20.0f; vec2[5] = 0.2f;
    vec3[X] = 10.0f; vec3[Y] = 0.0f; vec3[Z] = 0.0f;
    vec3[3] = 20.0f; vec3[4] = 2.0f; vec3[5] = 0.2f;
    vec4[X] = 0.0f; vec4[Y] = 10.0f; vec4[Z] = 0.0f;
    vec4[3] = 2.0f; vec4[4] = 20.0f; vec4[5] = 0.2f;
    // _vec_itr -= NEXT_VEC * 4;

    angles[X] = 0.03159f;
    angles[Y] = 0.03159f;
    angles[Z] = 0.03159f;

    // bodyの座標変換
    mat4array_get_translationv3(_cube_itr, _vec_itr);
    mat4array_scalev3(_cube_itr, &_vec_itr[3]);

    // 帆の座標変換
    int i = SAIL1, j = SAIL_VEC1;
    for (; i < SAILEND; i += NEXT_CUBE, j += NEXT_VEC) {
        mat4array_get_rotation(&_cube_itr[i], angles[Z], MAT4ARRAY_ROLL);
        mat4array_translatev3(&_cube_itr[i], &_vec_itr[j]);
        mat4array_scalev3(&_cube_itr[i], &_vec_itr[j + SCALE]);
    }
}

void animate_cubes(int input)
{
    // BODY
    if (input & KEY_E) {
        _vec_itr[YAW] += 0.03159f;
        if (_vec_itr[YAW] >= WINDMILL_TAU)
            _vec_itr[YAW] = 0.0f;
        mat4array_get_translationv3(_cube_itr, _vec_itr);
        mat4array_rotate(_cube_itr, _vec_itr[YAW], 0.0f, 1.0f, 0.0f);
        mat4array_scalev3(_cube_itr, &_vec_itr[SCALE]);
        int i = SAIL1, j = SAIL_VEC1;
        for (; i < SAILEND; i += NEXT_CUBE, j += NEXT_VEC) {
            _vec_itr[j + 2] = _vec_itr[2];
            mat4array_get_rotation(&_cube_itr[i], _vec_itr[YAW], MAT4ARRAY_YAW);
            mat4array_rotate(&_cube_itr[i], _vec_itr[ROLL], 0.0f, 0.0f, 1.0f);
            mat4array_translatev3(&_cube_itr[i], &_vec_itr[j]);
            mat4array_scalev3(&_cube_itr[i], &_vec_itr[j + SCALE]);
        }
    }
    if (input & KEY_Q) {
        _vec_itr[ROLL] += 0.03159f;
        if (_vec_itr[ROLL] >= WINDMILL_TAU)
            _vec_itr[ROLL] = 0.0f;
        int i = SAIL1, j = SAIL_VEC1;
        for (; i < SAILEND; i += NEXT_CUBE, j += NEXT_VEC) {
            mat4array_get_rotation(&_cube_itr[i], _vec_itr[YAW], MAT4ARRAY_YAW);
            mat4array_rotate(&_cube_itr[i], _vec_itr[ROLL], 0.0f, 0.0f, 1.0f);
            mat4array_translatev3(&_cube_itr[i], &_vec_itr[j]);
            mat4array_scalev3(&_cube_itr[i], &_vec_itr[j + SCALE]);
        }
    }
}

void
draw_objects36(int model_fd, float *restrict objs, int len, int stride)
{
    int i = 0;
    for (; i < len; ++i) {
        glUniformMatrix4fv(model_fd, 1, GL_FALSE, objs);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        objs += stride;
    }
}
