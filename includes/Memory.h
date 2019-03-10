#ifndef MEMORY_H
# define MEMORY_H

# define PAGE_DIRECTORY_ADDRESS 0x1000

# include <libk.h>
# include <types.h>

// Note : PDE = Page Directory Entry
# define PDE_ADDRESS_MASK	0xFFFFF000	// The address must be 4Kb aligned
# define PDE_P_MASK			(1 << 0)	// Present			: must be 1 to reference a page table
# define PDE_RW_MASK		(1 << 1)	// Read/Write		: if 0, writes may not be allowed to the 4-MByte region controlled by this entry
# define PDE_U_MASK			(1 << 2)	// Users/Supervisor	: if 0, user-mode access not allowed
# define PDE_W_MASK			(1 << 3)	// Write-Through	: if 0, write-back caching is enabled. If not, then write-through caching is enabled. (c'est un peu mystique, j'ai rien compris, j'espere secrètement que ca sert a rien et je vais sagement totalement l'ignorer)
# define PDE_D_MASK			(1 << 4)	// Cache Disable	: If the bit is set, the page will not be cached. Otherwise, it will be. (Useless d'apres OSDev)
# define PDE_A_MASK			(1 << 5)	// Accessed			: used to discover whether a page has been read or written to. If it has, then the bit is set, otherwise, it is not. Note that, this bit will not be cleared by the CPU, so that burden falls on the OS (if it needs this bit at all).
// Bit 6 is ignored.
# define PDE_S_MASK			(1 << 7)	// Page Size		: If the bit is set, then pages are 4 MiB in size. Otherwise, they are 4 KiB. Please note that 4-MiB pages require PSE to be enabled.
typedef uint32_t page_directory_entry_t;

// Note : PTE = Page Directory Entry
# define PTE_ADDRESS_MASK	0xFFFFF000	// The address must be 4Kb aligned
# define PTE_P_MASK			(1 << 0)	// Present			: must be 1 to reference a page table
# define PTE_RW_MASK		(1 << 1)	// Read/Write		: if 0, writes may not be allowed to the 4-MByte region controlled by this entry
# define PTE_U_MASK			(1 << 2)	// Users/Supervisor	: if 0, user-mode access not allowed
# define PTE_W_MASK			(1 << 3)	// Write-Through	: if 0, write-back caching is enabled. If not, then write-through caching is enabled. (c'est un peu mystique, j'ai rien compris, j'espere secrètement que ca sert a rien et je vais sagement totalement l'ignorer)
# define PTE_CD_MASK		(1 << 4)	// Cache Disable	: If the bit is set, the page will not be cached. Otherwise, it will be. (Useless d'apres OSDev)
# define PTE_A_MASK			(1 << 5)	// Accessed			: used to discover whether a page has been read or written to. If it has, then the bit is set, otherwise, it is not. Note that, this bit will not be cleared by the CPU, so that burden falls on the OS (if it needs this bit at all).
# define PTE_D_MASK			(1 << 6)	// Dirty			: indicates whether software has written to the 4-KByte page referenced by this entry
# define PTE_PAT_MASK		(1 << 7)	// PAT				: If the PAT is supported, indirectly determines the memory type used to access the 4-KByte page referenced by this entry (see Section 4.9.2); otherwise, reserved
# define PTE_G_MASK			(1 << 8)	// Global			: if CR4.PGE = 1, determines whether the translation is global
typedef uint32_t page_table_entry_t;



class Memory {
private:
	page_directory_entry_t *_pd;

	page_directory_entry_t	create_one_way_pde(uint16_t first_bits_of_addr, uint8_t pat, uint8_t global, uint8_t user, uint8_t rw);
public:
	Memory();
	void init();
};

#endif


