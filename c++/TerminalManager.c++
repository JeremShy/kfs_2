#include <TerminalManager.h>
#include <libk.h>

TerminalManager::TerminalManager()
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
}

void TerminalManager::switchTerminal(int nbr)
{
	if (nbr > NB_TERMS)
		return ;
	if (_enabledTerminal == _terms + nbr)
		return ;
	_enabledTerminal->disable();
	_enabledTerminal = _terms + nbr;
	_enabledTerminal->enable();
}

Terminal	*TerminalManager::getActualTerm()
{
	return (_enabledTerminal);
}
