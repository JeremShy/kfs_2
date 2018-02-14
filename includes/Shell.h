#ifndef SHELL_H
# define SHELL_H

class Shell {
private:
	char	_buffer[255];
	char	_prompt[64];
	void	exec_buffer();
public:
	void	start();
};

#endif
