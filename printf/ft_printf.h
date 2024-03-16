/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_printf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:29:59 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/03/16 12:20:36 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdint.h>

int 	print_char(int c);
int 	print_str(char *str);
int 	p_digit(long n);
int 	print_unsigned(unsigned int n);
int 	print_pointer(unsigned long long ptr);
int 	p_hexa(unsigned int num, const char word);
char    *ft_strchr(const char *s, int c);

#endif
