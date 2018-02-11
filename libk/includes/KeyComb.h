#ifndef KEYCOMB_H
# define KEYCOMB_H
# include <types.h>

# define KEYCOMB_SHIFT (1 << 0)
# define KEYCOMB_CTRL (1 << 1)
# define KEYCOMB_ALT (1 << 2)
# define KEYCOMB_ASCII (1 << 3)

class KeyComb
{
private:
	int	_flags;
	char	_ascii;
	char	_code;

	void	setAscii(bool val);

	static constexpr unsigned char scancode[128] =
	{
	    0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b', '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',  0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';','\'', '`',  0,'\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',  0, '*',  0, ' ',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, '-',  0,  0,  0, '+',  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	};

	static constexpr unsigned char majscancode[128] =
	{
	    0, 27, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '\b', '\t', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n',   0, 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~',  0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',  0, '*',   0, ' ',   0,   0,   0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0, '_',   0,   0,   0, '=',   0,   0,   0,   0,   0,   0,  0,  0,   0,   0,   0,
	};

public:
	KeyComb	();
	KeyComb (KeyComb const & src);

	void setKeyFromScancode(char scancode);

	bool	isShiftPressed();
	bool	isCtrlPressed();
	bool	isAltPressed();
	bool	isAscii();

	void	pressShift();
	void	pressCtrl();
	void	pressAlt();

	char	getAscii();
	char	getCode();

	void	describe();
};

#endif
