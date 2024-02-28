/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_digit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:36:46 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/02/24 15:07:43 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_digit(long n, int base, int controlhex)
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
