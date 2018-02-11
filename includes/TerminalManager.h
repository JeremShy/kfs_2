#ifndef TERMINAL_MANAGER_H

# define TERMINAL_MANAGER_H
# include <Terminal.h>
# include <types.h>

# define NB_TERMS 3

class TerminalManager
{
private:
	Terminal	_terms[NB_TERMS];
	Terminal	*_enabledTerminal;
public:
	TerminalManager();
	void	switchTerminal(int nterm);
	Terminal	*getActualTerm();
};
#endif
