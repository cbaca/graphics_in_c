/** input.c */

#include <GLFW/glfw3.h>
#include <stdio.h>
#include "key_macros.h"

/** キーボード入力格納 */
static int _pressed_keys = 0;
// static double _mousex = 0;
// static double _mousey = 0;

// void _scoll_collback(GLFWwindow *win, double xoff, double yoff) { }
// void
// _mouse_callback(__attribute__ ((unused)) GLFWwindow *win, double x, double y)
// {
//     static int _begin = 0;
//     static double lastX = 0.0;
//     static double lastY = 0.0;
//     if (!_begin)
//         _begin = 1;
//     _mousex = x - lastX;
//     _mousey = lastY - y;
//     lastX = x;
//     lastY = y;
// }

int
get_keys()
{
    return _pressed_keys;
}

void
_key_callback(
      GLFWwindow *win
    , int key
    , __attribute__ ((unused)) int scancode
    , int action
    , __attribute__ ((unused)) int mode
)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GL_TRUE);

    /** キーの機能がこうならなきゃならん：
     *  Wキーは風車（かざぐるま）回転スイッチ切り替え
     *  Yキーは風車自体をピッチ周り回転
     *  左右向きキーがヴィーウをピッチに（Y回転軸ね。忘れっちゃダメだよ）
     *  上下向きキーがプレーヤーを今向いてる目せんを前後通らせる
     *      子供でも簡単に楽しく出来るように作りなさい
     *
     *  他はperspective projectionを絶対に実装（じっそう）しないと
     *      1. viewing volume encompasses plane
     *      2. start with orthographic projection while doing
     *         modeling and viewing
     *      3. enable HIDDEN SURFACE REMOVAL and CLEAR DEPTH BUFFER
     */

    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_W:
                _pressed_keys |= KEY_W;
                break;

            case GLFW_KEY_A:
                _pressed_keys |= KEY_A;
                break;

            case GLFW_KEY_S:
                _pressed_keys |= KEY_S;
                break;

            case GLFW_KEY_D:
                _pressed_keys |= KEY_D;
                break;

            case GLFW_KEY_K:
                _pressed_keys |= KEY_K;
                break;

            case GLFW_KEY_J:
                _pressed_keys |= KEY_J;
                break;

            case GLFW_KEY_H:
                _pressed_keys |= KEY_H;
                break;

            case GLFW_KEY_L:
                _pressed_keys |= KEY_L;
                break;

            case GLFW_KEY_SPACE:
                _pressed_keys |= KEY_SPACE;

            case GLFW_KEY_LEFT_SHIFT:
                _pressed_keys |= KEY_SHIFT;
                break;

            case GLFW_KEY_RIGHT_SHIFT:
                _pressed_keys |= KEY_SHIFT;
                break;

            default:
                break;
        }
    } else if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_W:
                _pressed_keys &= ~KEY_W;
                break;

            case GLFW_KEY_A:
                _pressed_keys &= ~KEY_A;
                break;

            case GLFW_KEY_S:
                _pressed_keys &= ~KEY_S;
                break;

            case GLFW_KEY_D:
                _pressed_keys &= ~KEY_D;
                break;

            case GLFW_KEY_K:
                _pressed_keys &= ~KEY_K;
                break;

            case GLFW_KEY_J:
                _pressed_keys &= ~KEY_J;
                break;

            case GLFW_KEY_H:
                _pressed_keys &= ~KEY_H;
                break;

            case GLFW_KEY_L:
                _pressed_keys &= ~KEY_L;
                break;

            case GLFW_KEY_SPACE:
                _pressed_keys &= ~KEY_SPACE;
                break;

            case GLFW_KEY_LEFT_SHIFT:
                _pressed_keys &= ~KEY_SHIFT;
                break;
            case GLFW_KEY_RIGHT_SHIFT:
                _pressed_keys &= ~KEY_SHIFT;
                break;

            default:
                break;
        }
    }
}
