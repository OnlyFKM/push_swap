# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/02 11:56:26 by frcastil          #+#    #+#              #
#    Updated: 2023/10/23 13:04:01 by frcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

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

CC = gcc

OBJS = ${SRCS:.c=.o}

all: $(LIBFT)/libft.a $(NAME)
	
$(NAME): $(OBJS)
	@$(CC) -g $(CFLAGS) $(LIBFT)/libft.a $(OBJS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

test3: $(NAME)
    $(eval ARG = $(shell jot -r 3 $(shell echo "-(2^31)" | bc) $(shell echo "(2^31)-1" | bc) | tr ' ' '\n' | sort -n | tr '\n' ' '))
    ./push_swap $(ARG) | ./checker_macos $(ARG)
    @echo -n "Instructions: "
    @./push_swap $(ARG) | wc -l

test5: $(NAME)
    $(eval ARG = $(shell jot -r 5 $(shell echo "-(2^31)" | bc) $(shell echo "(2^31)-1" | bc) | tr ' ' '\n' | sort -n | tr '\n' ' '))
    ./push_swap $(ARG) | ./checker_macos $(ARG)
    @echo -n "Instructions: "
    @./push_swap $(ARG) | wc -l

test100: $(NAME)
    $(eval ARG = $(shell jot -r 100 $(shell echo "-(2^31)" | bc) $(shell echo "(2^31)-1" | bc) | tr ' ' '\n' | sort -n | tr '\n' ' '))
    ./push_swap $(ARG) | ./checker_macos $(ARG)
    @echo -n "Instructions: "
    @./push_swap $(ARG) | wc -l

test500: $(NAME)
    $(eval ARG = $(shell jot -r 500 $(shell echo "-(2^31)" | bc) $(shell echo "(2^31)-1" | bc) | tr ' ' '\n' | sort -n | tr '\n' ' '))
    ./push_swap $(ARG) | ./checker_macos $(ARG)
    @echo -n "Instructions: "
    @./push_swap $(ARG) | wc -l

clean:
	@rm -rf $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
