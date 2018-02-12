gdtr:
limit:	.word	0 // For limit storage
base:	.int	0 // For base storage

.global setGdt

setGdt:
   movl   4(%esp), %eax
   mov   %eax, (base)
   movw   8(%esp), %ax
   mov   %ax, (limit)
   lgdt  (gdtr)

   ljmp $0x08, $flush2

flush2:
	mov 0x10, %ax
	mov %ax, %ds
	mov %ax, %es
	mov %ax, %fs
	mov %ax, %gs
	mov %ax, %ss
	ret
