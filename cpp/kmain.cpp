#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>
#include <multiboot.h>
#include <Kernel.h>
#include <Shell.h>

TerminalManager termManager;
Gdt	g_gdt;
Kernel _kernel;

void kernel_main(struct multiboot_info *infos)
{
	putstr_color("Hello, kernel World!\nHow are you ?\n", VGA_COLOR_CYAN);
	Shell shell;

	shell.start();
}
