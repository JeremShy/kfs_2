#include <libk.h>
#include <stdarg.h>
#include <descriptor_table.h>
#include <boot.h>
#include <Kernel.h>
#include <Shell.h>

// extern IO __io;

Kernel	__kernel;
// IO		__io;

void kernel_main(struct multiboot_info *infos, unsigned int magic)
{
	__kernel.init();
	IO::putstr_color("Hello, kernel World ! How are you ?\n", VGA_COLOR_CYAN);
	IO::putstr_color("coucou\n", VGA_COLOR_RED);
	printk("Magic : %x\n", magic);
	printk("Infos : %x\n", infos);
	Shell shell;
	int	i;

	if ((infos->flags & FLAG_MEM_SET) != 0)
	{
		printk("mem is set !\n");
		printk("mem_lower = %x (= %d) and mem_upper = %x( = %d)\n", infos->mem_lower, infos->mem_lower, infos->mem_upper, infos->mem_upper);
		multiboot_memory_map_t *mmap = (multiboot_memory_map_t*)infos->mmap_addr;
		i = 0;

		uint64_t total_length;

		total_length = 0;
		// while ((uint32_t)mmap < infos->mmap_addr + infos->mmap_length)
		// {
		// 	uint64_t	baddr;
		// 	uint64_t	length;

		// 	baddr =  ((uint64_t)mmap->base_addr_high << 32) + mmap->base_addr_low;
		// 	length = ((uint64_t)mmap->length_high << 32)    + mmap->length_low;

		// 	printk(
		// 			"page %d : base_addr : %x, length : %x - base_addr + length : %x\n",
		// 			i,
		// 			(uint32_t)baddr,
		// 			(uint32_t)length,
		// 			(uint32_t)(baddr + length)
		// 		);
		// 	total_length += length;
		// 	mmap = (multiboot_memory_map_t *)((uint32_t)mmap + mmap->size + sizeof(mmap->size));
		// 	i++;
		// }
		// printk("total_length : %x\n", (uint32_t)total_length);
	}
	shell.start();
}
