/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:00:51 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 10:00:51 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_s(va_list *ap)
{
	int		count;
	char	*str;

	count = 0;
	str = va_arg(*ap, char *);
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
