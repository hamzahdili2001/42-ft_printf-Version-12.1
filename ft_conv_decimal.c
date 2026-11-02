/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_decimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 14:04:19 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 16:06:16 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_d(va_list *ap, t_flag *flags)
{
	int		n;
	int		count;
	long	mag;

	(void)flags;
	n = va_arg(*ap, int);
	mag = 0;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		mag = -(long)n;
	}
	else
		mag = n;
	count += ft_putnbr_base((unsigned long)mag, "0123456789", 10);
	return (count);
}
