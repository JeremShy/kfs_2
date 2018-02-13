.global print_stack

print_stack:
	push %ebp
	mov %esp, %ebp

	mov $0, %edi // i
	mov $0, %esi

.debut:
	mov %ss:10, %eax
	push %eax

	lea .msg, %eax
	push %eax

	call printk

	inc %edi
	cmp $1, %edi
	je .fin
	jmp .debut

.fin:
	mov %ebp, %esp
	pop %ebp
	ret

.msg:
	.ascii "Function : %p\n"
	.long 0
