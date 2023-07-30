/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 12:25:06 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/27 14:18:58 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	printf_string(char *str)
{
	unsigned int	i;

	if (!str)
	{
		ft_putstr_fd("(NULL)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	i = ft_strlen(str);
	return (i);
}
