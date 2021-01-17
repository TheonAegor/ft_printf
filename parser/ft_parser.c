/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:48 by taegor            #+#    #+#             */
/*   Updated: 2021/01/18 01:13:20 by taegor           ###   ########.fr       */
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

int		parse_precision(char *format, int *i, va_list args, s_modif *flag)
{
	int star;

	star = 0;
	if (format[*i] == '*')
	{
		flag->precision = va_arg(args, int);
		if (flag->precision < 0)
			flag->precision = -1;
		++*i;
	}
	else if (ft_isdigit(format[*i]) && !flag->precision)
	{
		flag->width = ft_atoi(&format[*i]);
		while(ft_isdigit(format[*i]))
			++*i;
	}
	return (1);
}

int		parse_flags(char *format, int *i, va_list args, s_modif *flag)
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

int		parse_format(char *format, int *i, s_modif *flag)
{
	int count;
	count = 0;
	//printf("line__=%d\n", format[*i]);
	while (format[*i] && format[*i] != '%')
	{
		ft_putchar(format[*i]);
		flag->result++;
		++*i;
	}
	return (count);
}

int		ft_parser(char *format, va_list args, int *i, s_modif *flag)
{
	int j;

//	printf("\nress = %d\n", *i);
//	printf("\nshift = %d\n", j);
	if ((j = parse_format(format,i, flag)) < 0)
		return(-1);
//	printf("\nress = %d\n", *i);
//	printf("line__=%d\n", format[*i]);
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
//	printf("\nparser\n");
//	printf("i=%d\n", *i);
/*
	printf("\ntype=%c\n", flag->type);
	printf("flag=%d\n", flag->flag);
	printf("width=%d\n", flag->width);
	printf("prec=%d\n", flag->precision);
	printf("\nres = %d\n", *i);
*/

	return (j);
}
