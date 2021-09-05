/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:54:22 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/04 12:13:01 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		found;
	char	*aux;

	found = 0;
	aux = (char *)s;
	c = (char)c;
	if (*aux == c)
		found = 1;
	while (*aux != '\0' && found == 0)
	{
		aux++;
		if (*aux == c)
			found = 1;
	}
	if (found == 0)
		return (NULL);
	return (aux);
}
