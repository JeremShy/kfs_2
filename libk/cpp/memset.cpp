#include <libk.h>

void	*memset(void *s, const int c, const size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)s)[i] = (char)c;
		i++;
	}
	return (s);
}
