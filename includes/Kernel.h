#ifndef KERNEL_H
# define KERNEL_H

# include <Gdt.h>
# include <IO.h>

extern "C" void kernel_init(struct multiboot_info *infos);

class IO;

class Kernel {
private:
	Gdt * const _gdt;
public:
	IO * const io;
	Kernel();
	void	halt();
	void	reboot();
};

extern Kernel __kernel;
#endif
