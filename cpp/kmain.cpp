#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>
#include <multiboot.h>
#include <Kernel.h>
#include <Shell.h>

extern IO __io;

IO __io;
Gdt	__gdt;
Kernel __kernel;

void kernel_main(struct multiboot_info *infos)
{
	IO::putstr_color("Hello, kernel World!\nHow are you ?\n", VGA_COLOR_CYAN);
	printk("coucou\n");
	Shell shell;

	shell.start();
}
