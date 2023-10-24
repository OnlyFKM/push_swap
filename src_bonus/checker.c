/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:41:50 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 18:05:02 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_messages(stack_a, stack_b, line) == EXIT_FAILURE)
			break ;
		free(line);
		line = get_next_line(0);
	}
}

int	ft_messages(t_stack **stack_a, t_stack **stack_b, char *order)
{
	if (ft_strncmp(order, "sa", 2) == 0)
		return (ft_swap_a(stack_a), EXIT_SUCCESS);
	if (ft_strncmp(order, "sb", 2) == 0)
		return (ft_swap_b(stack_b), EXIT_SUCCESS);
	if (ft_strncmp(order, "ss", 2) == 0)
		return (ft_swap_s(stack_a, stack_b), EXIT_SUCCESS);
	if (ft_strncmp(order, "pa", 2) == 0)
		return (ft_push_a(stack_a, stack_b), EXIT_SUCCESS);
	if (ft_strncmp(order, "pb", 2) == 0)
		return (ft_push_b(stack_a, stack_b), EXIT_SUCCESS);
	if (ft_strncmp(order, "ra", 2) == 0)
		return (ft_rotate_a(stack_a), EXIT_SUCCESS);
	if (ft_strncmp(order, "rb", 2) == 0)
		return (ft_rotate_b(stack_a), EXIT_SUCCESS);
	if (ft_strncmp(order, "rr", 2) == 0)
		return (ft_rotate_r(stack_a, stack_b), EXIT_SUCCESS);
	if (ft_strncmp(order, "rra", 3) == 0)
		return (ft_reverse_rotate_a(stack_a), EXIT_SUCCESS);
	if (ft_strncmp(order, "rrb", 3) == 0)
		return (ft_reverse_rotate_b(stack_a), EXIT_SUCCESS);
	if (ft_strncmp(order, "rrb", 3) == 0)
		return (ft_reverse_rotate_r(stack_a, stack_b), EXIT_SUCCESS);
	return (ft_printf("Error\n"), EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	**str;
	int		i;

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
	ft_checker(stack_a, stack_b);
	ft_final_check(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
