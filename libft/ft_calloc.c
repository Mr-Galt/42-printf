/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:30:11 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/10 09:41:58 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;

	if (size && (count > (UINT32_MAX / size)))
		return (NULL);
	buffer = (void *)malloc(count * size);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, count * size);
	return (buffer);
}
