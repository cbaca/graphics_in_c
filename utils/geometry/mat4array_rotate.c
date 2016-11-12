/** mat4array_rotate.c */
#include "include/mat4array_make.h"
#include <math.h>

void
mat4array_make_rotation(float *restrict new, double seta)
{
    /** ヨー回転だけの場合 */
    double c = cos(seta);
    double s = sin(seta);
    mat4array_make(new, MAT4ARRAY_IDENTITY);
    new[0] = (float)  c;
    new[1] = (float)(-s);
    new[4] = (float)  s;
    new[5] = (float)  c;
    /** ロールはまだ */
    /** ピッチはまだ */
    /** なんこかの組み合わせは四元数（英：quaternion）を調べなさい */
}
