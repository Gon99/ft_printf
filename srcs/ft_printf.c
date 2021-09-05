#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

void print_str(char *cad)
{
	int i;
	char *word;

	i = 0;
	word = strdup(cad);
	while (word[i])
	{
		write(1, &word[i], 1);
		i++;
	}
}

int ft_printf(const char *cad, ...)
{
	int	i;
	va_list args;

	i = 0;
	va_start(args, cad);
	while (cad[i])
	{
		if (cad[i] == '%' && cad[i + 1] == 's')
		{
			print_str(va_arg(args, char*));
		}
		write(1, &cad, 1);
		cad++;
	}
	va_end(args);
	return (0);
}

int main()
{
	//char cad[] = "Hola";
	//int n = 5;
	//float o = 5.2;

	ft_printf("1: %s\n2:%s\n", "hola", "prueba");
	//ft_printf("%s\n %d\n %f\n", cad, n, o);
	//ft_printf("%s", cad);
}
