/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_extras.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:44:14 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/02 18:50:33 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flag *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->precision = -1;
}

const char	*parse_flags(const char *fmt, t_flag *flags, va_list *ap)
{
	(void)ap;
	while (*fmt == '-' || *fmt == '+' || *fmt == ' ' || *fmt == '0'
		|| *fmt == '#')
	{
		if (*fmt == '-')
			flags->minus = 1;
		if (*fmt == '+')
			flags->plus = 1;
		if (*fmt == ' ')
			flags->space = 1;
		if (*fmt == '0')
			flags->zero = 1;
		if (*fmt == '#')
			flags->hash = 1;
		fmt++;
	}
	if (*fmt == '*')
	{
		// TODO: handle the width.
		// ...
		return (NULL);
	}
	if (*fmt == '.')
	{
		// TODO: handle precision.
		//...
		return (NULL);
	}
	return (fmt);
}
