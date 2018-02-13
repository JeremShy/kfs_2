#include <libk.h>

int	putchar(int c)
{
	termManager.getActualTerm()->putchar(c);
	return (c);
}
