#ifndef VEC3_TEST_H
#define VEC3_TEST_H
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TEST_COUNT 10000000
#define TEST_VERBOSE 1
/**
 * Test if dot product value is correct;
 * Compare speed of dot product calculations;
 * return 1 on success, 0 on failure.
 */
typedef clock_t testtime_t;

void print_speed(const char *msg, const size_t len, const testtime_t clk);
testtime_t get_start_time(void);
testtime_t get_end_time(const testtime_t start);
size_t get_time(const clock_t start);

int test_cpy(void);
int test_construct(void);
int test_set(void);
int test_init(void);
int test_add(void);
int test_sub(void);
int test_negate(void);
int test_mul(void);
int test_div(void);
int test_add_scalar(void);
int test_mul_scalar(void);
int test_div_scalar(void);
int test_normalize(void);
int test_dot(void);
int test_cross(void);
int test_length(void);
int test_copy_mul_scalar(void);
int test_copy_sub(void);
int test_copy_add(void);
int test_copy_cross(void);
int test_equiv(void);
int test_point_in_sphere(void);
#endif /* VEC3_TEST_H */
