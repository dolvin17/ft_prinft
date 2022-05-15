# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 20:28:36 by ghuertas          #+#    #+#              #
#    Updated: 2022/05/14 22:52:05 by dolvin17         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc -c
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
SRCS =	ft_print_char.c \
		ft_print_str.c \
		ft_printf.c \
		ft_printn_base.c \
		ft_printnu_base.c \
		ft_strlenv2.c \

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
.PHONY: all clean fclean re
