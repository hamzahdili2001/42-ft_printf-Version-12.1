/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:23:29 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 10:09:39 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	dispatch(char spec, va_list *ap)
{
	static const t_conv	table[] = {{'c', conv_c}, {'s', conv_s}, {'p', conv_p},
	{'d', conv_d}, {'i', conv_d}, {'u', conv_u}, {'x', conv_x}, {'X',
		conv_upx}, {'%', conv_pct}, {0, NULL}};

	while (table->spec)
	{
		if (table->spec == spec)
			return (table->f(ap));
	}
	return (-1);
}

int	ft_printf(const char *ap, ...)
{
	return (0);
}

/*
int	main(void)
{
	printf("%d\n", ft_printf('c'));
	return (0);
}
*/
