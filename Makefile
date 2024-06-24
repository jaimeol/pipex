# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jolivare < jolivare@student.42mad.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/01 10:25:16 by jolivare          #+#    #+#              #
#    Updated: 2024/06/17 10:26:45 by jolivare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS_NAME = .bonus

SOURCES = src/pipex.c src/make_childs.c src/path.c src/errors.c \

OBJECTS = $(SOURCES:.c=.o)

BONUS_SRC = bonus/pipex_bonus.c bonus/make_childs_bonus.c bonus/make_here_doc.c\
			bonus/get_next_line_bonus.c bonus/files_bonus.c bonus/errors_bonus.c \
			bonus/path_bonus.c bonus/do_forks.c \
				

BONUS_OBJS = $(BONUS_SRC:.c=.o)

LIBFT = libft/libft.a
PRINTF = printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -f
CC = cc


all: $(NAME)

$(LIBFT):
	$(MAKE) -sC libft/
	$(MAKE) -sC printf/	

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME) -Llibft/ -lft -Lprintf/ -lftprintf

bonus: .bonus
.bonus: $(BONUS_OBJS) $(LIBFT)
	$(CC) $(BONUS_OBJS) $(CFLAGS) -o $(NAME) -Llibft/ -lft -Lprintf/ -lftprintf
	@touch .bonus

clean:
	make clean -sC libft
	make clean -sC printf
	$(REMOVE) $(BONUS_OBJS)
	$(REMOVE) $(OBJECTS)
	@rm -rf .bonus

fclean: clean
	make fclean -sC libft
	make fclean -sC printf
	$(REMOVE) $(NAME)

re: fclean all


.PHONY: all clean fclean re