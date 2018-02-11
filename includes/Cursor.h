#ifndef CURSOR_H
# define CURSOR_H

# include <types.h>

class Cursor {
public:
	Cursor();
	void	enable(uint8_t startLine, uint8_t endLine);
	void	disable();
	void	moveCursorTo(int x, int y);
private:
};

#endif
