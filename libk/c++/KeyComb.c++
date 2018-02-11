#include <KeyComb.h>
#include <libk.h>

constexpr unsigned char KeyComb::scancode[128]; // Kamoulox
constexpr unsigned char KeyComb::majscancode[128];

KeyComb::KeyComb() : _flags(0), _ascii(0), _code(0)
{
}

KeyComb::KeyComb (KeyComb const & src) : _flags(src._flags), _ascii(src._ascii), _code(src._code)
{
}

bool	KeyComb::isShiftPressed()
{
	return ((bool)(_flags & KEYCOMB_SHIFT));
}

bool	KeyComb::isCtrlPressed()
{
	bool ret = (_flags & KEYCOMB_CTRL);
	return (ret);
}

bool	KeyComb::isAltPressed()
{
	return ((bool)(_flags & KEYCOMB_ALT));
}

bool	KeyComb::isAscii()
{
	return ((bool)(_flags & KEYCOMB_ASCII));
}

char	KeyComb::getAscii()
{
	return (_ascii);
}

char	KeyComb::getCode()
{
	return (_code);
}


void	KeyComb::pressShift()
{
	_flags |= KEYCOMB_SHIFT;
}

void	KeyComb::pressCtrl()
{
	_flags |= KEYCOMB_CTRL;
}

void	KeyComb::pressAlt()
{
	_flags |= KEYCOMB_ALT;
}

void	KeyComb::setAscii(bool val)
{
	if (val)
		_flags |= KEYCOMB_ASCII;
	else
		_flags = _flags & (~KEYCOMB_ASCII);
}

void KeyComb::setKeyFromScancode(char code)
{
	_code = code;
	if (isAltPressed() || isCtrlPressed())
	{
		setAscii(false);
		return ;
	}
	if (isShiftPressed())
	{
		if (this->majscancode[(unsigned char)code] == '\0')
			setAscii(false);
		else
		{
			setAscii(true);
			_ascii = this->majscancode[(unsigned char)code];
		}
	}
	else
	{
		if (this->scancode[(unsigned char)code] == '\0')
			setAscii(false);
		else
		{
			setAscii(true);
			_ascii = this->scancode[(unsigned char)code];
		}
	}
}

void	KeyComb::describe()
{
	printk("shift: ");
	if (isShiftPressed())
	{
		printk("pressed.\n");
	}
	else
	{
		printk("not pressed.\n");
	}
	printk("Ctrl: ");
	if (isCtrlPressed())
	{
		printk("pressed.\n");
	}
	else
	{
		printk("not pressed.\n");
	}
	printk("Alt: ");
	if (isAltPressed())
	{
		printk("pressed.\n");
	}
	else
	{
		printk("not pressed.\n");
	}
	printk("Code : %d\n", _code);
}
