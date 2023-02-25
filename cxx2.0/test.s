	.text
	.file	"test.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function __cxx_global_var_init
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	leaq	_ZStL8__ioinit(%rip), %rdi
	callq	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	_ZStL8__ioinit(%rip), %rsi
	leaq	__dso_handle(%rip), %rdx
	callq	__cxa_atexit@PLT
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc
                                        # -- End function
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI1_0:
	.quad	0x4000000000000000              # double 2
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
	subq	$48, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	movl	$0, -20(%rbp)
	movq	_ZSt4cout@GOTPCREL(%rip), %rdi
	movq	%rdi, -40(%rbp)                 # 8-byte Spill
	leaq	.L.str(%rip), %rsi
	callq	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdi
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rsi
	movq	%rsi, -32(%rbp)                 # 8-byte Spill
	callq	_ZNSolsEPFRSoS_E@PLT
	movl	$1, %edi
	movsd	.LCPI1_0(%rip), %xmm0           # xmm0 = mem[0],zero
	callq	_Z6myfuncIidEDTplfp_fp0_ET_T0_
	movq	-40(%rbp), %rdi                 # 8-byte Reload
	callq	_ZNSolsEd@PLT
	movq	-32(%rbp), %rsi                 # 8-byte Reload
	movq	%rax, %rdi
	callq	_ZNSolsEPFRSoS_E@PLT
	movl	x(%rip), %esi
	leaq	-16(%rbp), %rdi
	callq	_ZZ4mainEN3$_0clEi
	movq	%fs:40, %rax
	movq	-8(%rbp), %rcx
	cmpq	%rcx, %rax
	jne	.LBB1_2
# %bb.1:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB1_2:
	.cfi_def_cfa %rbp, 16
	callq	__stack_chk_fail@PLT
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.section	.text._Z6myfuncIidEDTplfp_fp0_ET_T0_,"axG",@progbits,_Z6myfuncIidEDTplfp_fp0_ET_T0_,comdat
	.weak	_Z6myfuncIidEDTplfp_fp0_ET_T0_  # -- Begin function _Z6myfuncIidEDTplfp_fp0_ET_T0_
	.p2align	4, 0x90
	.type	_Z6myfuncIidEDTplfp_fp0_ET_T0_,@function
_Z6myfuncIidEDTplfp_fp0_ET_T0_:         # @_Z6myfuncIidEDTplfp_fp0_ET_T0_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movsd	%xmm0, -16(%rbp)
	cvtsi2sdl	-4(%rbp), %xmm0
	addsd	-16(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	_Z6myfuncIidEDTplfp_fp0_ET_T0_, .Lfunc_end2-_Z6myfuncIidEDTplfp_fp0_ET_T0_
	.cfi_endproc
                                        # -- End function
	.text
	.p2align	4, 0x90                         # -- Begin function _ZZ4mainEN3$_0clEi
	.type	_ZZ4mainEN3$_0clEi,@function
_ZZ4mainEN3$_0clEi:                     # @"_ZZ4mainEN3$_0clEi"
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	_ZZ4mainEN3$_0clEi, .Lfunc_end3-_ZZ4mainEN3$_0clEi
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function _GLOBAL__sub_I_test.cpp
	.type	_GLOBAL__sub_I_test.cpp,@function
_GLOBAL__sub_I_test.cpp:                # @_GLOBAL__sub_I_test.cpp
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	callq	__cxx_global_var_init
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end4:
	.size	_GLOBAL__sub_I_test.cpp, .Lfunc_end4-_GLOBAL__sub_I_test.cpp
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object          # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.type	x,@object                       # @x
	.data
	.globl	x
	.p2align	2
x:
	.long	1                               # 0x1
	.size	x, 4

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"hehe"
	.size	.L.str, 5

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_test.cpp
	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __cxx_global_var_init
	.addrsig_sym __cxa_atexit
	.addrsig_sym _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	.addrsig_sym _ZNSolsEPFRSoS_E
	.addrsig_sym _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.addrsig_sym _ZNSolsEd
	.addrsig_sym _Z6myfuncIidEDTplfp_fp0_ET_T0_
	.addrsig_sym _ZZ4mainEN3$_0clEi
	.addrsig_sym _GLOBAL__sub_I_test.cpp
	.addrsig_sym __stack_chk_fail
	.addrsig_sym _ZStL8__ioinit
	.addrsig_sym __dso_handle
	.addrsig_sym x
	.addrsig_sym _ZSt4cout
