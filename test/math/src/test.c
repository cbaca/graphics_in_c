#include "test.h"
#include "Mat4.h"
#include "Vec3.h"
#include "vec3.h"

#define A0  21.64f
#define A1   2.00f
#define B0  64.32f
#define B1 122.49f
#define C0 323.32f
#define C1  43.40f

DECLARE_TEST_FUNC_1(cpy, vec3_cpy, vec3copy)
DECLARE_TEST_FUNC_1(negate, vec3_negate, vec3negate)
DECLARE_TEST_FUNC_1(normalize, vec3_normalize, vec3normalize)
DECLARE_TEST_FUNC_1(length, vec3_length, vec3length)
DECLARE_TEST_FUNC_2(set, vec3_set, vec3set)
DECLARE_TEST_FUNC_2(add, vec3_add, vec3add)
DECLARE_TEST_FUNC_2(sub, vec3_sub, vec3sub)
DECLARE_TEST_FUNC_2(mul, vec3_mul, vec3mul)
DECLARE_TEST_FUNC_2(div, vec3_div, vec3div)
DECLARE_TEST_FUNC_2(cross, vec3_cross, vec3cross)
DECLARE_TEST_FUNC_2(copy_add, vec3_copy_add, vec3copyAdd)
DECLARE_TEST_FUNC_2(copy_sub, vec3_copy_sub, vec3copySub)
DECLARE_TEST_FUNC_2(dot, vec3_dot, vec3dot)
DECLARE_TEST_FUNC_2(copy_cross, vec3_copy_cross, vec3copyCross)
DECLARE_TEST_FUNC_2(equiv, vec3_equiv, vec3equiv)
DECLARE_TEST_FUNC_FL(add_scalar, vec3_add_scalar, vec3addScalar)
DECLARE_TEST_FUNC_FL(mul_scalar, vec3_mul_scalar, vec3mulScalar)
DECLARE_TEST_FUNC_FL(div_scalar, vec3_div_scalar, vec3divScalar)
DECLARE_TEST_FUNC_FL(copy_mul_scalar, vec3_copy_mul_scalar, vec3copyMulScalar)

/**
 *  Vec3 copy
 */
/*
*/
int test_cpy(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    const Vec3 vc0 = vec3copy(&v0);
    const Vec3 vc1 = vec3copy(&v1);
    const Vec3 va0 = vec3_cpy(&v0);
    const Vec3 va1 = vec3_cpy(&v1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("orig0:", &v0);
        vec3printf("vc0:  ", &vc0);
        vec3printf("va0:  ", &va0);
        vec3printf("orig1:", &v1);
        vec3printf("vc1:  ", &vc1);
        vec3printf("va1:  ", &va1);

        fprintf(stderr, "copies not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 cpy test:\n");
    print_speed("asm", 6, _test_cpy_asm(&v0));
    print_speed("c  ", 6, _test_cpy_c(&v0));
    printf("\n");
#endif
    return 1;
}

/**
 * vec3 construct
 */
static testtime_t _test_construct_asm(const float x, const float y, const float z)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_construct(x, y, z);
    return get_end_time(start);
}

static testtime_t _test_construct_c(const float x, const float y, const float z)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3construct(x, y, z);
    return get_end_time(start);
}

int test_construct(void)
{
    const Vec3 vc0 = vec3construct(A0, B0, C0);
    const Vec3 vc1 = vec3construct(A1, B1, C1);
    const Vec3 va0 = vec3_construct(A0, B0, C0);
    const Vec3 va1 = vec3_construct(A1, B1, C1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        printf("Vec3 construct test\n");
        printf("orig0: %f %f %f\n", A0, B0, C0);
        printf("orig1: %f %f %f\n", A1, B1, C1);
        vec3printf("c  : ", &vc0);
        vec3printf("asm: ", &va0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 construct test\n");
    print_speed("asm", 3, _test_construct_asm(A0, B0, C0));
    print_speed("c  ", 3, _test_construct_c(A0, B0, C0));
    printf("\n");
#endif
    return 1;
}

/**
 * vec3_set test
 */
 /*
 */
int test_set(void)
{
    const Vec3 orig0 = vec3_construct(A0, B0, C0);
    const Vec3 orig1 = vec3_construct(A1, B1, C1);
    Vec3 vc0, vc1;
    Vec3 va0, va1;
    vec3set(&vc0, &orig0);
    vec3set(&vc1, &orig1);
    vec3_set(&va0, &orig0);
    vec3_set(&va1, &orig1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("orig:", &orig0);
        vec3printf("c  : ", &vc0);
        vec3printf("asm: ", &va0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 set test\n");
    print_speed("asm", 6, _test_set_asm(&va0, &orig0));
    print_speed("c  ", 6, _test_set_c(&vc0, &orig0));
    printf("\n");
#endif
    return 1;
}

/**
 * Test init
 */
static testtime_t _test_init_asm_speed(Vec3 *dest, const float x, const float y, const float z)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_init(dest, x, y, z);
    return get_end_time(start);
}

static testtime_t _test_init_c_speed(Vec3 *dest, const float x, const float y, const float z)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3init(dest, x, y, z);
    return get_end_time(start);
}

int test_init(void)
{
    Vec3 vc0, vc1;
    Vec3 va0, va1;
    vec3init(&vc0, A0, B0, C0);
    vec3init(&vc1, A1, B1, C1);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        const Vec3 orig0 = vec3_construct(A0, B0, C0);
        vec3printf("orig:", &orig0);
        vec3printf("c  : ", &vc0);
        vec3printf("asm: ", &va0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 init test\n");
    print_speed("asm", 3, _test_init_asm_speed(&va0, A0, B0, C0));
    print_speed("c  ", 3, _test_init_c_speed(&vc0, A0, B0, C0));
    printf("\n");
#endif
    return 1;
}

/**
 * Test add
 */
/*
*/
int test_add(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3add(&vc0, &v0);
    vec3add(&vc1, &v1);
    vec3_add(&va0, &v0);
    vec3_add(&va1, &v1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 add test\n");
    print_speed("asm", 6, _test_add_asm(&va0, &v0));
    print_speed("c  ", 6, _test_add_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * test sub
 */
/*
*/
int test_sub(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3sub(&vc0, &v0);
    vec3sub(&vc1, &v1);
    vec3_sub(&va0, &v0);
    vec3_sub(&va1, &v1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 sub test\n");
    print_speed("asm", 6, _test_sub_asm(&va0, &v0));
    print_speed("c  ", 6, _test_sub_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * test negate
 */
/*
*/
int test_negate(void)
{
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, -A0, B0, -C0);
    vec3_init(&va0, -A0, B0, -C0);
    vec3_init(&vc1, A1, -B1, C1);
    vec3_init(&va1, A1, -B1, C1);

    vec3negate(&vc0);
    vec3negate(&vc1);
    vec3_negate(&va0);
    vec3_negate(&va1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        const Vec3 v0 = vec3construct(A0, B0, C0);
        vec3printf("orig:", &v0);
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 negate test\n");
    print_speed("asm", 6, _test_negate_asm(&va0));
    print_speed("c  ", 6, _test_negate_c(&vc0));
    printf("\n");
#endif
    return 1;
}

/**
 * test mul
 */
 /*
*/
int test_mul(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3mul(&vc0, &v0);
    vec3mul(&vc1, &v1);
    vec3_mul(&va0, &v0);
    vec3_mul(&va1, &v1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 mul test\n");
    print_speed("asm", 6, _test_mul_asm(&va0, &v0));
    print_speed("c  ", 6, _test_mul_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * test div
 */
/*
*/
int test_div(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3div(&vc0, &v0);
    vec3div(&vc1, &v1);
    vec3_div(&va0, &v0);
    vec3_div(&va1, &v1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 div test\n");
    print_speed("asm", 6, _test_div_asm(&va0, &v0));
    print_speed("c  ", 6, _test_div_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * Test add scalar
 */
/*
*/
int test_add_scalar(void)
{
    const float s = C0;
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3addScalar(&vc0, s);
    vec3addScalar(&vc1, s);
    vec3_add_scalar(&va0, s);
    vec3_add_scalar(&va1, s);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 add scalar test\n");
    print_speed("asm", 6, _test_add_scalar_asm(&va0, s));
    print_speed("c  ", 6, _test_add_scalar_c(&va0, s));
    printf("\n");
#endif
    return 1;
}

/**
 * Test mul scalar
 */
 /*
 */
int test_mul_scalar(void)
{
    const float s = C0;
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3mulScalar(&vc0, s);
    vec3mulScalar(&vc1, s);
    vec3_mul_scalar(&va0, s);
    vec3_mul_scalar(&va1, s);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 mul scalar test\n");
    print_speed("asm", 6, _test_mul_scalar_asm(&va0, s));
    print_speed("c  ", 6, _test_mul_scalar_c(&va0, s));
    printf("\n");
#endif
    return 1;
}

/**
 * Test vec3  div scalar
 */
 /*
 */
int test_div_scalar(void)
{
    const float s = C0;
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3divScalar(&vc0, s);
    vec3divScalar(&vc1, s);
    vec3_div_scalar(&va0, s);
    vec3_div_scalar(&va1, s);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 div scalar test\n");
    print_speed("asm", 6, _test_div_scalar_asm(&va0, s));
    print_speed("c  ", 6, _test_div_scalar_c(&va0, s));
    printf("\n");
#endif
    return 1;
}

/**
 * Test Vec3 normalize
 */
/*
*/
int test_normalize(void)
{
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    vec3_init(&vc0, A0, B0, C0);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);
    vec3_init(&vc1, A1, B1, C1);

    vec3normalize(&vc0);
    vec3normalize(&vc1);
    vec3_normalize(&va0);
    vec3_normalize(&va1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm: ", &va0);
        vec3printf("c  : ", &vc0);
        vec3printf("asm: ", &va1);
        vec3printf("c  : ", &vc1);
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    printf("Vec3 normalize test\n");
    print_speed("asm", 6, _test_normalize_asm(&va0));
    print_speed("c  ", 6, _test_normalize_c(&va0));
    printf("\n");
#endif
    return 1;
}

/**
 * test dot
 */
/*
*/
int test_dot(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    float c = vec3dot(&v0, &v1);
    float a = vec3_dot(&v0, &v1);

    if (a != c) {
        printf("asm: %f\n", a);
        printf("c  : %f\n", c);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 dot test\n");
    print_speed("asm", 6, _test_dot_asm(&v0, &v1));
    print_speed("c  ", 6, _test_dot_c(&v0, &v1));
    printf("\n");
#endif
    return 1;
}

/**
 * test cross
 */
/*
*/
int test_cross(void)
{
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    va0 = vc0 = vec3construct(A0, B0, C0);
    va1 = vc1 = vec3construct(A1, B1, C1);

    vec3cross(&vc0, &vc1);
    vec3_cross(&va0, &va1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm", &va0);
        vec3printf("c  ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 cross test\n");
    print_speed("asm", 6, _test_cross_asm(&va0, &va1));
    print_speed("c  ", 6, _test_cross_c(&vc0, &vc1));
    printf("\n");
#endif
    return 1;
}

/**
 * test length
 */
/*
*/
int test_length(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    float c0 = vec3length(&v0);
    float c1 = vec3length(&v1);
    float a0 = vec3_length(&v0);
    float a1 = vec3_length(&v1);
    if ((a0 != c0) || (a1 != c1)) {
        printf("asm: %f\n", a0);
        printf("c  : %f\n", c0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 length test\n");
    print_speed("asm", 6, _test_length_asm(&v0));
    print_speed("c  ", 6, _test_length_c(&v1));
    printf("\n");
#endif
    return 1;
}

/**
 * test copy mul scalar
 */
/*
*/
int test_copy_mul_scalar(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    const float s = C0;

    Vec3 c0 = vec3copyMulScalar(&v0, s);
    Vec3 c1 = vec3copyMulScalar(&v1, s);
    Vec3 a0 = vec3_copy_mul_scalar(&v0, s);
    Vec3 a1 = vec3_copy_mul_scalar(&v1, s);

    if (!vec3equiv(&a0, &c0) || !vec3equiv(&a1, &c1)) {
        vec3printf("asm", &a0);
        vec3printf("c  ", &c0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 copy_mul_scalar test\n");
    print_speed("asm", 4, _test_copy_mul_scalar_asm(&v0, s));
    print_speed("c  ", 4, _test_copy_mul_scalar_c(&v1, s));
    printf("\n");
#endif
    return 1;
}

/**
 * test copy add
 */
/*
*/
int test_copy_add(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    Vec3 c0 = vec3copyAdd(&v0, &v0);
    Vec3 c1 = vec3copyAdd(&v0, &v1);
    Vec3 a0 = vec3_copy_add(&v0, &v0);
    Vec3 a1 = vec3_copy_add(&v0, &v1);

    if (!vec3equiv(&a0, &c0) || !vec3equiv(&a1, &c1)) {
        vec3printf("asm", &a0);
        vec3printf("c  ", &c0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 copy_add test\n");
    print_speed("asm", 4, _test_copy_add_asm(&v0, &v1));
    print_speed("c  ", 4, _test_copy_add_c(&v0, &v1));
    printf("\n");
#endif
    return 1;
}

/**
 * test copy sub
 */
/*
*/
int test_copy_sub(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    Vec3 c0 = vec3copySub(&v0, &v0);
    Vec3 c1 = vec3copySub(&v0, &v1);
    Vec3 a0 = vec3_copy_sub(&v0, &v0);
    Vec3 a1 = vec3_copy_sub(&v0, &v1);

    if (!vec3equiv(&a0, &c0) || !vec3equiv(&a1, &c1)) {
        vec3printf("asm", &a0);
        vec3printf("c  ", &c0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 copy_sub test\n");
    print_speed("asm", 4, _test_copy_sub_asm(&v0, &v1));
    print_speed("c  ", 4, _test_copy_sub_c(&v0, &v1));
    printf("\n");
#endif
    return 1;
}

/**
 * test copy_cross
 */
/*
*/
int test_copy_cross(void)
{
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    va0 = vc0 = vec3construct(A0, B0, C0);
    va1 = vc1 = vec3construct(A1, B1, C1);

    vc0 = vec3copyCross(&vc0, &vc1);
    va0 = vec3_copy_cross(&va0, &va1);

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        vec3printf("asm", &va0);
        vec3printf("c  ", &vc0);
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 copy_cross test\n");
    print_speed("asm", 6, _test_copy_cross_asm(&va0, &va1));
    print_speed("c  ", 6, _test_copy_cross_c(&vc0, &vc1));
    printf("\n");
#endif
    return 1;
}

/**
 * test vec3 quivalence
 */
/*
*/
int test_equiv(void)
{
    Vec3 v[15];
    Vec3 u[15];
    int i;
    for (i = 0; i < 15; ++i)
        v[i] = u[i] = vec3construct((float)i, (float)i, (float)i);

    Vec3 x = vec3construct(A0, B0, C0);

    for (i = 0; i < 15; ++i)
        if (vec3_equiv(&v[i], &x))
                goto printandleave;

    for (i = 0; i < 15; ++i)
        if (vec3equiv(&v[i], &x))
                goto printandleave;

    for (i = 0; i < 15; ++i)
        if (!vec3_equiv(&v[i], &u[i]))
                goto printandleave;

    for (i = 0; i < 15; ++i)
        if (!vec3equiv(&v[i], &u[i]))
                goto printandleave;

#ifdef TEST_VERBOSE
    printf("Vec3 equiv test\n");
    print_speed("asm", 6, _test_equiv_asm(&v[0], &u[0]));
    print_speed("c  ", 6, _test_equiv_c(&v[1], &u[1]));
    printf("\n");
#endif
    return 1;

    printandleave:
    fprintf(stderr, "not equal!\n");
    return 0;
}

/**
 * test vec3 point in sphere
 */
#ifdef TEST_VERBOSE
static testtime_t _test_point_in_sphere_asm(const Vec3 *v0, const Vec3 *v1, const float radius)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_point_in_sphere(v0, v1, radius);
    return get_end_time(start);
}

static testtime_t _test_point_in_sphere_c(const Vec3 *v0, const Vec3 *v1, const float radius)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        pointInSphere(v0, v1, radius);
    return get_end_time(start);
}
#endif

int test_point_in_sphere(void)
{
    Vec3 pt[10];
    int i;
    for (i = 0; i < 10; ++i)
        pt[i] = vec3construct((float)i+10.f, (float)i+10.f, (float)i+10.f);

    float r = 0.001f;
    Vec3 s = vec3construct(0.0f, 0.0f, 0.0f);

    for (i = 0; i < 10; ++i)
        if (vec3_point_in_sphere(&pt[i], &s,  r))
            goto exitfailed;

    for (i = 0; i < 10; ++i)
        if (pointInSphere(&pt[i], &s, r))
            goto exitfailed;

    for (i = 0; i < 10; ++i)
        pt[i] = vec3construct((float)i, (float)i, (float)i);
    r = 20.0f;

    for (i = 0; i < 10; ++i)
        if (!vec3_point_in_sphere(&pt[i], &s, r))
            goto exitfailed;

    for (i = 0; i < 10; ++i)
        if (!pointInSphere(&pt[i], &s, r))
            goto exitfailed;


#ifdef TEST_VERBOSE
    printf("Vec3 point_in_sphere test\n");
    print_speed("asm", 6, _test_point_in_sphere_asm(&pt[0], &pt[1], r));
    print_speed("c  ", 6, _test_point_in_sphere_c(&pt[2], &pt[3], r));
    printf("\n");
#endif
    return 1;

    exitfailed:
    printf("Vec3 point_in_sphere test\n");
    fprintf(stderr, "not equal!\n");
    return 0;
}
