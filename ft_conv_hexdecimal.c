/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexdecimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:03:33 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 16:25:35 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_x(va_list *ap)
{
	unsigned int	n;

	n = va_arg(*ap, unsigned int);
	return (ft_putnbr_base(n, "0123456789abcdef", 16));
}
