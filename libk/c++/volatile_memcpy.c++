#include <libk.h>

void	volatile_memcpy(void volatile *dest, const void volatile *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char*)dest)[i] = ((const char*)src)[i];
		i++;
	}
}
