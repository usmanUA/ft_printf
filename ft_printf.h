/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:57:58 by uahmed            #+#    #+#             */
/*   Updated: 2023/11/11 21:07:56 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int					ft_printf(const char *f, ...);
int					ft_handlespecs(va_list args, const char *f);
int					ft_putstr(char *c);
int					ft_putchar(char c);
int					ft_puthexadec(const char *f, unsigned int hex);
int					ft_putpointer(unsigned long int point);
int					ft_putnbr(int nbr);
int					ft_putunbr(unsigned int nbr);
#endif
