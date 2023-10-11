/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:27:16 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/02 14:30:33 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dcount(long int nb)
{
	int	i;

	i = 0;
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

int	ft_printdec(int nb)
{
	long int	c;

	c = 0;
	ft_putnbr(nb);
	if (nb >= 0)
		return (c + ft_dcount(nb));
	c = (long int)nb * (-1);
	return (ft_dcount(c) + 1);
}
