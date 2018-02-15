#ifndef SHELL_H
# define SHELL_H

class Shell {
private:
	char	_buffer[255];
	char	_prompt[64];
	char	*_actualChar;
	void	execBuffer();
	void	deleteActualChar();
public:
	void	start();
};

#endif
