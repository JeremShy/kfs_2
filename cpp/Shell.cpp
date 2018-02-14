#include <libk.h>
#include <TerminalManager.h>
#include <Shell.h>
#include <Kernel.h>

void	Shell::exec_buffer()
{
	if (strcmp(_buffer, "print_stack") == 0)
	{
		print_stack();
	}
	else if (strcmp(_buffer, "halt") == 0)
	{
		_kernel.halt();
	}
	else if (strcmp(_buffer, "reboot") == 0)
	{
		_kernel.reboot();
	}
}

void Shell::start()
{
	memset(_buffer, 255, 0);
	memcpy(_prompt, "# ", 3);
	putstr(_prompt);
	while (1)
	{
		KeyComb comb = getKeyComb_down();
		if (comb.isAscii())
		{
			putchar(comb.getAscii());
			if (comb.getAscii() != '\n')
				appendChar(_buffer, 255, comb.getAscii());
			else
			{
				this->exec_buffer();
				memset(_buffer, 0, 255);
				putstr(_prompt);
			}
		}
		else
		{
			if (comb.getCode() == 16 && comb.isCtrlPressed())
				termManager.switchTerminal(0);
			else if (comb.getCode() == 17 && comb.isCtrlPressed())
				termManager.switchTerminal(1);
			else if (comb.getCode() == 18 && comb.isCtrlPressed())
				termManager.switchTerminal(2);
			else if (comb.getCode() == 75) // Left
				moveCursorPrec();
			else if (comb.getCode() == 77) // Right
				moveCursorNext();
			else if (comb.getCode() == 72) // Up
				moveCursorUp();
			else if (comb.getCode() == 80) // Down
				moveCursorDown();
		}
	}
}
