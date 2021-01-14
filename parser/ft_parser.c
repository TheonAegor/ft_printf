/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:48 by taegor            #+#    #+#             */
/*   Updated: 2021/01/14 22:05:34 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/libft.h"

int		ft_istype(char *format, int i)
{
	if (format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'c' || format[i] == 's' || format[i] == 'p' 
			|| format[i] == 'x' || format[i] == 'X')
		return (1);
	return (0);

}

int		parse_flags(char *format, int *i, va_list args, s_modif *flag)
{
	while (format[i] == '-' || format[i] == '0')
	{
		while (format[i] == '-')
		{                 
			flag->flag = 1;
			*i++;  
			if (format[i] == '*')
			{                                      
				star++;                            
				if (star == 1)                     
					flag->width = va_arg(args, int);
				*i++;
			}
		}
		while (format[i] == '0' && flag->flag != 1)
		{
			flag.flag = 2;
			*i++;
			if (format[i] == '*')
			{
				star++;
				if (star == 1)
					flag->width = va_arg(args, int);
				*i++;
			}
		}
	}
	 return (1);
}

s_modif	ft_parser(char *format, va_list args)
{
	int		i;
	int		is_full;
	s_modif flag;
	int		star;
	int		star2;

	i = 0;
	star = 0;
	star2 = 0;
	flag.flag = 0;
	flag.width = 0;
	flag.precision = 0;
	while (!ft_istype(format, i) && format[i])	
	{
		while (format[i] == '-')
		{
			flag.flag = 1;
			i++;
			if (format[i] == '*')
			{
				star++;
				if (star == 1)
					flag.width = va_arg(args, int);
				i++;
			}
		}
		while (format[i] == '0' && flag.flag != 1)
		{
			flag.flag = 2;
			i++;
			if (format[i] == '*')
			{
				star++;
				if (star == 1)
					flag.width = va_arg(args, int);
				i++;
			}
		}
		if (ft_isdigit(format[i]) && !flag.precision)
			flag.width = ft_atoi(format);
		while(ft_isdigit(format[i]))
			i++;
		if (format[i] == '.')
		{
			i++;
			if (format[i] == '*')
			{
				star2++;
				if (star == 1)
					flag.precision = va_arg(args, int);
				i++;
			}
			if (ft_isdigit(format[i]))
				flag.precision = ft_atoi(&format[i]);	
		}
	}
	flag.type = format[i];
	return (flag);
}
/*
Варианты модификаторо:
1)только модификатор типа - если format[i] = type
2)все вместе
*/
