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
 *  [ pos ][front][right][  up ][world]
 *  0      3      6      9      12
 */

#   define x 0
#   define y 1
#   define z 2
void
player_init(float *restrict vec)
{
    vec[x] =  0.0f; // pos
    vec[y] =  0.0f;
    vec[z] =  0.0f;
    vec += 3;       // front
    vec[x] = (float)(cos(-WINDMILL_PI2) * cos(0));
    vec[y] = (float)sin(0);
    vec[z] = (float)(sin(-WINDMILL_PI2) * cos(0));
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
}

void    /* played_data */
player_update(float *restrict vec, double yaw, double pitch)
{
    vec += 3;
/*
 *  [posit][front][right][ up  ][world]
 *  -3     0      3      6      9
 */
    // front[x] = (float)(cos(yaw) * cos(pitch));
    // front[y] = (float)sin(pitch);
    // front[z] = (float)sin(yaw) * cos(pitch);
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
player_move(float *vec, int input, float vel)
{
/*
 *  [ pos ][front][right][ up  ][world]
 *  0      3      6      9      12
 */
    if (input & KEY_SHIFT) {
    }
    if (input & KEY_UP) {
        vec[x] += vec[3] * vel;
        vec[y] += vec[4] * vel;
        vec[z] += vec[5] * vel;
    }
    if (input & KEY_DOWN) {
        vec[x] -= vec[3] * vel;
        vec[y] -= vec[4] * vel;
        vec[z] -= vec[5] * vel;
    }
    if (input & KEY_RIGHT) {
        vec[x] += vec[6] * vel;
        vec[y] += vec[7] * vel;
        vec[z] += vec[8] * vel;
    }
    if (input & KEY_LEFT) {
        vec[x] -= vec[6] * vel;
        vec[y] -= vec[7] * vel;
        vec[z] -= vec[8] * vel;
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
/*
        int input = get_keys();
        if (input & KEY_SHIFT) {
        }
        if (input & KEY_UP) {
            cam.pos[x] += dcam;
            cam.pos[y] += dcam;
            cam.pos[z] += dcam;
        }
        if (input & KEY_DOWN) {
            cam.pos[x] -= dcam;
            cam.pos[y] -= dcam;
            cam.pos[z] -= dcam;
        }
        if (input & KEY_RIGHT) {
            cam.pos[x] += dcam;
            cam.pos[y] += dcam;
            cam.pos[z] += dcam;
        }
        if (input & KEY_LEFT) {
            float cross[3] = {
                  cam.eye[y] * cam.nec[z] - cam.eye[z] * cam.nec[y]
                , cam.eye[z] * cam.nec[x] - cam.eye[x] * cam.nec[z]
                , cam.eye[x] * cam.nec[y] - cam.eye[y] * cam.nec[x] };
            float rlen = 1.0f / (float)sqrt(
                  cross[x] * cross[x]
                + cross[y] * cross[y]
                + cross[z] * cross[z] );
            cam.pos[x] -= cross[x] * rlen * dcam;
            cam.pos[y] -= cross[y] * rlen * dcam;
            cam.pos[z] -= cross[z] * rlen * dcam;
        }
*/
