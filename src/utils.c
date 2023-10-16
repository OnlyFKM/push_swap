/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:58:50 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/16 12:34:24 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	*ft_stacklast(t_stack *stack)
{
	t_stack	*current;

	if (!stack)
		return (0);
	current = stack;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (*stack == NULL)
		*stack = new;
	else
	{
		current = ft_stacklast(*stack);
		current->next = new;
	}
}

int	ft_stacksize(t_stack *stack)
{
	int		i;
	t_stack	*current;

	if (!stack)
		return (0);
	i = 1;
	current = stack;
	while (current->next)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	ft_free_str(char **str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_sorted_list(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp == NULL)
		return (TRUE);
	while (tmp && tmp->next)
	{
		if (tmp->values > tmp->next->values)
			return (FALSE);
		tmp = tmp->next;
	}
	ft_printf("ordenada\n");
	return (TRUE);
}
