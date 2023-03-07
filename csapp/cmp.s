	.text
	.file	"cmp.c"
	.globl	cmp                             # -- Begin function cmp
	.p2align	4, 0x90
	.type	cmp,@function
cmp:                                    # @cmp
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	movl	-4(%rbp), %eax
	cmpl	-8(%rbp), %eax
	setl	%al
	andb	$1, %al
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	cmp, .Lfunc_end0-cmp
	.cfi_endproc
                                        # -- End function
	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
