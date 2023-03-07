	.text
	.file	"cnd.c"
	.globl	cond                            # -- Begin function cond
	.p2align	4, 0x90
	.type	cond,@function
cond:                                   # @cond
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpq	$0, -16(%rbp)
	je	.LBB0_3
# %bb.1:
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rcx
	cmpq	(%rcx), %rax
	jle	.LBB0_3
# %bb.2:
	movq	-8(%rbp), %rcx
	movq	-16(%rbp), %rax
	movq	%rcx, (%rax)
.LBB0_3:
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	cond, .Lfunc_end0-cond
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
