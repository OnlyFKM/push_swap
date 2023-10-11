/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:17:10 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/09 19:13:49 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int num)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->n = num;
	new_list->fin_ind = 0;
	new_list->pos = 0;
	new_list->target_pos = 0;
	new_list->cost_a = 0;
	new_list->cost_b = 0;
	new_list->next = NULL;
	return (new_list);
}
