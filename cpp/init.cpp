#include <Gdt.h>
#include <Kernel.h>
#include <libk.h>
#include <boot.h>

extern "C" void kernel_init(struct multiboot_info *infos, unsigned int magic)
{
	if (magic != MULTIBOOT_BOOTLOADER_MAGIC)
		return ;
	initGdt();
	asm("   movw $0x18, %ax \n \
			movw %ax, %ss \n \
			movl $0x20000, %esp");
	kernel_main(infos, magic);
}
