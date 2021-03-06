/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:31:36 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/13 16:59:34 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbr(unsigned int n, int *l)
{
	*l = *l + 1;
	if (n > 9)
	{
		ft_putunbr(n / 10, l);
		ft_putchar_fd(n % 10 + '0', 1);
	}
	else
		ft_putchar_fd(n + '0', 1);
}
