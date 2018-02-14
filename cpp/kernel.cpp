#include <Kernel.h>
#include <libk.h>

Kernel::Kernel()
{
	printk("here !\n");
	this->_gdt = &g_gdt;
}
