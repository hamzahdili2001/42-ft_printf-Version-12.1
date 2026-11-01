/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:14:29 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 14:01:15 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_conv
{
	char	spec;
	int		(*f)(va_list *);
}			t_conv;

int			ft_printf(const char *fmt, ...);
int			dispatch(char spec, va_list *ap);
int			ft_putchar(int c);
int			conv_c(va_list *ap);
int			conv_s(va_list *ap);
int			conv_p(va_list *ap);
int			conv_d(va_list *ap);
int			conv_u(va_list *ap);
int			conv_x(va_list *ap);
int			conv_upx(va_list *ap);
int			conv_pct(va_list *ap);
#endif
