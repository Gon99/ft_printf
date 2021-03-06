/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_convertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:01:45 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/10 13:36:22 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	hex_length(unsigned long int n)
{
	int	count;

	count = 1;
	while (n / 16 > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

static void	handle_hex(unsigned long int n, int i, char *hex, int t)
{
	unsigned long int	aux;

	aux = 1;
	while (n != 0)
	{
		aux = n % 16;
		if (aux < 10)
			aux = aux + 48;
		else if (aux >= 10 && t == 1)
			aux = aux + 55;
		else if (aux >= 10 && t == 0)
			aux = aux + 87;
		hex[i--] = aux;
		n /= 16;
	}
}

char	*to_hex(unsigned long int n, int t)
{
	size_t	l;
	char	*hex;

	l = hex_length(n);
	hex = malloc(sizeof(char) * (l + 1));
	if (!hex)
		return (0);
	handle_hex(n, l - 1, hex, t);
	if (n == 0)
		hex[l - 1] = '0';
	hex[l] = '\0';
	return (hex);
}
