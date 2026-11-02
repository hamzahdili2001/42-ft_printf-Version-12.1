/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:01:18 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 14:08:43 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	conv_c(va_list *ap, t_flag *flags)
{
	int	c;

	(void)flags;
	c = va_arg(*ap, int);
	ft_putchar(c);
	return (1);
}
