/** mat4array_scale.c */
/*   S_x  0   0   0
 *    0  S_y  0   0
 *    0   0  S_z  0
 *    0   0   0   1
 */
void
mat4array_get_scaled(float *restrict out, float x, float y, float z)
{
    out[ 0] = x;    out[ 1] = 0.0f; out[ 2] = 0.0f; out[ 3] = 0.0f;
    out[ 4] = 0.0f; out[ 5] = y;    out[ 6] = 0.0f; out[ 7] = 0.0f;
    out[ 8] = 0.0f; out[ 9] = 0.0f; out[10] = z;    out[11] = 0.0f;
    out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 1.0f;
}
