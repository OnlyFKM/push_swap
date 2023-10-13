# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 11:56:26 by frcastil          #+#    #+#              #
#    Updated: 2023/10/12 12:58:40 by frcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wextra -Wall -Werror
LIBFT = ./libft

SRCS = src/main.c\
	src/checkers.c\
	src/utils.c\
	src/utils_2.c\
	src/stack.c\
	src/push.c\
	src/swap.c\
	src/rotate.c\
	src/reverse_rotate.c\
	src/algorithm.c\

CC = gcc

OBJS = ${SRCS:.c=.o}

all: $(LIBFT)/libft.a $(NAME)

	
$(NAME): $(OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
