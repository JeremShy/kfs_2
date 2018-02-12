#include <kernel.h>

struct	gdt_entry create_entry(uint32_t	base, uint32_t limit, uint8_t access, uint8_t flags)
{
	struct	gdt_entry ret;

	if (limit > 0xFFFFF)
	{
		printk("Error : Can't encode this value, limit is a 20 bits value.\n");
		return ret;
	}

	ret.limit_0_15 = limit & 0xFFFF; // first two bytes of limit
	ret.limit_16_19_flags = ((limit >> 16) && 0xF);

	 ret.limit_16_19_flags |= ((flags & 0xF) << 4);

	ret.access = access;

	ret.base_0_15 = base & 0xFFFF; // first two bytes of base
	ret.base_16_23 = (base >> 16) & 0xFF;
	ret.base_24_31 = (base >> 24) & 0xFF;

	return (ret);
}

void	load_gdt()
{
	struct gdt_descriptor descriptor;
	struct gdt_entry	*gdt;

	gdt = (gdt_entry*)0x00000800;
	descriptor.base = (uint32_t)gdt;
	descriptor.limit = sizeof(struct gdt_entry) * 7 - 1;

	*gdt = create_entry(0, 0, 0, 0);
	*(gdt + 1) = create_entry(0, 0xFFFFF, 0x9A, 0xCF);
	*(gdt + 2) = create_entry(0, 0xFFFFF, 0x92, 0xCF);

	setGdt(descriptor.base, descriptor.limit);
}
