# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 11:09:23 by frcastil          #+#    #+#              #
#    Updated: 2023/10/11 12:24:22 by frcastil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILES = ft_atoi.c\
    ft_bzero.c\
    ft_calloc.c\
    ft_isalnum.c\
    ft_isalpha.c\
    ft_isascii.c\
    ft_isdigit.c\
    ft_isprint.c\
    ft_itoa.c\
    ft_memchr.c\
    ft_memcmp.c\
    ft_memcpy.c\
    ft_memmove.c\
    ft_memset.c\
    ft_printchar.c\
    ft_printdec.c\
    ft_printf.c\
    ft_printhexa.c\
    ft_printptr.c\
    ft_printstr.c\
    ft_printunsigned.c\
    ft_putchar_fd.c\
    ft_putchar.c\
    ft_putendl_fd.c\
    ft_putnbr_fd.c\
    ft_putnbr.c\
    ft_putstr_fd.c\
    ft_split.c\
    ft_strchr.c\
    ft_strdup.c\
    ft_striteri.c\
    ft_strjoin.c\
    ft_strlcat.c\
    ft_strlcpy.c\
    ft_strlen.c\
    ft_strmapi.c\
    ft_strncmp.c\
    ft_strnstr.c\
    ft_strtrim.c\
    ft_substr.c\
    ft_tolower.c\
    ft_toupper.c\
    get_next_line.c\
    get_next_line_utils.c\
    ft_lstnew_bonus.c\
    ft_lstadd_front_bonus.c\
    ft_lstsize_bonus.c\
    ft_lstlast_bonus.c\
    ft_lstadd_back_bonus.c\
    ft_lstdelone_bonus.c\
    ft_lstclear_bonus.c\

OBJECTS = $(notdir $(FILES:.c=.o))

BONUS_OBJ = $(BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(OBJECTS): $(FILES)
	@gcc $(FLAGS) -c $(FILES)

clean:
	@rm -f $(OBJECTS) $(BONUS_OBJ)

fclean:
	@rm -f $(NAME) $(OBJECTS) $(BONUS_OBJ)

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJ)
	@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJ)

.PHONY: all bonus clean fclean re