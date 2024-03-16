/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_digit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:36:46 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/16 10:50:50 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_digit(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		size += print_char('0');
	if (n == -2147483648)
	{
		size += print_str("-2147483648");
		return (size);
	}
	if (n < 0)
	{
		size += print_char('-');
		n = -n;
	}
	if (n > 0)
		size += print_unsigned((unsigned int)n);
	return (size);
}
/*
int	main (void)
{
	int	num;
	int cont;

	num = 4554;

	cont = printf("Numero %d\n", num);
	printf("cont de printf: %d\n", cont);
	cont = p_digit(num, 10, 0);
	printf("\ncont de pdigit: %d\n", cont);
	return (0);
}*/