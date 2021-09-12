#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putunbr(long n, int *l)
{
	*l = *l + 1;
	if (n > 4294967295)
	{
		ft_putchar_fd('0', 1);
		*l = 10;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		ft_putunbr(n, l);
	}
	else
	{
		if (n > 9)
		{
			ft_putunbr(n / 10, l);
			ft_putchar_fd(n % 10 + '0', 1);
		}
		else
			ft_putchar_fd(n + '0', 1);
	}
}
