/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:02:13 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/02 11:18:09 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_p(va_list *ap)
{
	void			*p;
	unsigned long	addr;

	p = va_arg(*ap, void *);
	if (!p)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)p;
	return (ft_putstr("0x") + ft_putnbr_base(addr, "0123456789abcdef", 16));
}
