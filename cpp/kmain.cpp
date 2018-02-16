#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>
#include <multiboot.h>
#include <Kernel.h>
#include <Shell.h>

extern IO __io;

Kernel	__kernel;
IO		__io;
Gdt		__gdt;

void kernel_main(struct multiboot_info *infos)
{
	__kernel.init();
	IO::putstr_color("Hello, kernel World ! How are you ?\n", VGA_COLOR_CYAN);
	IO::putstr_color("coucou\n", VGA_COLOR_RED);
	Shell shell;

	shell.start();
}
