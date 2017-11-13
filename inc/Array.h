#ifndef MULT_ARRAY_H
#define MULT_ARRAY_H
#include <stdlib.h>

typedef enum arraydata_t {
    ARRAY_FLOAT,
    ARRAY_UNSIGNED_INT,
} arraydata_t;

typedef struct Array {
    arraydata_t dataType;
    size_t max_len;
    size_t cur_len;
    size_t data_size;
    void *data;
} Array;

Array *new_array(size_t start_len, arraydata_t dataType) __attribute__ ((malloc));
Array *cpy_array(Array *dest, const Array *const src);
Array *cat_array(Array *dest, const Array *const src);

size_t append_array(Array *a, const void *const data);
size_t append_arrayV3(Array *a, const void *const data);
size_t append_arrayVx(Array *a, const void *const data, size_t len);

float *get_array_data_float(Array *a, size_t *len);
unsigned int *get_array_data_uint(Array *a, size_t *len);
void *get_ptr_at_index(Array *a, const size_t index);

void destroy_array(Array *a);

void printArray(Array *a, const char *c, size_t stride);
#endif // MULT_ARRAY_H
