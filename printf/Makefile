# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 10:39:11 by jolivare          #+#    #+#              #
#    Updated: 2023/11/10 15:33:44 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = ft_printf.c \
		  ft_putchar_pf.c \
		  ft_puthexlow_pf.c \
		  ft_puthexup_pf.c \
		  ft_putnbr_pf.c \
		  ft_putunsigned_pf.c \
		  ft_putptr_pf.c \
		  ft_putstr_pf.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(NAME) $(OBJECTS)

clean:
	$(REMOVE) $(OBJECTS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re