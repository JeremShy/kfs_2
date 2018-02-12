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

   mov 0x10, %ax      // 0x10 is the offset in the GDT to our data segment
   mov %ax, %ds
   mov %ax, %es
   mov %ax, %fs
   mov %ax, %gs
   mov %ax, %ss
   ljmp $0x08, $flush2   // 0x08 is the offset to our code segment: Far jump!

flush2:
   ret               // Returns back to the C code!
