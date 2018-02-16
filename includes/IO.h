#ifndef IO_H

# define IO_H
# include <Terminal.h>
# include <types.h>
# include <KeyComb.h>

# define NB_TERMS 3

class IO
{
private:
	Terminal	_terms[NB_TERMS];
	Terminal	*_enabledTerminal;

	void	_putstr(const char *str);
	void	_putstr_color(const char *str, uint8_t color);
	int		_putchar(int c);
	void	_moveCursorPrec();
	void	_moveCursorNext();
	void	_moveCursorUp();
	void	_moveCursorDown();
	void	_switchTerminal(int nterm);
	static char _getScancode();

public:
	IO();

	static KeyComb getKeyComb_down();
	static void	putstr(const char *str);
	static void	putstr_color(const char *str, uint8_t color);
	static int	putchar(int c);
	static void	moveCursorPrec();
	static void	moveCursorNext();
	static void	moveCursorUp();
	static void	moveCursorDown();
	static void	switchTerminal(int nterm);

	Terminal	*getActualTerm();

};

#endif
