	.file	"Cursor.cpp"
	.text
	.type	_ZL3inbt, @function
_ZL3inbt:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movw	%ax, -20(%rbp)
	movzwl	-20(%rbp), %eax
	movl	%eax, %edx
#APP
# 19 "libk/includes/inline.h" 1
	inb %dx, %al
# 0 "" 2
#NO_APP
	movb	%al, -1(%rbp)
	movzbl	-1(%rbp), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	_ZL3inbt, .-_ZL3inbt
	.type	_ZL4outbth, @function
_ZL4outbth:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %edx
	movl	%esi, %eax
	movw	%dx, -4(%rbp)
	movb	%al, -8(%rbp)
	movzbl	-8(%rbp), %eax
	movzwl	-4(%rbp), %edx
#APP
# 25 "libk/includes/inline.h" 1
	outb %al, %dx
# 0 "" 2
#NO_APP
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_ZL4outbth, .-_ZL4outbth
	.align 2
	.globl	_ZN6CursorC2Ev
	.type	_ZN6CursorC2Ev, @function
_ZN6CursorC2Ev:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_ZN6CursorC2Ev, .-_ZN6CursorC2Ev
	.globl	_ZN6CursorC1Ev
	.set	_ZN6CursorC1Ev,_ZN6CursorC2Ev
	.align 2
	.globl	_ZN6Cursor12moveCursorToEii
	.type	_ZN6Cursor12moveCursorToEii, @function
_ZN6Cursor12moveCursorToEii:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$4, %eax
	movl	%eax, %edx
	movl	-28(%rbp), %eax
	addl	%edx, %eax
	movw	%ax, -2(%rbp)
	movl	$15, %esi
	movl	$980, %edi
	call	_ZL4outbth
	movzwl	-2(%rbp), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$981, %edi
	call	_ZL4outbth
	movl	$14, %esi
	movl	$980, %edi
	call	_ZL4outbth
	movzwl	-2(%rbp), %eax
	shrw	$8, %ax
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$981, %edi
	call	_ZL4outbth
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	_ZN6Cursor12moveCursorToEii, .-_ZN6Cursor12moveCursorToEii
	.align 2
	.globl	_ZN6Cursor6enableEhh
	.type	_ZN6Cursor6enableEhh, @function
_ZN6Cursor6enableEhh:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, %ecx
	movl	%edx, %eax
	movb	%cl, -12(%rbp)
	movb	%al, -16(%rbp)
	movl	$10, %esi
	movl	$980, %edi
	call	_ZL4outbth
	movl	$981, %edi
	call	_ZL3inbt
	andl	$-64, %eax
	orb	-12(%rbp), %al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$981, %edi
	call	_ZL4outbth
	movl	$11, %esi
	movl	$980, %edi
	call	_ZL4outbth
	movl	$992, %edi
	call	_ZL3inbt
	andl	$-32, %eax
	orb	-16(%rbp), %al
	movzbl	%al, %eax
	movl	%eax, %esi
	movl	$981, %edi
	call	_ZL4outbth
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	_ZN6Cursor6enableEhh, .-_ZN6Cursor6enableEhh
	.align 2
	.globl	_ZN6Cursor7disableEv
	.type	_ZN6Cursor7disableEv, @function
_ZN6Cursor7disableEv:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$8, %rsp
	movq	%rdi, -8(%rbp)
	movl	$10, %esi
	movl	$980, %edi
	call	_ZL4outbth
	movl	$32, %esi
	movl	$981, %edi
	call	_ZL4outbth
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	_ZN6Cursor7disableEv, .-_ZN6Cursor7disableEv
	.ident	"GCC: (Debian 6.3.0-18) 6.3.0 20170516"
	.section	.note.GNU-stack,"",@progbits
