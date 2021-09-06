#include "../libft/libft.h"

#include <stdarg.h>

void print_str(char *cad)
{
	int i;
	char *word;

	i = 0;
	word = ft_strdup(cad);
	while (word[i])
	{
		write(1, &word[i], 1);
		i++;
	}
	free(word);
}

static int hex_length(int n)
{
	int count;

	count = 1;
	while (n / 16 > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

char*	to_hex(int n)
{
	int	l;
	char	*hex;
	int	aux;
	int	i;

	l = hex_length(n);
	hex = malloc(sizeof(char) * (l + 1));
	aux = 0;
	i = l - 1;
	if (!hex)
		return (0);
	while (n != 0)
	{
		aux = n % 16;
		if (aux < 10)
			aux = aux + 48;
		else
			aux = aux + 55;
		hex[i--] = aux;
		n /= 16;
	}
	hex[l] = '\0';
	return (hex);
}

static int handle_formats(char c1, char c2, va_list args)
{
	int	ret;

	ret = 1;
	if (c1 == '%' && c2 == 'c')	
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c1 == '%' && c2 == 's')	
		print_str(va_arg(args, char *));
	/*else if (c1 == '%' && c2 == 'p')	
		print_pointer(va_arg(args, char *));*/
	else if (c1 == '%' && c2 == 'd')	
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c1 == '%' && c2 == 'i')	
		ft_putnbr_fd(va_arg(args, int), 1);
	/*else if (c1 == '%' && c2 == 'u')	
		print_unsigned_int(va_arg(args, char *));*/
	else if (c1 == '%' && c2 == 'x')	
		print_str(to_hex(va_arg(args, int)));
	/*else if (c1 == '%' && c2 == 'X')	
		print_hex_up(va_arg(args, char *));
	else if (c1 == '%' && c2 == '%')	
		print_p_sign(va_arg(args, char *));*/
	else
		ret = 0;
	return (ret);
}

int ft_printf(const char *cad, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args, cad);
	while (cad[i])
	{
		if (handle_formats(cad[i], cad[i + 1], args) == 1)
			i++;
		else
			write(1, &cad[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int main()
{
	//char cad[] = "Hola";
	//int n = 5;
	//float o = 5.2;

	ft_printf("1: %s\n2: %s\n3: %c\n4: %d\n5: %i\n6: %i\n7: %x\n", "hola", "prueba", 'p', 2147483647, 0, -202, -10);
	printf("OR: %x\n", -10);
	//printf("1: %s\n2: %s\n3: %c\n4: %d\n5: %i\n6: %i\n", "hola", "prueba", 'p', 2147483648, 0, -202);
	//ft_printf("%s\n %d\n %f\n", cad, n, o);
	//ft_printf("%s", cad);
}
