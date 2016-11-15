/** mat4array_perspective.c */
#include <math.h>
#include <assert.h>

/* openglのglmと言う行列関数ようC++テンプレート・リブはこんなような宣言されている
 * 関数は存在でありました:
 *  float get_perspective(
 *        field_of_view // size of viewspace
 *      , aspect_ratio // viewport_w / viewport_h
 *      , near_plane  // uuh, is this related to fulcrum/ view？probably
 *      , far_plane);
 *
 *  そしていつかしらここんなかでperspective divisionを
 *  perspective divison とは行列の多分11, 12, 13番座標にある変数を一個ずっつ
 *  14番の座標の変数に割ることになっている気がした。
 *  11, 12, 13がオブジェクトの頂点のX, Y, Zのその順番のままになってるはずだね。
 *  そして14番座標がWもしくはnomalizeなんちゃらとして使われる。こいつで割ると
 *  4次元の行列が3次元の画面に映せる座標になるんだったかも。
 *
 *  NDCと目座標のビッグ違いがZ軸の向きが逆です。NDCは手前から後ろまで行くと座標
 *  のZは 大きくなる。目座標はZ小さくなる。
 *  NDCのほうはleft handed座標システムと言うそうです。目座標はその通りright
 *  handed.
 *  NDCに変換する時にこの違いも認めないと。
 *
 */

void
mat4array_get_perspective( /* glm/gtc/matrix_transform.inl */
      float *restrict out
    , const float field_of_view /* 大体約45度になるらしいけ π/4 ってことか */
    , const float aspect_ratio  /* viewport_w / viewport_h                 */
    , const float near_plane    /* 大体約1.0f                              */
    , const float far_plane)    /* 大体約100.0f                            */
{
    assert(aspect_ratio > 0.0f);

    float loc = (float)tan(field_of_view / 2);

    out[ 0] = 1.0f / (aspect_ratio * loc);
    out[ 5] = 1.0f / loc;
    out[10] = -(far_plane + near_plane) / far_plane - near_plane;
    out[11] = -1.0f;
    out[14] = -(2.0f * far_plane * near_plane) / far_plane - near_plane;
}
