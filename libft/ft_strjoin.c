/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:16:03 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/09 15:57:19 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	r;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	r = 0;
	i = 0;
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	while (r < ft_strlen(s2))
	{
		join[i] = s2[r];
		i++;
		r++;
	}
	join[i] = '\0';
	return (join);
}
