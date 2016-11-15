/** mat4array_transpose.c */
#include <assert.h>
void
mat4array_transpose(float *restrict out)
{
    assert(out != (void *)0);
    
    /* コピー */
    float tmp[16];
    tmp[ 0] = out[ 0]; tmp[ 1] = out[ 1]; tmp[ 2] = out[ 2]; tmp[ 3] = out[ 3];
    tmp[ 4] = out[ 4]; tmp[ 5] = out[ 5]; tmp[ 6] = out[ 6]; tmp[ 7] = out[ 7];
    tmp[ 8] = out[ 8]; tmp[ 9] = out[ 9]; tmp[10] = out[10]; tmp[11] = out[11];
    tmp[12] = out[12]; tmp[13] = out[13]; tmp[14] = out[14]; tmp[15] = out[15];

    int i = 0;
    for (; i < 4; out += 4, ++i) {
        float *restrict itr = tmp;
        int j = 0;
        for (; j < 4; itr += 4, ++j)
            out[j] = itr[i];
    }
}
