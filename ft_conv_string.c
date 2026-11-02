/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:00:51 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/02 10:44:38 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conv_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	if (!str)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}
