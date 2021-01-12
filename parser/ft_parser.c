/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:48 by taegor            #+#    #+#             */
/*   Updated: 2021/01/12 22:06:00 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_parser.h"
#include "../includes/libft.h"

s_modif	ft_parser(char *format)
{
	int		i;
	s_modif flag;

	i = 0;
	while (format[i] != 'd' &&  format[i] != 'i' && format[i] != 'u'
			&& format[i] != 'c' && format[i] != 's' && format[i] != 'p' 
			&& format[i] != 'x' && format[i] != 'X' && format[i])
	{
		while (format[i] == '-' && flag.flag != 0)
		{
			flag.flag = -1;			
			i++;
		}
		while (format[i] == '0' && flag.flag != -1)
		{
			flag.flag = 0;
			i++;
		}
		if (ft_isdigit(format[i]))
			flag.width = ft_atoi(format);
		i++;
	}
	return (flag);

}
/*
Варианты модификаторо:
1)только модификатор типа - если format[i] = type
2)все вместе
*/
