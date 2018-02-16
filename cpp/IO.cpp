#include <libk.h>
#include <Kernel.h>
#include <IO.h>

IO::IO()
{
	_enabledTerminal = (Terminal*)_terms;
	volatile uint16_t*	buffer = (uint16_t*)0xB8000;

	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			buffer[index] = vga_entry(' ', vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK));
		}
	}
	_enabledTerminal->enable();
	print_status("Input / Output", VGA_COLOR_GREEN, "OK");
}

void IO::_switchTerminal(int nbr)
{
	if (nbr > NB_TERMS)
		return ;
	if (_enabledTerminal == _terms + nbr)
		return ;
	_enabledTerminal->disable();
	_enabledTerminal = _terms + nbr;
	_enabledTerminal->enable();
}

void	IO::_putstr(const char *str)
{
	_enabledTerminal->write(str, strlen(str));
}

void	IO::_putstr_color(const char *str, uint8_t color)
{
	uint8_t oldcolor = _enabledTerminal->getColor();

	_enabledTerminal->setColor(color);
	_putstr(str);
	_enabledTerminal->setColor(oldcolor);
}

int	IO::_putchar(int c)
{
	_enabledTerminal->putchar(c);
	return (c);
}

void	IO::_moveCursorPrec()
{
	_enabledTerminal->moveCursorPrec();
}
void	IO::_moveCursorNext()
{
	_enabledTerminal->moveCursorNext();
}
void	IO::_moveCursorUp()
{
	_enabledTerminal->moveCursorUp();
}
void	IO::_moveCursorDown()
{
	_enabledTerminal->moveCursorDown();
}

Terminal	*IO::getActualTerm()
{
	return (_enabledTerminal);
}

char IO::_getScancode()
{
    while (!(inb(0x64) & 1));
    return inb(0x60);
}

KeyComb IO::getKeyComb_down()
{
	KeyComb ret;
	unsigned char code;
	int	ignore = 0;
    do
	{
		ignore = 0;
		code = IO::_getScancode();
		if (code == 0x2A || code == 0x36)
		{
			ret.pressShift();
			ignore = 1;
		}
		else if (code == 0x1D)
		{
			ret.pressCtrl();
			ignore = 1;
		}
		else if (code == 0xB8)
		{
			ret.pressAlt();
			ignore = 1;
		}
	} while (ignore || code & 0x80);
	ret.setKeyFromScancode(code);
	return (ret);
}


void	IO::putstr(const char *str)
{
	__kernel.io->_putstr(str);
}
void	IO::putstr_color(const char *str, uint8_t color)
{
	__kernel.io->_putstr_color(str, color);
}
int	IO::putchar(int c)
{
	__kernel.io->_putchar(c);
	return (c);
}
void	IO::moveCursorPrec()
{
	__kernel.io->_moveCursorPrec();
}
void	IO::moveCursorNext()
{
	__kernel.io->_moveCursorNext();
}
void	IO::moveCursorUp()
{
	__kernel.io->_moveCursorUp();
}
void	IO::moveCursorDown()
{
	__kernel.io->_moveCursorDown();
}

void	IO::switchTerminal(int nterm)
{
	__kernel.io->_switchTerminal(nterm);
}
