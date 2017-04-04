/**
 * @file player.c
 * -----------------------------------------------------------------------------
 */
#include "player.h"
#include "input.h"
#include "mat4array.h"
#include "math_constants.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*  player data should look like ...
 *  0              16     19     22     25     28     31
 *  [ view matrix ][ pos ][front][right][tate ][world][data ]
 *                                                      angles, speed
 */

#define PITCH 0
#define YAW 1
#define VEL 2
#define X 0
#define Y 1
#define Z 2
#define VIEW_M 0
#define DATA 16
#define POS 19
#define FRONT 22
#define RIGHT 25
#define UP 28
#define WORLD 31

static struct player_iter_t _itr;
static float *restrict _view;

void player_init(void *player)
{
    _view = player;
    _itr.dat = (float *)player + DATA;
    _itr.pos = (float *)player + POS;
    _itr.frn = (float *)player + FRONT;
    _itr.yoko = (float *)player + RIGHT;
    _itr.tate = (float *)player + UP;
    _itr.wrld = (float *)player + WORLD;

    mat4array_set(_view, MAT4ARRAY_IDENTITY);
    _itr.dat[PITCH] = 0.0f;
    _itr.dat[YAW] = -HALF_PI;
    _itr.dat[VEL] = 5.0f;

    _itr.pos[X] =  0.0f;
    _itr.pos[Y] =  0.0f;
    _itr.pos[Z] =  10.0f;

    _itr.frn[X] = (float)(cos(_itr.dat[YAW]) * cos(_itr.dat[PITCH]));
    _itr.frn[Y] = (float)sin(_itr.dat[PITCH]);
    _itr.frn[Z] = (float)(sin(_itr.dat[YAW]) * cos(_itr.dat[PITCH]));

    _itr.yoko[X] =  0.0f;
    _itr.yoko[Y] =  0.0f;
    _itr.yoko[Z] =  0.0f;
    _itr.tate[X] =  0.0f;
    _itr.tate[Y] =  1.0f;
    _itr.tate[Z] =  0.0f;
    _itr.wrld[X] =  0.0f;
    _itr.wrld[Y] =  1.0f;
    _itr.wrld[Z] =  0.0f;
    normalizev3(_itr.frn);
    crossv3fst(_itr.yoko, _itr.frn, _itr.wrld);
    normalizev3(_itr.yoko);
    crossv3fst(_itr.tate, _itr.yoko, _itr.frn);
    normalizev3(_itr.tate);
}

void player_look(void)
{
    _itr.frn[X] = (float)(cos(_itr.dat[YAW]) * cos(_itr.dat[PITCH]));
    _itr.frn[Y] = (float)sin(_itr.dat[PITCH]);
    _itr.frn[Z] = (float)(sin(_itr.dat[YAW]) * cos(_itr.dat[PITCH]));
    normalizev3(_itr.frn);
    crossv3fst(_itr.yoko, _itr.frn, _itr.wrld);
    normalizev3(_itr.yoko);
    crossv3fst(_itr.tate, _itr.yoko, _itr.frn);
    normalizev3(_itr.tate);
}

void player_move(const int input, const float timeval)
{
    if (input & KEY_L)
        _itr.dat[YAW] += SIXTEENTH_PI / 45;
    if (input & KEY_H)
        _itr.dat[YAW] -= SIXTEENTH_PI / 45;
    if (input & KEY_K)
        _itr.dat[PITCH] += SIXTEENTH_PI / 45;
    if (input & KEY_J)
        _itr.dat[PITCH] -= SIXTEENTH_PI / 45;
    if (input & 0xf0/* 240 */) {
        if (_itr.dat[PITCH] > HALF_PI)
            _itr.dat[PITCH] = HALF_PI;
        if (_itr.dat[PITCH] < -HALF_PI)
            _itr.dat[PITCH] = -HALF_PI;
        player_look();
    }

    _itr.dat[VEL] = 5.0f * timeval;
    if (input & KEY_D) {            // 右移動
        _itr.pos[X] += _itr.yoko[X] * _itr.dat[VEL];
        _itr.pos[Y] += _itr.yoko[Y] * _itr.dat[VEL];
        _itr.pos[Z] += _itr.yoko[Z] * _itr.dat[VEL];
    }
    if (input & KEY_A) {            //左移動
        _itr.pos[X] -= _itr.yoko[X] * _itr.dat[VEL];
        _itr.pos[Y] -= _itr.yoko[Y] * _itr.dat[VEL];
        _itr.pos[Z] -= _itr.yoko[Z] * _itr.dat[VEL];
    }
    if (input & KEY_W) {            // まっすぐに移動
        _itr.pos[X] += _itr.frn[X] * _itr.dat[VEL];
        _itr.pos[Y] += _itr.frn[Y] * _itr.dat[VEL];
        _itr.pos[Z] += _itr.frn[Z] * _itr.dat[VEL];
    }
    if (input & KEY_S) {            // 後ろに移動
        _itr.pos[X] -= _itr.frn[X] * _itr.dat[VEL];
        _itr.pos[Y] -= _itr.frn[Y] * _itr.dat[VEL];
        _itr.pos[Z] -= _itr.frn[Z] * _itr.dat[VEL];
    }
}

void player_get_view(void)
{
    float pos_plus_front[3] = {
          _itr.pos[X] + _itr.frn[X]
        , _itr.pos[Y] + _itr.frn[Y]
        , _itr.pos[Z] + _itr.frn[Z]
    };
    mat4array_get_look_at(_view, _itr.pos, pos_plus_front, _itr.wrld);
}
