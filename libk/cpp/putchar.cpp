#include <libk.h>

int	putchar(int c)
{
	__io.putchar(c);
	return (c);
}
