/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:54 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/11 20:54:38 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(int nbr)
{
	int	size;

	if (nbr == 0)
		return (1);
	size = 0;
	if (nbr < 0)
		size++;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

int	ft_putnbr(int nbr)
{
	int	tot_chars;

	tot_chars = ft_size(nbr);
	if (nbr == -2147483648)
	{
		return (ft_putstr("-2147483648"));
	}
	else
	{
		if (nbr < 0)
		{
			nbr *= -1;
			if (ft_putchar('-') == -1)
				return (-1);
		}
		if (nbr > 9)
		{
			if (ft_putnbr(nbr / 10) == -1)
				return (-1);
		}
		if (ft_putchar(nbr % 10 + '0') == -1)
			return (-1);
	}
	return (tot_chars);
}
