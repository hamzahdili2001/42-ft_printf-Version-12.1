/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:23:29 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/03 11:24:37 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int		total;
	int		n;
	va_list	args;

	total = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (!*fmt)
				break ;
			n = dispatch(*fmt, &args);
			if (n < 0)
				return (va_end(args), -1);
			total += n;
		}
		else
			total += ft_putchar(*fmt);
		fmt++;
	}
	va_end(args);
	return (total);
}
