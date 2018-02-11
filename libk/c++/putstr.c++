#include <libk.h>

void putstr(const char* data)
{
	termManager.getActualTerm()->write(data, strlen(data));
}
