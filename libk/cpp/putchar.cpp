#include <libk.h>

int	putchar(const int c)
{
	__io.putchar(c);
	return (c);
}
