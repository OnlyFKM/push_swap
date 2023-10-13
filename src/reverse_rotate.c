/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:37:37 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/13 13:02:42 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		first = *stack;
		while (first->next != last)
			first = first->next;
		first->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
