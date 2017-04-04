/**
 * @file windmill.h
 * -----------------------------------------------------------------------------
 */
#ifndef WINDMILL_H_
#define WINDMILL_H_

struct wm_data_t {
    float cubes[16];
    float cube_vecs[30];
    float angle_vecs[3];
};

void windmill_init(float *restrict cubes, float *restrict vecs,
    float *restrict angles);
void animate_cubes(int);
void draw_objects36(int, float *restrict, int, int);
#endif /* WINDMILL_H_ */
