/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:48:20 by mheinke           #+#    #+#             */
/*   Updated: 2023/07/31 16:05:21 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include "./libft/libft.h"

int		ft_printf(const char *input, ...);
int		printf_unsigned(unsigned int nb);
int		printf_string(char *str);
int		printf_int(int n);
int		printf_char(int c);

#endif