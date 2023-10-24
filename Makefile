# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 11:56:26 by frcastil          #+#    #+#              #
#    Updated: 2023/10/24 18:05:27 by frcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CFLAGS = -Wextra -Wall -Werror
LIBFT = ./libft

SRCS = src/main.c\
	src/checkers.c\
	src/utils.c\
	src/position.c\
	src/stack.c\
	src/push.c\
	src/swap.c\
	src/rotate.c\
	src/reverse_rotate.c\
	src/algorithm.c\
	src/steps.c\
	src/cost.c\

SRCS_BONUS = src/checkers.c\
	src/utils.c\
	src/position.c\
	src/stack.c\
	src/push.c\
	src/swap.c\
	src/rotate.c\
	src/reverse_rotate.c\
	src/algorithm.c\
	src/steps.c\
	src/cost.c\
	src_bonus/checker.c\
	src_bonus/utils_bonus.c\

CC = gcc

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: $(LIBFT)/libft.a $(NAME)

bonus: all $(NAME_BONUS)
	
$(NAME): $(OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS_BONUS) -o $(NAME_BONUS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re bonus
