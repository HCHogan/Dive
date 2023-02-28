	.text
	.file	"test03.cpp"
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
	leaq	mytuple(%rip), %rdi
	callq	_ZN5tupleIJidfEEC2Ev
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc
                                        # -- End function
	.section	.text._ZN5tupleIJidfEEC2Ev,"axG",@progbits,_ZN5tupleIJidfEEC2Ev,comdat
	.weak	_ZN5tupleIJidfEEC2Ev            # -- Begin function _ZN5tupleIJidfEEC2Ev
	.p2align	4, 0x90
	.type	_ZN5tupleIJidfEEC2Ev,@function
_ZN5tupleIJidfEEC2Ev:                   # @_ZN5tupleIJidfEEC2Ev
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_ZN5tupleIJdfEEC2Ev
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	_ZN5tupleIJidfEEC2Ev, .Lfunc_end1-_ZN5tupleIJidfEEC2Ev
	.cfi_endproc
                                        # -- End function
	.text
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
	movl	$0, -4(%rbp)
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	main, .Lfunc_end2-main
	.cfi_endproc
                                        # -- End function
	.section	.text._ZN5tupleIJdfEEC2Ev,"axG",@progbits,_ZN5tupleIJdfEEC2Ev,comdat
	.weak	_ZN5tupleIJdfEEC2Ev             # -- Begin function _ZN5tupleIJdfEEC2Ev
	.p2align	4, 0x90
	.type	_ZN5tupleIJdfEEC2Ev,@function
_ZN5tupleIJdfEEC2Ev:                    # @_ZN5tupleIJdfEEC2Ev
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_ZN5tupleIJfEEC2Ev
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	_ZN5tupleIJdfEEC2Ev, .Lfunc_end3-_ZN5tupleIJdfEEC2Ev
	.cfi_endproc
                                        # -- End function
	.section	.text._ZN5tupleIJfEEC2Ev,"axG",@progbits,_ZN5tupleIJfEEC2Ev,comdat
	.weak	_ZN5tupleIJfEEC2Ev              # -- Begin function _ZN5tupleIJfEEC2Ev
	.p2align	4, 0x90
	.type	_ZN5tupleIJfEEC2Ev,@function
_ZN5tupleIJfEEC2Ev:                     # @_ZN5tupleIJfEEC2Ev
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end4:
	.size	_ZN5tupleIJfEEC2Ev, .Lfunc_end4-_ZN5tupleIJfEEC2Ev
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90                         # -- Begin function _GLOBAL__sub_I_test03.cpp
	.type	_GLOBAL__sub_I_test03.cpp,@function
_GLOBAL__sub_I_test03.cpp:              # @_GLOBAL__sub_I_test03.cpp
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
.Lfunc_end5:
	.size	_GLOBAL__sub_I_test03.cpp, .Lfunc_end5-_GLOBAL__sub_I_test03.cpp
	.cfi_endproc
                                        # -- End function
	.type	mytuple,@object                 # @mytuple
	.bss
	.globl	mytuple
	.p2align	3
mytuple:
	.zero	24
	.size	mytuple, 24

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_test03.cpp
	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __cxx_global_var_init
	.addrsig_sym _GLOBAL__sub_I_test03.cpp
	.addrsig_sym mytuple
