#include <descriptor_table.h>
#include <libk.h>

// struct	gdt_entry create_entry(uint32_t	base, uint32_t limit, uint8_t access, uint8_t flags)
// {
// 	struct	gdt_entry ret;
//
// 	ret.limit_0_15 = limit & 0xFFFF; // first two bytes of limit
// 	ret.limit_16_19_flags = ((limit >> 16) && 0x0F);
//
// 	ret.limit_16_19_flags |= (flags & 0xF0);
//
// 	ret.access = access;
//
// 	ret.base_0_15 = base & 0xFFFF; // first two bytes of base
// 	ret.base_16_23 = (base >> 16) & 0xFF;
// 	ret.base_24_31 = (base >> 24) & 0xFF;
//
// 	return (ret);
// }

// static void encodeGdtEntry(uint8_t *target, uint32_t base, uint32_t limit, uint8_t type)
// {
//     // Check the limit to make sure that it can be encoded
//     if ((limit > 65536) && (limit & 0xFFF) != 0xFFF) {
//         printk("You can't do that!");
//     }
//     if (limit > 65536) {
//         // Adjust granularity if required
//         limit = limit >> 12;
//         target[6] = 0xC0;
//     } else {
//         target[6] = 0x40;
//     }
//
//     // Encode the limit
//     target[0] = limit & 0xFF;
//     target[1] = (limit >> 8) & 0xFF;
//     target[6] |= (limit >> 16) & 0xF;
//
//     // Encode the base
//     target[2] = base & 0xFF;
//     target[3] = (base >> 8) & 0xFF;
//     target[4] = (base >> 16) & 0xFF;
//     target[7] = (base >> 24) & 0xFF;
//
//     // And... Type
//     target[5] = type;
// }
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

static void	load_gdt(struct gdt_ptr *descriptor)
{
	struct gdt_entry	*gdt;

	gdt = (struct gdt_entry*)0x00000800;
	descriptor->limit = (sizeof(struct gdt_entry) * 5) - 1;
	descriptor->base = 0x00000800;

	// encodeGdtEntry(gdt, 0, 0, 0);
	// encodeGdtEntry(gdt + 8, 0x00000000, 0xffffffff, 0x9A);
	// encodeGdtEntry(gdt + 16, 0x00000000, 0xffffffff, 0x92);

	gdt_set_gate(gdt + 0, 0, 0, 0);                // Null segment
    gdt_set_gate(gdt + 1, 0x00000000, 0x03ffffff, 0x9A); // Code segment
    gdt_set_gate(gdt + 2, 0x00000000, 0x08ffffff, 0x92); // Data segment
    gdt_set_gate(gdt + 3, 0x0c000000, 0x03ffffff, 0xFA); // User mode code segment
    gdt_set_gate(gdt + 4, 0x10000000, 0x03ffffff, 0xF2); // User mode data segment

	setGdt(descriptor);
}

void	load_dts(struct gdt_ptr *descriptor)
{
	load_gdt(descriptor);
}
