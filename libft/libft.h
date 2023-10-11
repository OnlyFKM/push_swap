/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:33:58 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/11 12:38:18 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 10

typedef struct s_list
{
	int				n;
	int				data;
	int				index;
	int				fin_ind;
	int				pos;
	int				values;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_list	*next;
}					t_list;

// libft
int					ft_isalpha(int c);
int					ft_isdigit(int x);
int					ft_isalnum(int x);
int					ft_isascii(int x);
int					ft_isprint(int x);
size_t				ft_strlen(const char *a);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
size_t				ft_strlcpy(char *rest_dst, const char *rest_src,
						size_t dstsize);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

// libft_bonus
t_list				*ft_lstnew(int num);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(int));
void				ft_lstclear(t_list **lst, void (*del)(int));

// get_next_line
char				*get_next_line(int fd);

// get_next_line_utils
void				*ft_calloc_gnl(size_t count, size_t size);
int					ft_strchr_gnl(const char *s, int c);
size_t				ft_strlen_gnl(const char *str);
char				*ft_strjoin_gnl(char *s1, char *s2);

// ft_printf
int					ft_putchar(char c);
int					ft_printchar(char c);
int					ft_printdec(int nb);
int					ft_printhexa(unsigned long long nb, char ch);
int					ft_printptr(unsigned long long ptr);
int					ft_printstr(char *str);
int					ft_printunsigned(unsigned int nb);
int					ft_putnbr(int n);
int					ft_printf(char const *type, ...);

#endif