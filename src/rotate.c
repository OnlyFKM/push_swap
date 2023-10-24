/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:38:34 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/23 15:12:30 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_stacksize(*stack) > 1)
	{
		first = *stack;
		last = *stack;
		*stack = first->next;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

void	ft_rotate_a(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_r(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
