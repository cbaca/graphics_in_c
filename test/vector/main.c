#include "vector.h"
#include <stdio.h>

DECLARE_VECTOR(float, float)

void vector_float_print(struct vector_float_t *v, const char *title, size_t stride)
{
    if (title)
        printf("%s: ", title);
    printf("%lu\n", v->cur_len);
    size_t i;
    float *ptr = v->load;
    for (i = 0; i < v->cur_len; i += stride) {
        size_t j;
        for (j = i; j < i + stride; ++j) {
            printf("%f ", *ptr++);
        }
        printf("\n");
    }
    printf("\n");
}


int main(void)
{
    struct vector_float_t vectorf;
    vector_float_init(&vectorf, 20);
    if (!vectorf.load)
        return 1;
    vector_float_append(&vectorf, 4.0f);
    vector_float_append(&vectorf, 5.0f);
    vector_float_append(&vectorf, 6.0f);
    vector_float_append(&vectorf, 7.0f);
    vector_float_append(&vectorf, 8.0f);
    vector_float_append(&vectorf, 9.0f);
    vector_float_append(&vectorf, 3.0f);
    vector_float_append(&vectorf, 12.0f);
    vector_float_append(&vectorf, 1.0f);

    float arr[3] = { 20.f, 21.f, 22.f };
    vector_float_append_x(&vectorf, arr, 3);
    vector_float_print(&vectorf, "floats", 3);
    return 0;
}
