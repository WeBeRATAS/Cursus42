# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 12:09:04 by rbuitrag          #+#    #+#              #
#    Updated: 2024/02/24 11:34:56 by rbuitrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

HEADER = libftprint.h

FLAGS = -Wall -Werror -Wextra

FILES = ft_printf.c 

OFILES = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OFILES)
	ar rc $(NAME) $(OFILES)

%.o:%.c $(HEADER) Makefile
	$(CC) $(FLAGS) $<

clean:
	rm -f $(OFILES)

fclean : clean
	rm -f $(NAME) $(OFILES) a.out

re : fclean all

.PHONY: clean fclean all re
