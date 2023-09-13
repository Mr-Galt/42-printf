/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:52:48 by mheinke           #+#    #+#             */
/*   Updated: 2023/09/12 12:43:16 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n <= 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size++;
		n /= 16;
	}
	return (size);
}

int	printf_hex(unsigned int n, int x_switch)
{
	char			*base_16;
	int				size;

	size = size_hex(n);
	base_16 = "0123456789abcdef";
	if (x_switch == 0)
		base_16 = "0123456789ABCDEF";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (printf_hex(n / 16, x_switch) == -1)
			return (-1);
		if (printf_hex(n % 16, x_switch) == -1)
			return (-1);
	}
	return (size);
}
