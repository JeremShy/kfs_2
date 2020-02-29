#ifndef LIBK_H
# define LIBK_H

# include <stddef.h>
# include <types.h>
# include <Terminal.h>
# include <inline.h>
# include <Cursor.h>
# include <KeyComb.h>
# include <IO.h>
# include <gdt.h>

// Thank you, GCC, that's nice.
typedef __builtin_va_list va_list;
# define va_start __builtin_va_start
# define va_end __builtin_va_end
# define va_arg __builtin_va_arg

size_t strlen(const char* str);

void	putnbr(int c);
void	putnbr_base(unsigned int nbr, uint8_t base);

void	print_status(const char *composant, uint8_t color, const char *status);


void	volatile_memcpy(void volatile *dest, const void volatile *src, size_t n);
void	*memset(void *dest, const int c, const size_t n);

char	*appendChar(char *buffer, const size_t size, const char c);

uint8_t	isprint(const char c);

int		strcmp(const char *s1, const char *s2);

// ASM functions
extern "C"
{
	void	print_stack();
	void	print_memory_line(const void *addr);
	void	printk(const char *s, ...);
	void	*memcpy(void *dest, const void *src, size_t n);

}
#endif
