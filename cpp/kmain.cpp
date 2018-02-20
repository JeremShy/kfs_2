#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>
#include <boot.h>
#include <Kernel.h>
#include <Shell.h>

// extern IO __io;

Kernel	__kernel;
// IO		__io;

void kernel_main(struct multiboot_info *infos, unsigned int magic)
{
	__kernel.init();
	IO::putstr_color("Hello, kernel World ! How are you ?\n", VGA_COLOR_CYAN);
	IO::putstr_color("coucou\n", VGA_COLOR_RED);
	printk("Magic : %x\n", magic);
	printk("Infos : %x\n", infos);
	Shell shell;

	if ((infos->flags & FLAG_MEM_SET )!= 0)
	{
		printk("mem is set !\n");
		printk("mem_lower = %x (= %d) and mem_upper = %x( = %d)\n", infos->mem_lower, infos->mem_lower, infos->mem_upper, infos->mem_upper);
	}

	shell.start();
}
