#include <libk.h>

extern "C" void	print_memory_line(const void *addr)
{
	const char	*pouet;
	printk("Addr : %p - Value : %p - ", addr, *(uint32_t*)addr);
	int	i = 0;

	pouet = (const char*)addr;
	while (i < 4)
	{
		if (isprint(pouet[i]))
			printk("%c", pouet[i]);
		else
			printk(".");
		i++;
	}
	printk("\n");
}
