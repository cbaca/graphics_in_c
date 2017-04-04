/**
 * @file player.h
 * -----------------------------------------------------------------------------
 */

#ifndef PLAYER_H_
#define PLAYER_H_
struct player_iter_t {

    float *restrict dat;
    float *restrict pos;
    float *restrict frn;
    float *restrict yoko;
    float *restrict tate;
    float *restrict wrld;
};

struct player_data_t {
    float view_m[16];
    float dat[3];
    float pos[3];
    float frn[3];
    float yoko[3];
    float tate[3];
    float wrld[3];
};

void player_init(void *player);
void player_look(void);
void player_move(const int input, const float timeval);
void player_get_view(void);
#endif /* PLAYER_H_ */
