/**
 * @file input.h
 * -----------------------------------------------------------------------------
 */
#ifndef WINDMILL_INPUT_H_
#define WINDMILL_INPUT_H_
#include "key_macros.h"
struct GLFWwindow;
int get_keys();
void key_callback(
    struct GLFWwindow *win,
    int key,
    __attribute__((unused)) int scancode,
    int action,
    __attribute__((unused)) int mode);
#endif /* WINDMILL_INPUT_H_ */
