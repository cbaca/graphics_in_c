#ifndef RENDER_H
#define RENDER_H
#include "Shader.h"
#include "World.h"
#include "Vec3.h"
#include "Scene.h"
#include "types.h"

typedef struct render_t Renderer;

/**
 * new_renderer
 * Allocates and returns pointer to instance of struct render_t.
 * @return struct render_t: Pointer to new instance of struct render_t. Returns null on failure;
 */
struct render_t *new_renderer(void) __attribute__ ((malloc));

/**
 * destroy_renderer
 * Finalizes and frees instance of struct render_t;
 * @param renderer: Pointer to instance of struct render_t;
 */
void destroy_renderer(struct render_t *renderer);

/**
 * update_renderer
 * Updates render state with window framebuffer size, time, and window update status.
 * @param renderer: Pointer to instance of struct render_t.
 * @param ws: Pointer to instance of WindowSize datatype, which  contains the window's
 *            framebuffer width, height, and aspect ratio in pixels.
 * @param seconds: Elapsed seconds since start of program.
 * @param needs_update: Boolean value which indicates whether the window has been interacted with since
 *                      the last update.
 */
void update_renderer(Renderer *r, const WindowSize *ws, const float seconds, const bool_t needs_update);

/**
 * render
 * Renders all objects in the struct render_t instance.
 */
void render(Renderer *r);

/**
 * render_idle
 * Renders a shader output on the entire framebuffer. For use when the window is not in focus.
 */
void render_idle(Renderer *r);

#endif /* RENDER_H */
