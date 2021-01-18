/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heula <heula@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 21:11:23 by heula             #+#    #+#             */
/*   Updated: 2021/01/11 20:34:33 by heula            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/printf.h"

const char	*ft_write(t_mode *format)
{
	if (*format->str == '%' || *format->str == '\0')
		return (format->str);
	while (*format->str != '%' && *format->str != '\0')
	{
		ft_putchar_fd(*format->str++, 1);
		format->result++;
	}
	return (format->str);
}

void		printspace(char *str, int count)
{
	while (count-- > 0)
	{
		*str = ' ';
		str++;
	}
}

void		printzero(char *str, int count)
{
	while (count-- > 0)
	{
		*str = '0';
		str++;
	}
}

int			printifnull(t_mode *format)
{
	char	*output;

	format->width = (format->width > 1) ? format->width : 1;
	if ((output = (char *)malloc(format->width + 1)) == NULL)
		return (-1);
	printspace(output, format->width - 1);
	output[format->width - 1] = '\0';
	if (format->flag == '-')
	{
		ft_putchar_fd('\0', 1);
		ft_putstr_fd(output, 1);
	}
	else
	{
		ft_putstr_fd(output, 1);
		ft_putchar_fd('\0', 1);
	}
	free(output);
	return (0);
}
