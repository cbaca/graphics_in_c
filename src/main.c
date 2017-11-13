// #include "Render.h"
#include "loop.h"
#include "backend.h"
#include <stdio.h>

// http://www.glfw.org/docs/latest/window_guide.html#window_creation
// MAIN

int main(int argc, char **argv)
{
#ifdef RADICAL
#include<stdio.h>
#endif
    (void)argc;
    (void)argv;

    init_backend(/* argc, argv */);

    mainloop();

    return backend_exit_success();
}
