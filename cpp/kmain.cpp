#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>
#include <multiboot.h>
#include <Kernel.h>

TerminalManager termManager;
Gdt	g_gdt;
Kernel _kernel;

void kernel_main(struct multiboot_info *infos)
{
	char buf[20] = "aaaaaaaaaaaaaaaaaaa";
	print_stack();
	putstr_color("Hello, kernel World!\nHow are you ?\n", VGA_COLOR_CYAN);

	while (1)
	{
		KeyComb comb = getKeyComb_down();
		if (comb.isAscii())
		{
			printk("%c", comb.getAscii());
		}
		else
		{
			if (comb.getCode() == 16 && comb.isCtrlPressed())
			{
				termManager.switchTerminal(0);
			}
			else if (comb.getCode() == 17 && comb.isCtrlPressed())
			{
				termManager.switchTerminal(1);
			}
			else if (comb.getCode() == 18 && comb.isCtrlPressed())
			{
				termManager.switchTerminal(2);
			}
			else if (comb.getCode() == 75) // Left
			{
				moveCursorPrec();
			}
			else if (comb.getCode() == 77) // Right
			{
				moveCursorNext();
			}
			else if (comb.getCode() == 72) // Up
			{
				moveCursorUp();
			}
			else if (comb.getCode() == 80) // Down
			{
				moveCursorDown();
			}
		}
	}
}
