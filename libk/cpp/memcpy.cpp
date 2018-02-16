#include <libk.h>

void	*memcpy(void *dest, const void *src, const size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((const char*)src)[i];
		i++;
	}
	return (dest);
}
