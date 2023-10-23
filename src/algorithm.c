/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:26:23 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/23 11:57:13 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_a_if(t_stack **stack_a, int *cost_a)
{
	if (*cost_a > 0)
	{
		while (*cost_a > 0)
		{
			ft_rotate_a(stack_a);
			(*cost_a)--;
		}
	}
	if (*cost_a < 0)
	{
		while (*cost_a < 0)
		{
			ft_reverse_rotate_a(stack_a);
			(*cost_a)++;
		}		
	}
}

void	ft_rotate_b_if(t_stack **stack_b, int *cost_b)
{
	if (*cost_b > 0)
	{
		while (*cost_b > 0)
		{
			ft_rotate_b(stack_b);
			(*cost_b)--;
		}
	}
	if (*cost_b < 0)
	{
		while (*cost_b < 0)
		{
			ft_reverse_rotate_b(stack_b);
			(*cost_b)++;
		}
	}
}

void	ft_best_algorithm(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 2)
		ft_swap_a(stack_a);
	if (i == 3)
		ft_second_step(stack_a);
	if (i > 3)
	{
		ft_put_index(stack_a);
		ft_first_step(stack_a, stack_b);
		ft_second_step(stack_a);
		while (ft_stacksize(*stack_b) > 0)
		{
			ft_put_position(stack_a);
			ft_put_position(stack_b);
			ft_third_step(stack_a, stack_b);
			ft_calculate_cost(stack_a, stack_b);
			ft_fourth_step(stack_a, stack_b);
/* 			ft_last_step(stack_a); */
		}
		if (!ft_sorted_list(stack_a))
			ft_last_step(stack_a);
	}
}
