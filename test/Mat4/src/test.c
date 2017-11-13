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

/**
 * test cpy
 */
#ifdef TEST_VERBOSE
static testtime_t _test_cpy_asm(const Vec3 *v0)
{
    const testtime_t start = get_start_time();
    size_t i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_cpy(v0);
    return get_end_time(start);
}

static testtime_t _test_cpy_c(const Vec3 *v0)
{
    const testtime_t start = get_start_time();
    size_t i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3copy(v0);
    return get_end_time(start);
}
#endif

int test_cpy(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    const Vec3 vc0 = vec3copy(&v0);
    const Vec3 vc1 = vec3copy(&v1);
    const Vec3 va0 = vec3_cpy(&v0);
    const Vec3 va1 = vec3_cpy(&v1);

#ifdef TEST_VERBOSE
    printf("Vec3 cpy test:\n");
    vec3printf("orig0:", &v0);
    vec3printf("vc0:  ", &vc0);
    vec3printf("va0:  ", &va0);
    vec3printf("orig1:", &v1);
    vec3printf("vc1:  ", &vc1);
    vec3printf("va1:  ", &va1);
#endif

    if (!vec3equiv(&vc0, &va0)) {
        fprintf(stderr, "c copies not equal!\n");
        return 0;
    }
    if (!vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "asm copies not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_cpy_asm(&v0));
    print_speed("c  ", 6, _test_cpy_c(&v0));
    printf("\n");
#endif
    return 1;
}

/**
 * vec3 construct
 */
#ifdef TEST_VERBOSE
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
#endif

int test_construct(void)
{
    const Vec3 vc0 = vec3construct(A0, B0, C0);
    const Vec3 vc1 = vec3construct(A1, B1, C1);
    const Vec3 va0 = vec3_construct(A0, B0, C0);
    const Vec3 va1 = vec3_construct(A1, B1, C1);

#ifdef TEST_VERBOSE
    printf("Vec3 construct test\n");
    printf("orig0: %f %f %f\n", A0, B0, C0);
    printf("orig1: %f %f %f\n", A1, B1, C1);
    vec3printf("c  : ", &vc0);
    vec3printf("asm: ", &va0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    print_speed("asm", 3, _test_construct_asm(A0, B0, C0));
    print_speed("c  ", 3, _test_construct_c(A0, B0, C0));
    printf("\n");
#endif
    return 1;
}

/**
 * test set
 */
#ifdef TEST_VERBOSE
static testtime_t _test_set_asm(Vec3 *dest, const Vec3 *src)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_set(dest, src);
    return get_end_time(start);
}

static testtime_t _test_set_c(Vec3 *dest, const Vec3 *src)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3set(dest, src);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 set test\n");
    vec3printf("orig:", &orig0);
    vec3printf("c  : ", &vc0);
    vec3printf("asm: ", &va0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_set_asm(&va0, &orig0));
    print_speed("c  ", 6, _test_set_c(&vc0, &orig0));
    printf("\n");
#endif
    return 1;
}

/**
 * Test init
 */
#ifdef TEST_VERBOSE
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
#endif

int test_init(void)
{
    Vec3 vc0, vc1;
    Vec3 va0, va1;
    vec3init(&vc0, A0, B0, C0);
    vec3init(&vc1, A1, B1, C1);
    vec3_init(&va0, A0, B0, C0);
    vec3_init(&va1, A1, B1, C1);

#ifdef TEST_VERBOSE
    const Vec3 orig0 = vec3_construct(A0, B0, C0);
    printf("Vec3 init test\n");
    vec3printf("orig:", &orig0);
    vec3printf("c  : ", &vc0);
    vec3printf("asm: ", &va0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 3, _test_init_asm_speed(&va0, A0, B0, C0));
    print_speed("c  ", 3, _test_init_c_speed(&vc0, A0, B0, C0));
    printf("\n");
#endif
    return 1;
}

/**
 * Test add
 */
#ifdef TEST_VERBOSE
static testtime_t _test_add_asm(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_add(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_add_c(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3add(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 add test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_add_asm(&va0, &v0));
    print_speed("c  ", 6, _test_add_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * test sub
 */
#ifdef TEST_VERBOSE
static testtime_t _test_sub_asm(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_sub(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_sub_c(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3sub(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 sub test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_sub_asm(&va0, &v0));
    print_speed("c  ", 6, _test_sub_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * test negate
 */
#ifdef TEST_VERBOSE
static testtime_t _test_negate_asm(Vec3 *v0)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_negate(v0);
    return get_end_time(start);
}

static testtime_t _test_negate_c(Vec3 *v0)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3negate(v0);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    const Vec3 v0 = vec3construct(A0, B0, C0);
    printf("Vec3 negate test\n");
    vec3printf("orig:", &v0);
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_negate_asm(&va0));
    print_speed("c  ", 6, _test_negate_c(&vc0));
    printf("\n");
#endif
    return 1;
}

/**
 * test mul
 */
#ifdef TEST_VERBOSE
static testtime_t _test_mul_asm(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_mul(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_mul_c(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3mul(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 mul test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_mul_asm(&va0, &v0));
    print_speed("c  ", 6, _test_mul_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * test div
 */
#ifdef TEST_VERBOSE
static testtime_t _test_div_asm(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_div(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_div_c(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3div(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 div test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_div_asm(&va0, &v0));
    print_speed("c  ", 6, _test_div_c(&vc0, &v0));
    printf("\n");
#endif
    return 1;
}

/**
 * Test add scalar
 */
#ifdef TEST_VERBOSE
static testtime_t _test_add_scalar_asm(Vec3 *v0, const float v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_add_scalar(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_add_scalar_c(Vec3 *v0, const float v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3addScalar(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 add scalar test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif
    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_add_scalar_asm(&va0, s));
    print_speed("c  ", 6, _test_add_scalar_c(&va0, s));
    printf("\n");
#endif
    printf("\n");
    return 1;
}

/**
 * Test mul scalar
 */
#ifdef TEST_VERBOSE
static testtime_t _test_mul_scalar_asm(Vec3 *v0, const float v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_mul_scalar(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_mul_scalar_c(Vec3 *v0, const float v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3mulScalar(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 mul scalar test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif
    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_mul_scalar_asm(&va0, s));
    print_speed("c  ", 6, _test_mul_scalar_c(&va0, s));
    printf("\n");
#endif
    printf("\n");
    return 1;
}

/**
 * Test div scalar
 */
#ifdef TEST_VERBOSE
static testtime_t _test_div_scalar_asm(Vec3 *v0, const float v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_div_scalar(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_div_scalar_c(Vec3 *v0, const float v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3divScalar(v0, v1);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 div scalar test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
#endif
    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_div_scalar_asm(&va0, s));
    print_speed("c  ", 6, _test_div_scalar_c(&va0, s));
    printf("\n");
#endif
    printf("\n");
    return 1;
}

/**
 * Test Vec3 normalize
 */
#ifdef TEST_VERBOSE
static testtime_t _test_normalize_asm(Vec3 *v0)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_normalize(v0);
    return get_end_time(start);
}

static testtime_t _test_normalize_c(Vec3 *v0)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3normalize(v0);
    return get_end_time(start);
}
#endif

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

#ifdef TEST_VERBOSE
    printf("Vec3 normalize test\n");
    vec3printf("asm: ", &va0);
    vec3printf("c  : ", &vc0);
    vec3printf("asm: ", &va1);
    vec3printf("c  : ", &vc1);
#endif
    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }
#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_normalize_asm(&va0));
    print_speed("c  ", 6, _test_normalize_c(&va0));
    printf("\n");
#endif
    printf("\n");
    return 1;
}

/**
 * test dot
 */
#ifdef TEST_VERBOSE
static testtime_t _test_dot_asm(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_dot(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_dot_c(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3dot(v0, v1);
    return get_end_time(start);
}
#endif

int test_dot(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    float c = vec3dot(&v0, &v1);
    float a = vec3_dot(&v0, &v1);
    if (a != c) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    printf("Vec3 dot test\n");
    printf("asm: %f\n", a);
    printf("c  : %f\n", c);
    print_speed("asm", 6, _test_dot_asm(&v0, &v1));
    print_speed("c  ", 6, _test_dot_c(&v0, &v1));
    printf("\n");
#endif
    return 1;
}

/**
 * test cross
 */
#ifdef TEST_VERBOSE
static testtime_t _test_cross_asm(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_cross(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_cross_c(Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3cross(v0, v1);
    return get_end_time(start);
}
#endif

int test_cross(void)
{
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    va0 = vc0 = vec3construct(A0, B0, C0);
    va1 = vc1 = vec3construct(A1, B1, C1);

    vec3cross(&vc0, &vc1);
    vec3_cross(&va0, &va1);

#ifdef TEST_VERBOSE
    printf("Vec3 cross test\n");
    vec3printf("asm", &va0);
    vec3printf("c  ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_cross_asm(&va0, &va1));
    print_speed("c  ", 6, _test_cross_c(&vc0, &vc1));
    printf("\n");
#endif
    return 1;
}

/**
 * test length
 */
#ifdef TEST_VERBOSE
static testtime_t _test_length_asm(const Vec3 *v0)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_length(v0);
    return get_end_time(start);
}

static testtime_t _test_length_c(const Vec3 *v0)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3length(v0);
    return get_end_time(start);
}
#endif

int test_length(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    float c0 = vec3length(&v0);
    float c1 = vec3length(&v1);
    float a0 = vec3_length(&v0);
    float a1 = vec3_length(&v1);
#ifdef TEST_VERBOSE
    printf("Vec3 length test\n");
    printf("asm: %f\n", a0);
    printf("c  : %f\n", c0);
#endif
    if ((a0 != c0) || (a1 != c1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_length_asm(&v0));
    print_speed("c  ", 6, _test_length_c(&v1));
    printf("\n");
#endif
    return 1;
}


/**
 * test copy mul scalar
 */
#ifdef TEST_VERBOSE
static testtime_t _test_copy_mul_scalar_asm(const Vec3 *v0, const float s)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_copy_mul_scalar(v0, s);
    return get_end_time(start);
}

static testtime_t _test_copy_mul_scalar_c(const Vec3 *v0, const float s)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3copyMulScalar(v0, s);
    return get_end_time(start);
}
#endif

int test_copy_mul_scalar(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);
    const float s = C0;

    Vec3 c0 = vec3copyMulScalar(&v0, s);
    Vec3 c1 = vec3copyMulScalar(&v1, s);
    Vec3 a0 = vec3_copy_mul_scalar(&v0, s);
    Vec3 a1 = vec3_copy_mul_scalar(&v1, s);
#ifdef TEST_VERBOSE
    printf("Vec3 copy_mul_scalar test\n");
    vec3printf("asm", &a0);
    vec3printf("c  ", &c0);
#endif
    if (!vec3equiv(&a0, &c0) || !vec3equiv(&a1, &c1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 4, _test_copy_mul_scalar_asm(&v0, s));
    print_speed("c  ", 4, _test_copy_mul_scalar_c(&v1, s));
    printf("\n");
#endif
    return 1;
}


/**
 * test copy add
 */
#ifdef TEST_VERBOSE
static testtime_t _test_copy_add_asm(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_copy_add(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_copy_add_c(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3copyAdd(v0, v1);
    return get_end_time(start);
}
#endif

int test_copy_add(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    Vec3 c0 = vec3copyAdd(&v0, &v0);
    Vec3 c1 = vec3copyAdd(&v0, &v1);
    Vec3 a0 = vec3_copy_add(&v0, &v0);
    Vec3 a1 = vec3_copy_add(&v0, &v1);
#ifdef TEST_VERBOSE
    printf("Vec3 copy_add test\n");
    vec3printf("asm", &a0);
    vec3printf("c  ", &c0);
#endif
    if (!vec3equiv(&a0, &c0) || !vec3equiv(&a1, &c1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 4, _test_copy_add_asm(&v0, &v1));
    print_speed("c  ", 4, _test_copy_add_c(&v0, &v1));
    printf("\n");
#endif
    return 1;
}


/**
 * test copy sub
 */
#ifdef TEST_VERBOSE
static testtime_t _test_copy_sub_asm(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_copy_sub(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_copy_sub_c(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3copySub(v0, v1);
    return get_end_time(start);
}
#endif

int test_copy_sub(void)
{
    const Vec3 v0 = vec3construct(A0, B0, C0);
    const Vec3 v1 = vec3construct(A1, B1, C1);

    Vec3 c0 = vec3copySub(&v0, &v0);
    Vec3 c1 = vec3copySub(&v0, &v1);
    Vec3 a0 = vec3_copy_sub(&v0, &v0);
    Vec3 a1 = vec3_copy_sub(&v0, &v1);
#ifdef TEST_VERBOSE
    printf("Vec3 copy_sub test\n");
    vec3printf("asm", &a0);
    vec3printf("c  ", &c0);
#endif
    if (!vec3equiv(&a0, &c0) || !vec3equiv(&a1, &c1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 4, _test_copy_sub_asm(&v0, &v1));
    print_speed("c  ", 4, _test_copy_sub_c(&v0, &v1));
    printf("\n");
#endif
    return 1;
}

/**
 * test copy_cross
 */
#ifdef TEST_VERBOSE
static testtime_t _test_copy_cross_asm(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_copy_cross(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_copy_cross_c(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3copyCross(v0, v1);
    return get_end_time(start);
}
#endif

int test_copy_cross(void)
{
    Vec3 va0, va1;
    Vec3 vc0, vc1;
    va0 = vc0 = vec3construct(A0, B0, C0);
    va1 = vc1 = vec3construct(A1, B1, C1);

    vc0 = vec3copyCross(&vc0, &vc1);
    va0 = vec3_copy_cross(&va0, &va1);

#ifdef TEST_VERBOSE
    printf("Vec3 copy_cross test\n");
    vec3printf("asm", &va0);
    vec3printf("c  ", &vc0);
#endif

    if (!vec3equiv(&vc0, &va0) || !vec3equiv(&vc1, &va1)) {
        fprintf(stderr, "not equal!\n");
        return 0;
    }

#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_copy_cross_asm(&va0, &va1));
    print_speed("c  ", 6, _test_copy_cross_c(&vc0, &vc1));
    printf("\n");
#endif
    return 1;
}

/**
 * test vec3 quivalence
 */
#ifdef TEST_VERBOSE
static testtime_t _test_equiv_asm(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3_equiv(v0, v1);
    return get_end_time(start);
}

static testtime_t _test_equiv_c(const Vec3 *v0, const Vec3 *v1)
{
    const testtime_t start = get_start_time();
    int i;
    for (i = 0; i < TEST_COUNT; ++i)
        vec3equiv(v0, v1);
    return get_end_time(start);
}
#endif

int test_equiv(void)
{
    Vec3 v[15];
    Vec3 u[15];
    int i;
    for (i = 0; i < 15; ++i)
        v[i] = u[i] = vec3construct((float)i, (float)i, (float)i);

    Vec3 x = vec3construct(A0, B0, C0);
#ifdef TEST_VERBOSE
    printf("Vec3 equiv test\n");
#endif

    for (i = 0; i < 15; ++i)
        if (vec3_equiv(&v[i], &x)) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }

    for (i = 0; i < 15; ++i)
        if (vec3equiv(&v[i], &x)) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }

    for (i = 0; i < 15; ++i)
        if (!vec3_equiv(&v[i], &u[i])) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }

    for (i = 0; i < 15; ++i)
        if (!vec3equiv(&v[i], &u[i])) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }



#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_equiv_asm(&v[0], &u[0]));
    print_speed("c  ", 6, _test_equiv_c(&v[1], &u[1]));
    printf("\n");
#endif
    return 1;
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
#ifdef TEST_VERBOSE
    printf("Vec3 point_in_sphere test\n");
#endif

    for (i = 0; i < 10; ++i)
        if (vec3_point_in_sphere(&pt[i], &s,  r)) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }

    for (i = 0; i < 10; ++i)
        if (pointInSphere(&pt[i], &s, r)) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }

    for (i = 0; i < 10; ++i)
        pt[i] = vec3construct((float)i, (float)i, (float)i);
    r = 20.0f;

    for (i = 0; i < 10; ++i)
        if (!vec3_point_in_sphere(&pt[i], &s, r)) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }

    for (i = 0; i < 10; ++i)
        if (!pointInSphere(&pt[i], &s, r)) {
            fprintf(stderr, "not equal!\n");
            return 0;
        }



#ifdef TEST_VERBOSE
    print_speed("asm", 6, _test_point_in_sphere_asm(&pt[0], &pt[1], r));
    print_speed("c  ", 6, _test_point_in_sphere_c(&pt[2], &pt[3], r));
    printf("\n");
#endif
    return 1;
}
