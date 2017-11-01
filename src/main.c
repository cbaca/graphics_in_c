#include "Render.h"
#include "Backend.h"
// #include "meshdata.h"
#include <stdio.h>

// http://www.glfw.org/docs/latest/window_guide.html#window_creation
// MAIN
int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    Window_t windowSize;
    Mouse_t mouseCoords;
    eventGetWindowSize(&windowSize);

    Render_t rend;
    if (!initRenderer(&rend)) backendExitFailure();

    double lastTime = backendGetTime();
    double deltaTime = 0.0;
    double thisTime = 0.0;
    double last = 0.0;
    int frameCount = 0;
    while (!eventLoopExit()) {
        frameCount++;
        if (backendGetTime() - lastTime >= 1.0) {
            if (eventDebugMode()) { printf("%lf ms / frame\n", 1000.0 /(double)frameCount); }
            frameCount = 0;
            lastTime += 1.0;
        }

        last = backendGetTime();
        deltaTime = last - thisTime;
        thisTime = last;
        // printf("%lf\n", deltaTime);


        bool update = eventGetUpdated();

        eventGetWindowSize(&windowSize);
        eventGetMousePos(&mouseCoords);
        backendHandleInputEvents();
        if (!eventFocused()) goto pollevents;

        // updateRenderer(&rend, &windowSize, &mouseCoords, (float)lastTime, update);
        updateRenderer(&rend, windowSize.w, windowSize.h, (float)deltaTime, update);
        render(&rend);

        pollevents:
        eventLoopTick();

    }
    finalizeRenderer(&rend);


    return backendExitSuccess();
}
