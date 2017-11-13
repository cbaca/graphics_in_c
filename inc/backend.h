#ifndef BACKEND_H
#define BACKEND_H
#include <stdbool.h>
#include "types.h"

/**
 */
bool_t window_is_focused(void);

bool_t window_is_debug_mode(void);

bool_t window_is_key_pressed(keytype_t key);

float window_aspect_ratio(void);

bool_t window_loop_is_over(void);

bool_t window_was_updated(void);

double get_window_time(void);


void window_cursor_position(struct cursor_t *c);

void window_cursor_positionv(float *v);

void window_size(struct window_size_t *w);

void set_window_pressed_key(keytype_t key, keystate_t key_state);

void set_window_cursor_position(const float x, const float y);

void set_window_size(const float w, const float h);

void update_window_left_mouse_clicked(void);

void update_window_left_mouse_release(void);

void window_tick(void);

int backend_exit_success(void);

void backend_exit_failure(void);

void update_backend_input_triggers(void);

void set_backend_key_callbacks(void (*func_ptr)(void *), void *data, keytype_t k);

void print_glfw_version(void);

void set_glfw_hints(void);

void init_backend(void);
#endif /* BACKEND_H */
