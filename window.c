/** window.c
 *  glfwようなものはここでやります。glfwと言えばGLFWwindowの変数を初期化、
 *  コールバック関数、キーボード入力など
 */

#include <GLFW/glfw3.h>
#include <stdio.h>

#define KEY_W 0x01 /** 上向きやで           */
#define KEY_A 0x02 /** 左向きヤビッシュ     */
#define KEY_S 0x04 /** 下向きじゃろ         */
#define KEY_D 0x08 /** 右向きに決まっとるべ */

#define NOT_KEY_W ~0x01
#define NOT_KEY_A ~0x02
#define NOT_KEY_S ~0x04
#define NOT_KEY_D ~0x08

/** フォーうアド宣言 */
// typedef struct _Keys_T _Keys_T;
// struct _Keys_T {
//     unsigned char w, a, s, d;
// };

/** 関数プロトタイプ宣言
*/
void _key_callback(GLFWwindow *, int, int, int, int);

/** グローバルwindow.cだけしかに使われない変数です */
static int _pressed_keys = 0;

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

    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_W) /** 上向き */
            _pressed_keys |= KEY_W;
        if (key == GLFW_KEY_A) /** 左向き */
            _pressed_keys |= KEY_A;
        if (key == GLFW_KEY_S) /** 下向き */
            _pressed_keys |= KEY_S;
        if (key == GLFW_KEY_D) /** 右向き */
            _pressed_keys |= KEY_D;
    } else if (action == GLFW_RELEASE) {
        if (key == GLFW_KEY_W) /** 上向き */
            _pressed_keys &= NOT_KEY_W;
        if (key == GLFW_KEY_A) /** 左向き */
            _pressed_keys &= NOT_KEY_A;
        if (key == GLFW_KEY_S) /** 下向き */
            _pressed_keys &= NOT_KEY_S;
        if (key == GLFW_KEY_D) /** 右向き */
            _pressed_keys &= NOT_KEY_D;
    }

    /* コンパイラ黙ってもらうためのとりあずいれとく */
    printf("scancode %d\n", scancode);
    printf("mode     %d\n", mode);
}

void
debug_print_keys()
{
    if (_pressed_keys & KEY_W)
        printf("UP!\n");
    if (_pressed_keys & KEY_A)
        printf("LEFT!\n");
    if (_pressed_keys & KEY_S)
        printf("DOWN!\n");
    if (_pressed_keys & KEY_D)
        printf("RIGHT!\n");
}
