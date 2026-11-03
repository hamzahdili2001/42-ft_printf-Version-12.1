/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 12:51:38 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/03 11:02:05 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count += ft_putchar(str[count]);
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base, unsigned int base_len)
{
	int	count;

	count = 0;
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base, base_len);
	count += ft_putchar(base[n % base_len]);
	return (count);
}
