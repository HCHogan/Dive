	.text
	.file	"31.4.c"
	.globl	main                            # -- Begin function main
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
	movb	$0, %al
	callq	func@PLT
	leaq	.L.str(%rip), %rdi
	movl	$100, %esi
	movb	$0, %al
	callq	printf@PLT
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	MAX,@object                     # @MAX
	.section	.rodata,"a",@progbits
	.globl	MAX
	.p2align	2
MAX:
	.long	100                             # 0x64
	.size	MAX, 4

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d"
	.size	.L.str, 3

	.type	buffer,@object                  # @buffer
	.bss
	.globl	buffer
	.p2align	4
buffer:
	.zero	400
	.size	buffer, 400

	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym func
	.addrsig_sym printf
