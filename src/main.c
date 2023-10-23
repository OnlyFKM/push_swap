/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:07:45 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/23 12:54:23 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_init_program(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_a == NULL)
	{
		ft_printf("Error\nFailed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	**stack_a = NULL;
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_b == NULL)
	{
		free(*stack_a);
		ft_printf("Error\nFailed to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	**stack_b = NULL;
}

char	**ft_check_args(int argc, char *argv[])
{
	char	**str;

	if (argc < 2)
	{
		ft_printf("Error\nThere is not a valid argue\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (str == NULL)
		{
			ft_printf("Error\nFailed to split arguments\n");
			exit(EXIT_FAILURE);
		}
		ft_check_conditions(str);
		return (str);
	}
	else
	{
		ft_check_conditions(argv + 1);
		return (argv + 1);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**str;
	int		i;
	//t_stack	*current;

	ft_init_program(&stack_a, &stack_b);
	str = ft_check_args(argc, argv);
	i = 0;
	while (str[i] != NULL)
	{
		if (!ft_transfer_stack(str[i], stack_a))
		{
			ft_printf("Error\nFailed to add elements to stack\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!ft_sorted_list(stack_a))
	{
		ft_best_algorithm(stack_a, stack_b, i);
	}
	// IMPRIMIR
	/* current = *stack_a;
	while (current)
	{
		ft_printf("%i\n", current->values);
		current = current->next;
	} */
	return (0);
}
