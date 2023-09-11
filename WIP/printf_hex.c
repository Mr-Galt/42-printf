/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:52:48 by mheinke           #+#    #+#             */
/*   Updated: 2023/08/25 08:32:27 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex(unsigned int n)
{
	int	size;

	if (n < 0 || n == 0)
		size = 1;
	else
		size = 0;
	while (n)
	{
		size ++;
		n /= 16;
	}
	return (size);
}

int	printf_hex(unsigned int n, int maj)
{
	char			*base_16;
	int				size;

	size = size_hex(n);
	if (maj == 0)
		base_16 = "0123456789ABCDEF";
	else
		base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		if (printf_hex(n / 16, maj) == -1)
			return (-1);
		if (printf_hex(n % 16, maj) == -1)
			return (-1);
	}
	return (size);
}
