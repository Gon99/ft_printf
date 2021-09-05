/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:03:27 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/03 16:25:06 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	unsigned char	*aux;

	aux = b;
	while (len > 0)
	{
		*aux = (unsigned char)c;
		len--;
		aux++;
	}
	return (b);
}
