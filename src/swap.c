/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:27:58 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/25 16:42:35 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (ft_stacksize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void	ft_swap_a(t_stack **stack_a, int flag)
{
	ft_swap(stack_a);
	if (flag == 1)
		ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack_b, int flag)
{
	ft_swap(stack_b);
	if (flag == 1)
		ft_printf("sb\n");
}

void	ft_swap_s(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (flag == 1)
		ft_printf("ss\n");
}
