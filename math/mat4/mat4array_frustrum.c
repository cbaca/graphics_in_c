/**
 * @file mat4array_frustrum.c
 */

void mat4array_get_frustrum(
      float *restrict out
    , float left
    , float right
    , float top
    , float bottom
    , float near
    , float far)
{
    float dz = right - left;
    float dy = top - bottom;
    float dx = far - near;

    out[ 0] =  2.0f * near / dz;
    /* out[ 1] =  0.0f; */
    /* out[ 2] =  0.0f; */
    /* out[ 3] =  0.0f; */
    /* out[ 4] =  0.0f; */
    out[ 5] =  2.0f * near / dy;
    /* out[ 6] =  0.0f; */
    /* out[ 7] =  0.0f; */
    out[ 8] =  (right + left) / dz;
    out[ 9] =  (top + bottom) / dy;
    out[10] = -(far + near) / dx;
    out[11] = -1;
    /* out[12] =  0.0f; */
    /* out[13] =  0.0f; */
    out[14] = -(2 * far * near) / dx;
    /* out[15] =  1.0f; */
}
