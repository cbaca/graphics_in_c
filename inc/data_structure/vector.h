#ifndef VECTOR_H
#define VECTOR_H
#include <stdlib.h>
#include <string.h>

#define DECLARE_VECTOR(prefix, type) \
    struct vector_ ## prefix ## _t { \
        type *load; \
        size_t cur_len, max_len; \
    }; \
    \
    static inline void _vector_ ## prefix ## _resize(struct vector_ ## prefix ## _t *v) \
    { \
        v->max_len *= 2; \
        type *tmp = realloc(v->load, v->max_len * sizeof(type)); \
        v->load = tmp; \
    } \
    \
    static inline void vector_ ## prefix ## _init(struct vector_ ## prefix ## _t *v, size_t hint) \
    { \
        if (hint < 1) \
            hint = 1; \
        v->load = malloc(sizeof(type) * hint); \
        v->cur_len = 0; \
        v->max_len = hint; \
    } \
    \
    static inline void vector_ ## prefix ## _append(struct vector_ ## prefix ## _t *v, type load) \
    { \
        v->load[v->cur_len++] = load; \
        if (v->cur_len > v->max_len) \
            _vector_ ## prefix ## _resize(v); \
    } \
    \
    static inline void vector_ ## prefix ## _append_x(struct vector_ ## prefix ## _t *v, type *load, size_t amount) \
    { \
        while (v->cur_len + amount > v->max_len) \
            _vector_ ## prefix ## _resize(v); \
        memcpy(v->load + v->cur_len, load, sizeof(type) * amount); \
        v->cur_len += amount; \
    } \
    \
    static inline void vector_ ## prefix ## _get_pointer_at_index(struct vector_ ## prefix ## _t *v, size_t index) \
    { \
        if (v->cur_len < index) \
            return NULL; \
        return v->load + index; \
    } \
    \
    static inline void vector_ ## prefix ## _concat(struct vector_ ## prefix ## _t *dest, struct vector_ ## prefix ## _t *src) \
    { \
        while (src->cur_len > dest->max_len) \
            _vector_ ## prefix ## _resie(dest); \
        memcpy(dest->load + dest->cur_len, src->load, src->cur_len * sizeof(type)); \
    }

#endif /* VECTOR_H */
