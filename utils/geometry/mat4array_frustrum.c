/** mat4array_frustrum.c */

void
mat4array_get_frustrum(
      float *restrict out
    , float left
    , float right
    , float top
    , float bottom
    , float near
    , float far)
{
    out[ 0] = 2.0f * near / (right - left);
    out[ 5] = 2.0f * near / (top - bottom);
    out[ 8] = (right + left) / (right - left);
    out[ 9] = (top + bottom) / (top - bottom);
    out[10] = - (far + near) / (far - near);
    out[11] = -1;
    out[14] = - (2 * far * near) / (far - near);
}
