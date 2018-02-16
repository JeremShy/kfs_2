#include <libk.h>
#include <Gdt.h>

Gdt::Gdt()
{
	_gdt = (struct gdt_entry*)0x00000800;
	_descriptor.limit = (sizeof(struct gdt_entry) * 5) - 1;
	_descriptor.base = 0x00000800;
	print_status("Global Descriptor Table", VGA_COLOR_GREEN, "OK");
}

static void	gdt_set_gate(struct gdt_entry* entry, uint32_t base, uint32_t limit, uint8_t access)
{
	entry->base_low    = (base & 0xFFFF);
	entry->base_middle = (base >> 16) & 0xFF;
	entry->base_high   = (base >> 24) & 0xFF;


	if (limit > 65536) {
        // Adjust granularity if required
        entry->limit_low = limit >> 12;
        entry->granularity = 0xC0;
    } else {
        entry->granularity = 0x40;
    }

	entry->limit_low   = (limit & 0xFFFF);
	entry->granularity |= (limit >> 16) & 0x0F;
	entry->access      = access;
}

void	initGdt()
{
	struct gdt_ptr descriptor;
	struct gdt_entry	*gdt;

	gdt = (struct gdt_entry*)0x00000800;
	descriptor.limit = (sizeof(struct gdt_entry) * 5) - 1;
	descriptor.base = 0x00000800;

	gdt_set_gate(gdt + 0, 0, 0, 0);               		 	// Null segment
    gdt_set_gate(gdt + 1, 0x00000000, 0xffffffff, 0x9A);	// Code segment
    gdt_set_gate(gdt + 2, 0x00000000, 0xffffffff, 0x92);	// Data segment
	gdt_set_gate(gdt + 3, 0x00000000, 0, 0x97);				// Kernel stack segment
    gdt_set_gate(gdt + 4, 0x00000000, 0xffffffff, 0xFA); 	// User mode code segment
	gdt_set_gate(gdt + 5, 0x00000000, 0xffffffff, 0xF2); 	// User mode data segment
    gdt_set_gate(gdt + 6, 0x00000000, 0, 0xF2);				// User mode stack segment

	setGdt(&descriptor);
}
