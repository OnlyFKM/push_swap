/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:00:36 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/24 14:13:51 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_transfer_stack(char *value_str, t_stack **stack)
{
	int		value;
	t_stack	*new_node;

	value = ft_atoi(value_str);
	//free(value_str);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	new_node->values = value;
	new_node->pos = 0;
	new_node->target = 0;
	new_node->index = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	ft_stackadd_back(stack, new_node);
	return (1);
}
