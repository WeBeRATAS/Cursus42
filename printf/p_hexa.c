/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_hexa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 11:50:59 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/23 13:54:34 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_search_hexadecimal(unsigned int num, const char word)
{
	int ctrl;

	ctrl = 0;
	if (num >= 16)
	{
		ft_search_hexadecimal(num / 16, word);
		ft_search_hexadecimal(num % 16, word);
	}
	else if (num < 10)
	{
		if ((print_char(num + '0')) < 0)
				return (-1);
	}
	else if (word == 'x')
	{
		if (print_char(num - 10 + 'a') < 0)
			return (-1);
	}
	if (word == 'X')
	{
		if (print_char(num - 10 + 'A') < 0)
			return (-1);
	}
	return (0);
}

static int	ft_length_hexadecimal(unsigned int num)
{
	int	len;

	len = 0;
	if (num <= 15 && num >= 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	p_hexa(unsigned int num, const char word)
{
	if (num == 0)
	{
		if (print_char('0') < 0)
			return (-1);
	}
	else
		if (ft_search_hexadecimal(num, word) == -1)
			return (-1);
	return (ft_length_hexadecimal(num));
}
