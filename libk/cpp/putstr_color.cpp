#include <libk.h>

void putstr_color(const char *data, uint8_t color)
{
	__io.putstr_color(data, color);
}
