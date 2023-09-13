/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mheinke <mheinke@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:48:20 by mheinke           #+#    #+#             */
/*   Updated: 2023/09/12 12:44:08 by mheinke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./libft/libft.h"

int	printf_char(int c);
int	printf_string(char *s);
int	printf_ptr(void *ptr);
int	ft_printf(const char *s, ...);
int	printf_nbr(int n);
int	printf_hex(unsigned int n, int x_switch);
int	printf_uint(unsigned int n);

#endif