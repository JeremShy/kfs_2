#include <IO.h>
#include <libk.h>

void	print_status(const char *composant, const uint8_t color, const char *status)
{
	IO::putstr_color("[ ", VGA_COLOR_BLUE);
	IO::putstr_color(composant, VGA_COLOR_BLUE);
	IO::putstr_color(" ]", VGA_COLOR_BLUE);

	IO::putchar(' ');
	if ((strlen(composant) + 4) - (strlen(status) + 1) > 70)
		IO::putchar('.');
	else
	{
		for (size_t i = 0; i < 70 - (strlen(composant) + 4) - (strlen(status) + 1); i++)
			IO::putchar('.');
	}
	IO::putstr_color(" ", color);
	IO::putstr_color(status, color);
	IO::putstr_color("\n", color);
}
