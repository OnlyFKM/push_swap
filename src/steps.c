/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:58:42 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 18:27:34 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_last_step(t_stack **stack_a)
{
	int	first;
	int	size;

	size = ft_stacksize(*stack_a);
	first = ft_min_index(stack_a)->index;
	if (first > size / 2)
	{
		while ((*stack_a)->index < size)
			ft_reverse_rotate_a(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != 1)
			ft_reverse_rotate_a(stack_a, 1);
	}
}

void	ft_fourth_step(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	cheapest = ft_calculate_cheapest(stack_b);
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		ft_reverse_rotate_r(stack_a, stack_b, 1);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		ft_rotate_r(stack_a, stack_b, 1);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	ft_rotate_a_if(stack_a, &(cheapest->cost_a));
	ft_rotate_b_if(stack_b, &(cheapest->cost_b));
	ft_push_a(stack_a, stack_b, 1);
}

void	ft_third_step(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_target;
	t_stack	*copy_a;
	t_stack	*copy_b;
	int		rest;

	max_target = ft_max_index(stack_a);
	copy_a = *stack_a;
	copy_b = *stack_b;
	while (copy_b)
	{
		if (copy_b->index > max_target->index)
			copy_b->target = ft_min_index(stack_a)->pos;
		rest = max_target->index - copy_b->index;
		ft_calculate_target(copy_a, copy_b, &rest);
		copy_a = *stack_a;
		copy_b = copy_b->next;
	}
}

void	ft_second_step(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;

	first = *stack_a;
	middle = first->next;
	last = middle->next;
	if (first->values > middle->values && first->values > last->values)
	{
		ft_rotate_a(stack_a, 1);
		ft_second_step(stack_a);
	}
	if (first->values < middle->values && middle->values > last->values)
	{
		ft_reverse_rotate_a(stack_a, 1);
		ft_second_step(stack_a);
	}
	if (first->values > middle->values && first->values < last->values)
		ft_swap_a(stack_a, 1);
}

void	ft_first_step(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	push;

	size = ft_stacksize(*stack_a);
	i = 0;
	push = 0;
	while (size > 6 && i < size && push < size / 2)
	{
		if ((*stack_a)->index < size / 2)
		{
			ft_push_b(stack_a, stack_b, 1);
			push++;
		}
		else
			ft_rotate_a(stack_a, 1);
		i++;
	}
	while (size - push > 3)
	{
		ft_push_b(stack_a, stack_b, 1);
		push++;
	}
}
