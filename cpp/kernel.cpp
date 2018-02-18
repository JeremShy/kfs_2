#include <Kernel.h>
#include <libk.h>

// extern IO	__io;

void	Kernel::halt()
{
	printk("stopping kernel...\n");
}

void	Kernel::reboot()
{
	printk("rebooting...\n");
	uint8_t good = 0x02;
	while (good & 0x02)
		good = inb(0x64);
	outb(0x64, 0xFE);
}

void	Kernel::init()
{
	print_status("First part of kernel", VGA_COLOR_GREEN, "OK");
	_mem.init();
}

Kernel::Kernel() : io(), _gdt(), _mem()
{
}
