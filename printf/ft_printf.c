/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:48:27 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/21 17:17:14 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	print_format(char type, va_list ap)
{
	if (type == 'c')
		return (print_char(va_arg(ap, int)));
	else if (type == 's')
		return (print_str(va_arg(ap, char *)));
	else if (type == 'd' || type == 'i')
		return (p_digit((long)(va_arg(ap, int))));
	else if (type == 'x' || type == 'X')
		return (p_hexa((va_arg(ap, unsigned int)), type));
	else if (type == 'u')
		return (print_unsigned((va_arg(ap, unsigned int))));
	else if (type == 'p')
		return (print_pointer(va_arg(ap, unsigned long long)));
	else if (type == '%')
		return (print_char('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count_print;
	int		i;
	int		len_print;

	va_start(ap, str);
	count_print = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len_print = -1;
			while (len_print == -1)
				len_print = print_format(str[++i], ap);
			count_print += len_print;
			i++;
			continue ;
		}
		print_char(str[i++]);
		count_print++;
	}
	va_end(ap);
	return (count_print);
}
/*
int	main(void)
{
	int	count;
	int	i;
	
	count = ft_printf("Caracter My printf %c\n", '%');
	ft_printf("The num chars My printf %d\n", count);
	count = printf("printf %c\n", '%');
	printf("num printf %d\n", count);
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
	count =	ft_printf("%p\n", (void *)42);
	count = printf("%p\n", (void *)42);
	printf("The chars written are printf  %d\n", count);
	count = ft_printf("%i\n", INT32_MAX);
	ft_printf("The chars written are MY %d\n", count);
	count = printf("%i\n", INT32_MAX);
	i = printf("%s\n", (char *)NULL);
i = ft_printf("%s\n", (char *)NULL);
	printf("%d\n", i);
	i = ft_printf("My printf %d\n", i);
	//count = printf("%\n");
	// Si el parametro es NULL, escribe (null) Y CUENTA
	// if (write(1, "(null)", 6) != 6)
	// return (-1);
	return (0);
}*/
