/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:29:15 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/16 12:29:13 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	capture_the_beast(const char *str, int neg_flag, int i)
{
	long	result;
	long	previous_result;

	result = 0;
	previous_result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		previous_result = result;
		result = result * 10 + str[i++] - '0';
		if (previous_result > result)
		{
			if (neg_flag < 0)
				return (0);
			else
				return (-1);
		}
	}
	return (result * neg_flag);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		neg_flag;

	i = 0;
	neg_flag = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_flag = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	return (capture_the_beast(str, neg_flag, i));
}
