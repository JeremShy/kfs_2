#ifndef GDT_H
# define GDT_H
# include <types.h>

# define GDT_ADDRESS 0x00000800

struct gdt_ptr
{
	uint16_t limit;
	uint32_t base;
}
__attribute__((packed));

extern uint32_t	stack_bottom;

struct gdt_entry
{
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_middle;
	uint8_t  access;
	uint8_t  granularity;
	uint8_t  base_high;
} __attribute__((packed));

extern "C"
{
	void	setGdt(struct gdt_ptr *gdt);
}

class Gdt {
private:
	struct gdt_ptr _descriptor;
	struct gdt_entry	*_gdt;
public:
	Gdt();
};

void	initGdt();

extern Gdt __gdt;

#endif
