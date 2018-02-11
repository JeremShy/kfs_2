#include <libk.h>

static	int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

static	void	ft_printing(int taille, int c)
{
	while (taille >= 0)
	{
		putchar((char)(c / (ft_pow(10, taille)) + (int)'0'));
		c %= ft_pow(10, taille);
		taille--;
	}
}

void			putnbr(int c)
{
	int	taille;
	int	tmp;

	if (c == 0)
		putchar('0');
	if (c == -2147483648)
	{
		putstr("-2147483648");
		return ;
	}
	if (c < 0)
	{
		putchar('-');
		c = c * -1;
	}
	tmp = c;
	taille = 0;
	while (tmp != 0)
	{
		tmp /= 10;
		taille += 1;
	}
	taille--;
	ft_printing(taille, c);
}
