/** input.c */

#include <GLFW/glfw3.h>
#include <stdio.h>
#include "key_macros.h"

/** キーボード入力格納 */
static int _pressed_keys = 0;
/* extern */ void _key_callback(
      GLFWwindow *
    , int
 /** 標準出力もコンパイラもどっちも黙ってくれないかな */
    , __attribute__ ((unused)) int
    , int
    , __attribute__ ((unused)) int
    );
/* extern */ int get_keys();

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
            case GLFW_KEY_Y:
                _pressed_keys |= KEY_Y;
                break;

            // ** 2次元では右へ向かう
            case GLFW_KEY_RIGHT:
                _pressed_keys |= KEY_RIGHT;
                break;
            case GLFW_KEY_L:
                _pressed_keys |= KEY_RIGHT;
                break;

            // ** 2次元では左へ向かう
            case GLFW_KEY_LEFT:
                _pressed_keys |= KEY_LEFT;
                break;
            case GLFW_KEY_H:
                _pressed_keys |= KEY_LEFT;
                break;

            // ** 2次元では下へ向かう
            case GLFW_KEY_DOWN:
                _pressed_keys |= KEY_DOWN;
                break;
            case GLFW_KEY_J:
                _pressed_keys |= KEY_DOWN;
                break;

            // ** 2次元では上へ向かう
            case GLFW_KEY_UP:
                _pressed_keys |= KEY_UP;
                break;
            case GLFW_KEY_K:
                _pressed_keys |= KEY_UP;
                break;

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
            case GLFW_KEY_Y:
                _pressed_keys &= ~KEY_Y;
                break;

            case GLFW_KEY_RIGHT:
                _pressed_keys &= ~KEY_RIGHT;
                break;
            case GLFW_KEY_L:
                _pressed_keys &= ~KEY_RIGHT;
                break;

            case GLFW_KEY_LEFT:
                _pressed_keys &= ~KEY_LEFT;
                break;
            case GLFW_KEY_H:
                _pressed_keys &= ~KEY_LEFT;
                break;

            case GLFW_KEY_DOWN:
                _pressed_keys &= ~KEY_DOWN;
                break;
            case GLFW_KEY_J:
                _pressed_keys &= ~KEY_DOWN;
                break;

            case GLFW_KEY_UP:
                _pressed_keys &= ~KEY_UP;
                break;
            case GLFW_KEY_K:
                _pressed_keys &= ~KEY_UP;
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

int
get_keys()
{
    return _pressed_keys;
}

void
debug_print_keys()
{
    if (_pressed_keys & KEY_SHIFT) {
        printf("SHIFT ");
        if (_pressed_keys & KEY_RIGHT)
            printf("RIGHT!\n");
        if (_pressed_keys & KEY_LEFT)
            printf("LEFT!\n");
        if (_pressed_keys & KEY_DOWN)
            printf("DOWN!\n");
        if (_pressed_keys & KEY_UP)
            printf("UP!\n");
    } else {
        if (_pressed_keys & KEY_W)
            printf("ほら！回ってるすげぇ！!\n");
        if (_pressed_keys & KEY_Y)
            printf("あれ・・建物自体動いてんじゃない？\n");
        if (_pressed_keys & KEY_RIGHT)
            printf("RIGHT!\n");
        if (_pressed_keys & KEY_LEFT)
            printf("LEFT!\n");
        if (_pressed_keys & KEY_DOWN)
            printf("DOWN!\n");
        if (_pressed_keys & KEY_UP)
            printf("UP!\n");
    }
}
