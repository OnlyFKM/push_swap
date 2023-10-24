/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:41:50 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 16:46:22 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		fd;

	fd = 0;
	line = get_next_line(fd);
	while (get_next_line(fd) > 0)
	{
		ft_messages(stack_a, stack_b, line);
		free(line);
	}
}

void	ft_final_check(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_sorted_list(stack_a) && stack_b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	ft_messages(t_stack **stack_a, t_stack **stack_b, char *order)
{
	if (ft_strncmp(order, "sa", 2) == 0)
		ft_swap_a(stack_a);
	if (ft_strncmp(order, "sb", 2) == 0)
		ft_swap_b(stack_b);
	if (ft_strncmp(order, "ss", 2) == 0)
		ft_swap_s(stack_a, stack_b);
	if (ft_strncmp(order, "pa", 2) == 0)
		ft_push_a(stack_a, stack_b);
	if (ft_strncmp(order, "pb", 2) == 0)
		ft_push_b(stack_a, stack_b);
	if (ft_strncmp(order, "ra", 2) == 0)
		ft_rotate(stack_a);
	if (ft_strncmp(order, "rb", 2) == 0)
		ft_rotate_b(stack_b);
	if (ft_strncmp(order, "rr", 2) == 0)
		ft_rotate_r(stack_a, stack_b);
	if (ft_strncmp(order, "rra", 3) == 0)
		ft_reverse_rotate_a(stack_a);
	if (ft_strncmp(order, "rrb", 3) == 0)
		ft_reverse_rotate_b(stack_b);
	if (ft_strncmp(order, "rrb", 3) == 0)
		ft_reverse_rotate_r(stack_a, stack_b);
	else
		ft_printf("Error\n");
}

int	main2(int argc, char *argv[])
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
