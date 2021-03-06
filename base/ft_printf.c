/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:59:45 by taegor            #+#    #+#             */
/*   Updated: 2021/01/22 15:49:50 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		init_delete(t_modif *flag, int i)
{
	if (i == 1)
	{
		flag->flag = 0;
		flag->width = 0;
		flag->precision = -1;
		flag->type = 0;
		flag->result = 0;
		flag->variable = 0;
	}
	else
	{
		flag->flag = 0;
		flag->width = 0;
		flag->precision = -1;
		free(flag->variable);
		flag->variable = NULL;
		flag->type = 0;
	}
	return (1);
}

int		ft_write(t_modif *flag, char *line, int *i)
{
	while (line[*i] != '%' && line[*i])
	{
		ft_putchar(line[*i]);
		flag->result++;
		++*i;
	}
	if (line[*i] == '\0')
		return (0);
	return (1);
}

int		ft_printf(const char *format, ...)
{
	char		*line;
	t_modif		flag;
	va_list		args;
	int			i;

	i = 0;
	init_delete(&flag, 1);
	va_start(args, format);
	line = ft_strdup(format);
	while (ft_write(&flag, line, &i) == 1)
	{
		ft_parser(line, args, &i, &flag);
		if (ft_processor(&flag, args) < 0)
		{
			free(line);
			init_delete(&flag, 0);
			return (-1);
		}
		init_delete(&flag, 0);
	}
	va_end(args);
	free(line);
	return (flag.result);
}
