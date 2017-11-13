#include "loop.h"
#include "Render.h"
#include "backend.h"
#include <stdio.h>

// http://www.glfw.org/docs/latest/window_guide.html#window_creation
// MAIN


void mainloop(void)
{
    WindowSize windowSize;
    Cursor mouseCoords;
    window_size(&windowSize);

    Renderer *rend = new_renderer();
    if (!rend) backend_exit_failure();

    double lastTime = get_window_time();
    double deltaTime = 0.0;
    double thisTime = 0.0;
    double last = 0.0;
    int frameCount = 0;

    while (!window_loop_is_over()) {
        frameCount++;
        if (get_window_time() - lastTime >= 1.0) {
            if (window_is_debug_mode()) { printf("%lf ms / frame\n", 1000.0 /(double)frameCount); }
            frameCount = 0;
            lastTime += 1.0;
        }

        last = get_window_time();
        deltaTime = last - thisTime;
        thisTime = last;

        window_size(&windowSize);
        window_cursor_position(&mouseCoords);
        update_backend_input_triggers();
        update_renderer(rend, &windowSize, (float)deltaTime, window_was_updated());

        if (!window_is_focused())
            render_idle(rend);
        else
            render(rend);

        window_tick();

    }
    destroy_renderer(rend);
}
