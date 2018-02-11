#include <libk.h>

Terminal::Terminal(void) : _row(0), _column(0), _color(vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK)), _buffer((uint16_t*) 0xB8000), _cursorUpdate(true), _enabled(false)
{
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			_hiddenBuffer[index] = vga_entry(' ', _color);
		}
	}
}

void	Terminal::moveCursorTo(int x, int y)
{
	_cursor.moveCursorTo(x, y);
}

void Terminal::setColor(uint8_t color)
{
	_color = color;
}

void Terminal::putEntryAt(char c, uint8_t color, size_t x, size_t y)
{
	const size_t index = y * VGA_WIDTH + x;
	_buffer[index] = vga_entry(c, color);
}

void	Terminal::enableCursorUpdate()
{
	_cursorUpdate = true;
	_cursor.moveCursorTo(_column, _row);
}
void	Terminal::disableCursorUpdate()
{
	_cursorUpdate = false;
}

void Terminal::putchar(char c)
{
	this->putEntryAt(c, _color, _column, _row);
	if (c == '\n')
		_column = 0;
	else
	{
		if (++_column == VGA_WIDTH) {
			_column = 0;
		}
		else
		{
			if (_cursorUpdate)
				_cursor.moveCursorTo(_column, _row);
			return ;
		}
	}
	if (++_row == VGA_HEIGHT)
	{
		scrollUp();
		_row--;
	}
	if (_cursorUpdate)
		_cursor.moveCursorTo(_column, _row);
}

void Terminal::write(const char* data, size_t size)
{
	disableCursorUpdate();
	for (size_t i = 0; i < size; i++)
		this->putchar(data[i]);
	enableCursorUpdate();
}

void	Terminal::scrollUp()
{
	int	y;
	int	x;
	size_t	index;
	size_t	nindex;

	y = 0;
	while (y < VGA_HEIGHT - 1)
	{
		x = 0;
		while (x < VGA_WIDTH)
		{
			index = y * VGA_WIDTH + x;
			nindex = (y + 1) * VGA_WIDTH + x;
			_buffer[index] = _buffer[nindex];
			x++;
		}
		y++;
	}
	x = 0;
	while (x < VGA_WIDTH)
	{
		index = y * VGA_WIDTH + x;
		_buffer[index] = vga_entry(' ', _color);
		x++;
	}
}


uint8_t	Terminal::getColor()
{
	return (_color);
}


void	Terminal::disableCursor()
{
	_cursor.disable();
}

void	Terminal::enableCursor(uint8_t startLine, uint8_t endLine)
{
	_cursor.enable(startLine, endLine);
}

void	Terminal::enable()
{
	_enabled = true;
	volatile_memcpy(_buffer, _hiddenBuffer, sizeof(_hiddenBuffer));
	moveCursorTo(_column, _row);
}

void	Terminal::disable()
{
	_enabled = false;
	volatile_memcpy(_hiddenBuffer, _buffer, sizeof(_hiddenBuffer));
}

void	Terminal::moveCursorPrec()
{
	if (_column > 0)
	{
		_column--;
	}
	else if (_row > 0)
	{
		_column = VGA_WIDTH - 1;
		_row--;
	}
	else
	{
		return ;
	}
	moveCursorTo(_column, _row);
}

void	Terminal::moveCursorNext()
{
	if (_column < VGA_WIDTH - 1)
	{
		_column++;
	}
	else if (_row < VGA_HEIGHT - 1)
	{
		_column = 0;
		_row++;
	}
	else
	{
		return ;
	}
	moveCursorTo(_column, _row);
}

void Terminal::moveCursorUp()
{
	if (_row > 0)
	{
		_row--;
		moveCursorTo(_column, _row);
	}
}

void Terminal::moveCursorDown()
{
	if (_row < VGA_HEIGHT - 1)
	{
		_row++;
		moveCursorTo(_column, _row);
	}
}
