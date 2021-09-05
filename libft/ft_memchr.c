/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:36:46 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/03 17:10:37 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*aux;

	i = 0;
	aux = (unsigned char *)s;
	while (n > 0)
	{
		if (*aux == (unsigned char)c)
			return (aux);
		aux++;
		n--;
	}
	return (NULL);
}
