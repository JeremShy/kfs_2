#include <libk.h>

char	*appendChar(char *buffer, const size_t size, const char c)
{
	size_t	len = strlen(buffer);

	if (len >= size - 1)
		return ((char*)NULL);
	buffer[len] = c;
	buffer[len + 1] = '\0';
	return (buffer);
}
