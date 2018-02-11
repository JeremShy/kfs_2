#ifndef LIBK_H
# define LIBK_H

# include <terminal.h>
# include <types.h>
# include <inline.h>
# include <Cursor.h>
# include <KeyComb.h>
# include <TerminalManager.h>

// Thank you, GCC, that's nice.
typedef __builtin_va_list va_list;
# define va_start __builtin_va_start
# define va_end __builtin_va_end
# define va_arg __builtin_va_arg

extern TerminalManager termManager;

size_t strlen(const char* str);
void putstr(const char* data);
void putstr_color(const char *data, uint8_t color);
void putnbr(int c);
int	putchar(int c);

char getScancode();
KeyComb getKeyComb_down();

void	moveCursorPrec();
void	moveCursorNext();
void	moveCursorUp();
void	moveCursorDown();


void printk(const char *s, ...);

void	memcpy(void *dest, const void *src, size_t n);
void	volatile_memcpy(void volatile *dest, const void volatile *src, size_t n);

int		strcmp(const char *s1, const char *s2);

// ASM functions
// extern "C"
// {
// }
#endif
