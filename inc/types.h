#pragma once
#include "math_types.h"
#define null (void *)0
#define nil  (void *)0
typedef enum keytype_t {
    KEY_ERR,
    KEY_ESC, KEY_SPACE, KEY_LSHIFT,
    KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T, KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, // KEY_LBRACKET, KEY_RBRACKET,
    KEY_A, KEY_S, KEY_D, KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, // KEY_SEMICOL, KEY_APOST,
    KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B, KEY_N, KEY_M, // KEY_COMMA, KEY_DOT,
    KEY_TOTAL,
} keytype_t;

typedef enum keystate_t {
    up = 0,
    down = !up,
} keystate_t;

typedef enum bool_t {
    no  = 0,
    yes = !no,
} bool_t;

typedef struct cursor_t {
    float x;
    float y;
} Cursor;

typedef struct window_size_t {
    float w;
    float h;
    float ar; // aspect ratio
} WindowSize;
