#include <libk.h>

static int      compte(unsigned int nbr, int base)
{
	int ret;

	ret = 0;
	while (nbr != 0)
	{
		nbr /= base;
		ret++;
	}
	return (ret);
}

void	putnbr_base(unsigned int nbr, uint8_t base)
{
	if (base > 16 || base <= 1)
	{
		printk("Error : Can't print a number of base %d\n", base);
		return ;
	}
	char	digits[17] = "0123456789abcdef";
	char	buffer[10] = {0};
	int	count = compte(nbr, base);

	int	i = 1;
	while (nbr != 0)
	{
		buffer[count - i] = digits[nbr % base];
		nbr /= base;
		i++;
	}
	buffer[count] = '\0';
	putstr(buffer);
}
