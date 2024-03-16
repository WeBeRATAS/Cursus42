/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:48:27 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/16 12:16:44 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static int	print_format(char type, va_list ap)
{
	int		count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(ap, int));
	else if (type == 's')
		count += print_str(va_arg(ap, char *));
	else if (type == 'd' || type == 'i')
		count += p_digit((long)(va_arg(ap, int)));
	else if (type == 'x' || type == 'X')
		count += p_hexa((va_arg(ap, unsigned int)), type);
	else if (type == 'u')
		count += print_unsigned((va_arg(ap, unsigned int)));
	else if (type == 'p')
		count += print_pointer(va_arg(ap, unsigned long long));
	else if (type == '%')
		count += print_char('%');
	else
		return (-1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;
	int		i;

	if (!str)
		return (-1);
	va_start(ap, str);
	count = 0;
	i = 0;
	while (str[i] != '\0' && count >= 0)
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i + 1]))
			{
				count += print_format(str[i + 1], ap);
				i++;
			}
		}
		else
			count += print_char(str[i]);
		i++;
		if (count < 0)
			count = -1;
	}
	va_end(ap);
	return (count);
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
