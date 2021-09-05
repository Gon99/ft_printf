/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <goliano-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:55:20 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/10 17:43:18 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(char const *s, unsigned int start)
{
	size_t	i;

	i = 0;
	while (s[start] != '\0')
	{
		i++;
		start++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	l;

	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		substr = (char *)ft_calloc((get_length(s, start) + 1), sizeof(char));
	else
		substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	if (start > ft_strlen(s))
		return (substr);
	i = 0;
	l = ft_strlen(s);
	while (i < len && l > 0)
	{
		substr[i] = s[start + i];
		i++;
		l--;
	}
	substr[i] = '\0';
	return (substr);
}
