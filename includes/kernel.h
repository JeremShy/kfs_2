#ifndef KERNEL_H
# define KERNEL_H

# include <libk.h>

struct	gdt_descriptor {
	uint16_t	limit;	// Size of the table minus 1
	uint32_t	base;	// 0x00000800
} __attribute__((packed));;

struct	gdt_entry
{
	uint16_t	limit_0_15;		// Limit Low
	uint16_t	base_0_15;		// Base Low

	uint8_t		base_16_23;	// Base Middle
	uint8_t		access;

	uint8_t		limit_16_19_flags;
	uint8_t		base_24_31;		// Base High
} __attribute__((packed)); // Wtf un peu, quand meme.

void	load_gdt();


extern "C"
{
	void	setGdt(uint32_t base, uint16_t limit);
}

#endif
