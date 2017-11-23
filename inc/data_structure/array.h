#ifndef ARRAY_H
#define ARRAY_H
#include "types.h"

#define ARRAY_ERROR(x) exit((x))
#define ARRAY_END(array) ((byte *)array->load + (array->cur_len * array->data_size))

/**
 *
 */
void array_init(struct array *a, size_t len, size_t data_size);

/**
 *
 */
void array_add_capacity(struct array *a, size_t amount);

/**
 *
 */
void array_copy(struct array *dest, struct array *src);

/**
 *
 */
void array_concat(struct array *dest, struct array *src);

/**
 *
 */
void array_push_back(struct array *a, const void *const data);

/**
 *
 */
void array_push_back_x(struct array *a, const void *const data, const size_t len);

/**
 *
 */
void *array_get_ptr_to_index(struct array *a, size_t index);

/**
 *
 */
void *array_get_ptr(struct array *a);

/**
 *
 */
void array_finalize(struct array *a);

#define array_append(aptr, data) \
({ \
    if (aptr->cur_len > a->max_len) \
        _array_resize(aptr); \
    ((typeof(data) *)aptr->load)[aptr->cur_len++] = data; \
})

#endif /* ARRAY_H */
