/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:13:46 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/21 16:42:12 by rbuitrag         ###   ########.fr       */
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
