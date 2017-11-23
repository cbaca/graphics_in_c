#include "array.h"
#include <assert.h>
#include <string.h>
#include <stdint.h>

#define _array_realloc(array) \
{ \
    void *tmp = realloc(array->load, array->max_len * array->data_size); \
    array->load = tmp; \
}

static inline void _array_resize(struct array *a)
{
    a->max_len *= 2;
    _array_realloc(a);
}

void array_init(struct array *a, size_t len, size_t data_size)
{
    if (len < 1)
        ARRAY_ERROR(EXIT_FAILURE);
    if (data_size % 2)
        ARRAY_ERROR(EXIT_FAILURE);
    if (data_size < sizeof(byte))
        ARRAY_ERROR(EXIT_FAILURE);
    a->load = malloc(data_size * len);
    a->cur_len = 0;
    a->data_size = data_size;
    a->max_len = len;
    assert(a->load);
}

void array_add_capacity(struct array *a, size_t amount)
{
    a->max_len += amount;
    _array_realloc(a);
}

void array_copy(struct array *dest, struct array *src)
{
    if (src->cur_len * src->data_size > dest->max_len * dest->data_size) {
        dest->max_len = src->cur_len;
        void *tmp = realloc(dest->load, dest->max_len * src->data_size);
        dest->load = tmp;
    }

    dest->data_size = src->data_size;
    dest->cur_len = src->cur_len;
    memcpy(dest->load, src->load, src->cur_len * src->data_size);
}

void array_concat(struct array *dest, struct array *src)
{
    while (src->cur_len > dest->max_len)
        _array_resize(dest);
    memcpy(ARRAY_END(dest), src->load, src->cur_len * src->data_size);
    dest->cur_len += src->cur_len;
}

void array_push_back(struct array *a, const void *const data)
{
    memcpy(ARRAY_END(a), data, a->data_size);
    a->cur_len++;
    if (a->cur_len > a->max_len)
        _array_resize(a);
}

void array_push_back_x(struct array *a, const void *const data, const size_t len)
{
    while (a->cur_len + len > a->max_len)
        _array_resize(a);

    memcpy(ARRAY_END(a), data, a->data_size * len);
    a->cur_len += len;
}

void *array_get_ptr_to_index(struct array *a, size_t index)
{
    if (a->cur_len < index)
        return nil;
    return (byte *)a->load + (a->data_size * index);
}

void *array_get_ptr(struct array *a)
{
    return a->load;
}

void array_finalize(struct array *a)
{
    free(a->load);
    a->load = nil;
}

/*
void array_print(Array *a, const char *c, size_t stride)
{
    if (c)
        printf("%s: %lu\n", c, a->cur_len);
    else
        printf("%lu\n", a->cur_len);
    if (a->dataType == ARRAY_FLOAT) {
        size_t i;
        float *ptr = (float *)a->data;
        for (i = 0; i < a->cur_len; i += stride) {
            size_t j;
            for (j = i; j < i + stride; ++j) {
                printf("%f ", *ptr++);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    if (a->dataType == ARRAY_UNSIGNED_INT) {
        size_t i;
        unsigned int *ptr = (unsigned int *)a->data;
        for (i = 0; i < a->cur_len; i += stride) {
            size_t j;
            for (j = i; j < i + stride; ++j) {
                printf("%u ", *ptr++);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
}
*/
