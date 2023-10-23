/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:25:20 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/20 16:36:58 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_calculate_target(t_stack *copy_a, t_stack *copy_b, int *rest)
{
	while (copy_a)
	{
		if (copy_b->index < copy_a->index)
		{
			if (copy_a->index - copy_b->index <= *rest)
			{
				*rest = copy_a->index - copy_b->index;
				copy_b->target = copy_a->pos;
			}
		}
		copy_a = copy_a->next;
	}
}

t_stack	*ft_max_index(t_stack **stack_a)
{
	t_stack	*copy;
	t_stack	*max_index;

	copy = *stack_a;
	max_index = *stack_a;
	while (copy)
	{
		if (copy->values > max_index->values)
			max_index = copy;
		copy = copy->next;
	}
	return (max_index);
}

t_stack	*ft_min_index(t_stack **stack_a)
{
	t_stack	*copy;
	t_stack	*min_index;

	copy = *stack_a;
	min_index = *stack_a;
	while (copy)
	{
		if (copy->values < min_index->values)
			min_index = copy;
		copy = copy->next;
	}
	return (min_index);
}

void	ft_put_index(t_stack **stack)
{
	t_stack	*current;
	t_stack	*cmp;

	current = *stack;
	while (current)
	{
		cmp = *stack;
		current->index = 1;
		while (cmp)
		{
			if (cmp->values < current->values)
				current->index++;
			cmp = cmp->next;
		}
		current = current->next;
	}
}

void	ft_put_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 1;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}
