#include <Memory.h>

page_directory_entry_t	Memory::create_one_way_pde(uint16_t first_bits_of_addr, uint8_t pat, uint8_t global, uint8_t user, uint8_t rw)
{
	page_directory_entry_t	ret;

	ret = 0;
	ret = (first_bits_of_addr << 22) | (pat << 12) | (global << 8) | (1 << 7) | (user << 2) | (rw << 1) | (1);
	if (first_bits_of_addr < 5)
		printk("ret : %x\n", ret);
	return (ret);
}

void Memory::init()
{
	print_status("Memory", VGA_COLOR_GREEN, "LOADING");

	_pd = (page_directory_entry_t*)PAGE_DIRECTORY_ADDRESS;
	for (int i = 0; i < 1024; i++)
	{
		_pd[i] = create_one_way_pde(i, 0, 1, 1, 1);
	}
}

Memory::Memory()
{
}
