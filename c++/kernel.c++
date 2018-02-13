#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>

TerminalManager termManager;

extern "C" void kernel_main(void)
{
	struct	gdt_ptr gdt_descriptor;
	load_dts(&gdt_descriptor); // Load descriptor tables
	asm("   movw $0x18, %ax \n \
	        movw %ax, %ss \n \
	        movl $0x20000, %esp");
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
