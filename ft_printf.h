/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 16:14:29 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/02 18:50:38 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flag
{
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		precision;

}			t_flag;

typedef struct s_conv
{
	char	spec;
	int		(*f)(va_list *, t_flag *);
}			t_conv;

void		init_flags(t_flag *flags);
int			ft_printf(const char *fmt, ...);
int			dispatch(char spec, va_list *ap, t_flag *flags);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_putnbr_base(unsigned long n, char *base, unsigned int base_len);
const char	*parse_flags(const char *fmt, t_flag *flags, va_list *ap);
int			conv_c(va_list *ap, t_flag *flags);
int			conv_s(va_list *ap, t_flag *flags);
int			conv_p(va_list *ap, t_flag *flags);
int			conv_d(va_list *ap, t_flag *flags);
int			conv_u(va_list *ap, t_flag *flags);
int			conv_x(va_list *ap, t_flag *flags);
int			conv_upx(va_list *ap, t_flag *flags);
int			conv_pct(va_list *ap, t_flag *flags);
#endif
