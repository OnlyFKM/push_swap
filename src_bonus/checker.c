/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:41:50 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/25 12:12:25 by frcastil         ###   ########.fr       */
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
			exit(EXIT_FAILURE);
		free(line);
		line = get_next_line(0);
	}
}

int	ft_messages(t_stack **stack_a, t_stack **stack_b, char *order)
{
	if (ft_strncmp(order, "sa\n", 3) == 0)
		return (ft_swap_a(stack_a, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "sb\n", 3) == 0)
		return (ft_swap_b(stack_b, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "ss\n", 3) == 0)
		return (ft_swap_s(stack_a, stack_b, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "pa\n", 3) == 0)
		return (ft_push_a(stack_a, stack_b, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "pb\n", 3) == 0)
		return (ft_push_b(stack_a, stack_b, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "ra\n", 3) == 0)
		return (ft_rotate_a(stack_a, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "rb\n", 3) == 0)
		return (ft_rotate_b(stack_a, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "rr\n", 3) == 0)
		return (ft_rotate_r(stack_a, stack_b, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "rra\n", 4) == 0)
		return (ft_reverse_rotate_a(stack_a, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "rrb\n", 4) == 0)
		return (ft_reverse_rotate_b(stack_b, 0), EXIT_SUCCESS);
	if (ft_strncmp(order, "rrr\n", 4) == 0)
		return (ft_reverse_rotate_r(stack_a, stack_b, 0), EXIT_SUCCESS);
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
	ft_free_str(str);
	ft_checker(stack_a, stack_b);
	ft_final_check(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
