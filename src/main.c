/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:07:45 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 17:31:39 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* void	ft_leaks(void)
{
	system("leaks -q push_swap");
} */

void	ft_free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*aux;

	node = *stack;
	while (node)
	{
		aux = node->next;
		free(node);
		node = aux;
	}
	free(stack);
}

void	ft_init_program(t_stack ***stack_a, t_stack ***stack_b)
{
	*stack_a = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_a == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	**stack_a = NULL;
	*stack_b = (t_stack **)malloc(sizeof(t_stack *));
	if (*stack_b == NULL)
	{
		free(*stack_a);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	**stack_b = NULL;
}

char	**ft_check_args(int argc, char *argv[])
{
	char	**str;

	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (str == NULL)
		{
			ft_printf("Error\n");
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

	//atexit(ft_leaks);
	ft_init_program(&stack_a, &stack_b);
	str = ft_check_args(argc, argv);
	i = 0;
	while (str[i] != NULL)
	{
		if (!ft_transfer_stack(str[i], stack_a))
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (!ft_sorted_list(stack_a))
		ft_best_algorithm(stack_a, stack_b, i);
	if (argc == 2)
		ft_free_str(str);
	return (ft_free_stack(stack_a), ft_free_stack(stack_b), 0);
}
