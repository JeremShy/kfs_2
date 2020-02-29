.global print_stack

print_stack:
	push %ebp
	mov %esp, %ebp
	push %edi
	push %esi

	lea .stack_nl, %eax
	push %eax
	call printk
	add %esp, 4

	mov $0, %edi // i
	mov $0, %esi

.debut:
	mov %edi, %ebx
	mov $0x20000, %eax
	int3
	shl %ebx
	shl %ebx
	sub %ebx, %eax
	push %eax
	push %eax

	call print_memory_line // printk(msg, addr, *addr)

	pop %eax // eax = printed addr
	mov %eax, %ebx
	pop %eax

	inc %edi
	cmp %ebp, %ebx
	jle .fin
	jmp .debut

.fin:
	pop %esi
	pop %edi
	mov %ebp, %esp
	pop %ebp
	ret

.msg:
	.asciz "Addr : %p - Value : %p\n"

.stack_nl:
	.asciz "Stack : \n"
