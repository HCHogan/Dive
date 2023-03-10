	.text
	.file	"avx2.c"
	.file	0 "/home/hank/Development/Dive/csapp" "avx2.c" md5 0x94e0ca5270c423c201b8228677fdd1da
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3                               # -- Begin function main
.LCPI0_0:
	.quad	0x3fef9add3c0e56b8              # double 0.98765432099999994
.LCPI0_1:
	.quad	0x3fbf9add3739635f              # double 0.123456789
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.loc	0 5 0                           # avx2.c:5:0
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
.Ltmp0:
	.loc	0 6 4 prologue_end              # avx2.c:6:4
	vmovsd	.LCPI0_1(%rip), %xmm0           # xmm0 = mem[0],zero
	vmovsd	%xmm0, a(%rip)
	.loc	0 7 4                           # avx2.c:7:4
	vmovsd	.LCPI0_0(%rip), %xmm0           # xmm0 = mem[0],zero
	vmovsd	%xmm0, b(%rip)
.Ltmp1:
	.loc	0 8 5                           # avx2.c:8:5
	vmovsd	a(%rip), %xmm0                  # xmm0 = mem[0],zero
	.loc	0 8 7 is_stmt 0                 # avx2.c:8:7
	vucomisd	b(%rip), %xmm0
.Ltmp2:
	.loc	0 8 5                           # avx2.c:8:5
	jbe	.LBB0_2
# %bb.1:
.Ltmp3:
	.loc	0 8 12                          # avx2.c:8:12
	leaq	.L.str(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	jmp	.LBB0_9
.LBB0_2:
.Ltmp4:
	.loc	0 9 10 is_stmt 1                # avx2.c:9:10
	vmovsd	a(%rip), %xmm1                  # xmm1 = mem[0],zero
	.loc	0 9 14 is_stmt 0                # avx2.c:9:14
	vmovsd	b(%rip), %xmm0                  # xmm0 = mem[0],zero
	.loc	0 9 12                          # avx2.c:9:12
	vucomisd	%xmm1, %xmm0
.Ltmp5:
	.loc	0 9 10                          # avx2.c:9:10
	jbe	.LBB0_4
# %bb.3:
.Ltmp6:
	.loc	0 9 17                          # avx2.c:9:17
	leaq	.L.str.1(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	jmp	.LBB0_8
.LBB0_4:
.Ltmp7:
	.loc	0 10 10 is_stmt 1               # avx2.c:10:10
	vmovsd	a(%rip), %xmm0                  # xmm0 = mem[0],zero
	.loc	0 10 12 is_stmt 0               # avx2.c:10:12
	vucomisd	b(%rip), %xmm0
.Ltmp8:
	.loc	0 10 10                         # avx2.c:10:10
	jne	.LBB0_6
	jp	.LBB0_6
# %bb.5:
.Ltmp9:
	.loc	0 10 18                         # avx2.c:10:18
	leaq	.L.str.2(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
	jmp	.LBB0_7
.LBB0_6:
	.loc	0 11 7 is_stmt 1                # avx2.c:11:7
	leaq	.L.str.3(%rip), %rdi
	movb	$0, %al
	callq	printf@PLT
.Ltmp10:
.LBB0_7:
	.loc	0 0 7 is_stmt 0                 # avx2.c:0:7
	jmp	.LBB0_8
.LBB0_8:
	jmp	.LBB0_9
.LBB0_9:
	.loc	0 13 2 is_stmt 1                # avx2.c:13:2
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Ltmp11:
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

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"OK>\n"
	.size	.L.str, 5

	.type	.L.str.1,@object                # @.str.1
.L.str.1:
	.asciz	"OK<\n"
	.size	.L.str.1, 5

	.type	.L.str.2,@object                # @.str.2
.L.str.2:
	.asciz	"OK=\n"
	.size	.L.str.2, 5

	.type	.L.str.3,@object                # @.str.3
.L.str.3:
	.asciz	"Not OK\n"
	.size	.L.str.3, 8

	.section	.debug_abbrev,"",@progbits
	.byte	1                               # Abbreviation Code
	.byte	17                              # DW_TAG_compile_unit
	.byte	1                               # DW_CHILDREN_yes
	.byte	37                              # DW_AT_producer
	.byte	37                              # DW_FORM_strx1
	.byte	19                              # DW_AT_language
	.byte	5                               # DW_FORM_data2
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	114                             # DW_AT_str_offsets_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	16                              # DW_AT_stmt_list
	.byte	23                              # DW_FORM_sec_offset
	.byte	27                              # DW_AT_comp_dir
	.byte	37                              # DW_FORM_strx1
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	115                             # DW_AT_addr_base
	.byte	23                              # DW_FORM_sec_offset
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	2                               # Abbreviation Code
	.byte	52                              # DW_TAG_variable
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	3                               # Abbreviation Code
	.byte	1                               # DW_TAG_array_type
	.byte	1                               # DW_CHILDREN_yes
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	4                               # Abbreviation Code
	.byte	33                              # DW_TAG_subrange_type
	.byte	0                               # DW_CHILDREN_no
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	55                              # DW_AT_count
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	5                               # Abbreviation Code
	.byte	36                              # DW_TAG_base_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	62                              # DW_AT_encoding
	.byte	11                              # DW_FORM_data1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	6                               # Abbreviation Code
	.byte	36                              # DW_TAG_base_type
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	11                              # DW_AT_byte_size
	.byte	11                              # DW_FORM_data1
	.byte	62                              # DW_AT_encoding
	.byte	11                              # DW_FORM_data1
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	7                               # Abbreviation Code
	.byte	52                              # DW_TAG_variable
	.byte	0                               # DW_CHILDREN_no
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	63                              # DW_AT_external
	.byte	25                              # DW_FORM_flag_present
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	2                               # DW_AT_location
	.byte	24                              # DW_FORM_exprloc
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	8                               # Abbreviation Code
	.byte	46                              # DW_TAG_subprogram
	.byte	0                               # DW_CHILDREN_no
	.byte	17                              # DW_AT_low_pc
	.byte	27                              # DW_FORM_addrx
	.byte	18                              # DW_AT_high_pc
	.byte	6                               # DW_FORM_data4
	.byte	64                              # DW_AT_frame_base
	.byte	24                              # DW_FORM_exprloc
	.byte	3                               # DW_AT_name
	.byte	37                              # DW_FORM_strx1
	.byte	58                              # DW_AT_decl_file
	.byte	11                              # DW_FORM_data1
	.byte	59                              # DW_AT_decl_line
	.byte	11                              # DW_FORM_data1
	.byte	73                              # DW_AT_type
	.byte	19                              # DW_FORM_ref4
	.byte	63                              # DW_AT_external
	.byte	25                              # DW_FORM_flag_present
	.byte	0                               # EOM(1)
	.byte	0                               # EOM(2)
	.byte	0                               # EOM(3)
	.section	.debug_info,"",@progbits
.Lcu_begin0:
	.long	.Ldebug_info_end0-.Ldebug_info_start0 # Length of Unit
.Ldebug_info_start0:
	.short	5                               # DWARF version number
	.byte	1                               # DWARF Unit Type
	.byte	8                               # Address Size (in bytes)
	.long	.debug_abbrev                   # Offset Into Abbrev. Section
	.byte	1                               # Abbrev [1] 0xc:0x8d DW_TAG_compile_unit
	.byte	0                               # DW_AT_producer
	.short	12                              # DW_AT_language
	.byte	1                               # DW_AT_name
	.long	.Lstr_offsets_base0             # DW_AT_str_offsets_base
	.long	.Lline_table_start0             # DW_AT_stmt_list
	.byte	2                               # DW_AT_comp_dir
	.byte	6                               # DW_AT_low_pc
	.long	.Lfunc_end0-.Lfunc_begin0       # DW_AT_high_pc
	.long	.Laddr_table_base0              # DW_AT_addr_base
	.byte	2                               # Abbrev [2] 0x23:0xa DW_TAG_variable
	.long	45                              # DW_AT_type
	.byte	0                               # DW_AT_decl_file
	.byte	8                               # DW_AT_decl_line
	.byte	2                               # DW_AT_location
	.byte	161
	.byte	0
	.byte	3                               # Abbrev [3] 0x2d:0xc DW_TAG_array_type
	.long	57                              # DW_AT_type
	.byte	4                               # Abbrev [4] 0x32:0x6 DW_TAG_subrange_type
	.long	61                              # DW_AT_type
	.byte	5                               # DW_AT_count
	.byte	0                               # End Of Children Mark
	.byte	5                               # Abbrev [5] 0x39:0x4 DW_TAG_base_type
	.byte	3                               # DW_AT_name
	.byte	6                               # DW_AT_encoding
	.byte	1                               # DW_AT_byte_size
	.byte	6                               # Abbrev [6] 0x3d:0x4 DW_TAG_base_type
	.byte	4                               # DW_AT_name
	.byte	8                               # DW_AT_byte_size
	.byte	7                               # DW_AT_encoding
	.byte	2                               # Abbrev [2] 0x41:0xa DW_TAG_variable
	.long	45                              # DW_AT_type
	.byte	0                               # DW_AT_decl_file
	.byte	9                               # DW_AT_decl_line
	.byte	2                               # DW_AT_location
	.byte	161
	.byte	1
	.byte	2                               # Abbrev [2] 0x4b:0xa DW_TAG_variable
	.long	45                              # DW_AT_type
	.byte	0                               # DW_AT_decl_file
	.byte	10                              # DW_AT_decl_line
	.byte	2                               # DW_AT_location
	.byte	161
	.byte	2
	.byte	2                               # Abbrev [2] 0x55:0xa DW_TAG_variable
	.long	95                              # DW_AT_type
	.byte	0                               # DW_AT_decl_file
	.byte	11                              # DW_AT_decl_line
	.byte	2                               # DW_AT_location
	.byte	161
	.byte	3
	.byte	3                               # Abbrev [3] 0x5f:0xc DW_TAG_array_type
	.long	57                              # DW_AT_type
	.byte	4                               # Abbrev [4] 0x64:0x6 DW_TAG_subrange_type
	.long	61                              # DW_AT_type
	.byte	8                               # DW_AT_count
	.byte	0                               # End Of Children Mark
	.byte	7                               # Abbrev [7] 0x6b:0xb DW_TAG_variable
	.byte	5                               # DW_AT_name
	.long	118                             # DW_AT_type
                                        # DW_AT_external
	.byte	0                               # DW_AT_decl_file
	.byte	3                               # DW_AT_decl_line
	.byte	2                               # DW_AT_location
	.byte	161
	.byte	4
	.byte	5                               # Abbrev [5] 0x76:0x4 DW_TAG_base_type
	.byte	6                               # DW_AT_name
	.byte	4                               # DW_AT_encoding
	.byte	8                               # DW_AT_byte_size
	.byte	7                               # Abbrev [7] 0x7a:0xb DW_TAG_variable
	.byte	7                               # DW_AT_name
	.long	118                             # DW_AT_type
                                        # DW_AT_external
	.byte	0                               # DW_AT_decl_file
	.byte	3                               # DW_AT_decl_line
	.byte	2                               # DW_AT_location
	.byte	161
	.byte	5
	.byte	8                               # Abbrev [8] 0x85:0xf DW_TAG_subprogram
	.byte	6                               # DW_AT_low_pc
	.long	.Lfunc_end0-.Lfunc_begin0       # DW_AT_high_pc
	.byte	1                               # DW_AT_frame_base
	.byte	86
	.byte	8                               # DW_AT_name
	.byte	0                               # DW_AT_decl_file
	.byte	5                               # DW_AT_decl_line
	.long	148                             # DW_AT_type
                                        # DW_AT_external
	.byte	5                               # Abbrev [5] 0x94:0x4 DW_TAG_base_type
	.byte	9                               # DW_AT_name
	.byte	5                               # DW_AT_encoding
	.byte	4                               # DW_AT_byte_size
	.byte	0                               # End Of Children Mark
.Ldebug_info_end0:
	.section	.debug_str_offsets,"",@progbits
	.long	44                              # Length of String Offsets Set
	.short	5
	.short	0
.Lstr_offsets_base0:
	.section	.debug_str,"MS",@progbits,1
.Linfo_string0:
	.asciz	"clang version 15.0.7"          # string offset=0
.Linfo_string1:
	.asciz	"avx2.c"                        # string offset=21
.Linfo_string2:
	.asciz	"/home/hank/Development/Dive/csapp" # string offset=28
.Linfo_string3:
	.asciz	"char"                          # string offset=62
.Linfo_string4:
	.asciz	"__ARRAY_SIZE_TYPE__"           # string offset=67
.Linfo_string5:
	.asciz	"a"                             # string offset=87
.Linfo_string6:
	.asciz	"double"                        # string offset=89
.Linfo_string7:
	.asciz	"b"                             # string offset=96
.Linfo_string8:
	.asciz	"main"                          # string offset=98
.Linfo_string9:
	.asciz	"int"                           # string offset=103
	.section	.debug_str_offsets,"",@progbits
	.long	.Linfo_string0
	.long	.Linfo_string1
	.long	.Linfo_string2
	.long	.Linfo_string3
	.long	.Linfo_string4
	.long	.Linfo_string5
	.long	.Linfo_string6
	.long	.Linfo_string7
	.long	.Linfo_string8
	.long	.Linfo_string9
	.section	.debug_addr,"",@progbits
	.long	.Ldebug_addr_end0-.Ldebug_addr_start0 # Length of contribution
.Ldebug_addr_start0:
	.short	5                               # DWARF version number
	.byte	8                               # Address size
	.byte	0                               # Segment selector size
.Laddr_table_base0:
	.quad	.L.str
	.quad	.L.str.1
	.quad	.L.str.2
	.quad	.L.str.3
	.quad	a
	.quad	b
	.quad	.Lfunc_begin0
.Ldebug_addr_end0:
	.ident	"clang version 15.0.7"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
	.addrsig_sym a
	.addrsig_sym b
	.section	.debug_line,"",@progbits
.Lline_table_start0:
