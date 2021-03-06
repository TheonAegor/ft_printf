/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:48 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 14:49:20 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_istype(char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'x' || format[i] == 'X' || format[i] == '%')
		return (1);
	return (0);
}

int		parse_precision(char *format, int *i, va_list args, t_modif *flag)
{
	flag->precision = 0;
	if (format[*i] == '*')
	{
		flag->precision = va_arg(args, int);
		if (flag->precision < 0)
			flag->precision = -1;
		else if (flag->flag == 2)
			flag->flag = 0;
		++*i;
	}
	else if (ft_isdigit(format[*i]) && flag->precision == 0)
	{
		if (flag->flag == 2)
			flag->flag = 0;
		flag->precision = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			++*i;
	}
	return (1);
}

int		parse_flags(char *format, int *i, va_list args, t_modif *flag)
{
	while (format[*i] == '-' || format[*i] == '0')
	{
		if (format[*i] == '-')
			flag->flag = 1;
		if (format[*i] == '0' && flag->flag != 1)
			flag->flag = 2;
		++*i;
	}
	if (format[*i] == '*')
	{
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->flag = 1;
			flag->width = flag->width * (-1);
		}
		++*i;
	}
	else if (ft_isdigit(format[*i]))
	{
		flag->width = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			++*i;
	}
	return (1);
}

int		ft_parser(char *format, va_list args, int *i, t_modif *flag)
{
	++*i;
	parse_flags(format, i, args, flag);
	if (format[*i] == '.')
	{
		++*i;
		parse_precision(format, i, args, flag);
	}
	flag->type = format[*i];
	if (ft_istype(format, *i) == 0 && flag->type == '\0')
		return (-1);
	++*i;
	return (1);
}
