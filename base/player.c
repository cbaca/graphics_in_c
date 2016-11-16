/* player.c */
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

/*  player's data array should look like this
 *  [pos][frt][rgt][up ][wrd][Θ][...
 *  0    3    6    9    12   15 16
 */

#   define x 0
#   define y 1
#   define z 2
void
player_init(float *restrict view, float *restrict vec)
{
    vec[x] =  0.0f; // pos
    vec[y] =  0.0f;
    vec[z] =  10.0f;
    vec += 3;       // front
    vec[x] = (float)(cos(-90.0f / 180.0f * WINDMILL_PI) * cos(0.0f));
    vec[y] = (float)sin(0.0f);
    vec[z] = (float)(sin(-90.0f / 180.0f * WINDMILL_PI) * cos(0.0f));
    normalizev3(vec);
    vec += 3;       // right
    vec[x] =  0.0f;
    vec[y] =  0.0f;
    vec[z] =  0.0f;
    vec += 3;       // up
    vec[x] =  0.0f;
    vec[y] =  1.0f;
    vec[z] =  0.0f;
    vec += 3;       // world up
    vec[x] =  0.0f;
    vec[y] =  1.0f;
    vec[z] =  0.0f;
    vec -= 9;
    // crossv3fst(right, front, world_up);
    crossv3fst(vec+3, vec, vec+9);
    // normalizev3(right);
    normalizev3(vec+3);
    // crossv3fst(up, right, front);
    crossv3fst(vec+6, vec+3, vec);
    // normalizev3(up);
    vec += 6;
    normalizev3(vec);
    mat4array_set(view, MAT4ARRAY_IDENTITY);
}

void    /* played_data */
player_update(float *restrict vec, double yaw, double pitch)
{
/*
 *  [posit][front][right][ up  ][world]
 *  -3     0      3      6      9
 */
    vec[x] = (float)(cos(yaw) * cos(pitch));
    vec[y] = (float)sin(pitch);
    vec[z] = (float)(sin(yaw) * cos(pitch));
    normalizev3(vec);
    // crossv3fst(right, front, world_up);
    crossv3fst(vec+3, vec, vec+9);
    // normalizev3(right);
    normalizev3(vec+3);
    // crossv3fst(up, right, front);
    crossv3fst(vec+6, vec+3, vec);
    // normalizev3(up);
    normalizev3(vec+6);
}

void
player_move(float *vec, int input, float vel, double *yaw, double *pitch)
{
/*
 *  [ pos ][front][right][ up  ][world]
 *  0      3      6      9      12
 */
    if (input & KEY_L)
        *yaw += WINDMILL_PI6 / 45; // 左に向かう
    if (input & KEY_H)
        *yaw -= WINDMILL_PI6 / 45; // 右に向かう
    if (input & KEY_K)
        *pitch += WINDMILL_PI6 / 45; // 上に向かう
    if (input & KEY_J)
        *pitch -= WINDMILL_PI6 / 45; // 下に向かう
    if (input | 240)
        player_update(vec + 3, *yaw, *pitch);
    if (input & KEY_D) {            // 左移動
        vec[x] += vec[6] * vel;
        vec[y] += vec[7] * vel;
        vec[z] += vec[8] * vel;
    }
    if (input & KEY_A) {            //右移動
        vec[x] -= vec[6] * vel;
        vec[y] -= vec[7] * vel;
        vec[z] -= vec[8] * vel;
    }
    if (input & KEY_W) {            // まっすぐに移動
        vec[x] += vec[3] * vel;
        vec[y] += vec[4] * vel;
        vec[z] += vec[5] * vel;
    }
    if (input & KEY_S) {            // 後ろに移動 
        vec[x] -= vec[3] * vel;
        vec[y] -= vec[4] * vel;
        vec[z] -= vec[5] * vel;
    }
    if (input & KEY_SHIFT) {
        if (input & KEY_W) { // fly
        }
        if (input & KEY_S) { // sink
        }
    }
}

void
player_get_view(float *restrict view, float *restrict vec)
{
    // pos + front
    float pos_plus_front[3] = {
        vec[x] + vec[3], vec[y] + vec[4], vec[z] + vec[5]
    };
    mat4array_get_look_at(view, vec, pos_plus_front, vec+9);
}

#   undef x
#   undef y
#   undef z
