	.text
	.file	"avx.c"
	.globl	float_mov                       # -- Begin function float_mov
	.p2align	4, 0x90
	.type	float_mov,@function
float_mov:                              # @float_mov
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	vmovsd	%xmm0, -8(%rbp)
	movq	%rdi, -16(%rbp)
	movq	%rsi, -24(%rbp)
	movq	-16(%rbp), %rax
	vmovsd	(%rax), %xmm0                   # xmm0 = mem[0],zero
	vmovsd	%xmm0, -32(%rbp)
	vmovsd	-8(%rbp), %xmm0                 # xmm0 = mem[0],zero
	movq	-24(%rbp), %rax
	vmovsd	%xmm0, (%rax)
	vmovsd	-32(%rbp), %xmm1                # xmm1 = mem[0],zero
                                        # implicit-def: $xmm0
	vcvtsd2ss	%xmm1, %xmm0, %xmm0
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	float_mov, .Lfunc_end0-float_mov
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI1_0:
	.quad	0x3fef9add3c0e56b8              # double 0.98765432099999994
.LCPI1_1:
	.quad	0x3fbf9add3739635f              # double 0.123456789
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	vmovsd	.LCPI1_1(%rip), %xmm0           # xmm0 = mem[0],zero
	vmovsd	%xmm0, a(%rip)
	vmovsd	.LCPI1_0(%rip), %xmm0           # xmm0 = mem[0],zero
	vmovsd	%xmm0, b(%rip)
	vmovsd	a(%rip), %xmm0                  # xmm0 = mem[0],zero
	leaq	a(%rip), %rdi
	leaq	b(%rip), %rsi
	callq	float_mov
	vmovsd	a(%rip), %xmm0                  # xmm0 = mem[0],zero
	callq	sqrt@PLT
	vmovsd	%xmm0, -16(%rbp)
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	a,@object                       # @a
	.bss
	.globl	a
	.p2align	3
a:
	.quad	0x0000000000000000              # double 0
	.size	a, 8

	.type	b,@object                       # @b
	.globl	b
	.p2align	3
b:
	.quad	0x0000000000000000              # double 0
	.size	b, 8

	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym float_mov
	.addrsig_sym sqrt
	.addrsig_sym a
	.addrsig_sym b
