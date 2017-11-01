#ifndef MULT_ARRAY_H
#define MULT_ARRAY_H
#include <stdlib.h>

typedef enum ArrayData_t {
    ARRAY_FLOAT,
    ARRAY_UNSIGNED_INT,
} ArrayData_t;

typedef struct Array {
    ArrayData_t dataType;
    size_t max_len;
    size_t cur_len;
    size_t data_size;
    void *data;
} Array;

Array *new_array(size_t start_len, ArrayData_t dataType);
Array *cat_array(Array *dest, const Array *const src);
size_t append_array(Array *a, const void *const data);
size_t append_arrayV3(Array *a, const void *const data);
size_t append_arrayVx(Array *a, const void *const data, size_t len);
float *get_array_data_float(Array *a, size_t *len);
unsigned int *get_array_data_uint(Array *a, size_t *len);
void destroy_array(Array *a);
void printArray(Array *a, const char *c, size_t stride);
#endif // MULT_ARRAY_H
