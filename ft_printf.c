/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:38 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/11 18:56:33 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handlespecs(va_list args, const char *f)
{
	if (*f == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*f == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (*f == 'p' | *f == 'x' | *f == 'X')
	{
		if (*f == 'p')
			return (ft_putpointer(va_arg(args, unsigned long int)));
		else
			return (ft_puthexadec(f, va_arg(args, unsigned int)));
	}
	else if (*f == 'd' | *f == 'i' | *f == 'u')
	{
		if (*f == 'u')
			return (ft_putunbr(va_arg(args, unsigned int)));
		else
			return (ft_putnbr(va_arg(args, int)));
	}
	else if (*f == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_implement(va_list args, const char *f)
{
	int	tot_char;
	int	bw;
	int	ind;

	ind = -1;
	tot_char = 0;
	while (f[++ind])
	{
		if (f[ind] == '%')
		{
			bw = ft_handlespecs(args, &f[++ind]);
			if (bw == -1)
				return (-1);
			tot_char += bw;
		}
		else
		{
			if (write(1, &f[ind], 1) == -1)
				return (-1);
			tot_char++;
		}
	}
	return (tot_char);
}

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		tot_char;

	if (!f)
		return (-1);
	va_start(args, f);
	tot_char = ft_implement(args, f);
	va_end(args);
	return (tot_char);
}
