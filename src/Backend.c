#include "Backend.h"
#include "meshdata.h"
#include "texture.h"
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

/**
 * Global variables
 */
GLFWwindow *glfwWindow;
static bool DebugMode;
static bool NeedsUpdate;
static bool Focused;

static bool Keypresses[KEY_TOTAL];
static float MouseX;
static float MouseY;
static float LastClickX;
static float LastClickY;
static float LastReleaseX;
static float LastReleaseY;
static float WindowWidth;
static float WindowHeight;
static float AspectRatio;

static KeyType callback_key_array[KEY_TOTAL];
size_t num_callbacks;
static void (*callback_funcs[KEY_TOTAL])(void *);
static void *callback_datas[KEY_TOTAL];

// Forward decs
static void _backendSetCallbacks(void);
static void _backendFramebufferSizeCallback(GLFWwindow *w, int width, int height);
static void _backendKeyDownCallback(GLFWwindow *w, int key, int scancode, int action, int mode);
static void _backendCursorPosCallback(__attribute__ ((unused)) GLFWwindow *w, double xpos, double ypos);
static void _backendGetErrorCallback(int error, const char *msg);
static void _backendMouseButtonCallback(GLFWwindow *w, int button, int action, __attribute__ ((unused)) int mod);


// Defs
bool eventFocused(void) { return Focused; }
bool eventDebugMode(void) { return DebugMode; }
bool eventGetKeyPress(KeyType key) { return Keypresses[key]; }
float eventGetAspectRatio(void) { return AspectRatio; }
void eventSetKey(KeyType key, bool state) { Keypresses[key] = state; }
bool eventLoopExit(void) { return glfwWindowShouldClose(glfwWindow); }

bool eventGetUpdated(void)
{
    bool ret = NeedsUpdate;
    NeedsUpdate = false;
    return ret;
}

void eventGetMousePos(Mouse_t *m)
{
    m->x = MouseX;
    m->y = MouseY;
}

void eventGetWindowSize(Window_t *w)
{
    w->w = WindowWidth;
    w->h = WindowHeight;
}

void eventSetMousePos(const float x, const float y)
{
    MouseX = x;
    MouseY = y;
}

void eventSetWindowSize(const float w, const float h)
{
    WindowWidth = w;
    WindowHeight = h;
    AspectRatio = w / h;
}

void eventUpdateLeftMouseClicked(void)
{
    LastClickX = MouseX;
    LastClickY = MouseY;
}

void eventUpdateLeftMouseReleased(void)
{
    LastReleaseX = MouseX;
    LastReleaseY = MouseY;
}

double backendGetTime(void)
{
    return glfwGetTime();
}

void eventLoopTick(void)
{
    size_t i;
    for (i = 0; i < num_callbacks; ++i) {
        KeyType k = callback_key_array[i];
        if (Keypresses[k] == true) {
            callback_funcs[k](callback_datas[k]);
            NeedsUpdate = true;
        }
    }
    glfwSwapBuffers(glfwWindow);
    glfwPollEvents();
}

int backendExitSuccess(void)
{
    finalizeTextures();
    finalizeMeshData();
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
    return EXIT_SUCCESS;
}

void backendExitFailure(void)
{
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
    exit(EXIT_FAILURE);
}

void backendHandleInputEvents(void)
{
    // glfwGetCursorPos(glfwWindow, &doublex, &doubley)
    if (Keypresses[KEY_ESC]) {
        glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        Focused = false;
    }
    if (Keypresses[KEY_Q])
        glfwSetWindowShouldClose(glfwWindow, 1);
}

void backendInit(void) __attribute__ ((constructor));
void backendInit(void)
{
    // glfw init
    glfwSetErrorCallback(_backendGetErrorCallback);
    eventSetWindowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT);
    // WindowWidth = DEFAULT_WINDOW_WIDTH;
    // WindowHeight = DEFAULT_WINDOW_HEIGHT;
    // AspectRatio = (float)WindowWidth / (float)WindowHeight;

    glfwInit();
    int major, minor, rev;
    glfwGetVersion(&major, &minor, &rev);
    printf("GLFW %d.%d.%d initialized\n", major, minor, rev);

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

    glfwWindow = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "OpenGL SB", NULL, NULL);
    if (glfwWindow == NULL) {
        fprintf(stderr, "Unable to get GLFW window context.\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(glfwWindow);
    _backendSetCallbacks();
    // glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glew init
    glewExperimental = GL_TRUE;
    GLenum result = glewInit();
    if (result != GLEW_OK) {
        fprintf(stderr, "glewInit returned error %s.\n", glewGetErrorString(result));
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    initTextures(TEXTURES_ROOT_DIR);
    initMeshData(MESHDATA_ROOT_DIR);
    printObjFiles();
    printTexFiles();

    // glFrontFace(GL_CW); glCullFace(GL_BACK); glEnable(GL_CULL_FACE); glDepthFunc(GL_LESS);
    // glEnable(GL_BLEND); glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); glEnable(GL_STENCIL_TEST);
    // glStencilFunc(GL_NOTEQUAL, 1, 0xff); glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
}

static void _backendSetCallbacks(void)
{
    glfwSetFramebufferSizeCallback(glfwWindow,  _backendFramebufferSizeCallback);
    glfwSetKeyCallback(glfwWindow,              _backendKeyDownCallback);
    glfwSetCursorPosCallback(glfwWindow,        _backendCursorPosCallback);
    glfwSetMouseButtonCallback(glfwWindow, _backendMouseButtonCallback);
    // glfwSetCursorEnterCallback(glfwWindow,        cursorEnterCallback);
    // glfwSetWindowCloseCallback(glfwWindow, windowCloseCallback);
    // glfwSetWindowFocusCallback(glfwWindow, windowFocusCallback);
    // glfwSetWindowRefreshCallback(glfwWindow, windowRefreshCallback);
}

void backendSetCallback(void (*funcPtr)(void *), void *data, KeyType k)
{
    callback_funcs[k] = funcPtr;
    callback_datas[k] = data;
    callback_funcs[k](callback_datas[k]);
    callback_key_array[num_callbacks++] = k;
}

// Ballback function definitions
static void _backendKeyDownCallback(
    __attribute__ ((unused)) GLFWwindow *w,
                                    int key,
           __attribute__ ((unused)) int scancode,
                                    int action,
           __attribute__ ((unused)) int mode)
{
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
        DebugMode ^= true;
    NeedsUpdate = true;
    if (action == GLFW_PRESS) {
        switch (key) {
            case GLFW_KEY_A: Keypresses[KEY_A] = true; break;
            case GLFW_KEY_B: Keypresses[KEY_B] = true; break;
            case GLFW_KEY_C: Keypresses[KEY_C] = true; break;
            case GLFW_KEY_D: Keypresses[KEY_D] = true; break;
            case GLFW_KEY_E: Keypresses[KEY_E] = true; break;
            case GLFW_KEY_F: Keypresses[KEY_F] = true; break;
            case GLFW_KEY_G: Keypresses[KEY_G] = true; break;
            case GLFW_KEY_H: Keypresses[KEY_H] = true; break;
            case GLFW_KEY_I: Keypresses[KEY_I] = true; break;
            case GLFW_KEY_J: Keypresses[KEY_J] = true; break;
            case GLFW_KEY_K: Keypresses[KEY_K] = true; break;
            case GLFW_KEY_L: Keypresses[KEY_L] = true; break;
            case GLFW_KEY_M: Keypresses[KEY_M] = true; break;
            case GLFW_KEY_N: Keypresses[KEY_N] = true; break;
            case GLFW_KEY_O: Keypresses[KEY_O] = true; break;
            case GLFW_KEY_P: Keypresses[KEY_P] = true; break;
            case GLFW_KEY_Q: Keypresses[KEY_Q] = true; break;
            case GLFW_KEY_R: Keypresses[KEY_R] = true; break;
            case GLFW_KEY_S: Keypresses[KEY_S] = true; break;
            case GLFW_KEY_T: Keypresses[KEY_T] = true; break;
            case GLFW_KEY_U: Keypresses[KEY_U] = true; break;
            case GLFW_KEY_V: Keypresses[KEY_V] = true; break;
            case GLFW_KEY_W: Keypresses[KEY_W] = true; break;
            case GLFW_KEY_X: Keypresses[KEY_X] = true; break;
            case GLFW_KEY_Y: Keypresses[KEY_Y] = true; break;
            case GLFW_KEY_Z: Keypresses[KEY_Z] = true; break;
            case GLFW_KEY_ESCAPE: Keypresses[KEY_ESC] = true; break;
            case GLFW_KEY_SPACE: Keypresses[KEY_SPACE] = true; break;
            case GLFW_KEY_LEFT_SHIFT: Keypresses[KEY_LSHIFT] = true; break;
            default: break;
        }
    } else if (action == GLFW_RELEASE) {
        switch (key) {
            case GLFW_KEY_A: Keypresses[KEY_A] = false; break;
            case GLFW_KEY_B: Keypresses[KEY_B] = false; break;
            case GLFW_KEY_C: Keypresses[KEY_C] = false; break;
            case GLFW_KEY_D: Keypresses[KEY_D] = false; break;
            case GLFW_KEY_E: Keypresses[KEY_E] = false; break;
            case GLFW_KEY_F: Keypresses[KEY_F] = false; break;
            case GLFW_KEY_G: Keypresses[KEY_G] = false; break;
            case GLFW_KEY_H: Keypresses[KEY_H] = false; break;
            case GLFW_KEY_I: Keypresses[KEY_I] = false; break;
            case GLFW_KEY_J: Keypresses[KEY_J] = false; break;
            case GLFW_KEY_K: Keypresses[KEY_K] = false; break;
            case GLFW_KEY_L: Keypresses[KEY_L] = false; break;
            case GLFW_KEY_M: Keypresses[KEY_M] = false; break;
            case GLFW_KEY_N: Keypresses[KEY_N] = false; break;
            case GLFW_KEY_O: Keypresses[KEY_O] = false; break;
            case GLFW_KEY_P: Keypresses[KEY_P] = false; break;
            case GLFW_KEY_Q: Keypresses[KEY_Q] = false; break;
            case GLFW_KEY_R: Keypresses[KEY_R] = false; break;
            case GLFW_KEY_S: Keypresses[KEY_S] = false; break;
            case GLFW_KEY_T: Keypresses[KEY_T] = false; break;
            case GLFW_KEY_U: Keypresses[KEY_U] = false; break;
            case GLFW_KEY_V: Keypresses[KEY_V] = false; break;
            case GLFW_KEY_W: Keypresses[KEY_W] = false; break;
            case GLFW_KEY_X: Keypresses[KEY_X] = false; break;
            case GLFW_KEY_Y: Keypresses[KEY_Y] = false; break;
            case GLFW_KEY_Z: Keypresses[KEY_Z] = false; break;
            case GLFW_KEY_ESCAPE: Keypresses[KEY_ESC] = false; break;
            case GLFW_KEY_SPACE: Keypresses[KEY_SPACE] = false; break;
            case GLFW_KEY_LEFT_SHIFT: Keypresses[KEY_LSHIFT] = false; break;
            default: break;
        }
    }
}

void _backendCursorPosCallback(__attribute__ ((unused)) GLFWwindow *w, double xpos, double ypos)
{
    // MouseX = (float)xpos;
    // MouseY = (float)ypos;
    eventSetMousePos((float)xpos, (float)ypos);
    MouseX = (float)xpos;
    MouseY = (float)ypos;
    NeedsUpdate = true;
}

void _backendGetErrorCallback(int error, const char *msg)
{
    fprintf(stderr, "GLFW error %d - %s", error, msg);
    exit(EXIT_FAILURE);
}

void _backendMouseButtonCallback(GLFWwindow *w, int button, int action, __attribute__ ((unused)) int mod)
{

    if (!Focused) {
        glfwSetInputMode(w, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        Focused = true;
    }

    if (action == GLFW_PRESS)
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            LastClickX = MouseX;
            LastClickY = MouseY;
        }
    if (action == GLFW_RELEASE)
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            LastReleaseX = MouseX;
            LastReleaseY = MouseY;
        }
}

static void _backendFramebufferSizeCallback(__attribute__ ((unused)) GLFWwindow *w, int width, int height)
{
    WindowWidth = (float)width;
    WindowHeight = (float)height;
    AspectRatio = WindowWidth / WindowHeight;
    glViewport(0, 0, width, height);
}

// void windowFocusCallback(GLFWwindow *w, int focused)
// {
//     if (focused) continue();
//     else pause();
// }
