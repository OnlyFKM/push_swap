/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:26:23 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/13 14:03:16 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_best_algorithm(int i, t_stack **stack_a)
{
	if (i == 2)
		ft_swap_a(stack_a);
	if (i == 3)
		ft_order_3(stack_a);
	if (i > 3)
}
