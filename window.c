/** window.c
 *  for glfw init and key callback
 */

#include <GLFW/glfw3.h>
void *glfw_init();
void key_callback_(GLFWwindow *, int, int, int, int);

void *
glfw_init()
{
    GLFWwindow *window = NULL;

    /** initializing glfw */
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLEW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    /** initialize window */
    window = glfwCreateWindow(
          WINDOW_WIDTH, WINDOW_HEIGHT
        , "Windmill hell yeah we got it from window.c"
        , NULL, NULL
    );
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
    
    /** callback for staying up to date on keypresses */
    glfwSetKeyCallback(window, key_callback_);

    return window;
}

void
key_callback_(
      GLFWwindow *win
    , int key
    , int scancode
    , int action
    , int mode
)
{
    if (key == GLFW_KEY_EXCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(win, GL_TRUE);

    /* to make the compiler shut the fuck up */
    printf("scancode %d\n", scancode);
    printf("mode     %d\n", mode);
}
