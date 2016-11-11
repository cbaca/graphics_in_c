/** window.c
 *  glfwようなものはここでやります。glfwと言えばGLFWwindowの変数を初期化、
 *  コールバック関数、キーボード入力を格納（かくのう）など
 */

#include <GLFW/glfw3.h>
#include <stdio.h>
#include "keys.h"

/** プロトタイプやグローバル宣言 */
static int _pressed_keys = 0; /** キーボード入力格納 */

void _key_callback(GLFWwindow *, int, int, int, int);
int get_keys();

/** もともとglfw_initだった
 *  @引数w ウィンドの横サイズのピクセル量
 *  @引数h ウィンドの縦サイズのピクセル量
 *  @戻り値（もどりち）初期化されているGLFWwindowのポインター変数
 */
void *
window_init(int w, int h)
{
    GLFWwindow *window = NULL;

    /** glfw初期化 */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /** glfw window初期化 */
    window = glfwCreateWindow(
        //  WINDOW_WIDTH, WINDOW_HEIGHT
          w, h
        , "Windmill hell yeah we got it from window.c"
        , NULL, NULL
    );
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    /** キー押されたばい_key_callback関数は呼ばれます */
    glfwSetKeyCallback(window, _key_callback);

    return window;
}

void
_key_callback(
      GLFWwindow *win
    , int key
    , int scancode
    , int action
    , int mode
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
            case GLFW_KEY_RIGHT:
                _pressed_keys |= KEY_RIGHT;
                break;
            case GLFW_KEY_LEFT:
                _pressed_keys |= KEY_LEFT;
                break;
            case GLFW_KEY_DOWN:
                _pressed_keys |= KEY_DOWN;
                break;
            case GLFW_KEY_UP:
                _pressed_keys |= KEY_UP;
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
            case GLFW_KEY_LEFT:
                _pressed_keys &= ~KEY_LEFT;
                break;
            case GLFW_KEY_DOWN:
                _pressed_keys &= ~KEY_DOWN;
                break;
            case GLFW_KEY_UP:
                _pressed_keys &= ~KEY_UP;
                break;
            default:
                break;
        }
    }

    /* コンパイラ黙ってもらうためのとりあずいれとく */
    printf("scancode %d\n", scancode);
    printf("mode     %d\n", mode);
}

int
get_keys()
{
    return _pressed_keys;
}

void
debug_print_keys()
{
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
