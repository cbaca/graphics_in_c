/*
 * The first six integer parameters are:
 *     rdi, rsi, rdx, rcx, r8, r9
 * The first eight floating point parameters are:
 *     xmm0 - xmm7
 * Return value registers:
 *     64: rax, rdx, xmm0, xmm1, ymm0, st(0), st(1)
 *     32: eax, edx, st(0)
 * Registers that can be used freely:
 *     64: rax, rcx, rdx, rsi, rdi, r8 - r11, st(0) - st(7), xmm0-xmm16, ymm0-ymm15
 *     32: eax, ecx, edx, st(0) - st(7), xmm0-xmm7, ymm0-ymm7
 * Registers that must be saved and restored:
 *     64: rbx, rbp, r12 - r15
 *     32: ebx, ebp, esi, edi
 */

    .intel_syntax noprefix

/**
 * Vec3 vec3_cpy(const Vec3 *src)
 *  src = rdi
 *  ret = xmm0, xmm1
 */
.global vec3_cpy
vec3_cpy:
    .cfi_startproc
    movaps xmm0, XMMWORD PTR [rdi]
    movss xmm1, DWORD PTR 8[rdi]
    ret
    .cfi_endproc
/**
 * Vec3 vec3_construct(const float x, const float y, const float z)
 */
.global vec3_construct
vec3_construct:
    .cfi_startproc
    movd    eax,  xmm0
    movd    edx,  xmm1
    movaps  xmm1, xmm2
    sal     rdx,  0x20
    mov     eax,  eax
    or      rax,  rdx
    mov     QWORD PTR -16[rsp], rax
    movq    xmm0, QWORD PTR -16[rsp]
    ret
    .cfi_endproc

/**
 * Vec3 *vec3set(Vec3 *dest, const Vec3 *src)
 *     dest = rdi
 *     src  = rsi
 *     ret  = rax
 */
.global vec3_set
vec3_set:
    .cfi_startproc
    movaps  xmm0, XMMWORD PTR [rsi]
    movaps  XMMWORD PTR [rdi], xmm0
    mov     rax, rdi
    ret                         # return dest
    .cfi_endproc

/**
 * Vec3 *vec3_init(Vec3 *dest, const float x, const float y, const float z)
 * rdi, xmm0, xmm1, xmm2
 * return rax
 */
.global vec3_init
vec3_init:
    .cfi_startproc
    movss   [rdi],     xmm0
    movss   [rdi + 4], xmm1
    movss   [rdi + 8], xmm2
    mov     rax, rdi
    ret
    .cfi_endproc

/**
 * Vec3 *vec3_add(Vec3 *dest, const Vec3 *src)
 * dest = rdi
 * sec  = rsi
 * ret  = rax
 */
.global vec3_add
vec3_add:
    .cfi_startproc
    movaps  xmm0, [rdi]
    movaps  xmm1, [rsi]
    addps   xmm0, xmm1
    movaps  [rdi], xmm0
    mov     rax, rdi
    ret
    .cfi_endproc

/**
 * Vec3 *vec3_sub(Vec3 *dest, const Vec3 *src)
 * dest = rdi
 * sec  = rsi
 * ret  = rax
 */
.global vec3_sub
vec3_sub:
    .cfi_startproc
    movaps  xmm0, [rdi]
    movaps  xmm1, [rsi]
    subps   xmm0, xmm1
    movaps  [rdi], xmm0
    mov     rax, rdi
    ret
    .cfi_endproc

/**
 * Vec3 *vec3_nagate(Vec3 *dest)
 *     dest = rdi
 *     ret = rax
 */
# psllq, shift packed data left logical
# psrlq, shift packed data right logical
# psrldq,shift double quarword right logical
# mocddup, move one double-fp and duplicate
.global vec3_negate
vec3_negate:
    .cfi_startproc
    movq     rcx, 0x8000000080000000
    movq     [rsp - 16], rcx
    movhps  xmm1, [rsp - 16]
    movlps  xmm1, [rsp - 16]
    movaps  xmm0, [rdi]
    xorps   xmm0, xmm1
    movaps  [rdi], xmm0
    mov     rax, rdi
    ret
    .cfi_endproc

/**
 * Vec3 *vec3_mul(Vec3 *dest, const Vec3 *src)
 */
.global vec3_mul
vec3_mul:
    .cfi_startproc
    movaps  xmm0,  [rdi]
    movaps  xmm1,  [rsi]
    mulps   xmm0,  xmm1
    movaps  [rdi], xmm0
    mov     rax,   rdi
    ret
    .cfi_endproc

/**
 *  Vec3 *vec3_div(Vec3 *dest, const Vec3 *src)
 */
.global vec3_div
vec3_div:
    .cfi_startproc
    movaps  xmm0, [rdi]
    movaps  xmm1, [rsi]
    divps   xmm0, xmm1
    movaps  [rdi], xmm0
    mov     rax, rdi
    ret
    .cfi_endproc

/**
 *  Vec3 *vec3_add_scalar(Vec3 *dest, const float s)
 *  dest = rdi
 *  s    = xmm0
 *  ret  = rax
 */
.global vec3_add_scalar
vec3_add_scalar:
    .cfi_startproc
    movd        rcx, xmm0
    movd        rdx, xmm0
    movsldup    xmm1, xmm0
    movlhps     xmm1, xmm1
    movaps      xmm0, XMMWORD PTR [rdi]
    addps       xmm0, xmm1
    movaps      XMMWORD PTR [rdi], xmm0
    mov         rax, rdi
    ret
    .cfi_endproc

/**
 *  Vec3 *vec3_mul_scalar(Vec3 *dest, const float s)
 *  dest = rdi
 *  s    = xmm0
 *  ret  = rax
 */
.global vec3_mul_scalar
vec3_mul_scalar:
    .cfi_startproc
    movd     rcx, xmm0
    movd     rdx, xmm0
    movsldup    xmm1, xmm0
    movlhps     xmm1, xmm1
    movaps  xmm0, [rdi]
    mulps   xmm0, xmm1
    movaps  [rdi], xmm0
    mov rax, rdi
    ret
    .cfi_endproc

/**
 *  Vec3 *vec3_mul_scalar(Vec3 *dest, const float s)
 *  dest = rdi
 *  s    = xmm0
 *  ret  = rax
 */
.global vec3_div_scalar
vec3_div_scalar:
    .cfi_startproc
    movd        rcx, xmm0
    movd        rdx, xmm0
    movsldup    xmm1, xmm0
    movlhps     xmm1, xmm1
    movaps  xmm0, XMMWORD PTR [rdi]
    divps   xmm0, xmm1
    movaps  XMMWORD PTR [rdi], xmm0
    mov rax, rdi
    ret
    .cfi_endproc

/**
 * Vec3 *vec3_normalize(Vec3 *dest)
 */
/*
.global vec3_normalize
vec3_normalize:
    .cfi_startproc
    sub     rsp, 24
    movaps  xmm0, [rdi]
    movaps  xmm1, [rdi]
    dpps    xmm1, xmm1, 0x71    # dot product


    // sqrtss  xmm1, xmm1          # reciprocal squre root of product
    movss   [rsp+4], xmm1
    mov     [rsp+8], rdi
    call    sqrtf@PLT
    mov     rdi,  [rsp + 8]
    movss   xmm1, [rsp + 4]

    mov     rcx, 0x3f800000     # 0x3f800000 == 1.0000f
    movd    xmm2, rcx
    divss   xmm2, xmm1

    movsldup    xmm1, xmm2
    movlhps xmm1, xmm1
    mulps   xmm0, xmm1          # multiply orig by reciprocal
    movaps  [rdi], xmm0
    mov     rax, rdi
    add     rsp, 24
    ret
    .cfi_endproc
    */
    /*
    .cfi_startproc
    movaps  xmm0, [rdi]
    movaps  xmm1, [rdi]
    dpps    xmm1, xmm1, 0x71    # dot product
    sqrtss  xmm1, xmm1          # reciprocal squre root of product

    mov     rcx, 0x3f800000     # 0x3f800000 == 1.0000f
    movd    xmm2, rcx
    divss   xmm2, xmm1

    movsldup    xmm1, xmm2
    movlhps xmm1, xmm1
    mulps   xmm0, xmm1          # multiply orig by reciprocal
    movaps  [rdi], xmm0
    mov     rax, rdi
    ret
    .cfi_endproc
    */

.global vec3_normalize
vec3_normalize:
    .cfi_startproc
    sub     rsp, 24
    .cfi_def_cfa_offset 32
    mov     rax, rdi
    movss   xmm3, [rdi]     # dest->x
    movss   xmm2, [rdi + 4] # dest->y
    movaps  xmm1, xmm3      # dest->x
    movaps  xmm0, xmm2      # dest->y
    mulss   xmm1, xmm3      # x = dest->x * dest->x
    movss   xmm4, [rdi + 8] # dest->z
    mulss   xmm0, xmm2      # y = dest->y * dest->y
    addss   xmm1, xmm0      # x + y
    movaps  xmm0, xmm4      # dest->z
    mulss   xmm0, xmm4      # dest->z * dest->z
    addss   xmm1, xmm0      # x + y + z
    pxor    xmm0, xmm0      # xmm0 = 0
    ucomiss xmm0, xmm1      # check if xmm1 is negative? compare x+y+z to 0.0f
    sqrtss  xmm5, xmm1      # xmm5 = sqrt(x+y+z)
    ja .L16
.L14:
    mov     rcx,  0x3f800000
    movd    xmm0, rcx
    divss   xmm0, xmm5
    mulss   xmm3, xmm0
    mulss   xmm2, xmm0
    mulss   xmm0, xmm4
    movss   [rax], xmm3
    movss   [rax + 4], xmm2
    movss   [rax + 8], xmm0
    .cfi_remember_state
    .cfi_def_cfa_offset 8
    add     rsp, 24
    mov     rax, rdi
    ret
.L16:
    .cfi_restore_state
    movaps  xmm0, xmm1
    movss   [rsp + 4], xmm5
    mov     [rsp + 8], rdi
    call    sqrtf@PLT
    mov     rax,  [rsp + 8]
    movss   xmm5, [rsp + 4]
    movss   xmm3, [rax]
    movss   xmm2, [rax + 4]
    movss   xmm4, [rax + 8]
    jmp .L14
    .cfi_endproc

/**
 * Vec3 *vec3_unit_direction(Vec3 *dest, const Vec3 *src);
 * dest = rdi
 * src  = rsi
 * ret  = rax
 */
 /*
.global vec3_unit_direction
vec3_unit_direction:
    .cfi_startproc
    movaps xmm0, [rdi]
    movaps xmm1, [rsi]
    # subtract
    subps  xmm1, xmm0
    #normalize
    mov     rax, rdi
    ret
    .cfi_endproc
    */

/**
 * Vec3 *vec3_mul_mat4(Vec3 *dest, Mat4 *m);
 */
# .global vec3_mul_mat4

/**
 * Vec3 *vec3_normal_vector(Vec3 *a, const Vec3 *b, const Vec3 *c)
 */
# .global vec3_normal_vector

/**
 * Vec3 *vec3_cross(Vec3 *dest, const Vec3 *src);
 * dest is rdi
 * src is rsi
 * return is rax
 */
.global vec3_cross
vec3_cross:
    .cfi_startproc          #xyxxy
    movss   xmm0, DWORD PTR 4[rdi]   #   xmm0 = dest->y * src->z - dest->z * src->y
    mulss   xmm0, DWORD PTR 8[rsi]
    movss   xmm1, DWORD PTR 8[rdi]   #
    mulss   xmm1, DWORD PTR 4[rsi]
    subss   xmm0, xmm1              #
    movss   xmm1, DWORD PTR 8[rdi]   #   xmm1 = dest->z * src->x - dest->x * src->z
    mulss   xmm1, DWORD PTR [rsi]
    movss   xmm2, DWORD PTR [rdi]     #
    mulss   xmm2, DWORD PTR 8[rsi]
    subss   xmm1, xmm2              #
    movss   xmm2, DWORD PTR [rdi]     # xmm2 = dest->x * src->y - dest->y * src->x
    mulss   xmm2, DWORD PTR 4[rsi]
    movss   xmm3, DWORD PTR 4[rdi]   #
    mulss   xmm3, DWORD PTR [rsi]
    subss   xmm2, xmm3              #
    movss   [rdi], xmm0
    movss   [rdi+4], xmm1
    movss   [rdi+8], xmm2
    mov     rax, rdi
    ret
    .cfi_endproc

/**
 * float vec3_dot(const Vec3 *v0, const Vec3 *v1)
 * v0 = rdi
 * v1 = rsi
 * ret = xmm0
 */
.global vec3_dot                # Function vec3_dot
vec3_dot:
    .cfi_startproc
    movaps  xmm1, [rdi]
    movaps  xmm0, [rsi];
    dpps    xmm0, xmm1, 0x71
    ret
    .cfi_endproc

/**
 * float vec3_length(const Vec3 *v)
 *  TODO need to refactor
 */
.global vec3_length
vec3_length:
    .cfi_startproc
    movss   xmm1, DWORD PTR [rdi]
    movss   xmm2, DWORD PTR 4[rdi]
    mulss   xmm1, xmm1
    mulss   xmm2, xmm2
    movss   xmm0, DWORD PTR 8[rdi]
    mulss   xmm0, xmm0
    addss   xmm1, xmm2
    pxor    xmm2, xmm2
    addss   xmm0, xmm1
    ucomiss xmm2, xmm0
    sqrtss  xmm1, xmm0
    ja  .L31
    movaps  xmm0, xmm1
    ret
.L31:
    sub     rsp, 24
    .cfi_def_cfa_offset 32 #cfi_define canonical frame address offset
    movss   [rsp+12], xmm1
    call    sqrtf@PLT
    movss   xmm1, [rsp+12]
    add     rsp, 24
    .cfi_def_cfa_offset 8
    movaps  xmm0, xmm1
    ret
    .cfi_endproc

/**
 * float vec3_distance(const Vec3 *from, const Vec3 *to)
 */
#.global vec3_distance

/**
 * Vec3 vec3_copy_mul_scalar(const Vec3 *src, const float s)
 *      src is rdi
 *      s is xmm0
 *      ret is xmm0hh, xmm0hl and xmm0hh
 */
.global vec3_copy_mul_scalar
vec3_copy_mul_scalar:
    .cfi_startproc
    movss   xmm3, DWORD PTR [rdi]
    movss   xmm2, DWORD PTR 4[rdi]
    movss   xmm1, DWORD PTR 8[rdi]
    mulss   xmm1, xmm0
    mulss   xmm2, xmm0
    mulss   xmm3, xmm0
    movd    eax, xmm2
    movd    edx, xmm3
    mov     rcx, rax
    sal     rcx, 0x20
    mov     eax, edx
    or      rax, rcx
    mov   QWORD PTR -16[rsp], rax
    movq   xmm0, QWORD PTR -16[rsp]
    ret
    .cfi_endproc

/**
 * Vec3 vec3_copy_add(const Vec3 *v0, const Vec3 *v1)
 *      v0 is rdi
 *      v1 is rsi
 *      ret is xmm0, xmm1
 */
.global vec3_copy_add
vec3_copy_add:
    .cfi_startproc
    movss   xmm1, DWORD PTR 8[rdi]
    addss   xmm1, DWORD PTR 8[rsi]
    movss   xmm2, DWORD PTR 4[rdi]
    addss   xmm2, DWORD PTR 4[rsi]
    movss   xmm0, DWORD PTR [rdi]
    addss   xmm0, DWORD PTR [rsi]
    movq    rdx, xmm2
    movd    eax, xmm0
    sal     rdx, 0x20
    or  rax, rdx
    mov     QWORD PTR -16[rsp], rax
    movq    xmm0, QWORD PTR -16[rsp]
    ret
    .cfi_endproc

/**
 * Vec3 vec3_copy_sub(const Vec3 *a, const Vec3 *b)
 */
.global vec3_copy_sub
vec3_copy_sub:
    .cfi_startproc
    movss   xmm1, DWORD PTR 8[rdi]
    subss   xmm1, DWORD PTR 8[rsi]
    movss   xmm2, DWORD PTR 4[rdi]
    subss   xmm2, DWORD PTR 4[rsi]
    movss   xmm0, DWORD PTR [rdi]
    subss   xmm0, DWORD PTR [rsi]
    movq    rdx, xmm2
    movd    eax, xmm0
    sal     rdx, 0x20
    or  rax, rdx
    mov     QWORD PTR -16[rsp], rax
    movq    xmm0, QWORD PTR -16[rsp]
    ret
    .cfi_endproc

/**
 * Vec3 vec3_copy_cross(const Vec3 *a, const Vec3 *b)
 * movsldup
 */
.global vec3_copy_cross
vec3_copy_cross:
    .cfi_startproc
    movss   xmm0, DWORD PTR 4[rdi]   #   xmm0 = dest->y * src->z - dest->z * src->y
    mulss   xmm0, DWORD PTR 8[rsi]
    movss   xmm1, DWORD PTR 8[rdi]   #
    mulss   xmm1, DWORD PTR 4[rsi]
    subss   xmm0, xmm1              #
    movss   xmm2, DWORD PTR 8[rdi]   #   xmm1 = dest->z * src->x - dest->x * src->z
    mulss   xmm2, DWORD PTR [rsi]
    movss   xmm1, DWORD PTR [rdi]     #
    mulss   xmm1, DWORD PTR 8[rsi]
    subss   xmm2, xmm1              #
    movss   xmm1, DWORD PTR [rdi]     # xmm2 = dest->x * src->y - dest->y * src->x
    mulss   xmm1, DWORD PTR 4[rsi]
    movss   xmm3, DWORD PTR 4[rdi]   #
    mulss   xmm3, DWORD PTR [rsi]
    subss   xmm1, xmm3              #
    movq    rdx, xmm2
    movd    eax, xmm0
    sal     rdx, 0x20
    or      rax, rdx
    mov     QWORD PTR -16[rsp], rax
    movq    xmm0, QWORD PTR -16[rsp]
    ret
    .cfi_endproc
/**
 * bool vec3_equiv(const Vec3 *v0, const Vec3 *v1)
 */
.global vec3_equiv
vec3_equiv:
    .cfi_startproc
    mov     DWORD PTR -4[rsp], 897988541
    movss   xmm0, DWORD PTR [rdi]
    xor     eax, eax
    subss   xmm0, DWORD PTR [rsi]
    mov     ecx,  3045472189
    movd    xmm1, ecx
    movss   xmm3, DWORD PTR 8[rdi]
    movss   xmm5, DWORD PTR 8[rsi]
    movss   xmm2, DWORD PTR 4[rdi]
    movss   xmm4, DWORD PTR 4[rsi]
    ucomiss xmm1, xmm0
    ja  .NOT_EQUIV
    ucomiss xmm0, DWORD PTR -4[rsp]
    ja .NOT_EQUIV
    subss   xmm2, xmm4
    ucomiss xmm1, xmm2
    ja .NOT_EQUIV
    ucomiss xmm2, DWORD PTR -4[rsp]
    subss   xmm3, xmm5
    ucomiss xmm1, xmm3
    ja .NOT_EQUIV
    ucomiss xmm3, DWORD PTR -4[rsp]
    setbe al
    .NOT_EQUIV:
    rep ret
    .cfi_endproc

/**
 * bool vec3_are_orthogonal(const Vec3 *v0, const Vec3 *v1)
 */
# .global vec3_are_orthogonal

/**
 * bool vec3_point_in_sphere(const Vec3 *pt, const Vec3 *sp, const float radius)
 */
.global vec3_point_in_sphere
vec3_point_in_sphere:
    .cfi_startproc
    xor     eax, eax
    mulss xmm0, xmm0
    movss   xmm1, DWORD PTR [rdi]
    subss   xmm1, DWORD PTR [rsi]
    mulss   xmm1, xmm1
    movss   xmm2, DWORD PTR 4[rdi]
    subss   xmm2, DWORD PTR 4[rsi]
    mulss   xmm2, xmm2
    addss   xmm1, xmm2
    movss   xmm3, DWORD PTR 8[rdi]
    subss   xmm3, DWORD PTR 8[rsi]
    mulss   xmm3, xmm3
    addss   xmm1, xmm3
    ucomiss xmm0, xmm1
    setnb   al
    ret
    .cfi_endproc

/**
 *
 */
# .global vec3_ray_plane_intersection

/**
 *
 */
# .global vec3_vector_plane_intersection

/**
 *
 */
# .global vec3_project_point

/**
 *
 */
# .global vec3_attentuation


/**
 *
 */
# .global vec3_compute_line_distance

/**
 *
 */
# .global vec3_compute_line_coefficients

/**
 *
 */
# .global vec3_rtp_to_xyx

/**
 *
 */
# .global vec3_printf
