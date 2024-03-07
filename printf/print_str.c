/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:37:39 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/06 16:26:12 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	/*int	count;

	count = 0;
	if (str == 0 || !str)
	{
		write(1, "(null)", 6);
		count = -1;
		return (6);
	}
	while (*str != '\0' && count >= 0)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	if (count == -1)
		return (-1);
	return (count);*/
	int		i;

	if (str == 0 || !str)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		else
			return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (print_char(str[i++]) < 0)
			return (-1);
	}
	return (i);
}
/*
int main (void)
{
	char	*str;

	str = 0;
	printf("Cadena: %s\n", str);
	printf("\nMi print str dice: %d\n", print_str(str));
	return (0);
}*/
