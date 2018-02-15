#ifndef KERNEL_H
# define KERNEL_H

# include <Gdt.h>

extern "C" void kernel_init(struct multiboot_info *infos);

class Kernel {
private:
	Gdt *_gdt;
public:
	Kernel();
	void	halt();
	void	reboot();
};

extern Kernel _kernel;
#endif