#ifndef DESCRIPTOR_TABLE_H
# define DESCRIPTOR_TABLE_H

# include <types.h>

struct gdt_ptr
{
   uint16_t limit;
   uint32_t base;
}
__attribute__((packed));

struct gdt_entry
{
   uint16_t limit_low;
   uint16_t base_low;
   uint8_t  base_middle;
   uint8_t  access;
   uint8_t  granularity;
   uint8_t  base_high;
} __attribute__((packed));

void	load_dts(struct	gdt_ptr *descriptor); // Load descriptor_tables

extern "C"
{
	void	setGdt(struct gdt_ptr *gdt);
}

#endif
