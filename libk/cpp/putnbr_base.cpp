#include <libk.h>

void	putnbr_base(unsigned int nbr, uint8_t base)
{
	if (base > 16 || base <= 1)
	{
		printk("Error : Can't print a number of base %d\n", base);
		return ;
	}
	char	digits[17] = "0123456789abcdef";
	char	buffer[10] = {0};
	int		count = 8;

	int	i = 1;
	int	j = 0;
	while (nbr != 0 || j < 8)
	{
		buffer[count - i] = digits[nbr % base];
		nbr /= base;
		i++;
		j++;
	}
	buffer[count] = '\0';
	putstr(buffer);
}
