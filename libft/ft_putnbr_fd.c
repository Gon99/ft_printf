/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <goliano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 16:17:12 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/10 17:42:30 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', fd);
		n = -n;
		ft_putnbr_fd(n, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putchar(n % 10 + '0', fd);
		}
		else
			ft_putchar(n + '0', fd);
	}
}
