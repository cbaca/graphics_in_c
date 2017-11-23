#ifndef TYPES_H
#define TYPES_H

#include <stdlib.h>
#include "math_types.h"

#define null ((void *)0)
#define nil  ((void *)0)

#define byte unsigned char
#define s8   char
#define u8   unsigned char
#define s32  int
#define u32  unsigned int
#define s64  long int
#define u64  unsigned long int

#define U8_MAX  ((u8)~0U)
#define S8_MAX  ((s8)(U8_MAX>>1))
#define S8_MIN  ((s8)(-S8_MAX-1))
#define U32_MAX ((u32)~0U)
#define S32_MAX ((s32)(U32_MAX>>1))
#define S32_MIN ((s32)(-S32_MAX-1))
#define U64_MAX ((u64)~0ULL)
#define S64_MAX ((s64)(U64_MAX>>1))
#define S64_MIN ((s64)(-S64_MAX-1))

#define swap(a, b) \
    do { \
        __auto_type _a = (a); (a) = (b); (b) = _a; \
    } while(0)

// #define _RET_IP_ (unsigned long)__builtin_return_address(0)
// #define _THIS_IP_ ({ __label__ __here; __here: (unsigned long)&&__here; })

#define container_of(ptr, type, member) \
({ \
    void __mptr = (void *)(ptr); \
    /* Make sure the pointer types are the same \
    assert(!__same_type(*(ptr), ((type *)0)->member) && !__same_type(*(ptr), void)); */ \
    ((type *)(__mptr - offsetof(type, member))); \
})

#define upper_32_bits(n) ((u32)(((n) >> 16) >> 16))
#define lower_32_bits(n) ((u32)(n))

typedef enum keytype_t {

    KEY_ERR,

    KEY_ESC, KEY_SPACE, KEY_LSHIFT,

    /* Number keys */
    KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
    KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,

    /* Top row */
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T,
    KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, // KEY_LBRACKET, KEY_RBRACKET,

    /* Middle row */
    KEY_A, KEY_S, KEY_D, KEY_F, KEY_G,
    KEY_H, KEY_J, KEY_K, KEY_L, // KEY_SEMICOL, KEY_APOST,

    /* Bottom row */
    KEY_Z, KEY_X, KEY_C, KEY_V, KEY_B,
    KEY_N, KEY_M, // KEY_COMMA, KEY_DOT,

    KEY_TOTAL,

} keytype_t;

struct array {
    size_t max_len;
    size_t cur_len;
    size_t data_size;
    void *load;
};

struct node {
    struct node *next;
    struct node *prev;
};

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

#endif /* TYPES_H */
