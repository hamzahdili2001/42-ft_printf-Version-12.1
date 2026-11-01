/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhdili <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 13:59:59 by hhdili            #+#    #+#             */
/*   Updated: 2026/11/01 14:37:20 by hhdili           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str;

	str = "this is an str test";
	printf("%d\n", ft_printf("%s\n", str));
	printf("%d\n", printf("%s\n", str));
	return (0);
}
