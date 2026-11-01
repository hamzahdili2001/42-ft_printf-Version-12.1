/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:02:13 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 17:13:34 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_p(va_list *ap)
{
	void			*p;
	int				count;
	unsigned long	addr;

	p = va_arg(*ap, void *);
	if (!p)
		return (ft_putstr("(nill)"));
	addr = (unsigned long)p;
	count = ft_putstr("0x");
	count += ft_putnbr_base(addr, "0123456789abcdef", 16);
	return (count);
}
