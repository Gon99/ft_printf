/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 16:00:46 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/09 12:28:37 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		l;
	int		i;
	int		found;

	l = ft_strlen(s) - 1;
	i = 0;
	if (c == 0)
		return (ft_strlen(s) + (char *)s);
	c = (char)c;
	found = 0;
	while (s[l] != '\0' && found == 0 && l >= 0)
	{
		if (s[l] == c)
			found = 1;
		l--;
	}
	l += 1;
	if (found == 0 || c == '\0')
		return (NULL);
	while (i < l)
	{
		s++;
		i++;
	}
	return ((char *)s);
}
