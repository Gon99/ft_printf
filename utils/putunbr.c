#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_putunbr(long n)
{
	if (n > 4294967295)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		ft_putunbr(n);
	}
	else
	{
		if (n > 9)
		{
			ft_putunbr(n / 10);
			ft_putchar_fd(n % 10 + '0', 1);
		}
		else
			ft_putchar_fd(n + '0', 1);
	}
}
