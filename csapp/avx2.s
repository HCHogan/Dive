	.text
	.file	"avx2.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rax
	.cfi_def_cfa_offset 16
	movabsq	$4593560419846153055, %rax      # imm = 0x3FBF9ADD3739635F
	movq	%rax, a(%rip)
	movabsq	$4607071218809329336, %rax      # imm = 0x3FEF9ADD3C0E56B8
	movq	%rax, b(%rip)
	leaq	.Lstr.5(%rip), %rdi
	callq	puts@PLT
	xorl	%eax, %eax
	popq	%rcx
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
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

	.type	.Lstr.5,@object                 # @str.5
	.section	.rodata.str1.1,"aMS",@progbits,1
.Lstr.5:
	.asciz	"OK<"
	.size	.Lstr.5, 4

	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
