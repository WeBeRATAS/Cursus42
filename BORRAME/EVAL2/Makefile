# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbuitrag <rbuitrag@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 12:18:38 by rbuitrag          #+#    #+#              #
#    Updated: 2024/02/09 15:31:10 by rbuitrag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

CC = gcc

FLAGS = -Wall -Wextra -Werror
	
FILES =  ft_strlen.c ft_memset.c ft_isprint.c ft_isdigit.c \
		 ft_isascii.c ft_isalpha.c ft_isalnum.c ft_bzero.c \
		 ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_memmove.c \
		 ft_strchr.c ft_toupper.c ft_tolower.c ft_memcmp.c  \
		 ft_strrchr.c ft_strnstr.c ft_atoi.c ft_calloc.c \
		 ft_strdup.c ft_substr.c ft_strncmp.c ft_strjoin.c \
		 ft_strtrim.c ft_memchr.c ft_split.c ft_itoa.c ft_strmapi.c \
		 ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		 ft_putnbr_fd.c 


OFILES = $(FILES:.c=.o)

all : $(NAME)
	
$(NAME): $(OFILES)
	@ar rc $(NAME) $(OFILES)

%.o:%.c $(HEADER) Makefile
	@$(CC) $(FLAGS) -c $<	

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) $(OFILES) a.out

re : fclean all

.PHONY: clean fclean all re
