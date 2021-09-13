/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:31:37 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/13 14:39:41 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

