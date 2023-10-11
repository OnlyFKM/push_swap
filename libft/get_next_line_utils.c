/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:47:21 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/03 12:10:13 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	mem = malloc(count * size);
	if (!mem)
		return (0);
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)mem);
}

int	ft_strchr_gnl(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	if (!str)
		return (0);
	while (*str != (char) c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
	}
	if (!s2)
		return (NULL);
	dst = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!dst)
		return (free(s1), s1 = NULL, NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		dst[i] = s1[i];
	while (s2[j] != '\0')
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (free(s1), s1 = NULL, dst);
}
