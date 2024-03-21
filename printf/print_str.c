/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:37:39 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/21 16:53:33 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int		i;

	if (!str)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		else
			return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (print_char(str[i]) < 0)
			return (-1);
		i++;
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
