	.file	"Mat4.c"
	.intel_syntax noprefix
# GNU C99 (GCC) version 7.2.0 (x86_64-pc-linux-gnu)
#	compiled by GNU C version 7.2.0, GMP version 6.1.2, MPFR version 3.1.5-p2, MPC version 1.0.3, isl version isl-0.18-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -I ./inc src/Mat4.c -masm=intel -mtune=generic
# -march=x86-64 -auxbase-strip mat4.s -g -O3 -Wall -Wshadow -Wextra -Werror
# -Wundef -Wpointer-arith -Wcast-align -Wwrite-strings -Wconversion
# -std=gnu99 -fverbose-asm
# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
# -falign-labels -fasynchronous-unwind-tables -fauto-inc-dec
# -fbranch-count-reg -fcaller-saves -fchkp-check-incomplete-type
# -fchkp-check-read -fchkp-check-write -fchkp-instrument-calls
# -fchkp-narrow-bounds -fchkp-optimize -fchkp-store-bounds
# -fchkp-use-static-bounds -fchkp-use-static-const-bounds
# -fchkp-use-wrappers -fcode-hoisting -fcombine-stack-adjustments -fcommon
# -fcompare-elim -fcprop-registers -fcrossjumping -fcse-follow-jumps
# -fdefer-pop -fdelete-null-pointer-checks -fdevirtualize
# -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexpensive-optimizations
# -fforward-propagate -ffp-int-builtin-inexact -ffunction-cse -fgcse
# -fgcse-after-reload -fgcse-lm -fgnu-runtime -fgnu-unique
# -fguess-branch-probability -fhoist-adjacent-loads -fident -fif-conversion
# -fif-conversion2 -findirect-inlining -finline -finline-atomics
# -finline-functions -finline-functions-called-once
# -finline-small-functions -fipa-bit-cp -fipa-cp -fipa-cp-clone -fipa-icf
# -fipa-icf-functions -fipa-icf-variables -fipa-profile -fipa-pure-const
# -fipa-ra -fipa-reference -fipa-sra -fipa-vrp -fira-hoist-pressure
# -fira-share-save-slots -fira-share-spill-slots
# -fisolate-erroneous-paths-dereference -fivopts -fkeep-static-consts
# -fleading-underscore -flifetime-dse -flra-remat -flto-odr-type-merging
# -fmath-errno -fmerge-constants -fmerge-debug-strings
# -fmove-loop-invariants -fomit-frame-pointer -foptimize-sibling-calls
# -foptimize-strlen -fpartial-inlining -fpeel-loops -fpeephole -fpeephole2
# -fplt -fpredictive-commoning -fprefetch-loop-arrays -free
# -freg-struct-return -freorder-blocks -freorder-functions
# -frerun-cse-after-loop -fsched-critical-path-heuristic
# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
# -fschedule-insns2 -fsemantic-interposition -fshow-column -fshrink-wrap
# -fshrink-wrap-separate -fsigned-zeros -fsplit-ivs-in-unroller
# -fsplit-loops -fsplit-paths -fsplit-wide-types -fssa-backprop
# -fssa-phiopt -fstack-protector-strong -fstdarg-opt -fstore-merging
# -fstrict-aliasing -fstrict-overflow -fstrict-volatile-bitfields
# -fsync-libcalls -fthread-jumps -ftoplevel-reorder -ftrapping-math
# -ftree-bit-ccp -ftree-builtin-call-dce -ftree-ccp -ftree-ch
# -ftree-coalesce-vars -ftree-copy-prop -ftree-cselim -ftree-dce
# -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
# -ftree-loop-distribute-patterns -ftree-loop-if-convert -ftree-loop-im
# -ftree-loop-ivcanon -ftree-loop-optimize -ftree-loop-vectorize
# -ftree-parallelize-loops= -ftree-partial-pre -ftree-phiprop -ftree-pre
# -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink
# -ftree-slp-vectorize -ftree-slsr -ftree-sra -ftree-switch-conversion
# -ftree-tail-merge -ftree-ter -ftree-vrp -funit-at-a-time -funswitch-loops
# -funwind-tables -fvar-tracking -fvar-tracking-assignments -fverbose-asm
# -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper

	.text
.Ltext0:
	.p2align 4,,15
	.globl	newMat4
	.type	newMat4, @function
newMat4:
.LFB27:
	.file 1 "src/Mat4.c"
	.loc 1 23 0
	.cfi_startproc
	sub	rsp, 8	#,
	.cfi_def_cfa_offset 16
# src/Mat4.c:24:     Mat4 *m = malloc(sizeof(Mat4));
	.loc 1 24 0
	mov	edi, 64	#,
	call	malloc@PLT	#
.LVL0:
# src/Mat4.c:25:     MAT4SET_IDENTITY(m);
	.loc 1 25 0
	movss	xmm0, DWORD PTR .LC0[rip]	# tmp89,
	movups	XMMWORD PTR [rax], xmm0	# MEM[(float *)m_3], tmp89
	movaps	xmm0, XMMWORD PTR .LC1[rip]	# tmp90,
	movups	XMMWORD PTR 16[rax], xmm0	# MEM[(float *)m_3 + 16B], tmp90
	movaps	xmm0, XMMWORD PTR .LC2[rip]	# tmp91,
	movups	XMMWORD PTR 32[rax], xmm0	# MEM[(float *)m_3 + 32B], tmp91
	movaps	xmm0, XMMWORD PTR .LC3[rip]	# tmp92,
	movups	XMMWORD PTR 48[rax], xmm0	# MEM[(float *)m_3 + 48B], tmp92
# src/Mat4.c:27: }
	.loc 1 27 0
	add	rsp, 8	#,
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE27:
	.size	newMat4, .-newMat4
	.p2align 4,,15
	.globl	destroyMat4
	.type	destroyMat4, @function
destroyMat4:
.LFB28:
	.loc 1 30 0
	.cfi_startproc
.LVL1:
# src/Mat4.c:31:     if (m)
	.loc 1 31 0
	test	rdi, rdi	# m
	je	.L4	#,
# src/Mat4.c:32:         free(m);
	.loc 1 32 0
	jmp	free@PLT	#
.LVL2:
	.p2align 4,,10
	.p2align 3
.L4:
# src/Mat4.c:33: }
	.loc 1 33 0
	rep ret
	.cfi_endproc
.LFE28:
	.size	destroyMat4, .-destroyMat4
	.p2align 4,,15
	.globl	setMat4
	.type	setMat4, @function
setMat4:
.LFB29:
	.loc 1 36 0
	.cfi_startproc
.LVL3:
# src/Mat4.c:37:     memcpy(dest, src, SIZEOFMAT4);
	.loc 1 37 0
	movdqu	xmm0, XMMWORD PTR [rsi]	# MEM[(void *)src_3(D)], MEM[(void *)src_3(D)]
# src/Mat4.c:36: {
	.loc 1 36 0
	mov	rax, rdi	# dest, dest
# src/Mat4.c:37:     memcpy(dest, src, SIZEOFMAT4);
	.loc 1 37 0
	movups	XMMWORD PTR [rdi], xmm0	# MEM[(void *)dest_2(D)], MEM[(void *)src_3(D)]
	movdqu	xmm0, XMMWORD PTR 16[rsi]	# MEM[(void *)src_3(D)], MEM[(void *)src_3(D)]
	movups	XMMWORD PTR 16[rdi], xmm0	# MEM[(void *)dest_2(D)], MEM[(void *)src_3(D)]
	movdqu	xmm0, XMMWORD PTR 32[rsi]	# MEM[(void *)src_3(D)], MEM[(void *)src_3(D)]
	movups	XMMWORD PTR 32[rdi], xmm0	# MEM[(void *)dest_2(D)], MEM[(void *)src_3(D)]
	movdqu	xmm0, XMMWORD PTR 48[rsi]	# MEM[(void *)src_3(D)], MEM[(void *)src_3(D)]
	movups	XMMWORD PTR 48[rdi], xmm0	# MEM[(void *)dest_2(D)], MEM[(void *)src_3(D)]
# src/Mat4.c:39: }
	.loc 1 39 0
	ret
	.cfi_endproc
.LFE29:
	.size	setMat4, .-setMat4
	.p2align 4,,15
	.globl	setIdentityMat4
	.type	setIdentityMat4, @function
setIdentityMat4:
.LFB30:
	.loc 1 42 0
	.cfi_startproc
.LVL4:
# src/Mat4.c:43:     MAT4SET_IDENTITY(mat);
	.loc 1 43 0
	movss	xmm0, DWORD PTR .LC0[rip]	# tmp89,
# src/Mat4.c:42: {
	.loc 1 42 0
	mov	rax, rdi	# mat, mat
# src/Mat4.c:43:     MAT4SET_IDENTITY(mat);
	.loc 1 43 0
	movups	XMMWORD PTR [rdi], xmm0	# MEM[(float *)mat_2(D)], tmp89
	movaps	xmm0, XMMWORD PTR .LC1[rip]	# tmp90,
	movups	XMMWORD PTR 16[rdi], xmm0	# MEM[(float *)mat_2(D) + 16B], tmp90
	movaps	xmm0, XMMWORD PTR .LC2[rip]	# tmp91,
	movups	XMMWORD PTR 32[rdi], xmm0	# MEM[(float *)mat_2(D) + 32B], tmp91
	movaps	xmm0, XMMWORD PTR .LC3[rip]	# tmp92,
	movups	XMMWORD PTR 48[rdi], xmm0	# MEM[(float *)mat_2(D) + 48B], tmp92
# src/Mat4.c:45: }
	.loc 1 45 0
	ret
	.cfi_endproc
.LFE30:
	.size	setIdentityMat4, .-setIdentityMat4
	.p2align 4,,15
	.globl	setTranslationMat4
	.type	setTranslationMat4, @function
setTranslationMat4:
.LFB31:
	.loc 1 48 0
	.cfi_startproc
.LVL5:
# src/Mat4.c:49:     MAT4SET(m, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, v->x, v->y, v->z, 1.0f);
	.loc 1 49 0
	movss	xmm0, DWORD PTR .LC0[rip]	# tmp93,
# src/Mat4.c:48: {
	.loc 1 48 0
	mov	rax, rdi	# m, m
# src/Mat4.c:49:     MAT4SET(m, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, v->x, v->y, v->z, 1.0f);
	.loc 1 49 0
	movups	XMMWORD PTR [rdi], xmm0	# MEM[(float *)m_5(D)], tmp93
	movaps	xmm0, XMMWORD PTR .LC1[rip]	# tmp94,
	movups	XMMWORD PTR 16[rdi], xmm0	# MEM[(float *)m_5(D) + 16B], tmp94
	movaps	xmm0, XMMWORD PTR .LC2[rip]	# tmp95,
	movups	XMMWORD PTR 32[rdi], xmm0	# MEM[(float *)m_5(D) + 32B], tmp95
	movss	xmm0, DWORD PTR [rsi]	# v_18(D)->x, v_18(D)->x
	movss	DWORD PTR 48[rdi], xmm0	# m_5(D)->data, v_18(D)->x
	movss	xmm0, DWORD PTR 4[rsi]	# v_18(D)->y, v_18(D)->y
	movss	DWORD PTR 52[rdi], xmm0	# m_5(D)->data, v_18(D)->y
	movss	xmm0, DWORD PTR 8[rsi]	# v_18(D)->z, v_18(D)->z
	mov	DWORD PTR 60[rdi], 0x3f800000	# m_5(D)->data,
	movss	DWORD PTR 56[rdi], xmm0	# m_5(D)->data, v_18(D)->z
# src/Mat4.c:51: }
	.loc 1 51 0
	ret
	.cfi_endproc
.LFE31:
	.size	setTranslationMat4, .-setTranslationMat4
	.p2align 4,,15
	.globl	setScaledMat4
	.type	setScaledMat4, @function
setScaledMat4:
.LFB32:
	.loc 1 54 0
	.cfi_startproc
.LVL6:
# src/Mat4.c:55:     MAT4SET(mat, v->x, 0.0f, 0.0f, 0.0f, 0.0f, v->y, 0.0f, 0.0f, 0.0f, 0.0f, v->z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	.loc 1 55 0
	movss	xmm0, DWORD PTR [rsi]	# v_5(D)->x, v_5(D)->x
	mov	QWORD PTR 4[rdi], 0	# MEM[(float *)mat_6(D) + 4B],
	mov	QWORD PTR 12[rdi], 0	# MEM[(float *)mat_6(D) + 12B],
	movss	DWORD PTR [rdi], xmm0	# mat_6(D)->data, v_5(D)->x
# src/Mat4.c:54: {
	.loc 1 54 0
	mov	rax, rdi	# mat, mat
# src/Mat4.c:55:     MAT4SET(mat, v->x, 0.0f, 0.0f, 0.0f, 0.0f, v->y, 0.0f, 0.0f, 0.0f, 0.0f, v->z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
	.loc 1 55 0
	movss	xmm0, DWORD PTR 4[rsi]	# v_5(D)->y, v_5(D)->y
	mov	QWORD PTR 24[rdi], 0	# MEM[(float *)mat_6(D) + 24B],
	mov	QWORD PTR 32[rdi], 0	# MEM[(float *)mat_6(D) + 32B],
	movss	DWORD PTR 20[rdi], xmm0	# mat_6(D)->data, v_5(D)->y
	movss	xmm0, DWORD PTR 8[rsi]	# v_5(D)->z, v_5(D)->z
	mov	QWORD PTR 44[rdi], 0	# MEM[(float *)mat_6(D) + 44B],
	movss	DWORD PTR 40[rdi], xmm0	# mat_6(D)->data, v_5(D)->z
	mov	QWORD PTR 52[rdi], 0	# MEM[(float *)mat_6(D) + 52B],
	mov	DWORD PTR 60[rdi], 1065353216	# MEM[(float *)mat_6(D) + 60B],
# src/Mat4.c:57: }
	.loc 1 57 0
	ret
	.cfi_endproc
.LFE32:
	.size	setScaledMat4, .-setScaledMat4
	.p2align 4,,15
	.globl	setRotationMat4
	.type	setRotationMat4, @function
setRotationMat4:
.LFB33:
	.loc 1 60 0
	.cfi_startproc
.LVL7:
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbp, rsi	# v, v
	mov	rbx, rdi	# mat, mat
	sub	rsp, 24	#,
	.cfi_def_cfa_offset 48
# src/Mat4.c:61:     const float rad = TO_RAD(degrees);
	.loc 1 61 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp127,
.LVL8:
	lea	rdi, 12[rsp]	# tmp125,
.LVL9:
	lea	rsi, 8[rsp]	# tmp126,
.LVL10:
	divss	xmm0, DWORD PTR .LC6[rip]	# rad,
	call	sincosf@PLT	#
.LVL11:
# src/Mat4.c:66:     const float nc = 1.0f - c;
	.loc 1 66 0
	movss	xmm0, DWORD PTR .LC4[rip]	# tmp131,
# src/Mat4.c:97: }
	.loc 1 97 0
	mov	rax, rbx	#, mat
# src/Mat4.c:68:     const float ys = v->y * s;
	.loc 1 68 0
	movss	xmm1, DWORD PTR 4[rbp]	# _3, v_26(D)->y
# src/Mat4.c:66:     const float nc = 1.0f - c;
	.loc 1 66 0
	movaps	xmm3, xmm0	# tmp131, tmp131
# src/Mat4.c:67:     const float zs = v->z * s;
	.loc 1 67 0
	movss	xmm0, DWORD PTR 8[rbp]	# _2, v_26(D)->z
	movaps	xmm10, xmm0	# zs, _2
# src/Mat4.c:68:     const float ys = v->y * s;
	.loc 1 68 0
	movaps	xmm8, xmm1	# ys, _3
# src/Mat4.c:70:     const float xy = v->x * v->y;
	.loc 1 70 0
	movaps	xmm5, xmm1	# xy, _3
# src/Mat4.c:71:     const float xz = v->x * v->z;
	.loc 1 71 0
	movaps	xmm9, xmm0	# xz, _2
# src/Mat4.c:69:     const float xs = v->x * s;
	.loc 1 69 0
	movss	xmm2, DWORD PTR 0[rbp]	# _4, v_26(D)->x
# src/Mat4.c:72:     const float yz = v->y * v->z;
	.loc 1 72 0
	movaps	xmm4, xmm0	# yz, _2
	movss	xmm6, DWORD PTR 8[rsp]	# sincostmp_54,
# src/Mat4.c:70:     const float xy = v->x * v->y;
	.loc 1 70 0
	mulss	xmm5, xmm2	# xy, _4
	movss	xmm7, DWORD PTR 12[rsp]	# sincostmp_54,
.LVL12:
# src/Mat4.c:66:     const float nc = 1.0f - c;
	.loc 1 66 0
	subss	xmm3, xmm6	# tmp131, sincostmp_54
.LVL13:
# src/Mat4.c:67:     const float zs = v->z * s;
	.loc 1 67 0
	mulss	xmm10, xmm7	# zs, sincostmp_54
.LVL14:
# src/Mat4.c:80:     mat->data[ 3] = 0.0f;
	.loc 1 80 0
	mov	DWORD PTR 12[rbx], 0x00000000	# mat_36(D)->data,
# src/Mat4.c:85:     mat->data[ 7] = 0.0f;
	.loc 1 85 0
	mov	DWORD PTR 28[rbx], 0x00000000	# mat_36(D)->data,
# src/Mat4.c:68:     const float ys = v->y * s;
	.loc 1 68 0
	mulss	xmm8, xmm7	# ys, sincostmp_54
.LVL15:
# src/Mat4.c:90:     mat->data[11] = 0.0f;
	.loc 1 90 0
	mov	QWORD PTR 44[rbx], 0	# MEM[(float *)mat_36(D) + 44B],
# src/Mat4.c:92:     mat->data[12] = 0.0f;
	.loc 1 92 0
	mov	QWORD PTR 52[rbx], 0	# MEM[(float *)mat_36(D) + 52B],
# src/Mat4.c:69:     const float xs = v->x * s;
	.loc 1 69 0
	mulss	xmm7, xmm2	# xs, _4
.LVL16:
# src/Mat4.c:94:     mat->data[14] = 0.0f;
	.loc 1 94 0
	mov	DWORD PTR 60[rbx], 1065353216	# MEM[(float *)mat_36(D) + 60B],
# src/Mat4.c:71:     const float xz = v->x * v->z;
	.loc 1 71 0
	mulss	xmm9, xmm2	# xz, _4
.LVL17:
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	mulss	xmm2, xmm2	# tmp135, _4
# src/Mat4.c:72:     const float yz = v->y * v->z;
	.loc 1 72 0
	mulss	xmm4, xmm1	# yz, _3
.LVL18:
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	mulss	xmm1, xmm1	# tmp142, _3
# src/Mat4.c:73:     const float xync = xy * nc;
	.loc 1 73 0
	mulss	xmm5, xmm3	# xync, nc
.LVL19:
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	mulss	xmm2, xmm3	# tmp136, nc
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	mulss	xmm0, xmm0	# tmp149, _2
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	mulss	xmm1, xmm3	# tmp143, nc
# src/Mat4.c:74:     const float xznc = xz * nc;
	.loc 1 74 0
	mulss	xmm9, xmm3	# xznc, nc
.LVL20:
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	addss	xmm2, xmm6	# tmp137, sincostmp_54
# src/Mat4.c:75:     const float yznc = yz * nc;
	.loc 1 75 0
	mulss	xmm4, xmm3	# yznc, nc
.LVL21:
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	mulss	xmm0, xmm3	# tmp150, nc
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	addss	xmm1, xmm6	# tmp144, sincostmp_54
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	movss	DWORD PTR [rbx], xmm2	# mat_36(D)->data, tmp137
# src/Mat4.c:78:     mat->data[ 1] = xync + zs;
	.loc 1 78 0
	movaps	xmm2, xmm10	# tmp138, zs
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	addss	xmm0, xmm6	# tmp151, sincostmp_54
# src/Mat4.c:78:     mat->data[ 1] = xync + zs;
	.loc 1 78 0
	addss	xmm2, xmm5	# tmp138, xync
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	movss	DWORD PTR 20[rbx], xmm1	# mat_36(D)->data, tmp144
# src/Mat4.c:84:     mat->data[ 6] = yznc + xs;
	.loc 1 84 0
	movaps	xmm1, xmm7	# tmp145, xs
# src/Mat4.c:82:     mat->data[ 4] = xync - zs;
	.loc 1 82 0
	subss	xmm5, xmm10	# tmp141, zs
.LVL22:
# src/Mat4.c:84:     mat->data[ 6] = yznc + xs;
	.loc 1 84 0
	addss	xmm1, xmm4	# tmp145, yznc
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	movss	DWORD PTR 40[rbx], xmm0	# mat_36(D)->data, tmp151
# src/Mat4.c:78:     mat->data[ 1] = xync + zs;
	.loc 1 78 0
	movss	DWORD PTR 4[rbx], xmm2	# mat_36(D)->data, tmp138
# src/Mat4.c:79:     mat->data[ 2] = xznc - ys;
	.loc 1 79 0
	movaps	xmm2, xmm9	# tmp139, xznc
# src/Mat4.c:88:     mat->data[ 9] = yznc - xs;
	.loc 1 88 0
	subss	xmm4, xmm7	# tmp148, xs
.LVL23:
# src/Mat4.c:79:     mat->data[ 2] = xznc - ys;
	.loc 1 79 0
	subss	xmm2, xmm8	# tmp139, ys
# src/Mat4.c:82:     mat->data[ 4] = xync - zs;
	.loc 1 82 0
	movss	DWORD PTR 16[rbx], xmm5	# mat_36(D)->data, tmp141
# src/Mat4.c:87:     mat->data[ 8] = xznc + ys;
	.loc 1 87 0
	addss	xmm8, xmm9	# tmp147, xznc
.LVL24:
# src/Mat4.c:84:     mat->data[ 6] = yznc + xs;
	.loc 1 84 0
	movss	DWORD PTR 24[rbx], xmm1	# mat_36(D)->data, tmp145
# src/Mat4.c:88:     mat->data[ 9] = yznc - xs;
	.loc 1 88 0
	movss	DWORD PTR 36[rbx], xmm4	# mat_36(D)->data, tmp148
# src/Mat4.c:79:     mat->data[ 2] = xznc - ys;
	.loc 1 79 0
	movss	DWORD PTR 8[rbx], xmm2	# mat_36(D)->data, tmp139
# src/Mat4.c:87:     mat->data[ 8] = xznc + ys;
	.loc 1 87 0
	movss	DWORD PTR 32[rbx], xmm8	# mat_36(D)->data, tmp147
# src/Mat4.c:97: }
	.loc 1 97 0
	add	rsp, 24	#,
	.cfi_def_cfa_offset 24
	pop	rbx	#
	.cfi_def_cfa_offset 16
.LVL25:
	pop	rbp	#
	.cfi_def_cfa_offset 8
.LVL26:
	ret
	.cfi_endproc
.LFE33:
	.size	setRotationMat4, .-setRotationMat4
	.p2align 4,,15
	.globl	setRotXMat4
	.type	setRotXMat4, @function
setRotXMat4:
.LFB34:
	.loc 1 100 0
	.cfi_startproc
.LVL27:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# mat, mat
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 32
# src/Mat4.c:102:     const float radians = TO_RAD(degrees);
	.loc 1 102 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp99,
.LVL28:
	lea	rdi, 12[rsp]	# tmp97,
.LVL29:
	lea	rsi, 8[rsp]	# tmp98,
	divss	xmm0, DWORD PTR .LC6[rip]	# radians,
	call	sincosf@PLT	#
.LVL30:
	movss	xmm0, DWORD PTR 12[rsp]	# sincostmp_25,
.LVL31:
# src/Mat4.c:105:     mat->data[ 0] = 1.0f;
	.loc 1 105 0
	movss	xmm2, DWORD PTR .LC0[rip]	# tmp103,
# src/Mat4.c:112:     mat->data[ 6] = s;
	.loc 1 112 0
	movss	DWORD PTR 24[rbx], xmm0	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:116:     mat->data[ 9] = -s;
	.loc 1 116 0
	xorps	xmm0, XMMWORD PTR .LC8[rip]	# tmp105,
.LVL32:
	movss	xmm1, DWORD PTR 8[rsp]	# sincostmp_25,
.LVL33:
# src/Mat4.c:110:     mat->data[ 4] = 0.0f;
	.loc 1 110 0
	mov	DWORD PTR 16[rbx], 0x00000000	# mat_8(D)->data,
# src/Mat4.c:105:     mat->data[ 0] = 1.0f;
	.loc 1 105 0
	movups	XMMWORD PTR [rbx], xmm2	# MEM[(float *)mat_8(D)], tmp103
# src/Mat4.c:113:     mat->data[ 7] = 0.0f;
	.loc 1 113 0
	mov	QWORD PTR 28[rbx], 0	# MEM[(float *)mat_8(D) + 28B],
# src/Mat4.c:118:     mat->data[11] = 0.0f;
	.loc 1 118 0
	mov	QWORD PTR 44[rbx], 0	# MEM[(float *)mat_8(D) + 44B],
# src/Mat4.c:125: }
	.loc 1 125 0
	mov	rax, rbx	#, mat
# src/Mat4.c:111:     mat->data[ 5] = c;
	.loc 1 111 0
	movss	DWORD PTR 20[rbx], xmm1	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:116:     mat->data[ 9] = -s;
	.loc 1 116 0
	movss	DWORD PTR 36[rbx], xmm0	# mat_8(D)->data, tmp105
# src/Mat4.c:117:     mat->data[10] = c;
	.loc 1 117 0
	movss	DWORD PTR 40[rbx], xmm1	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:120:     mat->data[12] = 0.0f;
	.loc 1 120 0
	mov	QWORD PTR 52[rbx], 0	# MEM[(float *)mat_8(D) + 52B],
# src/Mat4.c:122:     mat->data[14] = 0.0f;
	.loc 1 122 0
	mov	DWORD PTR 60[rbx], 1065353216	# MEM[(float *)mat_8(D) + 60B],
# src/Mat4.c:125: }
	.loc 1 125 0
	add	rsp, 16	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL34:
	ret
	.cfi_endproc
.LFE34:
	.size	setRotXMat4, .-setRotXMat4
	.p2align 4,,15
	.globl	setRotYMat4
	.type	setRotYMat4, @function
setRotYMat4:
.LFB35:
	.loc 1 128 0
	.cfi_startproc
.LVL35:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# mat, mat
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 32
# src/Mat4.c:130:     const float radians = TO_RAD(degrees);
	.loc 1 130 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp99,
.LVL36:
	lea	rdi, 12[rsp]	# tmp97,
.LVL37:
	lea	rsi, 8[rsp]	# tmp98,
	divss	xmm0, DWORD PTR .LC6[rip]	# radians,
	call	sincosf@PLT	#
.LVL38:
	movss	xmm1, DWORD PTR 12[rsp]	# sincostmp_25,
.LVL39:
# src/Mat4.c:134:     mat->data[ 1] = 0.0f;
	.loc 1 134 0
	mov	DWORD PTR 4[rbx], 0x00000000	# mat_8(D)->data,
# src/Mat4.c:135:     mat->data[ 2] = -s;
	.loc 1 135 0
	movaps	xmm2, xmm1	# tmp104, sincostmp_25
# src/Mat4.c:136:     mat->data[ 3] = 0.0f;
	.loc 1 136 0
	mov	QWORD PTR 12[rbx], 0	# MEM[(float *)mat_8(D) + 12B],
	movss	xmm0, DWORD PTR 8[rsp]	# sincostmp_25,
.LVL40:
# src/Mat4.c:138:     mat->data[ 4] = 0.0f;
	.loc 1 138 0
	mov	QWORD PTR 20[rbx], 1065353216	# MEM[(float *)mat_8(D) + 20B],
# src/Mat4.c:135:     mat->data[ 2] = -s;
	.loc 1 135 0
	xorps	xmm2, XMMWORD PTR .LC8[rip]	# tmp104,
# src/Mat4.c:133:     mat->data[ 0] = c;
	.loc 1 133 0
	movss	DWORD PTR [rbx], xmm0	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:140:     mat->data[ 6] = 0.0f;
	.loc 1 140 0
	mov	DWORD PTR 28[rbx], 0	# MEM[(float *)mat_8(D) + 28B],
# src/Mat4.c:143:     mat->data[ 8] = s;
	.loc 1 143 0
	movss	DWORD PTR 32[rbx], xmm1	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:144:     mat->data[ 9] = 0.0f;
	.loc 1 144 0
	mov	DWORD PTR 36[rbx], 0x00000000	# mat_8(D)->data,
# src/Mat4.c:145:     mat->data[10] = c;
	.loc 1 145 0
	movss	DWORD PTR 40[rbx], xmm0	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:146:     mat->data[11] = 0.0f;
	.loc 1 146 0
	mov	QWORD PTR 44[rbx], 0	# MEM[(float *)mat_8(D) + 44B],
# src/Mat4.c:153: }
	.loc 1 153 0
	mov	rax, rbx	#, mat
# src/Mat4.c:148:     mat->data[12] = 0.0f;
	.loc 1 148 0
	mov	QWORD PTR 52[rbx], 0	# MEM[(float *)mat_8(D) + 52B],
# src/Mat4.c:150:     mat->data[14] = 0.0f;
	.loc 1 150 0
	mov	DWORD PTR 60[rbx], 1065353216	# MEM[(float *)mat_8(D) + 60B],
# src/Mat4.c:135:     mat->data[ 2] = -s;
	.loc 1 135 0
	movss	DWORD PTR 8[rbx], xmm2	# mat_8(D)->data, tmp104
# src/Mat4.c:153: }
	.loc 1 153 0
	add	rsp, 16	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL41:
	ret
	.cfi_endproc
.LFE35:
	.size	setRotYMat4, .-setRotYMat4
	.p2align 4,,15
	.globl	setRotZMat4
	.type	setRotZMat4, @function
setRotZMat4:
.LFB36:
	.loc 1 156 0
	.cfi_startproc
.LVL42:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# mat, mat
	sub	rsp, 16	#,
	.cfi_def_cfa_offset 32
# src/Mat4.c:158:     const float radians = TO_RAD(degrees);
	.loc 1 158 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp99,
.LVL43:
	lea	rdi, 12[rsp]	# tmp97,
.LVL44:
	lea	rsi, 8[rsp]	# tmp98,
	divss	xmm0, DWORD PTR .LC6[rip]	# radians,
	call	sincosf@PLT	#
.LVL45:
	movss	xmm0, DWORD PTR 12[rsp]	# sincostmp_25,
.LVL46:
# src/Mat4.c:177:     mat->data[13] = 0.0f;
	.loc 1 177 0
	movabs	rax, 4575657221408423936	# tmp107,
# src/Mat4.c:162:     mat->data[ 1] = s;
	.loc 1 162 0
	movss	DWORD PTR 4[rbx], xmm0	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:166:     mat->data[ 4] = -s;
	.loc 1 166 0
	xorps	xmm0, XMMWORD PTR .LC8[rip]	# tmp103,
.LVL47:
	movss	xmm1, DWORD PTR 8[rsp]	# sincostmp_25,
.LVL48:
# src/Mat4.c:177:     mat->data[13] = 0.0f;
	.loc 1 177 0
	mov	QWORD PTR 56[rbx], rax	# MEM[(float *)mat_8(D) + 56B], tmp107
# src/Mat4.c:161:     mat->data[ 0] = c;
	.loc 1 161 0
	movss	DWORD PTR [rbx], xmm1	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:163:     mat->data[ 2] = 0.0f;
	.loc 1 163 0
	mov	QWORD PTR 8[rbx], 0	# MEM[(float *)mat_8(D) + 8B],
# src/Mat4.c:181: }
	.loc 1 181 0
	mov	rax, rbx	#, mat
# src/Mat4.c:167:     mat->data[ 5] = c;
	.loc 1 167 0
	movss	DWORD PTR 20[rbx], xmm1	# mat_8(D)->data, sincostmp_25
# src/Mat4.c:168:     mat->data[ 6] = 0.0f;
	.loc 1 168 0
	mov	QWORD PTR 24[rbx], 0	# MEM[(float *)mat_8(D) + 24B],
# src/Mat4.c:169:     mat->data[ 7] = 0.0f;
	.loc 1 169 0
	mov	QWORD PTR 32[rbx], 0	# MEM[(float *)mat_8(D) + 32B],
# src/Mat4.c:172:     mat->data[ 9] = 0.0f;
	.loc 1 172 0
	mov	QWORD PTR 40[rbx], 1065353216	# MEM[(float *)mat_8(D) + 40B],
# src/Mat4.c:166:     mat->data[ 4] = -s;
	.loc 1 166 0
	movss	DWORD PTR 16[rbx], xmm0	# mat_8(D)->data, tmp103
# src/Mat4.c:174:     mat->data[11] = 0.0f;
	.loc 1 174 0
	mov	QWORD PTR 48[rbx], 0	# MEM[(float *)mat_8(D) + 48B],
# src/Mat4.c:181: }
	.loc 1 181 0
	add	rsp, 16	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL49:
	ret
	.cfi_endproc
.LFE36:
	.size	setRotZMat4, .-setRotZMat4
	.p2align 4,,15
	.globl	mulMat4
	.type	mulMat4, @function
mulMat4:
.LFB37:
	.loc 1 184 0
	.cfi_startproc
.LVL50:
	sub	rsp, 104	#,
	.cfi_def_cfa_offset 112
	lea	r8, 32[rdi]	# _88,
	lea	r10, 48[rdi]	# _91,
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm0, XMMWORD PTR [rdi]	# MEM[(void *)dest_56(D)], MEM[(void *)dest_56(D)]
	lea	r9, 16[rdi]	# _100,
# src/Mat4.c:184: {
	.loc 1 184 0
	mov	rcx, QWORD PTR fs:40	# tmp552,
	mov	QWORD PTR 88[rsp], rcx	# D.4760, tmp552
	xor	ecx, ecx	# tmp552
.LVL51:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 16[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)dest_56(D)]
	lea	rcx, 64[rsi]	# _94,
# src/Mat4.c:184: {
	.loc 1 184 0
	mov	rax, rdi	# dest, dest
	cmp	r8, rcx	# _88, _94
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm0, XMMWORD PTR 16[rdi]	# MEM[(void *)dest_56(D)], MEM[(void *)dest_56(D)]
	setnb	dl	#, tmp373
	cmp	rsi, r10	# src, _91
	movaps	XMMWORD PTR 32[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)dest_56(D)]
	movdqu	xmm0, XMMWORD PTR 32[rdi]	# MEM[(void *)dest_56(D)], MEM[(void *)dest_56(D)]
	movaps	XMMWORD PTR 48[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)dest_56(D)]
	movdqu	xmm0, XMMWORD PTR 48[rdi]	# MEM[(void *)dest_56(D)], MEM[(void *)dest_56(D)]
	setnb	dil	#, tmp375
.LVL52:
	or	edx, edi	# tmp376, tmp375
	cmp	rax, rcx	# dest, _94
	setnb	dil	#, tmp378
	cmp	rsi, r9	# src, _100
	setnb	r11b	#, tmp380
	or	edi, r11d	# tmp381, tmp380
	and	edx, edi	# tmp382, tmp381
	cmp	rcx, r9	# _94, _100
	setbe	dil	#, tmp384
	cmp	rsi, r8	# src, _88
	setnb	r8b	#, tmp386
	or	edi, r8d	# tmp387, tmp386
	test	dl, dil	# tmp382, tmp387
	movaps	XMMWORD PTR 64[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)dest_56(D)]
.LVL53:
	je	.L19	#,
	lea	rdx, 64[rax]	# tmp389,
	cmp	rsi, rdx	# src, tmp389
	setnb	dil	#, tmp391
	cmp	r10, rcx	# _91, _94
	setnb	dl	#, tmp393
	or	dil, dl	# tmp391, tmp393
	je	.L19	#,
.LVL54:
	movss	xmm3, DWORD PTR 56[rsi]	# _291, MEM[(float *)src_55(D) + 56B]
	movss	DWORD PTR 8[rsp], xmm3	# %sfp, _291
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movss	xmm3, DWORD PTR [rsi]	# tmp395, MEM[(float *)src_55(D)]
	shufps	xmm3, xmm3, 0	# tmp395
	movss	xmm2, DWORD PTR 16[rsi]	# _206, MEM[(float *)src_55(D) + 16B]
# src/Mat4.c:191:         c[0] = d[i];
	.loc 1 191 0
	movaps	xmm14, XMMWORD PTR 16[rsp]	# vect__2.58, MEM[(float *)&d]
.LVL55:
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm2, xmm2, 0	# tmp406
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm3, xmm14	# tmp395, vect__2.58
# src/Mat4.c:192:         c[1] = d[i + 0x4];
	.loc 1 192 0
	movaps	xmm13, XMMWORD PTR 32[rsp]	# vect__4.61, MEM[(float *)&d + 16B]
.LVL56:
	movss	xmm10, DWORD PTR 20[rsi]	# _213, MEM[(float *)src_55(D) + 20B]
	movss	xmm1, DWORD PTR 32[rsi]	# _241, MEM[(float *)src_55(D) + 32B]
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm10, xmm10, 0	# tmp408
	movss	xmm7, DWORD PTR 36[rsi]	# _248, MEM[(float *)src_55(D) + 36B]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm15, xmm3	# vect__10.71, tmp395
	movss	xmm3, DWORD PTR 4[rsi]	# tmp397, MEM[(float *)src_55(D) + 4B]
	shufps	xmm3, xmm3, 0	# tmp397
	movss	xmm0, DWORD PTR 48[rsi]	# _276, MEM[(float *)src_55(D) + 48B]
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm1, xmm1, 0	# tmp417
	movss	xmm4, DWORD PTR 52[rsi]	# _283, MEM[(float *)src_55(D) + 52B]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm3, xmm13	# vect__12.75, vect__4.61
# src/Mat4.c:193:         c[2] = d[i + 0x8];
	.loc 1 193 0
	movaps	xmm12, XMMWORD PTR 48[rsp]	# vect__6.64, MEM[(float *)&d + 32B]
.LVL57:
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm7, xmm7, 0	# tmp419
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	shufps	xmm0, xmm0, 0	# tmp428
	movss	xmm9, DWORD PTR 24[rsi]	# _221, MEM[(float *)src_55(D) + 24B]
	shufps	xmm4, xmm4, 0	# tmp430
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm2, xmm14	# vect__21.92, vect__2.58
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm3, xmm15	# vect__13.76, vect__10.71
	movss	xmm15, DWORD PTR 8[rsi]	# tmp400, MEM[(float *)src_55(D) + 8B]
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm10, xmm13	# vect__23.96, vect__4.61
	movss	xmm6, DWORD PTR 40[rsi]	# _256, MEM[(float *)src_55(D) + 40B]
	movss	xmm11, DWORD PTR 60[rsi]	# _299, MEM[(float *)src_55(D) + 60B]
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm1, xmm14	# vect__32.113, vect__2.58
	movss	DWORD PTR 12[rsp], xmm11	# %sfp, _299
	movss	xmm8, DWORD PTR 28[rsi]	# _229, MEM[(float *)src_55(D) + 28B]
	mulps	xmm7, xmm13	# vect__34.117, vect__4.61
	movss	xmm5, DWORD PTR 44[rsi]	# _264, MEM[(float *)src_55(D) + 44B]
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm10, xmm2	# vect__24.97, vect__21.92
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm14, xmm0	# vect__43.134, tmp428
# src/Mat4.c:194:         c[3] = d[i + 0xc];
	.loc 1 194 0
	movaps	xmm11, XMMWORD PTR 64[rsp]	# vect__8.67, MEM[(float *)&d + 48B]
.LVL58:
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm13, xmm4	# vect__45.138, tmp430
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm7, xmm1	# vect__35.118, vect__32.113
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm15, xmm15, 0	# tmp400
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm9, xmm9, 0	# tmp411
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm6, xmm6, 0	# tmp422
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm15, xmm12	# vect__15.80, vect__6.64
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm13, xmm14	# vect__46.139, vect__43.134
	movss	xmm14, DWORD PTR 8[rsp]	# tmp433, %sfp
	shufps	xmm14, xmm14, 0	# tmp433
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm9, xmm12	# vect__26.101, vect__6.64
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm6, xmm12	# vect__37.122, vect__6.64
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm3, xmm15	# vect__16.81, vect__15.80
	movss	xmm15, DWORD PTR 12[rsi]	# tmp403, MEM[(float *)src_55(D) + 12B]
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm12, xmm14	# vect__48.143, tmp433
	movss	xmm14, DWORD PTR 12[rsp]	# tmp436, %sfp
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm9, xmm10	# vect__27.102, vect__24.97
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm15, xmm15, 0	# tmp403
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm8, xmm8, 0	# tmp414
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm6, xmm7	# vect__38.123, vect__35.118
	shufps	xmm5, xmm5, 0	# tmp425
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	shufps	xmm14, xmm14, 0	# tmp436
	addps	xmm12, xmm13	# vect__49.144, vect__46.139
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm15, xmm11	# vect__18.85, vect__8.67
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm8, xmm11	# vect__29.106, vect__8.67
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm5, xmm11	# vect__40.127, vect__8.67
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm3, xmm15	# vect__19.86, vect__18.85
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm11, xmm14	# vect__51.148, tmp436
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm8, xmm9	# vect__30.107, vect__27.102
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm5, xmm6	# vect__41.128, vect__38.123
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movups	XMMWORD PTR [rax], xmm3	# MEM[(float *)dest_56(D)], vect__19.86
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm11, xmm12	# vect__52.149, vect__49.144
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movups	XMMWORD PTR 16[rax], xmm8	# MEM[(float *)dest_56(D) + 16B], vect__30.107
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movups	XMMWORD PTR 32[rax], xmm5	# MEM[(float *)dest_56(D) + 32B], vect__41.128
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movups	XMMWORD PTR 48[rax], xmm11	# MEM[(float *)dest_56(D) + 48B], vect__52.149
.L20:
# src/Mat4.c:203: }
	.loc 1 203 0
	mov	rcx, QWORD PTR 88[rsp]	# tmp554, D.4760
	xor	rcx, QWORD PTR fs:40	# tmp554,
	jne	.L29	#,
	add	rsp, 104	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.LVL59:
	.p2align 4,,10
	.p2align 3
.L19:
	.cfi_restore_state
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movss	xmm1, DWORD PTR 4[rsi]	# tmp439, MEM[(float *)src_55(D) + 4B]
	movss	xmm5, DWORD PTR [rsi]	# tmp440, MEM[(float *)src_55(D)]
# src/Mat4.c:191:         c[0] = d[i];
	.loc 1 191 0
	movss	xmm4, DWORD PTR 16[rsp]	# _273, d
.LVL60:
# src/Mat4.c:192:         c[1] = d[i + 0x4];
	.loc 1 192 0
	movss	xmm0, DWORD PTR 32[rsp]	# _253, d
.LVL61:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulss	xmm5, xmm4	# tmp440, _273
	mulss	xmm1, xmm0	# tmp439, _253
# src/Mat4.c:193:         c[2] = d[i + 0x8];
	.loc 1 193 0
	movss	xmm3, DWORD PTR 48[rsp]	# _238, d
.LVL62:
# src/Mat4.c:194:         c[3] = d[i + 0xc];
	.loc 1 194 0
	movss	xmm2, DWORD PTR 64[rsp]	# _218, d
.LVL63:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addss	xmm1, xmm5	# tmp441, tmp440
	movss	xmm5, DWORD PTR 8[rsi]	# tmp442, MEM[(float *)src_55(D) + 8B]
	mulss	xmm5, xmm3	# tmp442, _238
	addss	xmm1, xmm5	# tmp443, tmp442
	movss	xmm5, DWORD PTR 12[rsi]	# tmp444, MEM[(float *)src_55(D) + 12B]
	mulss	xmm5, xmm2	# tmp444, _218
	addss	xmm1, xmm5	# tmp445, tmp444
	movss	DWORD PTR [rax], xmm1	# MEM[(struct Mat4 *)dest_56(D)], tmp445
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movss	xmm1, DWORD PTR 16[rsi]	# tmp446, MEM[(float *)src_55(D) + 16B]
	movss	xmm5, DWORD PTR 20[rsi]	# tmp447, MEM[(float *)src_55(D) + 20B]
	mulss	xmm1, xmm4	# tmp446, _273
	mulss	xmm5, xmm0	# tmp447, _253
	addss	xmm1, xmm5	# tmp448, tmp447
	movss	xmm5, DWORD PTR 24[rsi]	# tmp449, MEM[(float *)src_55(D) + 24B]
	mulss	xmm5, xmm3	# tmp449, _238
	addss	xmm1, xmm5	# tmp450, tmp449
	movss	xmm5, DWORD PTR 28[rsi]	# tmp451, MEM[(float *)src_55(D) + 28B]
	mulss	xmm5, xmm2	# tmp451, _218
	addss	xmm1, xmm5	# tmp452, tmp451
	movss	DWORD PTR 16[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 16B], tmp452
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movss	xmm1, DWORD PTR 32[rsi]	# tmp453, MEM[(float *)src_55(D) + 32B]
	movss	xmm5, DWORD PTR 36[rsi]	# tmp454, MEM[(float *)src_55(D) + 36B]
	mulss	xmm1, xmm4	# tmp453, _273
	mulss	xmm5, xmm0	# tmp454, _253
	addss	xmm1, xmm5	# tmp455, tmp454
	movss	xmm5, DWORD PTR 40[rsi]	# tmp456, MEM[(float *)src_55(D) + 40B]
	mulss	xmm5, xmm3	# tmp456, _238
	addss	xmm1, xmm5	# tmp457, tmp456
	movss	xmm5, DWORD PTR 44[rsi]	# tmp458, MEM[(float *)src_55(D) + 44B]
	mulss	xmm5, xmm2	# tmp458, _218
	addss	xmm1, xmm5	# tmp459, tmp458
	movss	DWORD PTR 32[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 32B], tmp459
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulss	xmm4, DWORD PTR 48[rsi]	# tmp461, MEM[(float *)src_55(D) + 48B]
.LVL64:
	mulss	xmm0, DWORD PTR 52[rsi]	# tmp460, MEM[(float *)src_55(D) + 52B]
.LVL65:
	mulss	xmm3, DWORD PTR 56[rsi]	# tmp463, MEM[(float *)src_55(D) + 56B]
.LVL66:
	mulss	xmm2, DWORD PTR 60[rsi]	# tmp465, MEM[(float *)src_55(D) + 60B]
.LVL67:
	addss	xmm0, xmm4	# tmp462, tmp461
# src/Mat4.c:192:         c[1] = d[i + 0x4];
	.loc 1 192 0
	movss	xmm4, DWORD PTR 36[rsp]	# _27, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addss	xmm0, xmm3	# tmp464, tmp463
# src/Mat4.c:193:         c[2] = d[i + 0x8];
	.loc 1 193 0
	movss	xmm3, DWORD PTR 52[rsp]	# _28, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addss	xmm0, xmm2	# tmp466, tmp465
# src/Mat4.c:194:         c[3] = d[i + 0xc];
	.loc 1 194 0
	movss	xmm2, DWORD PTR 68[rsp]	# _30, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movss	DWORD PTR 48[rax], xmm0	# MEM[(struct Mat4 *)dest_56(D) + 48B], tmp466
.LVL68:
# src/Mat4.c:191:         c[0] = d[i];
	.loc 1 191 0
	movss	xmm0, DWORD PTR 20[rsp]	# _25, d
.LVL69:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movss	xmm1, DWORD PTR [rsi]	# tmp467, MEM[(float *)src_55(D)]
	movss	xmm5, DWORD PTR 4[rsi]	# tmp468, MEM[(float *)src_55(D) + 4B]
	mulss	xmm1, xmm0	# tmp467, _25
	mulss	xmm5, xmm4	# tmp468, _27
	addss	xmm1, xmm5	# tmp469, tmp468
	movss	xmm5, DWORD PTR 8[rsi]	# tmp470, MEM[(float *)src_55(D) + 8B]
	mulss	xmm5, xmm3	# tmp470, _28
	addss	xmm1, xmm5	# tmp471, tmp470
	movss	xmm5, DWORD PTR 12[rsi]	# tmp472, MEM[(float *)src_55(D) + 12B]
	mulss	xmm5, xmm2	# tmp472, _30
	addss	xmm1, xmm5	# tmp473, tmp472
	movss	DWORD PTR 4[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 4B], tmp473
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movss	xmm1, DWORD PTR 16[rsi]	# tmp474, MEM[(float *)src_55(D) + 16B]
	movss	xmm5, DWORD PTR 20[rsi]	# tmp475, MEM[(float *)src_55(D) + 20B]
	mulss	xmm1, xmm0	# tmp474, _25
	mulss	xmm5, xmm4	# tmp475, _27
	addss	xmm1, xmm5	# tmp476, tmp475
	movss	xmm5, DWORD PTR 24[rsi]	# tmp477, MEM[(float *)src_55(D) + 24B]
	mulss	xmm5, xmm3	# tmp477, _28
	addss	xmm1, xmm5	# tmp478, tmp477
	movss	xmm5, DWORD PTR 28[rsi]	# tmp479, MEM[(float *)src_55(D) + 28B]
	mulss	xmm5, xmm2	# tmp479, _30
	addss	xmm1, xmm5	# tmp480, tmp479
	movss	DWORD PTR 20[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 20B], tmp480
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movss	xmm1, DWORD PTR 32[rsi]	# tmp481, MEM[(float *)src_55(D) + 32B]
	movss	xmm5, DWORD PTR 36[rsi]	# tmp482, MEM[(float *)src_55(D) + 36B]
	mulss	xmm1, xmm0	# tmp481, _25
	mulss	xmm5, xmm4	# tmp482, _27
	addss	xmm1, xmm5	# tmp483, tmp482
	movss	xmm5, DWORD PTR 40[rsi]	# tmp484, MEM[(float *)src_55(D) + 40B]
	mulss	xmm5, xmm3	# tmp484, _28
	addss	xmm1, xmm5	# tmp485, tmp484
	movss	xmm5, DWORD PTR 44[rsi]	# tmp486, MEM[(float *)src_55(D) + 44B]
	mulss	xmm5, xmm2	# tmp486, _30
	addss	xmm1, xmm5	# tmp487, tmp486
	movss	DWORD PTR 36[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 36B], tmp487
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulss	xmm4, DWORD PTR 52[rsi]	# tmp489, MEM[(float *)src_55(D) + 52B]
.LVL70:
	mulss	xmm0, DWORD PTR 48[rsi]	# tmp488, MEM[(float *)src_55(D) + 48B]
.LVL71:
	mulss	xmm3, DWORD PTR 56[rsi]	# tmp491, MEM[(float *)src_55(D) + 56B]
.LVL72:
	mulss	xmm2, DWORD PTR 60[rsi]	# tmp493, MEM[(float *)src_55(D) + 60B]
.LVL73:
	addss	xmm0, xmm4	# tmp490, tmp489
# src/Mat4.c:192:         c[1] = d[i + 0x4];
	.loc 1 192 0
	movss	xmm4, DWORD PTR 40[rsp]	# _312, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addss	xmm0, xmm3	# tmp492, tmp491
# src/Mat4.c:193:         c[2] = d[i + 0x8];
	.loc 1 193 0
	movss	xmm3, DWORD PTR 56[rsp]	# _314, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addss	xmm0, xmm2	# tmp494, tmp493
# src/Mat4.c:194:         c[3] = d[i + 0xc];
	.loc 1 194 0
	movss	xmm2, DWORD PTR 72[rsp]	# _316, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movss	DWORD PTR 52[rax], xmm0	# MEM[(struct Mat4 *)dest_56(D) + 52B], tmp494
.LVL74:
# src/Mat4.c:191:         c[0] = d[i];
	.loc 1 191 0
	movss	xmm0, DWORD PTR 24[rsp]	# _310, d
.LVL75:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movss	xmm1, DWORD PTR [rsi]	# tmp495, MEM[(float *)src_55(D)]
	movss	xmm5, DWORD PTR 4[rsi]	# tmp496, MEM[(float *)src_55(D) + 4B]
	mulss	xmm1, xmm0	# tmp495, _310
	mulss	xmm5, xmm4	# tmp496, _312
	addss	xmm1, xmm5	# tmp497, tmp496
	movss	xmm5, DWORD PTR 8[rsi]	# tmp498, MEM[(float *)src_55(D) + 8B]
	mulss	xmm5, xmm3	# tmp498, _314
	addss	xmm1, xmm5	# tmp499, tmp498
	movss	xmm5, DWORD PTR 12[rsi]	# tmp500, MEM[(float *)src_55(D) + 12B]
	mulss	xmm5, xmm2	# tmp500, _316
	addss	xmm1, xmm5	# tmp501, tmp500
	movss	DWORD PTR 8[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 8B], tmp501
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movss	xmm1, DWORD PTR 16[rsi]	# tmp502, MEM[(float *)src_55(D) + 16B]
	movss	xmm5, DWORD PTR 20[rsi]	# tmp503, MEM[(float *)src_55(D) + 20B]
	mulss	xmm1, xmm0	# tmp502, _310
	mulss	xmm5, xmm4	# tmp503, _312
	addss	xmm1, xmm5	# tmp504, tmp503
	movss	xmm5, DWORD PTR 24[rsi]	# tmp505, MEM[(float *)src_55(D) + 24B]
	mulss	xmm5, xmm3	# tmp505, _314
	addss	xmm1, xmm5	# tmp506, tmp505
	movss	xmm5, DWORD PTR 28[rsi]	# tmp507, MEM[(float *)src_55(D) + 28B]
	mulss	xmm5, xmm2	# tmp507, _316
	addss	xmm1, xmm5	# tmp508, tmp507
	movss	DWORD PTR 24[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 24B], tmp508
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movss	xmm1, DWORD PTR 32[rsi]	# tmp509, MEM[(float *)src_55(D) + 32B]
	movss	xmm5, DWORD PTR 36[rsi]	# tmp510, MEM[(float *)src_55(D) + 36B]
	mulss	xmm1, xmm0	# tmp509, _310
	mulss	xmm5, xmm4	# tmp510, _312
	addss	xmm1, xmm5	# tmp511, tmp510
	movss	xmm5, DWORD PTR 40[rsi]	# tmp512, MEM[(float *)src_55(D) + 40B]
	mulss	xmm5, xmm3	# tmp512, _314
	addss	xmm1, xmm5	# tmp513, tmp512
	movss	xmm5, DWORD PTR 44[rsi]	# tmp514, MEM[(float *)src_55(D) + 44B]
	mulss	xmm5, xmm2	# tmp514, _316
	addss	xmm1, xmm5	# tmp515, tmp514
	movss	DWORD PTR 40[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 40B], tmp515
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulss	xmm4, DWORD PTR 52[rsi]	# tmp517, MEM[(float *)src_55(D) + 52B]
.LVL76:
	mulss	xmm0, DWORD PTR 48[rsi]	# tmp516, MEM[(float *)src_55(D) + 48B]
.LVL77:
	mulss	xmm3, DWORD PTR 56[rsi]	# tmp519, MEM[(float *)src_55(D) + 56B]
.LVL78:
	mulss	xmm2, DWORD PTR 60[rsi]	# tmp521, MEM[(float *)src_55(D) + 60B]
.LVL79:
	addss	xmm0, xmm4	# tmp518, tmp517
# src/Mat4.c:192:         c[1] = d[i + 0x4];
	.loc 1 192 0
	movss	xmm4, DWORD PTR 44[rsp]	# _53, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addss	xmm0, xmm3	# tmp520, tmp519
# src/Mat4.c:193:         c[2] = d[i + 0x8];
	.loc 1 193 0
	movss	xmm3, DWORD PTR 60[rsp]	# _98, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addss	xmm0, xmm2	# tmp522, tmp521
# src/Mat4.c:194:         c[3] = d[i + 0xc];
	.loc 1 194 0
	movss	xmm2, DWORD PTR 76[rsp]	# _96, d
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movss	DWORD PTR 56[rax], xmm0	# MEM[(struct Mat4 *)dest_56(D) + 56B], tmp522
.LVL80:
# src/Mat4.c:191:         c[0] = d[i];
	.loc 1 191 0
	movss	xmm0, DWORD PTR 28[rsp]	# _65, d
.LVL81:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movss	xmm1, DWORD PTR [rsi]	# tmp523, MEM[(float *)src_55(D)]
	movss	xmm5, DWORD PTR 4[rsi]	# tmp524, MEM[(float *)src_55(D) + 4B]
	mulss	xmm1, xmm0	# tmp523, _65
	mulss	xmm5, xmm4	# tmp524, _53
	addss	xmm1, xmm5	# tmp525, tmp524
	movss	xmm5, DWORD PTR 8[rsi]	# tmp526, MEM[(float *)src_55(D) + 8B]
	mulss	xmm5, xmm3	# tmp526, _98
	addss	xmm1, xmm5	# tmp527, tmp526
	movss	xmm5, DWORD PTR 12[rsi]	# tmp528, MEM[(float *)src_55(D) + 12B]
	mulss	xmm5, xmm2	# tmp528, _96
	addss	xmm1, xmm5	# tmp529, tmp528
	movss	DWORD PTR 12[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 12B], tmp529
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movss	xmm1, DWORD PTR 16[rsi]	# tmp530, MEM[(float *)src_55(D) + 16B]
	movss	xmm5, DWORD PTR 20[rsi]	# tmp531, MEM[(float *)src_55(D) + 20B]
	mulss	xmm1, xmm0	# tmp530, _65
	mulss	xmm5, xmm4	# tmp531, _53
	addss	xmm1, xmm5	# tmp532, tmp531
	movss	xmm5, DWORD PTR 24[rsi]	# tmp533, MEM[(float *)src_55(D) + 24B]
	mulss	xmm5, xmm3	# tmp533, _98
	addss	xmm1, xmm5	# tmp534, tmp533
	movss	xmm5, DWORD PTR 28[rsi]	# tmp535, MEM[(float *)src_55(D) + 28B]
	mulss	xmm5, xmm2	# tmp535, _96
	addss	xmm1, xmm5	# tmp536, tmp535
	movss	DWORD PTR 28[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 28B], tmp536
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movss	xmm1, DWORD PTR 32[rsi]	# tmp537, MEM[(float *)src_55(D) + 32B]
	movss	xmm5, DWORD PTR 36[rsi]	# tmp538, MEM[(float *)src_55(D) + 36B]
	mulss	xmm1, xmm0	# tmp537, _65
	mulss	xmm5, xmm4	# tmp538, _53
	addss	xmm1, xmm5	# tmp539, tmp538
	movss	xmm5, DWORD PTR 40[rsi]	# tmp540, MEM[(float *)src_55(D) + 40B]
	mulss	xmm5, xmm3	# tmp540, _98
	addss	xmm1, xmm5	# tmp541, tmp540
	movss	xmm5, DWORD PTR 44[rsi]	# tmp542, MEM[(float *)src_55(D) + 44B]
	mulss	xmm5, xmm2	# tmp542, _96
	addss	xmm1, xmm5	# tmp543, tmp542
	movss	DWORD PTR 44[rax], xmm1	# MEM[(struct Mat4 *)dest_56(D) + 44B], tmp543
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulss	xmm0, DWORD PTR 48[rsi]	# tmp544, MEM[(float *)src_55(D) + 48B]
.LVL82:
	mulss	xmm4, DWORD PTR 52[rsi]	# tmp545, MEM[(float *)src_55(D) + 52B]
.LVL83:
	mulss	xmm3, DWORD PTR 56[rsi]	# tmp547, MEM[(float *)src_55(D) + 56B]
.LVL84:
	mulss	xmm2, DWORD PTR 60[rsi]	# tmp549, MEM[(float *)src_55(D) + 60B]
.LVL85:
	addss	xmm0, xmm4	# tmp546, tmp545
	addss	xmm0, xmm3	# tmp548, tmp547
	addss	xmm0, xmm2	# tmp550, tmp549
	movss	DWORD PTR 60[rax], xmm0	# MEM[(struct Mat4 *)dest_56(D) + 60B], tmp550
.LVL86:
	jmp	.L20	#
.LVL87:
.L29:
# src/Mat4.c:203: }
	.loc 1 203 0
	call	__stack_chk_fail@PLT	#
.LVL88:
	.cfi_endproc
.LFE37:
	.size	mulMat4, .-mulMat4
	.p2align 4,,15
	.globl	translateMat4
	.type	translateMat4, @function
translateMat4:
.LFB38:
	.loc 1 206 0
	.cfi_startproc
.LVL89:
# src/Mat4.c:208:     mat[12] += mat[0] * v->x + mat[4] * v->y + mat[ 8] * v->z;
	.loc 1 208 0
	movss	xmm0, DWORD PTR [rdi]	# MEM[(float *)m_53(D)], MEM[(float *)m_53(D)]
# src/Mat4.c:206: {
	.loc 1 206 0
	mov	rax, rdi	# m, m
# src/Mat4.c:208:     mat[12] += mat[0] * v->x + mat[4] * v->y + mat[ 8] * v->z;
	.loc 1 208 0
	movss	xmm1, DWORD PTR 16[rdi]	# MEM[(float *)m_53(D) + 16B], MEM[(float *)m_53(D) + 16B]
	mulss	xmm0, DWORD PTR [rsi]	# tmp142, v_55(D)->x
	mulss	xmm1, DWORD PTR 4[rsi]	# tmp144, v_55(D)->y
	addss	xmm0, xmm1	# tmp146, tmp144
	movss	xmm1, DWORD PTR 32[rdi]	# MEM[(float *)m_53(D) + 32B], MEM[(float *)m_53(D) + 32B]
	mulss	xmm1, DWORD PTR 8[rsi]	# tmp147, v_55(D)->z
	addss	xmm0, xmm1	# tmp149, tmp147
# src/Mat4.c:209:     mat[13] += mat[1] * v->x + mat[5] * v->y + mat[ 9] * v->z;
	.loc 1 209 0
	movss	xmm1, DWORD PTR 20[rdi]	# MEM[(float *)m_53(D) + 20B], MEM[(float *)m_53(D) + 20B]
# src/Mat4.c:208:     mat[12] += mat[0] * v->x + mat[4] * v->y + mat[ 8] * v->z;
	.loc 1 208 0
	addss	xmm0, DWORD PTR 48[rdi]	# tmp150, MEM[(float *)m_53(D) + 48B]
	movss	DWORD PTR 48[rdi], xmm0	# MEM[(float *)m_53(D) + 48B], tmp150
# src/Mat4.c:209:     mat[13] += mat[1] * v->x + mat[5] * v->y + mat[ 9] * v->z;
	.loc 1 209 0
	movss	xmm0, DWORD PTR 4[rdi]	# MEM[(float *)m_53(D) + 4B], MEM[(float *)m_53(D) + 4B]
	mulss	xmm1, DWORD PTR 4[rsi]	# tmp154, v_55(D)->y
	mulss	xmm0, DWORD PTR [rsi]	# tmp152, v_55(D)->x
	addss	xmm0, xmm1	# tmp156, tmp154
	movss	xmm1, DWORD PTR 36[rdi]	# MEM[(float *)m_53(D) + 36B], MEM[(float *)m_53(D) + 36B]
	mulss	xmm1, DWORD PTR 8[rsi]	# tmp157, v_55(D)->z
	addss	xmm0, xmm1	# tmp159, tmp157
# src/Mat4.c:210:     mat[14] += mat[2] * v->x + mat[6] * v->y + mat[10] * v->z;
	.loc 1 210 0
	movss	xmm1, DWORD PTR 24[rdi]	# MEM[(float *)m_53(D) + 24B], MEM[(float *)m_53(D) + 24B]
# src/Mat4.c:209:     mat[13] += mat[1] * v->x + mat[5] * v->y + mat[ 9] * v->z;
	.loc 1 209 0
	addss	xmm0, DWORD PTR 52[rdi]	# tmp160, MEM[(float *)m_53(D) + 52B]
	movss	DWORD PTR 52[rdi], xmm0	# MEM[(float *)m_53(D) + 52B], tmp160
# src/Mat4.c:210:     mat[14] += mat[2] * v->x + mat[6] * v->y + mat[10] * v->z;
	.loc 1 210 0
	movss	xmm0, DWORD PTR 8[rdi]	# MEM[(float *)m_53(D) + 8B], MEM[(float *)m_53(D) + 8B]
	mulss	xmm1, DWORD PTR 4[rsi]	# tmp164, v_55(D)->y
	mulss	xmm0, DWORD PTR [rsi]	# tmp162, v_55(D)->x
	addss	xmm0, xmm1	# tmp166, tmp164
	movss	xmm1, DWORD PTR 40[rdi]	# MEM[(float *)m_53(D) + 40B], MEM[(float *)m_53(D) + 40B]
	mulss	xmm1, DWORD PTR 8[rsi]	# tmp167, v_55(D)->z
	addss	xmm0, xmm1	# tmp169, tmp167
# src/Mat4.c:211:     mat[15] += mat[3] * v->x + mat[7] * v->y + mat[11] * v->z;
	.loc 1 211 0
	movss	xmm1, DWORD PTR 28[rdi]	# MEM[(float *)m_53(D) + 28B], MEM[(float *)m_53(D) + 28B]
# src/Mat4.c:210:     mat[14] += mat[2] * v->x + mat[6] * v->y + mat[10] * v->z;
	.loc 1 210 0
	addss	xmm0, DWORD PTR 56[rdi]	# tmp170, MEM[(float *)m_53(D) + 56B]
	movss	DWORD PTR 56[rdi], xmm0	# MEM[(float *)m_53(D) + 56B], tmp170
# src/Mat4.c:211:     mat[15] += mat[3] * v->x + mat[7] * v->y + mat[11] * v->z;
	.loc 1 211 0
	movss	xmm0, DWORD PTR 12[rdi]	# MEM[(float *)m_53(D) + 12B], MEM[(float *)m_53(D) + 12B]
	mulss	xmm1, DWORD PTR 4[rsi]	# tmp174, v_55(D)->y
	mulss	xmm0, DWORD PTR [rsi]	# tmp172, v_55(D)->x
	addss	xmm0, xmm1	# tmp176, tmp174
	movss	xmm1, DWORD PTR 44[rdi]	# MEM[(float *)m_53(D) + 44B], MEM[(float *)m_53(D) + 44B]
	mulss	xmm1, DWORD PTR 8[rsi]	# tmp177, v_55(D)->z
	addss	xmm0, xmm1	# tmp179, tmp177
	addss	xmm0, DWORD PTR 60[rdi]	# tmp180, MEM[(float *)m_53(D) + 60B]
	movss	DWORD PTR 60[rdi], xmm0	# MEM[(float *)m_53(D) + 60B], tmp180
# src/Mat4.c:213: }
	.loc 1 213 0
	ret
	.cfi_endproc
.LFE38:
	.size	translateMat4, .-translateMat4
	.p2align 4,,15
	.globl	scaleMat4
	.type	scaleMat4, @function
scaleMat4:
.LFB39:
	.loc 1 216 0
	.cfi_startproc
.LVL90:
# src/Mat4.c:217:     mat->data[ 0] *= v->x; mat->data[ 1] *= v->x; mat->data[ 2] *= v->x; mat->data[ 3] *= v->x;
	.loc 1 217 0
	movss	xmm0, DWORD PTR [rsi]	# _2, v_30(D)->x
# src/Mat4.c:216: {
	.loc 1 216 0
	mov	rax, rdi	# mat, mat
# src/Mat4.c:217:     mat->data[ 0] *= v->x; mat->data[ 1] *= v->x; mat->data[ 2] *= v->x; mat->data[ 3] *= v->x;
	.loc 1 217 0
	movss	xmm1, DWORD PTR [rdi]	# tmp117, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp117, _2
	movss	DWORD PTR [rdi], xmm1	# mat_29(D)->data, tmp117
	movss	xmm1, DWORD PTR 4[rdi]	# tmp119, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp119, _2
	movss	DWORD PTR 4[rdi], xmm1	# mat_29(D)->data, tmp119
	movss	xmm1, DWORD PTR 8[rdi]	# tmp121, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp121, _2
	mulss	xmm0, DWORD PTR 12[rdi]	# tmp123, mat_29(D)->data
	movss	DWORD PTR 8[rdi], xmm1	# mat_29(D)->data, tmp121
# src/Mat4.c:218:     mat->data[ 4] *= v->y; mat->data[ 5] *= v->y; mat->data[ 6] *= v->y; mat->data[ 7] *= v->y;
	.loc 1 218 0
	movss	xmm1, DWORD PTR 16[rdi]	# tmp125, mat_29(D)->data
# src/Mat4.c:217:     mat->data[ 0] *= v->x; mat->data[ 1] *= v->x; mat->data[ 2] *= v->x; mat->data[ 3] *= v->x;
	.loc 1 217 0
	movss	DWORD PTR 12[rdi], xmm0	# mat_29(D)->data, tmp123
# src/Mat4.c:218:     mat->data[ 4] *= v->y; mat->data[ 5] *= v->y; mat->data[ 6] *= v->y; mat->data[ 7] *= v->y;
	.loc 1 218 0
	movss	xmm0, DWORD PTR 4[rsi]	# _11, v_30(D)->y
	mulss	xmm1, xmm0	# tmp125, _11
	movss	DWORD PTR 16[rdi], xmm1	# mat_29(D)->data, tmp125
	movss	xmm1, DWORD PTR 20[rdi]	# tmp127, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp127, _11
	movss	DWORD PTR 20[rdi], xmm1	# mat_29(D)->data, tmp127
	movss	xmm1, DWORD PTR 24[rdi]	# tmp129, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp129, _11
	mulss	xmm0, DWORD PTR 28[rdi]	# tmp131, mat_29(D)->data
	movss	DWORD PTR 24[rdi], xmm1	# mat_29(D)->data, tmp129
# src/Mat4.c:219:     mat->data[ 8] *= v->z; mat->data[ 9] *= v->z; mat->data[10] *= v->z; mat->data[11] *= v->z;
	.loc 1 219 0
	movss	xmm1, DWORD PTR 32[rdi]	# tmp133, mat_29(D)->data
# src/Mat4.c:218:     mat->data[ 4] *= v->y; mat->data[ 5] *= v->y; mat->data[ 6] *= v->y; mat->data[ 7] *= v->y;
	.loc 1 218 0
	movss	DWORD PTR 28[rdi], xmm0	# mat_29(D)->data, tmp131
# src/Mat4.c:219:     mat->data[ 8] *= v->z; mat->data[ 9] *= v->z; mat->data[10] *= v->z; mat->data[11] *= v->z;
	.loc 1 219 0
	movss	xmm0, DWORD PTR 8[rsi]	# _20, v_30(D)->z
	mulss	xmm1, xmm0	# tmp133, _20
	movss	DWORD PTR 32[rdi], xmm1	# mat_29(D)->data, tmp133
	movss	xmm1, DWORD PTR 36[rdi]	# tmp135, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp135, _20
	movss	DWORD PTR 36[rdi], xmm1	# mat_29(D)->data, tmp135
	movss	xmm1, DWORD PTR 40[rdi]	# tmp137, mat_29(D)->data
	mulss	xmm1, xmm0	# tmp137, _20
	mulss	xmm0, DWORD PTR 44[rdi]	# tmp139, mat_29(D)->data
	movss	DWORD PTR 40[rdi], xmm1	# mat_29(D)->data, tmp137
	movss	DWORD PTR 44[rdi], xmm0	# mat_29(D)->data, tmp139
# src/Mat4.c:221: }
	.loc 1 221 0
	ret
	.cfi_endproc
.LFE39:
	.size	scaleMat4, .-scaleMat4
	.p2align 4,,15
	.globl	rotateMat4
	.type	rotateMat4, @function
rotateMat4:
.LFB40:
	.loc 1 224 0
	.cfi_startproc
.LVL91:
	push	rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	push	rbx	#
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	mov	rbp, rsi	# v, v
	mov	rbx, rdi	# mat, mat
	sub	rsp, 104	#,
	.cfi_def_cfa_offset 128
.LBB12:
.LBB13:
# src/Mat4.c:61:     const float rad = TO_RAD(degrees);
	.loc 1 61 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp166,
.LVL92:
	lea	rdi, 12[rsp]	# tmp164,
.LVL93:
	lea	rsi, 8[rsp]	# tmp165,
.LVL94:
.LBE13:
.LBE12:
# src/Mat4.c:224: {
	.loc 1 224 0
	mov	rax, QWORD PTR fs:40	# tmp227,
	mov	QWORD PTR 88[rsp], rax	# D.4838, tmp227
	xor	eax, eax	# tmp227
.LVL95:
.LBB20:
.LBB14:
# src/Mat4.c:61:     const float rad = TO_RAD(degrees);
	.loc 1 61 0
	divss	xmm0, DWORD PTR .LC6[rip]	# rad,
	call	sincosf@PLT	#
.LVL96:
# src/Mat4.c:67:     const float zs = v->z * s;
	.loc 1 67 0
	movss	xmm0, DWORD PTR 8[rbp]	# _71, v_6(D)->z
# src/Mat4.c:68:     const float ys = v->y * s;
	.loc 1 68 0
	movss	xmm2, DWORD PTR 4[rbp]	# _73, v_6(D)->y
# src/Mat4.c:71:     const float xz = v->x * v->z;
	.loc 1 71 0
	movaps	xmm9, xmm0	# xz, _71
	movss	xmm4, DWORD PTR 12[rsp]	# sincostmp_5,
.LVL97:
# src/Mat4.c:68:     const float ys = v->y * s;
	.loc 1 68 0
	movaps	xmm5, xmm4	# ys, sincostmp_5
# src/Mat4.c:70:     const float xy = v->x * v->y;
	.loc 1 70 0
	movaps	xmm13, xmm2	# xy, _73
# src/Mat4.c:72:     const float yz = v->y * v->z;
	.loc 1 72 0
	movaps	xmm1, xmm0	# yz, _71
# src/Mat4.c:69:     const float xs = v->x * s;
	.loc 1 69 0
	movss	xmm10, DWORD PTR 0[rbp]	# _75, v_6(D)->x
# src/Mat4.c:68:     const float ys = v->y * s;
	.loc 1 68 0
	mulss	xmm5, xmm2	# ys, _73
	movss	xmm3, DWORD PTR 8[rsp]	# sincostmp_5,
.LVL98:
# src/Mat4.c:67:     const float zs = v->z * s;
	.loc 1 67 0
	movaps	xmm6, xmm4	# zs, sincostmp_5
# src/Mat4.c:66:     const float nc = 1.0f - c;
	.loc 1 66 0
	movss	xmm8, DWORD PTR .LC4[rip]	# tmp170,
# src/Mat4.c:69:     const float xs = v->x * s;
	.loc 1 69 0
	mulss	xmm4, xmm10	# xs, _75
.LVL99:
# src/Mat4.c:66:     const float nc = 1.0f - c;
	.loc 1 66 0
	subss	xmm8, xmm3	# nc, sincostmp_5
.LVL100:
# src/Mat4.c:70:     const float xy = v->x * v->y;
	.loc 1 70 0
	mulss	xmm13, xmm10	# xy, _75
# src/Mat4.c:71:     const float xz = v->x * v->z;
	.loc 1 71 0
	mulss	xmm9, xmm10	# xz, _75
# src/Mat4.c:72:     const float yz = v->y * v->z;
	.loc 1 72 0
	mulss	xmm1, xmm2	# yz, _73
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	mulss	xmm10, xmm10	# tmp174, _75
# src/Mat4.c:84:     mat->data[ 6] = yznc + xs;
	.loc 1 84 0
	movaps	xmm12, xmm4	# _92, xs
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	mulss	xmm2, xmm2	# tmp176, _73
# src/Mat4.c:67:     const float zs = v->z * s;
	.loc 1 67 0
	mulss	xmm6, xmm0	# zs, _71
.LVL101:
# src/Mat4.c:73:     const float xync = xy * nc;
	.loc 1 73 0
	mulss	xmm13, xmm8	# xync, nc
.LVL102:
# src/Mat4.c:74:     const float xznc = xz * nc;
	.loc 1 74 0
	mulss	xmm9, xmm8	# xznc, nc
.LVL103:
# src/Mat4.c:75:     const float yznc = yz * nc;
	.loc 1 75 0
	mulss	xmm1, xmm8	# yznc, nc
.LVL104:
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	mulss	xmm10, xmm8	# tmp175, nc
# src/Mat4.c:78:     mat->data[ 1] = xync + zs;
	.loc 1 78 0
	movaps	xmm11, xmm6	# _86, zs
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	mulss	xmm2, xmm8	# tmp177, nc
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	mulss	xmm0, xmm0	# tmp178, _71
# src/Mat4.c:78:     mat->data[ 1] = xync + zs;
	.loc 1 78 0
	addss	xmm11, xmm13	# _86, xync
# src/Mat4.c:79:     mat->data[ 2] = xznc - ys;
	.loc 1 79 0
	movaps	xmm14, xmm9	# _87, xznc
# src/Mat4.c:77:     mat->data[ 0] = v->x * v->x * nc + c;
	.loc 1 77 0
	addss	xmm10, xmm3	# _85, sincostmp_5
# src/Mat4.c:82:     mat->data[ 4] = xync - zs;
	.loc 1 82 0
	subss	xmm13, xmm6	# _88, zs
.LVL105:
.LBE14:
.LBE20:
.LBB21:
.LBB22:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm6, XMMWORD PTR [rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
.LVL106:
.LBE22:
.LBE21:
.LBB29:
.LBB15:
# src/Mat4.c:83:     mat->data[ 5] = v->y * v->y * nc + c;
	.loc 1 83 0
	addss	xmm2, xmm3	# _91, sincostmp_5
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	mulss	xmm8, xmm0	# tmp179, tmp178
.LVL107:
# src/Mat4.c:84:     mat->data[ 6] = yznc + xs;
	.loc 1 84 0
	addss	xmm12, xmm1	# _92, yznc
.LBE15:
.LBE29:
.LBB30:
.LBB23:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm11, xmm11, 0	# tmp186
.LBE23:
.LBE30:
.LBB31:
.LBB16:
# src/Mat4.c:87:     mat->data[ 8] = xznc + ys;
	.loc 1 87 0
	addss	xmm9, xmm5	# _93, ys
.LVL108:
.LBE16:
.LBE31:
.LBB32:
.LBB24:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm10, xmm10, 0	# tmp188
.LBE24:
.LBE32:
.LBB33:
.LBB17:
# src/Mat4.c:88:     mat->data[ 9] = yznc - xs;
	.loc 1 88 0
	subss	xmm1, xmm4	# _94, xs
.LVL109:
.LBE17:
.LBE33:
.LBB34:
.LBB25:
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm13, xmm13, 0	# tmp197
.LBE25:
.LBE34:
.LBB35:
.LBB18:
# src/Mat4.c:79:     mat->data[ 2] = xznc - ys;
	.loc 1 79 0
	subss	xmm14, xmm5	# _87, ys
.LVL110:
.LBE18:
.LBE35:
.LBB36:
.LBB26:
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm2, xmm2, 0	# tmp195
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	pxor	xmm5, xmm5	# tmp185
.LVL111:
.LBE26:
.LBE36:
.LBB37:
.LBB19:
# src/Mat4.c:89:     mat->data[10] = v->z * v->z * nc + c;
	.loc 1 89 0
	addss	xmm8, xmm3	# _97, sincostmp_5
.LVL112:
.LBE19:
.LBE37:
.LBB38:
.LBB27:
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm9, xmm9, 0	# tmp206
	shufps	xmm1, xmm1, 0	# tmp204
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm0, XMMWORD PTR 16[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm10, xmm6	# vect__22.170, vect__14.160
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 16[rsp], xmm6	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm11, xmm0	# vect__24.171, vect__16.163
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 32[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm2, xmm0	# vect__35.180, vect__16.163
.LBE27:
.LBE38:
# src/Mat4.c:228: }
	.loc 1 228 0
	mov	rdx, QWORD PTR 88[rsp]	# tmp228, D.4838
	xor	rdx, QWORD PTR fs:40	# tmp228,
.LBB39:
.LBB28:
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm13, xmm6	# vect__33.179, vect__14.160
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm3, XMMWORD PTR 32[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm10, xmm11	# vect__25.172, vect__24.171
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm1, xmm0	# vect__46.188, vect__16.163
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 48[rsp], xmm3	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm9, xmm6	# vect__44.187, vect__14.160
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm13	# vect__36.181, vect__33.179
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm0, xmm5	# vect__57.196, tmp185
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm4, XMMWORD PTR 48[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm6, xmm5	# vect__55.195, tmp185
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm1, xmm9	# vect__47.189, vect__44.187
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm14, xmm14, 0	# tmp191
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	shufps	xmm12, xmm12, 0	# tmp200
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm7, xmm4	# vect__30.175, vect__20.169
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm8, xmm8, 0	# tmp209
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm14, xmm3	# vect__27.173, vect__18.166
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm6	# vect__58.197, vect__55.195
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 64[rsp], xmm4	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
.LVL113:
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm12, xmm3	# vect__38.182, vect__18.166
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm8, xmm3	# vect__49.190, vect__18.166
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm14, xmm10	# vect__28.174, vect__25.172
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	mulps	xmm3, xmm5	# vect__60.198, tmp185
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm12	# vect__39.183, vect__38.182
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm7, xmm5	# vect__30.175, tmp185
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm1, xmm8	# vect__50.191, vect__49.190
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm3	# vect__61.199, vect__60.198
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm14, xmm7	# vect__31.176, vect__30.175
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm7	# vect__42.184, vect__30.175
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm1, xmm7	# vect__53.192, vect__30.175
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movups	XMMWORD PTR [rbx], xmm14	# MEM[(float *)mat_3(D)], vect__31.176
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm4	# vect__64.200, vect__20.169
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movups	XMMWORD PTR 16[rbx], xmm2	# MEM[(float *)mat_3(D) + 16B], vect__42.184
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movups	XMMWORD PTR 32[rbx], xmm1	# MEM[(float *)mat_3(D) + 32B], vect__53.192
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movups	XMMWORD PTR 48[rbx], xmm0	# MEM[(float *)mat_3(D) + 48B], vect__64.200
.LVL114:
.LBE28:
.LBE39:
# src/Mat4.c:228: }
	.loc 1 228 0
	jne	.L35	#,
	add	rsp, 104	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 16
.LVL115:
	pop	rbp	#
	.cfi_def_cfa_offset 8
.LVL116:
	ret
.LVL117:
.L35:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL118:
	.cfi_endproc
.LFE40:
	.size	rotateMat4, .-rotateMat4
	.p2align 4,,15
	.globl	rotateXMat4
	.type	rotateXMat4, @function
rotateXMat4:
.LFB41:
	.loc 1 231 0
	.cfi_startproc
.LVL119:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# mat, mat
	sub	rsp, 96	#,
	.cfi_def_cfa_offset 112
.LBB46:
.LBB47:
# src/Mat4.c:102:     const float radians = TO_RAD(degrees);
	.loc 1 102 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp127,
.LVL120:
	lea	rdi, 12[rsp]	# tmp125,
.LVL121:
	lea	rsi, 8[rsp]	# tmp126,
.LBE47:
.LBE46:
# src/Mat4.c:231: {
	.loc 1 231 0
	mov	rax, QWORD PTR fs:40	# tmp165,
	mov	QWORD PTR 88[rsp], rax	# D.4898, tmp165
	xor	eax, eax	# tmp165
.LVL122:
.LBB51:
.LBB48:
# src/Mat4.c:102:     const float radians = TO_RAD(degrees);
	.loc 1 102 0
	divss	xmm0, DWORD PTR .LC6[rip]	# radians,
	call	sincosf@PLT	#
.LVL123:
.LBE48:
.LBE51:
.LBB52:
.LBB53:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm0, XMMWORD PTR [rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
.LBE53:
.LBE52:
# src/Mat4.c:234: }
	.loc 1 234 0
	mov	rdx, QWORD PTR 88[rsp]	# tmp166, D.4898
	xor	rdx, QWORD PTR fs:40	# tmp166,
.LBB57:
.LBB54:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm4, XMMWORD PTR 16[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:191:         c[0] = d[i];
	.loc 1 191 0
	movaps	xmm2, xmm0	# vect__12.207, MEM[(void *)mat_3(D)]
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 16[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	pxor	xmm0, xmm0	# tmp138
	movaps	xmm7, xmm4	# vect__22.217, vect__14.210
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 32[rsp], xmm4	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm7, xmm0	# vect__22.217, tmp138
	movss	xmm10, DWORD PTR 12[rsp]	# sincostmp_9,
.LVL124:
.LBE54:
.LBE57:
.LBB58:
.LBB49:
# src/Mat4.c:116:     mat->data[ 9] = -s;
	.loc 1 116 0
	movaps	xmm1, xmm10	# _68, sincostmp_9
.LBE49:
.LBE58:
.LBB59:
.LBB55:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm3, XMMWORD PTR 32[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm11, xmm7	# vect__23.218, vect__22.217
.LBE55:
.LBE59:
.LBB60:
.LBB50:
# src/Mat4.c:116:     mat->data[ 9] = -s;
	.loc 1 116 0
	xorps	xmm1, XMMWORD PTR .LC8[rip]	# _68,
.LVL125:
.LBE50:
.LBE60:
.LBB61:
.LBB56:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm6, xmm3	# vect__25.219, vect__16.213
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm5, XMMWORD PTR 48[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm6, xmm0	# vect__25.219, tmp138
	addps	xmm11, xmm2	# vect__23.218, vect__12.207
	movss	xmm9, DWORD PTR 8[rsp]	# tmp137,
	shufps	xmm9, xmm9, 0	# tmp137
	movaps	xmm8, xmm5	# vect__28.221, vect__18.216
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm1, xmm1, 0	# tmp151
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm8, xmm0	# vect__28.221, tmp138
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 48[rsp], xmm3	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm0, xmm2	# vect__31.225, vect__12.207
	movaps	xmm2, xmm9	# vect__33.226, tmp137
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm1, xmm4	# vect__44.233, vect__14.210
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm11, xmm6	# vect__26.220, vect__25.219
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 64[rsp], xmm5	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
.LVL126:
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm2, xmm4	# vect__33.226, vect__14.210
	shufps	xmm10, xmm10, 0	# tmp147
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm1, xmm0	# vect__45.234, vect__31.225
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm0	# vect__34.227, vect__31.225
	mulps	xmm10, xmm3	# vect__36.228, vect__16.213
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm7	# vect__56.240, vect__22.217
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm3, xmm9	# vect__47.235, tmp137
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm11, xmm8	# vect__29.222, vect__28.221
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm10	# vect__37.229, vect__36.228
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm1, xmm3	# vect__48.236, vect__47.235
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movups	XMMWORD PTR [rbx], xmm11	# MEM[(float *)mat_3(D)], vect__29.222
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm6	# vect__59.241, vect__25.219
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm8	# vect__40.230, vect__28.221
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm1, xmm8	# vect__51.237, vect__28.221
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm5	# vect__62.242, vect__18.216
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movups	XMMWORD PTR 16[rbx], xmm2	# MEM[(float *)mat_3(D) + 16B], vect__40.230
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movups	XMMWORD PTR 32[rbx], xmm1	# MEM[(float *)mat_3(D) + 32B], vect__51.237
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movups	XMMWORD PTR 48[rbx], xmm0	# MEM[(float *)mat_3(D) + 48B], vect__62.242
.LVL127:
.LBE56:
.LBE61:
# src/Mat4.c:234: }
	.loc 1 234 0
	jne	.L39	#,
	add	rsp, 96	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL128:
	ret
.LVL129:
.L39:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL130:
	.cfi_endproc
.LFE41:
	.size	rotateXMat4, .-rotateXMat4
	.p2align 4,,15
	.globl	rotateYMat4
	.type	rotateYMat4, @function
rotateYMat4:
.LFB42:
	.loc 1 237 0
	.cfi_startproc
.LVL131:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# mat, mat
	sub	rsp, 96	#,
	.cfi_def_cfa_offset 112
.LBB68:
.LBB69:
# src/Mat4.c:130:     const float radians = TO_RAD(degrees);
	.loc 1 130 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp127,
.LVL132:
	lea	rdi, 12[rsp]	# tmp125,
.LVL133:
	lea	rsi, 8[rsp]	# tmp126,
.LBE69:
.LBE68:
# src/Mat4.c:237: {
	.loc 1 237 0
	mov	rax, QWORD PTR fs:40	# tmp165,
	mov	QWORD PTR 88[rsp], rax	# D.4958, tmp165
	xor	eax, eax	# tmp165
.LVL134:
.LBB72:
.LBB70:
# src/Mat4.c:130:     const float radians = TO_RAD(degrees);
	.loc 1 130 0
	divss	xmm0, DWORD PTR .LC6[rip]	# radians,
	call	sincosf@PLT	#
.LVL135:
	movss	xmm0, DWORD PTR 12[rsp]	# sincostmp_9,
.LVL136:
	movss	xmm8, DWORD PTR 8[rsp]	# tmp137,
# src/Mat4.c:135:     mat->data[ 2] = -s;
	.loc 1 135 0
	movaps	xmm10, xmm0	# _68, sincostmp_9
	shufps	xmm8, xmm8, 0	# tmp137
.LBE70:
.LBE72:
.LBB73:
.LBB74:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm1, XMMWORD PTR 16[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	pxor	xmm3, xmm3	# tmp138
.LBE74:
.LBE73:
.LBB77:
.LBB71:
# src/Mat4.c:135:     mat->data[ 2] = -s;
	.loc 1 135 0
	xorps	xmm10, XMMWORD PTR .LC8[rip]	# _68,
.LVL137:
.LBE71:
.LBE77:
.LBB78:
.LBB75:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm9, XMMWORD PTR [rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm6, xmm1	# vect__22.260, vect__14.252
	movaps	xmm2, xmm8	# vect__20.259, tmp137
	mulps	xmm6, xmm3	# vect__22.260, tmp138
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm5, XMMWORD PTR 32[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
.LBE75:
.LBE78:
# src/Mat4.c:240: }
	.loc 1 240 0
	mov	rdx, QWORD PTR 88[rsp]	# tmp166, D.4958
	xor	rdx, QWORD PTR fs:40	# tmp166,
.LBB79:
.LBB76:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm2, xmm9	# vect__20.259, vect__12.249
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm4, XMMWORD PTR 48[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm10, xmm10, 0	# tmp142
	movaps	xmm7, xmm4	# vect__28.264, vect__18.258
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	shufps	xmm0, xmm0, 0	# tmp151
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 48[rsp], xmm5	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm10, xmm5	# vect__25.262, vect__16.255
	addps	xmm2, xmm6	# vect__23.261, vect__22.260
	mulps	xmm7, xmm3	# vect__28.264, tmp138
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 32[rsp], xmm1	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm0, xmm9	# vect__42.275, vect__12.249
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 16[rsp], xmm9	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm2, xmm10	# vect__26.263, vect__25.262
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 64[rsp], xmm4	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
.LVL138:
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm0, xmm6	# vect__45.276, vect__22.260
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm2, xmm7	# vect__29.265, vect__28.264
	movups	XMMWORD PTR [rbx], xmm2	# MEM[(float *)mat_3(D)], vect__29.265
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movaps	xmm2, xmm9	# vect__31.268, vect__12.249
	mulps	xmm2, xmm3	# vect__31.268, tmp138
	mulps	xmm3, xmm5	# vect__36.270, vect__16.255
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm5, xmm8	# vect__47.277, tmp137
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm1, xmm2	# vect__34.269, vect__31.268
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm2, xmm6	# vect__31.268, vect__22.260
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm0, xmm5	# vect__48.278, vect__47.277
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm1, xmm3	# vect__37.271, vect__36.270
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm0, xmm7	# vect__51.279, vect__28.264
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm1, xmm7	# vect__40.272, vect__28.264
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movups	XMMWORD PTR 32[rbx], xmm0	# MEM[(float *)mat_3(D) + 32B], vect__51.279
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movaps	xmm0, xmm2	# vect__56.282, vect__31.268
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movups	XMMWORD PTR 16[rbx], xmm1	# MEM[(float *)mat_3(D) + 16B], vect__40.272
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm3	# vect__59.283, vect__36.270
	addps	xmm0, xmm4	# vect__62.284, vect__18.258
	movups	XMMWORD PTR 48[rbx], xmm0	# MEM[(float *)mat_3(D) + 48B], vect__62.284
.LVL139:
.LBE76:
.LBE79:
# src/Mat4.c:240: }
	.loc 1 240 0
	jne	.L43	#,
	add	rsp, 96	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL140:
	ret
.LVL141:
.L43:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL142:
	.cfi_endproc
.LFE42:
	.size	rotateYMat4, .-rotateYMat4
	.p2align 4,,15
	.globl	rotateZMat4
	.type	rotateZMat4, @function
rotateZMat4:
.LFB43:
	.loc 1 243 0
	.cfi_startproc
.LVL143:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	mov	rbx, rdi	# mat, mat
	sub	rsp, 96	#,
	.cfi_def_cfa_offset 112
.LBB86:
.LBB87:
# src/Mat4.c:158:     const float radians = TO_RAD(degrees);
	.loc 1 158 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp126,
.LVL144:
	lea	rdi, 12[rsp]	# tmp124,
.LVL145:
	lea	rsi, 8[rsp]	# tmp125,
.LBE87:
.LBE86:
# src/Mat4.c:243: {
	.loc 1 243 0
	mov	rax, QWORD PTR fs:40	# tmp164,
	mov	QWORD PTR 88[rsp], rax	# D.5017, tmp164
	xor	eax, eax	# tmp164
.LVL146:
.LBB90:
.LBB88:
# src/Mat4.c:158:     const float radians = TO_RAD(degrees);
	.loc 1 158 0
	divss	xmm0, DWORD PTR .LC6[rip]	# radians,
	call	sincosf@PLT	#
.LVL147:
	movss	xmm2, DWORD PTR 8[rsp]	# tmp136,
	shufps	xmm2, xmm2, 0	# tmp136
	movss	xmm1, DWORD PTR 12[rsp]	# sincostmp_9,
.LVL148:
# src/Mat4.c:166:     mat->data[ 4] = -s;
	.loc 1 166 0
	movaps	xmm9, xmm1	# _68, sincostmp_9
.LBE88:
.LBE90:
.LBB91:
.LBB92:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	shufps	xmm1, xmm1, 0	# tmp139
.LVL149:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm4, XMMWORD PTR [rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm10, xmm2	# vect__20.301, tmp136
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm0, XMMWORD PTR 16[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	pxor	xmm8, xmm8	# tmp137
	mulps	xmm10, xmm4	# vect__20.301, vect__12.291
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm3, XMMWORD PTR 32[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	mulps	xmm1, xmm0	# vect__22.302, vect__14.294
	movaps	xmm6, xmm3	# vect__25.304, vect__16.297
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movdqu	xmm5, XMMWORD PTR 48[rbx]	# MEM[(void *)mat_3(D)], MEM[(void *)mat_3(D)]
.LBE92:
.LBE91:
.LBB95:
.LBB89:
# src/Mat4.c:166:     mat->data[ 4] = -s;
	.loc 1 166 0
	xorps	xmm9, XMMWORD PTR .LC8[rip]	# _68,
.LVL150:
.LBE89:
.LBE95:
.LBB96:
.LBB93:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	movaps	xmm7, xmm5	# vect__28.306, vect__18.300
	mulps	xmm6, xmm8	# vect__25.304, tmp137
	addps	xmm1, xmm10	# vect__23.303, vect__20.301
	mulps	xmm7, xmm8	# vect__28.306, tmp137
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 16[rsp], xmm4	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	mulps	xmm2, xmm0	# vect__33.311, vect__14.294
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 32[rsp], xmm0	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm1, xmm6	# vect__26.305, vect__25.304
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm0, xmm8	# vect__44.318, tmp137
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 48[rsp], xmm3	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
.LBE93:
.LBE96:
# src/Mat4.c:246: }
	.loc 1 246 0
	mov	rdx, QWORD PTR 88[rsp]	# tmp165, D.5017
	xor	rdx, QWORD PTR fs:40	# tmp165,
.LBB97:
.LBB94:
# src/Mat4.c:189:     memcpy(d, dest->data, MAT4_SIZE);
	.loc 1 189 0
	movaps	XMMWORD PTR 64[rsp], xmm5	# MEM[(void *)&d], MEM[(void *)mat_3(D)]
.LVL151:
# src/Mat4.c:196:         dest->data[i]       = c[0] * r[ 0] + c[1] * r[ 1] + c[2] * r[ 2] + c[3] * r[ 3];
	.loc 1 196 0
	addps	xmm1, xmm7	# vect__29.307, vect__28.306
	movups	XMMWORD PTR [rbx], xmm1	# MEM[(float *)mat_3(D)], vect__29.307
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movaps	xmm1, xmm9	# tmp146, _68
	shufps	xmm1, xmm1, 0	# tmp146
	mulps	xmm1, xmm4	# vect__31.310, vect__12.291
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	mulps	xmm4, xmm8	# vect__42.317, tmp137
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm1	# vect__34.312, vect__31.310
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm0, xmm4	# vect__45.319, vect__42.317
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm6	# vect__37.313, vect__25.304
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm3, xmm0	# vect__48.320, vect__45.319
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm6	# vect__59.324, vect__25.304
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	addps	xmm2, xmm7	# vect__40.314, vect__28.306
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	addps	xmm7, xmm3	# vect__51.321, vect__48.320
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	addps	xmm0, xmm5	# vect__62.325, vect__18.300
# src/Mat4.c:197:         dest->data[i + 0x4] = c[0] * r[ 4] + c[1] * r[ 5] + c[2] * r[ 6] + c[3] * r[ 7];
	.loc 1 197 0
	movups	XMMWORD PTR 16[rbx], xmm2	# MEM[(float *)mat_3(D) + 16B], vect__40.314
# src/Mat4.c:198:         dest->data[i + 0x8] = c[0] * r[ 8] + c[1] * r[ 9] + c[2] * r[10] + c[3] * r[11];
	.loc 1 198 0
	movups	XMMWORD PTR 32[rbx], xmm7	# MEM[(float *)mat_3(D) + 32B], vect__51.321
# src/Mat4.c:199:         dest->data[i + 0xc] = c[0] * r[12] + c[1] * r[13] + c[2] * r[14] + c[3] * r[15];
	.loc 1 199 0
	movups	XMMWORD PTR 48[rbx], xmm0	# MEM[(float *)mat_3(D) + 48B], vect__62.325
.LVL152:
.LBE94:
.LBE97:
# src/Mat4.c:246: }
	.loc 1 246 0
	jne	.L47	#,
	add	rsp, 96	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL153:
	ret
.LVL154:
.L47:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL155:
	.cfi_endproc
.LFE43:
	.size	rotateZMat4, .-rotateZMat4
	.p2align 4,,15
	.globl	setPerspectiveMat4
	.type	setPerspectiveMat4, @function
setPerspectiveMat4:
.LFB44:
	.loc 1 249 0
	.cfi_startproc
.LVL156:
	push	rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# src/Mat4.c:250:     float rdist = 1.0f / (far - near);
	.loc 1 250 0
	movaps	xmm5, xmm3	# tmp110, far
# src/Mat4.c:249: {
	.loc 1 249 0
	mov	rbx, rdi	# mat, mat
	sub	rsp, 32	#,
	.cfi_def_cfa_offset 48
# src/Mat4.c:250:     float rdist = 1.0f / (far - near);
	.loc 1 250 0
	subss	xmm5, xmm2	# tmp110, near
# src/Mat4.c:252:     float rad = PI * fov / 180.0f / 2.0f;
	.loc 1 252 0
	mulss	xmm0, DWORD PTR .LC5[rip]	# tmp114,
.LVL157:
# src/Mat4.c:250:     float rdist = 1.0f / (far - near);
	.loc 1 250 0
	movss	xmm4, DWORD PTR .LC4[rip]	# tmp111,
	lea	rdi, 28[rsp]	# tmp112,
.LVL158:
	lea	rsi, 24[rsp]	# tmp113,
# src/Mat4.c:249: {
	.loc 1 249 0
	movss	DWORD PTR 20[rsp], xmm1	# %sfp, aspect
# src/Mat4.c:250:     float rdist = 1.0f / (far - near);
	.loc 1 250 0
	movss	DWORD PTR 16[rsp], xmm3	# %sfp, far
	divss	xmm4, xmm5	# rdist, tmp110
	movss	DWORD PTR 12[rsp], xmm2	# %sfp, near
# src/Mat4.c:252:     float rad = PI * fov / 180.0f / 2.0f;
	.loc 1 252 0
	divss	xmm0, DWORD PTR .LC6[rip]	# tmp116,
# src/Mat4.c:250:     float rdist = 1.0f / (far - near);
	.loc 1 250 0
	movss	DWORD PTR 8[rsp], xmm4	# %sfp, rdist
.LVL159:
# src/Mat4.c:252:     float rad = PI * fov / 180.0f / 2.0f;
	.loc 1 252 0
	mulss	xmm0, DWORD PTR .LC9[rip]	# rad,
	call	sincosf@PLT	#
.LVL160:
# src/Mat4.c:253:     float cot = cosf(rad) / sinf(rad);
	.loc 1 253 0
	movss	xmm0, DWORD PTR 24[rsp]	# sincostmp_38,
# src/Mat4.c:268:     mat->data[11] = -1.0f;
	.loc 1 268 0
	mov	eax, 3212836864	# tmp134,
# src/Mat4.c:253:     float cot = cosf(rad) / sinf(rad);
	.loc 1 253 0
	divss	xmm0, DWORD PTR 28[rsp]	# cot,
.LVL161:
# src/Mat4.c:255:     mat->data[ 0] = cot / aspect;
	.loc 1 255 0
	movss	xmm1, DWORD PTR 20[rsp]	# aspect, %sfp
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	movss	xmm3, DWORD PTR 16[rsp]	# far, %sfp
# src/Mat4.c:268:     mat->data[11] = -1.0f;
	.loc 1 268 0
	mov	QWORD PTR 44[rbx], rax	# MEM[(float *)mat_21(D) + 44B], tmp134
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	movss	xmm2, DWORD PTR 12[rsp]	# near, %sfp
# src/Mat4.c:256:     mat->data[ 1] = 0.0f;
	.loc 1 256 0
	mov	QWORD PTR 4[rbx], 0	# MEM[(float *)mat_21(D) + 4B],
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	movss	xmm4, DWORD PTR 8[rsp]	# rdist, %sfp
# src/Mat4.c:257:     mat->data[ 2] = 0.0f;
	.loc 1 257 0
	mov	QWORD PTR 12[rbx], 0	# MEM[(float *)mat_21(D) + 12B],
# src/Mat4.c:262:     mat->data[ 6] = 0.0f;
	.loc 1 262 0
	mov	QWORD PTR 24[rbx], 0	# MEM[(float *)mat_21(D) + 24B],
# src/Mat4.c:263:     mat->data[ 7] = 0.0f;
	.loc 1 263 0
	mov	QWORD PTR 32[rbx], 0	# MEM[(float *)mat_21(D) + 32B],
# src/Mat4.c:276: }
	.loc 1 276 0
	mov	rax, rbx	#, mat
# src/Mat4.c:270:     mat->data[12] = 0.0f;
	.loc 1 270 0
	mov	DWORD PTR 52[rbx], 0	# MEM[(float *)mat_21(D) + 52B],
# src/Mat4.c:273:     mat->data[15] = 0.0f;
	.loc 1 273 0
	mov	DWORD PTR 60[rbx], 0x00000000	# mat_21(D)->data,
# src/Mat4.c:255:     mat->data[ 0] = cot / aspect;
	.loc 1 255 0
	movaps	xmm6, xmm0	# tmp120, cot
# src/Mat4.c:261:     mat->data[ 5] = cot;
	.loc 1 261 0
	movss	DWORD PTR 20[rbx], xmm0	# mat_21(D)->data, cot
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	movaps	xmm0, xmm3	# tmp121, far
.LVL162:
# src/Mat4.c:255:     mat->data[ 0] = cot / aspect;
	.loc 1 255 0
	divss	xmm6, xmm1	# tmp120, aspect
.LVL163:
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	addss	xmm0, xmm2	# tmp121, near
# src/Mat4.c:272:     mat->data[14] = -2 * near * far * rdist;
	.loc 1 272 0
	mulss	xmm2, DWORD PTR .LC10[rip]	# tmp125,
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	xorps	xmm0, XMMWORD PTR .LC8[rip]	# tmp122,
# src/Mat4.c:255:     mat->data[ 0] = cot / aspect;
	.loc 1 255 0
	movss	DWORD PTR [rbx], xmm6	# mat_21(D)->data, tmp120
# src/Mat4.c:272:     mat->data[14] = -2 * near * far * rdist;
	.loc 1 272 0
	mulss	xmm2, xmm3	# tmp127, far
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	mulss	xmm0, xmm4	# tmp124, rdist
# src/Mat4.c:272:     mat->data[14] = -2 * near * far * rdist;
	.loc 1 272 0
	mulss	xmm2, xmm4	# tmp128, rdist
# src/Mat4.c:267:     mat->data[10] = -(far + near) * rdist;
	.loc 1 267 0
	movss	DWORD PTR 40[rbx], xmm0	# mat_21(D)->data, tmp124
# src/Mat4.c:272:     mat->data[14] = -2 * near * far * rdist;
	.loc 1 272 0
	movss	DWORD PTR 56[rbx], xmm2	# mat_21(D)->data, tmp128
# src/Mat4.c:276: }
	.loc 1 276 0
	add	rsp, 32	#,
	.cfi_def_cfa_offset 16
	pop	rbx	#
	.cfi_def_cfa_offset 8
.LVL164:
	ret
	.cfi_endproc
.LFE44:
	.size	setPerspectiveMat4, .-setPerspectiveMat4
	.p2align 4,,15
	.globl	setLookAtMat4
	.type	setLookAtMat4, @function
setLookAtMat4:
.LFB45:
	.loc 1 279 0
	.cfi_startproc
.LVL165:
	push	r13	#
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	push	r12	#
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	mov	r12, rsi	# pos, pos
	push	rbp	#
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	push	rbx	#
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	mov	rbx, rdi	# mat, mat
# src/Mat4.c:284:     forward = vec3copy(tar);
	.loc 1 284 0
	mov	rdi, rdx	#, tar
.LVL166:
# src/Mat4.c:279: {
	.loc 1 279 0
	mov	r13, rcx	# up, up
	sub	rsp, 72	#,
	.cfi_def_cfa_offset 112
# src/Mat4.c:285:     forward = vec3copySub(&forward, pos);
	.loc 1 285 0
	mov	rbp, rsp	# tmp106,
# src/Mat4.c:279: {
	.loc 1 279 0
	mov	rax, QWORD PTR fs:40	# tmp142,
	mov	QWORD PTR 56[rsp], rax	# D.5030, tmp142
	xor	eax, eax	# tmp142
# src/Mat4.c:284:     forward = vec3copy(tar);
	.loc 1 284 0
	call	vec3copy@PLT	#
.LVL167:
# src/Mat4.c:285:     forward = vec3copySub(&forward, pos);
	.loc 1 285 0
	mov	rsi, r12	#, pos
	mov	rdi, rbp	#, tmp106
# src/Mat4.c:284:     forward = vec3copy(tar);
	.loc 1 284 0
	movq	QWORD PTR [rsp], xmm0	# forward, tmp104
	movss	DWORD PTR 8[rsp], xmm1	# forward,
# src/Mat4.c:289:     side = vec3copyCross(&side, up);
	.loc 1 289 0
	lea	r12, 16[rsp]	# tmp113,
.LVL168:
# src/Mat4.c:285:     forward = vec3copySub(&forward, pos);
	.loc 1 285 0
	call	vec3copySub@PLT	#
.LVL169:
# src/Mat4.c:286:     vec3normalize(&forward);
	.loc 1 286 0
	mov	rdi, rbp	#, tmp106
# src/Mat4.c:285:     forward = vec3copySub(&forward, pos);
	.loc 1 285 0
	movq	QWORD PTR [rsp], xmm0	# forward, tmp107
	movss	DWORD PTR 8[rsp], xmm1	# forward,
# src/Mat4.c:286:     vec3normalize(&forward);
	.loc 1 286 0
	call	vec3normalize@PLT	#
.LVL170:
# src/Mat4.c:288:     side = vec3copy(&forward);
	.loc 1 288 0
	mov	rdi, rbp	#, tmp106
	call	vec3copy@PLT	#
.LVL171:
# src/Mat4.c:289:     side = vec3copyCross(&side, up);
	.loc 1 289 0
	mov	rsi, r13	#, up
	mov	rdi, r12	#, tmp113
# src/Mat4.c:288:     side = vec3copy(&forward);
	.loc 1 288 0
	movq	QWORD PTR 16[rsp], xmm0	# side, tmp111
	movss	DWORD PTR 24[rsp], xmm1	# side,
# src/Mat4.c:289:     side = vec3copyCross(&side, up);
	.loc 1 289 0
	call	vec3copyCross@PLT	#
.LVL172:
# src/Mat4.c:290:     vec3normalize(&side);
	.loc 1 290 0
	mov	rdi, r12	#, tmp113
# src/Mat4.c:289:     side = vec3copyCross(&side, up);
	.loc 1 289 0
	movq	QWORD PTR 16[rsp], xmm0	# side, tmp114
	movss	DWORD PTR 24[rsp], xmm1	# side,
# src/Mat4.c:290:     vec3normalize(&side);
	.loc 1 290 0
	call	vec3normalize@PLT	#
.LVL173:
# src/Mat4.c:292:     top = vec3copy(&side);
	.loc 1 292 0
	mov	rdi, r12	#, tmp113
	call	vec3copy@PLT	#
.LVL174:
# src/Mat4.c:293:     top = vec3copyCross(&top, &forward);
	.loc 1 293 0
	lea	rdi, 32[rsp]	# tmp121,
	mov	rsi, rbp	#, tmp106
# src/Mat4.c:292:     top = vec3copy(&side);
	.loc 1 292 0
	movq	QWORD PTR 32[rsp], xmm0	# top, tmp118
	movss	DWORD PTR 40[rsp], xmm1	# top,
# src/Mat4.c:293:     top = vec3copyCross(&top, &forward);
	.loc 1 293 0
	call	vec3copyCross@PLT	#
.LVL175:
	movq	QWORD PTR 32[rsp], xmm0	# top, tmp122
# src/Mat4.c:297:     mat->data[ 2] = -forward.x;
	.loc 1 297 0
	movss	xmm2, DWORD PTR .LC8[rip]	# tmp128,
# src/Mat4.c:298:     mat->data[ 3] = 0.0f;
	.loc 1 298 0
	mov	DWORD PTR 12[rbx], 0x00000000	# mat_25(D)->data,
# src/Mat4.c:295:     mat->data[ 0] = side.x;
	.loc 1 295 0
	movss	xmm0, DWORD PTR 16[rsp]	# side.x, side.x
# src/Mat4.c:303:     mat->data[ 7] = 0.0f;
	.loc 1 303 0
	mov	DWORD PTR 28[rbx], 0x00000000	# mat_25(D)->data,
# src/Mat4.c:295:     mat->data[ 0] = side.x;
	.loc 1 295 0
	movss	DWORD PTR [rbx], xmm0	# mat_25(D)->data, side.x
# src/Mat4.c:308:     mat->data[11] = 0.0f;
	.loc 1 308 0
	mov	QWORD PTR 44[rbx], 0	# MEM[(float *)mat_25(D) + 44B],
# src/Mat4.c:296:     mat->data[ 1] = top.x;
	.loc 1 296 0
	movss	xmm0, DWORD PTR 32[rsp]	# top.x, top.x
# src/Mat4.c:310:     mat->data[12] = 0.0f;
	.loc 1 310 0
	mov	QWORD PTR 52[rbx], 0	# MEM[(float *)mat_25(D) + 52B],
# src/Mat4.c:296:     mat->data[ 1] = top.x;
	.loc 1 296 0
	movss	DWORD PTR 4[rbx], xmm0	# mat_25(D)->data, top.x
# src/Mat4.c:312:     mat->data[14] = 0.0f;
	.loc 1 312 0
	mov	DWORD PTR 60[rbx], 1065353216	# MEM[(float *)mat_25(D) + 60B],
# src/Mat4.c:297:     mat->data[ 2] = -forward.x;
	.loc 1 297 0
	movss	xmm0, DWORD PTR [rsp]	# forward.x, forward.x
	xorps	xmm0, xmm2	# tmp126, tmp128
# src/Mat4.c:293:     top = vec3copyCross(&top, &forward);
	.loc 1 293 0
	movss	DWORD PTR 40[rsp], xmm1	# top, tmp123
# src/Mat4.c:315: }
	.loc 1 315 0
	mov	rcx, QWORD PTR 56[rsp]	# tmp143, D.5030
	xor	rcx, QWORD PTR fs:40	# tmp143,
# src/Mat4.c:306:     mat->data[ 9] = top.z;
	.loc 1 306 0
	movss	DWORD PTR 36[rbx], xmm1	# mat_25(D)->data, tmp123
# src/Mat4.c:297:     mat->data[ 2] = -forward.x;
	.loc 1 297 0
	movss	DWORD PTR 8[rbx], xmm0	# mat_25(D)->data, tmp126
# src/Mat4.c:300:     mat->data[ 4] = side.y;
	.loc 1 300 0
	movss	xmm0, DWORD PTR 20[rsp]	# side.y, side.y
	movss	DWORD PTR 16[rbx], xmm0	# mat_25(D)->data, side.y
# src/Mat4.c:301:     mat->data[ 5] = top.y;
	.loc 1 301 0
	movss	xmm0, DWORD PTR 36[rsp]	# top.y, top.y
	movss	DWORD PTR 20[rbx], xmm0	# mat_25(D)->data, top.y
# src/Mat4.c:302:     mat->data[ 6] = -forward.y;
	.loc 1 302 0
	movss	xmm0, DWORD PTR 4[rsp]	# forward.y, forward.y
	xorps	xmm0, xmm2	# tmp132, tmp128
	movss	DWORD PTR 24[rbx], xmm0	# mat_25(D)->data, tmp132
# src/Mat4.c:305:     mat->data[ 8] = side.z;
	.loc 1 305 0
	movss	xmm0, DWORD PTR 24[rsp]	# side.z, side.z
	movss	DWORD PTR 32[rbx], xmm0	# mat_25(D)->data, side.z
# src/Mat4.c:307:     mat->data[10] = -forward.z;
	.loc 1 307 0
	movss	xmm0, DWORD PTR 8[rsp]	# forward.z, forward.z
	xorps	xmm0, xmm2	# tmp138, tmp128
	movss	DWORD PTR 40[rbx], xmm0	# mat_25(D)->data, tmp138
# src/Mat4.c:315: }
	.loc 1 315 0
	jne	.L53	#,
	add	rsp, 72	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 32
.LVL176:
	pop	rbp	#
	.cfi_def_cfa_offset 24
	pop	r12	#
	.cfi_def_cfa_offset 16
	pop	r13	#
	.cfi_def_cfa_offset 8
.LVL177:
	ret
.LVL178:
.L53:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL179:
	.cfi_endproc
.LFE45:
	.size	setLookAtMat4, .-setLookAtMat4
	.p2align 4,,15
	.globl	setLookAtMat4FP
	.type	setLookAtMat4FP, @function
setLookAtMat4FP:
.LFB46:
	.loc 1 318 0
	.cfi_startproc
.LVL180:
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	mov	r14, rdx	# up, up
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	mov	r13, rsi	# tar, tar
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	mov	rbx, rdi	# mat, mat
	sub	rsp, 64	#,
	.cfi_def_cfa_offset 112
# src/Mat4.c:320:     vec3normalize(vec3set(&n, tar));
	.loc 1 320 0
	mov	r12, rsp	# tmp104,
# src/Mat4.c:321:     vec3normalize(vec3cross(vec3set(&u, up), tar));
	.loc 1 321 0
	lea	rbp, 16[rsp]	# tmp105,
# src/Mat4.c:320:     vec3normalize(vec3set(&n, tar));
	.loc 1 320 0
	mov	rdi, r12	#, tmp104
.LVL181:
# src/Mat4.c:318: {
	.loc 1 318 0
	mov	rax, QWORD PTR fs:40	# tmp121,
	mov	QWORD PTR 56[rsp], rax	# D.5033, tmp121
	xor	eax, eax	# tmp121
# src/Mat4.c:320:     vec3normalize(vec3set(&n, tar));
	.loc 1 320 0
	call	vec3set@PLT	#
.LVL182:
	mov	rdi, rax	#, _1
	call	vec3normalize@PLT	#
.LVL183:
# src/Mat4.c:321:     vec3normalize(vec3cross(vec3set(&u, up), tar));
	.loc 1 321 0
	mov	rsi, r14	#, up
	mov	rdi, rbp	#, tmp105
	call	vec3set@PLT	#
.LVL184:
	mov	rsi, r13	#, tar
	mov	rdi, rax	#, _2
	call	vec3cross@PLT	#
.LVL185:
	mov	rdi, rax	#, _3
	call	vec3normalize@PLT	#
.LVL186:
# src/Mat4.c:322:     vec3cross(vec3set(&v, &n), &u);
	.loc 1 322 0
	lea	rdi, 32[rsp]	# tmp107,
	mov	rsi, r12	#, tmp104
	call	vec3set@PLT	#
.LVL187:
	mov	rsi, rbp	#, tmp105
	mov	rdi, rax	#, _4
	call	vec3cross@PLT	#
.LVL188:
# src/Mat4.c:324:     mat->data[ 0] = u.x;
	.loc 1 324 0
	movss	xmm0, DWORD PTR 16[rsp]	# u.x, u.x
# src/Mat4.c:327:     mat->data[ 3] = 0.0f;
	.loc 1 327 0
	mov	DWORD PTR 12[rbx], 0x00000000	# mat_24(D)->data,
# src/Mat4.c:324:     mat->data[ 0] = u.x;
	.loc 1 324 0
	movss	DWORD PTR [rbx], xmm0	# mat_24(D)->data, u.x
# src/Mat4.c:332:     mat->data[ 7] = 0.0f;
	.loc 1 332 0
	mov	DWORD PTR 28[rbx], 0x00000000	# mat_24(D)->data,
# src/Mat4.c:337:     mat->data[11] = 0.0f;
	.loc 1 337 0
	mov	QWORD PTR 44[rbx], 0	# MEM[(float *)mat_24(D) + 44B],
# src/Mat4.c:325:     mat->data[ 1] = u.y;
	.loc 1 325 0
	movss	xmm0, DWORD PTR 20[rsp]	# u.y, u.y
# src/Mat4.c:339:     mat->data[12] = 0.0f;
	.loc 1 339 0
	mov	QWORD PTR 52[rbx], 0	# MEM[(float *)mat_24(D) + 52B],
# src/Mat4.c:325:     mat->data[ 1] = u.y;
	.loc 1 325 0
	movss	DWORD PTR 4[rbx], xmm0	# mat_24(D)->data, u.y
# src/Mat4.c:341:     mat->data[14] = 0.0f;
	.loc 1 341 0
	mov	DWORD PTR 60[rbx], 1065353216	# MEM[(float *)mat_24(D) + 60B],
# src/Mat4.c:326:     mat->data[ 2] = u.z;
	.loc 1 326 0
	movss	xmm0, DWORD PTR 24[rsp]	# u.z, u.z
	movss	DWORD PTR 8[rbx], xmm0	# mat_24(D)->data, u.z
# src/Mat4.c:329:     mat->data[ 4] = v.x;
	.loc 1 329 0
	movss	xmm0, DWORD PTR 32[rsp]	# v.x, v.x
	movss	DWORD PTR 16[rbx], xmm0	# mat_24(D)->data, v.x
# src/Mat4.c:330:     mat->data[ 5] = v.y;
	.loc 1 330 0
	movss	xmm0, DWORD PTR 36[rsp]	# v.y, v.y
	movss	DWORD PTR 20[rbx], xmm0	# mat_24(D)->data, v.y
# src/Mat4.c:331:     mat->data[ 6] = v.z;
	.loc 1 331 0
	movss	xmm0, DWORD PTR 40[rsp]	# v.z, v.z
	movss	DWORD PTR 24[rbx], xmm0	# mat_24(D)->data, v.z
# src/Mat4.c:334:     mat->data[ 8] = n.x;
	.loc 1 334 0
	movss	xmm0, DWORD PTR [rsp]	# n.x, n.x
	movss	DWORD PTR 32[rbx], xmm0	# mat_24(D)->data, n.x
# src/Mat4.c:345: }
	.loc 1 345 0
	mov	rcx, QWORD PTR 56[rsp]	# tmp122, D.5033
	xor	rcx, QWORD PTR fs:40	# tmp122,
# src/Mat4.c:335:     mat->data[ 9] = n.y;
	.loc 1 335 0
	movss	xmm0, DWORD PTR 4[rsp]	# n.y, n.y
	movss	DWORD PTR 36[rbx], xmm0	# mat_24(D)->data, n.y
# src/Mat4.c:336:     mat->data[10] = n.z;
	.loc 1 336 0
	movss	xmm0, DWORD PTR 8[rsp]	# n.z, n.z
	movss	DWORD PTR 40[rbx], xmm0	# mat_24(D)->data, n.z
# src/Mat4.c:345: }
	.loc 1 345 0
	jne	.L57	#,
	add	rsp, 64	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 40
.LVL189:
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
	pop	r13	#
	.cfi_def_cfa_offset 16
.LVL190:
	pop	r14	#
	.cfi_def_cfa_offset 8
.LVL191:
	ret
.LVL192:
.L57:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL193:
	.cfi_endproc
.LFE46:
	.size	setLookAtMat4FP, .-setLookAtMat4FP
	.p2align 4,,15
	.globl	setCameraTransformMat4
	.type	setCameraTransformMat4, @function
setCameraTransformMat4:
.LFB47:
	.loc 1 348 0
	.cfi_startproc
.LVL194:
	push	r14	#
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	push	r13	#
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	mov	r14, rcx	# up, up
	push	r12	#
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	push	rbp	#
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	mov	r12, rsi	# pos, pos
	push	rbx	#
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
# src/Mat4.c:350:     vec3normalize(vec3sub(vec3set(&f, tar), pos));
	.loc 1 350 0
	mov	rsi, rdx	#, tar
.LVL195:
# src/Mat4.c:348: {
	.loc 1 348 0
	mov	rbx, rdi	# mat, mat
	sub	rsp, 80	#,
	.cfi_def_cfa_offset 128
# src/Mat4.c:350:     vec3normalize(vec3sub(vec3set(&f, tar), pos));
	.loc 1 350 0
	lea	rbp, 16[rsp]	# tmp114,
# src/Mat4.c:351:     vec3normalize(vec3cross(vec3set(&s, &f), up));
	.loc 1 351 0
	lea	r13, 32[rsp]	# tmp116,
# src/Mat4.c:348: {
	.loc 1 348 0
	mov	rax, QWORD PTR fs:40	# tmp147,
	mov	QWORD PTR 72[rsp], rax	# D.5036, tmp147
	xor	eax, eax	# tmp147
# src/Mat4.c:350:     vec3normalize(vec3sub(vec3set(&f, tar), pos));
	.loc 1 350 0
	mov	rdi, rbp	#, tmp114
.LVL196:
	call	vec3set@PLT	#
.LVL197:
	mov	rsi, r12	#, pos
	mov	rdi, rax	#, _1
	call	vec3sub@PLT	#
.LVL198:
	mov	rdi, rax	#, _2
	call	vec3normalize@PLT	#
.LVL199:
# src/Mat4.c:351:     vec3normalize(vec3cross(vec3set(&s, &f), up));
	.loc 1 351 0
	mov	rsi, rbp	#, tmp114
	mov	rdi, r13	#, tmp116
	call	vec3set@PLT	#
.LVL200:
	mov	rsi, r14	#, up
	mov	rdi, rax	#, _3
# src/Mat4.c:352:     vec3cross(vec3set(&u, &s), &f);
	.loc 1 352 0
	lea	r14, 48[rsp]	# tmp118,
.LVL201:
# src/Mat4.c:351:     vec3normalize(vec3cross(vec3set(&s, &f), up));
	.loc 1 351 0
	call	vec3cross@PLT	#
.LVL202:
	mov	rdi, rax	#, _4
	call	vec3normalize@PLT	#
.LVL203:
# src/Mat4.c:352:     vec3cross(vec3set(&u, &s), &f);
	.loc 1 352 0
	mov	rsi, r13	#, tmp116
	mov	rdi, r14	#, tmp118
	call	vec3set@PLT	#
.LVL204:
	mov	rsi, rbp	#, tmp114
	mov	rdi, rax	#, _5
	call	vec3cross@PLT	#
.LVL205:
# src/Mat4.c:354:     mat->data[ 0] = s.x;
	.loc 1 354 0
	movss	xmm0, DWORD PTR 32[rsp]	# s.x, s.x
# src/Mat4.c:356:     mat->data[ 2] = -f.x;
	.loc 1 356 0
	movss	xmm1, DWORD PTR .LC8[rip]	# tmp124,
# src/Mat4.c:354:     mat->data[ 0] = s.x;
	.loc 1 354 0
	movss	DWORD PTR [rbx], xmm0	# mat_35(D)->data, s.x
# src/Mat4.c:369:     mat->data[12] = -vec3dotProduct(&s, pos);
	.loc 1 369 0
	mov	rsi, r12	#, pos
	mov	rdi, r13	#, tmp116
# src/Mat4.c:355:     mat->data[ 1] = u.x;
	.loc 1 355 0
	movss	xmm0, DWORD PTR 48[rsp]	# u.x, u.x
# src/Mat4.c:357:     mat->data[ 3] = 0.0f;
	.loc 1 357 0
	mov	DWORD PTR 12[rbx], 0x00000000	# mat_35(D)->data,
# src/Mat4.c:355:     mat->data[ 1] = u.x;
	.loc 1 355 0
	movss	DWORD PTR 4[rbx], xmm0	# mat_35(D)->data, u.x
# src/Mat4.c:362:     mat->data[ 7] = 0.0f;
	.loc 1 362 0
	mov	DWORD PTR 28[rbx], 0x00000000	# mat_35(D)->data,
# src/Mat4.c:356:     mat->data[ 2] = -f.x;
	.loc 1 356 0
	movss	xmm0, DWORD PTR 16[rsp]	# f.x, f.x
# src/Mat4.c:367:     mat->data[11] = 0.0f;
	.loc 1 367 0
	mov	DWORD PTR 44[rbx], 0x00000000	# mat_35(D)->data,
# src/Mat4.c:356:     mat->data[ 2] = -f.x;
	.loc 1 356 0
	xorps	xmm0, xmm1	# tmp122, tmp124
# src/Mat4.c:366:     mat->data[10] = -f.z;
	.loc 1 366 0
	movaps	XMMWORD PTR [rsp], xmm1	# %sfp, tmp124
# src/Mat4.c:356:     mat->data[ 2] = -f.x;
	.loc 1 356 0
	movss	DWORD PTR 8[rbx], xmm0	# mat_35(D)->data, tmp122
# src/Mat4.c:359:     mat->data[ 4] = s.y;
	.loc 1 359 0
	movss	xmm0, DWORD PTR 36[rsp]	# s.y, s.y
	movss	DWORD PTR 16[rbx], xmm0	# mat_35(D)->data, s.y
# src/Mat4.c:360:     mat->data[ 5] = u.y;
	.loc 1 360 0
	movss	xmm0, DWORD PTR 52[rsp]	# u.y, u.y
	movss	DWORD PTR 20[rbx], xmm0	# mat_35(D)->data, u.y
# src/Mat4.c:361:     mat->data[ 6] = -f.y;
	.loc 1 361 0
	movss	xmm0, DWORD PTR 20[rsp]	# f.y, f.y
	xorps	xmm0, xmm1	# tmp128, tmp124
	movss	DWORD PTR 24[rbx], xmm0	# mat_35(D)->data, tmp128
# src/Mat4.c:364:     mat->data[ 8] = s.z;
	.loc 1 364 0
	movss	xmm0, DWORD PTR 40[rsp]	# s.z, s.z
	movss	DWORD PTR 32[rbx], xmm0	# mat_35(D)->data, s.z
# src/Mat4.c:365:     mat->data[ 9] = u.z;
	.loc 1 365 0
	movss	xmm0, DWORD PTR 56[rsp]	# u.z, u.z
	movss	DWORD PTR 36[rbx], xmm0	# mat_35(D)->data, u.z
# src/Mat4.c:366:     mat->data[10] = -f.z;
	.loc 1 366 0
	movss	xmm0, DWORD PTR 24[rsp]	# f.z, f.z
	xorps	xmm0, xmm1	# tmp134, tmp124
	movss	DWORD PTR 40[rbx], xmm0	# mat_35(D)->data, tmp134
# src/Mat4.c:369:     mat->data[12] = -vec3dotProduct(&s, pos);
	.loc 1 369 0
	call	vec3dot@PLT	#
.LVL206:
	movaps	xmm1, XMMWORD PTR [rsp]	# tmp124, %sfp
# src/Mat4.c:370:     mat->data[13] = -vec3dotProduct(&u, pos);
	.loc 1 370 0
	mov	rsi, r12	#, pos
	mov	rdi, r14	#, tmp118
# src/Mat4.c:369:     mat->data[12] = -vec3dotProduct(&s, pos);
	.loc 1 369 0
	xorps	xmm0, xmm1	# tmp139, tmp124
	movss	DWORD PTR 48[rbx], xmm0	# mat_35(D)->data, tmp139
# src/Mat4.c:370:     mat->data[13] = -vec3dotProduct(&u, pos);
	.loc 1 370 0
	call	vec3dot@PLT	#
.LVL207:
	movaps	xmm1, XMMWORD PTR [rsp]	# tmp124, %sfp
# src/Mat4.c:371:     mat->data[14] = vec3dotProduct(&f, pos);
	.loc 1 371 0
	mov	rsi, r12	#, pos
	mov	rdi, rbp	#, tmp114
# src/Mat4.c:370:     mat->data[13] = -vec3dotProduct(&u, pos);
	.loc 1 370 0
	xorps	xmm1, xmm0	# tmp142, _20
	movss	DWORD PTR 52[rbx], xmm1	# mat_35(D)->data, tmp142
# src/Mat4.c:371:     mat->data[14] = vec3dotProduct(&f, pos);
	.loc 1 371 0
	call	vec3dot@PLT	#
.LVL208:
# src/Mat4.c:374: }
	.loc 1 374 0
	mov	rcx, QWORD PTR 72[rsp]	# tmp148, D.5036
	xor	rcx, QWORD PTR fs:40	# tmp148,
# src/Mat4.c:371:     mat->data[14] = vec3dotProduct(&f, pos);
	.loc 1 371 0
	movss	DWORD PTR 56[rbx], xmm0	# mat_35(D)->data, _22
# src/Mat4.c:372:     mat->data[15] = 1.0f;
	.loc 1 372 0
	mov	DWORD PTR 60[rbx], 0x3f800000	# mat_35(D)->data,
# src/Mat4.c:374: }
	.loc 1 374 0
	jne	.L61	#,
	add	rsp, 80	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 48
	mov	rax, rbx	#, mat
	pop	rbx	#
	.cfi_def_cfa_offset 40
.LVL209:
	pop	rbp	#
	.cfi_def_cfa_offset 32
	pop	r12	#
	.cfi_def_cfa_offset 24
.LVL210:
	pop	r13	#
	.cfi_def_cfa_offset 16
	pop	r14	#
	.cfi_def_cfa_offset 8
	ret
.LVL211:
.L61:
	.cfi_restore_state
	call	__stack_chk_fail@PLT	#
.LVL212:
	.cfi_endproc
.LFE47:
	.size	setCameraTransformMat4, .-setCameraTransformMat4
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC11:
	.string	"%+-.2f %+-.2f %+-.2f %+-.2f\n"
	.text
	.p2align 4,,15
	.globl	printMat4
	.type	printMat4, @function
printMat4:
.LFB48:
	.loc 1 377 0
	.cfi_startproc
.LVL213:
	push	r12	#
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	lea	r12, 64[rdi]	# _24,
	push	rbp	#
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
# src/Mat4.c:381:         printf("%+-.2f %+-.2f %+-.2f %+-.2f\n", d[0], d[1], d[2], d[3]);
	.loc 1 381 0
	lea	rbp, .LC11[rip]	# tmp124,
# src/Mat4.c:377: {
	.loc 1 377 0
	push	rbx	#
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
# src/Mat4.c:377: {
	.loc 1 377 0
	mov	rbx, rdi	# d, m
.LVL214:
.L63:
# src/Mat4.c:381:         printf("%+-.2f %+-.2f %+-.2f %+-.2f\n", d[0], d[1], d[2], d[3]);
	.loc 1 381 0 discriminator 3
	pxor	xmm0, xmm0	# tmp123
	mov	rdi, rbp	#, tmp124
	pxor	xmm3, xmm3	#
	mov	eax, 4	#,
	pxor	xmm2, xmm2	#
# src/Mat4.c:382:         d+= 4;
	.loc 1 382 0 discriminator 3
	add	rbx, 16	# d,
.LVL215:
# src/Mat4.c:381:         printf("%+-.2f %+-.2f %+-.2f %+-.2f\n", d[0], d[1], d[2], d[3]);
	.loc 1 381 0 discriminator 3
	pxor	xmm1, xmm1	#
	cvtss2sd	xmm0, DWORD PTR -16[rbx]	# tmp123, MEM[base: d_23, offset: 0B]
	cvtss2sd	xmm3, DWORD PTR -4[rbx]	#, MEM[base: d_23, offset: 12B]
	cvtss2sd	xmm2, DWORD PTR -8[rbx]	#, MEM[base: d_23, offset: 8B]
	cvtss2sd	xmm1, DWORD PTR -12[rbx]	#, MEM[base: d_23, offset: 4B]
	call	printf@PLT	#
.LVL216:
# src/Mat4.c:380:     for (i = 0; i < 4; ++i) {
	.loc 1 380 0 discriminator 3
	cmp	rbx, r12	# d, _24
	jne	.L63	#,
# src/Mat4.c:384: }
	.loc 1 384 0
	pop	rbx	#
	.cfi_def_cfa_offset 24
.LVL217:
	pop	rbp	#
	.cfi_def_cfa_offset 16
	pop	r12	#
	.cfi_def_cfa_offset 8
.LVL218:
	ret
	.cfi_endproc
.LFE48:
	.size	printMat4, .-printMat4
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	1065353216
	.long	0
	.long	0
	.long	0
	.align 16
.LC1:
	.long	0
	.long	1065353216
	.long	0
	.long	0
	.align 16
.LC2:
	.long	0
	.long	0
	.long	1065353216
	.long	0
	.align 16
.LC3:
	.long	0
	.long	0
	.long	0
	.long	1065353216
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC4:
	.long	1065353216
	.align 4
.LC5:
	.long	1078530011
	.align 4
.LC6:
	.long	1127481344
	.section	.rodata.cst16
	.align 16
.LC8:
	.long	2147483648
	.long	0
	.long	0
	.long	0
	.section	.rodata.cst4
	.align 4
.LC9:
	.long	1056964608
	.align 4
.LC10:
	.long	3221225472
	.text
.Letext0:
	.file 2 "/usr/include/bits/types.h"
	.file 3 "./inc/math_types.h"
	.file 4 "/usr/include/math.h"
	.file 5 "/usr/lib/gcc/x86_64-pc-linux-gnu/7.2.0/include/stddef.h"
	.file 6 "/usr/include/libio.h"
	.file 7 "/usr/include/stdio.h"
	.file 8 "/usr/include/bits/sys_errlist.h"
	.file 9 "./inc/Vec3.h"
	.file 10 "/usr/include/stdlib.h"
	.file 11 "<built-in>"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x1545
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF112
	.byte	0xc
	.long	.LASF113
	.long	.LASF114
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
	.long	.LASF115
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
	.long	.LASF116
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
	.uleb128 0x7
	.long	0x101
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
	.value	0x233
	.long	0x151
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
	.value	0x239
	.long	0x124
	.uleb128 0xf
	.long	.LASF21
	.byte	0x4
	.value	0x23e
	.long	0x151
	.uleb128 0x4
	.long	.LASF22
	.byte	0x5
	.byte	0xd8
	.long	0x49
	.uleb128 0x6
	.byte	0x8
	.long	0x91
	.uleb128 0x7
	.long	0x174
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
	.long	0x30a
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
	.long	0x342
	.byte	0x60
	.uleb128 0x14
	.long	.LASF40
	.byte	0x6
	.value	0x106
	.long	0x348
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
	.long	0x34e
	.byte	0x83
	.uleb128 0x14
	.long	.LASF47
	.byte	0x6
	.value	0x118
	.long	0x35e
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
	.long	0x169
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
	.long	0x364
	.byte	0xc4
	.byte	0
	.uleb128 0x15
	.long	.LASF117
	.byte	0x6
	.byte	0x96
	.uleb128 0xa
	.long	.LASF56
	.byte	0x18
	.byte	0x6
	.byte	0x9c
	.long	0x342
	.uleb128 0xb
	.long	.LASF57
	.byte	0x6
	.byte	0x9d
	.long	0x342
	.byte	0
	.uleb128 0xb
	.long	.LASF58
	.byte	0x6
	.byte	0x9e
	.long	0x348
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
	.long	0x311
	.uleb128 0x6
	.byte	0x8
	.long	0x18d
	.uleb128 0xc
	.long	0x8a
	.long	0x35e
	.uleb128 0xd
	.long	0x49
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x30a
	.uleb128 0xc
	.long	0x8a
	.long	0x374
	.uleb128 0xd
	.long	0x49
	.byte	0x13
	.byte	0
	.uleb128 0x16
	.long	.LASF118
	.uleb128 0xf
	.long	.LASF60
	.byte	0x6
	.value	0x13b
	.long	0x374
	.uleb128 0xf
	.long	.LASF61
	.byte	0x6
	.value	0x13c
	.long	0x374
	.uleb128 0xf
	.long	.LASF62
	.byte	0x6
	.value	0x13d
	.long	0x374
	.uleb128 0x17
	.long	.LASF63
	.byte	0x7
	.byte	0x87
	.long	0x348
	.uleb128 0x17
	.long	.LASF64
	.byte	0x7
	.byte	0x88
	.long	0x348
	.uleb128 0x17
	.long	.LASF65
	.byte	0x7
	.byte	0x89
	.long	0x348
	.uleb128 0x17
	.long	.LASF66
	.byte	0x8
	.byte	0x1a
	.long	0x5e
	.uleb128 0xc
	.long	0x17a
	.long	0x3d4
	.uleb128 0x18
	.byte	0
	.uleb128 0x7
	.long	0x3c9
	.uleb128 0x17
	.long	.LASF67
	.byte	0x8
	.byte	0x1b
	.long	0x3d4
	.uleb128 0x19
	.long	.LASF98
	.byte	0x1
	.value	0x178
	.quad	.LFB48
	.quad	.LFE48-.LFB48
	.uleb128 0x1
	.byte	0x9c
	.long	0x441
	.uleb128 0x1a
	.string	"m"
	.byte	0x1
	.value	0x178
	.long	0x441
	.long	.LLST60
	.uleb128 0x1b
	.string	"d"
	.byte	0x1
	.value	0x17a
	.long	0x447
	.long	.LLST61
	.uleb128 0x1b
	.string	"i"
	.byte	0x1
	.value	0x17b
	.long	0x169
	.long	.LLST62
	.uleb128 0x1c
	.quad	.LVL216
	.long	0x14b4
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x101
	.uleb128 0x6
	.byte	0x8
	.long	0x2d
	.uleb128 0x1e
	.long	.LASF68
	.byte	0x1
	.value	0x15b
	.long	0x441
	.quad	.LFB47
	.quad	.LFE47-.LFB47
	.uleb128 0x1
	.byte	0x9c
	.long	0x5fe
	.uleb128 0x1a
	.string	"mat"
	.byte	0x1
	.value	0x15b
	.long	0x441
	.long	.LLST56
	.uleb128 0x1a
	.string	"pos"
	.byte	0x1
	.value	0x15b
	.long	0x5fe
	.long	.LLST57
	.uleb128 0x1a
	.string	"tar"
	.byte	0x1
	.value	0x15b
	.long	0x5fe
	.long	.LLST58
	.uleb128 0x1a
	.string	"up"
	.byte	0x1
	.value	0x15b
	.long	0x5fe
	.long	.LLST59
	.uleb128 0x1f
	.string	"f"
	.byte	0x1
	.value	0x15d
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0x1f
	.string	"s"
	.byte	0x1
	.value	0x15d
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x1f
	.string	"u"
	.byte	0x1
	.value	0x15d
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x20
	.quad	.LVL197
	.long	0x14c0
	.long	0x4f7
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0
	.uleb128 0x20
	.quad	.LVL198
	.long	0x14cb
	.long	0x50f
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.uleb128 0x21
	.quad	.LVL199
	.long	0x14d6
	.uleb128 0x20
	.quad	.LVL200
	.long	0x14c0
	.long	0x53a
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL202
	.long	0x14e1
	.long	0x553
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0
	.uleb128 0x21
	.quad	.LVL203
	.long	0x14d6
	.uleb128 0x20
	.quad	.LVL204
	.long	0x14c0
	.long	0x57e
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7e
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL205
	.long	0x14e1
	.long	0x596
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL206
	.long	0x14ec
	.long	0x5b4
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL207
	.long	0x14ec
	.long	0x5d2
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7e
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL208
	.long	0x14ec
	.long	0x5f0
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
	.quad	.LVL212
	.long	0x14f7
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0xfc
	.uleb128 0x1e
	.long	.LASF69
	.byte	0x1
	.value	0x13d
	.long	0x441
	.quad	.LFB46
	.quad	.LFE46-.LFB46
	.uleb128 0x1
	.byte	0x9c
	.long	0x732
	.uleb128 0x1a
	.string	"mat"
	.byte	0x1
	.value	0x13d
	.long	0x441
	.long	.LLST53
	.uleb128 0x1a
	.string	"tar"
	.byte	0x1
	.value	0x13d
	.long	0x5fe
	.long	.LLST54
	.uleb128 0x1a
	.string	"up"
	.byte	0x1
	.value	0x13d
	.long	0x5fe
	.long	.LLST55
	.uleb128 0x1f
	.string	"n"
	.byte	0x1
	.value	0x13f
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0x1f
	.string	"u"
	.byte	0x1
	.value	0x13f
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x1f
	.string	"v"
	.byte	0x1
	.value	0x13f
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x20
	.quad	.LVL182
	.long	0x14c0
	.long	0x69d
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x77
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.uleb128 0x21
	.quad	.LVL183
	.long	0x14d6
	.uleb128 0x20
	.quad	.LVL184
	.long	0x14c0
	.long	0x6c8
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
	.byte	0x7e
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL185
	.long	0x14e1
	.long	0x6e0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.uleb128 0x21
	.quad	.LVL186
	.long	0x14d6
	.uleb128 0x20
	.quad	.LVL187
	.long	0x14c0
	.long	0x70c
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x77
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL188
	.long	0x14e1
	.long	0x724
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.uleb128 0x21
	.quad	.LVL193
	.long	0x14f7
	.byte	0
	.uleb128 0x1e
	.long	.LASF70
	.byte	0x1
	.value	0x116
	.long	0x441
	.quad	.LFB45
	.quad	.LFE45-.LFB45
	.uleb128 0x1
	.byte	0x9c
	.long	0x8a6
	.uleb128 0x1a
	.string	"mat"
	.byte	0x1
	.value	0x116
	.long	0x441
	.long	.LLST49
	.uleb128 0x1a
	.string	"pos"
	.byte	0x1
	.value	0x116
	.long	0x8a6
	.long	.LLST50
	.uleb128 0x1a
	.string	"tar"
	.byte	0x1
	.value	0x116
	.long	0x8a6
	.long	.LLST51
	.uleb128 0x1a
	.string	"up"
	.byte	0x1
	.value	0x116
	.long	0x8a6
	.long	.LLST52
	.uleb128 0x22
	.long	.LASF71
	.byte	0x1
	.value	0x118
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0x22
	.long	.LASF72
	.byte	0x1
	.value	0x119
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x1f
	.string	"top"
	.byte	0x1
	.value	0x11a
	.long	0xf0
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x20
	.quad	.LVL167
	.long	0x1500
	.long	0x7dc
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0
	.uleb128 0x20
	.quad	.LVL169
	.long	0x150b
	.long	0x7fb
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x20
	.quad	.LVL170
	.long	0x14d6
	.long	0x813
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL171
	.long	0x1500
	.long	0x82b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL172
	.long	0x1516
	.long	0x849
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x7d
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL173
	.long	0x14d6
	.long	0x861
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL174
	.long	0x1500
	.long	0x879
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x7c
	.sleb128 0
	.byte	0
	.uleb128 0x20
	.quad	.LVL175
	.long	0x1516
	.long	0x898
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x76
	.sleb128 0
	.byte	0
	.uleb128 0x21
	.quad	.LVL179
	.long	0x14f7
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0xf0
	.uleb128 0x23
	.long	.LASF73
	.byte	0x1
	.byte	0xf8
	.long	0x441
	.quad	.LFB44
	.quad	.LFE44-.LFB44
	.uleb128 0x1
	.byte	0x9c
	.long	0x97d
	.uleb128 0x24
	.string	"mat"
	.byte	0x1
	.byte	0xf8
	.long	0x441
	.long	.LLST42
	.uleb128 0x24
	.string	"fov"
	.byte	0x1
	.byte	0xf8
	.long	0x96
	.long	.LLST43
	.uleb128 0x25
	.long	.LASF74
	.byte	0x1
	.byte	0xf8
	.long	0x96
	.long	.LLST44
	.uleb128 0x25
	.long	.LASF75
	.byte	0x1
	.byte	0xf8
	.long	0x96
	.long	.LLST45
	.uleb128 0x24
	.string	"far"
	.byte	0x1
	.byte	0xf8
	.long	0x96
	.long	.LLST46
	.uleb128 0x26
	.long	.LASF76
	.byte	0x1
	.byte	0xfa
	.long	0x2d
	.long	.LLST47
	.uleb128 0x27
	.string	"rad"
	.byte	0x1
	.byte	0xfc
	.long	0x2d
	.uleb128 0x28
	.string	"cot"
	.byte	0x1
	.byte	0xfd
	.long	0x2d
	.long	.LLST48
	.uleb128 0x1c
	.quad	.LVL160
	.long	0x1521
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x1d
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x3f000000
	.byte	0x1e
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0x23
	.long	.LASF77
	.byte	0x1
	.byte	0xf2
	.long	0x441
	.quad	.LFB43
	.quad	.LFE43-.LFB43
	.uleb128 0x1
	.byte	0x9c
	.long	0xa89
	.uleb128 0x24
	.string	"mat"
	.byte	0x1
	.byte	0xf2
	.long	0x441
	.long	.LLST38
	.uleb128 0x25
	.long	.LASF78
	.byte	0x1
	.byte	0xf2
	.long	0x96
	.long	.LLST39
	.uleb128 0x27
	.string	"tmp"
	.byte	0x1
	.byte	0xf4
	.long	0x101
	.uleb128 0x29
	.long	0xecf
	.quad	.LBB86
	.long	.Ldebug_ranges0+0x220
	.byte	0x1
	.byte	0xf5
	.long	0xa02
	.uleb128 0x2a
	.long	0xeea
	.uleb128 0x2b
	.long	0xedf
	.long	.LLST40
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x220
	.uleb128 0x2d
	.long	0x13f5
	.uleb128 0x2d
	.long	0x1411
	.uleb128 0x2d
	.long	0x141a
	.byte	0
	.byte	0
	.uleb128 0x29
	.long	0xe74
	.quad	.LBB91
	.long	.Ldebug_ranges0+0x260
	.byte	0x1
	.byte	0xf5
	.long	0xa42
	.uleb128 0x2a
	.long	0xe8f
	.uleb128 0x2b
	.long	0xe84
	.long	.LLST41
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x260
	.uleb128 0x2d
	.long	0x1482
	.uleb128 0x2d
	.long	0x148b
	.uleb128 0x2d
	.long	0x1494
	.uleb128 0x2d
	.long	0x149d
	.byte	0
	.byte	0
	.uleb128 0x20
	.quad	.LVL147
	.long	0x1521
	.long	0xa7b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0x91
	.sleb128 -100
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0x91
	.sleb128 -104
	.byte	0
	.uleb128 0x21
	.quad	.LVL155
	.long	0x14f7
	.byte	0
	.uleb128 0x23
	.long	.LASF79
	.byte	0x1
	.byte	0xec
	.long	0x441
	.quad	.LFB42
	.quad	.LFE42-.LFB42
	.uleb128 0x1
	.byte	0x9c
	.long	0xb95
	.uleb128 0x24
	.string	"mat"
	.byte	0x1
	.byte	0xec
	.long	0x441
	.long	.LLST34
	.uleb128 0x25
	.long	.LASF78
	.byte	0x1
	.byte	0xec
	.long	0x96
	.long	.LLST35
	.uleb128 0x27
	.string	"tmp"
	.byte	0x1
	.byte	0xee
	.long	0x101
	.uleb128 0x29
	.long	0xf13
	.quad	.LBB68
	.long	.Ldebug_ranges0+0x1a0
	.byte	0x1
	.byte	0xef
	.long	0xb0e
	.uleb128 0x2a
	.long	0xf2e
	.uleb128 0x2b
	.long	0xf23
	.long	.LLST36
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x1a0
	.uleb128 0x2d
	.long	0x136a
	.uleb128 0x2d
	.long	0x1386
	.uleb128 0x2d
	.long	0x138d
	.byte	0
	.byte	0
	.uleb128 0x29
	.long	0xe74
	.quad	.LBB73
	.long	.Ldebug_ranges0+0x1e0
	.byte	0x1
	.byte	0xef
	.long	0xb4e
	.uleb128 0x2a
	.long	0xe8f
	.uleb128 0x2b
	.long	0xe84
	.long	.LLST37
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x1e0
	.uleb128 0x2d
	.long	0x1482
	.uleb128 0x2d
	.long	0x148b
	.uleb128 0x2d
	.long	0x1494
	.uleb128 0x2d
	.long	0x149d
	.byte	0
	.byte	0
	.uleb128 0x20
	.quad	.LVL135
	.long	0x1521
	.long	0xb87
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0x91
	.sleb128 -100
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0x91
	.sleb128 -104
	.byte	0
	.uleb128 0x21
	.quad	.LVL142
	.long	0x14f7
	.byte	0
	.uleb128 0x23
	.long	.LASF80
	.byte	0x1
	.byte	0xe6
	.long	0x441
	.quad	.LFB41
	.quad	.LFE41-.LFB41
	.uleb128 0x1
	.byte	0x9c
	.long	0xca1
	.uleb128 0x24
	.string	"mat"
	.byte	0x1
	.byte	0xe6
	.long	0x441
	.long	.LLST30
	.uleb128 0x25
	.long	.LASF78
	.byte	0x1
	.byte	0xe6
	.long	0x96
	.long	.LLST31
	.uleb128 0x27
	.string	"tmp"
	.byte	0x1
	.byte	0xe8
	.long	0x101
	.uleb128 0x29
	.long	0xf57
	.quad	.LBB46
	.long	.Ldebug_ranges0+0x100
	.byte	0x1
	.byte	0xe9
	.long	0xc1a
	.uleb128 0x2a
	.long	0xf72
	.uleb128 0x2b
	.long	0xf67
	.long	.LLST32
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x100
	.uleb128 0x2d
	.long	0x12dd
	.uleb128 0x2d
	.long	0x12f9
	.uleb128 0x2d
	.long	0x1302
	.byte	0
	.byte	0
	.uleb128 0x29
	.long	0xe74
	.quad	.LBB52
	.long	.Ldebug_ranges0+0x150
	.byte	0x1
	.byte	0xe9
	.long	0xc5a
	.uleb128 0x2a
	.long	0xe8f
	.uleb128 0x2b
	.long	0xe84
	.long	.LLST33
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x150
	.uleb128 0x2d
	.long	0x1482
	.uleb128 0x2d
	.long	0x148b
	.uleb128 0x2d
	.long	0x1494
	.uleb128 0x2d
	.long	0x149d
	.byte	0
	.byte	0
	.uleb128 0x20
	.quad	.LVL123
	.long	0x1521
	.long	0xc93
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0x91
	.sleb128 -100
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0x91
	.sleb128 -104
	.byte	0
	.uleb128 0x21
	.quad	.LVL130
	.long	0x14f7
	.byte	0
	.uleb128 0x23
	.long	.LASF81
	.byte	0x1
	.byte	0xdf
	.long	0x441
	.quad	.LFB40
	.quad	.LFE40-.LFB40
	.uleb128 0x1
	.byte	0x9c
	.long	0xdf5
	.uleb128 0x24
	.string	"mat"
	.byte	0x1
	.byte	0xdf
	.long	0x441
	.long	.LLST24
	.uleb128 0x24
	.string	"v"
	.byte	0x1
	.byte	0xdf
	.long	0x5fe
	.long	.LLST25
	.uleb128 0x25
	.long	.LASF78
	.byte	0x1
	.byte	0xdf
	.long	0x96
	.long	.LLST26
	.uleb128 0x27
	.string	"tmp"
	.byte	0x1
	.byte	0xe1
	.long	0x101
	.uleb128 0x29
	.long	0xf9b
	.quad	.LBB12
	.long	.Ldebug_ranges0+0
	.byte	0x1
	.byte	0xe3
	.long	0xd6e
	.uleb128 0x2a
	.long	0xfbf
	.uleb128 0x2b
	.long	0xfb6
	.long	.LLST27
	.uleb128 0x2b
	.long	0xfab
	.long	.LLST28
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0
	.uleb128 0x2d
	.long	0x11fe
	.uleb128 0x2d
	.long	0x121a
	.uleb128 0x2d
	.long	0x1221
	.uleb128 0x2d
	.long	0x122a
	.uleb128 0x2d
	.long	0x1231
	.uleb128 0x2d
	.long	0x1238
	.uleb128 0x2d
	.long	0x1241
	.uleb128 0x2d
	.long	0x1248
	.uleb128 0x2d
	.long	0x1251
	.uleb128 0x2d
	.long	0x125a
	.uleb128 0x2d
	.long	0x1263
	.uleb128 0x2d
	.long	0x126c
	.uleb128 0x2d
	.long	0x1273
	.byte	0
	.byte	0
	.uleb128 0x29
	.long	0xe74
	.quad	.LBB21
	.long	.Ldebug_ranges0+0x80
	.byte	0x1
	.byte	0xe3
	.long	0xdae
	.uleb128 0x2a
	.long	0xe8f
	.uleb128 0x2b
	.long	0xe84
	.long	.LLST29
	.uleb128 0x2c
	.long	.Ldebug_ranges0+0x80
	.uleb128 0x2d
	.long	0x1482
	.uleb128 0x2d
	.long	0x148b
	.uleb128 0x2d
	.long	0x1494
	.uleb128 0x2d
	.long	0x149d
	.byte	0
	.byte	0
	.uleb128 0x20
	.quad	.LVL96
	.long	0x1521
	.long	0xde7
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0x91
	.sleb128 -116
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x3
	.byte	0x91
	.sleb128 -120
	.byte	0
	.uleb128 0x21
	.quad	.LVL118
	.long	0x14f7
	.byte	0
	.uleb128 0x23
	.long	.LASF82
	.byte	0x1
	.byte	0xd7
	.long	0x441
	.quad	.LFB39
	.quad	.LFE39-.LFB39
	.uleb128 0x1
	.byte	0x9c
	.long	0xe2f
	.uleb128 0x2e
	.string	"mat"
	.byte	0x1
	.byte	0xd7
	.long	0x441
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2e
	.string	"v"
	.byte	0x1
	.byte	0xd7
	.long	0x5fe
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x23
	.long	.LASF83
	.byte	0x1
	.byte	0xcd
	.long	0x441
	.quad	.LFB38
	.quad	.LFE38-.LFB38
	.uleb128 0x1
	.byte	0x9c
	.long	0xe74
	.uleb128 0x2e
	.string	"m"
	.byte	0x1
	.byte	0xcd
	.long	0x441
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2e
	.string	"v"
	.byte	0x1
	.byte	0xcd
	.long	0x5fe
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2f
	.string	"mat"
	.byte	0x1
	.byte	0xcf
	.long	0x447
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x30
	.long	.LASF85
	.byte	0x1
	.byte	0xb7
	.long	0x441
	.byte	0x1
	.long	0xebf
	.uleb128 0x31
	.long	.LASF84
	.byte	0x1
	.byte	0xb7
	.long	0x441
	.uleb128 0x32
	.string	"src"
	.byte	0x1
	.byte	0xb7
	.long	0x441
	.uleb128 0x27
	.string	"c"
	.byte	0x1
	.byte	0xb9
	.long	0xebf
	.uleb128 0x27
	.string	"i"
	.byte	0x1
	.byte	0xba
	.long	0x5e
	.uleb128 0x27
	.string	"r"
	.byte	0x1
	.byte	0xbb
	.long	0x447
	.uleb128 0x27
	.string	"d"
	.byte	0x1
	.byte	0xbc
	.long	0xe0
	.byte	0
	.uleb128 0xc
	.long	0x2d
	.long	0xecf
	.uleb128 0xd
	.long	0x49
	.byte	0x3
	.byte	0
	.uleb128 0x30
	.long	.LASF86
	.byte	0x1
	.byte	0x9b
	.long	0x441
	.byte	0x1
	.long	0xf13
	.uleb128 0x32
	.string	"mat"
	.byte	0x1
	.byte	0x9b
	.long	0x441
	.uleb128 0x31
	.long	.LASF78
	.byte	0x1
	.byte	0x9b
	.long	0x96
	.uleb128 0x33
	.long	.LASF87
	.byte	0x1
	.byte	0x9e
	.long	0x96
	.uleb128 0x27
	.string	"s"
	.byte	0x1
	.byte	0x9f
	.long	0x2d
	.uleb128 0x27
	.string	"c"
	.byte	0x1
	.byte	0xa0
	.long	0x2d
	.byte	0
	.uleb128 0x30
	.long	.LASF88
	.byte	0x1
	.byte	0x7f
	.long	0x441
	.byte	0x1
	.long	0xf57
	.uleb128 0x32
	.string	"mat"
	.byte	0x1
	.byte	0x7f
	.long	0x441
	.uleb128 0x31
	.long	.LASF78
	.byte	0x1
	.byte	0x7f
	.long	0x96
	.uleb128 0x33
	.long	.LASF87
	.byte	0x1
	.byte	0x82
	.long	0x96
	.uleb128 0x27
	.string	"s"
	.byte	0x1
	.byte	0x83
	.long	0x2d
	.uleb128 0x27
	.string	"c"
	.byte	0x1
	.byte	0x84
	.long	0x2d
	.byte	0
	.uleb128 0x30
	.long	.LASF89
	.byte	0x1
	.byte	0x63
	.long	0x441
	.byte	0x1
	.long	0xf9b
	.uleb128 0x32
	.string	"mat"
	.byte	0x1
	.byte	0x63
	.long	0x441
	.uleb128 0x31
	.long	.LASF78
	.byte	0x1
	.byte	0x63
	.long	0x96
	.uleb128 0x33
	.long	.LASF87
	.byte	0x1
	.byte	0x66
	.long	0x96
	.uleb128 0x27
	.string	"s"
	.byte	0x1
	.byte	0x67
	.long	0x2d
	.uleb128 0x27
	.string	"c"
	.byte	0x1
	.byte	0x68
	.long	0x2d
	.byte	0
	.uleb128 0x30
	.long	.LASF90
	.byte	0x1
	.byte	0x3b
	.long	0x441
	.byte	0x1
	.long	0x104f
	.uleb128 0x32
	.string	"mat"
	.byte	0x1
	.byte	0x3b
	.long	0x441
	.uleb128 0x32
	.string	"v"
	.byte	0x1
	.byte	0x3b
	.long	0x5fe
	.uleb128 0x31
	.long	.LASF78
	.byte	0x1
	.byte	0x3b
	.long	0x96
	.uleb128 0x27
	.string	"rad"
	.byte	0x1
	.byte	0x3d
	.long	0x96
	.uleb128 0x27
	.string	"c"
	.byte	0x1
	.byte	0x3f
	.long	0x96
	.uleb128 0x27
	.string	"s"
	.byte	0x1
	.byte	0x40
	.long	0x96
	.uleb128 0x27
	.string	"nc"
	.byte	0x1
	.byte	0x42
	.long	0x96
	.uleb128 0x27
	.string	"zs"
	.byte	0x1
	.byte	0x43
	.long	0x96
	.uleb128 0x27
	.string	"ys"
	.byte	0x1
	.byte	0x44
	.long	0x96
	.uleb128 0x27
	.string	"xs"
	.byte	0x1
	.byte	0x45
	.long	0x96
	.uleb128 0x27
	.string	"xy"
	.byte	0x1
	.byte	0x46
	.long	0x96
	.uleb128 0x27
	.string	"xz"
	.byte	0x1
	.byte	0x47
	.long	0x96
	.uleb128 0x27
	.string	"yz"
	.byte	0x1
	.byte	0x48
	.long	0x96
	.uleb128 0x33
	.long	.LASF91
	.byte	0x1
	.byte	0x49
	.long	0x96
	.uleb128 0x33
	.long	.LASF92
	.byte	0x1
	.byte	0x4a
	.long	0x96
	.uleb128 0x33
	.long	.LASF93
	.byte	0x1
	.byte	0x4b
	.long	0x96
	.byte	0
	.uleb128 0x23
	.long	.LASF94
	.byte	0x1
	.byte	0x35
	.long	0x441
	.quad	.LFB32
	.quad	.LFE32-.LFB32
	.uleb128 0x1
	.byte	0x9c
	.long	0x1089
	.uleb128 0x2e
	.string	"mat"
	.byte	0x1
	.byte	0x35
	.long	0x441
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2e
	.string	"v"
	.byte	0x1
	.byte	0x35
	.long	0x5fe
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x23
	.long	.LASF95
	.byte	0x1
	.byte	0x2f
	.long	0x441
	.quad	.LFB31
	.quad	.LFE31-.LFB31
	.uleb128 0x1
	.byte	0x9c
	.long	0x10c1
	.uleb128 0x2e
	.string	"m"
	.byte	0x1
	.byte	0x2f
	.long	0x441
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2e
	.string	"v"
	.byte	0x1
	.byte	0x2f
	.long	0x5fe
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x23
	.long	.LASF96
	.byte	0x1
	.byte	0x29
	.long	0x441
	.quad	.LFB30
	.quad	.LFE30-.LFB30
	.uleb128 0x1
	.byte	0x9c
	.long	0x10f0
	.uleb128 0x2e
	.string	"mat"
	.byte	0x1
	.byte	0x29
	.long	0x441
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.uleb128 0x30
	.long	.LASF97
	.byte	0x1
	.byte	0x23
	.long	0x441
	.byte	0x1
	.long	0x1117
	.uleb128 0x31
	.long	.LASF84
	.byte	0x1
	.byte	0x23
	.long	0x441
	.uleb128 0x32
	.string	"src"
	.byte	0x1
	.byte	0x23
	.long	0x1117
	.byte	0
	.uleb128 0x6
	.byte	0x8
	.long	0x10c
	.uleb128 0x34
	.long	.LASF99
	.byte	0x1
	.byte	0x1d
	.quad	.LFB28
	.quad	.LFE28-.LFB28
	.uleb128 0x1
	.byte	0x9c
	.long	0x115d
	.uleb128 0x24
	.string	"m"
	.byte	0x1
	.byte	0x1d
	.long	0x441
	.long	.LLST0
	.uleb128 0x35
	.quad	.LVL2
	.long	0x1530
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x3
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0
	.byte	0
	.uleb128 0x23
	.long	.LASF100
	.byte	0x1
	.byte	0x16
	.long	0x441
	.quad	.LFB27
	.quad	.LFE27-.LFB27
	.uleb128 0x1
	.byte	0x9c
	.long	0x119e
	.uleb128 0x2f
	.string	"m"
	.byte	0x1
	.byte	0x18
	.long	0x441
	.uleb128 0x1
	.byte	0x50
	.uleb128 0x1c
	.quad	.LVL0
	.long	0x153c
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x8
	.byte	0x40
	.byte	0
	.byte	0
	.uleb128 0x36
	.long	0x10f0
	.quad	.LFB29
	.quad	.LFE29-.LFB29
	.uleb128 0x1
	.byte	0x9c
	.long	0x11c8
	.uleb128 0x37
	.long	0x1100
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x37
	.long	0x110b
	.uleb128 0x1
	.byte	0x54
	.byte	0
	.uleb128 0x36
	.long	0xf9b
	.quad	.LFB33
	.quad	.LFE33-.LFB33
	.uleb128 0x1
	.byte	0x9c
	.long	0x12b0
	.uleb128 0x2b
	.long	0xfab
	.long	.LLST1
	.uleb128 0x2b
	.long	0xfb6
	.long	.LLST2
	.uleb128 0x2b
	.long	0xfbf
	.long	.LLST3
	.uleb128 0x38
	.long	0xfca
	.uleb128 0x16
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.byte	0x9f
	.uleb128 0x38
	.long	0xfd5
	.uleb128 0x1
	.byte	0x67
	.uleb128 0x39
	.long	0xfde
	.long	.LLST4
	.uleb128 0x38
	.long	0xfe7
	.uleb128 0x1
	.byte	0x64
	.uleb128 0x38
	.long	0xff1
	.uleb128 0x1
	.byte	0x6b
	.uleb128 0x39
	.long	0xffb
	.long	.LLST5
	.uleb128 0x38
	.long	0x1005
	.uleb128 0x1
	.byte	0x68
	.uleb128 0x39
	.long	0x100f
	.long	.LLST6
	.uleb128 0x39
	.long	0x1019
	.long	.LLST7
	.uleb128 0x39
	.long	0x1023
	.long	.LLST8
	.uleb128 0x39
	.long	0x102d
	.long	.LLST9
	.uleb128 0x38
	.long	0x1038
	.uleb128 0x1
	.byte	0x6a
	.uleb128 0x39
	.long	0x1043
	.long	.LLST10
	.uleb128 0x1c
	.quad	.LVL11
	.long	0x1521
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -40
	.byte	0
	.byte	0
	.uleb128 0x36
	.long	0xf57
	.quad	.LFB34
	.quad	.LFE34-.LFB34
	.uleb128 0x1
	.byte	0x9c
	.long	0x133d
	.uleb128 0x2b
	.long	0xf67
	.long	.LLST11
	.uleb128 0x2b
	.long	0xf72
	.long	.LLST12
	.uleb128 0x38
	.long	0xf7d
	.uleb128 0x16
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.byte	0x9f
	.uleb128 0x39
	.long	0xf88
	.long	.LLST13
	.uleb128 0x38
	.long	0xf91
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x1c
	.quad	.LVL30
	.long	0x1521
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0x36
	.long	0xf13
	.quad	.LFB35
	.quad	.LFE35-.LFB35
	.uleb128 0x1
	.byte	0x9c
	.long	0x13c8
	.uleb128 0x2b
	.long	0xf23
	.long	.LLST14
	.uleb128 0x2b
	.long	0xf2e
	.long	.LLST15
	.uleb128 0x38
	.long	0xf39
	.uleb128 0x16
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.byte	0x9f
	.uleb128 0x38
	.long	0xf44
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x38
	.long	0xf4d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x1c
	.quad	.LVL38
	.long	0x1521
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0x36
	.long	0xecf
	.quad	.LFB36
	.quad	.LFE36-.LFB36
	.uleb128 0x1
	.byte	0x9c
	.long	0x1455
	.uleb128 0x2b
	.long	0xedf
	.long	.LLST16
	.uleb128 0x2b
	.long	0xeea
	.long	.LLST17
	.uleb128 0x38
	.long	0xef5
	.uleb128 0x16
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.byte	0x9f
	.uleb128 0x39
	.long	0xf00
	.long	.LLST18
	.uleb128 0x38
	.long	0xf09
	.uleb128 0x1
	.byte	0x62
	.uleb128 0x1c
	.quad	.LVL45
	.long	0x1521
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x61
	.uleb128 0x15
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x40490fdb
	.byte	0x1e
	.byte	0xf4
	.uleb128 0x2d
	.byte	0x4
	.long	0x43340000
	.byte	0x1b
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x55
	.uleb128 0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x1d
	.uleb128 0x1
	.byte	0x54
	.uleb128 0x2
	.byte	0x91
	.sleb128 -24
	.byte	0
	.byte	0
	.uleb128 0x36
	.long	0xe74
	.quad	.LFB37
	.quad	.LFE37-.LFB37
	.uleb128 0x1
	.byte	0x9c
	.long	0x14b4
	.uleb128 0x2b
	.long	0xe84
	.long	.LLST19
	.uleb128 0x2b
	.long	0xe8f
	.long	.LLST20
	.uleb128 0x39
	.long	0xe9a
	.long	.LLST21
	.uleb128 0x39
	.long	0xea3
	.long	.LLST22
	.uleb128 0x39
	.long	0xeac
	.long	.LLST23
	.uleb128 0x38
	.long	0xeb5
	.uleb128 0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x21
	.quad	.LVL88
	.long	0x14f7
	.byte	0
	.uleb128 0x3a
	.long	.LASF101
	.long	.LASF101
	.byte	0x7
	.value	0x13e
	.uleb128 0x3b
	.long	.LASF102
	.long	.LASF102
	.byte	0x9
	.byte	0x12
	.uleb128 0x3b
	.long	.LASF103
	.long	.LASF103
	.byte	0x9
	.byte	0x16
	.uleb128 0x3b
	.long	.LASF104
	.long	.LASF104
	.byte	0x9
	.byte	0x1d
	.uleb128 0x3b
	.long	.LASF105
	.long	.LASF105
	.byte	0x9
	.byte	0x35
	.uleb128 0x3b
	.long	.LASF106
	.long	.LASF106
	.byte	0x9
	.byte	0x3e
	.uleb128 0x3c
	.long	.LASF119
	.long	.LASF119
	.uleb128 0x3b
	.long	.LASF107
	.long	.LASF107
	.byte	0x9
	.byte	0x10
	.uleb128 0x3b
	.long	.LASF108
	.long	.LASF108
	.byte	0x9
	.byte	0x48
	.uleb128 0x3b
	.long	.LASF109
	.long	.LASF109
	.byte	0x9
	.byte	0x49
	.uleb128 0x3d
	.long	.LASF120
	.long	.LASF121
	.byte	0xb
	.byte	0
	.long	.LASF120
	.uleb128 0x3a
	.long	.LASF110
	.long	.LASF110
	.byte	0xa
	.value	0x1c0
	.uleb128 0x3a
	.long	.LASF111
	.long	.LASF111
	.byte	0xa
	.value	0x1a8
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
	.uleb128 0x1b
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
	.uleb128 0x1c
	.uleb128 0x4109
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x31
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
	.uleb128 0x1f
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
	.uleb128 0x18
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
	.byte	0
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
	.uleb128 0x23
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
	.uleb128 0x24
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
	.uleb128 0x25
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
	.uleb128 0x26
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
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x27
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
	.uleb128 0x28
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
	.uleb128 0x29
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
	.uleb128 0x2a
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2b
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2c
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2d
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x2e
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
	.uleb128 0x2f
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
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x30
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
	.uleb128 0x31
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
	.uleb128 0x32
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
	.uleb128 0x33
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
	.uleb128 0x34
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
	.uleb128 0x35
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
	.uleb128 0x36
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
	.uleb128 0x37
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x38
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x39
	.uleb128 0x34
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3a
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
	.uleb128 0x3b
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
	.uleb128 0x3c
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
	.byte	0
	.byte	0
	.uleb128 0x3d
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
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST60:
	.quad	.LVL213-.Ltext0
	.quad	.LVL214-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL214-.Ltext0
	.quad	.LVL218-.Ltext0
	.value	0x3
	.byte	0x7c
	.sleb128 -64
	.byte	0x9f
	.quad	.LVL218-.Ltext0
	.quad	.LFE48-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LLST61:
	.quad	.LVL213-.Ltext0
	.quad	.LVL214-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL214-.Ltext0
	.quad	.LVL215-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL215-.Ltext0
	.quad	.LVL216-.Ltext0
	.value	0x3
	.byte	0x73
	.sleb128 -16
	.byte	0x9f
	.quad	.LVL216-.Ltext0
	.quad	.LVL217-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST62:
	.quad	.LVL213-.Ltext0
	.quad	.LVL214-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	0
	.quad	0
.LLST56:
	.quad	.LVL194-.Ltext0
	.quad	.LVL196-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL196-.Ltext0
	.quad	.LVL209-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL209-.Ltext0
	.quad	.LVL211-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL211-.Ltext0
	.quad	.LFE47-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST57:
	.quad	.LVL194-.Ltext0
	.quad	.LVL195-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL195-.Ltext0
	.quad	.LVL210-.Ltext0
	.value	0x1
	.byte	0x5c
	.quad	.LVL210-.Ltext0
	.quad	.LVL211-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL211-.Ltext0
	.quad	.LFE47-.Ltext0
	.value	0x1
	.byte	0x5c
	.quad	0
	.quad	0
.LLST58:
	.quad	.LVL194-.Ltext0
	.quad	.LVL197-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL197-1-.Ltext0
	.quad	.LFE47-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LLST59:
	.quad	.LVL194-.Ltext0
	.quad	.LVL197-1-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL197-1-.Ltext0
	.quad	.LVL201-.Ltext0
	.value	0x1
	.byte	0x5e
	.quad	.LVL201-.Ltext0
	.quad	.LVL202-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL202-1-.Ltext0
	.quad	.LFE47-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	0
	.quad	0
.LLST53:
	.quad	.LVL180-.Ltext0
	.quad	.LVL181-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL181-.Ltext0
	.quad	.LVL189-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL189-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL192-.Ltext0
	.quad	.LFE46-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST54:
	.quad	.LVL180-.Ltext0
	.quad	.LVL182-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL182-1-.Ltext0
	.quad	.LVL190-.Ltext0
	.value	0x1
	.byte	0x5d
	.quad	.LVL190-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL192-.Ltext0
	.quad	.LFE46-.Ltext0
	.value	0x1
	.byte	0x5d
	.quad	0
	.quad	0
.LLST55:
	.quad	.LVL180-.Ltext0
	.quad	.LVL182-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL182-1-.Ltext0
	.quad	.LVL191-.Ltext0
	.value	0x1
	.byte	0x5e
	.quad	.LVL191-.Ltext0
	.quad	.LVL192-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	.LVL192-.Ltext0
	.quad	.LFE46-.Ltext0
	.value	0x1
	.byte	0x5e
	.quad	0
	.quad	0
.LLST49:
	.quad	.LVL165-.Ltext0
	.quad	.LVL166-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL166-.Ltext0
	.quad	.LVL176-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL176-.Ltext0
	.quad	.LVL178-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL178-.Ltext0
	.quad	.LFE45-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST50:
	.quad	.LVL165-.Ltext0
	.quad	.LVL167-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL167-1-.Ltext0
	.quad	.LVL168-.Ltext0
	.value	0x1
	.byte	0x5c
	.quad	.LVL168-.Ltext0
	.quad	.LVL169-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL169-1-.Ltext0
	.quad	.LFE45-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST51:
	.quad	.LVL165-.Ltext0
	.quad	.LVL167-1-.Ltext0
	.value	0x1
	.byte	0x51
	.quad	.LVL167-1-.Ltext0
	.quad	.LFE45-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x51
	.byte	0x9f
	.quad	0
	.quad	0
.LLST52:
	.quad	.LVL165-.Ltext0
	.quad	.LVL167-1-.Ltext0
	.value	0x1
	.byte	0x52
	.quad	.LVL167-1-.Ltext0
	.quad	.LVL177-.Ltext0
	.value	0x1
	.byte	0x5d
	.quad	.LVL177-.Ltext0
	.quad	.LVL178-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x52
	.byte	0x9f
	.quad	.LVL178-.Ltext0
	.quad	.LFE45-.Ltext0
	.value	0x1
	.byte	0x5d
	.quad	0
	.quad	0
.LLST42:
	.quad	.LVL156-.Ltext0
	.quad	.LVL158-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL158-.Ltext0
	.quad	.LVL164-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL164-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST43:
	.quad	.LVL156-.Ltext0
	.quad	.LVL157-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL157-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST44:
	.quad	.LVL156-.Ltext0
	.quad	.LVL160-1-.Ltext0
	.value	0x1
	.byte	0x62
	.quad	.LVL160-1-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -28
	.quad	0
	.quad	0
.LLST45:
	.quad	.LVL156-.Ltext0
	.quad	.LVL160-1-.Ltext0
	.value	0x1
	.byte	0x63
	.quad	.LVL160-1-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -36
	.quad	0
	.quad	0
.LLST46:
	.quad	.LVL156-.Ltext0
	.quad	.LVL160-1-.Ltext0
	.value	0x1
	.byte	0x64
	.quad	.LVL160-1-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -32
	.quad	0
	.quad	0
.LLST47:
	.quad	.LVL159-.Ltext0
	.quad	.LVL160-1-.Ltext0
	.value	0x1
	.byte	0x65
	.quad	.LVL160-1-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x2
	.byte	0x91
	.sleb128 -40
	.quad	0
	.quad	0
.LLST48:
	.quad	.LVL161-.Ltext0
	.quad	.LVL162-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL162-.Ltext0
	.quad	.LVL163-.Ltext0
	.value	0x1
	.byte	0x67
	.quad	.LVL163-.Ltext0
	.quad	.LVL164-.Ltext0
	.value	0x2
	.byte	0x73
	.sleb128 20
	.quad	.LVL164-.Ltext0
	.quad	.LFE44-.Ltext0
	.value	0x2
	.byte	0x70
	.sleb128 20
	.quad	0
	.quad	0
.LLST38:
	.quad	.LVL143-.Ltext0
	.quad	.LVL145-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL145-.Ltext0
	.quad	.LVL153-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL153-.Ltext0
	.quad	.LVL154-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL154-.Ltext0
	.quad	.LFE43-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST39:
	.quad	.LVL143-.Ltext0
	.quad	.LVL144-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL144-.Ltext0
	.quad	.LFE43-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST40:
	.quad	.LVL146-.Ltext0
	.quad	.LVL150-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2492
	.sleb128 0
	.quad	0
	.quad	0
.LLST41:
	.quad	.LVL150-.Ltext0
	.quad	.LVL152-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST34:
	.quad	.LVL131-.Ltext0
	.quad	.LVL133-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL133-.Ltext0
	.quad	.LVL140-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL140-.Ltext0
	.quad	.LVL141-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL141-.Ltext0
	.quad	.LFE42-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST35:
	.quad	.LVL131-.Ltext0
	.quad	.LVL132-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL132-.Ltext0
	.quad	.LFE42-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST36:
	.quad	.LVL134-.Ltext0
	.quad	.LVL137-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+2760
	.sleb128 0
	.quad	0
	.quad	0
.LLST37:
	.quad	.LVL137-.Ltext0
	.quad	.LVL139-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST30:
	.quad	.LVL119-.Ltext0
	.quad	.LVL121-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL121-.Ltext0
	.quad	.LVL128-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL128-.Ltext0
	.quad	.LVL129-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL129-.Ltext0
	.quad	.LFE41-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST31:
	.quad	.LVL119-.Ltext0
	.quad	.LVL120-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL120-.Ltext0
	.quad	.LFE41-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST32:
	.quad	.LVL122-.Ltext0
	.quad	.LVL125-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3028
	.sleb128 0
	.quad	0
	.quad	0
.LLST33:
	.quad	.LVL125-.Ltext0
	.quad	.LVL127-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST24:
	.quad	.LVL91-.Ltext0
	.quad	.LVL93-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL93-.Ltext0
	.quad	.LVL115-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL115-.Ltext0
	.quad	.LVL117-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL117-.Ltext0
	.quad	.LFE40-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST25:
	.quad	.LVL91-.Ltext0
	.quad	.LVL94-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL94-.Ltext0
	.quad	.LVL116-.Ltext0
	.value	0x1
	.byte	0x56
	.quad	.LVL116-.Ltext0
	.quad	.LVL117-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	.LVL117-.Ltext0
	.quad	.LFE40-.Ltext0
	.value	0x1
	.byte	0x56
	.quad	0
	.quad	0
.LLST26:
	.quad	.LVL91-.Ltext0
	.quad	.LVL92-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL92-.Ltext0
	.quad	.LFE40-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST27:
	.quad	.LVL95-.Ltext0
	.quad	.LVL112-.Ltext0
	.value	0x1
	.byte	0x56
	.quad	0
	.quad	0
.LLST28:
	.quad	.LVL95-.Ltext0
	.quad	.LVL112-.Ltext0
	.value	0x6
	.byte	0xf2
	.long	.Ldebug_info0+3309
	.sleb128 0
	.quad	0
	.quad	0
.LLST29:
	.quad	.LVL112-.Ltext0
	.quad	.LVL114-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	0
	.quad	0
.LLST0:
	.quad	.LVL1-.Ltext0
	.quad	.LVL2-1-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL2-1-.Ltext0
	.quad	.LVL2-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	.LVL2-.Ltext0
	.quad	.LFE28-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	0
	.quad	0
.LLST1:
	.quad	.LVL7-.Ltext0
	.quad	.LVL9-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL9-.Ltext0
	.quad	.LVL25-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL25-.Ltext0
	.quad	.LFE33-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST2:
	.quad	.LVL7-.Ltext0
	.quad	.LVL10-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL10-.Ltext0
	.quad	.LVL26-.Ltext0
	.value	0x1
	.byte	0x56
	.quad	.LVL26-.Ltext0
	.quad	.LFE33-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST3:
	.quad	.LVL7-.Ltext0
	.quad	.LVL8-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL8-.Ltext0
	.quad	.LFE33-.Ltext0
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
	.quad	.LVL12-.Ltext0
	.quad	.LVL16-.Ltext0
	.value	0x1
	.byte	0x68
	.quad	0
	.quad	0
.LLST5:
	.quad	.LVL15-.Ltext0
	.quad	.LVL24-.Ltext0
	.value	0x1
	.byte	0x69
	.quad	0
	.quad	0
.LLST6:
	.quad	.LVL16-.Ltext0
	.quad	.LVL19-.Ltext0
	.value	0x1
	.byte	0x66
	.quad	0
	.quad	0
.LLST7:
	.quad	.LVL16-.Ltext0
	.quad	.LVL17-.Ltext0
	.value	0x8
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x13
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x9f
	.quad	.LVL17-.Ltext0
	.quad	.LVL20-.Ltext0
	.value	0x1
	.byte	0x6a
	.quad	0
	.quad	0
.LLST8:
	.quad	.LVL16-.Ltext0
	.quad	.LVL18-.Ltext0
	.value	0x8
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0xf5
	.uleb128 0x12
	.uleb128 0x2d
	.byte	0x1e
	.byte	0x9f
	.quad	.LVL18-.Ltext0
	.quad	.LVL21-.Ltext0
	.value	0x1
	.byte	0x65
	.quad	0
	.quad	0
.LLST9:
	.quad	.LVL19-.Ltext0
	.quad	.LVL22-.Ltext0
	.value	0x1
	.byte	0x66
	.quad	0
	.quad	0
.LLST10:
	.quad	.LVL21-.Ltext0
	.quad	.LVL23-.Ltext0
	.value	0x1
	.byte	0x65
	.quad	0
	.quad	0
.LLST11:
	.quad	.LVL27-.Ltext0
	.quad	.LVL29-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL29-.Ltext0
	.quad	.LVL34-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL34-.Ltext0
	.quad	.LFE34-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST12:
	.quad	.LVL27-.Ltext0
	.quad	.LVL28-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL28-.Ltext0
	.quad	.LFE34-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST13:
	.quad	.LVL31-.Ltext0
	.quad	.LVL32-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL32-.Ltext0
	.quad	.LVL34-.Ltext0
	.value	0x2
	.byte	0x73
	.sleb128 24
	.quad	.LVL34-.Ltext0
	.quad	.LFE34-.Ltext0
	.value	0x2
	.byte	0x70
	.sleb128 24
	.quad	0
	.quad	0
.LLST14:
	.quad	.LVL35-.Ltext0
	.quad	.LVL37-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL37-.Ltext0
	.quad	.LVL41-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL41-.Ltext0
	.quad	.LFE35-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST15:
	.quad	.LVL35-.Ltext0
	.quad	.LVL36-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL36-.Ltext0
	.quad	.LFE35-.Ltext0
	.value	0x6
	.byte	0xf3
	.uleb128 0x3
	.byte	0xf5
	.uleb128 0x11
	.uleb128 0x2d
	.byte	0x9f
	.quad	0
	.quad	0
.LLST16:
	.quad	.LVL42-.Ltext0
	.quad	.LVL44-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL44-.Ltext0
	.quad	.LVL49-.Ltext0
	.value	0x1
	.byte	0x53
	.quad	.LVL49-.Ltext0
	.quad	.LFE36-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	0
	.quad	0
.LLST17:
	.quad	.LVL42-.Ltext0
	.quad	.LVL43-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL43-.Ltext0
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
.LLST18:
	.quad	.LVL46-.Ltext0
	.quad	.LVL47-.Ltext0
	.value	0x1
	.byte	0x61
	.quad	.LVL47-.Ltext0
	.quad	.LVL49-.Ltext0
	.value	0x2
	.byte	0x73
	.sleb128 4
	.quad	.LVL49-.Ltext0
	.quad	.LFE36-.Ltext0
	.value	0x2
	.byte	0x70
	.sleb128 4
	.quad	0
	.quad	0
.LLST19:
	.quad	.LVL50-.Ltext0
	.quad	.LVL52-.Ltext0
	.value	0x1
	.byte	0x55
	.quad	.LVL52-.Ltext0
	.quad	.LVL88-1-.Ltext0
	.value	0x1
	.byte	0x50
	.quad	.LVL88-1-.Ltext0
	.quad	.LFE37-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x55
	.byte	0x9f
	.quad	0
	.quad	0
.LLST20:
	.quad	.LVL50-.Ltext0
	.quad	.LVL88-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL88-1-.Ltext0
	.quad	.LFE37-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
	.quad	0
	.quad	0
.LLST21:
	.quad	.LVL60-.Ltext0
	.quad	.LVL61-.Ltext0
	.value	0x5
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0xc
	.quad	.LVL61-.Ltext0
	.quad	.LVL62-.Ltext0
	.value	0x8
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x8
	.quad	.LVL62-.Ltext0
	.quad	.LVL63-.Ltext0
	.value	0xb
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL63-.Ltext0
	.quad	.LVL64-.Ltext0
	.value	0xc
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL64-.Ltext0
	.quad	.LVL65-.Ltext0
	.value	0xe
	.byte	0x91
	.sleb128 -96
	.byte	0x93
	.uleb128 0x4
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL65-.Ltext0
	.quad	.LVL66-.Ltext0
	.value	0x10
	.byte	0x91
	.sleb128 -96
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -80
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL66-.Ltext0
	.quad	.LVL67-.Ltext0
	.value	0x11
	.byte	0x91
	.sleb128 -96
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -80
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL67-.Ltext0
	.quad	.LVL69-.Ltext0
	.value	0x12
	.byte	0x91
	.sleb128 -96
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -80
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -64
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -48
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL69-.Ltext0
	.quad	.LVL70-.Ltext0
	.value	0xc
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL70-.Ltext0
	.quad	.LVL71-.Ltext0
	.value	0xe
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -76
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL71-.Ltext0
	.quad	.LVL72-.Ltext0
	.value	0x10
	.byte	0x91
	.sleb128 -92
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -76
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL72-.Ltext0
	.quad	.LVL73-.Ltext0
	.value	0x11
	.byte	0x91
	.sleb128 -92
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -76
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -60
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL73-.Ltext0
	.quad	.LVL75-.Ltext0
	.value	0x12
	.byte	0x91
	.sleb128 -92
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -76
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -60
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -44
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL75-.Ltext0
	.quad	.LVL76-.Ltext0
	.value	0xc
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL76-.Ltext0
	.quad	.LVL77-.Ltext0
	.value	0xe
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -72
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL77-.Ltext0
	.quad	.LVL78-.Ltext0
	.value	0x10
	.byte	0x91
	.sleb128 -88
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -72
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL78-.Ltext0
	.quad	.LVL79-.Ltext0
	.value	0x11
	.byte	0x91
	.sleb128 -88
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -72
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -56
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL79-.Ltext0
	.quad	.LVL81-.Ltext0
	.value	0x12
	.byte	0x91
	.sleb128 -88
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -72
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -56
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -40
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL81-.Ltext0
	.quad	.LVL82-.Ltext0
	.value	0xc
	.byte	0x61
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL82-.Ltext0
	.quad	.LVL83-.Ltext0
	.value	0xe
	.byte	0x91
	.sleb128 -84
	.byte	0x93
	.uleb128 0x4
	.byte	0x65
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL83-.Ltext0
	.quad	.LVL84-.Ltext0
	.value	0x10
	.byte	0x91
	.sleb128 -84
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -68
	.byte	0x93
	.uleb128 0x4
	.byte	0x64
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL84-.Ltext0
	.quad	.LVL85-.Ltext0
	.value	0x11
	.byte	0x91
	.sleb128 -84
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -68
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -52
	.byte	0x93
	.uleb128 0x4
	.byte	0x63
	.byte	0x93
	.uleb128 0x4
	.quad	.LVL85-.Ltext0
	.quad	.LVL87-.Ltext0
	.value	0x12
	.byte	0x91
	.sleb128 -84
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -68
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -52
	.byte	0x93
	.uleb128 0x4
	.byte	0x91
	.sleb128 -36
	.byte	0x93
	.uleb128 0x4
	.quad	0
	.quad	0
.LLST22:
	.quad	.LVL53-.Ltext0
	.quad	.LVL54-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL59-.Ltext0
	.quad	.LVL68-.Ltext0
	.value	0x2
	.byte	0x30
	.byte	0x9f
	.quad	.LVL68-.Ltext0
	.quad	.LVL74-.Ltext0
	.value	0x2
	.byte	0x31
	.byte	0x9f
	.quad	.LVL74-.Ltext0
	.quad	.LVL80-.Ltext0
	.value	0x2
	.byte	0x32
	.byte	0x9f
	.quad	.LVL80-.Ltext0
	.quad	.LVL86-.Ltext0
	.value	0x2
	.byte	0x33
	.byte	0x9f
	.quad	.LVL86-.Ltext0
	.quad	.LVL87-.Ltext0
	.value	0x2
	.byte	0x34
	.byte	0x9f
	.quad	0
	.quad	0
.LLST23:
	.quad	.LVL51-.Ltext0
	.quad	.LVL88-1-.Ltext0
	.value	0x1
	.byte	0x54
	.quad	.LVL88-1-.Ltext0
	.quad	.LFE37-.Ltext0
	.value	0x4
	.byte	0xf3
	.uleb128 0x1
	.byte	0x54
	.byte	0x9f
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
	.quad	.LBB12-.Ltext0
	.quad	.LBE12-.Ltext0
	.quad	.LBB20-.Ltext0
	.quad	.LBE20-.Ltext0
	.quad	.LBB29-.Ltext0
	.quad	.LBE29-.Ltext0
	.quad	.LBB31-.Ltext0
	.quad	.LBE31-.Ltext0
	.quad	.LBB33-.Ltext0
	.quad	.LBE33-.Ltext0
	.quad	.LBB35-.Ltext0
	.quad	.LBE35-.Ltext0
	.quad	.LBB37-.Ltext0
	.quad	.LBE37-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB21-.Ltext0
	.quad	.LBE21-.Ltext0
	.quad	.LBB30-.Ltext0
	.quad	.LBE30-.Ltext0
	.quad	.LBB32-.Ltext0
	.quad	.LBE32-.Ltext0
	.quad	.LBB34-.Ltext0
	.quad	.LBE34-.Ltext0
	.quad	.LBB36-.Ltext0
	.quad	.LBE36-.Ltext0
	.quad	.LBB38-.Ltext0
	.quad	.LBE38-.Ltext0
	.quad	.LBB39-.Ltext0
	.quad	.LBE39-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB46-.Ltext0
	.quad	.LBE46-.Ltext0
	.quad	.LBB51-.Ltext0
	.quad	.LBE51-.Ltext0
	.quad	.LBB58-.Ltext0
	.quad	.LBE58-.Ltext0
	.quad	.LBB60-.Ltext0
	.quad	.LBE60-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB52-.Ltext0
	.quad	.LBE52-.Ltext0
	.quad	.LBB57-.Ltext0
	.quad	.LBE57-.Ltext0
	.quad	.LBB59-.Ltext0
	.quad	.LBE59-.Ltext0
	.quad	.LBB61-.Ltext0
	.quad	.LBE61-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB68-.Ltext0
	.quad	.LBE68-.Ltext0
	.quad	.LBB72-.Ltext0
	.quad	.LBE72-.Ltext0
	.quad	.LBB77-.Ltext0
	.quad	.LBE77-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB73-.Ltext0
	.quad	.LBE73-.Ltext0
	.quad	.LBB78-.Ltext0
	.quad	.LBE78-.Ltext0
	.quad	.LBB79-.Ltext0
	.quad	.LBE79-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB86-.Ltext0
	.quad	.LBE86-.Ltext0
	.quad	.LBB90-.Ltext0
	.quad	.LBE90-.Ltext0
	.quad	.LBB95-.Ltext0
	.quad	.LBE95-.Ltext0
	.quad	0
	.quad	0
	.quad	.LBB91-.Ltext0
	.quad	.LBE91-.Ltext0
	.quad	.LBB96-.Ltext0
	.quad	.LBE96-.Ltext0
	.quad	.LBB97-.Ltext0
	.quad	.LBE97-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF90:
	.string	"setRotationMat4"
.LASF46:
	.string	"_shortbuf"
.LASF117:
	.string	"_IO_lock_t"
.LASF68:
	.string	"setCameraTransformMat4"
.LASF65:
	.string	"stderr"
.LASF35:
	.string	"_IO_buf_end"
.LASF78:
	.string	"degrees"
.LASF85:
	.string	"mulMat4"
.LASF17:
	.string	"_POSIX_"
.LASF20:
	.string	"signgam"
.LASF33:
	.string	"_IO_write_end"
.LASF3:
	.string	"unsigned int"
.LASF19:
	.string	"_LIB_VERSION_TYPE"
.LASF27:
	.string	"_flags"
.LASF76:
	.string	"rdist"
.LASF72:
	.string	"side"
.LASF39:
	.string	"_markers"
.LASF91:
	.string	"xync"
.LASF12:
	.string	"Mat4"
.LASF108:
	.string	"vec3copySub"
.LASF114:
	.string	"/home/user/projects/openGL/test/math"
.LASF15:
	.string	"_SVID_"
.LASF59:
	.string	"_pos"
.LASF64:
	.string	"stdout"
.LASF38:
	.string	"_IO_save_end"
.LASF0:
	.string	"float"
.LASF111:
	.string	"malloc"
.LASF24:
	.string	"long long unsigned int"
.LASF18:
	.string	"_ISOC_"
.LASF86:
	.string	"setRotZMat4"
.LASF67:
	.string	"sys_errlist"
.LASF37:
	.string	"_IO_backup_base"
.LASF48:
	.string	"_offset"
.LASF66:
	.string	"sys_nerr"
.LASF41:
	.string	"_fileno"
.LASF79:
	.string	"rotateYMat4"
.LASF22:
	.string	"size_t"
.LASF30:
	.string	"_IO_read_base"
.LASF14:
	.string	"_IEEE_"
.LASF63:
	.string	"stdin"
.LASF57:
	.string	"_next"
.LASF87:
	.string	"radians"
.LASF70:
	.string	"setLookAtMat4"
.LASF95:
	.string	"setTranslationMat4"
.LASF107:
	.string	"vec3copy"
.LASF25:
	.string	"matrix44f32_t"
.LASF10:
	.string	"char"
.LASF54:
	.string	"_mode"
.LASF56:
	.string	"_IO_marker"
.LASF28:
	.string	"_IO_read_ptr"
.LASF21:
	.string	"_LIB_VERSION"
.LASF11:
	.string	"data"
.LASF106:
	.string	"vec3dot"
.LASF74:
	.string	"aspect"
.LASF31:
	.string	"_IO_write_base"
.LASF60:
	.string	"_IO_2_1_stdin_"
.LASF23:
	.string	"long long int"
.LASF101:
	.string	"printf"
.LASF61:
	.string	"_IO_2_1_stdout_"
.LASF36:
	.string	"_IO_save_base"
.LASF109:
	.string	"vec3copyCross"
.LASF69:
	.string	"setLookAtMat4FP"
.LASF71:
	.string	"forward"
.LASF75:
	.string	"near"
.LASF105:
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
.LASF45:
	.string	"_vtable_offset"
.LASF88:
	.string	"setRotYMat4"
.LASF120:
	.string	"sincosf"
.LASF29:
	.string	"_IO_read_end"
.LASF80:
	.string	"rotateXMat4"
.LASF115:
	.string	"vec3f32_t"
.LASF6:
	.string	"short int"
.LASF7:
	.string	"long int"
.LASF121:
	.string	"__builtin_sincosf"
.LASF119:
	.string	"__stack_chk_fail"
.LASF102:
	.string	"vec3set"
.LASF118:
	.string	"_IO_FILE_plus"
.LASF103:
	.string	"vec3sub"
.LASF110:
	.string	"free"
.LASF99:
	.string	"destroyMat4"
.LASF104:
	.string	"vec3normalize"
.LASF47:
	.string	"_lock"
.LASF4:
	.string	"long unsigned int"
.LASF116:
	.string	"Vec3"
.LASF43:
	.string	"_old_offset"
.LASF26:
	.string	"_IO_FILE"
.LASF96:
	.string	"setIdentityMat4"
.LASF112:
	.string	"GNU C99 7.2.0 -masm=intel -mtune=generic -march=x86-64 -g -O3 -std=gnu99"
.LASF83:
	.string	"translateMat4"
.LASF1:
	.string	"unsigned char"
.LASF58:
	.string	"_sbuf"
.LASF82:
	.string	"scaleMat4"
.LASF73:
	.string	"setPerspectiveMat4"
.LASF32:
	.string	"_IO_write_ptr"
.LASF98:
	.string	"printMat4"
.LASF97:
	.string	"setMat4"
.LASF113:
	.string	"src/Mat4.c"
.LASF81:
	.string	"rotateMat4"
.LASF8:
	.string	"__off_t"
.LASF5:
	.string	"signed char"
.LASF2:
	.string	"short unsigned int"
.LASF92:
	.string	"xznc"
.LASF94:
	.string	"setScaledMat4"
.LASF13:
	.string	"double"
.LASF40:
	.string	"_chain"
.LASF89:
	.string	"setRotXMat4"
.LASF42:
	.string	"_flags2"
.LASF77:
	.string	"rotateZMat4"
.LASF93:
	.string	"yznc"
.LASF44:
	.string	"_cur_column"
.LASF84:
	.string	"dest"
.LASF16:
	.string	"_XOPEN_"
.LASF62:
	.string	"_IO_2_1_stderr_"
.LASF9:
	.string	"__off64_t"
.LASF55:
	.string	"_unused2"
.LASF34:
	.string	"_IO_buf_base"
.LASF100:
	.string	"newMat4"
	.ident	"GCC: (GNU) 7.2.0"
	.section	.note.GNU-stack,"",@progbits
