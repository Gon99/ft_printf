/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:06:05 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/13 17:13:06 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

char	*to_hex(unsigned long int n, int t);
void	ft_putunbr(unsigned int n, int *l);
int		ft_printf(const char *cad, ...);
size_t	ft_strlen(char const *s);
int		ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd, int *l);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(char const *s);

#endif
