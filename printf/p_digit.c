/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_digit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:36:46 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/07 15:51:55 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check(int res)
{
	if (res < 0)
		return (-1);
	else
		return (res);
}

int	p_digit(long n, int base, int controlhex)
{
	int		count;
	char	*symbols;

	count = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		else
		{
			count = (p_digit(-n, base, controlhex) + 1);
			if (ft_check(count) < 0)
				return (-1);
		}
	}
	else if (n < base)
	{
		if (controlhex == 0)
			symbols = "0123456789abcdef";
		else
			symbols = "0123456789ABCDEF";
		count = print_char(symbols[n]);
		if (ft_check(count) < 0)
			return (-1);
	}
	else
	{
		count = p_digit(n / base, base, controlhex);
		count = (count + p_digit(n % base, base, controlhex));
		if (ft_check(count) < 0)
			return (-1);
	}
	return (count);
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
