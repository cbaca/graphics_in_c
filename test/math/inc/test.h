#ifndef VEC3_TEST_H
#define VEC3_TEST_H
#include "Geomath.h"
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

struct test_stats_t {
    char *func_name;
    clock_t asm_speed;
    clock_t c_speed;
    int passing_stats;
};

void print_speed(const char *msg, size_t len, testtime_t clk);
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

#define DECLARE_TEST_FUNC_FL(name, f0, f1)\
    clock_t _test_ ## name ## _asm(Vec3 *v0, float f)\
    {\
        const clock_t start = clock();\
        size_t i;\
        for (i = 0; i < TEST_COUNT; ++i)\
            f0(v0, f);\
        return clock() - start;\
    }\
    clock_t _test_ ## name ## _c(Vec3 *v0, float f)\
    {\
        const clock_t start = clock();\
        size_t i;\
        for (i = 0; i < TEST_COUNT; ++i)\
            f1(v0, f);\
        return clock() - start;\
    }

#define DECLARE_TEST_FUNC_2(name, f0, f1)\
    clock_t _test_ ## name ## _asm(Vec3 *v0, const Vec3 *v1)\
    {\
        const clock_t start = clock();\
        size_t i;\
        for (i = 0; i < TEST_COUNT; ++i)\
            f0(v0, v1);\
        return clock() - start;\
    }\
    clock_t _test_ ## name ## _c(Vec3 *v0, const Vec3 *v1)\
    {\
        const clock_t start = clock();\
        size_t i;\
        for (i = 0; i < TEST_COUNT; ++i)\
            f1(v0, v1);\
        return clock() - start;\
    }

#define DECLARE_TEST_FUNC_1(name, f0, f1)\
    clock_t _test_ ## name ## _asm(Vec3 *v0)\
    {\
        const clock_t start = clock();\
        size_t i;\
        for (i = 0; i < TEST_COUNT; ++i)\
            f0(v0);\
        return clock() - start;\
    }\
    clock_t _test_ ## name ## _c(Vec3 *v0)\
    {\
        const clock_t start = clock();\
        size_t i;\
        for (i = 0; i < TEST_COUNT; ++i)\
            f1(v0);\
        return clock() - start;\
    }

#endif /* VEC3_TEST_H */
