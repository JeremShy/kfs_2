#include <libk.h>

void putstr_color(const char *data, uint8_t color)
{
	uint8_t oldcolor = termManager.getActualTerm()->getColor();

	termManager.getActualTerm()->setColor(color);
	putstr(data);
	termManager.getActualTerm()->setColor(oldcolor);
}
