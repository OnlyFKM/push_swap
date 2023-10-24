/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:13:34 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 17:33:32 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_duplicates(char **argv)
{
	char	**current;
	char	**compare;
	int		i;

	current = argv + 1;
	while (*current != NULL)
	{
		compare = argv;
		while (compare < current)
		{
			i = 0;
			while ((*current)[i] != '\0' && (*compare)[i] != '\0'
				&& (*current)[i] == (*compare)[i])
				i++;
			if ((*current)[i] == (*compare)[i])
				return (FALSE);
			compare++;
		}
		current++;
	}
	return (TRUE);
}

int	ft_check_correct_digits(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		if (argv[i][j] == '-')
		{
			j++;
			if (argv[i][j] == '-' || argv[i][j] == '+')
				return (FALSE);
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (FALSE);
			j++;
		}
		if (ft_atoi(argv[i]) < MIN_INT || ft_atoi(argv[i]) > MAX_INT)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_check_conditions(char *argv[])
{
	if (ft_check_duplicates(argv) == FALSE)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (ft_check_correct_digits((argv)) == FALSE)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
