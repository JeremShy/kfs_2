#ifndef KERNEL_H
# define KERNEL_H

# include <Gdt.h>
# include <IO.h>
# include <Memory.h>

class IO;

class Kernel {
public:
	IO io;
private:
	Gdt const _gdt;
	Memory _mem;

public:
	Kernel();
	void	init();
	void	halt();
	void	reboot();
};

extern Kernel __kernel;
#endif
