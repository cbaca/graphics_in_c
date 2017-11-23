	.file	"Vec3.c"
	.intel_syntax noprefix
	.text
.Ltext0:
	.p2align 4,,15
	.globl	vec3copy
	.type	vec3copy, @function
vec3copy:
.LFB27:
	.file 1 "src/Vec3.c"
	.loc 1 13 0
	.cfi_startproc
.LVL0:
	.loc 1 14 0
	mov	eax, DWORD PTR 4[rdi]
	.loc 1 15 0
	movss	xmm1, DWORD PTR 8[rdi]
	.loc 1 14 0
	sal	rax, 32
	mov	rdx, rax
	mov	eax, DWORD PTR [rdi]
	or	rax, rdx
	.loc 1 15 0
	mov	QWORD PTR -16[rsp], rax
	movq	xmm0, QWORD PTR -16[rsp]
	ret
	.cfi_endproc
.LFE27:
	.size	vec3copy, .-vec3copy
	.p2align 4,,15
	.globl	vec3construct
	.type	vec3construct, @function
vec3construct:
.LFB28:
	.loc 1 18 0
	.cfi_startproc
.LVL1:
	.loc 1 19 0
	movd	eax, xmm0
	movd	edx, xmm1
	.loc 1 20 0
	movaps	xmm1, xmm2
.LVL2:
	.loc 1 19 0
	sal	rdx, 32
	mov	eax, eax
	or	rax, rdx
	.loc 1 20 0
	mov	QWORD PTR -16[rsp], rax
	movq	xmm0, QWORD PTR -16[rsp]
.LVL3:
	ret
	.cfi_endproc
.LFE28:
	.size	vec3construct, .-vec3construct
	.p2align 4,,15
	.globl	vec3set
	.type	vec3set, @function
vec3set:
.LFB29:
	.loc 1 23 0
	.cfi_startproc
.LVL4:
	.loc 1 24 0
	movss	xmm0, DWORD PTR [rsi]
	.loc 1 23 0
	mov	rax, rdi
	.loc 1 24 0
	movss	DWORD PTR [rdi], xmm0
	.loc 1 25 0
	movss	xmm0, DWORD PTR 4[rsi]
	movss	DWORD PTR 4[rdi], xmm0
	.loc 1 26 0
	movss	xmm0, DWORD PTR 8[rsi]
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 28 0
	ret
	.cfi_endproc
.LFE29:
	.size	vec3set, .-vec3set
	.p2align 4,,15
	.globl	vec3init
	.type	vec3init, @function
vec3init:
.LFB30:
	.loc 1 31 0
	.cfi_startproc
.LVL5:
	.loc 1 31 0
	mov	rax, rdi
	.loc 1 32 0
	movss	DWORD PTR [rdi], xmm0
	.loc 1 33 0
	movss	DWORD PTR 4[rdi], xmm1
	.loc 1 34 0
	movss	DWORD PTR 8[rdi], xmm2
	.loc 1 36 0
	ret
	.cfi_endproc
.LFE30:
	.size	vec3init, .-vec3init
	.p2align 4,,15
	.globl	vec3add
	.type	vec3add, @function
vec3add:
.LFB31:
	.loc 1 39 0
	.cfi_startproc
.LVL6:
	.loc 1 40 0
	movss	xmm0, DWORD PTR [rdi]
	.loc 1 39 0
	mov	rax, rdi
	.loc 1 40 0
	addss	xmm0, DWORD PTR [rsi]
	movss	DWORD PTR [rdi], xmm0
	.loc 1 41 0
	movss	xmm0, DWORD PTR 4[rdi]
	addss	xmm0, DWORD PTR 4[rsi]
	movss	DWORD PTR 4[rdi], xmm0
	.loc 1 42 0
	movss	xmm0, DWORD PTR 8[rdi]
	addss	xmm0, DWORD PTR 8[rsi]
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 44 0
	ret
	.cfi_endproc
.LFE31:
	.size	vec3add, .-vec3add
	.p2align 4,,15
	.globl	vec3sub
	.type	vec3sub, @function
vec3sub:
.LFB32:
	.loc 1 47 0
	.cfi_startproc
.LVL7:
	.loc 1 48 0
	movss	xmm0, DWORD PTR [rdi]
	.loc 1 47 0
	mov	rax, rdi
	.loc 1 48 0
	subss	xmm0, DWORD PTR [rsi]
	movss	DWORD PTR [rdi], xmm0
	.loc 1 49 0
	movss	xmm0, DWORD PTR 4[rdi]
	subss	xmm0, DWORD PTR 4[rsi]
	movss	DWORD PTR 4[rdi], xmm0
	.loc 1 50 0
	movss	xmm0, DWORD PTR 8[rdi]
	subss	xmm0, DWORD PTR 8[rsi]
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 52 0
	ret
	.cfi_endproc
.LFE32:
	.size	vec3sub, .-vec3sub
	.p2align 4,,15
	.globl	vec3negate
	.type	vec3negate, @function
vec3negate:
.LFB33:
	.loc 1 55 0
	.cfi_startproc
.LVL8:
	.loc 1 56 0
	movss	xmm1, DWORD PTR .LC0[rip]
	movss	xmm0, DWORD PTR [rdi]
	.loc 1 55 0
	mov	rax, rdi
	.loc 1 56 0
	xorps	xmm0, xmm1
	movss	DWORD PTR [rdi], xmm0
	movss	xmm0, DWORD PTR 4[rdi]
	xorps	xmm0, xmm1
	movss	DWORD PTR 4[rdi], xmm0
	movss	xmm0, DWORD PTR 8[rdi]
	xorps	xmm0, xmm1
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 58 0
	ret
	.cfi_endproc
.LFE33:
	.size	vec3negate, .-vec3negate
	.p2align 4,,15
	.globl	vec3mul
	.type	vec3mul, @function
vec3mul:
.LFB34:
	.loc 1 61 0
	.cfi_startproc
.LVL9:
	.loc 1 62 0
	movss	xmm0, DWORD PTR [rdi]
	.loc 1 61 0
	mov	rax, rdi
	.loc 1 62 0
	mulss	xmm0, DWORD PTR [rsi]
	movss	DWORD PTR [rdi], xmm0
	.loc 1 63 0
	movss	xmm0, DWORD PTR 4[rdi]
	mulss	xmm0, DWORD PTR 4[rsi]
	movss	DWORD PTR 4[rdi], xmm0
	.loc 1 64 0
	movss	xmm0, DWORD PTR 8[rdi]
	mulss	xmm0, DWORD PTR 8[rsi]
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 66 0
	ret
	.cfi_endproc
.LFE34:
	.size	vec3mul, .-vec3mul
	.p2align 4,,15
	.globl	vec3div
	.type	vec3div, @function
vec3div:
.LFB35:
	.loc 1 69 0
	.cfi_startproc
.LVL10:
	.loc 1 70 0
	movss	xmm0, DWORD PTR [rdi]
	.loc 1 69 0
	mov	rax, rdi
	.loc 1 70 0
	divss	xmm0, DWORD PTR [rsi]
	movss	DWORD PTR [rdi], xmm0
	.loc 1 71 0
	movss	xmm0, DWORD PTR 4[rdi]
	divss	xmm0, DWORD PTR 4[rsi]
	movss	DWORD PTR 4[rdi], xmm0
	.loc 1 72 0
	movss	xmm0, DWORD PTR 8[rdi]
	divss	xmm0, DWORD PTR 8[rsi]
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 74 0
	ret
	.cfi_endproc
.LFE35:
	.size	vec3div, .-vec3div
	.p2align 4,,15
	.globl	vec3addScalar
	.type	vec3addScalar, @function
vec3addScalar:
.LFB36:
	.loc 1 77 0
	.cfi_startproc
.LVL11:
	.loc 1 78 0
	movss	xmm1, DWORD PTR [rdi]
	.loc 1 77 0
	mov	rax, rdi
	.loc 1 78 0
	addss	xmm1, xmm0
	movss	DWORD PTR [rdi], xmm1
	.loc 1 79 0
	movss	xmm1, DWORD PTR 4[rdi]
	addss	xmm1, xmm0
	.loc 1 80 0
	addss	xmm0, DWORD PTR 8[rdi]
.LVL12:
	.loc 1 79 0
	movss	DWORD PTR 4[rdi], xmm1
	.loc 1 80 0
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 82 0
	ret
	.cfi_endproc
.LFE36:
	.size	vec3addScalar, .-vec3addScalar
	.p2align 4,,15
	.globl	vec3mulScalar
	.type	vec3mulScalar, @function
vec3mulScalar:
.LFB37:
	.loc 1 85 0
	.cfi_startproc
.LVL13:
	.loc 1 86 0
	movss	xmm1, DWORD PTR [rdi]
	.loc 1 85 0
	mov	rax, rdi
	.loc 1 86 0
	mulss	xmm1, xmm0
	movss	DWORD PTR [rdi], xmm1
	movss	xmm1, DWORD PTR 4[rdi]
	mulss	xmm1, xmm0
	mulss	xmm0, DWORD PTR 8[rdi]
.LVL14:
	movss	DWORD PTR 4[rdi], xmm1
	movss	DWORD PTR 8[rdi], xmm0
	.loc 1 88 0
	ret
	.cfi_endproc
.LFE37:
	.size	vec3mulScalar, .-vec3mulScalar
	.p2align 4,,15
	.globl	vec3divScalar
	.type	vec3divScalar, @function
vec3divScalar:
.LFB38:
	.loc 1 91 0
	.cfi_startproc
.LVL15:
	.loc 1 92 0
	movss	xmm1, DWORD PTR [rdi]
	.loc 1 91 0
	mov	rax, rdi
	.loc 1 92 0
	divss	xmm1, xmm0
	movss	DWORD PTR [rdi], xmm1
	.loc 1 93 0
	movss	xmm1, DWORD PTR 4[rdi]
	divss	xmm1, xmm0
	movss	DWORD PTR 4[rdi], xmm1
	.loc 1 94 0
	movss	xmm1, DWORD PTR 8[rdi]
	divss	xmm1, xmm0
	movss	DWORD PTR 8[rax], xmm1
	.loc 1 96 0
	ret
	.cfi_endproc
.LFE38:
	.size	vec3divScalar, .-vec3divScalar
	.p2align 4,,15
	.globl	vec3normalize
	.type	vec3normalize, @function
vec3normalize:
.LFB39:
	.loc 1 99 0
	.cfi_startproc
.LVL16:
	sub	rsp, 24
	.cfi_def_cfa_offset 32
	.loc 1 99 0
	mov	rax, rdi
	.loc 1 100 0
	movss	xmm3, DWORD PTR [rdi]
	movss	xmm2, DWORD PTR 4[rdi]
	movaps	xmm1, xmm3
	movaps	xmm0, xmm2
	mulss	xmm1, xmm3
	movss	xmm4, DWORD PTR 8[rdi]
	mulss	xmm0, xmm2
	addss	xmm1, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, xmm4
	addss	xmm1, xmm0
	pxor	xmm0, xmm0
	ucomiss	xmm0, xmm1
	sqrtss	xmm5, xmm1
	ja	.L17
.LVL17:
.L15:
	movss	xmm0, DWORD PTR .LC2[rip]
	divss	xmm0, xmm5
.LVL18:
	.loc 1 103 0
	mulss	xmm3, xmm0
	mulss	xmm2, xmm0
	mulss	xmm0, xmm4
.LVL19:
	movss	DWORD PTR [rax], xmm3
	movss	DWORD PTR 4[rax], xmm2
	movss	DWORD PTR 8[rax], xmm0
	.loc 1 105 0
	add	rsp, 24
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.LVL20:
.L17:
	.cfi_restore_state
	.loc 1 100 0
	movaps	xmm0, xmm1
	movss	DWORD PTR 4[rsp], xmm5
	mov	QWORD PTR 8[rsp], rdi
	call	sqrtf@PLT
.LVL21:
	mov	rax, QWORD PTR 8[rsp]
	movss	xmm5, DWORD PTR 4[rsp]
	movss	xmm3, DWORD PTR [rax]
	movss	xmm2, DWORD PTR 4[rax]
	movss	xmm4, DWORD PTR 8[rax]
	jmp	.L15
	.cfi_endproc
.LFE39:
	.size	vec3normalize, .-vec3normalize
	.p2align 4,,15
	.globl	vec3unitDirection
	.type	vec3unitDirection, @function
vec3unitDirection:
.LFB40:
	.loc 1 108 0
	.cfi_startproc
.LVL22:
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	pxor	xmm5, xmm5
.LBB148:
.LBB149:
	.loc 1 48 0
	movss	xmm3, DWORD PTR [rsi]
.LBE149:
.LBE148:
	.loc 1 108 0
	mov	rax, rdi
.LBB151:
.LBB150:
	.loc 1 49 0
	movss	xmm2, DWORD PTR 4[rsi]
	.loc 1 48 0
	subss	xmm3, DWORD PTR [rdi]
	.loc 1 49 0
	subss	xmm2, DWORD PTR 4[rdi]
	.loc 1 50 0
	movss	xmm1, DWORD PTR 8[rsi]
	subss	xmm1, DWORD PTR 8[rdi]
.LVL23:
.LBE150:
.LBE151:
.LBB152:
.LBB153:
	.loc 1 100 0
	movaps	xmm0, xmm3
	movaps	xmm4, xmm2
	mulss	xmm0, xmm3
	mulss	xmm4, xmm2
	addss	xmm0, xmm4
	movaps	xmm4, xmm1
	mulss	xmm4, xmm1
	addss	xmm0, xmm4
	ucomiss	xmm5, xmm0
	sqrtss	xmm4, xmm0
	ja	.L21
.LVL24:
.L19:
	movss	xmm0, DWORD PTR .LC2[rip]
	divss	xmm0, xmm4
.LVL25:
	.loc 1 103 0
	mulss	xmm3, xmm0
	mulss	xmm2, xmm0
	mulss	xmm1, xmm0
.LBE153:
.LBE152:
.LBB155:
.LBB156:
	.loc 1 24 0
	movss	DWORD PTR [rax], xmm3
	.loc 1 25 0
	movss	DWORD PTR 4[rax], xmm2
	.loc 1 26 0
	movss	DWORD PTR 8[rax], xmm1
.LVL26:
.LBE156:
.LBE155:
	.loc 1 111 0
	add	rsp, 40
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.LVL27:
.L21:
	.cfi_restore_state
	movss	DWORD PTR 20[rsp], xmm4
	mov	QWORD PTR 24[rsp], rdi
	movss	DWORD PTR 16[rsp], xmm1
	movss	DWORD PTR 12[rsp], xmm2
	movss	DWORD PTR 8[rsp], xmm3
.LBB157:
.LBB154:
	.loc 1 100 0
	call	sqrtf@PLT
.LVL28:
	mov	rax, QWORD PTR 24[rsp]
	movss	xmm4, DWORD PTR 20[rsp]
	movss	xmm1, DWORD PTR 16[rsp]
	movss	xmm2, DWORD PTR 12[rsp]
	movss	xmm3, DWORD PTR 8[rsp]
	jmp	.L19
.LBE154:
.LBE157:
	.cfi_endproc
.LFE40:
	.size	vec3unitDirection, .-vec3unitDirection
	.p2align 4,,15
	.globl	vec3mulMat4
	.type	vec3mulMat4, @function
vec3mulMat4:
.LFB41:
	.loc 1 114 0
	.cfi_startproc
.LVL29:
	.loc 1 115 0
	movss	xmm0, DWORD PTR [rdi]
.LVL30:
	.loc 1 114 0
	mov	rax, rdi
	.loc 1 115 0
	movss	xmm4, DWORD PTR 4[rdi]
.LVL31:
	.loc 1 118 0
	movss	xmm1, DWORD PTR 8[rsi]
	movss	xmm2, DWORD PTR 24[rsi]
	mulss	xmm1, xmm0
	mulss	xmm2, xmm4
	.loc 1 115 0
	movss	xmm3, DWORD PTR 8[rdi]
.LVL32:
	.loc 1 117 0
	movss	xmm5, DWORD PTR 20[rsi]
	mulss	xmm5, xmm4
	.loc 1 116 0
	mulss	xmm4, DWORD PTR 16[rsi]
.LVL33:
	.loc 1 118 0
	addss	xmm1, xmm2
	movss	xmm2, DWORD PTR 40[rsi]
	mulss	xmm2, xmm3
	addss	xmm1, xmm2
	.loc 1 117 0
	movss	xmm2, DWORD PTR 4[rsi]
	mulss	xmm2, xmm0
	.loc 1 116 0
	mulss	xmm0, DWORD PTR [rsi]
.LVL34:
	addss	xmm1, DWORD PTR 56[rsi]
	.loc 1 117 0
	addss	xmm2, xmm5
	movss	xmm5, DWORD PTR 36[rsi]
	mulss	xmm5, xmm3
	.loc 1 116 0
	mulss	xmm3, DWORD PTR 32[rsi]
.LVL35:
	addss	xmm0, xmm4
	.loc 1 117 0
	addss	xmm2, xmm5
	.loc 1 116 0
	addss	xmm0, xmm3
	addss	xmm2, DWORD PTR 52[rsi]
.LVL36:
	addss	xmm0, DWORD PTR 48[rsi]
.LBB158:
.LBB159:
	.loc 1 34 0
	movss	DWORD PTR 8[rdi], xmm1
.LVL37:
	.loc 1 33 0
	movss	DWORD PTR 4[rdi], xmm2
.LVL38:
	.loc 1 32 0
	movss	DWORD PTR [rdi], xmm0
.LVL39:
.LBE159:
.LBE158:
	.loc 1 119 0
	ret
	.cfi_endproc
.LFE41:
	.size	vec3mulMat4, .-vec3mulMat4
	.p2align 4,,15
	.globl	vec3normalVector
	.type	vec3normalVector, @function
vec3normalVector:
.LFB42:
	.loc 1 122 0
	.cfi_startproc
.LVL40:
.LBB160:
.LBB161:
	.loc 1 174 0
	movss	xmm2, DWORD PTR [rdx]
.LBE161:
.LBE160:
	.loc 1 122 0
	mov	rax, rdi
.LBB166:
.LBB162:
	.loc 1 174 0
	movss	xmm0, DWORD PTR 4[rdx]
	movss	xmm7, DWORD PTR 4[rdi]
	movaps	xmm4, xmm2
.LBE162:
.LBE166:
.LBB167:
.LBB168:
	movss	xmm1, DWORD PTR 8[rsi]
	movss	xmm2, DWORD PTR 4[rsi]
.LBE168:
.LBE167:
.LBB172:
.LBB163:
	movaps	xmm5, xmm0
	movss	xmm8, DWORD PTR 8[rdi]
.LBE163:
.LBE172:
.LBB173:
.LBB169:
	subss	xmm2, xmm7
	subss	xmm1, xmm8
.LBE169:
.LBE173:
.LBB174:
.LBB164:
	movss	xmm3, DWORD PTR 8[rdx]
	movss	xmm6, DWORD PTR [rdi]
	subss	xmm5, xmm7
.LBE164:
.LBE174:
.LBB175:
.LBB170:
	movss	xmm0, DWORD PTR [rsi]
.LBE170:
.LBE175:
.LBB176:
.LBB165:
	subss	xmm4, xmm6
.LVL41:
	subss	xmm3, xmm8
.LVL42:
.LBE165:
.LBE176:
.LBB177:
.LBB171:
	subss	xmm0, xmm6
.LVL43:
.LBE171:
.LBE177:
.LBB178:
.LBB179:
	.loc 1 134 0
	movaps	xmm7, xmm1
	movaps	xmm6, xmm2
	mulss	xmm7, xmm5
	mulss	xmm6, xmm3
	.loc 1 135 0
	mulss	xmm1, xmm4
.LVL44:
	mulss	xmm3, xmm0
.LVL45:
	.loc 1 136 0
	mulss	xmm2, xmm4
.LVL46:
	mulss	xmm0, xmm5
.LVL47:
	.loc 1 134 0
	subss	xmm6, xmm7
.LVL48:
	subss	xmm1, xmm3
.LVL49:
	subss	xmm0, xmm2
.LVL50:
.LBB180:
.LBB181:
	.loc 1 32 0
	movss	DWORD PTR [rdi], xmm6
	.loc 1 33 0
	movss	DWORD PTR 4[rdi], xmm1
	.loc 1 34 0
	movss	DWORD PTR 8[rdi], xmm0
.LVL51:
.LBE181:
.LBE180:
.LBE179:
.LBE178:
	.loc 1 130 0
	ret
	.cfi_endproc
.LFE42:
	.size	vec3normalVector, .-vec3normalVector
	.p2align 4,,15
	.globl	vec3cross
	.type	vec3cross, @function
vec3cross:
.LFB43:
	.loc 1 133 0
	.cfi_startproc
.LVL52:
	.loc 1 136 0
	movss	xmm6, DWORD PTR 4[rsi]
	.loc 1 133 0
	mov	rax, rdi
	.loc 1 136 0
	movss	xmm2, DWORD PTR 4[rdi]
	.loc 1 134 0
	movaps	xmm4, xmm2
	movaps	xmm7, xmm6
	.loc 1 136 0
	movss	xmm5, DWORD PTR [rsi]
	.loc 1 135 0
	movss	xmm3, DWORD PTR 8[rsi]
.LVL53:
	.loc 1 136 0
	mulss	xmm2, xmm5
	movss	xmm0, DWORD PTR [rdi]
	.loc 1 134 0
	mulss	xmm4, xmm3
	.loc 1 135 0
	movss	xmm1, DWORD PTR 8[rdi]
.LVL54:
	mulss	xmm3, xmm0
.LVL55:
	.loc 1 134 0
	mulss	xmm7, xmm1
	.loc 1 136 0
	mulss	xmm0, xmm6
.LVL56:
	.loc 1 135 0
	mulss	xmm1, xmm5
.LVL57:
	.loc 1 134 0
	subss	xmm4, xmm7
	subss	xmm0, xmm2
	subss	xmm1, xmm3
.LVL58:
.LBB182:
.LBB183:
	.loc 1 32 0
	movss	DWORD PTR [rdi], xmm4
	.loc 1 34 0
	movss	DWORD PTR 8[rdi], xmm0
.LVL59:
	.loc 1 33 0
	movss	DWORD PTR 4[rdi], xmm1
.LBE183:
.LBE182:
	.loc 1 142 0
	ret
	.cfi_endproc
.LFE43:
	.size	vec3cross, .-vec3cross
	.p2align 4,,15
	.globl	vec3dot
	.type	vec3dot, @function
vec3dot:
.LFB44:
	.loc 1 145 0
	.cfi_startproc
.LVL60:
	.loc 1 146 0
	movss	xmm0, DWORD PTR [rdi]
	movss	xmm1, DWORD PTR 4[rdi]
	mulss	xmm0, DWORD PTR [rsi]
	mulss	xmm1, DWORD PTR 4[rsi]
	addss	xmm0, xmm1
	movss	xmm1, DWORD PTR 8[rdi]
	mulss	xmm1, DWORD PTR 8[rsi]
	addss	xmm0, xmm1
	.loc 1 147 0
	ret
	.cfi_endproc
.LFE44:
	.size	vec3dot, .-vec3dot
	.p2align 4,,15
	.globl	vec3length
	.type	vec3length, @function
vec3length:
.LFB45:
	.loc 1 150 0
	.cfi_startproc
.LVL61:
	.loc 1 151 0
	movss	xmm1, DWORD PTR [rdi]
	movss	xmm2, DWORD PTR 4[rdi]
	mulss	xmm1, xmm1
	mulss	xmm2, xmm2
	movss	xmm0, DWORD PTR 8[rdi]
	mulss	xmm0, xmm0
	addss	xmm1, xmm2
	pxor	xmm2, xmm2
	addss	xmm0, xmm1
	ucomiss	xmm2, xmm0
	sqrtss	xmm1, xmm0
	ja	.L32
	.loc 1 152 0
	movaps	xmm0, xmm1
	ret
.L32:
	.loc 1 150 0
	sub	rsp, 24
	.cfi_def_cfa_offset 32
	movss	DWORD PTR 12[rsp], xmm1
	.loc 1 151 0
	call	sqrtf@PLT
.LVL62:
	movss	xmm1, DWORD PTR 12[rsp]
	.loc 1 152 0
	add	rsp, 24
	.cfi_def_cfa_offset 8
	movaps	xmm0, xmm1
	ret
	.cfi_endproc
.LFE45:
	.size	vec3length, .-vec3length
	.p2align 4,,15
	.globl	vec3distance
	.type	vec3distance, @function
vec3distance:
.LFB46:
	.loc 1 155 0
	.cfi_startproc
.LVL63:
	.loc 1 156 0
	movss	xmm1, DWORD PTR [rsi]
	.loc 1 157 0
	movss	xmm2, DWORD PTR 4[rsi]
	.loc 1 156 0
	subss	xmm1, DWORD PTR [rdi]
.LVL64:
	.loc 1 157 0
	subss	xmm2, DWORD PTR 4[rdi]
.LVL65:
	.loc 1 158 0
	movss	xmm0, DWORD PTR 8[rsi]
	subss	xmm0, DWORD PTR 8[rdi]
.LVL66:
	.loc 1 159 0
	mulss	xmm1, xmm1
.LVL67:
	mulss	xmm2, xmm2
.LVL68:
	mulss	xmm0, xmm0
.LVL69:
	addss	xmm1, xmm2
	pxor	xmm2, xmm2
	addss	xmm0, xmm1
	ucomiss	xmm2, xmm0
	sqrtss	xmm1, xmm0
	ja	.L39
	.loc 1 160 0
	movaps	xmm0, xmm1
	ret
.L39:
	.loc 1 155 0
	sub	rsp, 24
	.cfi_def_cfa_offset 32
	movss	DWORD PTR 12[rsp], xmm1
	.loc 1 159 0
	call	sqrtf@PLT
.LVL70:
	movss	xmm1, DWORD PTR 12[rsp]
	.loc 1 160 0
	add	rsp, 24
	.cfi_def_cfa_offset 8
	movaps	xmm0, xmm1
	ret
	.cfi_endproc
.LFE46:
	.size	vec3distance, .-vec3distance
	.p2align 4,,15
	.globl	vec3copyMulScalar
	.type	vec3copyMulScalar, @function
vec3copyMulScalar:
.LFB47:
	.loc 1 163 0
	.cfi_startproc
.LVL71:
	movss	xmm3, DWORD PTR 4[rdi]
	mulss	xmm3, xmm0
	movss	xmm2, DWORD PTR [rdi]
	mulss	xmm2, xmm0
	mulss	xmm0, DWORD PTR 8[rdi]
.LVL72:
	movd	eax, xmm3
	movd	edx, xmm2
	mov	rcx, rax
	sal	rcx, 32
	mov	eax, edx
	or	rax, rcx
	.loc 1 164 0
	movaps	xmm1, xmm0
	.loc 1 165 0
	mov	QWORD PTR -16[rsp], rax
	movq	xmm0, QWORD PTR -16[rsp]
	ret
	.cfi_endproc
.LFE47:
	.size	vec3copyMulScalar, .-vec3copyMulScalar
	.p2align 4,,15
	.globl	vec3copyAdd
	.type	vec3copyAdd, @function
vec3copyAdd:
.LFB48:
	.loc 1 168 0
	.cfi_startproc
.LVL73:
	.loc 1 169 0
	movss	xmm2, DWORD PTR 4[rdi]
	movss	xmm0, DWORD PTR [rdi]
	addss	xmm2, DWORD PTR 4[rsi]
	addss	xmm0, DWORD PTR [rsi]
	movss	xmm1, DWORD PTR 8[rdi]
.LVL74:
	.loc 1 170 0
	addss	xmm1, DWORD PTR 8[rsi]
	movq	rdx, xmm2
	movd	eax, xmm0
	sal	rdx, 32
	or	rax, rdx
	mov	QWORD PTR -16[rsp], rax
	movq	xmm0, QWORD PTR -16[rsp]
	ret
	.cfi_endproc
.LFE48:
	.size	vec3copyAdd, .-vec3copyAdd
	.p2align 4,,15
	.globl	vec3copySub
	.type	vec3copySub, @function
vec3copySub:
.LFB49:
	.loc 1 173 0
	.cfi_startproc
.LVL75:
	.loc 1 174 0
	movss	xmm2, DWORD PTR 4[rdi]
	movss	xmm0, DWORD PTR [rdi]
	subss	xmm2, DWORD PTR 4[rsi]
	subss	xmm0, DWORD PTR [rsi]
	movss	xmm1, DWORD PTR 8[rdi]
.LVL76:
	.loc 1 175 0
	subss	xmm1, DWORD PTR 8[rsi]
	movq	rdx, xmm2
	movd	eax, xmm0
	sal	rdx, 32
	or	rax, rdx
	mov	QWORD PTR -16[rsp], rax
	movq	xmm0, QWORD PTR -16[rsp]
	ret
	.cfi_endproc
.LFE49:
	.size	vec3copySub, .-vec3copySub
	.p2align 4,,15
	.globl	vec3copyCross
	.type	vec3copyCross, @function
vec3copyCross:
.LFB50:
	.loc 1 178 0
	.cfi_startproc
.LVL77:
	.loc 1 181 0
	movss	xmm6, DWORD PTR 4[rsi]
	movss	xmm3, DWORD PTR 4[rdi]
	.loc 1 179 0
	movaps	xmm7, xmm6
	movaps	xmm2, xmm3
	.loc 1 181 0
	movss	xmm1, DWORD PTR [rdi]
	movss	xmm5, DWORD PTR [rsi]
	.loc 1 180 0
	movss	xmm0, DWORD PTR 8[rdi]
	.loc 1 181 0
	mulss	xmm3, xmm5
	.loc 1 180 0
	movss	xmm4, DWORD PTR 8[rsi]
.LVL78:
	.loc 1 179 0
	mulss	xmm7, xmm0
	mulss	xmm2, xmm4
	.loc 1 180 0
	mulss	xmm0, xmm5
	mulss	xmm4, xmm1
	.loc 1 181 0
	mulss	xmm1, xmm6
	subss	xmm2, xmm7
	subss	xmm0, xmm4
	.loc 1 182 0
	subss	xmm1, xmm3
	movd	edx, xmm2
	movq	rax, xmm0
	sal	rax, 32
	or	rax, rdx
	mov	QWORD PTR -16[rsp], rax
	movq	xmm0, QWORD PTR -16[rsp]
	ret
	.cfi_endproc
.LFE50:
	.size	vec3copyCross, .-vec3copyCross
	.p2align 4,,15
	.globl	vec3equiv
	.type	vec3equiv, @function
vec3equiv:
.LFB51:
	.loc 1 185 0
	.cfi_startproc
.LVL79:
.LBB184:
.LBB185:
	.loc 1 174 0
	movss	xmm0, DWORD PTR [rdi]
.LBE185:
.LBE184:
	.loc 1 187 0
	xor	eax, eax
.LBB190:
.LBB186:
	.loc 1 174 0
	subss	xmm0, DWORD PTR [rsi]
.LBE186:
.LBE190:
	.loc 1 187 0
	movss	xmm1, DWORD PTR .LC3[rip]
.LBB191:
.LBB187:
	.loc 1 174 0
	movss	xmm3, DWORD PTR 8[rdi]
	movss	xmm5, DWORD PTR 8[rsi]
	movss	xmm2, DWORD PTR 4[rdi]
	movss	xmm4, DWORD PTR 4[rsi]
.LVL80:
.LBE187:
.LBE191:
	.loc 1 187 0
	ucomiss	xmm1, xmm0
	ja	.L44
	.loc 1 188 0
	ucomiss	xmm0, DWORD PTR .LC4[rip]
	ja	.L44
.LBB192:
.LBB188:
	.loc 1 174 0
	subss	xmm2, xmm4
.LVL81:
.LBE188:
.LBE192:
	.loc 1 189 0
	ucomiss	xmm1, xmm2
	ja	.L44
	.loc 1 190 0
	ucomiss	xmm2, DWORD PTR .LC4[rip]
	ja	.L44
.LBB193:
.LBB189:
	.loc 1 174 0
	subss	xmm3, xmm5
.LVL82:
.LBE189:
.LBE193:
	.loc 1 191 0
	ucomiss	xmm1, xmm3
	ja	.L44
	.loc 1 192 0
	ucomiss	xmm3, DWORD PTR .LC4[rip]
	setbe	al
.LVL83:
.L44:
	.loc 1 194 0
	rep ret
	.cfi_endproc
.LFE51:
	.size	vec3equiv, .-vec3equiv
	.p2align 4,,15
	.globl	areOrthogonal
	.type	areOrthogonal, @function
areOrthogonal:
.LFB52:
	.loc 1 197 0
	.cfi_startproc
.LVL84:
	.loc 1 198 0
	movss	xmm0, DWORD PTR [rdi]
	mov	edx, 0
	movss	xmm1, DWORD PTR 4[rdi]
	mulss	xmm0, DWORD PTR [rsi]
	mulss	xmm1, DWORD PTR 4[rsi]
	addss	xmm0, xmm1
	movss	xmm1, DWORD PTR 8[rdi]
	mulss	xmm1, DWORD PTR 8[rsi]
	addss	xmm0, xmm1
	pxor	xmm1, xmm1
	ucomiss	xmm0, xmm1
	setnp	al
	cmovne	eax, edx
	.loc 1 199 0
	ret
	.cfi_endproc
.LFE52:
	.size	areOrthogonal, .-areOrthogonal
	.p2align 4,,15
	.globl	ray_plane_intersection
	.type	ray_plane_intersection, @function
ray_plane_intersection:
.LFB53:
	.loc 1 203 0
	.cfi_startproc
.LVL85:
	.loc 1 207 0
	mov	rax, QWORD PTR 8[rcx]
.LVL86:
	mov	r8, QWORD PTR [rcx]
.LBB194:
.LBB195:
	.loc 1 25 0
	movss	xmm2, DWORD PTR 4[rdx]
	.loc 1 24 0
	movss	xmm12, DWORD PTR [rdx]
.LBE195:
.LBE194:
.LBB197:
.LBB198:
	.loc 1 136 0
	movaps	xmm3, xmm2
.LBE198:
.LBE197:
.LBB203:
.LBB204:
	.loc 1 48 0
	movss	xmm15, DWORD PTR [rax]
	.loc 1 49 0
	movss	xmm9, DWORD PTR 4[rax]
.LBE204:
.LBE203:
.LBB211:
.LBB199:
	.loc 1 136 0
	movaps	xmm10, xmm12
.LBE199:
.LBE211:
.LBB212:
.LBB205:
	.loc 1 50 0
	movss	xmm4, DWORD PTR 8[rax]
.LBE205:
.LBE212:
	.loc 1 208 0
	mov	rax, QWORD PTR 16[rcx]
.LVL87:
.LBB213:
.LBB206:
	.loc 1 48 0
	movss	xmm8, DWORD PTR [r8]
	.loc 1 49 0
	movss	xmm14, DWORD PTR 4[r8]
.LBE206:
.LBE213:
.LBB214:
.LBB200:
	.loc 1 135 0
	movaps	xmm5, xmm12
.LBE200:
.LBE214:
.LBB215:
.LBB216:
	.loc 1 48 0
	movss	xmm1, DWORD PTR [rax]
.LBE216:
.LBE215:
.LBB220:
.LBB207:
	subss	xmm15, xmm8
.LVL88:
.LBE207:
.LBE220:
.LBB221:
.LBB217:
	.loc 1 49 0
	movss	xmm7, DWORD PTR 4[rax]
	.loc 1 48 0
	subss	xmm1, xmm8
	.loc 1 49 0
	subss	xmm7, xmm14
.LBE217:
.LBE221:
.LBB222:
.LBB208:
	.loc 1 50 0
	movss	xmm0, DWORD PTR 8[r8]
.LBE208:
.LBE222:
.LBB223:
.LBB218:
	movss	xmm6, DWORD PTR 8[rax]
.LBE218:
.LBE223:
.LBB224:
.LBB209:
	.loc 1 49 0
	subss	xmm9, xmm14
.LVL89:
.LBE209:
.LBE224:
.LBB225:
.LBB219:
	.loc 1 50 0
	subss	xmm6, xmm0
.LBE219:
.LBE225:
.LBB226:
.LBB196:
	.loc 1 26 0
	movss	xmm11, DWORD PTR 8[rdx]
.LBE196:
.LBE226:
.LBB227:
.LBB201:
	.loc 1 136 0
	mulss	xmm3, xmm1
	.loc 1 135 0
	movaps	xmm13, xmm11
	.loc 1 136 0
	mulss	xmm10, xmm7
.LBE201:
.LBE227:
.LBB228:
.LBB210:
	.loc 1 50 0
	subss	xmm4, xmm0
.LVL90:
.LBE210:
.LBE228:
.LBB229:
.LBB202:
	.loc 1 135 0
	mulss	xmm13, xmm1
	mulss	xmm5, xmm6
.LVL91:
	.loc 1 134 0
	subss	xmm10, xmm3
	movaps	xmm3, xmm2
	movaps	xmm2, xmm11
.LVL92:
	mulss	xmm3, xmm6
.LVL93:
	subss	xmm13, xmm5
	mulss	xmm2, xmm7
	subss	xmm3, xmm2
.LVL94:
.LBE202:
.LBE229:
.LBB230:
.LBB231:
	.loc 1 146 0
	movaps	xmm2, xmm13
	mulss	xmm2, xmm7
	movaps	xmm5, xmm3
	mulss	xmm5, xmm1
	addss	xmm5, xmm2
	movaps	xmm2, xmm10
	mulss	xmm2, xmm6
	addss	xmm5, xmm2
.LVL95:
.LBE231:
.LBE230:
	.loc 1 213 0
	movss	xmm2, DWORD PTR .LC4[rip]
	ucomiss	xmm2, xmm5
	ja	.L56
.LVL96:
.LBB232:
.LBB233:
	.loc 1 48 0
	movss	xmm2, DWORD PTR [rsi]
	subss	xmm2, xmm8
	movaps	xmm8, xmm2
.LVL97:
	.loc 1 49 0
	movss	xmm2, DWORD PTR 4[rsi]
.LVL98:
	subss	xmm2, xmm14
.LBE233:
.LBE232:
.LBB235:
.LBB236:
	.loc 1 146 0
	mulss	xmm3, xmm8
.LVL99:
.LBE236:
.LBE235:
.LBB239:
.LBB234:
	.loc 1 49 0
	movaps	xmm14, xmm2
.LVL100:
	.loc 1 50 0
	movss	xmm2, DWORD PTR 8[rsi]
.LVL101:
	subss	xmm2, xmm0
.LVL102:
.LBE234:
.LBE239:
.LBB240:
.LBB237:
	.loc 1 146 0
	movaps	xmm0, xmm13
.LBE237:
.LBE240:
	.loc 1 217 0
	movss	xmm13, DWORD PTR .LC3[rip]
.LVL103:
.LBB241:
.LBB238:
	.loc 1 146 0
	mulss	xmm0, xmm14
.LVL104:
	addss	xmm3, xmm0
	movaps	xmm0, xmm10
	mulss	xmm0, xmm2
	addss	xmm0, xmm3
.LVL105:
.LBE238:
.LBE241:
	.loc 1 217 0
	ucomiss	xmm13, xmm0
	.loc 1 215 0
	movss	DWORD PTR 4[rdi], xmm0
.LVL106:
	.loc 1 217 0
	ja	.L56
	.loc 1 217 0 is_stmt 0 discriminator 2
	ucomiss	xmm0, xmm5
	ja	.L56
.LVL107:
.LBB242:
.LBB243:
	.loc 1 136 0 is_stmt 1
	movaps	xmm10, xmm9
.LVL108:
	movaps	xmm3, xmm15
	.loc 1 134 0
	mulss	xmm9, xmm2
.LVL109:
	.loc 1 136 0
	mulss	xmm10, xmm8
.LVL110:
	mulss	xmm3, xmm14
	.loc 1 135 0
	mulss	xmm8, xmm4
.LVL111:
	.loc 1 134 0
	mulss	xmm4, xmm14
.LVL112:
	subss	xmm10, xmm3
	.loc 1 135 0
	movaps	xmm3, xmm15
	mulss	xmm3, xmm2
	.loc 1 134 0
	subss	xmm4, xmm9
.LVL113:
.LBE243:
.LBE242:
.LBB245:
.LBB246:
	.loc 1 146 0
	movss	xmm2, DWORD PTR 4[rdx]
.LVL114:
	mulss	xmm11, xmm10
.LVL115:
.LBE246:
.LBE245:
.LBB248:
.LBB244:
	.loc 1 134 0
	subss	xmm3, xmm8
.LVL116:
.LBE244:
.LBE248:
.LBB249:
.LBB247:
	.loc 1 146 0
	mulss	xmm12, xmm4
.LVL117:
	mulss	xmm2, xmm3
	addss	xmm2, xmm12
	addss	xmm2, xmm11
.LVL118:
.LBE247:
.LBE249:
	.loc 1 221 0
	ucomiss	xmm13, xmm2
	.loc 1 219 0
	movss	DWORD PTR [rdi], xmm2
.LVL119:
	.loc 1 221 0
	ja	.L56
	.loc 1 221 0 is_stmt 0 discriminator 2
	movaps	xmm8, xmm0
	addss	xmm8, xmm2
	ucomiss	xmm8, xmm5
	ja	.L56
	.loc 1 225 0 is_stmt 1
	movss	xmm8, DWORD PTR .LC2[rip]
.LBB250:
.LBB251:
	.loc 1 146 0
	mulss	xmm7, xmm3
.LVL120:
.LBE251:
.LBE250:
	.loc 1 225 0
	mov	rax, rdi
	divss	xmm8, xmm5
.LVL121:
.LBB255:
.LBB252:
	.loc 1 146 0
	mulss	xmm1, xmm4
.LVL122:
	mulss	xmm6, xmm10
.LVL123:
.LBE252:
.LBE255:
.LBB256:
.LBB257:
	.loc 1 86 0
	mulss	xmm0, xmm8
	mulss	xmm2, xmm8
	movss	DWORD PTR 4[rdi], xmm0
.LBE257:
.LBE256:
.LBB260:
.LBB253:
	.loc 1 146 0
	movaps	xmm0, xmm7
.LBE253:
.LBE260:
.LBB261:
.LBB258:
	.loc 1 86 0
	movss	DWORD PTR [rdi], xmm2
.LBE258:
.LBE261:
.LBB262:
.LBB254:
	.loc 1 146 0
	addss	xmm0, xmm1
	addss	xmm0, xmm6
.LBE254:
.LBE262:
.LBB263:
.LBB259:
	.loc 1 86 0
	mulss	xmm0, xmm8
	movss	DWORD PTR 8[rdi], xmm0
.LVL124:
.LBE259:
.LBE263:
	.loc 1 226 0
	ret
.LVL125:
	.p2align 4,,10
	.p2align 3
.L56:
	.loc 1 213 0
	xor	eax, eax
	ret
	.cfi_endproc
.LFE53:
	.size	ray_plane_intersection, .-ray_plane_intersection
	.p2align 4,,15
	.globl	ray_and_plane_intersection
	.type	ray_and_plane_intersection, @function
ray_and_plane_intersection:
.LFB54:
	.loc 1 229 0
	.cfi_startproc
.LVL126:
.LBB264:
.LBB265:
	.loc 1 48 0
	movss	xmm8, DWORD PTR [rcx]
	.loc 1 49 0
	movss	xmm14, DWORD PTR 4[rcx]
.LBE265:
.LBE264:
.LBB272:
.LBB273:
	.loc 1 48 0
	movss	xmm1, DWORD PTR [r9]
	.loc 1 49 0
	movss	xmm7, DWORD PTR 4[r9]
	.loc 1 48 0
	subss	xmm1, xmm8
	.loc 1 49 0
	subss	xmm7, xmm14
.LBE273:
.LBE272:
.LBB276:
.LBB277:
	.loc 1 25 0
	movss	xmm2, DWORD PTR 4[rdx]
	.loc 1 24 0
	movss	xmm12, DWORD PTR [rdx]
.LBE277:
.LBE276:
.LBB279:
.LBB280:
	.loc 1 136 0
	movaps	xmm3, xmm2
	movaps	xmm10, xmm12
.LBE280:
.LBE279:
.LBB289:
.LBB266:
	.loc 1 50 0
	movss	xmm0, DWORD PTR 8[rcx]
.LBE266:
.LBE289:
.LBB290:
.LBB281:
	.loc 1 136 0
	mulss	xmm3, xmm1
.LBE281:
.LBE290:
.LBB291:
.LBB274:
	.loc 1 50 0
	movss	xmm6, DWORD PTR 8[r9]
.LBE274:
.LBE291:
.LBB292:
.LBB282:
	.loc 1 136 0
	mulss	xmm10, xmm7
.LBE282:
.LBE292:
.LBB293:
.LBB275:
	.loc 1 50 0
	subss	xmm6, xmm0
.LBE275:
.LBE293:
.LBB294:
.LBB278:
	.loc 1 26 0
	movss	xmm11, DWORD PTR 8[rdx]
.LBE278:
.LBE294:
.LBB295:
.LBB283:
	.loc 1 135 0
	movaps	xmm5, xmm12
	movaps	xmm13, xmm11
.LBE283:
.LBE295:
.LBB296:
.LBB267:
	.loc 1 48 0
	movss	xmm15, DWORD PTR [r8]
.LBE267:
.LBE296:
.LBB297:
.LBB284:
	.loc 1 134 0
	subss	xmm10, xmm3
	movaps	xmm3, xmm2
	movaps	xmm2, xmm11
	.loc 1 135 0
	mulss	xmm5, xmm6
	mulss	xmm13, xmm1
.LBE284:
.LBE297:
.LBB298:
.LBB268:
	.loc 1 49 0
	movss	xmm9, DWORD PTR 4[r8]
.LBE268:
.LBE298:
.LBB299:
.LBB285:
	.loc 1 134 0
	mulss	xmm2, xmm7
.LBE285:
.LBE299:
.LBB300:
.LBB269:
	.loc 1 50 0
	movss	xmm4, DWORD PTR 8[r8]
.LBE269:
.LBE300:
.LBB301:
.LBB286:
	.loc 1 134 0
	mulss	xmm3, xmm6
.LBE286:
.LBE301:
.LBB302:
.LBB270:
	.loc 1 48 0
	subss	xmm15, xmm8
.LVL127:
	.loc 1 49 0
	subss	xmm9, xmm14
.LVL128:
.LBE270:
.LBE302:
.LBB303:
.LBB287:
	.loc 1 134 0
	subss	xmm13, xmm5
.LBE287:
.LBE303:
.LBB304:
.LBB271:
	.loc 1 50 0
	subss	xmm4, xmm0
.LVL129:
.LBE271:
.LBE304:
.LBB305:
.LBB288:
	.loc 1 134 0
	subss	xmm3, xmm2
.LVL130:
.LBE288:
.LBE305:
.LBB306:
.LBB307:
	.loc 1 146 0
	movaps	xmm2, xmm13
	movaps	xmm5, xmm3
	mulss	xmm2, xmm7
	mulss	xmm5, xmm1
	addss	xmm5, xmm2
	movaps	xmm2, xmm10
	mulss	xmm2, xmm6
	addss	xmm5, xmm2
.LVL131:
.LBE307:
.LBE306:
	.loc 1 240 0
	movss	xmm2, DWORD PTR .LC4[rip]
	ucomiss	xmm2, xmm5
	ja	.L62
.LVL132:
.LBB308:
.LBB309:
	.loc 1 48 0
	movss	xmm2, DWORD PTR [rsi]
	subss	xmm2, xmm8
	movaps	xmm8, xmm2
.LVL133:
	.loc 1 49 0
	movss	xmm2, DWORD PTR 4[rsi]
.LVL134:
	subss	xmm2, xmm14
.LBE309:
.LBE308:
.LBB311:
.LBB312:
	.loc 1 146 0
	mulss	xmm3, xmm8
.LVL135:
.LBE312:
.LBE311:
.LBB315:
.LBB310:
	.loc 1 49 0
	movaps	xmm14, xmm2
.LVL136:
	.loc 1 50 0
	movss	xmm2, DWORD PTR 8[rsi]
.LVL137:
	subss	xmm2, xmm0
.LVL138:
.LBE310:
.LBE315:
.LBB316:
.LBB313:
	.loc 1 146 0
	movaps	xmm0, xmm13
.LBE313:
.LBE316:
	.loc 1 244 0
	pxor	xmm13, xmm13
.LVL139:
.LBB317:
.LBB314:
	.loc 1 146 0
	mulss	xmm0, xmm14
.LVL140:
	addss	xmm3, xmm0
	movaps	xmm0, xmm10
	mulss	xmm0, xmm2
	addss	xmm0, xmm3
.LVL141:
.LBE314:
.LBE317:
	.loc 1 244 0
	ucomiss	xmm13, xmm0
	.loc 1 242 0
	movss	DWORD PTR 4[rdi], xmm0
.LVL142:
	.loc 1 244 0
	ja	.L62
	.loc 1 244 0 is_stmt 0 discriminator 2
	ucomiss	xmm0, xmm5
	ja	.L62
.LVL143:
.LBB318:
.LBB319:
	.loc 1 136 0 is_stmt 1
	movaps	xmm10, xmm9
.LVL144:
	movaps	xmm3, xmm15
	.loc 1 134 0
	mulss	xmm9, xmm2
.LVL145:
	.loc 1 136 0
	mulss	xmm10, xmm8
.LVL146:
	mulss	xmm3, xmm14
	.loc 1 135 0
	mulss	xmm8, xmm4
.LVL147:
	.loc 1 134 0
	mulss	xmm4, xmm14
.LVL148:
	subss	xmm10, xmm3
	.loc 1 135 0
	movaps	xmm3, xmm15
	mulss	xmm3, xmm2
	.loc 1 134 0
	subss	xmm4, xmm9
.LVL149:
.LBE319:
.LBE318:
.LBB321:
.LBB322:
	.loc 1 146 0
	movss	xmm2, DWORD PTR 4[rdx]
.LVL150:
	mulss	xmm11, xmm10
.LVL151:
.LBE322:
.LBE321:
.LBB324:
.LBB320:
	.loc 1 134 0
	subss	xmm3, xmm8
.LVL152:
.LBE320:
.LBE324:
.LBB325:
.LBB323:
	.loc 1 146 0
	mulss	xmm12, xmm4
.LVL153:
	mulss	xmm2, xmm3
	addss	xmm2, xmm12
	addss	xmm2, xmm11
.LVL154:
.LBE323:
.LBE325:
	.loc 1 248 0
	ucomiss	xmm13, xmm2
	.loc 1 246 0
	movss	DWORD PTR [rdi], xmm2
.LVL155:
	.loc 1 248 0
	ja	.L62
	.loc 1 248 0 is_stmt 0 discriminator 2
	movaps	xmm8, xmm0
	addss	xmm8, xmm2
	ucomiss	xmm8, xmm5
	ja	.L62
	.loc 1 252 0 is_stmt 1
	movss	xmm8, DWORD PTR .LC2[rip]
.LBB326:
.LBB327:
	.loc 1 146 0
	mulss	xmm7, xmm3
.LVL156:
.LBE327:
.LBE326:
	.loc 1 252 0
	mov	rax, rdi
	divss	xmm8, xmm5
.LVL157:
.LBB331:
.LBB328:
	.loc 1 146 0
	mulss	xmm1, xmm4
.LVL158:
	mulss	xmm6, xmm10
.LVL159:
.LBE328:
.LBE331:
.LBB332:
.LBB333:
	.loc 1 86 0
	mulss	xmm0, xmm8
	mulss	xmm2, xmm8
	movss	DWORD PTR 4[rdi], xmm0
.LBE333:
.LBE332:
.LBB336:
.LBB329:
	.loc 1 146 0
	movaps	xmm0, xmm7
.LBE329:
.LBE336:
.LBB337:
.LBB334:
	.loc 1 86 0
	movss	DWORD PTR [rdi], xmm2
.LBE334:
.LBE337:
.LBB338:
.LBB330:
	.loc 1 146 0
	addss	xmm0, xmm1
	addss	xmm0, xmm6
.LBE330:
.LBE338:
.LBB339:
.LBB335:
	.loc 1 86 0
	mulss	xmm0, xmm8
	movss	DWORD PTR 8[rdi], xmm0
.LVL160:
.LBE335:
.LBE339:
	.loc 1 263 0
	ret
.LVL161:
	.p2align 4,,10
	.p2align 3
.L62:
	.loc 1 240 0
	xor	eax, eax
	ret
	.cfi_endproc
.LFE54:
	.size	ray_and_plane_intersection, .-ray_and_plane_intersection
	.p2align 4,,15
	.globl	vectorAndPlaneIntersection
	.type	vectorAndPlaneIntersection, @function
vectorAndPlaneIntersection:
.LFB55:
	.loc 1 270 0
	.cfi_startproc
.LVL162:
	sub	rsp, 88
	.cfi_def_cfa_offset 96
	pxor	xmm10, xmm10
.LBB364:
.LBB365:
	.loc 1 100 0
	movss	xmm1, DWORD PTR [rdx]
	movss	xmm7, DWORD PTR 4[rdx]
	movaps	xmm2, xmm1
	movaps	xmm0, xmm7
	mulss	xmm2, xmm1
	movss	xmm4, DWORD PTR 8[rdx]
	mulss	xmm0, xmm7
	addss	xmm2, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, xmm4
	addss	xmm0, xmm2
	ucomiss	xmm10, xmm0
	sqrtss	xmm5, xmm0
	ja	.L72
.LVL163:
.L65:
	movss	xmm3, DWORD PTR .LC2[rip]
	movaps	xmm8, xmm3
	divss	xmm8, xmm5
.LVL164:
	.loc 1 103 0
	mulss	xmm1, xmm8
	mulss	xmm7, xmm8
	mulss	xmm8, xmm4
.LVL165:
	movss	DWORD PTR [rdx], xmm1
	movaps	xmm9, xmm1
	movss	DWORD PTR 4[rdx], xmm7
.LBE365:
.LBE364:
.LBB368:
.LBB369:
.LBB370:
.LBB371:
	.loc 1 48 0
	movss	xmm6, DWORD PTR [r8]
	.loc 1 49 0
	movss	xmm5, DWORD PTR 4[r8]
.LVL166:
	.loc 1 48 0
	subss	xmm6, DWORD PTR [rcx]
.LBE371:
.LBE370:
.LBE369:
.LBE368:
.LBB383:
.LBB366:
	.loc 1 103 0
	movss	DWORD PTR 8[rdx], xmm8
.LVL167:
.LBE366:
.LBE383:
.LBB384:
.LBB380:
.LBB373:
.LBB372:
	.loc 1 49 0
	subss	xmm5, DWORD PTR 4[rcx]
	.loc 1 50 0
	movss	xmm4, DWORD PTR 8[r8]
	subss	xmm4, DWORD PTR 8[rcx]
.LVL168:
.LBE372:
.LBE373:
.LBB374:
.LBB375:
	.loc 1 100 0
	movaps	xmm2, xmm6
	movaps	xmm0, xmm5
	mulss	xmm2, xmm6
	mulss	xmm0, xmm5
	addss	xmm2, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, xmm4
	addss	xmm0, xmm2
	ucomiss	xmm10, xmm0
	sqrtss	xmm1, xmm0
	ja	.L73
.LVL169:
.L66:
	divss	xmm3, xmm1
.LVL170:
.LBE375:
.LBE374:
.LBE380:
.LBE384:
.LBB385:
.LBB386:
	.loc 1 198 0
	movaps	xmm2, xmm9
.LBE386:
.LBE385:
.LBB388:
.LBB381:
.LBB378:
.LBB376:
	.loc 1 103 0
	mulss	xmm5, xmm3
	mulss	xmm6, xmm3
	mulss	xmm4, xmm3
.LVL171:
.LBE376:
.LBE378:
.LBE381:
.LBE388:
.LBB389:
.LBB387:
	.loc 1 198 0
	movaps	xmm0, xmm5
	mulss	xmm2, xmm6
	mulss	xmm0, xmm7
	addss	xmm2, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, xmm8
	addss	xmm2, xmm0
.LVL172:
.LBE387:
.LBE389:
	.loc 1 275 0
	ucomiss	xmm2, xmm10
	jp	.L70
	.loc 1 277 0
	mov	eax, 0
	.loc 1 275 0
	je	.L64
.L70:
.LVL173:
.LBB390:
.LBB391:
	.loc 1 48 0
	movss	xmm11, DWORD PTR [rcx]
.LVL174:
.LBE391:
.LBE390:
	.loc 1 291 0
	mov	eax, 1
.LBB394:
.LBB392:
	.loc 1 49 0
	movss	xmm10, DWORD PTR 4[rcx]
.LVL175:
	.loc 1 48 0
	movss	xmm1, DWORD PTR [rsi]
	.loc 1 49 0
	movss	xmm0, DWORD PTR 4[rsi]
	.loc 1 48 0
	subss	xmm1, xmm11
.LVL176:
	.loc 1 49 0
	subss	xmm0, xmm10
.LVL177:
	.loc 1 50 0
	movss	xmm3, DWORD PTR 8[rcx]
.LVL178:
.LBE392:
.LBE394:
.LBB395:
.LBB396:
	.loc 1 146 0
	mulss	xmm1, xmm9
.LVL179:
	mulss	xmm0, xmm7
.LVL180:
	addss	xmm1, xmm0
.LBE396:
.LBE395:
.LBB398:
.LBB393:
	.loc 1 50 0
	movss	xmm0, DWORD PTR 8[rsi]
	subss	xmm0, xmm3
.LVL181:
.LBE393:
.LBE398:
.LBB399:
.LBB397:
	.loc 1 146 0
	mulss	xmm0, xmm8
.LVL182:
	addss	xmm0, xmm1
.LVL183:
.LBE397:
.LBE399:
	.loc 1 287 0
	mulss	xmm6, xmm0
.LVL184:
	.loc 1 288 0
	mulss	xmm5, xmm0
.LVL185:
	.loc 1 289 0
	mulss	xmm0, xmm4
.LVL186:
	.loc 1 287 0
	divss	xmm6, xmm2
	.loc 1 288 0
	divss	xmm5, xmm2
	.loc 1 287 0
	addss	xmm6, xmm11
.LVL187:
.LBB400:
.LBB401:
	.loc 1 24 0
	movss	DWORD PTR [rdi], xmm6
.LVL188:
.LBE401:
.LBE400:
	.loc 1 289 0
	divss	xmm0, xmm2
	.loc 1 287 0
	addss	xmm5, xmm10
.LVL189:
.LBB404:
.LBB402:
	.loc 1 25 0
	movss	DWORD PTR 4[rdi], xmm5
.LVL190:
.LBE402:
.LBE404:
	.loc 1 287 0
	addss	xmm0, xmm3
.LVL191:
.LBB405:
.LBB403:
	.loc 1 26 0
	movss	DWORD PTR 8[rdi], xmm0
.LVL192:
.L64:
.LBE403:
.LBE405:
	.loc 1 292 0
	add	rsp, 88
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.LVL193:
.L72:
	.cfi_restore_state
	movss	DWORD PTR 56[rsp], xmm10
	mov	QWORD PTR 48[rsp], r8
	mov	QWORD PTR 40[rsp], rcx
	mov	QWORD PTR 32[rsp], rdx
	mov	QWORD PTR 24[rsp], rsi
	movss	DWORD PTR 12[rsp], xmm5
	mov	QWORD PTR 16[rsp], rdi
.LBB406:
.LBB367:
	.loc 1 100 0
	call	sqrtf@PLT
.LVL194:
	mov	rdx, QWORD PTR 32[rsp]
	movss	xmm10, DWORD PTR 56[rsp]
	mov	r8, QWORD PTR 48[rsp]
	mov	rcx, QWORD PTR 40[rsp]
	mov	rsi, QWORD PTR 24[rsp]
	mov	rdi, QWORD PTR 16[rsp]
	movss	xmm1, DWORD PTR [rdx]
	movss	xmm7, DWORD PTR 4[rdx]
	movss	xmm4, DWORD PTR 8[rdx]
	movss	xmm5, DWORD PTR 12[rsp]
	jmp	.L65
.LVL195:
.L73:
	movss	DWORD PTR 76[rsp], xmm3
	mov	QWORD PTR 64[rsp], rcx
	mov	QWORD PTR 56[rsp], rdx
	movss	DWORD PTR 72[rsp], xmm10
	mov	QWORD PTR 48[rsp], rsi
	mov	QWORD PTR 40[rsp], rdi
	movss	DWORD PTR 32[rsp], xmm1
	movss	DWORD PTR 24[rsp], xmm4
	movss	DWORD PTR 16[rsp], xmm5
	movss	DWORD PTR 12[rsp], xmm6
.LBE367:
.LBE406:
.LBB407:
.LBB382:
.LBB379:
.LBB377:
	call	sqrtf@PLT
.LVL196:
	mov	rdx, QWORD PTR 56[rsp]
	movss	xmm3, DWORD PTR 76[rsp]
	mov	rcx, QWORD PTR 64[rsp]
	movss	xmm10, DWORD PTR 72[rsp]
	mov	rsi, QWORD PTR 48[rsp]
	movss	xmm9, DWORD PTR [rdx]
	mov	rdi, QWORD PTR 40[rsp]
	movss	xmm7, DWORD PTR 4[rdx]
	movss	xmm8, DWORD PTR 8[rdx]
	movss	xmm1, DWORD PTR 32[rsp]
	movss	xmm4, DWORD PTR 24[rsp]
	movss	xmm5, DWORD PTR 16[rsp]
	movss	xmm6, DWORD PTR 12[rsp]
	jmp	.L66
.LBE377:
.LBE379:
.LBE382:
.LBE407:
	.cfi_endproc
.LFE55:
	.size	vectorAndPlaneIntersection, .-vectorAndPlaneIntersection
	.p2align 4,,15
	.globl	vec3projectPoint
	.type	vec3projectPoint, @function
vec3projectPoint:
.LFB56:
	.loc 1 295 0
	.cfi_startproc
.LVL197:
.LBB408:
.LBB409:
	.loc 1 86 0
	movss	xmm3, DWORD PTR 4[rsi]
.LBE409:
.LBE408:
	.loc 1 295 0
	mov	rax, rdi
.LBB412:
.LBB410:
	.loc 1 86 0
	movss	xmm2, DWORD PTR 8[rsi]
	mulss	xmm3, xmm0
.LVL198:
	mulss	xmm2, xmm0
.LVL199:
.LBE410:
.LBE412:
.LBB413:
.LBB414:
	.loc 1 48 0
	movss	xmm1, DWORD PTR [rdi]
.LBE414:
.LBE413:
.LBB416:
.LBB411:
	.loc 1 86 0
	mulss	xmm0, DWORD PTR [rsi]
.LVL200:
.LBE411:
.LBE416:
.LBB417:
.LBB415:
	.loc 1 48 0
	subss	xmm1, xmm0
	.loc 1 49 0
	movss	xmm0, DWORD PTR 4[rdi]
.LVL201:
	subss	xmm0, xmm3
	.loc 1 48 0
	movss	DWORD PTR [rax], xmm1
.LVL202:
	.loc 1 49 0
	movss	DWORD PTR 4[rdi], xmm0
	.loc 1 50 0
	movss	xmm0, DWORD PTR 8[rdi]
	subss	xmm0, xmm2
	movss	DWORD PTR 8[rdi], xmm0
.LVL203:
.LBE415:
.LBE417:
	.loc 1 298 0
	ret
	.cfi_endproc
.LFE56:
	.size	vec3projectPoint, .-vec3projectPoint
	.p2align 4,,15
	.globl	vec3attenuation
	.type	vec3attenuation, @function
vec3attenuation:
.LFB57:
	.loc 1 304 0
	.cfi_startproc
.LVL204:
	.loc 1 305 0
	divss	xmm0, xmm1
.LVL205:
	movaps	xmm1, xmm0
.LVL206:
	.loc 1 306 0
	pxor	xmm0, xmm0
.LVL207:
	ucomiss	xmm0, xmm1
	ja	.L77
	.loc 1 306 0 is_stmt 0 discriminator 2
	movss	xmm2, DWORD PTR .LC2[rip]
	ucomiss	xmm1, xmm2
	jbe	.L79
	.loc 1 307 0 is_stmt 1
	rep ret
	.p2align 4,,10
	.p2align 3
.L79:
	.loc 1 306 0 discriminator 5
	subss	xmm2, xmm1
	movaps	xmm0, xmm2
	ret
	.p2align 4,,10
	.p2align 3
.L77:
	.loc 1 306 0 is_stmt 0
	movss	xmm0, DWORD PTR .LC2[rip]
	.loc 1 307 0 is_stmt 1
	ret
	.cfi_endproc
.LFE57:
	.size	vec3attenuation, .-vec3attenuation
	.p2align 4,,15
	.globl	pointInSphere
	.type	pointInSphere, @function
pointInSphere:
.LFB58:
	.loc 1 311 0
	.cfi_startproc
.LVL208:
	.loc 1 312 0
	movss	xmm1, DWORD PTR [rdi]
	.loc 1 315 0
	mulss	xmm0, xmm0
.LVL209:
	.loc 1 313 0
	movss	xmm3, DWORD PTR 4[rdi]
	.loc 1 312 0
	subss	xmm1, DWORD PTR [rsi]
.LVL210:
	.loc 1 313 0
	subss	xmm3, DWORD PTR 4[rsi]
.LVL211:
	.loc 1 314 0
	movss	xmm2, DWORD PTR 8[rdi]
	subss	xmm2, DWORD PTR 8[rsi]
.LVL212:
	.loc 1 315 0
	mulss	xmm1, xmm1
.LVL213:
	mulss	xmm3, xmm3
.LVL214:
	mulss	xmm2, xmm2
.LVL215:
	addss	xmm1, xmm3
	addss	xmm1, xmm2
	ucomiss	xmm0, xmm1
	setnb	al
	.loc 1 316 0
	ret
	.cfi_endproc
.LFE58:
	.size	pointInSphere, .-pointInSphere
	.p2align 4,,15
	.globl	vec3computeLineDistance
	.type	vec3computeLineDistance, @function
vec3computeLineDistance:
.LFB59:
	.loc 1 320 0
	.cfi_startproc
.LVL216:
	.loc 1 321 0
	movss	xmm1, DWORD PTR [rdi]
	movss	xmm2, DWORD PTR 4[rdi]
	mulss	xmm1, xmm0
	mulss	xmm2, xmm0
	mulss	xmm0, DWORD PTR 8[rdi]
.LVL217:
	mulss	xmm1, DWORD PTR [rsi]
	mulss	xmm2, DWORD PTR 4[rsi]
	mulss	xmm0, DWORD PTR 8[rsi]
	addss	xmm1, xmm2
	addss	xmm0, xmm1
	addss	xmm0, DWORD PTR 12[rdi]
	.loc 1 322 0
	ret
	.cfi_endproc
.LFE59:
	.size	vec3computeLineDistance, .-vec3computeLineDistance
	.p2align 4,,15
	.globl	vec3computeLineCoefficients
	.type	vec3computeLineCoefficients, @function
vec3computeLineCoefficients:
.LFB60:
	.loc 1 325 0
	.cfi_startproc
.LVL218:
	sub	rsp, 40
	.cfi_def_cfa_offset 48
	.loc 1 326 0
	movss	xmm1, DWORD PTR 4[rsi]
	movss	xmm2, DWORD PTR 4[rdx]
	subss	xmm2, xmm1
	.loc 1 327 0
	movss	xmm6, DWORD PTR 4[rcx]
	.loc 1 326 0
	movss	xmm4, DWORD PTR 8[rsi]
	.loc 1 327 0
	subss	xmm6, xmm1
	.loc 1 326 0
	movss	xmm0, DWORD PTR [rsi]
	movss	xmm5, DWORD PTR 8[rdx]
	movss	xmm3, DWORD PTR [rdx]
	subss	xmm5, xmm4
	.loc 1 327 0
	movss	xmm7, DWORD PTR 8[rcx]
	.loc 1 326 0
	subss	xmm3, xmm0
.LVL219:
	.loc 1 327 0
	movss	xmm1, DWORD PTR [rcx]
	subss	xmm7, xmm4
	subss	xmm1, xmm0
.LVL220:
.LBB428:
.LBB429:
	.loc 1 136 0
	movaps	xmm8, xmm2
	movaps	xmm0, xmm3
	.loc 1 134 0
	mulss	xmm2, xmm7
.LVL221:
	.loc 1 136 0
	mulss	xmm8, xmm1
.LVL222:
	.loc 1 135 0
	mulss	xmm3, xmm7
.LVL223:
	mulss	xmm1, xmm5
.LVL224:
	.loc 1 134 0
	mulss	xmm5, xmm6
.LVL225:
	.loc 1 136 0
	mulss	xmm0, xmm6
.LVL226:
	.loc 1 134 0
	subss	xmm1, xmm3
	subss	xmm2, xmm5
.LVL227:
	movaps	xmm4, xmm0
.LVL228:
.LBE429:
.LBE428:
.LBB431:
.LBB432:
	.loc 1 100 0
	movaps	xmm0, xmm1
	movaps	xmm3, xmm2
.LBE432:
.LBE431:
.LBB435:
.LBB430:
	.loc 1 134 0
	subss	xmm4, xmm8
.LBE430:
.LBE435:
.LBB436:
.LBB433:
	.loc 1 100 0
	mulss	xmm0, xmm1
	mulss	xmm3, xmm2
	addss	xmm3, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, xmm4
	addss	xmm3, xmm0
	pxor	xmm0, xmm0
	ucomiss	xmm0, xmm3
	sqrtss	xmm5, xmm3
	ja	.L85
.LVL229:
.L83:
	movss	xmm0, DWORD PTR .LC2[rip]
	divss	xmm0, xmm5
.LVL230:
	.loc 1 103 0
	mulss	xmm1, xmm0
	mulss	xmm2, xmm0
	mulss	xmm0, xmm4
.LVL231:
.LBE433:
.LBE436:
	.loc 1 331 0
	movss	DWORD PTR 4[rdi], xmm1
.LBB437:
.LBB438:
	.loc 1 56 0
	xorps	xmm1, XMMWORD PTR .LC0[rip]
.LBE438:
.LBE437:
	.loc 1 330 0
	movss	DWORD PTR [rdi], xmm2
	.loc 1 332 0
	movss	DWORD PTR 8[rdi], xmm0
.LBB439:
.LBB440:
	.loc 1 146 0
	mulss	xmm2, DWORD PTR [rsi]
	mulss	xmm1, DWORD PTR 4[rsi]
	mulss	xmm0, DWORD PTR 8[rsi]
	subss	xmm1, xmm2
	subss	xmm1, xmm0
.LBE440:
.LBE439:
	.loc 1 333 0
	movss	DWORD PTR 12[rdi], xmm1
	.loc 1 334 0
	add	rsp, 40
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.LVL232:
.L85:
	.cfi_restore_state
.LBB441:
.LBB434:
	.loc 1 100 0
	movaps	xmm0, xmm3
	mov	QWORD PTR 24[rsp], rsi
	mov	QWORD PTR 16[rsp], rdi
	movss	DWORD PTR 12[rsp], xmm5
	movss	DWORD PTR 8[rsp], xmm2
	movss	DWORD PTR 4[rsp], xmm1
	movss	DWORD PTR [rsp], xmm4
	call	sqrtf@PLT
.LVL233:
	mov	rsi, QWORD PTR 24[rsp]
	mov	rdi, QWORD PTR 16[rsp]
	movss	xmm5, DWORD PTR 12[rsp]
	movss	xmm2, DWORD PTR 8[rsp]
	movss	xmm1, DWORD PTR 4[rsp]
	movss	xmm4, DWORD PTR [rsp]
	jmp	.L83
.LBE434:
.LBE441:
	.cfi_endproc
.LFE60:
	.size	vec3computeLineCoefficients, .-vec3computeLineCoefficients
	.p2align 4,,15
	.globl	rtp_to_xyz
	.type	rtp_to_xyz, @function
rtp_to_xyz:
.LFB61:
	.loc 1 337 0
	.cfi_startproc
.LVL234:
	push	r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	push	rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	push	rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	mov	rbx, rdi
	sub	rsp, 32
	.cfi_def_cfa_offset 64
	lea	rbp, 28[rsp]
	lea	r12, 24[rsp]
	.loc 1 337 0
	movss	DWORD PTR 20[rsp], xmm0
	movaps	xmm0, xmm1
.LVL235:
	movss	DWORD PTR 16[rsp], xmm2
	mov	rsi, r12
	mov	rdi, rbp
.LVL236:
	call	sincosf@PLT
.LVL237:
	movss	xmm2, DWORD PTR 16[rsp]
	mov	rsi, r12
	movaps	xmm0, xmm2
	mov	rdi, rbp
	movss	xmm1, DWORD PTR 24[rsp]
	movss	xmm4, DWORD PTR 28[rsp]
	movss	DWORD PTR 12[rsp], xmm1
	movss	DWORD PTR 8[rsp], xmm4
	call	sincosf@PLT
.LVL238:
	.loc 1 338 0
	movss	xmm3, DWORD PTR 20[rsp]
	.loc 1 342 0
	mov	rax, rbx
	.loc 1 338 0
	movss	xmm0, DWORD PTR 28[rsp]
	mulss	xmm0, xmm3
	movss	xmm1, DWORD PTR 12[rsp]
	.loc 1 340 0
	mulss	xmm3, DWORD PTR 24[rsp]
	.loc 1 338 0
	mulss	xmm1, xmm0
	.loc 1 339 0
	mulss	xmm0, DWORD PTR 8[rsp]
	.loc 1 340 0
	movss	DWORD PTR 8[rbx], xmm3
	.loc 1 338 0
	movss	DWORD PTR [rbx], xmm1
	.loc 1 339 0
	movss	DWORD PTR 4[rbx], xmm0
	.loc 1 342 0
	add	rsp, 32
	.cfi_def_cfa_offset 32
	pop	rbx
	.cfi_def_cfa_offset 24
.LVL239:
	pop	rbp
	.cfi_def_cfa_offset 16
	pop	r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE61:
	.size	rtp_to_xyz, .-rtp_to_xyz
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC5:
	.string	"%s %+-.6f %+-.6f %+-.6f\n"
.LC6:
	.string	"%+-.6f %+-.6f %+-.6f\n"
	.text
	.p2align 4,,15
	.globl	vec3printf
	.type	vec3printf, @function
vec3printf:
.LFB62:
	.loc 1 345 0
	.cfi_startproc
.LVL240:
	pxor	xmm2, xmm2
	.loc 1 346 0
	test	rdi, rdi
	pxor	xmm1, xmm1
	pxor	xmm0, xmm0
	cvtss2sd	xmm2, DWORD PTR 8[rsi]
	cvtss2sd	xmm1, DWORD PTR 4[rsi]
	cvtss2sd	xmm0, DWORD PTR [rsi]
	je	.L89
	.loc 1 348 0
	mov	rsi, rdi
.LVL241:
	lea	rdi, .LC5[rip]
.LVL242:
	mov	eax, 3
	jmp	printf@PLT
.LVL243:
	.p2align 4,,10
	.p2align 3
.L89:
	.loc 1 352 0
	lea	rdi, .LC6[rip]
.LVL244:
	mov	eax, 3
	jmp	printf@PLT
.LVL245:
	.cfi_endproc
.LFE62:
	.size	vec3printf, .-vec3printf
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC2:
	.long	1065353216
	.align 4
.LC3:
	.long	3045472189
	.align 4
.LC4:
	.long	897988541
	.text
.Letext0:
	.file 2 "/usr/include/bits/types.h"
	.file 3 "./inc/math_types.h"
	.file 4 "/usr/include/math.h"
	.file 5 "/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include/stddef.h"
	.file 6 "/usr/include/libio.h"
	.file 7 "/usr/include/stdio.h"
	.file 8 "/usr/include/bits/sys_errlist.h"
	.file 9 "/usr/include/bits/mathcalls.h"
	.file 10 "<built-in>"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x18a3
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF124
	.byte	0xc
	.long	.LASF125
	.long	.LASF126
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x4
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF4
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF5
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF6
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF7
	.uleb128 0x4
	.long	.LASF8
	.byte	0x2
	.byte	0x8c
	.long	0x65
	.uleb128 0x4
	.long	.LASF9
	.byte	0x2
	.byte	0x8d
	.long	0x65
	.uleb128 0x5
	.byte	0x8
	.uleb128 0x6
	.byte	0x8
	.long	0x8a
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF10
	.uleb128 0x7
	.long	0x8a
	.uleb128 0x7
	.long	0x2d
	.uleb128 0x8
	.long	.LASF127
	.byte	0x10
	.byte	0x10
	.byte	0x3
	.byte	0x11
	.long	0xc7
	.uleb128 0x9
	.string	"x"
	.byte	0x3
	.byte	0x12
	.long	0x2d
	.byte	0
	.uleb128 0x9
	.string	"y"
	.byte	0x3
	.byte	0x13
	.long	0x2d
	.byte	0x4
	.uleb128 0x9
	.string	"z"
	.byte	0x3
	.byte	0x14
	.long	0x2d
	.byte	0x8
	.byte	0
	.uleb128 0xa
	.long	.LASF25
	.byte	0x40
	.byte	0x3
	.byte	0x17
	.long	0xe0
	.uleb128 0xb
	.long	.LASF11
	.byte	0x3
	.byte	0x18
	.long	0xe0
	.byte	0
	.byte	0
	.uleb128 0xc
	.long	0x2d
	.long	0xf0
	.uleb128 0xd
	.long	0x49
	.byte	0xf
	.byte	0
	.uleb128 0xe
	.long	.LASF128
	.byte	0x3
	.byte	0x1d
	.long	0x9b
	.byte	0x10
	.uleb128 0x7
	.long	0xf0
	.uleb128 0x4
	.long	.LASF12
	.byte	0x3
	.byte	0x1e
	.long	0xc7
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.long	.LASF13
	.uleb128 0xf
	.long	.LASF20
	.byte	0x4
	.value	0x14a
	.long	0x5e
	.uleb128 0x10
	.byte	0x5
	.byte	0x4
	.long	0x5e
	.byte	0x4
	.value	0x23c
	.long	0x14c
	.uleb128 0x11
	.long	.LASF14
	.sleb128 -1
	.uleb128 0x12
	.long	.LASF15
	.byte	0
	.uleb128 0x12
	.long	.LASF16
	.byte	0x1
	.uleb128 0x12
	.long	.LASF17
	.byte	0x2
	.uleb128 0x12
	.long	.LASF18
	.byte	0x3
	.byte	0
	.uleb128 0x13
	.long	.LASF19
	.byte	0x4
	.value	0x242
	.long	0x11f
	.uleb128 0xf
	.long	.LASF21
	.byte	0x4
	.value	0x247
	.long	0x14c
	.uleb128 0x4
	.long	.LASF22
	.byte	0x5
	.byte	0xd8
	.long	0x49
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF23
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF24
	.uleb128 0xa
	.long	.LASF26
	.byte	0xd8
	.byte	0x6
	.byte	0xf1
	.long	0x2fa
	.uleb128 0xb
	.long	.LASF27
	.byte	0x6
	.byte	0xf2
	.long	0x5e
	.byte	0
	.uleb128 0xb
	.long	.LASF28
	.byte	0x6
	.byte	0xf7
	.long	0x84
	.byte	0x8
	.uleb128 0xb
	.long	.LASF29
	.byte	0x6
	.byte	0xf8
	.long	0x84
	.byte	0x10
	.uleb128 0xb
	.long	.LASF30
	.byte	0x6
	.byte	0xf9
	.long	0x84
	.byte	0x18
	.uleb128 0xb
	.long	.LASF31
	.byte	0x6
	.byte	0xfa
	.long	0x84
	.byte	0x20
	.uleb128 0xb
	.long	.LASF32
	.byte	0x6
	.byte	0xfb
	.long	0x84
	.byte	0x28
	.uleb128 0xb
	.long	.LASF33
	.byte	0x6
	.byte	0xfc
	.long	0x84
	.byte	0x30
	.uleb128 0xb
	.long	.LASF34
	.byte	0x6
	.byte	0xfd
	.long	0x84
	.byte	0x38
	.uleb128 0xb
	.long	.LASF35
	.byte	0x6
	.byte	0xfe
	.long	0x84
	.byte	0x40
	.uleb128 0x14
	.long	.LASF36
	.byte	0x6
	.value	0x100
	.long	0x84
	.byte	0x48
	.uleb128 0x14
	.long	.LASF37
	.byte	0x6
	.value	0x101
	.long	0x84
	.byte	0x50
	.uleb128 0x14
	.long	.LASF38
	.byte	0x6
	.value	0x102
	.long	0x84
	.byte	0x58
	.uleb128 0x14
	.long	.LASF39
	.byte	0x6
	.value	0x104
	.long	0x332
	.byte	0x60
	.uleb128 0x14
	.long	.LASF40
	.byte	0x6
	.value	0x106
	.long	0x338
	.byte	0x68
	.uleb128 0x14
	.long	.LASF41
	.byte	0x6
	.value	0x108
	.long	0x5e
	.byte	0x70
	.uleb128 0x14
	.long	.LASF42
	.byte	0x6
	.value	0x10c
	.long	0x5e
	.byte	0x74
	.uleb128 0x14
	.long	.LASF43
	.byte	0x6
	.value	0x10e
	.long	0x6c
	.byte	0x78
	.uleb128 0x14
	.long	.LASF44
	.byte	0x6
	.value	0x112
	.long	0x3b
	.byte	0x80
	.uleb128 0x14
	.long	.LASF45
	.byte	0x6
	.value	0x113
	.long	0x50
	.byte	0x82
	.uleb128 0x14
	.long	.LASF46
	.byte	0x6
	.value	0x114
	.long	0x33e
	.byte	0x83
	.uleb128 0x14
	.long	.LASF47
	.byte	0x6
	.value	0x118
	.long	0x34e
	.byte	0x88
	.uleb128 0x14
	.long	.LASF48
	.byte	0x6
	.value	0x121
	.long	0x77
	.byte	0x90
	.uleb128 0x14
	.long	.LASF49
	.byte	0x6
	.value	0x129
	.long	0x82
	.byte	0x98
	.uleb128 0x14
	.long	.LASF50
	.byte	0x6
	.value	0x12a
	.long	0x82
	.byte	0xa0
	.uleb128 0x14
	.long	.LASF51
	.byte	0x6
	.value	0x12b
	.long	0x82
	.byte	0xa8
	.uleb128 0x14
	.long	.LASF52
	.byte	0x6
	.value	0x12c
	.long	0x82
	.byte	0xb0
	.uleb128 0x14
	.long	.LASF53
	.byte	0x6
	.value	0x12e
	.long	0x164
	.byte	0xb8
	.uleb128 0x14
	.long	.LASF54
	.byte	0x6
	.value	0x12f
	.long	0x5e
	.byte	0xc0
	.uleb128 0x14
	.long	.LASF55
	.byte	0x6
	.value	0x131
	.long	0x354
	.byte	0xc4
	.byte	0
	.uleb128 0x15
	.long	.LASF129
	.byte	0x6
	.byte	0x96
	.uleb128 0xa
	.long	.LASF56
	.byte	0x18
	.byte	0x6
	.byte	0x9c
	.long	0x332
	.uleb128 0xb
	.long	.LASF57
	.byte	0x6
	.byte	0x9d
	.long	0x332
	.byte	0
	.uleb128 0xb
	.long	.LASF58
	.byte	0x6
	.byte	0x9e
	.long	0x338
	.byte	0x8
	.uleb128 0xb
	.long	.LASF59
	.byte	0x6
	.byte	0xa2
	.long	0x5e
	.byte	0x10
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x301
	.uleb128 0x6
	.byte	0x8
	.long	0x17d
	.uleb128 0xc
	.long	0x8a
	.long	0x34e
	.uleb128 0xd
	.long	0x49
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x2fa
	.uleb128 0xc
	.long	0x8a
	.long	0x364
	.uleb128 0xd
	.long	0x49
	.byte	0x13
	.byte	0
	.uleb128 0x16
	.long	.LASF130
	.uleb128 0xf
	.long	.LASF60
	.byte	0x6
	.value	0x13b
	.long	0x364
	.uleb128 0xf
	.long	.LASF61
	.byte	0x6
	.value	0x13c
	.long	0x364
	.uleb128 0xf
	.long	.LASF62
	.byte	0x6
	.value	0x13d
	.long	0x364
	.uleb128 0x6
	.byte	0x8
	.long	0x91
	.uleb128 0x7
	.long	0x38d
	.uleb128 0x17
	.long	.LASF63
	.byte	0x7
	.byte	0x87
	.long	0x338
	.uleb128 0x17
	.long	.LASF64
	.byte	0x7
	.byte	0x88
	.long	0x338
	.uleb128 0x17
	.long	.LASF65
	.byte	0x7
	.byte	0x89
	.long	0x338
	.uleb128 0x17
	.long	.LASF66
	.byte	0x8
	.byte	0x1a
	.long	0x5e
	.uleb128 0xc
	.long	0x393
	.long	0x3cf
	.uleb128 0x18
	.byte	0
	.uleb128 0x7
	.long	0x3c4
	.uleb128 0x17
	.long	.LASF67
	.byte	0x8
	.byte	0x1b
	.long	0x3cf
	.uleb128 0x19
	.long	.LASF71
	.byte	0x1
	.value	0x158
	.quad	.LFB62
	.quad	.LFE62-.LFB62
	.uleb128 0x1
	.byte	0x9c
	.long	0x45d
	.uleb128 0x1a
	.long	.LASF68
	.byte	0x1
	.value	0x158
	.long	0x38d
	.long	.LLST113
	.uleb128 0x1b
	.string	"v"
	.byte	0x1
	.value	0x158
	.long	0x45d
	.long	.LLST114
	.uleb128 0x1c
	.quad	.LVL243
	.long	0x1880
	.long	0x441
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x9
	.byte	0x3
	.quad	.LC5
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x1e
	.quad	.LVL245
	.long	0x1880
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x9
	.byte	0x3
	.quad	.LC6
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0xfc
	.uleb128 0x1f
	.long	.LASF73
	.byte	0x1
	.value	0x150
	.long	0x50e
	.quad	.LFB61
	.quad	.LFE61-.LFB61
	.uleb128 0x1
	.byte	0x9c
	.long	0x50e
	.uleb128 0x1b
	.string	"v"
	.byte	0x1
	.value	0x150
	.long	0x50e
	.long	.LLST109
	.uleb128 0x1a
	.long	.LASF69
	.byte	0x1
	.value	0x150
	.long	0x2d
	.long	.LLST110
	.uleb128 0x1a
	.long	.LASF70
	.byte	0x1
	.value	0x150
	.long	0x2d
	.long	.LLST111
	.uleb128 0x1b
	.string	"phi"
	.byte	0x1
	.value	0x150
	.long	0x2d
	.long	.LLST112
	.uleb128 0x20
	.quad	.LVL237
	.long	0x188c
	.long	0x4ea
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x5
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.uleb128 0x21
	.quad	.LVL238
	.long	0x188c
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x5
	.byte	0x91
	.sleb128 -48
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0xf0
	.uleb128 0x19
	.long	.LASF72
	.byte	0x1
	.value	0x144
	.quad	.LFB60
	.quad	.LFE60-.LFB60
	.uleb128 0x1
	.byte	0x9c
	.long	0x664
	.uleb128 0x1b
	.string	"ret"
	.byte	0x1
	.value	0x144
	.long	0x664
	.long	.LLST101
	.uleb128 0x1b
	.string	"p0"
	.byte	0x1
	.value	0x144
	.long	0x50e
	.long	.LLST102
	.uleb128 0x1b
	.string	"p1"
	.byte	0x1
	.value	0x144
	.long	0x50e
	.long	.LLST103
	.uleb128 0x1b
	.string	"p2"
	.byte	0x1
	.value	0x144
	.long	0x50e
	.long	.LLST104
	.uleb128 0x22
	.string	"v"
	.byte	0x1
	.value	0x146
	.long	0xf0
	.long	.LLST105
	.uleb128 0x22
	.string	"u"
	.byte	0x1
	.value	0x147
	.long	0xf0
	.long	.LLST106
	.uleb128 0x23
	.string	"n"
	.byte	0x1
	.value	0x148
	.long	0xf0
	.uleb128 0x24
	.long	0x1123
	.quad	.LBB428
	.long	.Ldebug_ranges0+0x970
	.byte	0x1
	.value	0x149
	.long	0x5bc
	.uleb128 0x25
	.long	0x113e
	.long	.LLST107
	.uleb128 0x26
	.long	0x1133
	.byte	0
	.uleb128 0x24
	.long	0x1319
	.quad	.LBB431
	.long	.Ldebug_ranges0+0x9a0
	.byte	0x1
	.value	0x149
	.long	0x61e
	.uleb128 0x25
	.long	0x1329
	.long	.LLST108
	.uleb128 0x27
	.long	.Ldebug_ranges0+0x9a0
	.uleb128 0x28
	.long	0x16d1
	.uleb128 0x21
	.quad	.LVL233
	.long	0x189b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x23
	.byte	0x91
	.sleb128 -40
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x91
	.sleb128 -40
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x91
	.sleb128 -44
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x91
	.sleb128 -44
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x22
	.byte	0x77
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x77
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x22
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x29
	.long	0x1457
	.quad	.LBB437
	.quad	.LBE437-.LBB437
	.byte	0x1
	.value	0x14d
	.long	0x640
	.uleb128 0x26
	.long	0x1467
	.byte	0
	.uleb128 0x2a
	.long	0x1100
	.quad	.LBB439
	.quad	.LBE439-.LBB439
	.byte	0x1
	.value	0x14d
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x26
	.long	0x1110
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x2d
	.uleb128 0x1f
	.long	.LASF74
	.byte	0x1
	.value	0x13f
	.long	0x2d
	.quad	.LFB59
	.quad	.LFE59-.LFB59
	.uleb128 0x1
	.byte	0x9c
	.long	0x6b5
	.uleb128 0x2b
	.long	.LASF75
	.byte	0x1
	.value	0x13f
	.long	0x664
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2c
	.string	"v"
	.byte	0x1
	.value	0x13f
	.long	0x50e
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x1b
	.string	"r"
	.byte	0x1
	.value	0x13f
	.long	0x2d
	.long	.LLST100
	.byte	0
	.uleb128 0x1f
	.long	.LASF76
	.byte	0x1
	.value	0x136
	.long	0x72c
	.quad	.LFB58
	.quad	.LFE58-.LFB58
	.uleb128 0x1
	.byte	0x9c
	.long	0x72c
	.uleb128 0x2c
	.string	"pt"
	.byte	0x1
	.value	0x136
	.long	0x45d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2c
	.string	"sp"
	.byte	0x1
	.value	0x136
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x1a
	.long	.LASF69
	.byte	0x1
	.value	0x136
	.long	0x96
	.long	.LLST96
	.uleb128 0x22
	.string	"x"
	.byte	0x1
	.value	0x138
	.long	0x2d
	.long	.LLST97
	.uleb128 0x22
	.string	"y"
	.byte	0x1
	.value	0x139
	.long	0x2d
	.long	.LLST98
	.uleb128 0x22
	.string	"z"
	.byte	0x1
	.value	0x13a
	.long	0x2d
	.long	.LLST99
	.byte	0
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.long	.LASF77
	.uleb128 0x1f
	.long	.LASF78
	.byte	0x1
	.value	0x12f
	.long	0x2d
	.quad	.LFB57
	.quad	.LFE57-.LFB57
	.uleb128 0x1
	.byte	0x9c
	.long	0x786
	.uleb128 0x1a
	.long	.LASF79
	.byte	0x1
	.value	0x12f
	.long	0x96
	.long	.LLST93
	.uleb128 0x1a
	.long	.LASF80
	.byte	0x1
	.value	0x12f
	.long	0x96
	.long	.LLST94
	.uleb128 0x22
	.string	"att"
	.byte	0x1
	.value	0x131
	.long	0x2d
	.long	.LLST95
	.byte	0
	.uleb128 0x1f
	.long	.LASF81
	.byte	0x1
	.value	0x126
	.long	0x50e
	.quad	.LFB56
	.quad	.LFE56-.LFB56
	.uleb128 0x1
	.byte	0x9c
	.long	0x82d
	.uleb128 0x2c
	.string	"pos"
	.byte	0x1
	.value	0x126
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x1a
	.long	.LASF79
	.byte	0x1
	.value	0x126
	.long	0x2d
	.long	.LLST89
	.uleb128 0x2b
	.long	.LASF82
	.byte	0x1
	.value	0x126
	.long	0x50e
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x22
	.string	"n"
	.byte	0x1
	.value	0x128
	.long	0xf0
	.long	.LLST90
	.uleb128 0x24
	.long	0x137a
	.quad	.LBB408
	.long	.Ldebug_ranges0+0x900
	.byte	0x1
	.value	0x129
	.long	0x809
	.uleb128 0x25
	.long	0x1395
	.long	.LLST91
	.uleb128 0x26
	.long	0x138a
	.byte	0
	.uleb128 0x2d
	.long	0x1471
	.quad	.LBB413
	.long	.Ldebug_ranges0+0x940
	.byte	0x1
	.value	0x129
	.uleb128 0x26
	.long	0x148c
	.uleb128 0x25
	.long	0x1481
	.long	.LLST92
	.byte	0
	.byte	0
	.uleb128 0x1f
	.long	.LASF83
	.byte	0x1
	.value	0x10d
	.long	0x72c
	.quad	.LFB55
	.quad	.LFE55-.LFB55
	.uleb128 0x1
	.byte	0x9c
	.long	0xa55
	.uleb128 0x1b
	.string	"ret"
	.byte	0x1
	.value	0x10d
	.long	0x50e
	.long	.LLST69
	.uleb128 0x1a
	.long	.LASF84
	.byte	0x1
	.value	0x10d
	.long	0x50e
	.long	.LLST70
	.uleb128 0x1a
	.long	.LASF85
	.byte	0x1
	.value	0x10d
	.long	0x50e
	.long	.LLST71
	.uleb128 0x1b
	.string	"lv0"
	.byte	0x1
	.value	0x10d
	.long	0x50e
	.long	.LLST72
	.uleb128 0x1b
	.string	"lv1"
	.byte	0x1
	.value	0x10d
	.long	0x50e
	.long	.LLST73
	.uleb128 0x2e
	.long	.LASF86
	.byte	0x1
	.value	0x110
	.long	0xf0
	.uleb128 0x23
	.string	"t0"
	.byte	0x1
	.value	0x117
	.long	0x2d
	.uleb128 0x23
	.string	"t1"
	.byte	0x1
	.value	0x117
	.long	0x2d
	.uleb128 0x2f
	.long	.LASF87
	.byte	0x1
	.value	0x118
	.long	0xf0
	.long	.LLST74
	.uleb128 0x2f
	.long	.LASF88
	.byte	0x1
	.value	0x11f
	.long	0xf0
	.long	.LLST75
	.uleb128 0x24
	.long	0x1319
	.quad	.LBB364
	.long	.Ldebug_ranges0+0x720
	.byte	0x1
	.value	0x10f
	.long	0x91b
	.uleb128 0x25
	.long	0x1329
	.long	.LLST76
	.uleb128 0x27
	.long	.Ldebug_ranges0+0x720
	.uleb128 0x28
	.long	0x16d1
	.uleb128 0x30
	.quad	.LVL194
	.long	0x189b
	.byte	0
	.byte	0
	.uleb128 0x24
	.long	0x12eb
	.quad	.LBB368
	.long	.Ldebug_ranges0+0x760
	.byte	0x1
	.value	0x112
	.long	0x9b0
	.uleb128 0x25
	.long	0x1304
	.long	.LLST77
	.uleb128 0x25
	.long	0x12fb
	.long	.LLST78
	.uleb128 0x27
	.long	.Ldebug_ranges0+0x760
	.uleb128 0x28
	.long	0x1715
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB370
	.long	.Ldebug_ranges0+0x7b0
	.byte	0x1
	.byte	0x6e
	.long	0x979
	.uleb128 0x25
	.long	0x148c
	.long	.LLST79
	.uleb128 0x25
	.long	0x1481
	.long	.LLST80
	.byte	0
	.uleb128 0x32
	.long	0x1319
	.quad	.LBB374
	.long	.Ldebug_ranges0+0x7e0
	.byte	0x1
	.byte	0x6e
	.uleb128 0x25
	.long	0x1329
	.long	.LLST81
	.uleb128 0x27
	.long	.Ldebug_ranges0+0x7e0
	.uleb128 0x28
	.long	0x16d1
	.uleb128 0x30
	.quad	.LVL196
	.long	0x189b
	.byte	0
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x24
	.long	0xef4
	.quad	.LBB385
	.long	.Ldebug_ranges0+0x820
	.byte	0x1
	.value	0x113
	.long	0x9db
	.uleb128 0x25
	.long	0xf0d
	.long	.LLST82
	.uleb128 0x25
	.long	0xf04
	.long	.LLST83
	.byte	0
	.uleb128 0x24
	.long	0x1471
	.quad	.LBB390
	.long	.Ldebug_ranges0+0x850
	.byte	0x1
	.value	0x11a
	.long	0xa02
	.uleb128 0x25
	.long	0x148c
	.long	.LLST84
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x24
	.long	0x1100
	.quad	.LBB395
	.long	.Ldebug_ranges0+0x890
	.byte	0x1
	.value	0x11b
	.long	0xa2d
	.uleb128 0x25
	.long	0x1119
	.long	.LLST85
	.uleb128 0x25
	.long	0x1110
	.long	.LLST86
	.byte	0
	.uleb128 0x2d
	.long	0x150b
	.quad	.LBB400
	.long	.Ldebug_ranges0+0x8c0
	.byte	0x1
	.value	0x122
	.uleb128 0x25
	.long	0x1526
	.long	.LLST87
	.uleb128 0x25
	.long	0x151b
	.long	.LLST88
	.byte	0
	.byte	0
	.uleb128 0x33
	.long	.LASF89
	.byte	0x1
	.byte	0xe4
	.long	0x50e
	.quad	.LFB54
	.quad	.LFE54-.LFB54
	.uleb128 0x1
	.byte	0x9c
	.long	0xcae
	.uleb128 0x34
	.string	"ret"
	.byte	0x1
	.byte	0xe4
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"ray"
	.byte	0x1
	.byte	0xe4
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x35
	.long	.LASF90
	.byte	0x1
	.byte	0xe4
	.long	0x45d
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x34
	.string	"v0"
	.byte	0x1
	.byte	0xe4
	.long	0x45d
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x34
	.string	"v1"
	.byte	0x1
	.byte	0xe4
	.long	0x45d
	.uleb128 0x1
	.byte	0x58
	.uleb128 0x34
	.string	"v2"
	.byte	0x1
	.byte	0xe4
	.long	0x45d
	.uleb128 0x1
	.byte	0x59
	.uleb128 0x36
	.string	"e0"
	.byte	0x1
	.byte	0xe6
	.long	0xf0
	.long	.LLST54
	.uleb128 0x36
	.string	"e1"
	.byte	0x1
	.byte	0xe6
	.long	0xf0
	.long	.LLST55
	.uleb128 0x36
	.string	"p"
	.byte	0x1
	.byte	0xe6
	.long	0xf0
	.long	.LLST56
	.uleb128 0x36
	.string	"t"
	.byte	0x1
	.byte	0xe6
	.long	0xf0
	.long	.LLST57
	.uleb128 0x36
	.string	"q"
	.byte	0x1
	.byte	0xe6
	.long	0xf0
	.long	.LLST58
	.uleb128 0x37
	.string	"det"
	.byte	0x1
	.byte	0xe7
	.long	0x2d
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB264
	.long	.Ldebug_ranges0+0x430
	.byte	0x1
	.byte	0xea
	.long	0xb35
	.uleb128 0x25
	.long	0x148c
	.long	.LLST59
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB272
	.long	.Ldebug_ranges0+0x4b0
	.byte	0x1
	.byte	0xeb
	.long	0xb57
	.uleb128 0x26
	.long	0x148c
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x31
	.long	0x150b
	.quad	.LBB276
	.long	.Ldebug_ranges0+0x4f0
	.byte	0x1
	.byte	0xec
	.long	0xb79
	.uleb128 0x26
	.long	0x1526
	.uleb128 0x26
	.long	0x151b
	.byte	0
	.uleb128 0x31
	.long	0x1123
	.quad	.LBB279
	.long	.Ldebug_ranges0+0x520
	.byte	0x1
	.byte	0xec
	.long	0xb9f
	.uleb128 0x25
	.long	0x113e
	.long	.LLST60
	.uleb128 0x26
	.long	0x1133
	.byte	0
	.uleb128 0x38
	.long	0x1100
	.quad	.LBB306
	.quad	.LBE306-.LBB306
	.byte	0x1
	.byte	0xee
	.long	0xbcd
	.uleb128 0x25
	.long	0x1119
	.long	.LLST61
	.uleb128 0x25
	.long	0x1110
	.long	.LLST62
	.byte	0
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB308
	.long	.Ldebug_ranges0+0x5c0
	.byte	0x1
	.byte	0xf2
	.long	0xbf3
	.uleb128 0x25
	.long	0x148c
	.long	.LLST63
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x31
	.long	0x1100
	.quad	.LBB311
	.long	.Ldebug_ranges0+0x5f0
	.byte	0x1
	.byte	0xf2
	.long	0xc19
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x25
	.long	0x1110
	.long	.LLST64
	.byte	0
	.uleb128 0x31
	.long	0x1123
	.quad	.LBB318
	.long	.Ldebug_ranges0+0x630
	.byte	0x1
	.byte	0xf6
	.long	0xc3f
	.uleb128 0x25
	.long	0x113e
	.long	.LLST65
	.uleb128 0x26
	.long	0x1133
	.byte	0
	.uleb128 0x31
	.long	0x1100
	.quad	.LBB321
	.long	.Ldebug_ranges0+0x660
	.byte	0x1
	.byte	0xf6
	.long	0xc65
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x25
	.long	0x1110
	.long	.LLST66
	.byte	0
	.uleb128 0x31
	.long	0x1100
	.quad	.LBB326
	.long	.Ldebug_ranges0+0x690
	.byte	0x1
	.byte	0xfa
	.long	0xc87
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x26
	.long	0x1110
	.byte	0
	.uleb128 0x32
	.long	0x137a
	.quad	.LBB332
	.long	.Ldebug_ranges0+0x6e0
	.byte	0x1
	.byte	0xfc
	.uleb128 0x25
	.long	0x1395
	.long	.LLST67
	.uleb128 0x25
	.long	0x138a
	.long	.LLST68
	.byte	0
	.byte	0
	.uleb128 0x33
	.long	.LASF91
	.byte	0x1
	.byte	0xca
	.long	0x50e
	.quad	.LFB53
	.quad	.LFE53-.LFB53
	.uleb128 0x1
	.byte	0x9c
	.long	0xeee
	.uleb128 0x34
	.string	"ret"
	.byte	0x1
	.byte	0xca
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"ray"
	.byte	0x1
	.byte	0xca
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x35
	.long	.LASF90
	.byte	0x1
	.byte	0xca
	.long	0x45d
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x34
	.string	"v"
	.byte	0x1
	.byte	0xca
	.long	0xeee
	.uleb128 0x1
	.byte	0x52
	.uleb128 0x36
	.string	"e0"
	.byte	0x1
	.byte	0xcc
	.long	0xf0
	.long	.LLST39
	.uleb128 0x36
	.string	"e1"
	.byte	0x1
	.byte	0xcc
	.long	0xf0
	.long	.LLST40
	.uleb128 0x36
	.string	"p"
	.byte	0x1
	.byte	0xcc
	.long	0xf0
	.long	.LLST41
	.uleb128 0x36
	.string	"t"
	.byte	0x1
	.byte	0xcc
	.long	0xf0
	.long	.LLST42
	.uleb128 0x36
	.string	"q"
	.byte	0x1
	.byte	0xcc
	.long	0xf0
	.long	.LLST43
	.uleb128 0x37
	.string	"det"
	.byte	0x1
	.byte	0xcd
	.long	0x2d
	.uleb128 0x31
	.long	0x150b
	.quad	.LBB194
	.long	.Ldebug_ranges0+0x170
	.byte	0x1
	.byte	0xd1
	.long	0xd71
	.uleb128 0x26
	.long	0x1526
	.uleb128 0x26
	.long	0x151b
	.byte	0
	.uleb128 0x31
	.long	0x1123
	.quad	.LBB197
	.long	.Ldebug_ranges0+0x1a0
	.byte	0x1
	.byte	0xd1
	.long	0xd97
	.uleb128 0x25
	.long	0x113e
	.long	.LLST44
	.uleb128 0x26
	.long	0x1133
	.byte	0
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB203
	.long	.Ldebug_ranges0+0x200
	.byte	0x1
	.byte	0xcf
	.long	0xdbd
	.uleb128 0x25
	.long	0x148c
	.long	.LLST45
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB215
	.long	.Ldebug_ranges0+0x280
	.byte	0x1
	.byte	0xd0
	.long	0xddf
	.uleb128 0x26
	.long	0x148c
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x38
	.long	0x1100
	.quad	.LBB230
	.quad	.LBE230-.LBB230
	.byte	0x1
	.byte	0xd3
	.long	0xe0d
	.uleb128 0x25
	.long	0x1119
	.long	.LLST46
	.uleb128 0x25
	.long	0x1110
	.long	.LLST47
	.byte	0
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB232
	.long	.Ldebug_ranges0+0x2d0
	.byte	0x1
	.byte	0xd7
	.long	0xe33
	.uleb128 0x25
	.long	0x148c
	.long	.LLST48
	.uleb128 0x26
	.long	0x1481
	.byte	0
	.uleb128 0x31
	.long	0x1100
	.quad	.LBB235
	.long	.Ldebug_ranges0+0x300
	.byte	0x1
	.byte	0xd7
	.long	0xe59
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x25
	.long	0x1110
	.long	.LLST49
	.byte	0
	.uleb128 0x31
	.long	0x1123
	.quad	.LBB242
	.long	.Ldebug_ranges0+0x340
	.byte	0x1
	.byte	0xdb
	.long	0xe7f
	.uleb128 0x25
	.long	0x113e
	.long	.LLST50
	.uleb128 0x26
	.long	0x1133
	.byte	0
	.uleb128 0x31
	.long	0x1100
	.quad	.LBB245
	.long	.Ldebug_ranges0+0x370
	.byte	0x1
	.byte	0xdb
	.long	0xea5
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x25
	.long	0x1110
	.long	.LLST51
	.byte	0
	.uleb128 0x31
	.long	0x1100
	.quad	.LBB250
	.long	.Ldebug_ranges0+0x3a0
	.byte	0x1
	.byte	0xdf
	.long	0xec7
	.uleb128 0x26
	.long	0x1119
	.uleb128 0x26
	.long	0x1110
	.byte	0
	.uleb128 0x32
	.long	0x137a
	.quad	.LBB256
	.long	.Ldebug_ranges0+0x3f0
	.byte	0x1
	.byte	0xe1
	.uleb128 0x25
	.long	0x1395
	.long	.LLST52
	.uleb128 0x25
	.long	0x138a
	.long	.LLST53
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x45d
	.uleb128 0x39
	.long	.LASF94
	.byte	0x1
	.byte	0xc4
	.long	0x72c
	.byte	0x1
	.long	0xf17
	.uleb128 0x3a
	.string	"a"
	.byte	0x1
	.byte	0xc4
	.long	0x45d
	.uleb128 0x3a
	.string	"b"
	.byte	0x1
	.byte	0xc4
	.long	0x45d
	.byte	0
	.uleb128 0x33
	.long	.LASF92
	.byte	0x1
	.byte	0xb8
	.long	0x72c
	.quad	.LFB51
	.quad	.LFE51-.LFB51
	.uleb128 0x1
	.byte	0x9c
	.long	0xf84
	.uleb128 0x34
	.string	"v0"
	.byte	0x1
	.byte	0xb8
	.long	0x45d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"v1"
	.byte	0x1
	.byte	0xb8
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x36
	.string	"v"
	.byte	0x1
	.byte	0xba
	.long	0xf0
	.long	.LLST36
	.uleb128 0x32
	.long	0xfbc
	.quad	.LBB184
	.long	.Ldebug_ranges0+0x110
	.byte	0x1
	.byte	0xba
	.uleb128 0x25
	.long	0xfd5
	.long	.LLST37
	.uleb128 0x25
	.long	0xfcc
	.long	.LLST38
	.byte	0
	.byte	0
	.uleb128 0x33
	.long	.LASF93
	.byte	0x1
	.byte	0xb1
	.long	0xf0
	.quad	.LFB50
	.quad	.LFE50-.LFB50
	.uleb128 0x1
	.byte	0x9c
	.long	0xfbc
	.uleb128 0x34
	.string	"a"
	.byte	0x1
	.byte	0xb1
	.long	0x45d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"b"
	.byte	0x1
	.byte	0xb1
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x39
	.long	.LASF95
	.byte	0x1
	.byte	0xac
	.long	0xf0
	.byte	0x1
	.long	0xfdf
	.uleb128 0x3a
	.string	"a"
	.byte	0x1
	.byte	0xac
	.long	0x45d
	.uleb128 0x3a
	.string	"b"
	.byte	0x1
	.byte	0xac
	.long	0x45d
	.byte	0
	.uleb128 0x33
	.long	.LASF96
	.byte	0x1
	.byte	0xa7
	.long	0xf0
	.quad	.LFB48
	.quad	.LFE48-.LFB48
	.uleb128 0x1
	.byte	0x9c
	.long	0x1017
	.uleb128 0x34
	.string	"a"
	.byte	0x1
	.byte	0xa7
	.long	0x45d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"b"
	.byte	0x1
	.byte	0xa7
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x33
	.long	.LASF97
	.byte	0x1
	.byte	0xa2
	.long	0xf0
	.quad	.LFB47
	.quad	.LFE47-.LFB47
	.uleb128 0x1
	.byte	0x9c
	.long	0x1051
	.uleb128 0x34
	.string	"a"
	.byte	0x1
	.byte	0xa2
	.long	0x45d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3b
	.string	"s"
	.byte	0x1
	.byte	0xa2
	.long	0x96
	.long	.LLST35
	.byte	0
	.uleb128 0x33
	.long	.LASF98
	.byte	0x1
	.byte	0x9a
	.long	0x2d
	.quad	.LFB46
	.quad	.LFE46-.LFB46
	.uleb128 0x1
	.byte	0x9c
	.long	0x10c4
	.uleb128 0x3c
	.long	.LASF99
	.byte	0x1
	.byte	0x9a
	.long	0x45d
	.long	.LLST30
	.uleb128 0x3b
	.string	"to"
	.byte	0x1
	.byte	0x9a
	.long	0x45d
	.long	.LLST31
	.uleb128 0x36
	.string	"x"
	.byte	0x1
	.byte	0x9c
	.long	0x2d
	.long	.LLST32
	.uleb128 0x36
	.string	"y"
	.byte	0x1
	.byte	0x9d
	.long	0x2d
	.long	.LLST33
	.uleb128 0x36
	.string	"z"
	.byte	0x1
	.byte	0x9e
	.long	0x2d
	.long	.LLST34
	.uleb128 0x30
	.quad	.LVL70
	.long	0x189b
	.byte	0
	.uleb128 0x33
	.long	.LASF100
	.byte	0x1
	.byte	0x95
	.long	0x2d
	.quad	.LFB45
	.quad	.LFE45-.LFB45
	.uleb128 0x1
	.byte	0x9c
	.long	0x1100
	.uleb128 0x3b
	.string	"v"
	.byte	0x1
	.byte	0x95
	.long	0x45d
	.long	.LLST29
	.uleb128 0x30
	.quad	.LVL62
	.long	0x189b
	.byte	0
	.uleb128 0x39
	.long	.LASF101
	.byte	0x1
	.byte	0x90
	.long	0x2d
	.byte	0x1
	.long	0x1123
	.uleb128 0x3a
	.string	"v"
	.byte	0x1
	.byte	0x90
	.long	0x45d
	.uleb128 0x3a
	.string	"m"
	.byte	0x1
	.byte	0x90
	.long	0x45d
	.byte	0
	.uleb128 0x39
	.long	.LASF102
	.byte	0x1
	.byte	0x84
	.long	0x50e
	.byte	0x1
	.long	0x114a
	.uleb128 0x3d
	.long	.LASF103
	.byte	0x1
	.byte	0x84
	.long	0x50e
	.uleb128 0x3a
	.string	"src"
	.byte	0x1
	.byte	0x84
	.long	0x45d
	.byte	0
	.uleb128 0x33
	.long	.LASF104
	.byte	0x1
	.byte	0x79
	.long	0x50e
	.quad	.LFB42
	.quad	.LFE42-.LFB42
	.uleb128 0x1
	.byte	0x9c
	.long	0x1254
	.uleb128 0x34
	.string	"a"
	.byte	0x1
	.byte	0x79
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"b"
	.byte	0x1
	.byte	0x79
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x34
	.string	"c"
	.byte	0x1
	.byte	0x79
	.long	0x45d
	.uleb128 0x1
	.byte	0x51
	.uleb128 0x36
	.string	"v"
	.byte	0x1
	.byte	0x7b
	.long	0xf0
	.long	.LLST16
	.uleb128 0x31
	.long	0xfbc
	.quad	.LBB160
	.long	.Ldebug_ranges0+0x60
	.byte	0x1
	.byte	0x7b
	.long	0x11c3
	.uleb128 0x25
	.long	0xfd5
	.long	.LLST17
	.uleb128 0x25
	.long	0xfcc
	.long	.LLST18
	.byte	0
	.uleb128 0x31
	.long	0xfbc
	.quad	.LBB167
	.long	.Ldebug_ranges0+0xc0
	.byte	0x1
	.byte	0x7c
	.long	0x11ed
	.uleb128 0x25
	.long	0xfd5
	.long	.LLST19
	.uleb128 0x25
	.long	0xfcc
	.long	.LLST20
	.byte	0
	.uleb128 0x3e
	.long	0x1123
	.quad	.LBB178
	.quad	.LBE178-.LBB178
	.byte	0x1
	.byte	0x7d
	.uleb128 0x25
	.long	0x113e
	.long	.LLST21
	.uleb128 0x25
	.long	0x1133
	.long	.LLST22
	.uleb128 0x3e
	.long	0x14d4
	.quad	.LBB180
	.quad	.LBE180-.LBB180
	.byte	0x1
	.byte	0x86
	.uleb128 0x25
	.long	0x1501
	.long	.LLST23
	.uleb128 0x25
	.long	0x14f8
	.long	.LLST24
	.uleb128 0x25
	.long	0x14ef
	.long	.LLST25
	.uleb128 0x25
	.long	0x14e4
	.long	.LLST22
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x33
	.long	.LASF105
	.byte	0x1
	.byte	0x71
	.long	0x50e
	.quad	.LFB41
	.quad	.LFE41-.LFB41
	.uleb128 0x1
	.byte	0x9c
	.long	0x12d5
	.uleb128 0x35
	.long	.LASF103
	.byte	0x1
	.byte	0x71
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"mat"
	.byte	0x1
	.byte	0x71
	.long	0x12d5
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x36
	.string	"a"
	.byte	0x1
	.byte	0x73
	.long	0x12db
	.long	.LLST12
	.uleb128 0x3e
	.long	0x14d4
	.quad	.LBB158
	.quad	.LBE158-.LBB158
	.byte	0x1
	.byte	0x74
	.uleb128 0x25
	.long	0x1501
	.long	.LLST13
	.uleb128 0x25
	.long	0x14f8
	.long	.LLST14
	.uleb128 0x26
	.long	0x14ef
	.uleb128 0x25
	.long	0x14e4
	.long	.LLST15
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x101
	.uleb128 0xc
	.long	0x2d
	.long	0x12eb
	.uleb128 0xd
	.long	0x49
	.byte	0x3
	.byte	0
	.uleb128 0x39
	.long	.LASF106
	.byte	0x1
	.byte	0x6b
	.long	0x50e
	.byte	0x1
	.long	0x1319
	.uleb128 0x3a
	.string	"a"
	.byte	0x1
	.byte	0x6b
	.long	0x50e
	.uleb128 0x3a
	.string	"b"
	.byte	0x1
	.byte	0x6b
	.long	0x45d
	.uleb128 0x37
	.string	"dir"
	.byte	0x1
	.byte	0x6d
	.long	0xf0
	.byte	0
	.uleb128 0x39
	.long	.LASF107
	.byte	0x1
	.byte	0x62
	.long	0x50e
	.byte	0x1
	.long	0x133e
	.uleb128 0x3a
	.string	"v"
	.byte	0x1
	.byte	0x62
	.long	0x50e
	.uleb128 0x3f
	.long	.LASF108
	.byte	0x1
	.byte	0x64
	.long	0x2d
	.byte	0
	.uleb128 0x33
	.long	.LASF109
	.byte	0x1
	.byte	0x5a
	.long	0x50e
	.quad	.LFB38
	.quad	.LFE38-.LFB38
	.uleb128 0x1
	.byte	0x9c
	.long	0x137a
	.uleb128 0x35
	.long	.LASF103
	.byte	0x1
	.byte	0x5a
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x35
	.long	.LASF110
	.byte	0x1
	.byte	0x5a
	.long	0x2d
	.uleb128 0x1
	.byte	0x61
	.byte	0
	.uleb128 0x39
	.long	.LASF111
	.byte	0x1
	.byte	0x54
	.long	0x50e
	.byte	0x1
	.long	0x13a1
	.uleb128 0x3d
	.long	.LASF103
	.byte	0x1
	.byte	0x54
	.long	0x50e
	.uleb128 0x3d
	.long	.LASF110
	.byte	0x1
	.byte	0x54
	.long	0x2d
	.byte	0
	.uleb128 0x33
	.long	.LASF112
	.byte	0x1
	.byte	0x4c
	.long	0x50e
	.quad	.LFB36
	.quad	.LFE36-.LFB36
	.uleb128 0x1
	.byte	0x9c
	.long	0x13df
	.uleb128 0x35
	.long	.LASF103
	.byte	0x1
	.byte	0x4c
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3c
	.long	.LASF110
	.byte	0x1
	.byte	0x4c
	.long	0x2d
	.long	.LLST2
	.byte	0
	.uleb128 0x33
	.long	.LASF113
	.byte	0x1
	.byte	0x44
	.long	0x50e
	.quad	.LFB35
	.quad	.LFE35-.LFB35
	.uleb128 0x1
	.byte	0x9c
	.long	0x141b
	.uleb128 0x35
	.long	.LASF103
	.byte	0x1
	.byte	0x44
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"src"
	.byte	0x1
	.byte	0x44
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x33
	.long	.LASF114
	.byte	0x1
	.byte	0x3c
	.long	0x50e
	.quad	.LFB34
	.quad	.LFE34-.LFB34
	.uleb128 0x1
	.byte	0x9c
	.long	0x1457
	.uleb128 0x35
	.long	.LASF103
	.byte	0x1
	.byte	0x3c
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"src"
	.byte	0x1
	.byte	0x3c
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x39
	.long	.LASF115
	.byte	0x1
	.byte	0x36
	.long	0x50e
	.byte	0x1
	.long	0x1471
	.uleb128 0x3a
	.string	"v"
	.byte	0x1
	.byte	0x36
	.long	0x50e
	.byte	0
	.uleb128 0x39
	.long	.LASF116
	.byte	0x1
	.byte	0x2e
	.long	0x50e
	.byte	0x1
	.long	0x1498
	.uleb128 0x3d
	.long	.LASF103
	.byte	0x1
	.byte	0x2e
	.long	0x50e
	.uleb128 0x3a
	.string	"src"
	.byte	0x1
	.byte	0x2e
	.long	0x45d
	.byte	0
	.uleb128 0x33
	.long	.LASF117
	.byte	0x1
	.byte	0x26
	.long	0x50e
	.quad	.LFB31
	.quad	.LFE31-.LFB31
	.uleb128 0x1
	.byte	0x9c
	.long	0x14d4
	.uleb128 0x35
	.long	.LASF103
	.byte	0x1
	.byte	0x26
	.long	0x50e
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x34
	.string	"src"
	.byte	0x1
	.byte	0x26
	.long	0x45d
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x39
	.long	.LASF118
	.byte	0x1
	.byte	0x1e
	.long	0x50e
	.byte	0x1
	.long	0x150b
	.uleb128 0x3d
	.long	.LASF103
	.byte	0x1
	.byte	0x1e
	.long	0x50e
	.uleb128 0x3a
	.string	"x"
	.byte	0x1
	.byte	0x1e
	.long	0x96
	.uleb128 0x3a
	.string	"y"
	.byte	0x1
	.byte	0x1e
	.long	0x96
	.uleb128 0x3a
	.string	"z"
	.byte	0x1
	.byte	0x1e
	.long	0x96
	.byte	0
	.uleb128 0x39
	.long	.LASF119
	.byte	0x1
	.byte	0x16
	.long	0x50e
	.byte	0x1
	.long	0x1532
	.uleb128 0x3d
	.long	.LASF103
	.byte	0x1
	.byte	0x16
	.long	0x50e
	.uleb128 0x3a
	.string	"src"
	.byte	0x1
	.byte	0x16
	.long	0x45d
	.byte	0
	.uleb128 0x39
	.long	.LASF120
	.byte	0x1
	.byte	0x11
	.long	0xf0
	.byte	0x1
	.long	0x155e
	.uleb128 0x3a
	.string	"x"
	.byte	0x1
	.byte	0x11
	.long	0x96
	.uleb128 0x3a
	.string	"y"
	.byte	0x1
	.byte	0x11
	.long	0x96
	.uleb128 0x3a
	.string	"z"
	.byte	0x1
	.byte	0x11
	.long	0x96
	.byte	0
	.uleb128 0x39
	.long	.LASF121
	.byte	0x1
	.byte	0xc
	.long	0xf0
	.byte	0x1
	.long	0x157a
	.uleb128 0x3a
	.string	"src"
	.byte	0x1
	.byte	0xc
	.long	0x45d
	.byte	0
	.uleb128 0x40
	.long	0x155e
	.quad	.LFB27
	.quad	.LFE27-.LFB27
	.uleb128 0x1
	.byte	0x9c
	.long	0x159d
	.uleb128 0x41
	.long	0x156e
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x40
	.long	0x1532
	.quad	.LFB28
	.quad	.LFE28-.LFB28
	.uleb128 0x1
	.byte	0x9c
	.long	0x15d2
	.uleb128 0x25
	.long	0x1542
	.long	.LLST0
	.uleb128 0x25
	.long	0x154b
	.long	.LLST1
	.uleb128 0x41
	.long	0x1554
	.uleb128 0x1
	.byte	0x63
	.byte	0
	.uleb128 0x40
	.long	0x150b
	.quad	.LFB29
	.quad	.LFE29-.LFB29
	.uleb128 0x1
	.byte	0x9c
	.long	0x15fc
	.uleb128 0x41
	.long	0x151b
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0x1526
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x40
	.long	0x14d4
	.quad	.LFB30
	.quad	.LFE30-.LFB30
	.uleb128 0x1
	.byte	0x9c
	.long	0x1634
	.uleb128 0x41
	.long	0x14e4
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0x14ef
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x41
	.long	0x14f8
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x41
	.long	0x1501
	.uleb128 0x1
	.byte	0x63
	.byte	0
	.uleb128 0x40
	.long	0x1471
	.quad	.LFB32
	.quad	.LFE32-.LFB32
	.uleb128 0x1
	.byte	0x9c
	.long	0x165e
	.uleb128 0x41
	.long	0x1481
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0x148c
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x40
	.long	0x1457
	.quad	.LFB33
	.quad	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.long	0x1681
	.uleb128 0x41
	.long	0x1467
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x40
	.long	0x137a
	.quad	.LFB37
	.quad	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.long	0x16ad
	.uleb128 0x41
	.long	0x138a
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x25
	.long	0x1395
	.long	.LLST3
	.byte	0
	.uleb128 0x40
	.long	0x1319
	.quad	.LFB39
	.quad	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.long	0x16e8
	.uleb128 0x25
	.long	0x1329
	.long	.LLST4
	.uleb128 0x42
	.long	0x1332
	.long	.LLST5
	.uleb128 0x30
	.quad	.LVL21
	.long	0x189b
	.byte	0
	.uleb128 0x40
	.long	0x12eb
	.quad	.LFB40
	.quad	.LFE40-.LFB40
	.uleb128 0x1
	.byte	0x9c
	.long	0x17a4
	.uleb128 0x25
	.long	0x12fb
	.long	.LLST6
	.uleb128 0x25
	.long	0x1304
	.long	.LLST7
	.uleb128 0x28
	.long	0x130d
	.uleb128 0x31
	.long	0x1471
	.quad	.LBB148
	.long	.Ldebug_ranges0+0
	.byte	0x1
	.byte	0x6e
	.long	0x1744
	.uleb128 0x25
	.long	0x148c
	.long	.LLST8
	.uleb128 0x25
	.long	0x1481
	.long	.LLST9
	.byte	0
	.uleb128 0x31
	.long	0x1319
	.quad	.LBB152
	.long	.Ldebug_ranges0+0x30
	.byte	0x1
	.byte	0x6e
	.long	0x177d
	.uleb128 0x25
	.long	0x1329
	.long	.LLST10
	.uleb128 0x27
	.long	.Ldebug_ranges0+0x30
	.uleb128 0x28
	.long	0x16d1
	.uleb128 0x30
	.quad	.LVL28
	.long	0x189b
	.byte	0
	.byte	0
	.uleb128 0x3e
	.long	0x150b
	.quad	.LBB155
	.quad	.LBE155-.LBB155
	.byte	0x1
	.byte	0x6e
	.uleb128 0x26
	.long	0x1526
	.uleb128 0x25
	.long	0x151b
	.long	.LLST11
	.byte	0
	.byte	0
	.uleb128 0x40
	.long	0x1123
	.quad	.LFB43
	.quad	.LFE43-.LFB43
	.uleb128 0x1
	.byte	0x9c
	.long	0x1802
	.uleb128 0x41
	.long	0x1133
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0x113e
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3e
	.long	0x14d4
	.quad	.LBB182
	.quad	.LBE182-.LBB182
	.byte	0x1
	.byte	0x86
	.uleb128 0x26
	.long	0x1501
	.uleb128 0x25
	.long	0x14f8
	.long	.LLST27
	.uleb128 0x26
	.long	0x14ef
	.uleb128 0x25
	.long	0x14e4
	.long	.LLST28
	.byte	0
	.byte	0
	.uleb128 0x40
	.long	0x1100
	.quad	.LFB44
	.quad	.LFE44-.LFB44
	.uleb128 0x1
	.byte	0x9c
	.long	0x182c
	.uleb128 0x41
	.long	0x1110
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0x1119
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x40
	.long	0xfbc
	.quad	.LFB49
	.quad	.LFE49-.LFB49
	.uleb128 0x1
	.byte	0x9c
	.long	0x1856
	.uleb128 0x41
	.long	0xfcc
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0xfd5
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x40
	.long	0xef4
	.quad	.LFB52
	.quad	.LFE52-.LFB52
	.uleb128 0x1
	.byte	0x9c
	.long	0x1880
	.uleb128 0x41
	.long	0xf04
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x41
	.long	0xf0d
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x43
	.long	.LASF122
	.long	.LASF122
	.byte	0x7
	.value	0x13e
	.uleb128 0x44
	.long	.LASF131
	.long	.LASF132
	.byte	0xa
	.byte	0
	.long	.LASF131
	.uleb128 0x45
	.long	.LASF123
	.long	.LASF123
	.byte	0x9
	.byte	0x95
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x88
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x88
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x13
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x2115
	.uleb128 0x19
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x410a
	.byte	0
	.uleb128 0x2
	.uleb128 0x18
	.uleb128 0x2111
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x2115
	.uleb128 0x19
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2a
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x2e
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2f
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x30
	.uleb128 0x4109
	.byte	0
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x31
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x32
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x17
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x33
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x34
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x35
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x36
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x37
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x38
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x39
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3a
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3b
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3c
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3d
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x3e
	.uleb128 0x1d
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x58
	.uleb128 0xb
	.uleb128 0x59
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x3f
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x40
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x41
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x42
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x43
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.byte	0
	.byte	0
	.uleb128 0x44
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x6e
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x45
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.uleb128 0x6e
	.uleb128 0xe
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST113:
	.quad	.LVL240-.Ltext0
	.quad	.LVL242-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL242-.Ltext0
	.quad	.LVL243-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL243-1-.Ltext0
	.quad	.LVL243-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	.LVL243-.Ltext0
	.quad	.LVL244-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL244-.Ltext0
	.quad	.LFE62-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LLST114:
	.quad	.LVL240-.Ltext0
	.quad	.LVL241-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL241-.Ltext0
	.quad	.LVL243-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL243-.Ltext0
	.quad	.LVL245-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL245-1-.Ltext0
	.quad	.LFE62-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST109:
	.quad	.LVL234-.Ltext0
	.quad	.LVL236-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL236-.Ltext0
	.quad	.LVL239-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL239-.Ltext0
	.quad	.LFE61-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST110:
	.quad	.LVL234-.Ltext0
	.quad	.LVL235-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL235-.Ltext0
	.quad	.LFE61-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -44
	.quad	0
	.quad	0
.LLST111:
	.quad	.LVL234-.Ltext0
	.quad	.LVL237-1-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	.LVL237-1-.Ltext0
	.quad	.LFE61-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST112:
	.quad	.LVL234-.Ltext0
	.quad	.LVL237-1-.Ltext0
	.value	0x1
	.byte	0x63
	.quad	.LVL237-1-.Ltext0
	.quad	.LFE61-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -48
	.quad	0
	.quad	0
.LLST101:
	.quad	.LVL218-.Ltext0
	.quad	.LVL229-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL229-.Ltext0
	.quad	.LVL232-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	.LVL232-.Ltext0
	.quad	.LVL233-1-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL233-1-.Ltext0
	.quad	.LFE60-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -32
	.quad	0
	.quad	0
.LLST102:
	.quad	.LVL218-.Ltext0
	.quad	.LVL229-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL229-.Ltext0
	.quad	.LVL232-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL232-.Ltext0
	.quad	.LVL233-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL233-1-.Ltext0
	.quad	.LFE60-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -24
	.quad	0
	.quad	0
.LLST103:
	.quad	.LVL218-.Ltext0
	.quad	.LVL229-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL229-.Ltext0
	.quad	.LVL232-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL232-.Ltext0
	.quad	.LVL233-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL233-1-.Ltext0
	.quad	.LFE60-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LLST104:
	.quad	.LVL218-.Ltext0
	.quad	.LVL229-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL229-.Ltext0
	.quad	.LVL232-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	.LVL232-.Ltext0
	.quad	.LVL233-1-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL233-1-.Ltext0
	.quad	.LFE60-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LLST105:
	.quad	.LVL219-.Ltext0
	.quad	.LVL221-.Ltext0
	.value	0xb
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL221-.Ltext0
	.quad	.LVL222-.Ltext0
	.value	0xb
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL222-.Ltext0
	.quad	.LVL223-.Ltext0
	.value	0x16
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL223-.Ltext0
	.quad	.LVL225-.Ltext0
	.value	0x16
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL225-.Ltext0
	.quad	.LVL226-.Ltext0
	.value	0x1f
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL226-.Ltext0
	.quad	.LVL228-.Ltext0
	.value	0x2a
	.byte	0x71
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL228-.Ltext0
	.quad	.LVL229-.Ltext0
	.value	0x2c
	.byte	0x71
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL232-.Ltext0
	.quad	.LVL233-1-.Ltext0
	.value	0x2c
	.byte	0x71
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST106:
	.quad	.LVL220-.Ltext0
	.quad	.LVL224-.Ltext0
	.value	0xb
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL224-.Ltext0
	.quad	.LVL229-.Ltext0
	.value	0x16
	.byte	0x72
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL232-.Ltext0
	.quad	.LVL233-1-.Ltext0
	.value	0x16
	.byte	0x72
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST107:
	.quad	.LVL220-.Ltext0
	.quad	.LVL227-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+1405
	.sleb128 0
	.quad	0
	.quad	0
.LLST108:
	.quad	.LVL227-.Ltext0
	.quad	.LVL231-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+1419
	.sleb128 0
	.quad	.LVL232-.Ltext0
	.quad	.LFE60-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+1419
	.sleb128 0
	.quad	0
	.quad	0
.LLST100:
	.quad	.LVL216-.Ltext0
	.quad	.LVL217-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL217-.Ltext0
	.quad	.LFE59-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST96:
	.quad	.LVL208-.Ltext0
	.quad	.LVL209-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL209-.Ltext0
	.quad	.LFE58-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST97:
	.quad	.LVL210-.Ltext0
	.quad	.LVL213-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	.LVL213-.Ltext0
	.quad	.LFE58-.Ltext0
	.value	0xc
	.byte	0x75
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.quad	0
	.quad	0
.LLST98:
	.quad	.LVL211-.Ltext0
	.quad	.LVL214-.Ltext0
	.value	0x1
	.byte	0x64
	.quad	.LVL214-.Ltext0
	.quad	.LFE58-.Ltext0
	.value	0xc
	.byte	0x75
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.quad	0
	.quad	0
.LLST99:
	.quad	.LVL212-.Ltext0
	.quad	.LVL215-.Ltext0
	.value	0x1
	.byte	0x63
	.quad	.LVL215-.Ltext0
	.quad	.LFE58-.Ltext0
	.value	0xc
	.byte	0x75
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.quad	0
	.quad	0
.LLST93:
	.quad	.LVL204-.Ltext0
	.quad	.LVL205-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL205-.Ltext0
	.quad	.LFE57-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST94:
	.quad	.LVL204-.Ltext0
	.quad	.LVL206-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	.LVL206-.Ltext0
	.quad	.LFE57-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST95:
	.quad	.LVL206-.Ltext0
	.quad	.LVL207-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL207-.Ltext0
	.quad	.LFE57-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	0
	.quad	0
.LLST89:
	.quad	.LVL197-.Ltext0
	.quad	.LVL200-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL200-.Ltext0
	.quad	.LFE56-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST90:
	.quad	.LVL197-.Ltext0
	.quad	.LVL198-.Ltext0
	.value	0x16
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL198-.Ltext0
	.quad	.LVL199-.Ltext0
	.value	0x15
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL199-.Ltext0
	.quad	.LVL200-.Ltext0
	.value	0x14
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL200-.Ltext0
	.quad	.LVL201-.Ltext0
	.value	0xb
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL201-.Ltext0
	.quad	.LVL202-.Ltext0
	.value	0x16
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL202-.Ltext0
	.quad	.LFE56-.Ltext0
	.value	0xa
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST91:
	.quad	.LVL197-.Ltext0
	.quad	.LVL199-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	0
	.quad	0
.LLST92:
	.quad	.LVL199-.Ltext0
	.quad	.LVL203-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST69:
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL163-.Ltext0
	.quad	.LVL193-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	.LVL193-.Ltext0
	.quad	.LVL194-1-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL194-1-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x3
	.byte	0x91
	.sleb128 -80
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LLST70:
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL163-.Ltext0
	.quad	.LVL193-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL193-.Ltext0
	.quad	.LVL194-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL194-1-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x3
	.byte	0x91
	.sleb128 -72
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST71:
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL163-.Ltext0
	.quad	.LVL193-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL193-.Ltext0
	.quad	.LVL194-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL194-1-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -64
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LLST72:
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL163-.Ltext0
	.quad	.LVL193-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	.LVL193-.Ltext0
	.quad	.LVL194-1-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL194-1-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -56
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LLST73:
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	.LVL163-.Ltext0
	.quad	.LVL193-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x58
	.byte	0x9f
	.quad	.LVL193-.Ltext0
	.quad	.LVL194-1-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	.LVL194-1-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -48
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x58
	.byte	0x9f
	.quad	0
	.quad	0
.LLST74:
	.quad	.LVL173-.Ltext0
	.quad	.LVL174-.Ltext0
	.value	0xe
	.byte	0x74
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL174-.Ltext0
	.quad	.LVL175-.Ltext0
	.value	0x16
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL175-.Ltext0
	.quad	.LVL176-.Ltext0
	.value	0x1e
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL176-.Ltext0
	.quad	.LVL177-.Ltext0
	.value	0x15
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL177-.Ltext0
	.quad	.LVL178-.Ltext0
	.value	0xc
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL178-.Ltext0
	.quad	.LVL179-.Ltext0
	.value	0x14
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL179-.Ltext0
	.quad	.LVL180-.Ltext0
	.value	0x1d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL180-.Ltext0
	.quad	.LVL181-.Ltext0
	.value	0x26
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL181-.Ltext0
	.quad	.LVL182-.Ltext0
	.value	0x1d
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL182-.Ltext0
	.quad	.LVL188-.Ltext0
	.value	0x26
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL188-.Ltext0
	.quad	.LVL190-.Ltext0
	.value	0x1c
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL190-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0x10
	.byte	0x93
	.uleb128 0x8
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST75:
	.quad	.LVL183-.Ltext0
	.quad	.LVL184-.Ltext0
	.value	0x38
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL184-.Ltext0
	.quad	.LVL185-.Ltext0
	.value	0x28
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x1b
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL185-.Ltext0
	.quad	.LVL186-.Ltext0
	.value	0x16
	.byte	0x93
	.uleb128 0x8
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL186-.Ltext0
	.quad	.LVL187-.Ltext0
	.value	0x24
	.byte	0x93
	.uleb128 0x8
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x22
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL187-.Ltext0
	.quad	.LVL189-.Ltext0
	.value	0x27
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x22
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL189-.Ltext0
	.quad	.LVL191-.Ltext0
	.value	0x28
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x22
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1b
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x22
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL191-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0xb
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST76:
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL163-.Ltext0
	.quad	.LVL167-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL193-.Ltext0
	.quad	.LVL194-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL194-1-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -64
	.quad	0
	.quad	0
.LLST77:
	.quad	.LVL167-.Ltext0
	.quad	.LVL169-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	.LVL195-.Ltext0
	.quad	.LVL196-1-.Ltext0
	.value	0x1
	.byte	0x58
	.quad	0
	.quad	0
.LLST78:
	.quad	.LVL167-.Ltext0
	.quad	.LVL171-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2207
	.sleb128 0
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2207
	.sleb128 0
	.quad	0
	.quad	0
.LLST79:
	.quad	.LVL167-.Ltext0
	.quad	.LVL168-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2207
	.sleb128 0
	.quad	0
	.quad	0
.LLST80:
	.quad	.LVL167-.Ltext0
	.quad	.LVL168-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2378
	.sleb128 0
	.quad	0
	.quad	0
.LLST81:
	.quad	.LVL168-.Ltext0
	.quad	.LVL171-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2378
	.sleb128 0
	.quad	.LVL195-.Ltext0
	.quad	.LFE55-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2378
	.sleb128 0
	.quad	0
	.quad	0
.LLST82:
	.quad	.LVL171-.Ltext0
	.quad	.LVL172-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2207
	.sleb128 0
	.quad	0
	.quad	0
.LLST83:
	.quad	.LVL171-.Ltext0
	.quad	.LVL172-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LLST84:
	.quad	.LVL173-.Ltext0
	.quad	.LVL178-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	0
	.quad	0
.LLST85:
	.quad	.LVL178-.Ltext0
	.quad	.LVL183-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2241
	.sleb128 0
	.quad	0
	.quad	0
.LLST86:
	.quad	.LVL178-.Ltext0
	.quad	.LVL183-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LLST87:
	.quad	.LVL183-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2257
	.sleb128 0
	.quad	0
	.quad	0
.LLST88:
	.quad	.LVL183-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST54:
	.quad	.LVL126-.Ltext0
	.quad	.LVL127-.Ltext0
	.value	0xe
	.byte	0x78
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL127-.Ltext0
	.quad	.LVL128-.Ltext0
	.value	0xe
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL128-.Ltext0
	.quad	.LVL129-.Ltext0
	.value	0xd
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6a
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL129-.Ltext0
	.quad	.LVL145-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6a
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL145-.Ltext0
	.quad	.LVL146-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL146-.Ltext0
	.quad	.LVL148-.Ltext0
	.value	0xb
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL148-.Ltext0
	.quad	.LVL160-.Ltext0
	.value	0x16
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL160-.Ltext0
	.quad	.LVL161-.Ltext0
	.value	0x6
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0xc
	.quad	.LVL161-.Ltext0
	.quad	.LFE54-.Ltext0
	.value	0x16
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x78
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST55:
	.quad	.LVL129-.Ltext0
	.quad	.LVL156-.Ltext0
	.value	0xb
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL156-.Ltext0
	.quad	.LVL158-.Ltext0
	.value	0xa
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL158-.Ltext0
	.quad	.LVL159-.Ltext0
	.value	0x7
	.byte	0x93
	.uleb128 0x8
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL159-.Ltext0
	.quad	.LVL160-.Ltext0
	.value	0x12
	.byte	0x93
	.uleb128 0x8
	.byte	0x79
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL161-.Ltext0
	.quad	.LFE54-.Ltext0
	.value	0xb
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST56:
	.quad	.LVL129-.Ltext0
	.quad	.LVL130-.Ltext0
	.value	0xa
	.byte	0x6d
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x6c
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL130-.Ltext0
	.quad	.LVL135-.Ltext0
	.value	0xb
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x6e
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL135-.Ltext0
	.quad	.LVL139-.Ltext0
	.value	0x1c
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x18
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6e
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL139-.Ltext0
	.quad	.LVL140-.Ltext0
	.value	0x1c
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x18
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL140-.Ltext0
	.quad	.LVL142-.Ltext0
	.value	0x2b
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x18
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL142-.Ltext0
	.quad	.LVL144-.Ltext0
	.value	0x19
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL144-.Ltext0
	.quad	.LVL151-.Ltext0
	.value	0x16
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL151-.Ltext0
	.quad	.LVL153-.Ltext0
	.value	0x18
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL153-.Ltext0
	.quad	.LVL155-.Ltext0
	.value	0x1a
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x71
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	0
	.quad	0
.LLST57:
	.quad	.LVL132-.Ltext0
	.quad	.LVL133-.Ltext0
	.value	0xe
	.byte	0x74
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL133-.Ltext0
	.quad	.LVL134-.Ltext0
	.value	0xd
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL134-.Ltext0
	.quad	.LVL136-.Ltext0
	.value	0xd
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL136-.Ltext0
	.quad	.LVL137-.Ltext0
	.value	0xc
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL137-.Ltext0
	.quad	.LVL138-.Ltext0
	.value	0xc
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL138-.Ltext0
	.quad	.LVL147-.Ltext0
	.value	0xb
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL147-.Ltext0
	.quad	.LVL150-.Ltext0
	.value	0x16
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL150-.Ltext0
	.quad	.LVL155-.Ltext0
	.value	0x21
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL155-.Ltext0
	.quad	.LVL160-.Ltext0
	.value	0x15
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL160-.Ltext0
	.quad	.LVL161-.Ltext0
	.value	0x7
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	0
	.quad	0
.LLST58:
	.quad	.LVL143-.Ltext0
	.quad	.LVL147-.Ltext0
	.value	0xb
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL147-.Ltext0
	.quad	.LVL149-.Ltext0
	.value	0x16
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL149-.Ltext0
	.quad	.LVL150-.Ltext0
	.value	0xb
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL150-.Ltext0
	.quad	.LVL152-.Ltext0
	.value	0x16
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL152-.Ltext0
	.quad	.LVL161-.Ltext0
	.value	0xb
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST59:
	.quad	.LVL126-.Ltext0
	.quad	.LVL129-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	0
	.quad	0
.LLST60:
	.quad	.LVL129-.Ltext0
	.quad	.LVL130-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2767
	.sleb128 0
	.quad	0
	.quad	0
.LLST61:
	.quad	.LVL130-.Ltext0
	.quad	.LVL131-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2767
	.sleb128 0
	.quad	0
	.quad	0
.LLST62:
	.quad	.LVL130-.Ltext0
	.quad	.LVL131-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2781
	.sleb128 0
	.quad	0
	.quad	0
.LLST63:
	.quad	.LVL132-.Ltext0
	.quad	.LVL138-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	0
	.quad	0
.LLST64:
	.quad	.LVL138-.Ltext0
	.quad	.LVL141-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2781
	.sleb128 0
	.quad	0
	.quad	0
.LLST65:
	.quad	.LVL143-.Ltext0
	.quad	.LVL152-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2753
	.sleb128 0
	.quad	0
	.quad	0
.LLST66:
	.quad	.LVL152-.Ltext0
	.quad	.LVL154-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LLST67:
	.quad	.LVL157-.Ltext0
	.quad	.LVL160-.Ltext0
	.value	0x1
	.byte	0x69
	.quad	0
	.quad	0
.LLST68:
	.quad	.LVL157-.Ltext0
	.quad	.LVL160-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST39:
	.quad	.LVL86-.Ltext0
	.quad	.LVL87-.Ltext0
	.value	0xe
	.byte	0x70
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x70
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x70
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL87-.Ltext0
	.quad	.LVL88-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6a
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL88-.Ltext0
	.quad	.LVL89-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6a
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL89-.Ltext0
	.quad	.LVL90-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6a
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL90-.Ltext0
	.quad	.LVL109-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6a
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL109-.Ltext0
	.quad	.LVL110-.Ltext0
	.value	0xc
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL110-.Ltext0
	.quad	.LVL112-.Ltext0
	.value	0xb
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL112-.Ltext0
	.quad	.LVL124-.Ltext0
	.value	0x1c
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x72
	.sleb128 8
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL124-.Ltext0
	.quad	.LVL125-.Ltext0
	.value	0x6
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0xc
	.quad	.LVL125-.Ltext0
	.quad	.LFE53-.Ltext0
	.value	0x1c
	.byte	0x90
	.uleb128 0x20
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x72
	.sleb128 8
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST40:
	.quad	.LVL90-.Ltext0
	.quad	.LVL120-.Ltext0
	.value	0xb
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL120-.Ltext0
	.quad	.LVL122-.Ltext0
	.value	0xa
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL122-.Ltext0
	.quad	.LVL123-.Ltext0
	.value	0x7
	.byte	0x93
	.uleb128 0x8
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL123-.Ltext0
	.quad	.LVL124-.Ltext0
	.value	0x18
	.byte	0x93
	.uleb128 0x8
	.byte	0x72
	.sleb128 16
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL125-.Ltext0
	.quad	.LFE53-.Ltext0
	.value	0xb
	.byte	0x62
	.byte	0x93
	.uleb128 0x4
	.byte	0x68
	.byte	0x93
	.uleb128 0x4
	.byte	0x67
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST41:
	.quad	.LVL90-.Ltext0
	.quad	.LVL91-.Ltext0
	.value	0xb
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x6c
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL91-.Ltext0
	.quad	.LVL92-.Ltext0
	.value	0xb
	.byte	0x6d
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x6c
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL92-.Ltext0
	.quad	.LVL93-.Ltext0
	.value	0xb
	.byte	0x6d
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x6c
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL93-.Ltext0
	.quad	.LVL94-.Ltext0
	.value	0xc
	.byte	0x6d
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x6c
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL94-.Ltext0
	.quad	.LVL99-.Ltext0
	.value	0xb
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x6e
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL99-.Ltext0
	.quad	.LVL103-.Ltext0
	.value	0x1c
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x18
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6e
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL103-.Ltext0
	.quad	.LVL104-.Ltext0
	.value	0x1c
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x18
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL104-.Ltext0
	.quad	.LVL106-.Ltext0
	.value	0x2b
	.byte	0x71
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x18
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL106-.Ltext0
	.quad	.LVL108-.Ltext0
	.value	0x19
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL108-.Ltext0
	.quad	.LVL115-.Ltext0
	.value	0x16
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x1c
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL115-.Ltext0
	.quad	.LVL117-.Ltext0
	.value	0x18
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x1d
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL117-.Ltext0
	.quad	.LVL119-.Ltext0
	.value	0x1a
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x71
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x17
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	0
	.quad	0
.LLST42:
	.quad	.LVL96-.Ltext0
	.quad	.LVL97-.Ltext0
	.value	0xe
	.byte	0x74
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL97-.Ltext0
	.quad	.LVL98-.Ltext0
	.value	0xd
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL98-.Ltext0
	.quad	.LVL100-.Ltext0
	.value	0xd
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL100-.Ltext0
	.quad	.LVL101-.Ltext0
	.value	0xc
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL101-.Ltext0
	.quad	.LVL102-.Ltext0
	.value	0xc
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL102-.Ltext0
	.quad	.LVL111-.Ltext0
	.value	0xb
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL111-.Ltext0
	.quad	.LVL114-.Ltext0
	.value	0x17
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL114-.Ltext0
	.quad	.LVL119-.Ltext0
	.value	0x25
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL119-.Ltext0
	.quad	.LVL124-.Ltext0
	.value	0x18
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL124-.Ltext0
	.quad	.LVL125-.Ltext0
	.value	0x7
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	0
	.quad	0
.LLST43:
	.quad	.LVL107-.Ltext0
	.quad	.LVL111-.Ltext0
	.value	0xb
	.byte	0x69
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL111-.Ltext0
	.quad	.LVL113-.Ltext0
	.value	0x17
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL113-.Ltext0
	.quad	.LVL114-.Ltext0
	.value	0xb
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL114-.Ltext0
	.quad	.LVL116-.Ltext0
	.value	0x19
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x6f
	.byte	0x93
	.uleb128 0x4
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x72
	.sleb128 0
	.byte	0x6
	.byte	0x23
	.uleb128 0x8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL116-.Ltext0
	.quad	.LVL125-.Ltext0
	.value	0xb
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x6b
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST44:
	.quad	.LVL90-.Ltext0
	.quad	.LVL94-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3343
	.sleb128 0
	.quad	0
	.quad	0
.LLST45:
	.quad	.LVL86-.Ltext0
	.quad	.LVL90-.Ltext0
	.value	0x2
	.byte	0x72
	.sleb128 0
	.quad	0
	.quad	0
.LLST46:
	.quad	.LVL94-.Ltext0
	.quad	.LVL95-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3343
	.sleb128 0
	.quad	0
	.quad	0
.LLST47:
	.quad	.LVL94-.Ltext0
	.quad	.LVL95-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3357
	.sleb128 0
	.quad	0
	.quad	0
.LLST48:
	.quad	.LVL96-.Ltext0
	.quad	.LVL102-.Ltext0
	.value	0x2
	.byte	0x72
	.sleb128 0
	.quad	0
	.quad	0
.LLST49:
	.quad	.LVL102-.Ltext0
	.quad	.LVL105-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3357
	.sleb128 0
	.quad	0
	.quad	0
.LLST50:
	.quad	.LVL107-.Ltext0
	.quad	.LVL116-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3329
	.sleb128 0
	.quad	0
	.quad	0
.LLST51:
	.quad	.LVL116-.Ltext0
	.quad	.LVL118-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LLST52:
	.quad	.LVL121-.Ltext0
	.quad	.LVL124-.Ltext0
	.value	0x1
	.byte	0x69
	.quad	0
	.quad	0
.LLST53:
	.quad	.LVL121-.Ltext0
	.quad	.LVL124-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST36:
	.quad	.LVL80-.Ltext0
	.quad	.LVL81-.Ltext0
	.value	0x19
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL81-.Ltext0
	.quad	.LVL82-.Ltext0
	.value	0x12
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL82-.Ltext0
	.quad	.LVL83-.Ltext0
	.value	0xb
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL83-.Ltext0
	.quad	.LFE51-.Ltext0
	.value	0x1d
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST37:
	.quad	.LVL79-.Ltext0
	.quad	.LVL80-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	0
	.quad	0
.LLST38:
	.quad	.LVL79-.Ltext0
	.quad	.LVL80-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST35:
	.quad	.LVL71-.Ltext0
	.quad	.LVL72-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL72-.Ltext0
	.quad	.LFE47-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST30:
	.quad	.LVL63-.Ltext0
	.quad	.LVL70-1-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL70-1-.Ltext0
	.quad	.LFE46-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LLST31:
	.quad	.LVL63-.Ltext0
	.quad	.LVL70-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL70-1-.Ltext0
	.quad	.LFE46-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST32:
	.quad	.LVL64-.Ltext0
	.quad	.LVL67-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	.LVL67-.Ltext0
	.quad	.LVL70-1-.Ltext0
	.value	0xc
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.quad	0
	.quad	0
.LLST33:
	.quad	.LVL65-.Ltext0
	.quad	.LVL68-.Ltext0
	.value	0x1
	.byte	0x63
	.quad	.LVL68-.Ltext0
	.quad	.LVL70-1-.Ltext0
	.value	0xc
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.quad	0
	.quad	0
.LLST34:
	.quad	.LVL66-.Ltext0
	.quad	.LVL69-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL69-.Ltext0
	.quad	.LVL70-1-.Ltext0
	.value	0xc
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.quad	0
	.quad	0
.LLST29:
	.quad	.LVL61-.Ltext0
	.quad	.LVL62-1-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL62-1-.Ltext0
	.quad	.LFE45-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LLST16:
	.quad	.LVL41-.Ltext0
	.quad	.LVL42-.Ltext0
	.value	0x8
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL42-.Ltext0
	.quad	.LVL45-.Ltext0
	.value	0xb
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL45-.Ltext0
	.quad	.LVL51-.Ltext0
	.value	0x14
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x66
	.byte	0x93
	.uleb128 0x4
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x9f
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST17:
	.quad	.LVL40-.Ltext0
	.quad	.LVL41-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST18:
	.quad	.LVL40-.Ltext0
	.quad	.LVL41-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	0
	.quad	0
.LLST19:
	.quad	.LVL42-.Ltext0
	.quad	.LVL43-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST20:
	.quad	.LVL42-.Ltext0
	.quad	.LVL43-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	0
	.quad	0
.LLST21:
	.quad	.LVL43-.Ltext0
	.quad	.LVL51-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+4492
	.sleb128 0
	.quad	0
	.quad	0
.LLST22:
	.quad	.LVL43-.Ltext0
	.quad	.LVL51-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST23:
	.quad	.LVL43-.Ltext0
	.quad	.LVL46-.Ltext0
	.value	0x10
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL46-.Ltext0
	.quad	.LVL47-.Ltext0
	.value	0x18
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL47-.Ltext0
	.quad	.LVL50-.Ltext0
	.value	0x20
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL50-.Ltext0
	.quad	.LVL51-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	0
	.quad	0
.LLST24:
	.quad	.LVL43-.Ltext0
	.quad	.LVL44-.Ltext0
	.value	0x10
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL44-.Ltext0
	.quad	.LVL45-.Ltext0
	.value	0x16
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL45-.Ltext0
	.quad	.LVL47-.Ltext0
	.value	0x1c
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL47-.Ltext0
	.quad	.LVL49-.Ltext0
	.value	0x24
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x15
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x74
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL49-.Ltext0
	.quad	.LVL51-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	0
	.quad	0
.LLST25:
	.quad	.LVL43-.Ltext0
	.quad	.LVL44-.Ltext0
	.value	0x10
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL44-.Ltext0
	.quad	.LVL45-.Ltext0
	.value	0x16
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL45-.Ltext0
	.quad	.LVL46-.Ltext0
	.value	0x1c
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL46-.Ltext0
	.quad	.LVL48-.Ltext0
	.value	0x24
	.byte	0x74
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x75
	.sleb128 4
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x71
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0x1e
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x19
	.uleb128 0x2d
	.byte	0x1c
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL48-.Ltext0
	.quad	.LVL51-.Ltext0
	.value	0x1
	.byte	0x67
	.quad	0
	.quad	0
.LLST12:
	.quad	.LVL30-.Ltext0
	.quad	.LVL31-.Ltext0
	.value	0x5
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0xc
	.quad	.LVL31-.Ltext0
	.quad	.LVL32-.Ltext0
	.value	0x8
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL32-.Ltext0
	.quad	.LVL33-.Ltext0
	.value	0x11
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL33-.Ltext0
	.quad	.LVL34-.Ltext0
	.value	0x12
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL34-.Ltext0
	.quad	.LVL35-.Ltext0
	.value	0x13
	.byte	0x75
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL35-.Ltext0
	.quad	.LVL37-.Ltext0
	.value	0x14
	.byte	0x75
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 8
	.byte	0x93
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL37-.Ltext0
	.quad	.LVL38-.Ltext0
	.value	0x12
	.byte	0x75
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x75
	.sleb128 4
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL38-.Ltext0
	.quad	.LVL39-.Ltext0
	.value	0xe
	.byte	0x75
	.sleb128 0
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL39-.Ltext0
	.quad	.LFE41-.Ltext0
	.value	0xa
	.byte	0x93
	.uleb128 0xc
	.byte	0x9e
	.uleb128 0x4
	.long	0x3f800000
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST13:
	.quad	.LVL36-.Ltext0
	.quad	.LVL37-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	0
	.quad	0
.LLST14:
	.quad	.LVL36-.Ltext0
	.quad	.LVL37-.Ltext0
	.value	0x1
	.byte	0x63
	.quad	0
	.quad	0
.LLST15:
	.quad	.LVL36-.Ltext0
	.quad	.LVL37-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST2:
	.quad	.LVL11-.Ltext0
	.quad	.LVL12-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL12-.Ltext0
	.quad	.LFE36-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST0:
	.quad	.LVL1-.Ltext0
	.quad	.LVL3-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL3-.Ltext0
	.quad	.LFE28-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST1:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	.LVL2-.Ltext0
	.quad	.LFE28-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST3:
	.quad	.LVL13-.Ltext0
	.quad	.LVL14-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL14-.Ltext0
	.quad	.LFE37-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST4:
	.quad	.LVL16-.Ltext0
	.quad	.LVL17-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL17-.Ltext0
	.quad	.LVL20-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	.LVL20-.Ltext0
	.quad	.LVL21-1-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL21-1-.Ltext0
	.quad	.LFE39-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -24
	.quad	0
	.quad	0
.LLST5:
	.quad	.LVL18-.Ltext0
	.quad	.LVL19-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL19-.Ltext0
	.quad	.LVL20-.Ltext0
	.value	0xc
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x3f800000
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x1b
	.byte	0x9f
	.quad	0
	.quad	0
.LLST6:
	.quad	.LVL22-.Ltext0
	.quad	.LVL24-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL24-.Ltext0
	.quad	.LVL27-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	.LVL27-.Ltext0
	.quad	.LVL28-1-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL28-1-.Ltext0
	.quad	.LFE40-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -24
	.quad	0
	.quad	0
.LLST7:
	.quad	.LVL22-.Ltext0
	.quad	.LVL24-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL24-.Ltext0
	.quad	.LVL27-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL27-.Ltext0
	.quad	.LVL28-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL28-1-.Ltext0
	.quad	.LFE40-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST8:
	.quad	.LVL22-.Ltext0
	.quad	.LVL23-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST9:
	.quad	.LVL22-.Ltext0
	.quad	.LVL23-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+5909
	.sleb128 0
	.quad	0
	.quad	0
.LLST10:
	.quad	.LVL23-.Ltext0
	.quad	.LVL25-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+5909
	.sleb128 0
	.quad	.LVL27-.Ltext0
	.quad	.LFE40-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+5909
	.sleb128 0
	.quad	0
	.quad	0
.LLST11:
	.quad	.LVL25-.Ltext0
	.quad	.LVL26-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST27:
	.quad	.LVL54-.Ltext0
	.quad	.LVL55-.Ltext0
	.value	0x10
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x14
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL55-.Ltext0
	.quad	.LVL56-.Ltext0
	.value	0x12
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL56-.Ltext0
	.quad	.LVL57-.Ltext0
	.value	0x14
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x75
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL57-.Ltext0
	.quad	.LVL58-.Ltext0
	.value	0x16
	.byte	0xf5
	.uleb128 0x16
	.uleb128 0x2d
	.byte	0x75
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x75
	.sleb128 0
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x74
	.sleb128 8
	.byte	0xf6
	.byte	0x4
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x1c
	.byte	0x9f
	.quad	.LVL58-.Ltext0
	.quad	.LVL59-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	0
	.quad	0
.LLST28:
	.quad	.LVL53-.Ltext0
	.quad	.LVL59-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.quad	.LBB148-.Ltext0
	.quad	.LBE148-.Ltext0
	.quad	.LBB151-.Ltext0
	.quad	.LBE151-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB152-.Ltext0
	.quad	.LBE152-.Ltext0
	.quad	.LBB157-.Ltext0
	.quad	.LBE157-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB160-.Ltext0
	.quad	.LBE160-.Ltext0
	.quad	.LBB166-.Ltext0
	.quad	.LBE166-.Ltext0
	.quad	.LBB172-.Ltext0
	.quad	.LBE172-.Ltext0
	.quad	.LBB174-.Ltext0
	.quad	.LBE174-.Ltext0
	.quad	.LBB176-.Ltext0
	.quad	.LBE176-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB167-.Ltext0
	.quad	.LBE167-.Ltext0
	.quad	.LBB173-.Ltext0
	.quad	.LBE173-.Ltext0
	.quad	.LBB175-.Ltext0
	.quad	.LBE175-.Ltext0
	.quad	.LBB177-.Ltext0
	.quad	.LBE177-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB184-.Ltext0
	.quad	.LBE184-.Ltext0
	.quad	.LBB190-.Ltext0
	.quad	.LBE190-.Ltext0
	.quad	.LBB191-.Ltext0
	.quad	.LBE191-.Ltext0
	.quad	.LBB192-.Ltext0
	.quad	.LBE192-.Ltext0
	.quad	.LBB193-.Ltext0
	.quad	.LBE193-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB194-.Ltext0
	.quad	.LBE194-.Ltext0
	.quad	.LBB226-.Ltext0
	.quad	.LBE226-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB197-.Ltext0
	.quad	.LBE197-.Ltext0
	.quad	.LBB211-.Ltext0
	.quad	.LBE211-.Ltext0
	.quad	.LBB214-.Ltext0
	.quad	.LBE214-.Ltext0
	.quad	.LBB227-.Ltext0
	.quad	.LBE227-.Ltext0
	.quad	.LBB229-.Ltext0
	.quad	.LBE229-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB203-.Ltext0
	.quad	.LBE203-.Ltext0
	.quad	.LBB212-.Ltext0
	.quad	.LBE212-.Ltext0
	.quad	.LBB213-.Ltext0
	.quad	.LBE213-.Ltext0
	.quad	.LBB220-.Ltext0
	.quad	.LBE220-.Ltext0
	.quad	.LBB222-.Ltext0
	.quad	.LBE222-.Ltext0
	.quad	.LBB224-.Ltext0
	.quad	.LBE224-.Ltext0
	.quad	.LBB228-.Ltext0
	.quad	.LBE228-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB215-.Ltext0
	.quad	.LBE215-.Ltext0
	.quad	.LBB221-.Ltext0
	.quad	.LBE221-.Ltext0
	.quad	.LBB223-.Ltext0
	.quad	.LBE223-.Ltext0
	.quad	.LBB225-.Ltext0
	.quad	.LBE225-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB232-.Ltext0
	.quad	.LBE232-.Ltext0
	.quad	.LBB239-.Ltext0
	.quad	.LBE239-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB235-.Ltext0
	.quad	.LBE235-.Ltext0
	.quad	.LBB240-.Ltext0
	.quad	.LBE240-.Ltext0
	.quad	.LBB241-.Ltext0
	.quad	.LBE241-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB242-.Ltext0
	.quad	.LBE242-.Ltext0
	.quad	.LBB248-.Ltext0
	.quad	.LBE248-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB245-.Ltext0
	.quad	.LBE245-.Ltext0
	.quad	.LBB249-.Ltext0
	.quad	.LBE249-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB250-.Ltext0
	.quad	.LBE250-.Ltext0
	.quad	.LBB255-.Ltext0
	.quad	.LBE255-.Ltext0
	.quad	.LBB260-.Ltext0
	.quad	.LBE260-.Ltext0
	.quad	.LBB262-.Ltext0
	.quad	.LBE262-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB256-.Ltext0
	.quad	.LBE256-.Ltext0
	.quad	.LBB261-.Ltext0
	.quad	.LBE261-.Ltext0
	.quad	.LBB263-.Ltext0
	.quad	.LBE263-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB264-.Ltext0
	.quad	.LBE264-.Ltext0
	.quad	.LBB289-.Ltext0
	.quad	.LBE289-.Ltext0
	.quad	.LBB296-.Ltext0
	.quad	.LBE296-.Ltext0
	.quad	.LBB298-.Ltext0
	.quad	.LBE298-.Ltext0
	.quad	.LBB300-.Ltext0
	.quad	.LBE300-.Ltext0
	.quad	.LBB302-.Ltext0
	.quad	.LBE302-.Ltext0
	.quad	.LBB304-.Ltext0
	.quad	.LBE304-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB272-.Ltext0
	.quad	.LBE272-.Ltext0
	.quad	.LBB291-.Ltext0
	.quad	.LBE291-.Ltext0
	.quad	.LBB293-.Ltext0
	.quad	.LBE293-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB276-.Ltext0
	.quad	.LBE276-.Ltext0
	.quad	.LBB294-.Ltext0
	.quad	.LBE294-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB279-.Ltext0
	.quad	.LBE279-.Ltext0
	.quad	.LBB290-.Ltext0
	.quad	.LBE290-.Ltext0
	.quad	.LBB292-.Ltext0
	.quad	.LBE292-.Ltext0
	.quad	.LBB295-.Ltext0
	.quad	.LBE295-.Ltext0
	.quad	.LBB297-.Ltext0
	.quad	.LBE297-.Ltext0
	.quad	.LBB299-.Ltext0
	.quad	.LBE299-.Ltext0
	.quad	.LBB301-.Ltext0
	.quad	.LBE301-.Ltext0
	.quad	.LBB303-.Ltext0
	.quad	.LBE303-.Ltext0
	.quad	.LBB305-.Ltext0
	.quad	.LBE305-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB308-.Ltext0
	.quad	.LBE308-.Ltext0
	.quad	.LBB315-.Ltext0
	.quad	.LBE315-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB311-.Ltext0
	.quad	.LBE311-.Ltext0
	.quad	.LBB316-.Ltext0
	.quad	.LBE316-.Ltext0
	.quad	.LBB317-.Ltext0
	.quad	.LBE317-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB318-.Ltext0
	.quad	.LBE318-.Ltext0
	.quad	.LBB324-.Ltext0
	.quad	.LBE324-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB321-.Ltext0
	.quad	.LBE321-.Ltext0
	.quad	.LBB325-.Ltext0
	.quad	.LBE325-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB326-.Ltext0
	.quad	.LBE326-.Ltext0
	.quad	.LBB331-.Ltext0
	.quad	.LBE331-.Ltext0
	.quad	.LBB336-.Ltext0
	.quad	.LBE336-.Ltext0
	.quad	.LBB338-.Ltext0
	.quad	.LBE338-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB332-.Ltext0
	.quad	.LBE332-.Ltext0
	.quad	.LBB337-.Ltext0
	.quad	.LBE337-.Ltext0
	.quad	.LBB339-.Ltext0
	.quad	.LBE339-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB364-.Ltext0
	.quad	.LBE364-.Ltext0
	.quad	.LBB383-.Ltext0
	.quad	.LBE383-.Ltext0
	.quad	.LBB406-.Ltext0
	.quad	.LBE406-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB368-.Ltext0
	.quad	.LBE368-.Ltext0
	.quad	.LBB384-.Ltext0
	.quad	.LBE384-.Ltext0
	.quad	.LBB388-.Ltext0
	.quad	.LBE388-.Ltext0
	.quad	.LBB407-.Ltext0
	.quad	.LBE407-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB370-.Ltext0
	.quad	.LBE370-.Ltext0
	.quad	.LBB373-.Ltext0
	.quad	.LBE373-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB374-.Ltext0
	.quad	.LBE374-.Ltext0
	.quad	.LBB378-.Ltext0
	.quad	.LBE378-.Ltext0
	.quad	.LBB379-.Ltext0
	.quad	.LBE379-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB385-.Ltext0
	.quad	.LBE385-.Ltext0
	.quad	.LBB389-.Ltext0
	.quad	.LBE389-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB390-.Ltext0
	.quad	.LBE390-.Ltext0
	.quad	.LBB394-.Ltext0
	.quad	.LBE394-.Ltext0
	.quad	.LBB398-.Ltext0
	.quad	.LBE398-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB395-.Ltext0
	.quad	.LBE395-.Ltext0
	.quad	.LBB399-.Ltext0
	.quad	.LBE399-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB400-.Ltext0
	.quad	.LBE400-.Ltext0
	.quad	.LBB404-.Ltext0
	.quad	.LBE404-.Ltext0
	.quad	.LBB405-.Ltext0
	.quad	.LBE405-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB408-.Ltext0
	.quad	.LBE408-.Ltext0
	.quad	.LBB412-.Ltext0
	.quad	.LBE412-.Ltext0
	.quad	.LBB416-.Ltext0
	.quad	.LBE416-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB413-.Ltext0
	.quad	.LBE413-.Ltext0
	.quad	.LBB417-.Ltext0
	.quad	.LBE417-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB428-.Ltext0
	.quad	.LBE428-.Ltext0
	.quad	.LBB435-.Ltext0
	.quad	.LBE435-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB431-.Ltext0
	.quad	.LBE431-.Ltext0
	.quad	.LBB436-.Ltext0
	.quad	.LBE436-.Ltext0
	.quad	.LBB441-.Ltext0
	.quad	.LBE441-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF113:
	.string	"vec3div"
.LASF46:
	.string	"_shortbuf"
.LASF92:
	.string	"vec3equiv"
.LASF99:
	.string	"from"
.LASF129:
	.string	"_IO_lock_t"
.LASF65:
	.string	"stderr"
.LASF35:
	.string	"_IO_buf_end"
.LASF17:
	.string	"_POSIX_"
.LASF20:
	.string	"signgam"
.LASF33:
	.string	"_IO_write_end"
.LASF3:
	.string	"unsigned int"
.LASF120:
	.string	"vec3construct"
.LASF19:
	.string	"_LIB_VERSION_TYPE"
.LASF78:
	.string	"vec3attenuation"
.LASF27:
	.string	"_flags"
.LASF111:
	.string	"vec3mulScalar"
.LASF39:
	.string	"_markers"
.LASF12:
	.string	"Mat4"
.LASF90:
	.string	"raydir"
.LASF119:
	.string	"vec3set"
.LASF95:
	.string	"vec3copySub"
.LASF80:
	.string	"maxdist"
.LASF70:
	.string	"theta"
.LASF126:
	.string	"/home/user/projects/openGL/test/math"
.LASF15:
	.string	"_SVID_"
.LASF59:
	.string	"_pos"
.LASF64:
	.string	"stdout"
.LASF94:
	.string	"areOrthogonal"
.LASF38:
	.string	"_IO_save_end"
.LASF105:
	.string	"vec3mulMat4"
.LASF104:
	.string	"vec3normalVector"
.LASF0:
	.string	"float"
.LASF24:
	.string	"long long unsigned int"
.LASF18:
	.string	"_ISOC_"
.LASF67:
	.string	"sys_errlist"
.LASF37:
	.string	"_IO_backup_base"
.LASF81:
	.string	"vec3projectPoint"
.LASF48:
	.string	"_offset"
.LASF75:
	.string	"coeffs"
.LASF86:
	.string	"unitdir"
.LASF66:
	.string	"sys_nerr"
.LASF83:
	.string	"vectorAndPlaneIntersection"
.LASF41:
	.string	"_fileno"
.LASF106:
	.string	"vec3unitDirection"
.LASF22:
	.string	"size_t"
.LASF72:
	.string	"vec3computeLineCoefficients"
.LASF100:
	.string	"vec3length"
.LASF30:
	.string	"_IO_read_base"
.LASF77:
	.string	"_Bool"
.LASF14:
	.string	"_IEEE_"
.LASF63:
	.string	"stdin"
.LASF57:
	.string	"_next"
.LASF85:
	.string	"plane_normal"
.LASF114:
	.string	"vec3mul"
.LASF98:
	.string	"vec3distance"
.LASF121:
	.string	"vec3copy"
.LASF89:
	.string	"ray_and_plane_intersection"
.LASF25:
	.string	"matrix44f32_t"
.LASF10:
	.string	"char"
.LASF54:
	.string	"_mode"
.LASF56:
	.string	"_IO_marker"
.LASF97:
	.string	"vec3copyMulScalar"
.LASF28:
	.string	"_IO_read_ptr"
.LASF21:
	.string	"_LIB_VERSION"
.LASF11:
	.string	"data"
.LASF101:
	.string	"vec3dot"
.LASF117:
	.string	"vec3add"
.LASF31:
	.string	"_IO_write_base"
.LASF60:
	.string	"_IO_2_1_stdin_"
.LASF23:
	.string	"long long int"
.LASF122:
	.string	"printf"
.LASF61:
	.string	"_IO_2_1_stdout_"
.LASF36:
	.string	"_IO_save_base"
.LASF76:
	.string	"pointInSphere"
.LASF93:
	.string	"vec3copyCross"
.LASF115:
	.string	"vec3negate"
.LASF79:
	.string	"dist"
.LASF102:
	.string	"vec3cross"
.LASF49:
	.string	"__pad1"
.LASF50:
	.string	"__pad2"
.LASF51:
	.string	"__pad3"
.LASF52:
	.string	"__pad4"
.LASF53:
	.string	"__pad5"
.LASF118:
	.string	"vec3init"
.LASF71:
	.string	"vec3printf"
.LASF45:
	.string	"_vtable_offset"
.LASF73:
	.string	"rtp_to_xyz"
.LASF91:
	.string	"ray_plane_intersection"
.LASF131:
	.string	"sincosf"
.LASF82:
	.string	"norm"
.LASF29:
	.string	"_IO_read_end"
.LASF109:
	.string	"vec3divScalar"
.LASF127:
	.string	"vec3f32_t"
.LASF6:
	.string	"short int"
.LASF7:
	.string	"long int"
.LASF132:
	.string	"__builtin_sincosf"
.LASF87:
	.string	"diff"
.LASF125:
	.string	"src/Vec3.c"
.LASF130:
	.string	"_IO_FILE_plus"
.LASF116:
	.string	"vec3sub"
.LASF68:
	.string	"name"
.LASF88:
	.string	"point_of_intersection"
.LASF107:
	.string	"vec3normalize"
.LASF47:
	.string	"_lock"
.LASF4:
	.string	"long unsigned int"
.LASF128:
	.string	"Vec3"
.LASF43:
	.string	"_old_offset"
.LASF26:
	.string	"_IO_FILE"
.LASF108:
	.string	"rlen"
.LASF69:
	.string	"radius"
.LASF124:
	.string	"GNU C99 7.2.0 -masm=intel -mtune=generic -march=x86-64 -g -O3 -std=gnu99"
.LASF1:
	.string	"unsigned char"
.LASF58:
	.string	"_sbuf"
.LASF32:
	.string	"_IO_write_ptr"
.LASF123:
	.string	"sqrtf"
.LASF110:
	.string	"scalar"
.LASF8:
	.string	"__off_t"
.LASF5:
	.string	"signed char"
.LASF96:
	.string	"vec3copyAdd"
.LASF2:
	.string	"short unsigned int"
.LASF13:
	.string	"double"
.LASF74:
	.string	"vec3computeLineDistance"
.LASF40:
	.string	"_chain"
.LASF42:
	.string	"_flags2"
.LASF44:
	.string	"_cur_column"
.LASF103:
	.string	"dest"
.LASF16:
	.string	"_XOPEN_"
.LASF62:
	.string	"_IO_2_1_stderr_"
.LASF112:
	.string	"vec3addScalar"
.LASF9:
	.string	"__off64_t"
.LASF55:
	.string	"_unused2"
.LASF34:
	.string	"_IO_buf_base"
.LASF84:
	.string	"point_on_plane"
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
