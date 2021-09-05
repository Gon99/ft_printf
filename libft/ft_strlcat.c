/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 13:38:44 by goliano-          #+#    #+#             */
/*   Updated: 2021/08/09 12:01:54 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	i = 0;
	if (dstsize <= len1)
		len2 += dstsize;
	else
		len2 += len1;
	while (src[i] != '\0' && len1 + 1 < dstsize)
	{
		dst[len1] = src[i];
		len1++;
		i++;
	}
	dst[len1] = '\0';
	return (len2);
}
