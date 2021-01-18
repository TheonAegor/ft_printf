/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:18:03 by heula             #+#    #+#             */
/*   Updated: 2021/01/10 20:25:22 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"
#include <stdarg.h>

int	processor(t_mode *format)
{
	int i;

	if (format->type == 'c')
		i = print_c(format);
	if (format->type == 's')
		i = print_s(format);
	if (format->type == '%')
		i = print_percent(format);
	if (format->type == 'd' || format->type == 'i')
		i = print_d_i(format);
	if (format->type == 'x' || format->type == 'X')
		i = print_hex(format);
	if (format->type == 'u')
		i = print_u(format);
	if (format->type == 'p')
		i = print_p(format);
	if (i < 0)
		return (0);
	return (i);
}

int	ft_printf(const char *string, ...)
{
	t_mode	format;
	int		i;

	i = 0;
	format.str = string;
	format.result = 0;
	va_start(format.s, string);
	while (*(ft_write(&format)) != '\0')
	{
		if ((parserstart(&format)) == -1)
			return (0);
		if ((i = processor(&format)) == -1)
			return (-1);
		format.result = format.result + i;
	}
	va_end(format.s);
	return (format.result);
}
