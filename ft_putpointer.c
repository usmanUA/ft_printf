/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:37 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/09 15:59:42 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checknull(char *null)
{
	if (write(1, null, 6) == -1)
		return (-1);
	return (6);
}

int	ft_putpointer(unsigned long int point)
{
	static int	tot_point;
	char		new_point;
	char		*point_arr;

	if (!point && point != 0)
		return (ft_checknull("(null)"));
	tot_point = 0;
	point_arr = "0123456789abcdef";
	if (point >= 16)
	{
		if (ft_putpointer(point / 16) == -1)
			return (-1);
	}
	if (!tot_point)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		tot_point += 2;
	}
	new_point = point_arr[point % 16];
	if (write(1, &new_point, 1) == -1)
		return (-1);
	tot_point++;
	return (tot_point);
}
