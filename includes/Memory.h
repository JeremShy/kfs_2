#ifndef MEMORY_H
# define MEMORY_H

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
# define PDE_S_MASK			(1 << 7)	// Page Size		: If the bit is set, then pages are 4 MiB in size. Otherwise, they are 4 KiB. Please note that 4-MiB pages require PSE to be enabled.
typedef uint32_t page_directory_entry;

class Memory {
private:
public:
	Memory();
	void init();
};

#endif



/*
	Fonctionnement pagination :
		Registre cr3 : Addresse du Page Directory (PD)
		PD : Tableau de 1024 * 32bit Page Directory Entry (PDE) Contennant l'adresse d'une Page Table (PT)
		PT : Tableau de 1024 * 32bit Page Table Entry (PTE) contenant l'adresse des pages
	Le kernel doit changer la valeur de cr3 lorsqu'il change de contexte (Par exemple d'application) pour que chaque appli ait un mapping de memoire virtuelle separee des autres.
*/
