/** keys.h */
#ifndef KEYS_H_
#define KEYS_H_
/** ビットマスク見たいな漢字で使う*/
#define KEY_UP    0x01 /** 上向きやで           */
#define KEY_LEFT  0x02 /** 左向きヤビッシュ     */
#define KEY_DOWN  0x04 /** 下向きこのやろ       */
#define KEY_RIGHT 0x08 /** 右向きばかやろ       */
#define KEY_Y     0x10 /** 風車本体回転やろう   */
#define KEY_W     0x20 /** そういつの羽を回転ちくしょめが */
/* なーーんかあってなさそ */

/** ぎゃく */
#define NOT_KEY_UP    ~0x01
#define NOT_KEY_LEFT  ~0x02
#define NOT_KEY_DOWN  ~0x04
#define NOT_KEY_RIGHT ~0x08
#define NOT_KEY_Y     ~0x10
#define NOT_KEY_W     ~0x20
#endif
