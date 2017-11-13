#include "backend.h"
#include "meshdata.h"
#include "texture.h"
#include "shaderdata.h"
#include <stdlib.h>
#include <stdio.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#define DEFAULT_WINDOW_WIDTH 960
#define DEFAULT_WINDOW_HEIGHT 540
#define MESHDATA_ROOT_DIR "resources/meshdata"
#define TEXTURES_ROOT_DIR "resources/textures"
#define SHADERS_ROOT_DIR "shaders"

/**
 * Global variables
 */
static struct window_state_t {
    GLFWwindow *glfwWindow;

    struct cursor_t cursor;
    struct cursor_t click;
    struct cursor_t release;
    struct window_size_t window_size;

    bool_t debug_mode;
    bool_t needs_update;
    bool_t focused;

    keystate_t keypresses[KEY_TOTAL];

} State;

static struct window_callback_t {

    size_t onkey_count;
    keytype_t onkey_array[KEY_TOTAL];
    void (*onkey_funcs[KEY_TOTAL])(void *);
    void *onkey_param_data[KEY_TOTAL];

} Callbacks;

// Local function declarations
static void _print_glfw_version(void);
static void _set_glfw_hints(void);
static void _set_glfw_callbacks(void);
static void _keydown_callback(GLFWwindow *w, int key, int scancode, int action, int mode);
static void _framebuffer_size_callback(GLFWwindow *w, int width, int height);
static void _cursor_callback(__attribute__ ((unused)) GLFWwindow *w, double xpos, double ypos);
static void _mousebutton_callback(GLFWwindow *w, int button, int action, __attribute__ ((unused)) int mod);
static void _geterror_callback(int error, const char *msg);

// Function definitions
static void _print_glfw_version(void)
{
    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);
    printf("GLFW %d.%d.%d initialized\n", major, minor, rev);
}

static void _set_glfw_hints(void)
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_DECORATED, GLFW_TRUE);
    glfwWindowHint(GLFW_FOCUSED, GL_FALSE);

    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_ALPHA_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_SAMPLES, 4);
}


static void _set_glfw_callbacks(void)
{
    glfwSetKeyCallback(State.glfwWindow,              _keydown_callback);
    glfwSetFramebufferSizeCallback(State.glfwWindow,  _framebuffer_size_callback);
    glfwSetCursorPosCallback(State.glfwWindow,        _cursor_callback);
    glfwSetMouseButtonCallback(State.glfwWindow,      _mousebutton_callback);

    // glfwSetCursorEnterCallback(glfwWindow,        cursorEnterCallback);
    // glfwSetWindowCloseCallback(glfwWindow, windowCloseCallback);
    // glfwSetWindowFocusCallback(glfwWindow, windowFocusCallback);
    // glfwSetWindowRefreshCallback(glfwWindow, windowRefreshCallback);
}

static void _keydown_callback(
    __attribute__ ((unused)) GLFWwindow *w,
                             int key,
    __attribute__ ((unused)) int scancode,
                             int action,
    __attribute__ ((unused)) int mode)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        State.debug_mode = !State.debug_mode;
    State.needs_update = yes;
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_1: State.keypresses[KEY_1] = down; break; case GLFW_KEY_2: State.keypresses[KEY_2] = down; break;
            case GLFW_KEY_3: State.keypresses[KEY_3] = down; break; case GLFW_KEY_4: State.keypresses[KEY_4] = down; break;
            case GLFW_KEY_5: State.keypresses[KEY_5] = down; break; case GLFW_KEY_6: State.keypresses[KEY_6] = down; break;
            case GLFW_KEY_7: State.keypresses[KEY_7] = down; break; case GLFW_KEY_8: State.keypresses[KEY_8] = down; break;
            case GLFW_KEY_9: State.keypresses[KEY_9] = down; break; case GLFW_KEY_0: State.keypresses[KEY_0] = down; break;
            case GLFW_KEY_A: State.keypresses[KEY_A] = down; break; case GLFW_KEY_B: State.keypresses[KEY_B] = down; break;
            case GLFW_KEY_C: State.keypresses[KEY_C] = down; break; case GLFW_KEY_D: State.keypresses[KEY_D] = down; break;
            case GLFW_KEY_E: State.keypresses[KEY_E] = down; break; case GLFW_KEY_F: State.keypresses[KEY_F] = down; break;
            case GLFW_KEY_G: State.keypresses[KEY_G] = down; break; case GLFW_KEY_H: State.keypresses[KEY_H] = down; break;
            case GLFW_KEY_I: State.keypresses[KEY_I] = down; break; case GLFW_KEY_J: State.keypresses[KEY_J] = down; break;
            case GLFW_KEY_K: State.keypresses[KEY_K] = down; break; case GLFW_KEY_L: State.keypresses[KEY_L] = down; break;
            case GLFW_KEY_M: State.keypresses[KEY_M] = down; break; case GLFW_KEY_N: State.keypresses[KEY_N] = down; break;
            case GLFW_KEY_O: State.keypresses[KEY_O] = down; break; case GLFW_KEY_P: State.keypresses[KEY_P] = down; break;
            case GLFW_KEY_Q: State.keypresses[KEY_Q] = down; break; case GLFW_KEY_R: State.keypresses[KEY_R] = down; break;
            case GLFW_KEY_S: State.keypresses[KEY_S] = down; break; case GLFW_KEY_T: State.keypresses[KEY_T] = down; break;
            case GLFW_KEY_U: State.keypresses[KEY_U] = down; break; case GLFW_KEY_V: State.keypresses[KEY_V] = down; break;
            case GLFW_KEY_W: State.keypresses[KEY_W] = down; break; case GLFW_KEY_X: State.keypresses[KEY_X] = down; break;
            case GLFW_KEY_Y: State.keypresses[KEY_Y] = down; break; case GLFW_KEY_Z: State.keypresses[KEY_Z] = down; break;
            case GLFW_KEY_ESCAPE: State.keypresses[KEY_ESC] = down; break;
            case GLFW_KEY_SPACE: State.keypresses[KEY_SPACE] = down; break;
            case GLFW_KEY_LEFT_SHIFT: State.keypresses[KEY_LSHIFT] = down; break;
            default: break;
        }
    } else if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_1: State.keypresses[KEY_1] = up; break; case GLFW_KEY_2: State.keypresses[KEY_2] = up; break;
            case GLFW_KEY_3: State.keypresses[KEY_3] = up; break; case GLFW_KEY_4: State.keypresses[KEY_4] = up; break;
            case GLFW_KEY_5: State.keypresses[KEY_5] = up; break; case GLFW_KEY_6: State.keypresses[KEY_6] = up; break;
            case GLFW_KEY_7: State.keypresses[KEY_7] = up; break; case GLFW_KEY_8: State.keypresses[KEY_8] = up; break;
            case GLFW_KEY_9: State.keypresses[KEY_9] = up; break; case GLFW_KEY_0: State.keypresses[KEY_0] = up; break;
            case GLFW_KEY_A: State.keypresses[KEY_A] = up; break; case GLFW_KEY_B: State.keypresses[KEY_B] = up; break;
            case GLFW_KEY_C: State.keypresses[KEY_C] = up; break; case GLFW_KEY_D: State.keypresses[KEY_D] = up; break;
            case GLFW_KEY_E: State.keypresses[KEY_E] = up; break; case GLFW_KEY_F: State.keypresses[KEY_F] = up; break;
            case GLFW_KEY_G: State.keypresses[KEY_G] = up; break; case GLFW_KEY_H: State.keypresses[KEY_H] = up; break;
            case GLFW_KEY_I: State.keypresses[KEY_I] = up; break; case GLFW_KEY_J: State.keypresses[KEY_J] = up; break;
            case GLFW_KEY_K: State.keypresses[KEY_K] = up; break; case GLFW_KEY_L: State.keypresses[KEY_L] = up; break;
            case GLFW_KEY_M: State.keypresses[KEY_M] = up; break; case GLFW_KEY_N: State.keypresses[KEY_N] = up; break;
            case GLFW_KEY_O: State.keypresses[KEY_O] = up; break; case GLFW_KEY_P: State.keypresses[KEY_P] = up; break;
            case GLFW_KEY_Q: State.keypresses[KEY_Q] = up; break; case GLFW_KEY_R: State.keypresses[KEY_R] = up; break;
            case GLFW_KEY_S: State.keypresses[KEY_S] = up; break; case GLFW_KEY_T: State.keypresses[KEY_T] = up; break;
            case GLFW_KEY_U: State.keypresses[KEY_U] = up; break; case GLFW_KEY_V: State.keypresses[KEY_V] = up; break;
            case GLFW_KEY_W: State.keypresses[KEY_W] = up; break; case GLFW_KEY_X: State.keypresses[KEY_X] = up; break;
            case GLFW_KEY_Y: State.keypresses[KEY_Y] = up; break; case GLFW_KEY_Z: State.keypresses[KEY_Z] = up; break;
            case GLFW_KEY_ESCAPE: State.keypresses[KEY_ESC] = up; break;
            case GLFW_KEY_SPACE: State.keypresses[KEY_SPACE] = up; break;
            case GLFW_KEY_LEFT_SHIFT: State.keypresses[KEY_LSHIFT] = up; break;
            default: break;
        }
    }
}

static void _cursor_callback(__attribute__ ((unused)) GLFWwindow *w, double xpos, double ypos)
{
    State.cursor.x = (float)xpos;
    State.cursor.y = (float)ypos;
    State.needs_update = yes;
}

static void _geterror_callback(int error, const char *msg)
{
    fprintf(stderr, "GLFW error %d - %s", error, msg);
    exit(EXIT_FAILURE);
}

static void _mousebutton_callback(GLFWwindow *w, int button, int action, __attribute__ ((unused)) int mod)
{

    if (!State.focused) {
        glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        State.focused = true;
    }
    if (action == GLFW_PRESS)
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            State.click.x = State.cursor.x;
            State.click.y = State.cursor.y;
        }
    if (action == GLFW_RELEASE)
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            State.release.x = State.cursor.x;
            State.release.y = State.cursor.y;
        }
}

static void _framebuffer_size_callback(__attribute__ ((unused)) GLFWwindow *w, int width, int height)
{
    State.window_size.w = (float)width;
    State.window_size.h = (float)height;
    State.window_size.ar = State.window_size.w / State.window_size.h;
    glViewport(0, 0, width, height);
}

// void window_focus_callback(GLFWwindow *w, int focused)
// {
//     if (focused) continue();
//     else pause();
// }

// Function definitions
bool_t window_is_focused(void)
{
     return State.focused;
}

bool_t window_is_debug_mode(void)
{
     return State.debug_mode;
}

bool_t window_is_key_pressed(keytype_t key)
{
     return State.keypresses[key];
}

float window_aspect_ratio(void)
{
     return State.window_size.ar;
}

void set_window_pressed_key(keytype_t key, keystate_t key_state)
{
     State.keypresses[key] = key_state;
}

bool_t window_loop_is_over(void)
{
     return glfwWindowShouldClose(State.glfwWindow);
}

bool_t window_was_updated(void)
{
    if (!State.needs_update) return no;
    State.needs_update = no;
    return yes;
}

void window_cursor_position(struct cursor_t *c)
{
    *c = State.cursor;
}

void window_cursor_positionv(float *v)
{
    v[0] = State.cursor.x;
    v[1] = State.cursor.y;
}

void window_size(struct window_size_t *w)
{
    *w = State.window_size;
}

void set_window_cursor_position(const float x, const float y)
{
    State.cursor.x = x;
    State.cursor.y = y;
}

void set_window_size(const float w, const float h)
{
    State.window_size.w = w;
    State.window_size.h = h;
    State.window_size.ar = w/h;
}

void update_window_left_mouse_clicked(void)
{
    State.click.x = State.cursor.x;
    State.click.y = State.cursor.y;
}

void update_window_left_mouse_release(void)
{
    State.release.x = State.cursor.x;
    State.release.y = State.cursor.y;
}

double get_window_time(void)
{
    return glfwGetTime();
}

void window_tick(void)
{
    size_t i;
    for (i = 0; i < Callbacks.onkey_count; ++i) {
        const keytype_t k = Callbacks.onkey_array[i];
        if (State.keypresses[k]) {
            Callbacks.onkey_funcs[k](Callbacks.onkey_param_data[k]);
            State.needs_update = yes;
        }
    }

    glfwSwapBuffers(State.glfwWindow);
    glfwPollEvents();
}

int backend_exit_success(void)
{
    finalizeTextures();
    finalizeMeshData();
    glfwDestroyWindow(State.glfwWindow);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void backend_exit_failure(void)
{
    glfwDestroyWindow(State.glfwWindow);
    glfwTerminate();
    exit(EXIT_FAILURE);
}

void update_backend_input_triggers(void)
{
    if (State.keypresses[KEY_ESC]) {
        glfwSetInputMode(State.glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        State.focused = no;
    }
    if (State.keypresses[KEY_Q])
        glfwSetWindowShouldClose(State.glfwWindow, 1);
}

void set_backend_key_callbacks(void (*func_ptr)(void *), void *data, keytype_t k)
{
    Callbacks.onkey_funcs[k] = func_ptr;
    Callbacks.onkey_param_data[k] = data;
    Callbacks.onkey_funcs[k](Callbacks.onkey_param_data[k]);
    Callbacks.onkey_array[Callbacks.onkey_count++] = k;
}

void init_backend(void)
{
    // glfw init
    glfwSetErrorCallback(_geterror_callback);
    set_window_size(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);

    glfwInit();
    _print_glfw_version();
    _set_glfw_hints();

    State.glfwWindow = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "OpenGL SB", NULL, NULL);
    if (!State.glfwWindow) {
        fprintf(stderr, "Unable to get GLFW window context.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(State.glfwWindow);
    _set_glfw_callbacks();

    // glew init
    glewExperimental = GL_TRUE;
    GLenum result = glewInit();
    if (result != GLEW_OK) {
        fprintf(stderr, "glewInit returned error %s.\n", glewGetErrorString(result));
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // glFrontFace(GL_CW); glCullFace(GL_BACK); glEnable(GL_CULL_FACE); glDepthFunc(GL_LESS);
    // glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glEnable(GL_STENCIL_TEST);
    // glStencilFunc(GL_NOTEQUAL, 1, 0xff); glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    initTextures(TEXTURES_ROOT_DIR);
    initMeshData(MESHDATA_ROOT_DIR);
    // initShaderData(SHADERS_ROOT_DIR);
    printObjFiles();
    printTexFiles();
    // printShaderFiles();

}
