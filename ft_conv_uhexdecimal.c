/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_uhexdecimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:04:07 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 16:32:21 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_upx(va_list *ap)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789ABCDEF", 16));
}
