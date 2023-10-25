/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:04:46 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 18:19:40 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_push(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*tmp;

	if (ft_stacksize(*stack_two) >= 1)
	{
		tmp = *stack_two;
		*stack_two = (*stack_two)->next;
		tmp->next = *stack_one;
		*stack_one = tmp;
	}
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ft_push(stack_a, stack_b);
	if (flag == 1)
		ft_printf("pa\n");
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b, int flag)
{
	ft_push(stack_b, stack_a);
	if (flag == 1)
		ft_printf("pb\n");
}
