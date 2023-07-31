/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:00:59 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/31 16:59:23 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	process_input(const char *input, unsigned int *i, va_list *args)
{
	unsigned int	return_counter;

	return_counter = 0;
	if (input[*i] == 'c')
		return_counter += printf_char(va_arg(*args, int));
	else if (input[*i] == 's')
		return_counter += printf_string(va_arg(*args, char *));
	else if (input[*i] == '%')
	{
		printf_char('%');
		return (1);
	}
	return (return_counter);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	return_length;

	i = 0;
	return_length = 0;
	va_start(args, input);
	while (input[i])
	{
	{
		if (input[i] == '%')
		{
			i++;
			return_length += process_input(input, &i, &args);
		}	
		else
		{
			return_length += printf_char(input[i]);
		}
		i++;
	}
	}
	va_end(args);
	return (return_length);
}

// int	main(void){
// 	printf("OG PrintF: %c%c%c\n", 'a', '\t', 'b');
// 	ft_printf("My PrintF: %c%c%c\n", 'a', '\t', 'b');
// }