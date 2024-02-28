/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:39:55 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/02/28 15:50:48 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	else
		return (1);
}
/*
int main(void)
{
	char	c[40];

	c = "\001\002\007\v\010\f\r\n";
	printf("%s\n", c);
	print_char((int)c);
	return (0);
}*/
