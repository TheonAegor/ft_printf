/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:51:39 by heula             #+#    #+#             */
/*   Updated: 2021/01/11 20:48:28 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	parserbeforedot(t_mode *format)
{
	while (*format->str == '-' || *format->str == '0')
	{
		if (*format->str == '-')
			format->flag = '-';
		if (*format->str == '0' && format->flag != '-')
			format->flag = '0';
		format->str++;
	}
	if (*format->str == '*')
	{
		format->width = va_arg(format->s, int);
		if (format->width < 0)
		{
			format->flag = '-';
			format->width = format->width * (-1);
		}
		format->str++;
	}
	else if (ft_isdigit(*format->str))
	{
		format->width = ft_atoi(format->str);
		while (ft_isdigit(*format->str))
			format->str++;
	}
}

void	parserifdot(t_mode *format)
{
	if (*format->str == '*')
	{
		format->accuracy = va_arg(format->s, int);
		if (format->accuracy < 0)
			format->accuracy = -1;
		format->str++;
	}
	else
	{
		format->accuracy = ft_atoi(format->str);
		while (ft_isdigit(*format->str))
			format->str++;
	}
}

int		parserstart(t_mode *format)
{
	char *types;

	types = "cspdiuxX%%";
	format->flag = '1';
	format->width = -1;
	format->accuracy = -1;
	format->str++;
	parserbeforedot(format);
	if (*format->str == '.')
	{
		format->str++;
		parserifdot(format);
	}
	format->type = *format->str;
	if ((ft_strchr(types, format->type)) == NULL || format->type == '\0')
		return (-1);
	format->str++;
	return (0);
}
