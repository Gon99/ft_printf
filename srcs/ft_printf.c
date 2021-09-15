/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:10:15 by goliano-          #+#    #+#             */
/*   Updated: 2021/09/15 11:00:36 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdarg.h>
#include <stdint.h>

static int	print_str(char *cad, int im)
{
	int		i;
	char	*word;

	i = 0;
	if (!cad)
		word = ft_strdup("(null)");
	else
		word = ft_strdup(cad);
	while (word[i])
	{
		write(1, &word[i], 1);
		i++;
	}
	free(word);
	if (im)
		free(cad);
	if (!cad)
		return (6);
	return (i);
}

static char	*handle_pointer(void *ptr)
{
	char	*hex;
	size_t	l;
	char	*pointer;
	size_t	i;
	size_t	x;

	hex = to_hex((uintptr_t)ptr, 0);
	l = ft_strlen(hex);
	pointer = malloc(sizeof(char) * (l + 4));
	if (!pointer)
		return (0);
	i = 0;
	x = 0;
	ft_strlcpy(pointer, "0x", 3);
	while (pointer[i])
		i++;
	while (hex[x])
		pointer[i++] = hex[x++];
	pointer[i] = '\0';
	free(hex);
	return (pointer);
}

static int	handle_formats(char c1, char c2, va_list args)
{
	int	l;

	l = 0;
	if (c1 == '%' && c2 == 'c')
		l = ft_putchar_fd(va_arg(args, int), 1);
	else if (c1 == '%' && c2 == 's')
		l = print_str(va_arg(args, char *), 0);
	else if (c1 == '%' && c2 == 'p')
		l = print_str(handle_pointer(va_arg(args, unsigned int *)), 1);
	else if (c1 == '%' && (c2 == 'd' || c2 == 'i'))
		ft_putnbr_fd(va_arg(args, int), 1, &l);
	else if (c1 == '%' && c2 == 'u')
		ft_putunbr(va_arg(args, long), &l);
	else if (c1 == '%' && c2 == 'x')
		l = print_str(to_hex(va_arg(args, unsigned int), 0), 1);
	else if (c1 == '%' && c2 == 'X')
		l = print_str(to_hex(va_arg(args, unsigned int), 1), 1);
	else if (c1 == '%' && c2 == '%')
		l = ft_putchar_fd('%', 1);
	else
		l = -1;
	return (l);
}

int	ft_printf(const char *cad, ...)
{
	int		i;
	int		l;
	int		tl;
	va_list	args;

	i = -1;
	va_start(args, cad);
	l = 0;
	tl = 0;
	while (cad[++i])
	{
		l = handle_formats(cad[i], cad[i + 1], args);
		if (l >= 0)
		{
			tl += l;
			i++;
		}
		else
		{
			write(1, &cad[i], 1);
			tl++;
		}
	}
	va_end(args);
	return (tl);
}
