/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 20:14:55 by mheinke           #+#    #+#             */
/*   Updated: 2023/08/02 20:29:38 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	size_hex_address(unsigned long long n)
{
	int	size;

	if (n < 0)
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

static int	ft_hex_address(unsigned long long n)
{
	char	*base_16;
	int		size;

	size = size_hex_address(n);
	base_16 = "0123456789abcdef";
	if (n < 16)
	{
		if (printf_char(base_16[n]) == -1)
			return (-1);
	}
	else
	{
		ft_hex_address(n / 16);
		ft_hex_address(n % 16);
	}
	return (size);
}

int	printf_ptr(void *ptr)
{
	int	n;

	if (printf_string("0x") == -1)
		return (-1);
	n = ft_hex_address((unsigned long long) ptr);
	if (n != 0)
		return (n + 2);
	else
		return (3);
}
