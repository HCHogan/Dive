	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_cmp                            ; -- Begin function cmp
	.p2align	2
_cmp:                                   ; @cmp
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #16
	.cfi_def_cfa_offset 16
	str	w0, [sp, #12]
	str	w1, [sp, #8]
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #8]
	subs	w8, w8, w9
	cset	w8, lt
	and	w0, w8, #0x1
	add	sp, sp, #16
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
