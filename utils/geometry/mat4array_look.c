/** mat4array_look.c */
#include <math.h>

void
mat4array_get_look_at(
      float *restrict out /* 16 戻り値として使用 */
    , float *restrict eye /* 3  カメラ立場       */
    , float *restrict mid /* 3  カメラ向き       */
    , float *restrict up) /* 3  どこが上だったみたいな？ */
{
 /* 座標に使用 */
#   define x 0
#   define y 1
#   define z 2
    /* ロールー回転軸ベクトルを作って、そして単位ベクトルに */
    float roll[3] = { mid[x] - eye[x],  mid[y] - eye[y], mid[z] - eye[z] };
    float len_recip = 1.0f / (float)sqrt(
               /** ロールさんとロールさんのドット積 */
        roll[x] * roll[x] + roll[y] * roll[y] +  roll[z] * roll[z]
        );
    roll[x] *= len_recip;
    roll[y] *= len_recip;
    roll[z] *= len_recip;

    /* ロールとアップからピッチベクトル出す */
    float pitch[3] = {
        /* まず、ロールとアップのクロス積 */
          roll[y] * up[z] - roll[z] * up[y]
        , roll[z] * up[x] - roll[x] * up[z]
        , roll[x] * up[y] - roll[y] * up[x]
    };
    /* そして単位べくトリに */
    len_recip = 1.0f / (float)sqrt(
        pitch[x] * pitch[x] + pitch[y] * pitch[y] +  pitch[z] * pitch[z]
        );
    pitch[x] *= len_recip;
    pitch[y] *= len_recip;
    pitch[z] *= len_recip;

    /* ピッチとロールのクロス積がヨーになる */
    float yaw[3] = {
          pitch[y] * roll[z] - pitch[z] * roll[y]
        , pitch[z] * roll[x] - pitch[x] * roll[z]
        , pitch[x] * roll[y] - pitch[y] * roll[x]
    };

    /* 最後にマトリクスを */
    out[ 0] = pitch[x];
    out[ 4] = pitch[y];
    out[ 8] = pitch[z];

    out[ 1] = yaw[x];
    out[ 5] = yaw[y];
    out[ 9] = yaw[z];

    out[ 2] = -roll[x];
    out[ 6] = -roll[y];
    out[10] = -roll[z];

    out[12] = pitch[x] * eye[x] + pitch[y] * eye[y] + pitch[z] * eye[z];
    out[13] = yaw[x] * eye[x] + yaw[y] * eye[y] + yaw[z] * eye[z];
    out[14] = roll[x] * eye[x] + roll[y] * eye[y] + roll[z] * eye[z];
#   undef x
#   undef y
#   undef z
}

/* https://en.wikipedia.org/wiki/Dot_product
 * a1 * b1 + a2 * b2 + a3 * b3 ... + aN * bN
 * float
 * dot_productv3(vec3 a, vec3 b)
 * {
 *   return a.x * b.x +
 *          a.y * b.y +
 *          a.z * b.z;
 *
 * }
 */
/* float
 * length(vec3 a)
 * {
 *   return sqrt(dot_product(a, a));
 * }
 */
/*  vec3
 *  normalize(vec3 a)
 *  {
 *      float len = length(a)
 *      return { a.x / len, a.y / len, a.z / len };
 *  }
 */
/*  vec3
 *  cross(vec3 a, vec3 b)
 *  {
 *      return {
 *            a.y * b.z - a.z * b.y
 *          , a.z * b.x - a.x * b.z
 *          , a.x * b.y - a.y * b.x
 *      };
 *   }
 */

