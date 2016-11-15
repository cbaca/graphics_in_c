/** mat4array_look.c */
#include <math.h>

void
mat4array_get_look_at(
      float *restrict out /* 16 */
    , float *restrict eye /* 3  */
    , float *restrict mid /* 3  */
    , float *restrict up) /* 3  */
{
    float roll[3] = { mid[0] - eye[0],  mid[1] - eye[1], mid[2] - eye[2] };
    float len_recip = 1 / (float)sqrt((roll[0] * roll[0]) + (roll[1] * roll[1]) + roll[2] * roll[2]);
    roll[0] *= len_recip;
    roll[1] *= len_recip;
    roll[2] *= len_recip;
    float pitch[3] = /* { }; normalize(corss(roll, up)) */
    float yaw[3] = /* { }; */
}
