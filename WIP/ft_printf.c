/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:00:59 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/30 21:09:26 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	process_input(const char input, va_list args)
{
	int	i;

	i = 0;
	if (input == 'c')
		i = printf_char(va_arg(args, int));
	else if (input == 's')
		i = printf_string(va_arg(args, char *));
	else if (input == 'd')
		i = printf_int(va_arg(args, int));
	else if (input == 'i')
		i = printf_int(va_arg(args, int));
	else if (input == '%')
		{
			printf_char('%');
			return (1);
		}
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	return_length;

	if (!input)
		return (0);
	i = 0;
	return_length = 0;
	va_start(args, input);
	while (input[i])
	{
	{
		if (input[i] == '%' && ft_strchr("cspdiuxX%", input[++i]))
			return_length += process_input(input[i], args);
		else if (input[i])
			return_length += printf_char(input[i]);
		if (input[i])
			i++;
	}
	}
	va_end(args);
	return (return_length);
}
