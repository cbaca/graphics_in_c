#include "test.h"
#include <stdlib.h>
#include <stdint.h>

#define ALL_PASS        0x0000
#define TEST_CPY        0x0001
#define TEST_CONSTRUCT  0x0002
#define TEST_SET        0x0004
#define TEST_INIT       0x0008
#define TEST_ADD        0x0010
#define TEST_SUB        0x0020
#define TEST_NEGATE     0x0040
#define TEST_MUL        0x0080
#define TEST_DIV        0x0100
#define TEST_ADD_SCALAR 0x0200
#define TEST_MUL_SCALAR 0x0400
#define TEST_DIV_SCALAR 0x0800
#define TEST_NORMALIZE  0x1000
#define TEST_DOT        0x2000
#define TEST_CROSS      0x4000
#define TEST_LENGTH     0x8000
#define TEST_COPY_MUL_SCALAR 0x10000
#define TEST_COPY_ADD   0x20000
#define TEST_COPY_SUB   0x40000
#define TEST_COPY_CROSS 0x80000
#define TEST_EQUIV      0x100000
#define TEST_POINT_IN_SPHERE 0x100000
#define TEST_ALL        0xffffffff

const char *test_strings[] = { "All passed", "VEC3CPY", "VEC3_CONSTRUCT", "VEC3_SET", "VEC3_INIT",
                            "VEC3_ADD", "VEC3_SUB", "VEC3_NEGATE", "VEC3_MUL", "VEC3_DIV", "VEC3_ADD_SCALAR",
                            "VEC3_MUL_SCALAR", "VEC3_DIV_SCALAR", "VEC3_NORMALIZE", "VEC3_DOT", "VEC3_CROSS",
                            "VEC3_LENGTH", "VEC3_COPY_MUL_SCALAR", "VEC3_COPY_ADD", "VEC3_COPY_SUB",
                            "VEC3_COPY_CROSS", "VEC3_EQUIV" };
void test_query(uint64_t tst)
{
    size_t num_errors = 0;
    size_t error_list[32];
    if (tst & TEST_CPY)
        error_list[num_errors++] = 1;
    if (tst & TEST_CONSTRUCT)
        error_list[num_errors++] = 2;
    if (tst & TEST_SET)
        error_list[num_errors++] = 3;
    if (tst & TEST_INIT)
        error_list[num_errors++] = 4;
    if (tst & TEST_ADD)
        error_list[num_errors++] = 5;
    if (tst & TEST_SUB)
        error_list[num_errors++] = 6;
    if (tst & TEST_NEGATE)
        error_list[num_errors++] = 7;
    if (tst & TEST_MUL)
        error_list[num_errors++] = 8;
    if (tst & TEST_DIV)
        error_list[num_errors++] = 9;
    if (tst & TEST_ADD_SCALAR)
        error_list[num_errors++] = 10;
    if (tst & TEST_MUL_SCALAR)
        error_list[num_errors++] = 11;
    if (tst & TEST_DIV_SCALAR)
        error_list[num_errors++] = 12;
    if (tst & TEST_NORMALIZE)
        error_list[num_errors++] = 13;
    if (tst & TEST_DOT)
        error_list[num_errors++] = 14;
    if (tst & TEST_CROSS)
        error_list[num_errors++] = 15;
    if (tst & TEST_LENGTH)
        error_list[num_errors++] = 16;
    if (tst & TEST_COPY_MUL_SCALAR)
        error_list[num_errors++] = 17;
    if (tst & TEST_COPY_ADD)
        error_list[num_errors++] = 18;
    if (tst & TEST_COPY_SUB)
        error_list[num_errors++] = 19;
    if (tst & TEST_COPY_CROSS)
        error_list[num_errors++] = 20;
    if (tst & TEST_EQUIV)
        error_list[num_errors++] = 21;
    if (tst & TEST_POINT_IN_SPHERE)
        error_list[num_errors++] = 22;

    printf("Failed tests:\n");
    size_t i;
    for (i = 0; i < num_errors; ++i)
        printf("%s\n", test_strings[error_list[i]]);
}

int main(void)
{
    uint64_t failed = ALL_PASS;
    uint64_t curtest = TEST_CPY;
    if (!test_cpy())
        failed |= curtest;
    curtest <<= 1;
    if (!test_construct())
        failed |= curtest;
    curtest <<= 1;
    if (!test_set())
        failed |= curtest;
    curtest <<= 1;
    if (!test_init())
        failed |= curtest;
    curtest <<= 1;
    if (!test_add())
        failed |= curtest;
    curtest <<= 1;
    if (!test_sub())
        failed |= curtest;
    curtest <<= 1;
    if (!test_negate())
        failed |= curtest;
    curtest <<= 1;
    if (!test_mul())
        failed |= curtest;
    curtest <<= 1;
    if (!test_div())
        failed |= curtest;
    curtest <<= 1;
    if (!test_add_scalar())
        failed |= curtest;
    curtest <<= 1;
    if (!test_mul_scalar())
        failed |= curtest;
    curtest <<= 1;
    if (!test_div_scalar())
        failed |= curtest;
    curtest <<= 1;
    if (!test_normalize())
        failed |= curtest;
    curtest <<= 1;
    if (!test_dot())
        failed |= curtest;
    curtest <<= 1;
    if (!test_cross())
        failed |= curtest;
    curtest <<= 1;
    if (!test_length())
        failed |= curtest;
    curtest <<= 1;
    if (!test_copy_mul_scalar())
        failed |= curtest;
    curtest <<= 1;
    if (!test_copy_add())
        failed |= curtest;
    curtest <<= 1;
    if (!test_copy_sub())
        failed |= curtest;
    curtest <<= 1;
    if (!test_copy_cross())
        failed |= curtest;
    curtest <<= 1;
    if (!test_equiv())
        failed |= curtest;
    curtest <<= 1;
    if (!test_point_in_sphere())
        failed |= curtest;

    if (failed != 0) {
        test_query(failed);
        return EXIT_FAILURE;
    }
    printf("All tests passed\n");
    return EXIT_SUCCESS;
}
