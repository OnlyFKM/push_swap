/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:26:23 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/16 12:35:34 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/* static void	ft_put_position(t_stack **stack)
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
} */

static void	ft_first_step(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	i;
	int	push;

	size = ft_stacksize(*stack_a);
	i = 0;
	push = 0;
	while (size / 2 + 1 > 3 && i < size)
	{
		if ((*stack_a)->index < size / 2)
		{
			ft_push_b(stack_a, stack_b);
			push++;
		}
		else
			ft_rotate_a(stack_a);
		i++;
	}
	while (size - push > 3)
	{
		ft_push_b(stack_a, stack_b);
		push++;
	}
}

void	ft_order_3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;		

	first = *stack_a;
	middle = first->next;
	last = middle->next;
	/* ft_printf("first: %d, middle: %d, last: %d\n", first->values, middle->values, last->values); */
	if (first->values > middle->values && first->values > last->values)
	{
		ft_rotate_a(stack_a);
		ft_order_3(stack_a);
	}
	if (first->values < middle->values && middle->values > last->values)
	{
		ft_reverse_rotate_a(stack_a);
		ft_order_3(stack_a);
	}
	if (first->values > middle->values && first->values < last->values)
		ft_swap_a(stack_a);
}

void	ft_best_algorithm(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 2)
		ft_swap_a(stack_a);
	if (i == 3)
		ft_order_3(stack_a);
	if (i > 3)
	{
		ft_first_step(stack_a, stack_b);
		ft_order_3(stack_a);
		/* while (ft_stacksize(*stack_b) > 0)
		{
			ft_put_position(stack_a);
			ft_put_position(stack_b);
		} */
	}
}
