#include <libk.h>

static void	handle_conv(va_list & list, char c)
{
	switch (c)
	{
		case 'c':
			IO::putchar(va_arg(list, int));
			break;
		case 'd':
			putnbr(va_arg(list, int));
			break;
		case 's':
			IO::putstr(va_arg(list, const char *));
			break;
		case 'p':
			IO::putstr("0x");
			putnbr_base(va_arg(list, unsigned int), 16); //this two lines are useless..
			break;
		case 'x':
			putnbr_base(va_arg(list, unsigned int), 16);
			break;
		default:
			IO::putchar('c');
			break;
	}
}

extern "C" void	printk(const char *s, ...)
{
	va_list list;
	int	i;

	va_start(list, s);

	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
			IO::putchar(s[i]);
		else
		{
			if (s[i + 1] != '%')
				handle_conv(list, s[i + 1]);
			else
				IO::putchar('%');
			i++;
		}
		i++;
	}

	va_end(list);
}
