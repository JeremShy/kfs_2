#include <libk.h>
#include <IO.h>
#include <Shell.h>
#include <Kernel.h>

void	Shell::execBuffer()
{
	if (strcmp(_buffer, "print_stack") == 0)
	{
		print_stack();
	}
	// else if (strcmp(_buffer, "halt") == 0)
	// {
	// 	__kernel.halt();
	// }
	else if (strcmp(_buffer, "reboot") == 0)
	{
		__kernel.reboot();
	}
}

void	Shell::deleteActualChar()
{
	char	*toDelete = _actualChar - 1;

	while (*toDelete != '\0')
	{
		*toDelete = *(toDelete + 1);
		toDelete++;
	}
	IO::moveCursorPrec();
}

void Shell::start()
{
	memset(_buffer, 255, 0);
	memcpy(_prompt, "# ", 3);
	IO::putstr(_prompt);
	_actualChar = _buffer;
	while (1)
	{
		KeyComb comb = IO::getKeyComb_down();
		if (comb.isAscii())
		{
			if (isprint(comb.getAscii()) || comb.getAscii() == '\n')
				IO::putchar(comb.getAscii());
			else if (comb.getAscii() == 8)
			{
				// if (_actualChar != _buffer)
				// {
				// 	deleteActualChar();
				// }
			}
			if (comb.getAscii() != '\n')
			{
				appendChar(_buffer, 255, comb.getAscii());
				_actualChar++;
			}
			else
			{
				this->execBuffer();
				memset(_buffer, 0, 255);
				_actualChar = _buffer;
				IO::putstr(_prompt);
			}
		}
		else
		{
			if (comb.getCode() == 16 && comb.isCtrlPressed())
				IO::switchTerminal(0);
			else if (comb.getCode() == 17 && comb.isCtrlPressed())
				IO::switchTerminal(1);
			else if (comb.getCode() == 18 && comb.isCtrlPressed())
				IO::switchTerminal(2);
			else if (comb.getCode() == 75) // Left
				IO::moveCursorPrec();
			else if (comb.getCode() == 77) // Right
				IO::moveCursorNext();
			else if (comb.getCode() == 72) // Up
				IO::moveCursorUp();
			else if (comb.getCode() == 80) // Down
				IO::moveCursorDown();
		}
	}
}
