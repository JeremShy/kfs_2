.global print_stack

print_stack:
	push %ebp
	mov %esp, %ebp
	push %edi
	push %esi

	lea .hello, %eax
	push %eax
	call printk
	add %esp, 4

	mov $0, %edi // i
	mov $0, %esi

.debut:
	mov %edi, %ebx
	mov $0x20000, %eax
	shl %ebx
	shl %ebx
	sub %ebx, %eax
	push (%eax)
	push %eax

	lea .msg, %eax
	push %eax

	call printk // printk(msg, addr, *addr)

	pop %eax
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

.hello:
	.asciz "Stack : \n"
