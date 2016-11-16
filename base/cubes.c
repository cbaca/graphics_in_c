/** @file objects.c */

/*  4 sails + 1 body = at least 5 objects */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../include/input.h"
#include "../include/mat4array.h"

/*  windmill data looks like:
 *  [  tower ][ sail1  ][ sail2  ][ sail3  ][ sail4  ]
 *  0         16        32        48        64       80
 */

enum {
      TOWER = 0x000
    , SAIL1 = 0x010
    , SAIL2 = 0x020
    , SAIL3 = 0x030
    , SAIL4 = 0x040
};

#   define NEXT 16
#   define x 0
#   define y 1
#   define z 2
#   define w 3
/* 風車（かざぐるま）つくれるかな */
void
windmill_init(float *windmill)
{

    // 風車の建物
    mat4array_set(windmill, MAT4ARRAY_IDENTITY);
    mat4array_scale(windmill, 1.0f, 1.5f, 1.0f);
    mat4array_translate(windmill, 0.0f, 0.0f, 0.0f);

    // 帆（ほ）sail 1
    //                太さ , 長さ, 厚さ
    float scl_v[3] = { 1.0f, 1.8f, 0.2f };
    //       rotate(sex, starfox, ballerina)
    float rot_v[3] = { 0.0f, 0.0f, 1.0f };
    //                 左右、飛んでみーな、ちかん
    float tranv[3] = { 0.0f, 1.2f, 0.5f };
    windmill += NEXT;
    mat4array_set(windmill, MAT4ARRAY_IDENTITY);
    mat4array_scalev3(windmill, scl_v);
    //                  no left/right, up, forward
    mat4array_translatev3(windmill, tranv);

    // sail 2
    windmill += NEXT;
    mat4array_set(windmill, MAT4ARRAY_IDENTITY);
    mat4array_scalev3(windmill, scl_v);
    mat4array_rotatev3(windmill, WINDMILL_PI2, rot_v);
    mat4array_translatev3(windmill, tranv);

    // sail 3
    windmill += NEXT;
    tranv[y] -= 0.5f;
    mat4array_set(windmill, MAT4ARRAY_IDENTITY);
    mat4array_scalev3(windmill, scl_v);
    // mat4array_rotatev3(windmill, WINDMILL_PI, rot_v);
    mat4array_translatev3(windmill, tranv);

    // sail 4
    windmill += NEXT;
    mat4array_set(windmill, MAT4ARRAY_IDENTITY);
    mat4array_scalev3(windmill, scl_v);
    mat4array_rotatev3(windmill, WINDMILL_PI2, rot_v);
    mat4array_translatev3(windmill, tranv);

}

/*  cubes data
 *  [ cube1  ][ cube2  ]
 *  0         16
 */
void
cubes_init(float *cubes)
{
    // body
    mat4array_set(cubes, MAT4ARRAY_IDENTITY);
    mat4array_scale(cubes, 1.0, 10.0, 1.0);

    // float scl_v[3] = { 1.0f, 1.8f, 0.2f };
    //       rotate(sex, starfox, ballerina)
    // float rot_v[3] = { 0.0f, 0.0f, 1.0f };
    //                 左右、飛んでみーな、ちかん
    // float tranv[3] = { 0.0f, 1.2f, 0.5f };
    // sail 1
    float trn[3] = { -5.0f, 0.0f, 0.0f };
    float scl[3] = {  0.5f, 7.5f, 0.2f };
    cubes += NEXT;
    mat4array_set(cubes, MAT4ARRAY_IDENTITY);
    mat4array_scalev3(cubes, scl);
    mat4array_translatev3(cubes, trn);

    // sail 2
    cubes += NEXT;
    trn[x] += 3.0f;
    mat4array_set(cubes, MAT4ARRAY_IDENTITY);
    mat4array_translatev3(cubes, trn);

    // sail 3
    cubes += NEXT;
    trn[x] += 4.0f;
    mat4array_set(cubes, MAT4ARRAY_IDENTITY);
    mat4array_translatev3(cubes, trn);

    // sail 4
    cubes += NEXT;
    trn[x] += 3.0f;
    mat4array_set(cubes, MAT4ARRAY_IDENTITY);
    mat4array_translatev3(cubes, trn);
}

void
animate_cubes(float *cubes)
{
    float trn[3] = { 0.0f, 0.0f, 0.0f };
    // const float time_scl = (float)(glfwGetTime() * WINDMILL_PI4 / 4);
    // mat4array_rotate(cubes, time_scl, 1.0f, 1.0f, 0.0f);
    cubes += NEXT;
    mat4array_translatev3(cubes, trn);

    // const float scalex = 1.0f;
    // const float scaley = 0.08f;
    // const float scalez = 1.0f;
    // mat4array_scale(cubes + NEXT, scalex, scaley, scalez);
    // mat4array_rotate(cubes + NEXT, time_scl, 1.0f, 1.0f, 0.0f);
    // mat4array_translate(cubes + NEXT, -1.3f, 1.3f, 0.0f);
}

void
draw_cubes(int model_fd, float *cubes, int len)
{
    int i = 0;
    for (; i < len; ++i) {
        glUniformMatrix4fv(model_fd, 1, GL_FALSE, cubes);
        glDrawArrays(GL_TRIANGLES, 0, 36);
        cubes += NEXT;
    }
}

void
get_projection(float *proj)
{
    mat4array_get_perspective(
        proj, WINDMILL_PI2, 4.0f / 3.0f, 0.1f, 100.0f);
}
#undef NEXT
#undef x
#undef y
#undef z
#undef w 
