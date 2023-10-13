/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:37:33 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/13 14:11:03 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_order_3(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;		

	first = *stack_a;
	middle = first->next;
	last = middle->next;
	ft_printf("first: %d, middle: %d, last: %d\n", first->values, middle->values, last->values);
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
