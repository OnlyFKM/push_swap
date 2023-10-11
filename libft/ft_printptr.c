/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcastil <frcastil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 14:59:58 by frcastil          #+#    #+#             */
/*   Updated: 2023/10/02 14:31:04 by frcastil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printptr(unsigned long long ptr)
{
	int	c;

	c = 0;
	c += ft_printstr("0x");
	c += ft_printhexa(ptr, 'x');
	return (c);
}
