#include <Kernel.h>
#include <libk.h>

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

Kernel::Kernel()
{
	this->_gdt = &g_gdt;
}
