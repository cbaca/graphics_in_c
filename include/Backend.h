#ifndef BACKEND_H
#define BACKEND_H
#include <stdbool.h>


/*
enum KeyMask {
    KEY_NOT = 0x00,
    KEY_W = 0x01, KEY_S = 0x02,
    KEY_A = 0x04, KEY_D = 0x08,
    KEY_K = 0x10, KEY_J = 0x20,
    KEY_H = 0x40, KEY_L = 0x80,
    KEY_E = 0x0100, KEY_Q = 0x0200,
    KEY_SPACE = 0x0400,
    KEY_SHIFT = 0x0800
};
*/

typedef enum KeyType {
    NOKEY,
    KEY_A, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F,
    KEY_G, KEY_H, KEY_I, KEY_J, KEY_K, KEY_L,
    KEY_M, KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R,
    KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X,
    KEY_Y, KEY_Z,
    KEY_ESC,
    KEY_SPACE,
    KEY_LSHIFT,
    KEY_TOTAL
} KeyType;

typedef struct Mouse_t {
    float x, y;
} Mouse_t;

typedef struct Window_t {
    float w, h;
} Window_t;

bool eventGetKeyPress(KeyType key);
bool eventGetUpdated(void);
void eventGetMousePos(Mouse_t *m);
void eventGetWindowSize(Window_t *w);
float eventGetAspectRatio(void);

void eventSetKey(KeyType key, bool pushed);
void eventSetMousePos(const float x, const float y);
void eventSetWindowSize(const float x, const float y);

void eventUpdateLeftMouseClicked(void);
void eventUpdateLeftMouseReleased(void);

void backendSetCallback(void (*funcPtr)(void *), void *data, KeyType k);

void backendInit(void);
void backendExitFailure(void);
void backendHandleInputEvents(void);

void backendInit(void);

int backendExitSuccess(void);
double backendGetTime(void);
bool eventLoopExit(void);
void eventLoopTick(void);
bool eventDebugMode(void);
bool eventFocused(void);
#endif /* BACKEND_H */
