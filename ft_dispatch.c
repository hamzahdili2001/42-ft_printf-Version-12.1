/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 10:34:33 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/02 17:15:52 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	dispatch(char spec, va_list *ap, t_flag *flags)
{
	static const t_conv	table[] = {{'c', conv_c}, {'s', conv_s}, {'p', conv_p},
			{'d', conv_d}, {'i', conv_d}, {'u', conv_u}, {'x', conv_x}, {'X',
			conv_upx}, {'%', conv_pct}, {0, NULL}};
	const t_conv		*p;

	(void)flags;
	p = table;
	while (p->spec)
	{
		if (p->spec == spec)
			return (p->f(ap, flags));
		p++;
	}
	return (-1);
}
