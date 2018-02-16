#include <Gdt.h>
#include <Kernel.h>
#include <libk.h>

extern "C" void kernel_init(struct multiboot_info *infos)
{
	initGdt();
	asm("   movw $0x18, %ax \n \
			movw %ax, %ss \n \
			movl $0x20000, %esp");
	kernel_main(infos);
}
