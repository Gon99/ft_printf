/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:45:50 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/09 12:11:44 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		j;
	size_t	nl;

	j = 0;
	nl = ft_strlen(needle);
	if (nl == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		while (haystack[j] == needle[j])
		{
			if (nl > len)
				return (NULL);
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack);
		}
		j = 0;
		len--;
		haystack++;
	}
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	return (NULL);
}
