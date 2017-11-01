#include "Array.h"
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

static void _adjust_arrayLen(Array *a);

Array *new_array(size_t start_len, ArrayData_t dataType)
{
    assert(sizeof(double) ==  sizeof(uint64_t));
    assert((sizeof(float) == sizeof(unsigned int)) == (sizeof(int) == sizeof(uint32_t)));

    start_len++;

    Array *a = malloc(sizeof(Array));
    if (!a) {
        fprintf(stderr, "Error allocating memory for Array *\n");
        return NULL;
    }
    a->dataType = dataType;
    a->max_len = start_len;
    a->cur_len = 0;

    switch (dataType) {
        case ARRAY_FLOAT:
        case ARRAY_UNSIGNED_INT:
            a->data_size = sizeof(uint32_t);
            a->data = malloc(a->data_size * start_len);
            break;
        default:
            return NULL;
    }
    return a;
}

void destroy_array(Array *a) { if (a) free(a->data), free(a); }

float *get_array_data_float(Array *a, size_t *len)
{
    *len = a->cur_len;
    float *ret = (float *)a->data;
    return ret;
}

unsigned int *get_array_data_uint(Array *a, size_t *len)
{
    *len = a->cur_len;
    unsigned int *ret = (unsigned int *)a->data;
    return ret;
}

size_t append_array(Array *a, const void *const data)
{
    uint32_t *d = (uint32_t *)a->data;
    d[a->cur_len++] = *(uint32_t *)data;
    if (a->max_len <= a->cur_len)
        _adjust_arrayLen(a);
    return a->cur_len;
}

size_t append_arrayV3(Array *a, const void *const data)
{
    if (a->max_len <= a->cur_len + 3)
        _adjust_arrayLen(a);
    uint32_t *ptr = ((uint32_t *)a->data) + a->cur_len;
    memcpy(ptr, data, a->data_size * 3);
    a->cur_len += 3;
    return a->cur_len;
}

size_t append_arrayVx(Array *a, const void *const data, size_t len)
{
    while (a->max_len <= a->cur_len + len)
        _adjust_arrayLen(a);
    uint32_t *ptr = ((uint32_t *)a->data) + a->cur_len;
    memcpy(ptr, data, a->data_size * len);
    a->cur_len += len;
    return a->cur_len;
}

Array *cat_array(Array *dest, const Array *const src)
{
    assert(dest->dataType == src->dataType);
    while (dest->max_len <= src->cur_len)
        _adjust_arrayLen(dest);

    uint32_t *d = ((uint32_t *)dest->data) + dest->cur_len;
    memcpy(d, src->data, src->cur_len * dest->data_size);
    dest->cur_len += src->cur_len;
    return dest;
}

void printArray(Array *a, const char *c, size_t stride)
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

static void _adjust_arrayLen(Array *a)
{
    a->max_len *= 2;
    uint32_t *tmp = realloc(a->data, a->max_len * a->data_size);
    a->data = tmp;
}
