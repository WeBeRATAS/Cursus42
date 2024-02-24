/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:48:27 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/02/24 11:49:18 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdarg.h>

static int	print_char(int c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}

static int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

static int	p_digit(long n, int base, int controlhex)
{
	int		count;
	char	*symbols;

	if (n < 0)
	{
		write(1, "-", 1);
		return ((p_digit(-n, base, controlhex) + 1));
	}
	else if (n < base)
	{
		if (controlhex == '0')
			symbols = "0123456789abcdef";
		else
			symbols = "0123456789ABCDEF";
		return (print_char(symbols[n]));
	}
	else
	{
		count = p_digit(n / base, base, controlhex);
		return (count + p_digit(n % base, base, controlhex));
	}
}

static int	print_format(char type, va_list ap)
{
	int		count;
/*	void	*ptr;*/

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(ap, int));
	else if (type == 's')
		count += print_str(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count += p_digit((long)(va_arg(ap, int)), 10, '0');
	else if (type == 'x')
		count += p_digit((long)(va_arg(ap, unsigned int)), 16, '0');
	else if (type == 'X')
		count += p_digit((long)(va_arg(ap, unsigned int)), 16, '1');
/*	else if (type == 'p')
		print_pointer(va_arg(ap, void *));*/
	else if (type == 'u')
		count += p_digit((unsigned long)(va_arg(ap, unsigned int)), 10, '0');
	else if (type == '%')
		count += print_char('%');
	else
		count += write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (write(1, "(null)", 6) != 6)
				return (-1);
			count += print_format(*(++format), ap);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
/*	int	count;*/
	int	i;

/*	count = ft_printf("Caracter My printf %c\n", 'A');
	ft_printf("The num chars My printf %d\n", count);
	count = printf("Caracter printf %c\n", 'A');
	printf("The num chars printf %d\n", count);
	count = ft_printf("hello %s\n", "Perraco");
	ft_printf("The caracteres son MY %d\n", count);
	count = printf("hello %s\n", "Perraco");
	printf("The caracteres con printf son %d\n", count);
	count = ft_printf("Hex de Myprintf X %X\n", 42);
	ft_printf("The caracteres con MY %d\n", count);
	count = printf("Hex de printf X %X\n", 42);
	printf("The hex are printf  %d\n", count);
	count = ft_printf("Hex de Myprintf x %x\n", 42);
	ft_printf("The caracteres con MY %d\n", count);
	count = printf("Hex de printf x %x\n", 42);
	printf("The hex are printf  %d\n", count);
	count = ft_printf("%d\n", INT32_MIN);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%d\n", INT32_MIN);
	printf("The chars written are printf  %d\n", count);
	count = ft_printf("%u\n", INT32_MIN);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%u\n", INT32_MIN);
	printf("The chars written are printf  %d\n", count);
	count = ft_printf("%p\n", (void *)&42);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%p\n", (void *)&42);
	printf("The chars written are printf  %d\n", count);
	count = ft_printf("%i\n", INT32_MAX);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%i\n", INT32_MAX);*/
	i = printf("%s\n", (char *)NULL);
	printf("%d", i);
	ft_printf("My printf %d\n", i);
/*	count = printf("%\n");*/
	// Si el parametro es NULL, escribe (null) Y CUENTA
	// if (write(1, "(null)", 6) != 6)
	// return (-1);
	return (0);
}
