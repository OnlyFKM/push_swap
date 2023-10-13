/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:04:46 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/11 17:47:36 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_stacksize(*stack) >= 1)
	{
		tmp = *stack;
		*stack = tmp->next;
		tmp->next = *stack;
		*stack = tmp;
		ft_printf("pa\n");
	}
}

void	ft_push_a(t_stack **stack_a)
{
	ft_push(stack_a);
	ft_printf("pa\n");
}

void	ft_push_b(t_stack **stack_b)
{
	ft_push(stack_b);
	ft_printf("pb\n");
}
