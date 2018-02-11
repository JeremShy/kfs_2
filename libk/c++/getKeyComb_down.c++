#include <libk.h>

char getScancode()
{
    while (!(inb(0x64) & 1));
    return inb(0x60);
}

KeyComb getKeyComb_down()
{
	KeyComb ret;
	unsigned char code;
	int	ignore = 0;
    do
	{
		ignore = 0;
		code = getScancode();
		if (code == 0x2A || code == 0x36)
		{
			ret.pressShift();
			ignore = 1;
		}
		else if (code == 0x1D)
		{
			ret.pressCtrl();
			ignore = 1;
		}
		else if (code == 0xB8)
		{
			ret.pressAlt();
			ignore = 1;
		}
	} while (ignore || code & 0x80);
	ret.setKeyFromScancode(code);
	return (ret);
}
