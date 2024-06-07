/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:54 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/11 21:06:51 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_usize(unsigned long int nbr)
{
	long int	size;

	if (nbr == 0)
		return (1);
	size = 0;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

int	ft_putunbr(unsigned int nbr)
{
	unsigned int	tot_chars;

	tot_chars = ft_usize(nbr);
	if (nbr > 9)
	{
		if (ft_putunbr(nbr / 10) == -1)
			return (-1);
	}
	if (ft_putchar(nbr % 10 + '0') == -1)
		return (-1);
	return (tot_chars);
}
