/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:55:37 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/09 15:26:55 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*str;
	int		i;

	l = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * l + 1);
	i = 0;
	if (str == NULL)
		return (NULL);
	while (i < l)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
