/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:59:25 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/09 15:59:28 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexadec(const char *f, unsigned int hex)
{
	static int	tot_hexs;
	char		new_hex;
	char		*hex_arr;

	tot_hexs = 0;
	hex_arr = "0123456789abcdef";
	if (hex >= 16)
	{
		if (ft_puthexadec(f, hex / 16) == -1)
			return (-1);
	}
	if (*f == 'X')
	{
		new_hex = hex_arr[hex % 16];
		if (new_hex >= 'a' && new_hex <= 'z')
			new_hex -= 32;
	}
	else
		new_hex = hex_arr[hex % 16];
	if (write(1, &new_hex, 1) == -1)
		return (-1);
	tot_hexs++;
	return (tot_hexs);
}
