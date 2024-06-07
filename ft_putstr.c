/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:58:54 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/09 15:59:02 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *c)
{
	int	tot_char;

	if (!c)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	tot_char = ft_strlen(c);
	if (write(1, c, tot_char) == -1)
		return (-1);
	return (tot_char);
}
