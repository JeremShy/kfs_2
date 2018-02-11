#ifndef TERMINAL_H
# define TERMINAL_H

# include <types.h>
# include <Cursor.h>

# define VGA_WIDTH 80
# define VGA_HEIGHT 25

class Terminal {
private:
	size_t _row;
	size_t _column;
	uint8_t _color;
	volatile uint16_t* _buffer;
	Cursor _cursor;
	bool	_cursorUpdate;
	bool	_enabled;
	uint16_t	_hiddenBuffer[VGA_WIDTH * VGA_HEIGHT];

	void putEntryAt(char c, uint8_t color, size_t x, size_t y);

public:
	Terminal();
	void putchar(char c);
	void write(const char* data, size_t size);
	void	scrollUp();

	void setColor(uint8_t color);
	uint8_t	getColor();

	void	disableCursor();
	void	enableCursor(uint8_t startLine, uint8_t endLine);

	void	moveCursorTo(int x, int y);

	void	enableCursorUpdate();
	void	disableCursorUpdate();

	void	enable();
	void	disable();

	void	moveCursorPrec();
	void	moveCursorNext();
	void	moveCursorUp();
	void	moveCursorDown();
};

#endif
